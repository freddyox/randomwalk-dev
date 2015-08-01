#ifndef RANDOMWALKER_HH
#define RANDOMWALKER_HH

#include <SFML/Graphics.hpp>

class RandomWalker : public sf::Drawable, public sf::Transformable {

private:
float displayx, displayy;
float stepsize;
float stepnumber;
sf::Vector2f origin;
sf::CircleShape drunkard;
sf::VertexArray lines;
int counter;
std::vector<sf::VertexArray> path;

public:
//displayx,displayy,stepnumber,stepsize
RandomWalker(float,float,float,float);
~RandomWalker() {};

void draw(sf::RenderTarget&, sf::RenderStates) const;

void walk(int);
sf::Vector2f drunkardPosition() { return drunkard.getPosition(); }

};
#endif
