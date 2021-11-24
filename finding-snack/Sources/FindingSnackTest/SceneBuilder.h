#pragma once

#include "FindingSnack.h"
// Abstract Builder
class SceneBuilder
{
protected:
    // 위 혹은 아래 결정해야함 
    ScenePtr mainMenuScene; 
    //FindingSnack* findingSnack;

public:
    SceneBuilder() {}

    virtual ~SceneBuilder() {}

    ScenePtr getScene() { return mainMenuScene; }

    // reset 미사용 
    void createNewSceneProduct() { mainMenuScene = Scene::create("MainMenuScene", "Images/startScene.PNG"); }

    // 다른 같은이름의 함수와 충돌발생가능성 확인 
    virtual void enter() = 0;
    virtual void exit() = 0;
    virtual void update() = 0;
    virtual void draw() = 0;
    virtual void event() = 0;

};
