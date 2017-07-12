import QtQuick 2.7
import QtQuick.Controls 2.1
import Ancre 4.2

PovQuickForm {

    Anchor {
        id: anchor
        objectName: "anchor"
    }

    bplay.onClicked: {
        anchor.media_play_click();
    }

    bstop.onClicked: {
        anchor.media_stop_click();
    }

    flickable.onContentXChanged: {
        if ( (flickable.contentX > 0 && flickable.contentX <= 50)
                || (flickable.contentX < 0 && flickable.contentX >= -50)){
            if (anchor.gauss)
                anchor.gauss = false
            if (flickable.previewstate == 1){
                flickable.previewstate = 0;
                anchor.view_reset();
            }
        }
        else if (flickable.contentX > 90 || flickable.contentX < -90){
            if (flickable.contentX > 90){
                flickable.contentX = 90;
            }
            else if (flickable.contentX > -90){
                flickable.contentX = -90;
            }
        }
        else if (flickable.contentX > 80 || flickable.contentX < -80){
            if (flickable.contentX > 80){
                if (flickable.previewstate == 0){
                    flickable.previewstate = 1;
                    anchor.r_preview();
                }
            }
            else{

                if (flickable.previewstate == 0){
                    flickable.previewstate = 1;
                    anchor.l_preview();
                }
            }
            if (!anchor.gauss)
                anchor.gauss = true
        }
        else if (flickable.contentX == 80 || flickable.contentX == -80){
            if (flickable.previewstate == 1){
               // console.log("previewchange");
                flickable.previewstate = 0;
                anchor.view_reset();
            }
            if (!anchor.gauss)
                anchor.gauss = true
        }
        else if (!anchor.gauss)
            anchor.gauss = false

    }

    flickable.onDragEnded: {
        if (flickable.contentX >= 50)
            anchor.l_swip();
        else if (flickable.contentX <= -50)
            anchor.r_swip();
        else
        {
            anchor.view_reset();
            anchor.flick_nodrag();
        }
        flickable.contentX = 0;
        flickable.previewstate = 0;
        if (anchor.gauss)
            anchor.gauss = false
    }

    flickable.onDragStarted: {
        anchor.arrow_start();
    }


    button.onClicked: {
        anchor.backclick();
//        anchor.backclick();
    }
    flickable.onWidthChanged: {
        anchor.debug_signal();
        anchor.arrow_start();

    }



}


