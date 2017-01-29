//
//  Button.hpp
//  projectHarp
//
//  Created by Elisabetta Motta on 02/12/2015.
//
//

#ifndef Button_hpp
#define Button_hpp

#include <stdio.h>

//Create a class for a base button that would be inherited by the classes Note and Scale.
class Button {
public:
    
    Button(float _x, float _y);
    
    float posX;
    float posY;
    
};


#endif /* Button_hpp */
