#pragma once

#include "ofMain.h"
#include "SomeClass.h"
#include "IgnorantClass.h"
#include "ofxFunctionPtr.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        //this class contains the functions we need:
        SomeClass someClass;
    
        //this class knows nothing about SomeClass:
        IgnorantClass ignorantClass;
    
        ofxStaticFunctionPtr staticPtr;
        ofxMemberFunctionPtr<SomeClass> memberPtr;
};
