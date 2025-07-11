//scene .hpp is going to create the parent class for all scenes, we will amnage the game through a scene manager and
//derive the scenes from this one class

#pragma once 
#include <SFML/Graphics.hpp>

//this is the base class 

class Scene{
    public:
        virtual ~Scene (){}//base destructor

        virtual void handleEvent(sf::Event &event)=0; //handles events from keyboard

        virtual void update(float dt) = 0; //update the game scene logic animations ect 

        virtual void render(sf::RenderWindow& window) = 0;
        //setting these equal to 0 forces every derived class to impliment its own version of these





};