import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.2
import EditText 1.0

Window {
    signal readTextSig();
    function readTextSlot(text)
    {
        console.log("qmlslot called")
        edittext.viewtext = text//テキストファイル読み込み
    }
    id:window
    width: 640
    height:800
    visible: true
    title: qsTr("Fint Confirm")
    //インスタンス化
    EditText {
        id:edittext
        objectName: "editTextIns"
    }

    Column{
        TextField{
            id:inputtext
            width:anchors.parent
            y:5
            height:24
            onEditingFinished: {
                edittext.viewtext = text
            }
        }

        Rectangle{
            width:window.width
            height:60
            Text{
                anchors.fill: parent
                text: "注意:\n日本語入力はキーボードからできません。\n 日本語を確認する場合は、test.txtに記述して読み込んでください。\n ttfファイル追加時はmain.qmlに項目追加後、ttfファイルを/home/ishida/.local/share/fontsに置く"
                color: "red"
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
                //ttfファイル追加時に下記項目を追加する。
                ListElement{name:"udsgPm_20180911.ttf";  value: "TT\-UDShinGoP\-Medium"}
                ListElement{name:"udsgPb_20180911.ttf";  value: "TT\-UDShinGoP\-Bold"}
            }
            onActivated: {
                edittext.viewfont = model.get(index).value;
            }
        }
        Button{
            id:readtextfile
            text:"Read test.txt"
            onClicked:{
                console.log("on clicked")
                readTextSig();
            }
        }
        Text {
            id: outputtext
            text:edittext.viewtext
            font.pointSize: 48
            font.family: edittext.viewfont
        }
    }
}
