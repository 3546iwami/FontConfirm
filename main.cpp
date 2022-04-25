#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QLocale>
#include <QTranslator>
#include <QFile>
#include <QTextStream>
#include <edittext.h>
#include<QVariant>

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);
    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "ConfirmFonts_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            app.installTranslator(&translator);
            break;
        }
    }
    //公開
    qmlRegisterType<EditText>("EditText",1,0,"EditText");
    //ファイルの読み込み
    QFile file("../FontConfirm/test.txt");
    QTextStream out(&file);
    QString str;
    if(!file.open(QIODevice::ReadOnly))//読み込みでオープンできたか
    {
        qDebug() << "can't open file.";
        return 0;
    }
    else {
        str = out.readAll();
        file.close();
        qDebug() << str;
    }
    //ソフト起動
    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
        &app, [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        }, Qt::QueuedConnection);
    engine.load(url);

    //ルートオブジェクトのウインドウポインタ取得
    QObject* rootObject{engine.rootObjects().first()};
    //オブジェクトID("editTextIns")という子要素を探し、C++クラスであるeditTextクラスとしてインスタンス化する。
    EditText* editText{rootObject->findChild<EditText*>("editTextIns")};
    //メモ帳の内容をセットする。
    editText->setEditText(str);

    //Connect QML Signal to C++ Slot
    QObject::connect(rootObject, SIGNAL(readTextSig()), editText, SLOT(readTextSlotCpp()));
    // Connect C++ Signal to QML Slot
    QObject::connect(editText, SIGNAL(readTextSigCpp(QVariant)), rootObject, SLOT(readTextSlot(QVariant)));

    return app.exec();
}
