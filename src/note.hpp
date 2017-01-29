//
//  note.hpp
//  projectHarp
//
//  Created by Elisabetta Motta on 11/11/2015.
//
//

#ifndef note_hpp
#define note_hpp

#include <stdio.h>

#include "ofMain.h"
#include "Button.hpp"


//Create note class
//Inherit the call Button
class Note: public Button {
public:
    
    // Create constructor for the Note object with coordinates, color and fonts as arguments
    Note(float _x, float _y, ofColor _tempC, ofTrueTypeFont *_font1, ofTrueTypeFont *_font2);
    
    // Specify the different methods of the object note
    void display();
    void grid();
    void selected();
    
    // Specify the properties
    ofColor col;
    ofTrueTypeFont *myfont2;
    ofTrueTypeFont *myfont3;
};


#endif /* note_hpp */
