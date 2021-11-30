#include "StageComponent.h"

StageComponent::StageComponent(FindingSnackObject* r) {
    root = r;
    root->stageComponent = this;
    //construct();
}

StageComponent::~StageComponent() {};

// ��ü�� �����ɶ� ���� �ʱ�ȭ �� �ʱ� ���õ� ������ ������ �ϰ� �ȴ�.
void StageComponent::enter() {
    // default ��� �ʱ�ȭ 
    char temp[45];
    for (int i = 0; i < 45; i++) {
        temp[i] = 0;
    }
	//sprintf(temp, "Images/Stage/stageStart/%d.PNG", root->getCurrentStage());
    sprintf(temp, "Images/Stage/stageStart/%d.PNG", root->getClickedStage());

    // ���� 
    // 1. �̸��� �Ȱ����� (�ּҴ� �޶���.)
    // 2. ��Ÿ �ڵ� ���� 
    showStageScene = Scene::create("showStage", temp);

    // �̰� �ƴ���, �Ƹ��� �̰� ������ ������ showStageScene���� 2�������� Ÿ�̸Ӱ����� 
    // �װ��߿��� 
    root->setStage(showStageScene);

    showStageTimer = Timer::create(2.f);

    roomLeftScene = Scene::create("roomLeft", "Images/Stage/room.PNG");

    roomRightScene = Scene::create("roomRight", "Images/Stage/roomSide.PNG");
    goRightRoomBtn = Object::create("Images/Stage/goRight.PNG", roomLeftScene, 1160, 30);
    goLeftRoomBtn = Object::create("Images/Stage/goLeft.PNG", roomRightScene, 30, 30);
    goRightRoomBtn->setScale(0.7);
    goLeftRoomBtn->setScale(0.7);

    stageRestartBtnL = Object::create("Images/Button/restartBtn.png", roomLeftScene, 10, 630);
    goBackMainMenuBtnL = Object::create("Images/Button/home.png", roomLeftScene, 110, 630);
    stageRestartBtnR = Object::create("Images/Button/restartBtn.png", roomRightScene, 10, 630);
    goBackMainMenuBtnR = Object::create("Images/Button/home.png", roomRightScene, 110, 630);
 
    event();

    makeStage(root->getClickedStage());
    // ���ӿɼ��� Stage���� �� �� ���� 
    setGameOption(GameOption::GAME_OPTION_INVENTORY_BUTTON, true);





};

// ��ü�� ����/���ŵɶ� �޸� ���� �� �Ҹ��� ������ �ϰ� �ȴ�.
void StageComponent::exit() {};


// ��ü�� �� �ൿ���� �ۼ��ϴ� ������ Ư�� �ð����� ���ϴ� �ִϸ��̼��̳� Ÿ�̹��� üũ �ϸ� ������ ���� �ۼ� �� �� �ִ�.
void StageComponent::update() {};

// ȭ�鿡 �׷��� �κ��� ��Ʈ�� �ϴ� �κ��̴�. �������� ����Ѵ�.
void StageComponent::draw() {};

// ������� ���ۿ� � ������ �Ұ������� ��Ʈ�� �� �� �ִ� �κ��̴�.
void StageComponent::event() {
    showStageTimer->start();
    showStageTimer->setOnTimerCallback([&](TimerPtr timer)->bool {

        timer->stop();

        root->setStage(roomLeftScene);
        roomLeftScene->enter(); 
        return true;
    });

    goRightRoomBtn->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)->bool {
        roomRightScene->enter();
        return true;
    });
    goLeftRoomBtn->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)->bool {
        roomLeftScene->enter();
        return true;
    });
    stageRestartBtnL->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)->bool {
        // �ʱ�ȭ�� �Ǿ����� ? �׸��� �� Ŭ������ ���Ͱ� ������� ? 
        enter();
        root->getStage()->enter();
        return true;
    });
    stageRestartBtnR->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)->bool {
        // �ʱ�ȭ�� �Ǿ����� ? �׸��� �� Ŭ������ ���Ͱ� ������� ? 
        enter();
        root->getStage()->enter();
        return true;
    });
    goBackMainMenuBtnL->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)->bool {
        // �ʱ�ȭ�� �Ǿ����� ? �׸��� �� Ŭ������ ���Ͱ� ������� ? 
        setGameOption(GameOption::GAME_OPTION_INVENTORY_BUTTON, false);
        root->getMainMenuScene()->enter();
        return true;
    });
    goBackMainMenuBtnR->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)->bool {
        // �ʱ�ȭ�� �Ǿ����� ? �׸��� �� Ŭ������ ���Ͱ� ������� ? 
        setGameOption(GameOption::GAME_OPTION_INVENTORY_BUTTON, false);
        root->getMainMenuScene()->enter();
        return true;
    });
};

// ����� ���� �Լ����� ������ ���� ����
void StageComponent::construct() {

}

void StageComponent::makeStage(int stageNum) {
    if (stageNum == 1)
        makeStage1();
    else if (stageNum == 2)
        makeStage2();
}

void StageComponent::makeStage1() {
    // default ��ҵ��� ���� �ٹ̰� ���ϸ� �ȴ�. 

    // ���� ȭ�鿡 ����, â��    
    // ������ ȭ�鿡 ����ȿ� ��â, ���� ��� �ؿ� ���ӱ� 

    // enter 
    closet = Object::create("Images/Stage/closetClose.png", roomLeftScene, 200, 150);
    windowLeft = Object::create("Images/Stage/curtainClose.png", roomLeftScene, 720, 400); // x = 177, (������������ ��ġ�� ���̷��� ���� ������ ) 
    windowRight = Object::create("Images/Stage/curtainClose.png", roomLeftScene, 880, 400); // -17
    
    wallCloset = Object::create("Images/Stage/wallclosetCloseTrainer.PNG", roomRightScene, 250, 250);
    sofa = Object::create("Images/Stage/sofaSide.png", roomRightScene, 550, 25);
    sofaCushionLeft = Object::create("Images/Stage/cushion.png", roomRightScene, 600, 170);
    sofaCushionRight = Object::create("Images/Stage/cushion.png", roomRightScene, 750, 125);

    hamburger = Object::create("Images/Stage/hamburger.png", roomRightScene, 650, 170);
    hamburger->hide();


    wallClosetGameOver = Timer::create(1.f);

    // ���� ��� 
    gameClearScene = Scene::create("gameClearScene", "Images/Stage/clearBackground.PNG");
    gameClearTimer = Timer::create(2.f);
    // ���� ���
    puangFail = Object::create("Images/Puang/Ǫ��_�޸��.png", roomRightScene, 250, 50);
    puangFail->hide();

    gameOverScene = Scene::create("gameOverScene", "Images/Stage/gameOverScene.PNG");


    puangFailMoving = Timer::create(1.f);
    puangCrying = Timer::create(1.f);
    gameOverPuangWeightUp = Timer::create(1.f);
    gameOverPuangWeightDown = Timer::create(1.f);
    puangWeightCnt = 0;

    


    // 
    //gameOverScene = Scene::create("gameOver", "Images/Stage/gameoverBackground.PNG");



    // event 
    closet->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)->bool {
        // �ʱ�ȭ�� �Ǿ����� ? �׸��� �� Ŭ������ ���Ͱ� ������� ? 
        closet->setImage("Images/Stage/closetOpen.png");
        return true;
    });

    windowLeft->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)->bool {
        // �ʱ�ȭ�� �Ǿ����� ? �׸��� �� Ŭ������ ���Ͱ� ������� ? 
        windowLeft->setImage("Images/Stage/leftWindow.png");
        return true;
    });

    windowRight->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)->bool {
        // �ʱ�ȭ�� �Ǿ����� ? �׸��� �� Ŭ������ ���Ͱ� ������� ? 
        windowRight->setImage("Images/Stage/rightWindow.png");
        return true;
    });


    sofaCushionLeft->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)->bool {
        // �ʱ�ȭ�� �Ǿ����� ? �׸��� �� Ŭ������ ���Ͱ� ������� ? 
        sofaCushionLeft->locate(roomRightScene, 600, 70);
        hamburger->show(); 
        return true;
    }); 
    sofaCushionRight->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)->bool {
        // �ʱ�ȭ�� �Ǿ����� ? �׸��� �� Ŭ������ ���Ͱ� ������� ? 
        sofaCushionRight->locate(roomRightScene, 700, 25);
        return true;
    });


    // ���� ��
    wallCloset->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)->bool {
        // �ʱ�ȭ�� �Ǿ����� ? �׸��� �� Ŭ������ ���Ͱ� ������� ? 
		//�����Ѵ� 
        puangFail->show();
        puangFailMoving->start();

		

		//��������, �����Ѵ�.
		//
		//���ӿ���ȭ�� ���.
		//
		//���ӿ���ȭ�� �ȿ��� ��Ѵ�. 

        return true;
    });

    puangFailMoving->setOnTimerCallback([&](TimerPtr timer)->bool {
        timer->stop();

        wallCloset->setImage("Images/Stage/wallclosetOpenTrainer.PNG");
        wallCloset->locate(roomRightScene, 250, 240);
        // timer start
        //wallClosetGameOver->start();
        puangCrying->start();
        return true;
    });

    puangCrying->setOnTimerCallback([&](TimerPtr timer)->bool {
        timer->stop();
        puangFail->setImage("Images/Puang/Ǫ��_����.png");
        wallClosetGameOver->start();
        return true;
    });

    wallClosetGameOver->setOnTimerCallback([&](TimerPtr timer)->bool {
        timer->stop();
        
        //root->getStageSelectScene()->enter();
        setGameOption(GameOption::GAME_OPTION_INVENTORY_BUTTON, false);

        gameOverScene->enter();
        puangFail->setImage("Images/Stage/Ǫ��_�.png");
        puangFail->locate(gameOverScene, 350, 50);
        gameOverPuangWeightDown->start();

        //puangFail->setImage("Images/Stage/Ǫ��_�.png");
        //puangFail->locate(gameOverScene, 250, 250);
        // �����ϴ� ��ǵ� 
        // �κ��丮 �ڽ� ���� �ʿ�, 
        return true;
    });
    gameOverPuangWeightUp->setOnTimerCallback([&](TimerPtr timer)->bool {
        if (puangWeightCnt < 4) {
            timer->stop();
            timer->set(1.f);
            puangFail->setImage("Images/Stage/Ǫ��_�.png");
            gameOverPuangWeightDown->start();
            puangWeightCnt++;
        }
        else {
            root->getStageSelectScene()->enter();
            
        }

        return true;
    });
    gameOverPuangWeightDown->setOnTimerCallback([&](TimerPtr timer)->bool {
        if (puangWeightCnt < 4) {
            timer->stop();
            timer->set(1.f);
            puangFail->setImage("Images/Stage/Ǫ��_�2.png");
            //puangFail->locate(gameOverScene, 250, 250);
            gameOverPuangWeightUp->start();
            puangWeightCnt++;
        }
        else {
            root->getStageSelectScene()->enter();
        }


        return true;
    });
    // ���� �� 
    hamburger->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)-> bool {
        //stage ++ 
        // game clear
        // menu Btn ?
        // go next game ? 
        setGameOption(GameOption::GAME_OPTION_INVENTORY_BUTTON, false);
        gameClearScene->enter();
        // ���� �߰� 
        // 1ź�� ��� ���� 2,3,ź�̱����¹��� �߻� 
        if (root->getCurrentStage() ==  root->getClickedStage())
            root->setCurrentStage(root->getCurrentStage() + 1);

        gameClearTimer->start();

        return true;
    });
    gameClearTimer->setOnTimerCallback([&](TimerPtr timer)->bool {
        timer->stop();
        root->getStageSelectScene()->enter();

        root->stageSelectComponent->update();

        return true;
    });

}
void StageComponent::makeStage2() {

    gymMan = Object::create("Images/Trainer/trainer.png", roomLeftScene, 880, 150);
    closet = Object::create("Images/Stage/closetClose.png", roomLeftScene, 200, 150);
    windowLeft = Object::create("Images/Stage/curtainClose.png", roomLeftScene, 720, 400); // x = 177, (������������ ��ġ�� ���̷��� ���� ������ ) 
    windowRight = Object::create("Images/Stage/curtainClose.png", roomLeftScene, 880, 400); // -17

    sofa = Object::create("Images/Stage/sofaFront.png", roomLeftScene, 620, 150);

  

    // ȭ��, ��, ���� 
    wallCloset = Object::create("Images/Stage/wallclosetBitjaru.PNG", roomRightScene, 250, 250);

}
