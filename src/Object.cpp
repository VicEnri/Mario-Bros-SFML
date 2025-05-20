#include "../headers/Object.h"

Object::Object(ObjectType type)
    : type(type), rect({{0.f, 0.f}, {0.f, 0.f}}) {}