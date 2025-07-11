// this file is to keep track of scenes currently in use, which will allow us to swicth scenes 

#pragma once 

#include <memory>
#include "Scene.hpp"

class SceneManager{
    private:
        std::unique_ptr<Scene> currentScene;//current scene is a unique pointer to a scnee object 
//when scene manager is destroyed the scene is also destroyed 
    public:
        void changeScene(std::unique_ptr<Scene> newScene ){
            currentScene = std::move(newScene);
        }

        Scene* getCurrentscene(){//get the current scene 
            return currentScene.get();
        }



};