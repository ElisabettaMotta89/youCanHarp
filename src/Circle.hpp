//
//  Square.hpp
//  projectHarp
//
//  Created by Elisabetta Motta on 15/11/2015.
//
//

#ifndef Circle_hpp
#define Circle_hpp

#include <stdio.h>

#include "ofMain.h"

/*Circle class:
 When the use selects scale and note/color, they'll be able to add Circle
 objects by clicking below the line.
 The new Circle object would bounce off the edges triggering the note
 corresponding to the color of the Circle.*/

//create Circle class

class Circle {
public:
    
    // Create constructor for the Circle object with coordinates and color as arguments
    Circle(float _x, float _y, ofColor _tempCol);
    
    // Specify the different methods of the object square
    void setup();
    void update();
    void display();
    
    // Specify the properties
    float posX;
    float posY;
    float dim;
    float speedX = 0.5;
    float speedY = 0.5;
    ofColor clr;

};


#endif /* Circle_hpp */
