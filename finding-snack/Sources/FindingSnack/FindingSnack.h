#pragma once
#include <bangtal>

using namespace bangtal;
// Product
class FindingSnack
{
// private or protected (MainMenu에서 잘 동작하는지 확인 필요)
protected:
    // 변수와 메소드 Scene기반으로 나눌것인지, 아님 getter setter 등의 기준으로 나눌것인지 
    // => 일단 Scene 기반 

    // getter setter 가 필요한가 ??? reset 은 ???
    // 필드를 protected || private로 두면 필요할듯하다. 바로 접근 불가능 
    // => 다만들어보고 필요없으면 지우고 어떤지 확인 해보기 


    // getter setter 가 많이 필요할것.
    // 불필요한 곳에도 상속이 전부 될것.


    // 변수들을 어디에서 초기화 할 것인가. 
    // Component 안에서 ? || FindingSnack 에서 ? 
    // => Component 안에서. 



    // 스테이지 총 30개 (30을 상수?화)


    // MainMenuData 
    ScenePtr mainMenuScene;
    ObjectPtr startBtn; 

    // MainMenuData 

    // StageSelectData
    ScenePtr stageSelectScene;

    const int STAGE_MAX = 30;
    // isClear[30];
    // 

    // 
    ScenePtr stagesScene[30];

public:
    // Constructor 
    FindingSnack() {
        //mainMenuScene = Scene::create("MainMenuScene", "Images/Background/startScene.PNG");

        //stageSelectScene = NULL;
        //for (int i = 0; i < 30; i++) stagesScene[i] = NULL;
    }
    ~FindingSnack() {}
    // Constructor 





    // MainMenuMethod

    // setter 
    void setMainMenuScene(ScenePtr s) { mainMenuScene = s; };
    void setMainMenuStartBtn(ObjectPtr o) { startBtn = o; }; 

    // getter 
    ScenePtr getMainMenuScene() { return mainMenuScene; };
    ObjectPtr getMainMenuStartBtn() { return startBtn; };


    // reset 
    void resetMainMenu() { mainMenuScene = Scene::create("MainMenuScene", "Images/Background/startScene.png"); }; // 초기화 & 리셋 함수
   
    // MainMenuMethod 










    void setStageSelectScene(ScenePtr ss) { stageSelectScene = ss; };
    // 30 -> STAGE_MAX
    void SetStages(ScenePtr s[30]) { for (int i = 0; i < 30; i++) stagesScene[i] = s[i]; };




    // err: 예외가 발생함 
    void start() { startGame(mainMenuScene); };

    // virtual 이 아닌 overriding한 것으로 오류 생기는 지 지속적인 확인 필요 
    void enter();
    void exit();
    void update();
    void draw();
    void event();

};
