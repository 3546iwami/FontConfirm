import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.2
import EditText 1.0

Window {
    id:window
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
     height:24
     onEditingFinished: {
         edittext.viewtext = text
         //getFontName();
     }
    }
    ComboBox{
        id:combofont
        width:window.width
        height:24
        editable: false//手動入力不可
        currentIndex: 0
        textRole:"name"
        displayText: "font:  " + model.get(currentIndex).name;
        model:ListModel{
            id:model
            ListElement{name:"udsgPm_20180911.ttf";  value: "TT\-UDShinGoP\-Medium"}
            ListElement{name:"udsgPb_20180911.ttf";  value: "TT\-UDShinGoP\-Bold"}
        }
        onActivated: {
            edittext.viewfont = model.get(index).value;
        }

    }

    Text {
        id: outputtext
        text:edittext.viewtext
        y:edittext.y + inputtext.height
        width:anchors.parent
        height:anchors.parent
        font.pointSize: 48
        font.family:"TT\-UDShinGoP\-Bold"
    }
    Text {
        id: outputtext2
        text:edittext.viewtext
        y:edittext.y + inputtext.height
        font.pointSize: 48
        font.family: edittext.viewfont
    }
    Text {
        id: outputtext3
        text:edittext.viewtext
        y:edittext.y + inputtext.height
        font.pointSize: 48
    }
}
}
