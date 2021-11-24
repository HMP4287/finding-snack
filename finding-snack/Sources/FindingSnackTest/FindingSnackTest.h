#pragma once

#include <iostream>
#include <memory>
#include <string>
#include <bangtal>


using namespace bangtal;
// Product
class FindingSnack
{
// or protected
private:
    ScenePtr mainMenuScene;
    ScenePtr stageSelectScene;
    ScenePtr stagesScene[30];

public:
    FindingSnack() { }
    ~FindingSnack() { }

    void setMainMenuScene(ScenePtr mm) { mainMenuScene = mm; };
    void setStageSelectScene(ScenePtr ss) { stageSelectScene = ss; };
    void SetStages(ScenePtr s[30]) { for (int i = 0; i < 30; i++) stagesScene[i] = s[i]; } // 30 상수화 

    ScenePtr getMainMenuScene() { return mainMenuScene; }

    // reset 미사용 
    // reset 의 개념임 
    void createNewSceneProduct() { mainMenuScene = Scene::create("MainMenuScene", "Images/startScene.PNG"); }

    void start() {
        startGame(mainMenuScene);
    }

    // 다른 같은이름의 함수와 충돌발생가능성 확인 
    virtual void enter() = 0;
    virtual void exit() = 0;
    virtual void update() = 0;
    virtual void draw() = 0;
    virtual void event() = 0;

};
