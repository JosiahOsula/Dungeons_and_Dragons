//main menu scene definitoioin, this will inherit the scnee

#pragma once 

#include<SFML/Graphics.hpp>
#include "Scene.hpp"
#include "SceneManager.hpp"

class MainMenu: public Scene{
    private:
        SceneManager& sceneManager; //reference to scene manager to change scenes 
        sf::Font font ; //the font we useto draw text 
        sf::Text titleText;
        sf::Text startText;
        sf::Text settingsText;
        int selectedOption = 0; //keeps track of the option chosen

    public:
        MainMenu(SceneManager& manager); //constructor 

        void handleEvent(sf::Event& event) override;
        void update(float dt) override;
        void render(sf::RenderWindow& window) override;

};