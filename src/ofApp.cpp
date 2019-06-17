#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    buttonColor.set(ofColor::green);
    buttonColor.setBrightness(200);
    font.load("verdana.ttf",20);
    myRect=font.getStringBoundingBox("A rendszer kikapcsolása", ofGetWindowWidth()/3,ofGetWindowHeight()/3);
    font.load("verdana.ttf",10);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    myRect.alignTo(font.getStringBoundingBox("A rendszer kikapcsolása", ofGetWindowWidth()/3,ofGetWindowHeight()/3));
    ofSetColor(buttonColor);
    ofFill();
    ofDrawRectRounded(myRect,10.0);
    ofSetColor(ofColor::black);
    ofNoFill();
    ofDrawRectRounded(myRect,10.0);
    font.drawString("A rendszer kikapcsolása", ofGetWindowWidth()/3,ofGetWindowHeight()/3);
    ofDrawBitmapString ("\n\n" + cmd, ofGetWindowWidth()/3.2,ofGetWindowHeight()/3);
    ofSetColor(255, 0, 0);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

    if (myRect.inside( x, y) ) 
        buttonColor.setBrightness(255);
    else buttonColor.setBrightness(200);

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    if (myRect.inside( x, y) && button == 0) 
        {
		// call the system command say
		#ifdef TARGET_OSX
			oflogNotice(__func__) << "NOT TESTED !!! cmd = "say -v " + words[step] + " ; // create the command
		#endif
		#ifdef TARGET_WIN32
            oflogNotice(__func__) << "NOT TESTED !!! cmd = "data\\SayStatic.exe " + words[step]";        // create the command
			
		#endif
		#ifdef TARGET_LINUX
			cmd = "data/turnOffAll.sh";           // create the command
            ofFile cmdFile (cmd);
            cmdFile.setExecutable();
		#endif

                // print command and execute it
                buttonColor.setBrightness(200);
                //cmd = ofSystem(cmd.c_str());
                startThread();
        }
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
/*
    if (myRect.inside( x, y) )
        ofSetColor(ofColor::deepPink);
*/
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

void ofApp::threadedFunction() {
    while(isThreadRunning()) {
        cmd = ofSystem(cmd.c_str());
//        cout << cmd << endl;
        stopThread();
    }
}