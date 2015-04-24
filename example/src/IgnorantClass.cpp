//
//  IgnorantClass.cpp
//  ofxFunctionPointer example
//
//  Created by enrico<naus3a>viola on 4/24/15.
//
//

#include "IgnorantClass.h"

void IgnorantClass::addGenericFunctionPointer(ofxFunctionPointer *_ptr){
    fPtrs.push_back(_ptr);
}

void IgnorantClass::executeAll(){
    for(int i=0;i<fPtrs.size();i++){
        fPtrs[i]->execute();
    }
}