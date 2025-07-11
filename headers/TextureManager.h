#pragma once

#include<SFML/Graphics.hpp>
#include<unordered_map>
#include<string>

class TextureManager{
    public:
        static sf::Texture& getTexture(const std::string& filename);
        static void clear() {textures.clear();}

    private:
        static std::unordered_map<std::string, sf::Texture> textures;
};