#ifndef EDITTEXT_H
#define EDITTEXT_H
#include<QObject>
#include<QString>

class editText:public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString viewtext MEMBER m_edittext NOTIFY inputSig);

public:
    editText();
signals:
    void inputSig();
public slots:
    void edittFont();
private:
    QString m_edittext;//編集文言
};

#endif // EDITTEXT_H
