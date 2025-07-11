#include <SFML/Graphics.hpp>
#include "SceneManager.hpp"
#include "MainMenu.hpp"

int main(){
    sf::RenderWindow window(sf::VideoMode(800,600),"My game");

    SceneManager sceneManager;
    sceneManager.changeScene(std::make_unique<MainMenu>(sceneManager));

    sf::Clock clock;

    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window.close();
            }
            if(sceneManager.getCurrentscene()){
                sceneManager.getCurrentscene()-> handleEvent(event);
            }
        }
        float dt = clock.restart().asSeconds();

        if(sceneManager.getCurrentscene()){
            sceneManager.getCurrentscene()->update(dt);
        }

        if(sceneManager.getCurrentscene()){
            sceneManager.getCurrentscene()->render(window);
        }


    }

    return 0;
}
