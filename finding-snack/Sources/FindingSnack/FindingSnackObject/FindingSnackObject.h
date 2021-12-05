#pragma once

#include "../FindingSnack.h"


using namespace bangtal;
class FindingSnackObject : public FindingSnack
{

protected:


    // IntroData start  --------------------------------------------------------------------------------------------------  
    // 인트로 관련 데이터는 component에 저장되어 있음. 
    ScenePtr introScene;
    // IntroData end  --------------------------------------------------------------------------------------------------  

    // MainMenuData start --------------------------------------------------------------------------------------------------  
    ScenePtr mainMenuScene;
    ObjectPtr startBtn;
    ObjectPtr gameInfoBtn;
    ObjectPtr gameInfo; 
    ObjectPtr gameInfoOutBtn;
    // MainMenuData end --------------------------------------------------------------------------------------------------  

    // StageSelectData start --------------------------------------------------------------------------------------------------  
    ScenePtr stageSelectScene;
    ObjectPtr stageSelectBtn;
    ObjectPtr stagesBtns[STAGE_MAX];
    ObjectPtr mainMenuBtn;
    char unclearNumImgPath[STAGE_MAX][40];
    char clearNumImgPath[STAGE_MAX][40];
    int clearStage[STAGE_MAX];
    int currentStage;
    int clickedStage; 
    // StageSelectData  end --------------------------------------------------------------------------------------------------  
    
    // StagesData  --------------------------------------------------------------------------------------------------  
    // 각 Stage에 관련된 데이터는 StageComponent에 저장되어 있음. 
    ScenePtr stageScene;
    // StagesData  end --------------------------------------------------------------------------------------------------  

public:

    FindingSnackObject() {};
    ~FindingSnackObject() {};

    // IntroMethod start --------------------------------------------------------------------------------------------------  
    void setIntroScene(ScenePtr s) { introScene = s; };
    ScenePtr getIntroScene() { return introScene; };
    // IntroMethod end --------------------------------------------------------------------------------------------------  

    // MainMenuMethod start --------------------------------------------------------------------------------------------------  
    void setMainMenuScene(ScenePtr s) { mainMenuScene = s; };
    void setMainMenuStartBtn(ObjectPtr o) { startBtn = o; };
    void setGameInfoBtn(ObjectPtr o) { gameInfoBtn = o; };
    void setGameInfoOutBtn(ObjectPtr o) { gameInfoOutBtn = o; };
    void setGameInfo(ObjectPtr o) { gameInfo = o; };
    ScenePtr getMainMenuScene() { return mainMenuScene; };
    ObjectPtr getMainMenuStartBtn() { return startBtn; };
    ObjectPtr getGameInfoBtn() { return gameInfoBtn; };
    ObjectPtr getGameInfoOutBtn() { return gameInfoOutBtn; };
    ObjectPtr getGameInfo() { return gameInfo; };
    // MainMenuMethod end --------------------------------------------------------------------------------------------------  

    // StageSelectMethod start --------------------------------------------------------------------------------------------------  
    void setStageSelectScene(ScenePtr s) { stageSelectScene = s; };
    ScenePtr getStageSelectScene() { return stageSelectScene; };
    void setStagesBtns(ObjectPtr o, int index) { stagesBtns[index] = o; };
    ObjectPtr getStagesBtns(int index) { return stagesBtns[index]; };
    void setMainMenuBtn(ObjectPtr o) { mainMenuBtn = o; };
    ObjectPtr getMainMenuBtn() { return mainMenuBtn; };
    void setClearStage(int index, bool isClear) { clearStage[index] = isClear; };
    bool getClearStage(int index) { return clearStage[index]; };
    void setCurrentStage(int stageNum) { currentStage = stageNum; };
    int getCurrentStage() { return currentStage; };
    void setClickedStage(int stageNum) { clickedStage = stageNum; };
    int getClickedStage() { return clickedStage; };
    // StageSelectMethod end --------------------------------------------------------------------------------------------------  

    // StageMethod start --------------------------------------------------------------------------------------------------  
    void setStage(ScenePtr s) { stageScene = s; };
    ScenePtr getStage() { return stageScene; };
    // StageMethod end --------------------------------------------------------------------------------------------------  


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

};
