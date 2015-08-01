//    ************************************************************
//    *                        Random Walk                       *
//    *                        August 2015                       *
//    ************************************************************
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include <iostream>

#include "../include/RandomWalker.hh"


const float gDisplayx = 1000;
const float gDisplayy = 1000;
int main() {
  //GAME SETUP
  sf::RenderWindow window(sf::VideoMode(gDisplayx,gDisplayy), "Random Walk");
  window.setFramerateLimit(60);

  // Handling Time 
  sf::Clock clock;
  float t = 0.0;
  float dt = 1.0/60.0;
  sf::Time time;
  int clicker=0;

  //////////////////////////////////////////////////////
  //                   Parameters                     //
  //////////////////////////////////////////////////////
  float stepnumber = 100;
  float stepsize = 50;
  // Initializations
  RandomWalker drunkard( window.getSize().x, window.getSize().y, stepnumber, stepsize );

  while( window.isOpen() ) {

    sf::Event event;
    while( window.pollEvent(event) ) {
      if( event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) ) {
	window.close();
      }
    }
    window.clear(sf::Color::Black);

    // UPDATING
    drunkard.walk(clicker);

    // DRAWINGS
    window.draw( drunkard );
 
    window.display();   

    t += dt;
    clicker++;
  }

  return 0;
}
