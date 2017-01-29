//
//  ofApp.cpp
//  projectHarp
//
//  Created by Elisabetta Motta on 24/11/2015.
//
//

#include "ofApp.h"

#include "note.hpp"
#include "Circle.hpp"
#include "Scale.hpp"

//--------------------------------------------------------------
void ofApp::setup(){
    
    //Load fonts
    myfont.load(ofToDataPath("verdana.ttf"), 30);
    myfont2.load(ofToDataPath("verdana.ttf"), 15);
    myfont3.load(ofToDataPath("verdana.ttf"), 10);
    
    //Load harp image
    harp.load("harp.png");
    
    //Load samples for 3 octaves from data folder
    c3.load("00C3.wav");
    d3.load("00D3.wav");
    e3.load("00E3.wav");
    f3.load("00F3.wav");
    g3.load("00G3.wav");
    a3.load("01A3.wav");
    b3.load("01B3.wav");
    c3s.load("00C3s.wav");
    d3s.load("00D3s.wav");
    f3s.load("00F3s.wav");
    g3s.load("00G3s.wav");
    a3s.load("01A3s.wav");
    
    c4.load("01C4.wav");
    d4.load("01D4.wav");
    e4.load("01E4.wav");
    f4.load("01F4.wav");
    g4.load("01G4.wav");
    a4.load("02A4.wav");
    b4.load("02B4.wav");
    c4s.load("01C4s.wav");
    d4s.load("01D4s.wav");
    f4s.load("01F4s.wav");
    g4s.load("01G4s.wav");
    a4s.load("02A4s.wav");
    
    c5.load("02C5.wav");
    d5.load("02D5.wav");
    e5.load("02E5.wav");
    f5.load("02F5.wav");
    g5.load("02G5.wav");
    a5.load("03A5.wav");
    b5.load("03B5.wav");
    c5s.load("02C5s.wav");
    d5s.load("02D5s.wav");
    f5s.load("02F5s.wav");
    g5s.load("02G5s.wav");
    a5s.load("03A5s.wav");
    
    
    //Create 12 pointers of type ofColor
    col.push_back(new ofColor(255, 0, 0));
    col.push_back(new ofColor(0, 0, 255));
    col.push_back(new ofColor(0, 255, 0));
    col.push_back(new ofColor(247, 240, 0));
    col.push_back(new ofColor(247, 112, 0));
    col.push_back(new ofColor(110, 0, 220));
    col.push_back(new ofColor(0, 0, 0));
    col.push_back(new ofColor(0, 247, 146));
    col.push_back(new ofColor(157, 250, 0));
    col.push_back(new ofColor(255, 28, 97));
    col.push_back(new ofColor(255, 159, 3));
    col.push_back(new ofColor(170, 170, 170));
    
    
    //Create 7 pointers of type Scale with different names
    scale.push_back((new Scale(21, 45, "C", &myfont)));
    scale.push_back((new Scale(64, 45, "D", &myfont)));
    scale.push_back((new Scale(107, 45, "E", &myfont)));
    scale.push_back((new Scale(21, 90, "F", &myfont)));
    scale.push_back((new Scale(64, 90, "G", &myfont)));
    scale.push_back((new Scale(107, 90, "A", &myfont)));
    scale.push_back((new Scale(64, 135, "B", &myfont)));

    
//    //create 12 pointers of type note with different colors and positions on the grid.
    note.push_back(new Note(175, 105, *col[0], &myfont2, &myfont3));
    note.push_back(new Note(200, 105, *col[1], &myfont2, &myfont3));
    note.push_back(new Note(225, 105, *col[2], &myfont2, &myfont3));
    note.push_back(new Note(250, 105, *col[3], &myfont2, &myfont3));
    note.push_back(new Note(275, 105, *col[4], &myfont2, &myfont3));
    note.push_back(new Note(300, 105, *col[5], &myfont2, &myfont3));
    note.push_back(new Note(325, 105, *col[6], &myfont2, &myfont3));
    note.push_back(new Note(187, 80, *col[7], &myfont2, &myfont3));
    note.push_back(new Note(212, 80, *col[8], &myfont2, &myfont3));
    note.push_back(new Note(262, 80, *col[9], &myfont2, &myfont3));
    note.push_back(new Note(287, 80, *col[10], &myfont2, &myfont3));
    note.push_back(new Note(312, 80, *col[11], &myfont2, &myfont3));
    
    //Initialize boolean vector with 7 values
    key.resize(7);

    
}

//Call deconstructor to delate objects in the heap
ofApp::~ofApp(){
//    for (ofColor *c : col){
//        delete c;
//    }
    for (Note *n : note) {
        delete n;
    }
    for (Circle *cir : circle) {
        delete cir;
    }
    for (Scale *s : scale) {
        delete s;
    }
}


//--------------------------------------------------------------
void ofApp::draw(){
    
    //set background to a gradient
    ofBackgroundGradient(ofColor(250, 200, 250), ofColor(30, 10, 30), OF_GRADIENT_CIRCULAR);
    
    //Display Scale buttons
    for(auto s: scale){
        s->display();
    }
    //Set color and draw the string with the "Select scale" instruction
    ofSetColor(255);
    ofFill();
    myfont2.drawString("Select Scale", 27, 35);
    
    //Draw line to delimitate the space where the user can add Circle objects
    ofSetColor(0);
    ofDrawLine(0, 207, 600, 207);
    
    //Resize and display harp image
    harp.resize(90, 130);
    harp.draw(470, 43);
    
    //Call grid function for every note object to draw grid of notes
    for (int i=0; i<note.size(); i++) {
        note[i]->grid();

    }
    
    
    //Scale selector
    /*When the user select a Scale, the Note objects that correspond
     to the notes in the scale will be displayed using the display
     function in the Note class.
     By calling the display function the program will also display
     the instruction "Select Colour/Note" and the names under the
     notes.*/
    
    if (key[0])
    {
        scale[0]->selected();
        note[0]->display();
        note[1]->display();
        note[2]->display();
        note[3]->display();
        note[4]->display();
        note[5]->display();
        note[6]->display();
    }
    
    if (key[1])
    {
        scale[1]->selected();
        note[7]->display();
        note[1]->display();
        note[2]->display();
        note[9]->display();
        note[4]->display();
        note[5]->display();
        note[6]->display();
    }
    
    if (key[2])
    {
        scale[2]->selected();
        note[7]->display();
        note[8]->display();
        note[2]->display();
        note[9]->display();
        note[10]->display();
        note[5]->display();
        note[6]->display();
    }

    if (key[3])
    {
        scale[3]->selected();
        note[0]->display();
        note[1]->display();
        note[2]->display();
        note[3]->display();
        note[4]->display();
        note[5]->display();
        note[11]->display();
    }
    
    if (key[4])
    {
        scale[4]->selected();
        note[0]->display();
        note[1]->display();
        note[2]->display();
        note[9]->display();
        note[4]->display();
        note[5]->display();
        note[6]->display();
    }
    
    if (key[5])
    {
        scale[5]->selected();
        note[7]->display();
        note[1]->display();
        note[2]->display();
        note[9]->display();
        note[10]->display();
        note[5]->display();
        note[6]->display();
    }
    
    if (key[6])
    {
        scale[6]->selected();
        note[7]->display();
        note[8]->display();
        note[2]->display();
        note[9]->display();
        note[10]->display();
        note[11]->display();
        note[6]->display();
    }
    
    
    /*Every time the user select a scale and a note the istruction to add Circles and to start again will be displayed.*/
    if (selected) {
        ofSetColor(255);
        ofFill();
        myfont3.drawString("Click on the space below to add new objects, relax and hear them bounce", 55, 195);
        myfont2.drawString("Start again!", 450, 35);
    }
    
    
    /*Go through all the Circle elements and call the update and display functions for each of them*/
    for (int i=0; i<circle.size(); i++) {
        circle[i]->update();
        circle[i]->display();
    }
    
    /*Every time a rectangle bounce off one of the edges an audio
     sample will be triggered according to the colour of the rectangle
     that is bouncing.*/
    for (int i=0; i<circle.size(); i++) {
        
        //If the rectangles bounce off the upper part of the edges it
        //they would play from the note c5 to b5.
        if ((circle[i]->posX<7 && circle[i]->posY<273) || (circle[i]->posX>ofGetWidth()-7 && circle[i]->posY<273) || circle[i]->posY<218){
            
            //All these conditions check if the colour of the Circle correspond to the Note colour and play a sample accordingly
            if(circle[i]->clr == note[0]->col){
                c5.play();
            }
            if(circle[i]->clr==note[1]->col){
                d5.play();
            }
            if(circle[i]->clr==note[2]->col){
                e5.play();
            }
            if(circle[i]->clr==note[3]->col){
                f5.play();
            }
            if(circle[i]->clr==note[4]->col){
                g5.play();
            }
            if(circle[i]->clr==note[5]->col){
                a5.play();
            }
            if(circle[i]->clr==note[6]->col){
                b5.play();
            }
            if(circle[i]->clr==note[7]->col){
                c5s.play();
            }
            if(circle[i]->clr==note[8]->col){
                d5s.play();
            }
            if(circle[i]->clr==note[9]->col){
                f5s.play();
            }
            if(circle[i]->clr==note[10]->col){
                g5s.play();
            }
            if(circle[i]->clr==note[11]->col){
                a5s.play();
            }

        }
        
        //If the rectangles bounce off the middle part of the edges it
        //they would play from the note c4 to b4.
        if ((circle[i]->posX<7 && circle[i]->posY>273 && circle[i]->posY<637) || (circle[i]->posX> ofGetWidth()-7 && circle[i]->posY>273 && circle[i]->posY<637)){
            if(circle[i]->clr == note[0]->col){
                c4.play();
            }
            if(circle[i]->clr==note[1]->col){
                d4.play();
            }
            if(circle[i]->clr==note[2]->col){
                e4.play();
            }
            if(circle[i]->clr==note[3]->col){
                f4.play();
            }
            if(circle[i]->clr==note[4]->col){
                g4.play();
            }
            if(circle[i]->clr==note[5]->col){
                a4.play();
            }
            if(circle[i]->clr==note[6]->col){
                b4.play();
            }
            if(circle[i]->clr==note[7]->col){
                c4s.play();
            }
            if(circle[i]->clr==note[8]->col){
                d4s.play();
            }
            if(circle[i]->clr==note[9]->col){
                f4s.play();
            }
            if(circle[i]->clr==note[10]->col){
                g4s.play();
            }
            if(circle[i]->clr==note[11]->col){
                a4s.play();
            }
        }
        
        //If the rectangles bounce off the lower part of the edges it
        //they would play from the note c3 to b3.
        if ((circle[i]->posX<7 && circle[i]->posY>637) || (circle[i]->posX>ofGetWidth()-7 && circle[i]->posY>637) || (circle[i]->posY> ofGetHeight()-7)){
            if(circle[i]->clr==note[0]->col){
                c3.play();
            }
            if(circle[i]->clr==note[1]->col){
                d3.play();
            }
            if(circle[i]->clr==note[2]->col){
                e3.play();
            }
            if(circle[i]->clr==note[3]->col){
                f3.play();
            }
            if(circle[i]->clr==note[4]->col){
                g3.play();
            }
            if(circle[i]->clr==note[5]->col){
                a3.play();
            }
            if(circle[i]->clr==note[6]->col){
                b3.play();
            }
            if(circle[i]->clr==note[7]->col){
                c3s.play();
            }
            if(circle[i]->clr==note[8]->col){
                d3s.play();
            }
            if(circle[i]->clr==note[9]->col){
                f3s.play();
            }
            if(circle[i]->clr==note[10]->col){
                g3s.play();
            }
            if(circle[i]->clr==note[11]->col){
                a3s.play();
            }

        }
    }
}


//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
    //When a certain Scale is selected all the key booleans are switched to false and only the one that correspond to the selected scale will be switched back to true, so the program will only display the notes in the selected scale.
    
    // C  select scale
    if(mouseX>21 && mouseX<61 && mouseY>45 && mouseY<85){
        for(auto i: key){
            i = false;
        }
        key[0] = true;
    }
    
    // D  select scale
    if(mouseX>64 && mouseX<104 && mouseY>45 && mouseY<85){
        for(auto i: key){
            i = false;
        }
        key[1] = true;    }
    
    // E  select scale
    if(mouseX>107 && mouseX<147 && mouseY>45 && mouseY<85){
        for(auto i: key){
            i = false;
        }
        key[2] = true;    }
    
    // F  select scale
    if(mouseX>21 && mouseX<61 && mouseY>90 && mouseY<130){
        for(auto i: key){
            i = false;
        }
        key[3] = true;    }
    
    // G  select scale
    if(mouseX>64 && mouseX<104 && mouseY>90 && mouseY<130){
        for(auto i: key){
            i = false;
        }
        key[4] = true;    }
    
    // A  select scale
    if(mouseX>107 && mouseX<147 && mouseY>90 && mouseY<130){
        for(auto i: key){
            i = false;
        }
        key[5] = true;    }
    
    // B  select scale
    if(mouseX>64 && mouseX<104 && mouseY>135 && mouseY<175){
        for(auto i: key){
            i = false;
        }
        key[6] = true;    }
    
    //Colour selector
    /*Every time the user select a colour the variable clr will then change
     to the colour of the selected note.
     Every time a colour/note is selected the boolean select will be
     true, so the user will be able to add Circles with the selected
     colour.
     If a boolean was not used, the first Circle the user would add
     after selecting the colour would be a Circle with the colour
     that they previously selected instead of the current colour. */
    
    if(mouseX>175 && mouseX<200 && mouseY>105 && mouseY<130){
        clr = note[0]->col;
        selected = true;
    }
    if(mouseX>200 &&mouseX<225 && mouseY>105 && mouseY<130){
        clr = note[1]->col;
        selected = true;
    }
    if(mouseX>225 && mouseX<250 && mouseY>105 && mouseY<130){
        clr = note[2]->col;
        selected = true;
    }
    if(mouseX>250 &&mouseX<275 && mouseY>105 && mouseY<130){
        clr = note[3]->col;
        selected = true;
    }
    if(mouseX>275 && mouseX<300 && mouseY>105 && mouseY<130){
        clr = note[4]->col;
        selected = true;
    }
    if(mouseX>300 &&mouseX<325 && mouseY>105 && mouseY<130){
        clr = note[5]->col;
        selected = true;
    }
    if(mouseX>325 && mouseX<350 && mouseY>105 && mouseY<130){
        clr = note[6]->col;
        selected = true;
    }
    if(mouseX>187 &&mouseX<212 && mouseY>80 && mouseY<105){
        clr = note[7]->col;
        selected = true;
    }
    if(mouseX>212 && mouseX<237 && mouseY>80 && mouseY<105){
        clr = note[8]->col;
        selected = true;
    }
    if(mouseX>262 &&mouseX<287 && mouseY>80 && mouseY<105){
        clr = note[9]->col;
        selected = true;
    }
    if(mouseX>287 && mouseX<312 && mouseY>80 && mouseY<105){
        clr = note[10]->col;
        selected = true;
    }
    if(mouseX>312 &&mouseX<337 && mouseY>80 && mouseY<105){
        clr = note[11]->col;
        selected = true;
    }
    
    /*After the user select a scale and a colour they will be able to
     add Circles in the space below the line*/
    
    /*Every time the mouse is pressed below the line the program
     will create a new Circle object at the mouse location, with colour "clr"
     (which is the variable used to store the selected colour)*/
    
    if(mouseY>210 && selected){

        circle.push_back(new Circle(mouseX, mouseY, ofColor(clr)));
    }
    
    //Start again button.
    /*If the user press the harp button all the Circle elements will be erased.
     Also the boolean "selected" will be set to false, so the user is
     not able to add any rectangle before they select a note*/
    
    if(mouseX>470 && mouseX<560 && mouseY>43 && mouseY<173){
        circle.erase(circle.begin(), circle.end());
        selected= false;
    }
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
