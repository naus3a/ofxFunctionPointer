//
//  ofxFunctionPointer.h
//  ofxFunctionPointer
//
//  Created by Enrico <naus3a> Viola, 2015
//  naus3a@gmail.com
//  http://naufolio.augmentedrealityag.com
//


#pragma once
#include "ofMain.h"

class ofxFunctionPointer{
public:
    ofxFunctionPointer(){
        bLinked = false;
    }
    
    virtual bool isLinked(){
        return bLinked;
    }
    virtual void execute(){}
protected:
    bool bLinked;
};

class ofxStaticFunctionPtr : public ofxFunctionPointer{
public:
    typedef void(*Func)(void);
    ofxStaticFunctionPtr(){
        ofxFunctionPointer::ofxFunctionPointer();
    }
    
    virtual void link( ofxStaticFunctionPtr::Func _func){
        if(!bLinked){
            func = _func;
            bLinked = true;
        }
    }
    
    virtual void operator=( ofxStaticFunctionPtr::Func _func){
        link(_func);
    }
    
    virtual void execute(){
        if(bLinked)func();
    }
protected:
    ofxStaticFunctionPtr::Func func;
};

template<typename TheClass>
class ofxMemberFunctionPtr : public ofxFunctionPointer{
public:
    typedef void(TheClass::*Func)();
    ofxMemberFunctionPtr(){
        ofxFunctionPointer();
        object = NULL;
    }
    virtual void link(TheClass * _object, ofxMemberFunctionPtr::Func _func){
        if(!bLinked){
            object = _object;
            func = _func;
            bLinked = true;
        }
    }
    
    virtual void execute(){
        if(bLinked)(object->*func)();
    }
protected:
    TheClass * object;
    ofxMemberFunctionPtr::Func func;
};
