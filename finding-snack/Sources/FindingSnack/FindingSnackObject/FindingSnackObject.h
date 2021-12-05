#pragma once

#include "../FindingSnack.h"


using namespace bangtal;
class FindingSnackObject : public FindingSnack
{

protected:


    // IntroData start  --------------------------------------------------------------------------------------------------  
    // ��Ʈ�� ���� �����ʹ� component�� ����Ǿ� ����. 
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
    // �� Stage�� ���õ� �����ʹ� StageComponent�� ����Ǿ� ����. 
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
    // ��ü�� �����ɶ� ���� �ʱ�ȭ �� �ʱ� ���õ� ������ ������ �ϰ� �ȴ�.
    void enter() {};

    // ��ü�� ����/���ŵɶ� �޸� ���� �� �Ҹ��� ������ �ϰ� �ȴ�.
    void exit() {};

    // ��ü�� �� �ൿ���� �ۼ��ϴ� ������ Ư�� �ð����� ���ϴ� �ִϸ��̼��̳� Ÿ�̹��� üũ �ϸ� ������ ���� �ۼ� �� �� �ִ�.
    void update() {};

	// ȭ�鿡 �׷��� �κ��� ��Ʈ�� �ϴ� �κ��̴�. �������� ����Ѵ�.
    void draw() {};

	// ������� ���ۿ� ������� �Ұ������� ��Ʈ�� �� �� �ִ� �κ��̴�.
    void event() {};

};
