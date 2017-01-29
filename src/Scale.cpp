//
//  Scale.cpp
//  projectHarp
//
//  Created by Elisabetta Motta on 24/11/2015.
//
//

#include "Scale.hpp"


//The constructor of the class Scale takes the x and y parameters from the Button class
Scale::Scale(float _x, float _y, string _key, ofTrueTypeFont *_font) : Button(_x, _y), key(_key), myFont(_font){
    
    }

/*When this function is called, the program will display the a rectagle with the letter of the scale*/
 
void Scale::display(){
    ofSetColor(0);
    ofNoFill();
    ofDrawRectangle(posX, posY, w, h);
    myFont->drawString(key, posX+6, posY+35);
    
}

void Scale::selected(){
    
    /*This function will be called when we select a scale and will turn the button of the selected scale to white*/

    ofSetColor(255);
    ofNoFill();
    ofDrawRectangle(posX, posY, w, h);
    myFont->drawString(key, posX+6, posY+35);

}

