#pragma once

#include "FindingSnack.h"
// Abstract Builder
class SceneBuilder
{
protected:
    // �� Ȥ�� �Ʒ� �����ؾ��� 
    ScenePtr mainMenuScene; 
    //FindingSnack* findingSnack;

public:
    SceneBuilder() {}

    virtual ~SceneBuilder() {}

    ScenePtr getScene() { return mainMenuScene; }

    // reset �̻�� 
    void createNewSceneProduct() { mainMenuScene = Scene::create("MainMenuScene", "Images/startScene.PNG"); }

    // �ٸ� �����̸��� �Լ��� �浹�߻����ɼ� Ȯ�� 
    virtual void enter() = 0;
    virtual void exit() = 0;
    virtual void update() = 0;
    virtual void draw() = 0;
    virtual void event() = 0;

};
