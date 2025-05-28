#pragma once

#include"Object.h"
#include"Global.h"
#include"Map.h"

struct checkCollisionResult{
    bool collided = false; //controlla se c'è stata una collisione
    bool grounded = false; //controlla se l'oggetto è a terra
};

class Collision{
    public:
        Collision(Map2D& map2D);

        checkCollisionResult checkCollision(float x, float y, float width, float height, float verticalVelocity);

    private:
        Map2D& map2D;
};