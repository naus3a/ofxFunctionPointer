#include "ofApp.h"

typedef void(*func)();

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0, 0, 0);
    ofSetVerticalSync(true);
    
    //static functions are super easy:
    staticPtr = &SomeClass::drawDot;
    
    //member functions need to keep track of their object:
    memberPtr.link(&someClass, &SomeClass::drawQuad);
    
    //sometimes we need to call function pointers from a generic class,
    //without passing objects or including the class containing the functions.
    //to do this, we create generic ofxFunctionPointer pointers:
    ignorantClass.addGenericFunctionPointer((ofxFunctionPointer *)&staticPtr);
    ignorantClass.addGenericFunctionPointer((ofxFunctionPointer *)&memberPtr);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofDrawBitmapString("These are drawn with function pointers:", 5,10);
    staticPtr.execute();
    memberPtr.execute();
    
    ofTranslate(0, 60);
    ofDrawBitmapString("These are drawn using generic ofxFunctionPointer pointers:", 5,10);
    ignorantClass.executeAll();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

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
