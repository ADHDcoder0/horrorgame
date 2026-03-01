#pragma once
#include "raylib.h"
//GameObject is a abstract class 
class GameObject {

    public:
        float x,y;
        bool active = true;

        GameObject(float startX = 0, float startY = 0) : x(startX), y(startY) {}  // initilizer new concept best practice 
        virtual ~GameObject() = default;  // destructor for polymorphic base class
        virtual void Update(float dt) = 0;  // to convert it into a abstaract class and this function must be their in the derived calss these must be overridden
        virtual void Draw() const = 0; //const outside mean no modification to the obejct 



};      