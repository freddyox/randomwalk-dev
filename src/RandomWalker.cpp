#include "../include/RandomWalker.hh"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

RandomWalker::RandomWalker(float width, float height, float stepN, float stepS) {
  displayx = width;
  displayy = height;

  // Parameters
  origin = sf::Vector2f(displayx/2.0,displayy/2.0);
  stepsize = stepS;
  stepnumber = stepN;
  counter = 0;

  // The Drunkard
  float radius = 5.0;
  drunkard.setRadius( radius );
  sf::FloatRect drunkardRect = drunkard.getLocalBounds();
  drunkard.setOrigin( drunkardRect.width/2.0, drunkardRect.height/2.0 );
  drunkard.setFillColor( sf::Color(47,154,247));
  drunkard.setPosition( origin );

  // Following the Drunk
  lines = sf::VertexArray(sf::LinesStrip,2);
}

void RandomWalker::draw( sf::RenderTarget& target, sf::RenderStates) const {
  target.draw( drunkard );
  std::vector<sf::VertexArray>::const_iterator cit;
  for(cit=path.begin(); cit != path.end(); cit++)
    target.draw(*cit);
}

void RandomWalker::walk(int clicker) {
  // Random numbers correspond to the following:
  // 1 = -x
  // 2 = -y
  // 3 = +x
  // 4 = +y
  if( clicker % 60 == 0 ) {
    counter++;
    srand(time(NULL));  
    int nextMove = rand() % 4 + 1;
  
    // needs works
    sf::Vector2f temp = drunkard.getPosition();
    if( temp.x > displayx ) {
      drunkard.setPosition( 0, temp.y );
    }
    if( temp.x < 0 ) {
      drunkard.setPosition( displayx, temp.y );
    }
    if( temp.y > displayy ) {
      drunkard.setPosition( temp.x, 0 );
    }
    if( temp.y < 0 ) {
      drunkard.setPosition( temp.x, displayy );
    }
    
      
  switch( nextMove ){
  case 1 :
    drunkard.move( -stepsize, 0 );
    lines[0].position = sf::Vector2f(temp.x,temp.y);
    lines[0].color = sf::Color::Red;
    lines[1].position = sf::Vector2f(temp.x-stepsize,temp.y);
    lines[1].color = sf::Color::Blue;
    path.push_back(lines);
    break;
  case 2:
    drunkard.move( 0, -stepsize );
    lines[0].position = sf::Vector2f(temp.x,temp.y);
    lines[0].color = sf::Color::Green;
    lines[1].position = sf::Vector2f(temp.x,temp.y-stepsize);
    lines[1].color = sf::Color::Magenta;
    path.push_back(lines);
    break;
  case 3:
    drunkard.move( stepsize, 0 );
    lines[0].position = sf::Vector2f(temp.x,temp.y);
    lines[0].color = sf::Color::Blue;
    lines[1].position = sf::Vector2f(temp.x + stepsize,temp.y);
    lines[1].color = sf::Color::Green;
    path.push_back(lines);
    break;
  case 4:
    drunkard.move( 0, stepsize );
    lines[0].position = sf::Vector2f(temp.x,temp.y);
    lines[0].color = sf::Color::Yellow;
    lines[1].position = sf::Vector2f(temp.x,temp.y+stepsize);
    lines[1].color = sf::Color::Blue;
    path.push_back(lines);
    break;
  default :
    drunkard.move(0,0);
    break;
    }
  }
  // Follow the Drunkard
  
}
