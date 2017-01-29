#pragma once

#include "ofMain.h"
#include "note.hpp"
#include "Circle.hpp"
#include "Scale.hpp"

#include <vector>
using std::vector;

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
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    //Declare deconstractor function
    ~ofApp();
    
   //Declare vector of pointers of type Scale
        vector <Scale *> scale;
    
    //set font variables
        ofTrueTypeFont myfont;
        ofTrueTypeFont myfont2;
        ofTrueTypeFont myfont3;
    
    //set image variable
        ofImage harp;
    
    //set color variable.
        ofColor clr;
    
    //Declare vector of pointers of type ofColor
        vector <ofColor *> col;
    
    //Declare vector of pointers of type Note
        vector<Note *> note;
    
    //Declare vector of pointers of type Circle
        vector<Circle *> circle;
    
    //Declare vector of boolean for each key
        vector <bool> key;
    
    //set boolean for the selected note
        bool selected;
    
    //set samples variables
        ofSoundPlayer c3, d3, e3, f3, g3, a3, b3, c4, d4, e4, f4, g4,       a4, b4;
        ofSoundPlayer c5, d5, e5, f5, g5, a5, b5, c3s, d3s, f3s, g3s, a3s;
        ofSoundPlayer c4s, d4s, f4s, g4s, a4s, c5s, d5s, f5s, g5s, a5s;

		
};
