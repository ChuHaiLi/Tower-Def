#include "TextureManager.h"
#include <iostream>

//Load texture cho các loại, tránh lỗi ảnh trắng
bool TextureManager::loadTexture(const std::string& key, const std::string& filename) {
    if (textureMap.find(key) != textureMap.end())
        return true;

    sf::Texture tex;
    if (!tex.loadFromFile(filename)) {
        std::cerr << "Failed to load texture: " << filename << std::endl;
        return false;
    }
    textureMap[key] = tex;
    return true;
}

const sf::Texture* TextureManager::getTexture(const std::string& key) const {
    auto it = textureMap.find(key);
    if (it != textureMap.end())
        return &(it->second);
    return nullptr;
}
