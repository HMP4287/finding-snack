#pragma once
#include "../FindingSnackObject.h"

// Component
class StageComponent : public FindingSnackObject
{
public:
    FindingSnackObject* root;

    // Stage elements
    // �������� ���Խ� ���� ó��ȭ�� room == stageScene
    ScenePtr showStageScene; 
    TimerPtr showStageTimer;

    ScenePtr roomLeftScene;
    ScenePtr roomRightScene;

    ObjectPtr goRightRoomBtn;
    ObjectPtr goLeftRoomBtn;

    // Default btn 
    ObjectPtr stageRestartBtnL;
    ObjectPtr goBackMainMenuBtnL;
    ObjectPtr stageRestartBtnR;
    ObjectPtr goBackMainMenuBtnR;


    ObjectPtr closet;
    ObjectPtr windowLeft;
    ObjectPtr windowRight; 
    ObjectPtr wallCloset; // �밢�� 
    ObjectPtr sofa; // �밢�� 
    ObjectPtr sofaCushionLeft;
    ObjectPtr sofaCushionRight;


    // stage2
    ObjectPtr gymMan;
    ObjectPtr plant;


    // ���� �� 
    ObjectPtr hamburger;
    ScenePtr gameClearScene;
    TimerPtr gameClearTimer;

    // ���� �ִϸ��̼� 
    ObjectPtr puangFail;
    
    ScenePtr gameOverScene;

    // puang should gym 
    TimerPtr puangFailMoving;
    TimerPtr puangCrying;
    int puangWeightCnt;
    TimerPtr gameOverPuangWeightUp;
    TimerPtr gameOverPuangWeightDown;

    TimerPtr wallClosetGameOver; 


    

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

    
    void makeStage(int stageNum);


    void makeStage1();
    void makeStage2();

};

