#ifndef EDITTEXT_H
#define EDITTEXT_H
#include<QObject>
#include<QString>
#include <QComboBox>

class editText:public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString viewtext READ getEditText WRITE setEditText NOTIFY inputSig);
    Q_PROPERTY(QString viewfont READ getEditFont WRITE setEditFont NOTIFY inputSig);

public:
    editText();
signals:
    void inputSig();
public slots:
    //QString getFontName();
private:
    QString m_edittext;//編集文言
    QString m_font;//フォント

    QString getEditText(){
        return m_edittext;
    }
    void setEditText(QString input){
        m_edittext = input;
        emit inputSig();
    }
    QString getEditFont(){
        return m_font;
    }
    void setEditFont(QString input){
        m_font = input;
        emit inputSig();
    }
};

#endif // EDITTEXT_H
