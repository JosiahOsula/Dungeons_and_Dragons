#include "MainMenu.hpp"
#include <iostream>

MainMenu::MainMenu(SceneManager& manager) : sceneManager(manager){// initialize manager 
    if(!font.loadFromFile("assets/font/arial.ttf")){
        std::cerr<<"failed to load font!";
    }

    titleText.setFont(font);
    titleText.setString("undertal");
    titleText.setCharacterSize(48);
    titleText.setFillColor(sf::Color::White);
    titleText.setPosition(100.f,50.f);

    
    startText.setFont(font);
    startText.setString("Start Game");
    startText.setCharacterSize(36);
    startText.setFillColor(sf::Color::Yellow);
    startText.setPosition(120.f, 150.f);

    
    settingsText.setFont(font);
    settingsText.setString("Settings");
    settingsText.setCharacterSize(36);
    settingsText.setFillColor(sf::Color::White);
    settingsText.setPosition(120.f, 200.f);

}

void MainMenu::handleEvent(sf::Event&event){
    if(event.type==sf::Event::KeyPressed){
        if (event.key.code == sf::Keyboard::Up||event.key.code == sf::Keyboard::Down){
            selectedOption = 1 - selectedOption;

            if (selectedOption == 0){
                startText.setFillColor(sf::Color::Yellow);
                settingsText.setFillColor(sf::Color::White);
            }
            else{
                startText.setFillColor(sf::Color::White);
                settingsText.setFillColor(sf::Color::Yellow);
            }
        }
        else if (event.key.code == sf::Keyboard::Enter){
            if(selectedOption == 0 ){
                std::cout<<"start game selected \n";
                //make a note here that we call the scene manager to bring us to start game 
            }
            else {
                std::cout<<"settings screen \n";
            }
        }


    }
}

void MainMenu::update(float dt){
    //where we need to update logic but notjing yet 
}

void MainMenu::render(sf::RenderWindow& window){
    window.clear(sf::Color::Black);
    window.draw(titleText);
    window.draw(startText);
    window.draw(settingsText);
    window.display();
}