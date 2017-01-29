//
//  Square.cpp
//  projectHarp
//
//  Created by Elisabetta Motta on 15/11/2015.
//
//

#include "Circle.hpp"


Circle::Circle(float _x, float _y, ofColor _tempCol):posX(_x), posY(_y), clr(_tempCol){
}


void Circle::update(){
    
    //Change posX and posY according to speedX and speedY to
    //animate the Circles

    posX += speedX;
    posY += speedY;
    
    //Make the Circles bounce off the edges by inverting the speed
    if (posX < 7 || posX > ofGetWidth()-7){
        speedX = -speedX;
    }
    if (posY < 218 || posY > ofGetHeight()-7){
        speedY = -speedY;
    }
}

/*Every time the program call this function a new Circle object
will be displayed*/
void Circle::display() {
    
    ofSetColor(clr, 90);
    ofFill();
    //The actual shape is made of 5 circles.
    ofDrawCircle(posX, posY, 5);
    ofSetColor(clr, 70);
    ofFill();
    ofDrawCircle(posX+5, posY+5, 5);
    ofSetColor(clr, 70);
    ofFill();
    ofDrawCircle(posX-5, posY-5, 5);
    ofSetColor(clr, 70);
    ofFill();
    ofDrawCircle(posX+5, posY-5, 5);
    ofSetColor(clr, 70);
    ofFill();
    ofDrawCircle(posX-5, posY+5, 5);
}











