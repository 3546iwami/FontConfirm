import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.2
import EditText 1.0

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    //インスタンス化
    EditText {
        id:edittext
    }
Column{
    TextField{
     id:inputtext
     width:anchors.parent
     y:5
     height:20
     onEditingFinished: {
         edittext.viewtext = text
         //inputtext_class.font("/udsgPb_20180911.ttf");
     }
    }
    Text {
        id: outputtext
        text:edittext.viewtext
        y:edittext + inputtext.height
        width:anchors.parent
        height:anchors.parent
        font.pointSize: 48
        //font.family: "./udsgPb_20180911.ttf"
    }
    Text {
        id: outputtext2
        text:edittext.viewtext
        y:inputtext.y + inputtext.height
//        width:anchors.parent
//        height:anchors.parent
        font.pointSize: 48
    }
    Text {
        id: outputtext3
        text:edittext.viewtext
        y:inputtext.y + inputtext.height
//        width:anchors.parent
//        height:anchors.parent
        font.pointSize: 48
    }
}
}
