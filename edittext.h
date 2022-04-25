#ifndef EDITTEXT_H
#define EDITTEXT_H
#include<QObject>
#include<QString>
#include<QVariant>

class EditText:public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString viewtext READ getEditText WRITE setEditText NOTIFY inputSig);
    Q_PROPERTY(QString viewfont READ getEditFont WRITE setEditFont NOTIFY inputSig);
public:
    explicit EditText(QObject *parent = 0);
    //テキスト代入関数
    Q_INVOKABLE void setEditText(QString input);
signals:
    void inputSig();
    void readTextSigCpp(QVariant);
public slots:
    void readTextSlotCpp();
private:
    QString m_edittext;//編集文言
    QString m_font;//フォント
    //テキスト取得関数
    QString getEditText();
    //フォント取得関数
    QString getEditFont();
    //フォント代入関数
    void setEditFont(QString input);
};
#endif // EDITTEXT_H
