//
//  note.cpp
//  projectHarp
//
//  Created by Elisabetta Motta on 11/11/2015.
//
//

#include "note.hpp"


//The constructor of the class Note takes the x and y parameters from the Button class
Note::Note(float _x, float _y, ofColor _tempC, ofTrueTypeFont *_font1, ofTrueTypeFont *_font2): Button(_x, _y), col(_tempC), myfont2(_font1), myfont3(_font2){
}

void Note::grid(){
    
    /*When this function is called the program will display a grid of squares where the notes will be displayed when a scale is selected*/
    
    ofNoFill();
    ofSetColor(0);//stroke color
    ofDrawRectangle(posX, posY, 25, 25);
    
}

void Note::display(){
    
    /*When this function is called, the program will display the a coloured rectagle corresponding to the note we want to display
     
     Display the instruction "Select colour/note" and the name of the notes.*/
    
    
    ofFill();
    ofSetColor(col, 150); //fill color
    ofDrawRectangle(posX, posY, 25, 25);
    
    ofSetColor(255);
    ofFill();
    myfont2->drawString("Select Color/Note", 190, 35);
    
    myfont3->drawString("C", 185, 141);
    myfont3->drawString("D", 210, 141);
    myfont3->drawString("E", 235, 141);
    myfont3->drawString("F", 260, 141);
    myfont3->drawString("G", 285, 141);
    myfont3->drawString("A", 310, 141);
    myfont3->drawString("B", 335, 141);
    
    }




