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
    void SetStages(ScenePtr s[30]) { for (int i = 0; i < 30; i++) stagesScene[i] = s[i]; } // 30 ���ȭ 

    ScenePtr getMainMenuScene() { return mainMenuScene; }

    // reset �̻�� 
    // reset �� ������ 
    void createNewSceneProduct() { mainMenuScene = Scene::create("MainMenuScene", "Images/startScene.PNG"); }

    void start() {
        startGame(mainMenuScene);
    }

    // �ٸ� �����̸��� �Լ��� �浹�߻����ɼ� Ȯ�� 
    virtual void enter() = 0;
    virtual void exit() = 0;
    virtual void update() = 0;
    virtual void draw() = 0;
    virtual void event() = 0;

};
