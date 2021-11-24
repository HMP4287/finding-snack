#pragma once

#include <iostream>
#include <memory>
#include <string>
#include <bangtal>


using namespace bangtal;
// Product
class FindingSnack
{
// private or protected (private�� gettersetter������ ������ getterSetter �� �����Ұű��ؼ�, private�� ��������.)
//private:
protected:
    // test �ϳ��� findingSnack�� �α����� 
    //FindingSnack* root;

    ScenePtr mainMenuScene;
    ScenePtr stageSelectScene;
    ScenePtr stagesScene[30];
    int temp;

public:
    // �ӽ÷� �ۺ� ȭ 
    //FindingSnack* root;
    FindingSnack() {}
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
    // virtual ���� -> �׳� �������̵����� ���� ���� => �ν��Ͻ� ������ �Ұ�����  

    void enter();
    void exit();
    void update();
    void draw();
    void event();

};
