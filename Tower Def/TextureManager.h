#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <string>
#include <unordered_map>
#include <SFML/Graphics.hpp>

class TextureManager {
private:
    std::unordered_map<std::string, sf::Texture> textureMap;

public:
    bool loadTexture(const std::string& key, const std::string& filename);
    const sf::Texture* getTexture(const std::string& key) const;
};

#endif
