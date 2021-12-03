#include "StageComponent.h"

StageComponent::StageComponent(FindingSnackObject* r) {
    root = r;
    root->stageComponent = this;
    //construct();
}

StageComponent::~StageComponent() {};

// ��ü�� �����ɶ� ���� �ʱ�ȭ �� �ʱ� ���õ� ������ ������ �ϰ� �ȴ�.
void StageComponent::enter() {
    resetBag();
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
        resetBag();
        root->getMainMenuScene()->enter();
        return true;
    });
    goBackMainMenuBtnR->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)->bool {
        // �ʱ�ȭ�� �Ǿ����� ? �׸��� �� Ŭ������ ���Ͱ� ������� ? 
        setGameOption(GameOption::GAME_OPTION_INVENTORY_BUTTON, false);
        resetBag();
        root->getMainMenuScene()->enter();
        return true;
    });
};

void StageComponent::resetBag() {

    // �κ��丮 40�ڽ��ϱ� 40�� �ݺ��ؼ� ��� �������ϴ��� ?
    if (bitjaru) {
        bitjaru->drop();
        bitjaru->hide();
    }
    if (brokenChair) {
        brokenChair->drop();
        brokenChair->hide();

    }
    if (book2) {
        book2->drop();
        book2->hide();
    }
    if (book3) {
        book3->drop();
        book2->hide();
    }
    if (paint) {
        paint->drop();
        paint->hide();
    }
    if (key) {
        key->drop();
        key->hide();
    }
    if (watermelon) {
        watermelon->drop();
        watermelon->hide();
    }
    if (fish) {
        fish->drop();
        fish->hide();
    }

}


// ����� ���� �Լ����� ������ ���� ����
void StageComponent::construct() {

}

void StageComponent::makeStage(int stageNum) {
    if (stageNum == 1)
        makeStage1();
    else if (stageNum == 2)
        makeStage2();
    else if (stageNum == 3)
        makeStage3();
    else if (stageNum == 4)
        makeStage4();
    else if (stageNum == 5)
        makeStage5();
    else if (stageNum == 6)
        makeStage6();
    else if (stageNum == 7)
        makeStage7();
    else if (stageNum == 8)
        makeStage8();

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


    facedGameOver = Timer::create(1.f);




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
        facedGameOver->start();
        return true;
    });

    facedGameOver->setOnTimerCallback([&](TimerPtr timer)->bool {
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

    hamburger = Object::create("Images/Stage/hamburger.png", roomLeftScene, 300, 120);
    burgerMoved = false;

    gymMan = Object::create("Images/Trainer/trainer.png", roomLeftScene, 880, 150);
    closet = Object::create("Images/Stage/closetClose.png", roomLeftScene, 200, 150);
    windowLeft = Object::create("Images/Stage/curtainClose.png", roomLeftScene, 710, 400); // x = 177, (������������ ��ġ�� ���̷��� ���� ������ ) 
    windowRight = Object::create("Images/Stage/curtainClose.png", roomLeftScene, 900, 400); // -17

    sofa = Object::create("Images/Stage/sofaFront.png", roomLeftScene, 620, 150);

    burgerMovedTimer = Timer::create(1.f);
    burgerMovedTimerAfter = Timer::create(1.f);

    // ȭ��, ��, ���� 
    plant = Object::create("Images/Stage/plantClose.png", roomRightScene, 100, 250);
    wallCloset = Object::create("Images/Stage/wallclosetBitjaru.PNG", roomRightScene, 250, 250);
    drawer = Object::create("Images/Stage/drawerClose.png", roomRightScene, 550, 75);

    bitjaru = Object::create("Images/Stage/bitjaru.png", roomRightScene, 300, 300);
    bitjaru->setScale(1.5f);
    bitjaru->hide();


    // ����
    
    gameClearScene = Scene::create("gameClearScene", "Images/Stage/clearBackground.PNG");
    gameClearTimer = Timer::create(2.f);




    // ���� 
    puangFail = Object::create("Images/Puang/Ǫ��_�޸��.png", roomLeftScene, 650, 50);
    puangFail->hide();
    gameOverScene = Scene::create("gameOverScene", "Images/Stage/gameOverScene.PNG");
    facedGameOver = Timer::create(1.f); // �׳� ���� ������ �ϳ��� 
    puangFailMoving = Timer::create(1.f);
    puangCrying = Timer::create(1.f);
    gameOverPuangWeightUp = Timer::create(1.f);
    gameOverPuangWeightDown = Timer::create(1.f);
    puangWeightCnt = 0;


    closet->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)->bool {
        closet->setImage("Images/Stage/closetOpen.png");
        return true;
    });

    windowLeft->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)->bool {
        windowLeft->setImage("Images/Stage/leftWindow.png");
        return true;
    });

    // ���� ������ -----
    windowRight->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)->bool {

        //windowRight->setImage("Images/Stage/rightWindow.png");
        //gymMan = Object::create("Images/Trainer/trainer.png", roomLeftScene, 880, 150);

        //gymMan->locate(roomLeftScene, 880, 150);
        puangFail->show();
        puangFailMoving->start();
        return true;
    });
    // �������� �߰��� �� 
    puangFailMoving->setOnTimerCallback([&](TimerPtr timer)->bool {
        timer->stop();
        windowRight->setImage("Images/Stage/rightWindow.png");
        gymMan = Object::create("Images/Trainer/trainer.png", roomLeftScene, 880, 150);
        // timer start
        //wallClosetGameOver->start();
        puangCrying->start();
        return true;
    });

    puangCrying->setOnTimerCallback([&](TimerPtr timer)->bool {
        timer->stop();
        puangFail->setImage("Images/Puang/Ǫ��_����.png");

        facedGameOver->start();
        return true;
    });

    facedGameOver->setOnTimerCallback([&](TimerPtr timer)->bool {
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
    // ���� �������. 
    plant->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)->bool {
        plant->setImage("Images/Stage/plantOpen.png");
        return true;
    });
    bitjaru->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)->bool {
        bitjaru->pick();
        
        return true;
    });

    wallCloset->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)->bool {
        wallCloset->setImage("Images/Stage/wallclosetOpen.png");
        wallCloset->locate(roomRightScene, 250, 240);
        // ���ڷ� �ʿ� 
        bitjaru->show();



        

        return true;
    });
    drawer->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)->bool {
        drawer->setImage("Images/Stage/drawerOpen.png");
        drawer->locate(roomRightScene, 455, 40);
        return true;
    });

    // ���� 
    hamburger->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)->bool {
        if (burgerMoved) {
            setGameOption(GameOption::GAME_OPTION_INVENTORY_BUTTON, false);
            gameClearScene->enter();
            // ���� �߰� 
            // 1ź�� ��� ���� 2,3,ź�̱����¹��� �߻� 
            if (root->getCurrentStage() == root->getClickedStage())
                root->setCurrentStage(root->getCurrentStage() + 1);

            gameClearTimer->start();

        }
        else if (bitjaru->isHanded()) {
            // Ǫ���� + ���ڷ� �����Ѵ�.
            bitjaru->drop();
            bitjaru->hide();
            //bitjaru = Object::create("Images/Stage/bitjaruLeft.png", roomLeftScene, 250, 100);
            bitjaruTemp = Object::create("Images/Stage/bitjaruLeft.png", roomLeftScene, 250, 100);
            bitjaruTemp->setScale(1.5f);
            puangBitjaru = Object::create("Images/Puang/Ǫ��_�޸��.png", roomLeftScene, 250, 50);
            // 1���ִٰ� ���� ���ڷ�� ģ ȭ�� ���� 
            // 
            // ���ڷ� ȸ�� + ���� �̵� 
            
            burgerMovedTimer->start();

            // ����   burgerMoved = true
            
        }
        else {
            showMessage("���� �� ��Ǫ��");
        
        }

        return true;
    });
    gameClearTimer->setOnTimerCallback([&](TimerPtr timer)->bool {
        timer->stop();
        root->getStageSelectScene()->enter();

        root->stageSelectComponent->update();

        return true;
    });
    // ����������� 

    burgerMovedTimer->setOnTimerCallback([&](TimerPtr timer)->bool {
        timer->stop();
        bitjaruTemp->setImage("Images/Stage/bitjaruRight.png");
        hamburger->locate(roomLeftScene, 500, 150);
        burgerMovedTimerAfter->start();
        return true;
    });
    burgerMovedTimerAfter->setOnTimerCallback([&](TimerPtr timer)->bool {
        timer->stop();
        bitjaruTemp->hide();
        puangBitjaru->hide();
        burgerMoved = true;

        return true;
    });




}

void StageComponent::makeStage3() {

    // �����ʱ�ȭ�� ���ū ü�� 

    // ���� ȭ�� 
    // ��� + ��� �� �μ��� ��ٸ� 
    // å�� + å1, 2, 3�� 
    closet = Object::create("Images/Stage/closetClose.png", roomLeftScene, 200, 150);
    brokenChair = Object::create("Images/Stage/ladderBroken.png", roomLeftScene, 280, 200);
    brokenChair->hide(); 
    burgerReach = 0;


    bookshelf = Object::create("Images/Stage/bookshelf.png", roomLeftScene, 750, 150);
    book1 = Object::create("Images/Stage/bookInBookshelf1.png", roomLeftScene, 780, 420);
    book2 = Object::create("Images/Stage/bookInBookshelf.png", roomLeftScene, 780, 280);
    book3 = Object::create("Images/Stage/bookInBookshelf.png", roomLeftScene, 780, 160);


    gameClearScene = Scene::create("gameClearScene", "Images/Stage/clearBackground.PNG");
    gameClearTimer = Timer::create(2.f);
    // new ����
    puangFallDown = Timer::create(1.f);
    puangFallDownAfter = Timer::create(1.f);

    // ���� 

    gameOverScene = Scene::create("gameOverScene", "Images/Stage/gameOverScene.PNG");
    facedGameOver = Timer::create(1.f); // �׳� ���� ������ �ϳ��� 
    puangFailMoving = Timer::create(1.f);
    puangCrying = Timer::create(1.f);
    gameOverPuangWeightUp = Timer::create(1.f);
    gameOverPuangWeightDown = Timer::create(1.f);
    puangWeightCnt = 0;
    // ���� ȭ�� 
    // ��� �뽺�ĵ�
    // ���� ���ӱ� 
    //hamburger = Object::create("Images/Stage/hamburger.png", roomRightScene, 380, 750);
    //hamburger->hide();
    wallCloset = Object::create("Images/Stage/wallCloBClosed.PNG", roomRightScene, 250, 220);
    hamburger = Object::create("Images/Stage/hamburger.png", roomRightScene, 340, 580);
    hamburger->hide();
    //hamburger->setScale(0.7f);
    stand = Object::create("Images/Stage/stand.png", roomRightScene, 580, 125);
    wallIsOpen = false;

    puangLovingTimer = Timer::create(1.f);
    puangFail = Object::create("Images/Puang/Ǫ��_�޸��.png", roomLeftScene,  750, 150);
    puangFail->hide();
    puangJumping = Object::create("Images/Puang/Ǫ��_�޸��.png", roomRightScene, 240, 300);
    puangJumping->hide();
    wallCloset->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)->bool {

        if (wallIsOpen) {
        
            if (brokenChair->isHanded()) {

                brokenChair->drop();
                brokenChair->hide();

                brokenChairTemp = Object::create("Images/Stage/ladderBroken.png", roomRightScene, 280, 200);
                burgerReach = 1;
            }
            else if (book2->isHanded() || book3->isHanded()) {
                if (book2) {
                    book2->drop();
                    book2->hide();
                }
                if (book3) {
                    book3->drop();
                    book3->hide();
                }

                bookTemp = Object::create("Images/Stage/bookItem.png", roomRightScene, 280, 200);
                burgerReach = 2;

            }
        }
        else {
            wallCloset->setImage("Images/Stage/wallClosetshelfOpen.png");
            wallCloset->locate(roomRightScene, 250, 205);
            hamburger->show();
            wallIsOpen = true;
        }


        

        return true;
    });


    
    hamburger->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)->bool {
        if (burgerReach == 0) {
            showMessage("Ű�� �� ��Ǫ��");
        }
        // ���� �η������� new ���� 
        else if (burgerReach == 1) {
            //puangFail->show();
            puangJumping->show();

            puangFallDown->start();
            

            
        }
        // ���� å��ħ ���� 
        else if (burgerReach == 2) {
            //puangFail->show();
            //puangFail->setImage("Images/Puang/Ǫ��_���.png");

            puangJumping->show();
            puangJumping->setImage("Images/Puang/Ǫ��_���.png");

            //setGameOption(GameOption::GAME_OPTION_INVENTORY_BUTTON, false);
            //gameClearScene->enter();
            //// ���� �߰� 
            //// 1ź�� ��� ���� 2,3,ź�̱����¹��� �߻� 
            //if (root->getCurrentStage() == root->getClickedStage())
            //    root->setCurrentStage(root->getCurrentStage() + 1);

            //gameClearTimer->start();
            puangLovingTimer->start();
        

        }

        return true;
    });

    puangLovingTimer->setOnTimerCallback([&](TimerPtr timer)->bool {
        timer->stop();

        resetBag();
        setGameOption(GameOption::GAME_OPTION_INVENTORY_BUTTON, false);
        gameClearScene->enter();
        gameClearTimer->start();

        return true;
    });

    gameClearTimer->setOnTimerCallback([&](TimerPtr timer)->bool {

        // ���� �߰� 
        // 1ź�� ��� ���� 2,3,ź�̱����¹��� �߻� 
        if (root->getCurrentStage() == root->getClickedStage())
            root->setCurrentStage(root->getCurrentStage() + 1);
        timer->stop();
        root->getStageSelectScene()->enter();

        root->stageSelectComponent->update();

        return true;
    });
    puangFallDown->setOnTimerCallback([&](TimerPtr timer)->bool {
        timer->stop();
        puangJumping->hide();
        puangJumping = Object::create("Images/Puang/Ǫ��_��.png", roomRightScene, 240, 100);
        //puangFail->setImage();
        //puangFail->locate(roomRightScene, 240, 100);
        puangFallDownAfter->start();

        return true;
    });
    puangFallDownAfter->setOnTimerCallback([&](TimerPtr timer)->bool {
        timer->stop();
        facedGameOver->start();

        return true;
    });
    closet->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)->bool {
        closet->setImage("Images/Stage/closetOpen.png");
        brokenChair->show();
        return true;
    });

    brokenChair->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)->bool {
        brokenChair->pick();
        return true;
    });

    // ���� ���� ����, å����� ��� ... 
    book1->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)->bool {
        //book1->hide();
        puangFail->show();
        puangFailMoving->start();


        return true;
    });
    // �������� �߰��� �� 
    puangFailMoving->setOnTimerCallback([&](TimerPtr timer)->bool {
        timer->stop();
        book1->hide();
        puangCrying->start();
        return true;
    });

    puangCrying->setOnTimerCallback([&](TimerPtr timer)->bool {
        timer->stop();
        puangFail->setImage("Images/Puang/Ǫ��_����.png");

        facedGameOver->start();
        return true;
    });

    facedGameOver->setOnTimerCallback([&](TimerPtr timer)->bool {
        timer->stop();
        
        //root->getStageSelectScene()->enter();
        setGameOption(GameOption::GAME_OPTION_INVENTORY_BUTTON, false);

        resetBag();
        gameOverScene->enter();
        puangFail->show();
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
    // ���� �������. 
    book2->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)->bool {
        //book2->hide();
        book2->setImage("Images/Stage/bookItem.png");
        //book2->locate(roomRightScene, 0, 0);
        book2->pick();
        return true;
    });
    book3->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)->bool {
        //book3->hide();
        book3->setImage("Images/Stage/bookItem.png");
        //book3->locate(roomRightScene, 0, 0);
        book3->pick();
        return true;
    });

}

void StageComponent::makeStage4() {
    gameClearScene = Scene::create("gameClearScene", "Images/Stage/clearBackground.PNG");
    gameClearTimer = Timer::create(2.f);
    // ����
    // ��, ����
    carMan = Object::create("Images/Trainer/trainer.png", roomLeftScene, 1200, 150);
    carMan->hide();
    carManX = 1200;
    car = Object::create("Images/Stage/car.png", roomLeftScene, 400, 150);
    carX = 400;
    sign = Object::create("Images/Stage/canPark.png", roomLeftScene, 200, 150);
    hamburger = Object::create("Images/Stage/hamburger.png", roomLeftScene, 650, 150);
    hamburger->hide();

    // ������ 
    // ���� 
    // ���� �� ����Ʈ         550, 75
   //  drawer->locate(roomRightScene, 455, 40);
    drawer = Object::create("Images/Stage/drawerClose.png", roomRightScene, 550, 75);
    paint = Object::create("Images/Stage/spraySpin.png", roomRightScene, 550, 175);
    paint->hide();

    puangComePaint = Timer::create(1.f);
    carManComming = Timer::create(1.f);
    carManInside = Timer::create(1.f);
    carOut = Timer::create(1.f);

    drawer->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)->bool {
        drawer->setImage("Images/Stage/drawerOpen.png");
        drawer->locate(roomRightScene, 455, 40);
        paint->show();
        return true;
    });

    paint->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)->bool {
        paint->pick();
        return true;
    });

    sign->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)->bool {
        if (paint->isHanded()) {
            // drop hide ���ϰ� �õ� 
            paint->drop();
            paint->hide();
            // Ǫ�� ����Ʈ��� ����
            paintTemp = Object::create("Images/Stage/spray.png", roomLeftScene, 360, 230);

            paintingPuang = Object::create("Images/Puang/Ǫ��_��_��.png", roomLeftScene, 200, 150);
            puangComePaint->start();

            // ��� ���ϱ�
            // ���� ���� 
            // ���� ���� 
            // �� ���� 
        }
        return true;
    });

    puangComePaint->setOnTimerCallback([&](TimerPtr timer)->bool {
        timer->stop();
        sign->setImage("Images/Stage/cannotPark.png");
        
        carManComming->start();

        return true;
    });

    carManComming->setOnTimerCallback([&](TimerPtr timer)->bool {
        timer->stop();
        
        carMan->show();
        // ��������� ����ɵ� �� �����÷ο� ?
        if (carManX > 600) {
            carManX -= 25;
            timer->set(0.1f);
            carMan->locate(roomLeftScene, carManX, 150);
            timer->start();
        }
        // ������ ���ȿ� �ֱ� 
        else {
            carManInside->start();

            paintingPuang->hide();
            paintTemp->hide();
        }

        return true;
    });
    carManInside->setOnTimerCallback([&](TimerPtr timer)->bool {
        timer->stop();
        carMan->hide();

        carOut->start();
        return true;
    });
    carOut->setOnTimerCallback([&](TimerPtr timer)->bool {
        timer->stop();

        if (carX < 1280) {
            if (carX == 700)
                hamburger->show();
            carX += 25;
            timer->set(0.1f);
            car->locate(roomLeftScene, carX, 150);
            timer->start();
        }
        // ������ ���ȿ� �ֱ� 
        
            //carManInside->start();
        return true;
    });




    hamburger->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)->bool {
        setGameOption(GameOption::GAME_OPTION_INVENTORY_BUTTON, false);
        resetBag();
        gameClearScene->enter();
        // ���� �߰� 
        // 1ź�� ��� ���� 2,3,ź�̱����¹��� �߻� 
        if (root->getCurrentStage() == root->getClickedStage())
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


void StageComponent::makeStage5() { 
}

void StageComponent::makeStage6() {
    // ����ȭ�� 
    // ��� ����
    // ������ 
    closet = Object::create("Images/Stage/closetLock.png", roomLeftScene, 200, 150);
    bottle = Object::create("Images/Stage/bottle.png", roomLeftScene, 750, 150);


    // ����ȭ�� 
    // â�� Ŀư �¿� 
    // â�� ���� �¿� 
    // â�� ���� �� 
    // Ű ȸ��, �̴��ｺ��ȸ��, ���� �� ȸ�� 
    //windowLeft = Object::create("Images/Stage/")
    windowLeft = Object::create("Images/Stage/curtainSide.png", roomRightScene, 500, 330); // x = 177, (������������ ��ġ�� ���̷��� ���� ������ ) 
    windowRight = Object::create("Images/Stage/curtainSide.png", roomRightScene, 635, 281); // -17
    windowStatus = 0;

    key = Object::create("Images/Stage/key.png", roomRightScene, 665, 360);
    key->hide();

    gymMan = Object::create("Images/Trainer/trainer1.png", roomRightScene, 680, 460);
    gymMan->hide();

    cloud = Object::create("Images/Stage/cloud.png", roomRightScene, 675, 410);
    cloud->hide();

    gymManSpin = true;
    keySpin = true; 

    gymStatus = 0;
    keyStatus = 0;

    gymManSpinTimer = Timer::create(0.5f);
    keySpinTimer = Timer::create(1.0f);

    gameOverScene = Scene::create("gameOverScene", "Images/Stage/gameOverScene.PNG");
    facedGameOver = Timer::create(1.f); // �׳� ���� ������ �ϳ��� 
    puangFailMoving = Timer::create(1.f);
    puangCrying = Timer::create(1.f);
    gameOverPuangWeightUp = Timer::create(1.f);
    gameOverPuangWeightDown = Timer::create(1.f);
    puangWeightCnt = 0;
    puangFail = Object::create("Images/Puang/Ǫ��_�޸��.png", roomRightScene, 480, 100);
    puangFail->hide();
    cloud->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)-> bool {
        cloud->hide();
        return true;
    });
    gameClearScene = Scene::create("gameClearScene", "Images/Stage/clearBackground.PNG");
    gameClearTimer = Timer::create(2.f);


    closetUnlocked = false;
    hamburger = Object::create("Images/Stage/hamburger.png", roomLeftScene, 280, 200);
    hamburger->hide();
    closet->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)->bool {
        
        if (closetUnlocked) {
            closet->setImage("Images/Stage/closetOpen.png");
            hamburger->show();
        }
        else if (key->isHanded()) {
            closet->setImage("Images/Stage/closetUnlock.png");
            key->drop();
            key->hide();
            closetUnlocked = true;
        }



        return true;
    });
    hamburger->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)->bool {
        setGameOption(GameOption::GAME_OPTION_INVENTORY_BUTTON, false);
        gameClearScene->enter();
        // ���� �߰� 
        // 1ź�� ��� ���� 2,3,ź�̱����¹��� �߻� 
        if (root->getCurrentStage() == root->getClickedStage())
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
    bottle->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)->bool {
        bottle->setImage("Images/Stage/bottleBreak.png");
        return true;
    });

    windowLeft->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)->bool {
        windowLeft->setImage("Images/Stage/windowSLO.png");
        return true;
    });
    windowRight->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)->bool {
       
        if (windowStatus == 0) {
            windowRight->setImage("Images/Stage/windowSRO.png");
            windowStatus = 1;
        }
        else if (windowStatus == 1) {
            windowRight->setImage("Images/Stage/windowSideOpen.png");
            key->show();
            gymMan->show();
            cloud->show();
            keySpinTimer->start();
            gymManSpinTimer->start();
        }
        return true;
    });


    keySpinTimer->setOnTimerCallback([&](TimerPtr timer)->bool {
        timer->stop();

        if (keySpin) {
            timer->set(1.0f);
            if (keyStatus % 4 == 0) {
                key->setImage("Images/Stage/key2.png");
            }
            else if (keyStatus % 4 == 1) {
                key->setImage("Images/Stage/key3.png");
            }
            else if (keyStatus % 4 == 2) {
                key->setImage("Images/Stage/key4.png");
            }
            else if (keyStatus % 4 == 3) {
                key->setImage("Images/Stage/key.png");
            }
            keyStatus++;

            timer->start();
        }
        // ������ ���ȿ� �ֱ� 

        //carManInside->start();
        return true;
    });
    gymManSpinTimer->setOnTimerCallback([&](TimerPtr timer)->bool {
        timer->stop();

        if (gymManSpin) {
            timer->set(0.5f);
            if (gymStatus % 4 == 0) {
                gymMan->setImage("Images/Trainer/trainer2.png");
            }
            else if (gymStatus % 4 == 1) {
                gymMan->setImage("Images/Trainer/trainer3.png");
            }
            else if (gymStatus % 4 == 2) {
                gymMan->setImage("Images/Trainer/trainer4.png");
            }
            else if (gymStatus % 4 == 3) {
                gymMan->setImage("Images/Trainer/trainer1.png");
            }
            gymStatus++;

            timer->start();
        }
        // ������ ���ȿ� �ֱ� 

        //carManInside->start();
        return true;
    });
    gymMan->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)->bool {
        gymManSpin = false;
        puangFail->show();
        puangFailMoving->start();


        return true;
    });

    // �������� �߰��� �� 
    puangFailMoving->setOnTimerCallback([&](TimerPtr timer)->bool {
        timer->stop();
        puangCrying->start();
        return true;
    });

    puangCrying->setOnTimerCallback([&](TimerPtr timer)->bool {
        timer->stop();
        puangFail->setImage("Images/Puang/Ǫ��_����.png");

        facedGameOver->start();
        return true;
    });

    facedGameOver->setOnTimerCallback([&](TimerPtr timer)->bool {
        timer->stop();
        
        //root->getStageSelectScene()->enter();
        setGameOption(GameOption::GAME_OPTION_INVENTORY_BUTTON, false);

        resetBag();
        gameOverScene->enter();
        puangFail->show();
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

    key->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)->bool {
        keySpin = false;
        key->pick();

        return true;
    });

}

void StageComponent::makeStage7() {
    // ����
    // ����� ���� 
    // å�� 
    //
    // 
    // 142

    gameClearScene = Scene::create("gameClearScene", "Images/Stage/clearBackground.PNG");
    gameClearTimer = Timer::create(2.f);
    refrigeratorUp = Object::create("Images/Stage/rUC.png", roomLeftScene, 250, 400);
    refrigeratorDown = Object::create("Images/Stage/rDC.png", roomLeftScene, 250, 150);


    puangHittingStatus = 0;
    hitCnt = 0;

    watermelon = Object::create("Images/Stage/watermelon.png", roomLeftScene, 310, 280);
    watermelon->hide();

    puangHitting = Object::create("Images/Puang/Ǫ��_�ڸ���1.PNG", roomLeftScene, 840, 120);
    puangHitting->hide();

    desk = Object::create("Images/Stage/table.png", roomLeftScene, 700, 50);
    desk->setScale(0.5f);

    watermelonDesk = Object::create("Images/Stage/watermelon.png", roomLeftScene, 780, 170);
    watermelonDesk->hide();


    hamburger = Object::create("Images/Stage/hamburger.png", roomLeftScene, 780, 170);
    hamburger->hide();

    sofa = Object::create("Images/Stage/sofaTrainer.png", roomRightScene, 250, 25);
    sofaCushionLeft = Object::create("Images/Stage/cushion.png", roomRightScene, 300, 250);
    sofaCushionRight = Object::create("Images/Stage/cushion.png", roomRightScene, 450, 205);
    gameOverScene = Scene::create("gameOverScene", "Images/Stage/gameOverScene.PNG");
    facedGameOver = Timer::create(1.f); // �׳� ���� ������ �ϳ��� 
    puangFailMoving = Timer::create(1.f);
    puangCrying = Timer::create(1.f);
    gameOverPuangWeightUp = Timer::create(1.f);
    gameOverPuangWeightDown = Timer::create(1.f);
    puangWeightCnt = 0;
    puangFail = Object::create("Images/Puang/Ǫ��_�޸��.png", roomRightScene, 180, 100);
    puangFail->hide();

    refrigeratorUp->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)->bool {
        refrigeratorUp->setImage("Images/Stage/rUO.png");
        return true;
    });

    refrigeratorDown->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)->bool {
        refrigeratorDown->setImage("Images/Stage/rDO.png");
        watermelon->show();
        return true;
    });
    watermelon->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)->bool {
        watermelon->pick();
        return true;
    });
    desk->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)->bool {

        if (watermelon->isHanded()) {
            watermelon->drop();
            watermelon->hide();
            watermelonDesk->show();
            puangHitting->show();
        }
        return true;
    });

    watermelonDesk->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)->bool {
        
        if (hitCnt < 20) {
            if (puangHittingStatus == 0) {
                puangHitting->setImage("Images/Puang/Ǫ��_�ڸ���2.PNG");
                puangHittingStatus = 1;
            }
            
            else {
                puangHitting->setImage("Images/Puang/Ǫ��_�ڸ���1.PNG");
                puangHittingStatus = 0;
            }
            
            hitCnt++;     
        }
        else {
            puangHitting->setImage("Images/Stage/Ǫ��_���.png");
            watermelonDesk->setImage("Images/Stage/watermelonBreak.png");
            hamburger->show();
        }
        return true;
    });

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


    // ���� 
    // ���Ŀ� Ʈ���̳� 
    // ���� ��� 

    sofaCushionLeft->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)->bool {
        sofaCushionLeft->locate(roomRightScene, 300, 70);
        puangFail->show();
        puangFailMoving->start();
        return true;
    });
    
    // �������� �߰��� �� 
    puangFailMoving->setOnTimerCallback([&](TimerPtr timer)->bool {
        timer->stop();
        puangCrying->start();
        return true;
    });

    puangCrying->setOnTimerCallback([&](TimerPtr timer)->bool {
        timer->stop();
        puangFail->setImage("Images/Puang/Ǫ��_����.png");

        facedGameOver->start();
        return true;
    });

    facedGameOver->setOnTimerCallback([&](TimerPtr timer)->bool {
        timer->stop();
        
        //root->getStageSelectScene()->enter();
        setGameOption(GameOption::GAME_OPTION_INVENTORY_BUTTON, false);

        resetBag();
        gameOverScene->enter();
        puangFail->show();
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

    sofaCushionRight->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)->bool {
        sofaCushionRight->locate(roomRightScene, 450, 25);
        return true;
    });

}

void StageComponent::makeStage8() {
    // fish 
    comeBigFish = Timer::create(0.1f);
    comeBigFishX = 700;
    eatingFish = Timer::create(2.f);

    givingFish = Timer::create(1.f);
    // ������� 
    gameClearScene = Scene::create("gameClearScene", "Images/Stage/clearBackground.PNG");
    gameClearTimer = Timer::create(2.f);
    // 
    // 
    // ����ȭ�� 
    // ����� 
    // ����
    // �߰�����?
    // �׸����� �ָ� ���� 
    // �����ָ� ��â ���� 
    hamburger = Object::create("Images/Stage/hamburger.png", roomLeftScene, 950, 150);
    hamburgerCanClick = false;
    
    refrigeratorUp = Object::create("Images/Stage/rUC.png", roomLeftScene, 250, 400);
    refrigeratorDown = Object::create("Images/Stage/rDC.png", roomLeftScene, 250, 150);
    
    dish = Object::create("Images/Stage/plate.png", roomLeftScene, 100, 50);
    dish->hide();

    fish = Object::create("Images/Stage/fish.png", roomLeftScene, 310, 280);
    fish->hide();
    chicken = Object::create("Images/Stage/chicken.png", roomLeftScene, 310, 180);
    chicken->hide();

    fly = Object::create("Images/Stage/paris.png", roomRightScene, 250, 250);
    fly->setScale(7.f);
    
    flyLeft = Object::create("Images/Stage/paris.png", roomLeftScene, 100, 50);

    //fly->setScale(5.f);

    
    bigFish = Object::create("Images/Stage/bigFishStand.png", roomLeftScene, 700, 50);
    bigFish->setScale(0.6f);
    gameOverScene = Scene::create("gameOverScene", "Images/Stage/gameOverScene.PNG");
    facedGameOver = Timer::create(1.f); // �׳� ���� ������ �ϳ��� 
    puangFailMoving = Timer::create(1.f);
    puangCrying = Timer::create(1.f);
    gameOverPuangWeightUp = Timer::create(1.f);
    gameOverPuangWeightDown = Timer::create(1.f);
    puangWeightCnt = 0;
    puangFail = Object::create("Images/Puang/Ǫ��_�޸��.png", roomLeftScene, 100, 50);
    puangFail->hide();
    refrigeratorUp->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)->bool {
        refrigeratorUp->setImage("Images/Stage/rUO.png");
        return true;
    });
    flyLeft->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)->bool {
        flyLeft->hide();
        dish->show();
        return true;
    });
    fly->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)->bool {
        fly->hide();
        return true;
    });


    refrigeratorDown->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)->bool {
        refrigeratorDown->setImage("Images/Stage/rDO.png");
        fish->show();
        chicken->show();
        return true;
    });

    fish->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)->bool {
        fish->pick();
        return true;
    });

    // ���� ���� 
    chicken->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)->bool {
        //chicken->hide();
        puangFail->show();

        puangFailMoving->start();
        // ���� ���� 
        return true;
    });


    // �������� �߰��� �� 
    puangFailMoving->setOnTimerCallback([&](TimerPtr timer)->bool {
        timer->stop();
        bigFish->setImage("Images/Stage/bigFishOpenV.png");
        bigFish->setScale(0.6f);
        puangCrying->start();
        return true;
    });

    puangCrying->setOnTimerCallback([&](TimerPtr timer)->bool {
        timer->stop();
        puangFail->setImage("Images/Puang/Ǫ��_����.png");
        if (fishTemp) {
            fishTemp->hide();
        }

        facedGameOver->start();
        return true;
    });

    facedGameOver->setOnTimerCallback([&](TimerPtr timer)->bool {
        timer->stop();
        
        //root->getStageSelectScene()->enter();
        setGameOption(GameOption::GAME_OPTION_INVENTORY_BUTTON, false);

        resetBag();
        gameOverScene->enter();
        puangFail->show();
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

    dish->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)->bool {
        // �Դ� �ִ� �߰� 
        if (fish->isHanded()) {
            fish->drop();
            fish->hide();
            // �׸����� ���� 
            // �� ���� // ���Ż��� 
            // �� ���� 
            puangGivingFish = Object::create("Images/Puang/Ǫ��_�޸��.png", roomLeftScene, 130, 50);

            //
            givingFish->start();

        
        }
        return true;
    });
    givingFish->setOnTimerCallback([&](TimerPtr timer)->bool {
        timer->stop();
        puangGivingFish->hide();
        fishTemp = Object::create("Images/Stage/fish.png", roomLeftScene, 120, 80);
       
        comeBigFish->start();

        return true;
    });
    comeBigFish->setOnTimerCallback([&](TimerPtr timer)->bool {
        timer->stop();
        if (comeBigFishX > 200) {
            timer->set(0.1f);
            comeBigFishX -= 10;
            bigFish->locate(roomLeftScene, comeBigFishX, 50);
            timer->start();
        }
        else {
            fishTemp->hide();
            bigFish->setImage("Images/Stage/bigFishEating.png");
            eatingFish->start();

        }

        return true;
    });
    eatingFish->setOnTimerCallback([&](TimerPtr timer)->bool {
        timer->stop();
        bigFish->setImage("Images/Stage/bigFishStand.png");
        
        hamburgerCanClick = true;


        return true;
    });

    bigFish->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)->bool {
        // ���� ����2 
        if (fish->isHanded()) {
            puangFail->show();
            puangFail->locate(roomLeftScene, 600, 150);
            puangFail->setImage("Images/Puang/Ǫ��_��_��.png");
            fishTemp = Object::create("Images/Stage/fish.png", roomLeftScene, 750, 250);

            puangFailMoving->start();
             
        }
        return true;
    });


    hamburger->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)-> bool {
        //stage ++ 
        // game clear
        // menu Btn ?
        // go next game ? 
        if (hamburgerCanClick) {
            setGameOption(GameOption::GAME_OPTION_INVENTORY_BUTTON, false);
            gameClearScene->enter();
            // ���� �߰� 
            // 1ź�� ��� ���� 2,3,ź�̱����¹��� �߻� 
            if (root->getCurrentStage() == root->getClickedStage())
                root->setCurrentStage(root->getCurrentStage() + 1);

            gameClearTimer->start();
        }


        return true;
    });
    gameClearTimer->setOnTimerCallback([&](TimerPtr timer)->bool {
        timer->stop();
        root->getStageSelectScene()->enter();

        root->stageSelectComponent->update();

        return true;
    });




    // ������ ȭ�� �ĸ��ϳ�
    // ������ ������� 

    
    // �Դ����� 
    // �Թ����� -> ��â 
    // �� �Դ°�
        

}

