#pragma once

#include <iostream>
#include <memory>
#include <string>
#include <bangtal>


using namespace bangtal;
// Product
class FindingSnack
{
// private or protected (private시 gettersetter없으면 오류남 getterSetter 다 생성할거긴해서, private이 좋을듯함.)
//private:
protected:
    // test 하나의 findingSnack만 두기위함 
    //FindingSnack* root;

    ScenePtr mainMenuScene;
    ScenePtr stageSelectScene;
    ScenePtr stagesScene[30];
    int temp;

public:
    // 임시로 퍼블릭 화 
    //FindingSnack* root;
    FindingSnack() {}
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
    // virtual 에서 -> 그냥 오버라이딩으로 변경 이유 => 인스턴스 생성이 불가능함  

    void enter();
    void exit();
    void update();
    void draw();
    void event();

};
