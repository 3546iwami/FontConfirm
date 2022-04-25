#include "edittext.h"
#include <QFile>
#include <QTextStream>
#include <QtCore/QDebug>
//コンストラクタ
EditText::EditText(QObject *parent): QObject(parent) {m_edittext ="Enter Text";}
//テキストセット
void EditText::setEditText(QString input){
    m_edittext = input;
    emit inputSig();
}
//テキスト取得関数
QString EditText::getEditText(){return m_edittext;}
//フォント取得関数
QString EditText::getEditFont(){return m_font;}
//フォント代入関数
void EditText::setEditFont(QString input){
    m_font = input;
    emit inputSig();
}
//テキストファイル読み込み
void EditText::readTextSlotCpp(){
    //ファイルの読み込み
    QFile file("../FontConfirm/test.txt");
    QTextStream out(&file);
    QString str;
    if(!file.open(QIODevice::ReadOnly))//読み込みでオープンできたか
    {
        qDebug() << "can't open file.";
        return;
    }
    else {
        str = out.readAll();
        file.close();
        qDebug() << str;
        emit readTextSigCpp(str);
    }
}
