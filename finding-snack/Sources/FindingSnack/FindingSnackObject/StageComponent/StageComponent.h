#pragma once
#include "../FindingSnackObject.h"

// Component
class StageComponent : public FindingSnackObject
{
public:
    FindingSnackObject* root;

    // Default Stage elements
    ScenePtr showStageScene; 
    TimerPtr showStageTimer;
    ScenePtr roomLeftScene;
    ScenePtr roomRightScene;
    ObjectPtr goRightRoomBtn;
    ObjectPtr goLeftRoomBtn;
    ObjectPtr stageRestartBtnL;
    ObjectPtr goBackMainMenuBtnL;
    ObjectPtr stageRestartBtnR;
    ObjectPtr goBackMainMenuBtnR;

    // stage1 
    ObjectPtr closet;
    ObjectPtr windowLeft;
    ObjectPtr windowRight; 
    ObjectPtr wallCloset; 
    ObjectPtr sofa;  
    ObjectPtr sofaCushionLeft;
    ObjectPtr sofaCushionRight;

    // stage2
    ObjectPtr puangBitjaru;
    ObjectPtr gymMan;
    ObjectPtr plant;
    ObjectPtr drawer;
    ObjectPtr bitjaru;
    ObjectPtr bitjaruTemp;
    bool burgerMoved;
    TimerPtr burgerMovedTimer;
    TimerPtr burgerMovedTimerAfter;

    // stage3
    ObjectPtr bookshelf;
    ObjectPtr book1;
    ObjectPtr book2;
    ObjectPtr book3;
    ObjectPtr bookTemp;
    ObjectPtr brokenChair;
    ObjectPtr brokenChairTemp;
    ObjectPtr stand;
    ObjectPtr puangJumping;
    TimerPtr puangFallDown;
    TimerPtr puangFallDownAfter;
    TimerPtr puangLovingTimer;
    int burgerReach;
    bool wallIsOpen;

    // stage4
    ObjectPtr car;
    ObjectPtr sign;
    ObjectPtr paint;
    ObjectPtr paintTemp;
    ObjectPtr paintingPuang;
    ObjectPtr carMan;
    TimerPtr puangComePaint;
    TimerPtr carManComming;
    int carManX;
    TimerPtr carManInside;
    TimerPtr carOut;
    int carX;
    
    // stage5
    ObjectPtr elephant;
    ObjectPtr ballon;
    ObjectPtr ballonGettingBig;
    TimerPtr gymManGymingFast;
    TimerPtr elephantBallonGetBig;
    ObjectPtr weight;
    ObjectPtr weightTemp; 
    int cntTwo; 
    double ballonScale;
    int ballonX;
    int ballonY;
    int gymManDStatus;
    int gymManSpeed; 
    int gymManY;

    // stage6
    ObjectPtr bottle;
    int windowStatus;
    ObjectPtr key;
    ObjectPtr cloud;
    TimerPtr keySpinTimer;
    TimerPtr gymManSpinTimer;
    bool gymManSpin;
    int gymStatus;
    bool keySpin;
    int keyStatus;
    bool closetUnlocked;
    
    // stage7
    ObjectPtr refrigeratorUp;
    ObjectPtr refrigeratorDown;
    ObjectPtr watermelon;
    ObjectPtr watermelonDesk;
    int puangHittingStatus;
    int hitCnt;
    ObjectPtr desk;
    ObjectPtr puangHitting;
    
    // stage8
    ObjectPtr fish; 
    ObjectPtr puangGivingFish;
    ObjectPtr fishTemp; 
    ObjectPtr chicken;
    ObjectPtr bigFish;
    ObjectPtr dish; 
    ObjectPtr gymManFood;
    ObjectPtr fly; 
    ObjectPtr flyLeft;
    int comeBigFishX;
    TimerPtr givingFish;
    TimerPtr comeBigFish;
    TimerPtr eatingFish;
    bool hamburgerCanClick;

    //stage 9   
    ObjectPtr sofaCushion;
    ObjectPtr bat1; 
    ObjectPtr bat2;
    ObjectPtr bottle1;
    ObjectPtr bottle2;
    ObjectPtr gymManTurn;
    ObjectPtr batTemp;
    ObjectPtr gymManBang;
    int gymManTurnStatus;
    int gymManTurnCnt;

    ObjectPtr star1; //window
    ObjectPtr star2; //bingle
    ObjectPtr star3; //bangsuk
    ObjectPtr star4; //mainmenu
    ObjectPtr star5; //bulga
    ObjectPtr starBox1;
    ObjectPtr starBox2;
    ObjectPtr starBox3;
    ObjectPtr starBox4;
    ObjectPtr starBox5;
    ObjectPtr starMainMenu;
    int clearStarCnt;
    bool starBoxStatus[5];
    bool gymManDead;
    int burgerY;
    

    ObjectPtr puangBat;
    ObjectPtr puangBatTemp;

    TimerPtr puangBatHit;
    TimerPtr puangBatHitAfter;

    TimerPtr burgerComingDown;

    ObjectPtr bulga;




    // 성공 시 
    ObjectPtr hamburger;
    ScenePtr gameClearScene;
    TimerPtr gameClearTimer;

    // 실패 애니메이션 
    ObjectPtr puangFail;
    ScenePtr gameOverScene;
    TimerPtr puangFailMoving;
    TimerPtr puangCrying;
    int puangWeightCnt;
    TimerPtr gameOverPuangWeightUp;
    TimerPtr gameOverPuangWeightDown;
    TimerPtr facedGameOver; 


    

    StageComponent(FindingSnackObject* r);
    ~StageComponent();

    // 객체가 생성될때 변수 초기화 및 초기 셋팅등 생성자 역할을 하게 된다.
    void enter();

    // 객체가 삭제/제거될때 메모리 삭제 등 소멸자 역할을 하게 된다.
    void exit();

    // 객체의 주 행동들을 작성하는 곳으로 특정 시간마다 변하는 애니메이션이나 타이밍을 체크 하며 다음과 같이 작성 할 수 있다.
    void update();

    // 화면에 그려질 부분을 컨트롤 하는 부분이다. 랜더링을 담당한다.
    void draw();

    // 사용자의 조작에 어떤반응을 할것인지를 컨트롤 할 수 있는 부분이다.
    void event();


    // 만들어 놓은 함수들을 가지고 로직 수행
    void construct();

    void resetBag();

    void makeStage(int stageNum);


    void makeStage1();
    void makeStage2();
    void makeStage3();
    void makeStage4();
    void makeStage5(); // 미완성 
    void makeStage6();
    void makeStage7();
    void makeStage8(); 
    void makeStage9();
    void makeStage10();
};

