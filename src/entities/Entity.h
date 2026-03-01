#pragma once
#include "../GameObject.h"

class Entity : public GameObject {
public:
    float speed = 100;

    Entity(float startX = 0, float startY = 0)
        : GameObject(startX, startY) {}

    virtual ~Entity() = default;

protected:
    void Move(float dx, float dy, float dt) {
        x += dx * speed * dt;  // better way to implemnt speed make its frame independent
        y += dy * speed * dt;
    }
};