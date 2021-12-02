#pragma once

#include "../FindingSnack.h"


using namespace bangtal;
// Product
class FindingSnackObject : public FindingSnack
{

protected:


    // IntroData
    // IntroData 관련 데이터는 component에 저장 
    ScenePtr introScene;

    // MainMenuData  --------------------------------------------------------------------------------------------------  

    ScenePtr mainMenuScene;
    ObjectPtr startBtn;
    ObjectPtr gameInfoBtn;
    // MainMenuData  --------------------------------------------------------------------------------------------------  


    // StageSelectData --------------------------------------------------------------------------------------------------  

    ScenePtr stageSelectScene;
    ObjectPtr stageSelectBtn;

    ObjectPtr stagesBtns[STAGE_MAX];

    ObjectPtr mainMenuBtn;

    // StageStartBtn
    char unclearNumImgPath[STAGE_MAX][40];
    char clearNumImgPath[STAGE_MAX][40];


    int clearStage[STAGE_MAX];
    int currentStage;

    int clickedStage; 

    // StageSelectData   --------------------------------------------------------------------------------------------------  



    // StagesData  --------------------------------------------------------------------------------------------------  
    // StageData 관련된 데이터는 StageComponent에 저장되어 있음. 
 
    //ScenePtr stagesScene[STAGE_MAX];
    ScenePtr stageScene;



    // StagesData  --------------------------------------------------------------------------------------------------  

public:

    // Constructor 
    // 여기서 Components 구성한다면 ?
    FindingSnackObject() {};
    ~FindingSnackObject() {};
    // Constructor 

    // IntroMethod
    void setIntroScene(ScenePtr s) { introScene = s; };
    ScenePtr getIntroScene() { return introScene; };
    // IntroMethod

    // set Components --------------------------------------------------------------------------------------------------  


    // set Components --------------------------------------------------------------------------------------------------  



    // MainMenuMethod --------------------------------------------------------------------------------------------------  
    // setter 
    void setMainMenuScene(ScenePtr s) { mainMenuScene = s; };
    void setMainMenuStartBtn(ObjectPtr o) { startBtn = o; };
    void setGameInfoBtn(ObjectPtr o) { gameInfoBtn = o; };

    // getter 
    ScenePtr getMainMenuScene() { return mainMenuScene; };
    ObjectPtr getMainMenuStartBtn() { return startBtn; };
    ObjectPtr getGameInfoBtn() { return gameInfoBtn; };

    // reset  //void resetMainMenu() { mainMenuScene = Scene::create("MainMenuScene", "Images/Background/startScene.png"); }; // 초기화 & 리셋 함수

    // MainMenuMethod --------------------------------------------------------------------------------------------------  

    // StageSelectMethod --------------------------------------------------------------------------------------------------  
    void setStageSelectScene(ScenePtr s) { stageSelectScene = s; };
    ScenePtr getStageSelectScene() { return stageSelectScene; };
    void setStagesBtns(ObjectPtr o, int index) { stagesBtns[index] = o; };
    ObjectPtr getStagesBtns(int index) { return stagesBtns[index]; };
    void setMainMenuBtn(ObjectPtr o) { mainMenuBtn = o; };
    ObjectPtr getMainMenuBtn() { return mainMenuBtn; };
    // 깬 스테이지 확인용 
    void setClearStage(int index, bool isClear) { clearStage[index] = isClear; };
    bool getClearStage(int index) { return clearStage[index]; };
    // 현재 클릭한 스테이지 확인용 
    void setCurrentStage(int stageNum) { currentStage = stageNum; };
    int getCurrentStage() { return currentStage; };

    void setClickedStage(int stageNum) { clickedStage = stageNum; };
    int getClickedStage() { return clickedStage; };



    // StageSelectMethod  --------------------------------------------------------------------------------------------------  


    // StageMethod  --------------------------------------------------------------------------------------------------  

    void setStage(ScenePtr s) { stageScene = s; };
    ScenePtr getStage() { return stageScene; };
    // StageMethod --------------------------------------------------------------------------------------------------  




    // 추후 인트로로 시작되게 변경해줘야함 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    void start() { startGame(stageSelectScene); };
    // 객체가 생성될때 변수 초기화 및 초기 셋팅등 생성자 역할을 하게 된다.
    void enter() {};

    // 객체가 삭제/제거될때 메모리 삭제 등 소멸자 역할을 하게 된다.
    void exit() {};

    // 객체의 주 행동들을 작성하는 곳으로 특정 시간마다 변하는 애니메이션이나 타이밍을 체크 하며 다음과 같이 작성 할 수 있다.
    void update() {};

	// 화면에 그려질 부분을 컨트롤 하는 부분이다. 랜더링을 담당한다.
    void draw() {};

	// 사용자의 조작에 어떤반응을 할것인지를 컨트롤 할 수 있는 부분이다.
    void event() {};
    
    //void makeStage(int stageNum) {};


};
