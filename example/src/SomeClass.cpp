//
//  SomeClass.cpp
//  ofxFunctionPointer example
//
//  Created by enrico<naus3a>viola on 4/23/15.
//
//


#include "SomeClass.h"

SomeClass::SomeClass(){
    r.set(60, 20, 40, 40);
}

void SomeClass::drawDot(){
    ofPushStyle();
    ofSetColor(ofColor::white);
    ofCircle(30,40,20);
    ofPopStyle();
}

void SomeClass::drawQuad(){
    ofPushStyle();
    ofSetColor(ofColor::yellow);
    ofRect(r);
    ofPopStyle();
}