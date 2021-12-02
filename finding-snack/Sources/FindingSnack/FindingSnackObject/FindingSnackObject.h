#pragma once

#include "../FindingSnack.h"


using namespace bangtal;
// Product
class FindingSnackObject : public FindingSnack
{

protected:


    // IntroData
    // IntroData ���� �����ʹ� component�� ���� 
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
    // StageData ���õ� �����ʹ� StageComponent�� ����Ǿ� ����. 
 
    //ScenePtr stagesScene[STAGE_MAX];
    ScenePtr stageScene;



    // StagesData  --------------------------------------------------------------------------------------------------  

public:

    // Constructor 
    // ���⼭ Components �����Ѵٸ� ?
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

    // reset  //void resetMainMenu() { mainMenuScene = Scene::create("MainMenuScene", "Images/Background/startScene.png"); }; // �ʱ�ȭ & ���� �Լ�

    // MainMenuMethod --------------------------------------------------------------------------------------------------  

    // StageSelectMethod --------------------------------------------------------------------------------------------------  
    void setStageSelectScene(ScenePtr s) { stageSelectScene = s; };
    ScenePtr getStageSelectScene() { return stageSelectScene; };
    void setStagesBtns(ObjectPtr o, int index) { stagesBtns[index] = o; };
    ObjectPtr getStagesBtns(int index) { return stagesBtns[index]; };
    void setMainMenuBtn(ObjectPtr o) { mainMenuBtn = o; };
    ObjectPtr getMainMenuBtn() { return mainMenuBtn; };
    // �� �������� Ȯ�ο� 
    void setClearStage(int index, bool isClear) { clearStage[index] = isClear; };
    bool getClearStage(int index) { return clearStage[index]; };
    // ���� Ŭ���� �������� Ȯ�ο� 
    void setCurrentStage(int stageNum) { currentStage = stageNum; };
    int getCurrentStage() { return currentStage; };

    void setClickedStage(int stageNum) { clickedStage = stageNum; };
    int getClickedStage() { return clickedStage; };



    // StageSelectMethod  --------------------------------------------------------------------------------------------------  


    // StageMethod  --------------------------------------------------------------------------------------------------  

    void setStage(ScenePtr s) { stageScene = s; };
    ScenePtr getStage() { return stageScene; };
    // StageMethod --------------------------------------------------------------------------------------------------  




    // ���� ��Ʈ�η� ���۵ǰ� ����������� !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
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
    
    //void makeStage(int stageNum) {};


};
