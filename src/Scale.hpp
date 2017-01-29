//
//  Scale.hpp
//  projectHarp
//
//  Created by Elisabetta Motta on 24/11/2015.
//
//

#ifndef Scale_hpp
#define Scale_hpp

#include <stdio.h>
#include "ofMain.h"
#include "note.hpp"
#include "Button.hpp"


//Create Scale class
//Inherit the call Button
class Scale: public Button {
public:

    // Create constructor for the Scale object with coordinates, string and font as arguments
    Scale(float _x, float _y, string _key, ofTrueTypeFont *_font);
    
    // Specify the different methods of the object note
    void display();
    void selected();
    
    //Specify the properties
    ofTrueTypeFont *myFont;
    float  w = 40;
    float h = 40;
    string key;



};

#endif /* Scale_hpp */
