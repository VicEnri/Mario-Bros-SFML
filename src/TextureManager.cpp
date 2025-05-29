#include <iostream>

#include "../headers/TextureManager.h"

std::unordered_map<std::string, sf::Texture> TextureManager::textures;

sf::Texture& TextureManager::getTexture(const std::string& filename){
    if(textures.find(filename) == textures.end()){
        sf::Texture texture;
        if(!texture.loadFromFile(filename))
            throw std::runtime_error("Errore nel caricamento della texture: " + filename);
        textures[filename] = std::move(texture);
    }
    return textures[filename];
}
