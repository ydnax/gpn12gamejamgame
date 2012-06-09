
#include "boxtools.hpp"

namespace picppgl{
/*
bool boxCollide(const objinfo &A, const objinfo &B){
    //The sides of the rectangles
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    //Calculate the sides of rect A
    leftA = A.p.x - A.w/2;
    rightA = A.p.x + A.w/2;
    topA = A.p.y - A.h/2;
    bottomA = A.p.y + A.h/2;
        
    //Calculate the sides of rect B
    leftB = B.p.x - B.w/2;
    rightB = B.p.x + B.w/2;
    topB = B.p.y - B.h/2;
    bottomB = B.p.y + B.h/2;
    
    if( bottomA <= topB )
        return false;
    if( topA >= bottomB )
        return false;
    if( rightA <= leftB )
        return false;
    if( leftA >= rightB )
        return false;

    return true;
}//*/

/*bool boxInsideBox(const objinfo &A, const objinfo &B){
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    //Calculate the sides of rect A
    leftA = A.p.x - A.w/2;
    rightA = A.p.x + A.w/2;
    topA = A.p.y - A.h/2;
    bottomA = A.p.y + A.h/2;
        
    //Calculate the sides of rect B
    leftB = B.p.x - B.w/2;
    rightB = B.p.x + B.w/2;
    topB = B.p.y - B.h/2;
    bottomB = B.p.y + B.h/2;
    if(topA>topB)
        return false;
    if(leftA>leftB)
        return false;
    if(bottomA<bottomB)
        return false;
    if(rightA<rightB)
        return false;
    return true;
}//*/


bool boxOutsideBox(const objinfo &A, const objinfo &B){
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    //Calculate the sides of rect A
    leftA = A.p.x ;
    rightA = A.p.x +A.w;
    topA = A.p.y ;
    bottomA = A.p.y + A.h;
    //Calculate the sides of rect B
    leftB = B.p.x ;
    rightB = B.p.x+B.w;
    topB = B.p.y ;
    bottomB = B.p.y + B.h;

    if(topA>bottomB)
        return true;
    if(leftA>rightB)
        return true;
    if(bottomA<topB)
        return true;
    if(rightA<leftB)
        return true;
    return false;
}


}