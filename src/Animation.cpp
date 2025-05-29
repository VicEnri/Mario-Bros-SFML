#include<iostream>

#include"../headers/Animation.h"

Animation::Animation(float lenght) : 
    lenght(lenght), 
    currentTime(0.0f){
}

void Animation::addFrame(Frame frame){
    frames.push_back(frame);
}

sf::Texture* Animation::update(float deltaTime){
    
    currentTime += deltaTime; //aggiorna il tempo corrente
    while(currentTime >= lenght)
        currentTime -= lenght;
    for(auto& frame : frames){
        if(currentTime <= frame.time) 
            return frame.texture; //restituisce il frame corrente
    }
    return nullptr;
}