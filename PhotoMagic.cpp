/*

Copyright [2021] <Justin Cheok>

*/
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <string>
#include <stdlib.h>
#include "FibLFSR.hpp"
using namespace std;

int main(int argc, char* argv[]) {
/* source filename */
std::string original_file;
/* output filename */
std::string encryption_file;

/* FibLFSR seed */
std::string bSeed;
int tap;
tap = 16;
if(argc == 4) {
original_file = argv[1];
encryption_file = argv[2];
bSeed = argv[3];
} else {
std::cout << "Error" << std::endl;;
}
sf::Image image;
sf::Image originalImage;
FibLFSR rand(bSeed, tap);

if(!originalImage.loadFromFile(original_file)) {
return -1;
}
if(!image.loadFromFile(original_file)) {
return -1;
}
sf::Color pixel;
sf::Vector2u size = image.getSize();
for(unsigned x = 0; x < size.x; x++) {
for(unsigned y = 0; y < size.y; y++) {
pixel = image.getPixel(x, y);
pixel.r = pixel.r ^ rand.generate(30);
pixel.g = pixel.g ^ rand.generate(30);
pixel.b = pixel.b ^ rand.generate(30);

image.setPixel(x, y, pixel);
}
}
sf::RenderWindow window(sf::VideoMode(size.x*2, size.y),"Encrypt");
sf::Texture texture, originalTexture;
texture.loadFromImage(image);
originalTexture.loadFromImage(originalImage);

sf::Sprite sprite, originalSprite;
sprite.setTexture(texture);
originalSprite.setTexture(originalTexture);
while (window.isOpen()) {
sf::Event event;
while (window.pollEvent(event)) {
if (event.type == sf::Event::Closed) {
window.close();
}
}
window.clear(sf::Color::White);
window.draw(originalSprite);
sprite.setPosition(sf::Vector2f(size.x, 0));
window.draw(sprite);
window.display();
}
if(!image.saveToFile(encryption_file)) {
return -1;
}
return 0;
}
