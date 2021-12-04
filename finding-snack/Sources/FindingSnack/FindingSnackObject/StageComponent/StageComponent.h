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




    // ���� �� 
    ObjectPtr hamburger;
    ScenePtr gameClearScene;
    TimerPtr gameClearTimer;

    // ���� �ִϸ��̼� 
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

    // ��ü�� �����ɶ� ���� �ʱ�ȭ �� �ʱ� ���õ� ������ ������ �ϰ� �ȴ�.
    void enter();

    // ��ü�� ����/���ŵɶ� �޸� ���� �� �Ҹ��� ������ �ϰ� �ȴ�.
    void exit();

    // ��ü�� �� �ൿ���� �ۼ��ϴ� ������ Ư�� �ð����� ���ϴ� �ִϸ��̼��̳� Ÿ�̹��� üũ �ϸ� ������ ���� �ۼ� �� �� �ִ�.
    void update();

    // ȭ�鿡 �׷��� �κ��� ��Ʈ�� �ϴ� �κ��̴�. �������� ����Ѵ�.
    void draw();

    // ������� ���ۿ� ������� �Ұ������� ��Ʈ�� �� �� �ִ� �κ��̴�.
    void event();


    // ����� ���� �Լ����� ������ ���� ����
    void construct();

    void resetBag();

    void makeStage(int stageNum);


    void makeStage1();
    void makeStage2();
    void makeStage3();
    void makeStage4();
    void makeStage5(); // �̿ϼ� 
    void makeStage6();
    void makeStage7();
    void makeStage8(); 
    void makeStage9();
    void makeStage10();
};

