#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    myRect.set(0,0,ofGetWindowWidth()/3,ofGetWindowHeight()/3);
    ofSetColor(255,0,0, 100);

    font.load("verdana.ttf",20);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    ofDrawRectangle(myRect);
    ofSetColor(ofColor::black);
    font.drawString("A rendszer kikapcsolása", ofGetWindowWidth()/3,ofGetWindowHeight()/3);
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
        ofSetColor(0,255,0, 255);
    else ofSetColor(255, 0, 0, 100);

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    if (myRect.inside( x, y) ) 
        {
		// call the system command say
		#ifdef TARGET_OSX
			string cmd = "say -v " + words[step] + " "; // create the command
		#endif
		#ifdef TARGET_WIN32
			string cmd = "data\\SayStatic.exe " + words[step];        // create the command
		#endif
		#ifdef TARGET_LINUX
			string cmd = "data/turnOffAll.sh";           // create the command
		#endif

                // print command and execute it
                cout << cmd << endl;
                ofSystem(cmd.c_str());
        }
    else ofSetColor(255, 0, 0);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

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
