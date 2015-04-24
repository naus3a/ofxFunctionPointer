//
//  IgnorantClass.h
//  ofxFunctionPointer example
//
//  Created by enrico<naus3a>viola on 4/24/15.
//
//

#pragma once
#include "ofMain.h"
#include "ofxFunctionPtr.h"

class IgnorantClass{
public:
    void addGenericFunctionPointer(ofxFunctionPointer * _ptr);
    void executeAll();
    
    vector<ofxFunctionPointer *> fPtrs;
};