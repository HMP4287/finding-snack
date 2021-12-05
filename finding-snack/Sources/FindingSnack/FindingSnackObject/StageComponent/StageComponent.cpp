#include "StageComponent.h"

StageComponent::StageComponent(FindingSnackObject* r) {
    root = r;
    root->stageComponent = this;
}

StageComponent::~StageComponent() {};

void StageComponent::enter() {
    resetObject();
    resetBag();
    char temp[45];
    for (int i = 0; i < 45; i++) {
        temp[i] = 0;
    }
    sprintf(temp, "Images/Stage/stageStart/%d.PNG", root->getClickedStage());
    showStageScene = Scene::create("showStage", temp);
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
    goRightRoomBtnFake = Object::create("Images/Stage/goRight.PNG", roomLeftScene, 1160, 30);
    goLeftRoomBtnFake = Object::create("Images/Stage/goLeft.PNG", roomRightScene, 30, 30);
    stageRestartBtnLFake = Object::create("Images/Button/restartBtn.png", roomLeftScene, 10, 630);
    goBackMainMenuBtnLFake = Object::create("Images/Button/home.png", roomLeftScene, 110, 630);
    stageRestartBtnRFake = Object::create("Images/Button/restartBtn.png", roomRightScene, 10, 630);
    goBackMainMenuBtnRFake = Object::create("Images/Button/home.png", roomRightScene, 110, 630);
    goRightRoomBtnFake->setScale(0.7);
    goLeftRoomBtnFake->setScale(0.7);
    hideFake();
    event();
    makeStage(root->getClickedStage());
    setGameOption(GameOption::GAME_OPTION_INVENTORY_BUTTON, true);
};
void StageComponent::showFake() {
    goRightRoomBtnFake->show();
    goLeftRoomBtnFake->show();
    stageRestartBtnLFake->show();
    goBackMainMenuBtnLFake->show();
    stageRestartBtnRFake->show();
    goBackMainMenuBtnRFake->show();
};

void StageComponent::hideFake() {
    goRightRoomBtnFake->hide();
    goLeftRoomBtnFake->hide();
    stageRestartBtnLFake->hide();
    goBackMainMenuBtnLFake->hide();
    stageRestartBtnRFake->hide();
    goBackMainMenuBtnRFake->hide();
}; 

void StageComponent::exit() {};
void StageComponent::update() {};
void StageComponent::draw() {};
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
        resetBag();
        resetObject();
        enter();
        root->getStage()->enter();
        return true;
    });
    stageRestartBtnR->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)->bool {
        resetBag();
        resetObject();
        enter();
        root->getStage()->enter();
        return true;
    });
    goBackMainMenuBtnL->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)->bool {
        resetBag();
        resetObject();
        setGameOption(GameOption::GAME_OPTION_INVENTORY_BUTTON, false);
        root->getMainMenuScene()->enter();
        return true;
    });
    goBackMainMenuBtnR->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)->bool {
        resetBag();
        resetObject();
        setGameOption(GameOption::GAME_OPTION_INVENTORY_BUTTON, false);
        root->getMainMenuScene()->enter();
        return true;
    });
};

void StageComponent::resetBag() {
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
    if (ballon) {
        ballon->drop();
        ballon->hide();
    }
    if (star1) {
        star1->drop();
        star1->hide();
    }
    if (star2) {
        star2->drop();
        star2->hide();
    }
    if (star3) {
        star3->drop();
        star3->hide();
    }

    if (star4) {
        star4->drop();
        star4->hide();
    }

    if (star5) {
        star5->drop();
        star5->hide();
    }
    if (bat1) {
        bat1->drop();
        bat1->hide();
    }
    if (bat2) {
        bat2->drop();
        bat2->hide();
    }
}


void StageComponent::construct() {}

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
    else if (stageNum == 9)
        makeStage9();
    else if (stageNum == 10)
        makeStage10();
}

void StageComponent::makeStage1() {
    // enter 
    closet = Object::create("Images/Stage/closetClose.png", roomLeftScene, 200, 150);
    windowLeft = Object::create("Images/Stage/curtainClose.png", roomLeftScene, 720, 400); 
    windowRight = Object::create("Images/Stage/curtainClose.png", roomLeftScene, 880, 400); 
    wallCloset = Object::create("Images/Stage/wallclosetCloseTrainer.PNG", roomRightScene, 250, 250);
    sofa = Object::create("Images/Stage/sofaSide.png", roomRightScene, 550, 25);
    sofaCushionLeft = Object::create("Images/Stage/cushion.png", roomRightScene, 600, 170);
    sofaCushionRight = Object::create("Images/Stage/cushion.png", roomRightScene, 750, 125);
    hamburger = Object::create("Images/Stage/hamburger.png", roomRightScene, 650, 170);
    hamburger->hide();
    facedGameOver = Timer::create(1.f);
    gameClearScene = Scene::create("gameClearScene", "Images/Stage/clearBackground.PNG");
    gameClearTimer = Timer::create(2.f);
    puangFail = Object::create("Images/Puang/Çª¾Ó_µÞ¸ð½À.png", roomRightScene, 250, 50);
    puangFail->hide();
    gameOverScene = Scene::create("gameOverScene", "Images/Stage/gameOverScene.PNG");
    puangFailMoving = Timer::create(1.f);
    puangCrying = Timer::create(1.f);
    gameOverPuangWeightUp = Timer::create(1.f);
    gameOverPuangWeightDown = Timer::create(1.f);
    puangWeightCnt = 0;
    canBurger = true;
    canTrainer = true; 
    // event 
    closet->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)->bool {
        closet->setImage("Images/Stage/closetOpen.png");
        return true;
    });

    windowLeft->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)->bool {
        windowLeft->setImage("Images/Stage/leftWindow.png");
        return true;
    });

    windowRight->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)->bool {
        windowRight->setImage("Images/Stage/rightWindow.png");
        return true;
    });

    sofaCushionLeft->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)->bool {
        sofaCushionLeft->locate(roomRightScene, 600, 70);
        hamburger->show(); 
        return true;
    }); 
    sofaCushionRight->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)->bool {
        sofaCushionRight->locate(roomRightScene, 700, 25);
        return true;
    });
    wallCloset->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)->bool {
        if (canTrainer) {
            showFake();
            puangFail->show();
            puangFailMoving->start();
            canBurger = false;
        }
        return true;
    });

    puangFailMoving->setOnTimerCallback([&](TimerPtr timer)->bool {
        timer->stop();
        wallCloset->setImage("Images/Stage/wallclosetOpenTrainer.PNG");
        wallCloset->locate(roomRightScene, 250, 240);
        puangCrying->start();
        return true;
    });

    puangCrying->setOnTimerCallback([&](TimerPtr timer)->bool {
        timer->stop();
        puangFail->setImage("Images/Puang/Çª¾Ó_Àý±Ô.png");
        facedGameOver->start();
        return true;
    });

    facedGameOver->setOnTimerCallback([&](TimerPtr timer)->bool {
        timer->stop();
        hideFake();
        setGameOption(GameOption::GAME_OPTION_INVENTORY_BUTTON, false);
        gameOverScene->enter();
        puangFail->setImage("Images/Stage/Çª¾Ó_¿îµ¿.png");
        puangFail->locate(gameOverScene, 350, 50);
        gameOverPuangWeightDown->start();
        return true;
    });
    gameOverPuangWeightUp->setOnTimerCallback([&](TimerPtr timer)->bool {
        if (puangWeightCnt < 4) {
            timer->stop();
            timer->set(1.f);
            puangFail->setImage("Images/Stage/Çª¾Ó_¿îµ¿.png");
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
            puangFail->setImage("Images/Stage/Çª¾Ó_¿îµ¿2.png");
            gameOverPuangWeightUp->start();
            puangWeightCnt++;
        }
        else {
            root->getStageSelectScene()->enter();
        }
        return true;
    });
    hamburger->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)-> bool {
        if (canBurger) {
            setGameOption(GameOption::GAME_OPTION_INVENTORY_BUTTON, false);
            gameClearScene->enter();
            if (root->getCurrentStage() == root->getClickedStage())
                root->setCurrentStage(root->getCurrentStage() + 1);
            gameClearTimer->start();
            canTrainer = false; 
        }
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
    windowLeft = Object::create("Images/Stage/curtainClose.png", roomLeftScene, 710, 400); 
    windowRight = Object::create("Images/Stage/curtainClose.png", roomLeftScene, 900, 400); 
    sofa = Object::create("Images/Stage/sofaFront.png", roomLeftScene, 620, 150);
    burgerMovedTimer = Timer::create(1.f);
    burgerMovedTimerAfter = Timer::create(1.f);
    plant = Object::create("Images/Stage/plantClose.png", roomRightScene, 100, 250);
    wallCloset = Object::create("Images/Stage/wallclosetBitjaru.PNG", roomRightScene, 250, 250);
    drawer = Object::create("Images/Stage/drawerClose.png", roomRightScene, 550, 75);
    bitjaru = Object::create("Images/Stage/bitjaru.png", roomRightScene, 300, 300);
    bitjaru->setScale(1.5f);
    bitjaru->hide();
    canBurger = true;
    canTrainer = true; 
    gameClearScene = Scene::create("gameClearScene", "Images/Stage/clearBackground.PNG");
    gameClearTimer = Timer::create(2.f);
    puangFail = Object::create("Images/Puang/Çª¾Ó_µÞ¸ð½À.png", roomLeftScene, 650, 50);
    puangFail->hide();
    gameOverScene = Scene::create("gameOverScene", "Images/Stage/gameOverScene.PNG");
    facedGameOver = Timer::create(1.f); 
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

    windowRight->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)->bool {
        if (canTrainer) {
            resetBag();
            showFake();
            puangFail->show();
            puangFailMoving->start();
            canBurger = false; 
        }
        return true;
    });
    puangFailMoving->setOnTimerCallback([&](TimerPtr timer)->bool {
        timer->stop();
        windowRight->setImage("Images/Stage/rightWindow.png");
        gymMan = Object::create("Images/Trainer/trainer.png", roomLeftScene, 880, 150);
        puangCrying->start();
        return true;
    });

    puangCrying->setOnTimerCallback([&](TimerPtr timer)->bool {
        timer->stop();
        puangFail->setImage("Images/Puang/Çª¾Ó_Àý±Ô.png");
        facedGameOver->start();
        return true;
    });

    facedGameOver->setOnTimerCallback([&](TimerPtr timer)->bool {
        timer->stop();
        hideFake();
        setGameOption(GameOption::GAME_OPTION_INVENTORY_BUTTON, false);
        gameOverScene->enter();
        puangFail->setImage("Images/Stage/Çª¾Ó_¿îµ¿.png");
        puangFail->locate(gameOverScene, 350, 50);
        gameOverPuangWeightDown->start();
        return true;
    });
    gameOverPuangWeightUp->setOnTimerCallback([&](TimerPtr timer)->bool {
        if (puangWeightCnt < 4) {
            timer->stop();
            timer->set(1.f);
            puangFail->setImage("Images/Stage/Çª¾Ó_¿îµ¿.png");
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
            puangFail->setImage("Images/Stage/Çª¾Ó_¿îµ¿2.png");
            gameOverPuangWeightUp->start();
            puangWeightCnt++;
        }
        else {
            root->getStageSelectScene()->enter();
        }

        return true;
    });
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
        bitjaru->show();
        return true;
    });
    drawer->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)->bool {
        drawer->setImage("Images/Stage/drawerOpen.png");
        drawer->locate(roomRightScene, 455, 40);
        return true;
    });
    hamburger->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)->bool {
        if (canBurger) {
       

            if (burgerMoved) {
                resetBag();
                setGameOption(GameOption::GAME_OPTION_INVENTORY_BUTTON, false);
                gameClearScene->enter();
                if (root->getCurrentStage() == root->getClickedStage())
                    root->setCurrentStage(root->getCurrentStage() + 1);
                gameClearTimer->start();

            }
            else if (bitjaru->isHanded()) {
                canTrainer = false;
                showFake();
                bitjaru->drop();
                bitjaru->hide();
                bitjaru->locate(roomRightScene, 1280, 720);
                bitjaruTemp = Object::create("Images/Stage/bitjaruLeft.png", roomLeftScene, 250, 100);
                bitjaruTemp->setScale(1.5f);
                puangBitjaru = Object::create("Images/Puang/Çª¾Ó_µÞ¸ð½À.png", roomLeftScene, 250, 50);
                burgerMovedTimer->start();

            }
            else {
                showMessage("ÆÈÀÌ ¾È ´êÇª¾Ó");

            }
        
        }
 

        return true;
    });
    gameClearTimer->setOnTimerCallback([&](TimerPtr timer)->bool {
        timer->stop();
        root->getStageSelectScene()->enter();
        root->stageSelectComponent->update();

        return true;
    });

    burgerMovedTimer->setOnTimerCallback([&](TimerPtr timer)->bool {
        timer->stop();
        bitjaruTemp->setImage("Images/Stage/bitjaruRight.png");
        hamburger->locate(roomLeftScene, 500, 150);
        burgerMovedTimerAfter->start();
        return true;
    });
    burgerMovedTimerAfter->setOnTimerCallback([&](TimerPtr timer)->bool {
        hideFake();
        canTrainer = true;
        timer->stop();
        bitjaruTemp->hide();
        puangBitjaru->hide();
        burgerMoved = true;

        return true;
    });
}

void StageComponent::makeStage3() {
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
    puangFallDown = Timer::create(1.f);
    puangFallDownAfter = Timer::create(1.f);
    gameOverScene = Scene::create("gameOverScene", "Images/Stage/gameOverScene.PNG");
    facedGameOver = Timer::create(1.f); 
    puangFailMoving = Timer::create(1.f);
    puangCrying = Timer::create(1.f);
    gameOverPuangWeightUp = Timer::create(1.f);
    gameOverPuangWeightDown = Timer::create(1.f);
    puangWeightCnt = 0;
    wallCloset = Object::create("Images/Stage/wallCloBClosed.PNG", roomRightScene, 250, 220);
    hamburger = Object::create("Images/Stage/hamburger.png", roomRightScene, 340, 580);
    hamburger->hide();
    stand = Object::create("Images/Stage/stand.png", roomRightScene, 580, 125);
    wallIsOpen = false;

    puangLovingTimer = Timer::create(1.f);
    puangFail = Object::create("Images/Puang/Çª¾Ó_µÞ¸ð½À.png", roomLeftScene,  750, 150);
    puangFail->hide();
    puangJumping = Object::create("Images/Puang/Çª¾Ó_µÞ¸ð½À.png", roomRightScene, 240, 300);
    puangJumping->hide();
    chairBookIsExist = false; 
    wallCloset->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)->bool {

        if (wallIsOpen) {
        
            if (brokenChair->isHanded() && (!chairBookIsExist)) {

                brokenChair->drop();
                brokenChair->hide();
                brokenChair->locate(roomRightScene, 1280, 720);

                brokenChairTemp = Object::create("Images/Stage/ladderBroken.png", roomRightScene, 280, 200);
                burgerReach = 1;
                chairBookIsExist = true;
            }
            else if ((book2->isHanded() || book3->isHanded()) && (!chairBookIsExist)) {
                if (book2) {
                    book2->drop();
                    book2->hide();
                    book2->locate(roomRightScene, 1280, 720);
                }
                if (book3) {
                    book3->drop();
                    book3->hide();
                    book3->locate(roomRightScene, 1280, 720);
                }

                bookTemp = Object::create("Images/Stage/bookItem.png", roomRightScene, 280, 200);
                burgerReach = 2;
                chairBookIsExist = true;

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
            showMessage("Å°°¡ ¾È ´êÇª¾Ó");
        }
        else if (burgerReach == 1) {
            showFake();
            puangJumping->show();
            puangFallDown->start();
        }
        else if (burgerReach == 2) {
            resetBag();
            showFake();
            puangJumping->show();
            puangJumping->setImage("Images/Puang/Çª¾Ó_»ç¶û.png");
            puangLovingTimer->start();
        }

        return true;
    });

    puangLovingTimer->setOnTimerCallback([&](TimerPtr timer)->bool {
        timer->stop();

        hideFake();
        resetBag();
        setGameOption(GameOption::GAME_OPTION_INVENTORY_BUTTON, false);
        gameClearScene->enter();
        gameClearTimer->start();

        return true;
    });

    gameClearTimer->setOnTimerCallback([&](TimerPtr timer)->bool {
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
        puangJumping = Object::create("Images/Puang/Çª¾Ó_´¯.png", roomRightScene, 240, 100);
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

    book1->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)->bool {
        showFake();
        //resetBag();
        puangFail->show();
        puangFailMoving->start();


        return true;
    });
    puangFailMoving->setOnTimerCallback([&](TimerPtr timer)->bool {
        timer->stop();
        book1->hide();
        puangCrying->start();
        return true;
    });

    puangCrying->setOnTimerCallback([&](TimerPtr timer)->bool {
        timer->stop();
        puangFail->setImage("Images/Puang/Çª¾Ó_Àý±Ô.png");

        facedGameOver->start();
        return true;
    });

    facedGameOver->setOnTimerCallback([&](TimerPtr timer)->bool {
        timer->stop();
        
        hideFake();
        setGameOption(GameOption::GAME_OPTION_INVENTORY_BUTTON, false);

        resetBag();
        gameOverScene->enter();
        puangFail->show();
        puangFail->setImage("Images/Stage/Çª¾Ó_¿îµ¿.png");
        puangFail->locate(gameOverScene, 350, 50);
        gameOverPuangWeightDown->start();
        return true;
    });
    gameOverPuangWeightUp->setOnTimerCallback([&](TimerPtr timer)->bool {
        if (puangWeightCnt < 4) {
            timer->stop();
            timer->set(1.f);
            puangFail->setImage("Images/Stage/Çª¾Ó_¿îµ¿.png");
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
            puangFail->setImage("Images/Stage/Çª¾Ó_¿îµ¿2.png");
            gameOverPuangWeightUp->start();
            puangWeightCnt++;
        }
        else {
            root->getStageSelectScene()->enter();
        }


        return true;
    });
    book2->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)->bool {
        book2->setImage("Images/Stage/bookItem.png");
        book2->pick();
        return true;
    });
    book3->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)->bool {
        book3->setImage("Images/Stage/bookItem.png");
        book3->pick();
        return true;
    });

}

void StageComponent::makeStage4() {
    gameClearScene = Scene::create("gameClearScene", "Images/Stage/clearBackground.PNG");
    gameClearTimer = Timer::create(2.f);
    carMan = Object::create("Images/Trainer/trainer.png", roomLeftScene, 1200, 150);
    carMan->hide();
    carManX = 1200;
    car = Object::create("Images/Stage/car.png", roomLeftScene, 400, 150);
    carX = 400;
    sign = Object::create("Images/Stage/canPark.png", roomLeftScene, 200, 150);
    hamburger = Object::create("Images/Stage/hamburger.png", roomLeftScene, 650, 150);
    hamburger->hide();

    drawer = Object::create("Images/Stage/drawerClose.png", roomRightScene, 550, 75);
    paint = Object::create("Images/Stage/spraySpin.png", roomRightScene, 550, 175);
    paint->hide();
    sprayOnce = true;

    hamburgerCanClick = false;
    puangComePaint = Timer::create(1.f);
    carManComming = Timer::create(1.f);
    carManInside = Timer::create(1.f);
    carOut = Timer::create(1.f);

    drawer->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)->bool {
        if (sprayOnce) {
            drawer->setImage("Images/Stage/drawerOpen.png");
            drawer->locate(roomRightScene, 455, 40);
            paint->show();
            sprayOnce = false;
        }

        return true;
    });

    paint->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)->bool {
        paint->pick();
        return true;
    });

    sign->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)->bool {
        if (paint->isHanded()) {
            showFake();
            paint->drop();
            paint->hide();
            paintTemp = Object::create("Images/Stage/spray.png", roomLeftScene, 360, 230);

            paintingPuang = Object::create("Images/Puang/Çª¾Ó_µÞ_¼Õ.png", roomLeftScene, 200, 150);
            puangComePaint->start();

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
        if (carManX > 600) {
            carManX -= 25;
            timer->set(0.1f);
            carMan->locate(roomLeftScene, carManX, 150);
            timer->start();
        }
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
        else {
            hamburgerCanClick = true;
            hideFake();
        }
        
        return true;
    });




    hamburger->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)->bool {
        if (hamburgerCanClick) {
            setGameOption(GameOption::GAME_OPTION_INVENTORY_BUTTON, false);
            resetBag();
            gameClearScene->enter();
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
}


void StageComponent::makeStage5() { 

    weightTemp = Object::create("Images/Stage/weight.png", roomLeftScene, 320, 90);
    weightTemp->hide();
    hamburger = Object::create("Images/Stage/hamburger.png", roomLeftScene, 320, 150);
    gymMan = Object::create("Images/Stage/trainerD1.png", roomLeftScene, 250, 50);
    elephant = Object::create("Images/Stage/elephant.png", roomLeftScene, 700, 150);
    elephant->setScale(0.3f);
    gymManY = 50;
    gymManDStatus = 0; 
    gymManSpeed = 0;
    elephantBallonGetBig = Timer::create(2.f);
    ballonScale = 0.2f; 
    ballonX = 670; 
    ballonY = 180;
    weight = Object::create("Images/Stage/weight.png", roomLeftScene, 600, 50);
    weight->hide();
    gameClearScene = Scene::create("gameClearScene", "Images/Stage/clearBackground.PNG");
    gameClearTimer = Timer::create(2.f);
    gymManGymingFast = Timer::create(1.f);

    hamburgerCanClick = false;
    drawer = Object::create("Images/Stage/drawerClose.png", roomRightScene, 550, 75);
    ballon = Object::create("Images/Stage/ballonSmall.png", roomRightScene, 550, 175);
    ballonOnce = true;
    ballon->hide();
    hamburger->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)-> bool {
        if (hamburgerCanClick) {
            setGameOption(GameOption::GAME_OPTION_INVENTORY_BUTTON, false);
            gameClearScene->enter();
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


    drawer->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)->bool {
        if (ballonOnce) {
            drawer->setImage("Images/Stage/drawerOpen.png");
            ballon->show();
            drawer->locate(roomRightScene, 455, 40);
            ballonOnce = false;
        }

        return true;
    });
    ballon->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)->bool {
        ballon->pick();
        return true;
    });

    gymMan->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)->bool {
        if (weight->isHanded()) {
            showFake();
            weight->drop();
            weight->hide(); 
            weightTemp->show();
            gymManGymingFast->start();
        }
        return true;
    });
    
    cntTwo = 0;
    gymManGymingFast->setOnTimerCallback([&](TimerPtr timer)->bool {
        timer->stop();

        
        if (gymManY < 700) {
            if (cntTwo < 2) {
                if (gymManDStatus == 0) {
                    timer->set(0.025f);
                    gymMan->setImage("Images/Stage/trainerD1.png");
                    gymMan->locate(roomLeftScene, 250, gymManY);
                    gymManDStatus = 1;

                }
                else if (gymManDStatus == 1) {
                    timer->set(0.025f);
                    gymMan->setImage("Images/Stage/trainerD2.png");
                    gymMan->locate(roomLeftScene, 200, gymManY);
                    gymManDStatus = 0;
                }
                cntTwo++;
            }
            else {
                cntTwo = 0; 
                gymManY += 20;
                timer->set(0.1f);
        
            }
            timer->start();

        }
        else {
            hamburgerCanClick = true;
            gymMan->hide();
            hideFake();
        }
        return true;
    });

    elephant->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)->bool {
        if (ballon->isHanded()) {
            ballon->drop();
            ballon->hide();
            ballon->locate(roomLeftScene, 1280, 720);
            showFake();
            ballonGettingBig = Object::create("Images/Stage/ballon.png", roomLeftScene, ballonX, ballonY);
            ballonGettingBig->setScale(ballonScale); 
            elephantBallonGetBig->start();
        }
        return true;
    });

    elephantBallonGetBig->setOnTimerCallback([&](TimerPtr timer)->bool {
        timer->stop();
        
        if (ballonScale < 2) {
            timer->set(2.f);
            ballonScale += 0.2;
            ballonGettingBig->setScale(ballonScale);
            ballonX -= 35;
            ballonY -= 10;
            ballonGettingBig->locate(roomLeftScene, ballonX, ballonY);
            timer->start();
        }

        else {
            hideFake();
            ballonGettingBig->hide();
            weight->show(); 
        }


        return true;
    });
    weight->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)->bool {
        weight->pick();
        return true;
    });


}

void StageComponent::makeStage6() {
    closet = Object::create("Images/Stage/closetLock.png", roomLeftScene, 200, 150);
    bottle = Object::create("Images/Stage/bottle.png", roomLeftScene, 750, 150);
    windowLeft = Object::create("Images/Stage/curtainSide.png", roomRightScene, 500, 330); 
    windowRight = Object::create("Images/Stage/curtainSide.png", roomRightScene, 635, 281); 
    windowStatus = 0;

    key = Object::create("Images/Stage/key.png", roomRightScene, 665, 360);
    key->hide();

    gymMan = Object::create("Images/Trainer/trainer1.png", roomRightScene, 680, 460);
    gymMan->hide();

    cloud = Object::create("Images/Stage/cloud.png", roomRightScene, 675, 410);
    cloud->hide();

    gymManSpin = true;
    keySpin = true; 
    gymManSpinCnt = 0;
    keySpinCnt = 0;
    gymStatus = 0;
    keyStatus = 0;

    gymManSpinTimer = Timer::create(0.1f);
    keySpinTimer = Timer::create(1.0f);

    gameOverScene = Scene::create("gameOverScene", "Images/Stage/gameOverScene.PNG");
    facedGameOver = Timer::create(1.f); 
    puangFailMoving = Timer::create(1.f);
    puangCrying = Timer::create(1.f);
    gameOverPuangWeightUp = Timer::create(1.f);
    gameOverPuangWeightDown = Timer::create(1.f);
    puangWeightCnt = 0;
    puangFail = Object::create("Images/Puang/Çª¾Ó_µÞ¸ð½À.png", roomRightScene, 480, 100);
    puangFail->hide();
    cloud->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)-> bool {
        cloud->hide();
        return true;
    });
    gameClearScene = Scene::create("gameClearScene", "Images/Stage/clearBackground.PNG");
    gameClearTimer = Timer::create(2.f);

    keyClickAble = true;


    closetUnlocked = false;
    hamburger = Object::create("Images/Stage/hamburger.png", roomLeftScene, 280, 200);
    hamburger->hide();
    noBlocking = false; 
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
        keySpin = false;
        gymManSpin = false;
        resetBag();

        gameClearScene->enter();
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
            if (!noBlocking) 
                showFake();
            key->show();
            gymMan->show();
            if (!noBlocking) 
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
            if (keyStatus == 1000) {
                keyStatus = 0;
            }
            

            timer->start();
        }
        return true;
    });
    gymManSpinTimer->setOnTimerCallback([&](TimerPtr timer)->bool {
        timer->stop();

        if (gymManSpin) {
            timer->set(0.1f);
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
            if (gymStatus == 1000) {
                gymStatus = 0;
            }

            timer->start();
        }
        return true;
    });
    gymMan->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)->bool {
        showFake();
        keyClickAble = false;
        gymManSpin = false;
        
        keySpin = false;
        puangFail->show();
        puangFailMoving->start();


        return true;
    });
    puangFailMoving->setOnTimerCallback([&](TimerPtr timer)->bool {
        timer->stop();
        puangCrying->start();
        return true;
    });

    puangCrying->setOnTimerCallback([&](TimerPtr timer)->bool {
        timer->stop();
        puangFail->setImage("Images/Puang/Çª¾Ó_Àý±Ô.png");

        facedGameOver->start();
        return true;
    });

    facedGameOver->setOnTimerCallback([&](TimerPtr timer)->bool {
        timer->stop();
        hideFake();
        
        setGameOption(GameOption::GAME_OPTION_INVENTORY_BUTTON, false);

        resetBag();
        gameOverScene->enter();
        puangFail->show();
        puangFail->setImage("Images/Stage/Çª¾Ó_¿îµ¿.png");
        puangFail->locate(gameOverScene, 350, 50);
        gameOverPuangWeightDown->start();
        return true;
    });
    gameOverPuangWeightUp->setOnTimerCallback([&](TimerPtr timer)->bool {
        if (puangWeightCnt < 4) {
            timer->stop();
            timer->set(1.f);
            puangFail->setImage("Images/Stage/Çª¾Ó_¿îµ¿.png");
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
            puangFail->setImage("Images/Stage/Çª¾Ó_¿îµ¿2.png");
            gameOverPuangWeightUp->start();
            puangWeightCnt++;
        }
        else {
            root->getStageSelectScene()->enter();
        }


        return true;
    });

    key->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)->bool {
        if (keyClickAble) {
            keySpin = false;
            gymManSpin = false;

            hideFake();

            key->pick();
            noBlocking = true;

        }

        return true;
    });

}

void StageComponent::makeStage7() {

    gameClearScene = Scene::create("gameClearScene", "Images/Stage/clearBackground.PNG");
    gameClearTimer = Timer::create(2.f);
    refrigeratorUp = Object::create("Images/Stage/rUC.png", roomLeftScene, 250, 400);
    refrigeratorDown = Object::create("Images/Stage/rDC.png", roomLeftScene, 250, 150);


    puangHittingStatus = 0;
    hitCnt = 0;

    watermelon = Object::create("Images/Stage/watermelon.png", roomLeftScene, 310, 280);
    watermelon->hide();

    puangHitting = Object::create("Images/Puang/Çª¾Ó_ÀÚ¸£±â1.PNG", roomLeftScene, 840, 120);
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
    facedGameOver = Timer::create(1.f); 
    puangFailMoving = Timer::create(1.f);
    puangCrying = Timer::create(1.f);
    gameOverPuangWeightUp = Timer::create(1.f);
    gameOverPuangWeightDown = Timer::create(1.f);
    puangWeightCnt = 0;
    puangFail = Object::create("Images/Puang/Çª¾Ó_µÞ¸ð½À.png", roomRightScene, 180, 100);
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
                puangHitting->setImage("Images/Puang/Çª¾Ó_ÀÚ¸£±â2.PNG");
                puangHittingStatus = 1;
            }
            
            else {
                puangHitting->setImage("Images/Puang/Çª¾Ó_ÀÚ¸£±â1.PNG");
                puangHittingStatus = 0;
            }
            
            hitCnt++;     
        }
        else {
            puangHitting->setImage("Images/Stage/Çª¾Ó_»ç¶û.png");
            watermelonDesk->setImage("Images/Stage/watermelonBreak.png");
            hamburger->show();
        }
        return true;
    });

    hamburger->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)-> bool {
        setGameOption(GameOption::GAME_OPTION_INVENTORY_BUTTON, false);
        gameClearScene->enter();
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


    sofaCushionLeft->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)->bool {
        sofaCushionLeft->locate(roomRightScene, 300, 70);
        showFake();
        puangFail->show();
        puangFailMoving->start();
        return true;
    });
    puangFailMoving->setOnTimerCallback([&](TimerPtr timer)->bool {
        timer->stop();
        puangCrying->start();
        return true;
    });

    puangCrying->setOnTimerCallback([&](TimerPtr timer)->bool {
        timer->stop();
        puangFail->setImage("Images/Puang/Çª¾Ó_Àý±Ô.png");

        facedGameOver->start();
        return true;
    });

    facedGameOver->setOnTimerCallback([&](TimerPtr timer)->bool {
        timer->stop();
        
        hideFake();
        setGameOption(GameOption::GAME_OPTION_INVENTORY_BUTTON, false);

        resetBag();
        gameOverScene->enter();
        puangFail->show();
        puangFail->setImage("Images/Stage/Çª¾Ó_¿îµ¿.png");
        puangFail->locate(gameOverScene, 350, 50);
        gameOverPuangWeightDown->start();
        return true;
    });
    gameOverPuangWeightUp->setOnTimerCallback([&](TimerPtr timer)->bool {
        if (puangWeightCnt < 4) {
            timer->stop();
            timer->set(1.f);
            puangFail->setImage("Images/Stage/Çª¾Ó_¿îµ¿.png");
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
            puangFail->setImage("Images/Stage/Çª¾Ó_¿îµ¿2.png");
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
    comeBigFish = Timer::create(0.1f);
    comeBigFishX = 700;
    eatingFish = Timer::create(2.f);

    givingFish = Timer::create(1.f);
    gameClearScene = Scene::create("gameClearScene", "Images/Stage/clearBackground.PNG");
    gameClearTimer = Timer::create(2.f);
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


    
    bigFish = Object::create("Images/Stage/bigFishStand.png", roomLeftScene, 700, 50);
    bigFish->setScale(0.6f);
    gameOverScene = Scene::create("gameOverScene", "Images/Stage/gameOverScene.PNG");
    facedGameOver = Timer::create(1.f); 
    puangFailMoving = Timer::create(1.f);
    puangCrying = Timer::create(1.f);
    gameOverPuangWeightUp = Timer::create(1.f);
    gameOverPuangWeightDown = Timer::create(1.f);
    puangWeightCnt = 0;
    puangFail = Object::create("Images/Puang/Çª¾Ó_µÞ¸ð½À.png", roomLeftScene, 100, 50);
    puangFail->hide();
    fishDead = false; 
    blockBigFishClick = false;
    blockDishClick = false; 
    blockChickenClick = false;
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

    chicken->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)->bool {
        if (!blockChickenClick) {

            if (fishDead)
                return true;


            showFake();
            puangFail->show();
            puangFailMoving->start();
            blockBigFishClick = true;
            blockDishClick = true; 
            blockChickenClick = true;
            
        }
        

        return true;
    });


    puangFailMoving->setOnTimerCallback([&](TimerPtr timer)->bool {
        timer->stop();
        bigFish->setImage("Images/Stage/bigFishOpenV.png");
        bigFish->setScale(0.6f);
        puangCrying->start();
        return true;
    });

    puangCrying->setOnTimerCallback([&](TimerPtr timer)->bool {
        timer->stop();
        puangFail->setImage("Images/Puang/Çª¾Ó_Àý±Ô.png");
        if (fishTemp) {
            fishTemp->hide();
        }

        facedGameOver->start();
        return true;
    });

    facedGameOver->setOnTimerCallback([&](TimerPtr timer)->bool {
        timer->stop();
        hideFake();
        setGameOption(GameOption::GAME_OPTION_INVENTORY_BUTTON, false);

        resetBag();
        gameOverScene->enter();
        puangFail->show();
        puangFail->setImage("Images/Stage/Çª¾Ó_¿îµ¿.png");
        puangFail->locate(gameOverScene, 350, 50);
        gameOverPuangWeightDown->start();
        return true;
    });
    gameOverPuangWeightUp->setOnTimerCallback([&](TimerPtr timer)->bool {
        if (puangWeightCnt < 4) {
            timer->stop();
            timer->set(1.f);
            puangFail->setImage("Images/Stage/Çª¾Ó_¿îµ¿.png");
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
            puangFail->setImage("Images/Stage/Çª¾Ó_¿îµ¿2.png");
            gameOverPuangWeightUp->start();
            puangWeightCnt++;
        }
        else {
            root->getStageSelectScene()->enter();
        }


        return true;
    });

    dish->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)->bool {

        if (!blockDishClick) {
            if (fish->isHanded()) {
                showFake();
                fishDead = true;
                fish->drop();
                fish->hide();
                fish->locate(roomLeftScene, 1280, 720);
                puangGivingFish = Object::create("Images/Puang/Çª¾Ó_µÞ¸ð½À.png", roomLeftScene, 130, 50);
                givingFish->start();
            }
            blockBigFishClick = true;
            blockDishClick = true;
            blockChickenClick = true;   
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
        hideFake();
        hamburgerCanClick = true;


        return true;
    });

    bigFish->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)->bool {
        if (!blockBigFishClick) {
        
            if (fishDead)
                return true;
            if (fish->isHanded()) {
                showFake();
                puangFail->show();
                puangFail->locate(roomLeftScene, 600, 150);
                puangFail->setImage("Images/Puang/Çª¾Ó_µÞ_¼Õ.png");
                fishTemp = Object::create("Images/Stage/fish.png", roomLeftScene, 750, 250);

                puangFailMoving->start();

            }
            blockDishClick = true;
            blockBigFishClick = true;
            blockChickenClick = true; 
        }

        return true;
    });


    hamburger->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)-> bool {
        resetBag();
        if (hamburgerCanClick) {
            setGameOption(GameOption::GAME_OPTION_INVENTORY_BUTTON, false);
            gameClearScene->enter();
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



        

}

void StageComponent::makeStage9() {
    starBox1 = Object::create("Images/Stage/emptyStar.png", roomLeftScene, 200, 500);
    starBox2 = Object::create("Images/Stage/emptyStar.png", roomLeftScene, 300, 500);
    starBox3 = Object::create("Images/Stage/emptyStar.png", roomLeftScene, 400, 500);
    starBox4 = Object::create("Images/Stage/emptyStar.png", roomLeftScene, 500, 500);
    starBox5 = Object::create("Images/Stage/emptyStar.png", roomLeftScene, 600, 500);

    sofa = Object::create("Images/Stage/sofaFront.png", roomLeftScene, 620, 150);
    sofaCushion = Object::create("Images/Stage/cushion.png", roomLeftScene, 600, 50);
    star3 = Object::create("Images/Stage/fullStar.png", roomLeftScene, 600, 50);
    star3->hide();
    gymMan = Object::create("Images/Trainer/trainer.png", roomLeftScene, 600, 80);
    bat1 = Object::create("Images/Stage/bat.png", roomRightScene, 250, 250);
    bat2 = Object::create("Images/Stage/bat.png", roomLeftScene, 250, 250);
    bat2->hide();
    
    windowLeft = Object::create("Images/Stage/curtainSide.png", roomRightScene, 500, 330); 
    windowRight = Object::create("Images/Stage/curtainSide.png", roomRightScene, 635, 281); 
    windowStatus = 0;
    gymManDead = false;

    bottle1 = Object::create("Images/Stage/bottle.png", roomRightScene, 600, 150);
    bottle2 = Object::create("Images/Stage/bottle.png", roomRightScene, 700, 100);

    bulga = Object::create("Images/Stage/bulga.png", roomRightScene, 600, 150);
    bulga->hide();
    star1 = Object::create("Images/Stage/fullStar.png", roomRightScene, 675, 410);
    star1->hide();
    star4 = Object::create("Images/Stage/fullStar.png", roomLeftScene, 210, 630);
    star4->hide();

    starCreateOnce = true;
    star5 = Object::create("Images/Stage/fullStar.png", roomRightScene, 600, 150);
    star5->hide();

    for (int i = 0; i < 5; i++) starBoxStatus[i] = false;

    starMainMenu = Object::create("Images/Button/home.png", roomLeftScene, 110, 630);
    clearStarCnt = 0;

    puangBatHit = Timer::create(1.f);
    puangBatHitAfter = Timer::create(1.f);
    gameClearScene = Scene::create("gameClearScene", "Images/Stage/clearBackground.PNG");
    gameClearTimer = Timer::create(2.f);
    hamburger = Object::create("Images/Stage/hamburger.png", roomLeftScene, 600, 700);
    hamburger->hide();
    burgerY = 700;
    burgerComingDown = Timer::create(0.5f);
    hamburgerCanClick = false;
    gameOverScene = Scene::create("gameOverScene", "Images/Stage/gameOverScene.PNG");
    facedGameOver = Timer::create(1.f); 
    puangFailMoving = Timer::create(1.f);
    puangCrying = Timer::create(1.f);
    gameOverPuangWeightUp = Timer::create(1.f);
    gameOverPuangWeightDown = Timer::create(1.f);
    puangWeightCnt = 0;
    gymManTurnStatus = 0;
    gymManTurnCnt = 0;
    puangFail = Object::create("Images/Puang/Çª¾Ó_µÞ¸ð½À.png", roomRightScene, 400, 50);
    puangFail->hide();
    gymManTurn = Object::create("Images/Stage/ºù±Û1.PNG", roomLeftScene, 500, 220);
    gymManTurn->setScale(1.5f);
    gymManTurn->hide();
    batTemp = Object::create("Images/Stage/¼öÁ÷bat.png", roomLeftScene, 650, 80);
    batTemp->hide();
    star2 = Object::create("Images/Stage/starcircle.PNG", roomLeftScene, 150, 10);
    star2->hide();
    sofaCushionOnce = false;
    bulgaCreateOnce = true;
    bulgaClickAble = true;
    burgerComingDown->setOnTimerCallback([&](TimerPtr timer)->bool {
        hamburger->show();
        timer->stop();
        if (burgerY > 150) {
            timer->set(0.5f);
            burgerY -= 30;
            hamburger->locate(roomLeftScene, 600, burgerY);
            timer->start();

        }
        else {
            hamburgerCanClick = true;
            hideFake();
            
        }


        return true;
    });

    gymMan->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)->bool {

        if (bat1->isHanded() || bat2->isHanded()) {

            gymMan->hide();
            gymManTurn->show();
            
            batTemp->show(); 

            
        }
        return true;
    });
    gymManTurn->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)->bool {
        if (gymManTurnCnt < 30) {
            if (gymManTurnCnt == 2) {
                showMessage("´õ »¡¸® µ¹·Á¾ß ÇØÇª¾Ó");
            }
            if (gymManTurnCnt == 15) {
                showMessage("´õ »¡¸® µ¹·Á¾ß ÇØÇª¾Ó!!!");
            }

            if (gymManTurnStatus == 0) {
                gymManTurn->setImage("Images/Stage/ºù±Û2.PNG");
                gymManTurnStatus = 1;

            }

            else {
                gymManTurn->setImage("Images/Stage/ºù±Û1.PNG");
                gymManTurnStatus = 0;

            }
            gymManTurnCnt++;
        
        }
        else {
            gymManTurn->hide();
            star2->show();
            gymManBang = Object::create("Images/Stage/trainerBang3.PNG", roomLeftScene, 100, 50);
            batTemp->hide();
            gymManDead = true;
        }
        return true;
    });

    hamburger->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)-> bool {
        resetBag();
        if (hamburgerCanClick) {
            setGameOption(GameOption::GAME_OPTION_INVENTORY_BUTTON, false);
            gameClearScene->enter();
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



    starMainMenu->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)->bool {
        starMainMenu->hide();
        star4->show();
        return true;
    });
    sofaCushion->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)->bool {
        if (!sofaCushionOnce) {
        
            if (gymManDead) {
                sofaCushion->locate(roomLeftScene, 400, 50);
                star3->show();
                batTemp->setImage("Images/Stage/bat.png");
            }
            sofaCushionOnce = true;
        }

        return true;
    });


    bulga->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)->bool {

        if (!bulgaClickAble) 
            return true;

        if (bulgaCreateOnce) {
            if (bat1->isHanded() || bat2->isHanded()) {
                showFake();
                puangBat = Object::create("Images/Puang/Çª¾Ó_µÞ_¼Õ.png", roomRightScene, 400, 50);
                puangBatTemp = Object::create("Images/Stage/bat.png", roomRightScene, 500, 150);
                puangBatHit->start();
                bulgaCreateOnce = false;
                bulgaClickAble = false;

            }

            else {
                showFake();
                puangFail->show();
                puangFailMoving->start();
            }

        }
        else {
            if (bat1->isHanded() || bat2->isHanded()) {
            }
            else {
                showFake();
                puangFail->show();
                puangFailMoving->start();
            }
        }






        return true;
    });

    puangFailMoving->setOnTimerCallback([&](TimerPtr timer)->bool {
        timer->stop();
        bulga->setScale(4.f);
        puangCrying->start();
        return true;
    });

    puangCrying->setOnTimerCallback([&](TimerPtr timer)->bool {
        timer->stop();
        puangFail->setImage("Images/Puang/Çª¾Ó_Àý±Ô.png");

        facedGameOver->start();
        return true;
    });

    facedGameOver->setOnTimerCallback([&](TimerPtr timer)->bool {
        timer->stop();
        
        hideFake();
        setGameOption(GameOption::GAME_OPTION_INVENTORY_BUTTON, false);

        resetBag();
        gameOverScene->enter();
        puangFail->show();
        puangFail->setImage("Images/Stage/Çª¾Ó_¿îµ¿.png");
        puangFail->locate(gameOverScene, 350, 50);
        gameOverPuangWeightDown->start();
        return true;
    });
    gameOverPuangWeightUp->setOnTimerCallback([&](TimerPtr timer)->bool {
        if (puangWeightCnt < 4) {
            timer->stop();
            timer->set(1.f);
            puangFail->setImage("Images/Stage/Çª¾Ó_¿îµ¿.png");
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
            puangFail->setImage("Images/Stage/Çª¾Ó_¿îµ¿2.png");
            gameOverPuangWeightUp->start();
            puangWeightCnt++;
        }
        else {
            root->getStageSelectScene()->enter();
        }


        return true;
    });







    puangBatHit->setOnTimerCallback([&](TimerPtr timer)->bool {
        timer->stop();
        puangBatTemp->setImage("Images/Stage/batR.png");
        puangBatTemp->locate(roomRightScene, 580, 150);
        star5->show();
        bulga->locate(roomRightScene, 700, 80);
        puangBatHitAfter->start();


        return true;
    });
    puangBatHitAfter->setOnTimerCallback([&](TimerPtr timer)->bool {
        timer->stop();
        puangBatTemp->hide();
        puangBat->hide();
        hideFake();

        bulgaClickAble = true;




        return true;
    });
    bottle1->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)->bool {
        bottle1->setImage("Images/Stage/bottleBreak.png");
        bulga->show();
        return true;
    });
    bottle2->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)->bool {
        bottle2->setImage("Images/Stage/bottleBreak.png");
        return true;
    });
    bat1->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)->bool {
        bat1->pick();
        return true;
    });
    bat2->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)->bool {
        bat2->pick();
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
            if (starCreateOnce) {
                windowRight->setImage("Images/Stage/nightWindow.png");
                star1->show();
                starCreateOnce = false;
            }

        }
        return true;
    });

    star1->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)->bool {
        star1->pick();
        return true;
    });
    star3->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)->bool {
        star3->pick();
        return true;
    });
    star2->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)->bool {
        star2->setImage("Images/Stage/fullStar.png");
        star2->pick();
        
        return true;
    });
    star4->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)->bool {
        star4->pick();
        return true;
    });
    star5->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)->bool {
        star5->pick();
        return true;
    });

    starBox1->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)->bool {
        if (starBoxStatus[0])
            return true;
        starBoxStatus[0] = true;
        if (clearStarCnt < 5) {
            if (star1->isHanded() || star2->isHanded() || star3->isHanded() || star4->isHanded() || star5->isHanded()) {
                starBox1->setImage("Images/Stage/fullStar.png");

                clearStarCnt++;
            }

            if (star1->isHanded()) {
                star1->drop();
                star1->hide();

            }
            if (star2->isHanded()) {
                star2->drop();
                star2->hide();
            }
            if (star3->isHanded()) {
                star3->drop();
                star3->hide();
            }
            if (star4->isHanded()) {
                star4->drop();
                star4->hide();
            }
            if (star5->isHanded()) {
                star5->drop();
                star5->hide();
            }

            if (clearStarCnt == 5) {
                if (star1->isHanded() || star2->isHanded() || star3->isHanded() || star4->isHanded() || star5->isHanded()) {
                    starBox1->setImage("Images/Stage/fullStar.png");

                    clearStarCnt++;
                }
                if (star1->isHanded()) {
                    star1->drop();
                    star1->hide();

                }
                if (star2->isHanded()) {
                    star2->drop();
                    star2->hide();
                }
                if (star3->isHanded()) {
                    star3->drop();
                    star3->hide();
                }
                if (star4->isHanded()) {
                    star4->drop();
                    star4->hide();
                }
                if (star5->isHanded()) {
                    star5->drop();
                    star5->hide();
                }


                showFake();
                burgerComingDown->start();
            }


        }

        return true;
    });
    starBox2->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)->bool {
        if (starBoxStatus[1])
            return true;
        starBoxStatus[1] = true;
        if (clearStarCnt < 5) {

            if (star1->isHanded() || star2->isHanded() || star3->isHanded() || star4->isHanded() || star5->isHanded()) {
                starBox2->setImage("Images/Stage/fullStar.png");

                clearStarCnt++;
              }
            if (star1->isHanded()) {
                star1->drop();
                star1->hide();
          
            }
            if (star2->isHanded()) {
                star2->drop();
                star2->hide();
              }
            if (star3->isHanded()) {
                star3->drop();
                star3->hide();
            }
            if (star4->isHanded()) {
                star4->drop();
                star4->hide();
              }
            if (star5->isHanded()) {
                star5->drop();
                star5->hide();
            }
            if (clearStarCnt == 5) {
                if (star1->isHanded() || star2->isHanded() || star3->isHanded() || star4->isHanded() || star5->isHanded()) {
                    starBox2->setImage("Images/Stage/fullStar.png");

                    clearStarCnt++;
                }
                if (star1->isHanded()) {
                    star1->drop();
                    star1->hide();

                }
                if (star2->isHanded()) {
                    star2->drop();
                    star2->hide();
                }
                if (star3->isHanded()) {
                    star3->drop();
                    star3->hide();
                }
                if (star4->isHanded()) {
                    star4->drop();
                    star4->hide();
                }
                if (star5->isHanded()) {
                    star5->drop();
                    star5->hide();
                }
                showFake();
                burgerComingDown->start();
            }

        }

        return true;
    });
    starBox3->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)->bool {
        if (starBoxStatus[2])
            return true;
        starBoxStatus[2] = true;
        if (clearStarCnt < 5) {
            if (star1->isHanded() || star2->isHanded() || star3->isHanded() || star4->isHanded() || star5->isHanded()) {
                starBox3->setImage("Images/Stage/fullStar.png");

                clearStarCnt++;
            }
            if (star1->isHanded()) {
                star1->drop();
                star1->hide();

            }
            if (star2->isHanded()) {
                star2->drop();
                star2->hide();
            }
            if (star3->isHanded()) {
                star3->drop();
                star3->hide();
            }
            if (star4->isHanded()) {
                star4->drop();
                star4->hide();
            }
            if (star5->isHanded()) {
                star5->drop();
                star5->hide();
            }
            if (clearStarCnt == 5) {
            
                if (star1->isHanded() || star2->isHanded() || star3->isHanded() || star4->isHanded() || star5->isHanded()) {
                    starBox3->setImage("Images/Stage/fullStar.png");

                    clearStarCnt++;
                }
                if (star1->isHanded()) {
                    star1->drop();
                    star1->hide();

                }
                if (star2->isHanded()) {
                    star2->drop();
                    star2->hide();
                }
                if (star3->isHanded()) {
                    star3->drop();
                    star3->hide();
                }
                if (star4->isHanded()) {
                    star4->drop();
                    star4->hide();
                }
                if (star5->isHanded()) {
                    star5->drop();
                    star5->hide();
                }
                showFake();
                burgerComingDown->start();
            }

        }

        return true;
    });
    starBox4->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)->bool {
        if (starBoxStatus[3])
            return true;
        starBoxStatus[3] = true;
        if (clearStarCnt < 5) {
            if (star1->isHanded() || star2->isHanded() || star3->isHanded() || star4->isHanded() || star5->isHanded()) {
                starBox4->setImage("Images/Stage/fullStar.png");

                clearStarCnt++;
            }
            if (star1->isHanded()) {
                star1->drop();
                star1->hide();

            }
            if (star2->isHanded()) {
                star2->drop();
                star2->hide();
            }
            if (star3->isHanded()) {
                star3->drop();
                star3->hide();
            }
            if (star4->isHanded()) {
                star4->drop();
                star4->hide();
            }
            if (star5->isHanded()) {
                star5->drop();
                star5->hide();
            }
            if (clearStarCnt == 5) {
                if (star1->isHanded() || star2->isHanded() || star3->isHanded() || star4->isHanded() || star5->isHanded()) {
                    starBox4->setImage("Images/Stage/fullStar.png");

                    clearStarCnt++;
                }
                if (star1->isHanded()) {
                    star1->drop();
                    star1->hide();

                }
                if (star2->isHanded()) {
                    star2->drop();
                    star2->hide();
                }
                if (star3->isHanded()) {
                    star3->drop();
                    star3->hide();
                }
                if (star4->isHanded()) {
                    star4->drop();
                    star4->hide();
                }
                if (star5->isHanded()) {
                    star5->drop();
                    star5->hide();
                }
                showFake();
                burgerComingDown->start();
            }

        }

        return true;
    });
    starBox5->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)->bool {
        if (starBoxStatus[4])
            return true;
        starBoxStatus[4] = true;
        if (clearStarCnt < 5) {
            if (star1->isHanded() || star2->isHanded() || star3->isHanded() || star4->isHanded() || star5->isHanded()) {
                starBox5->setImage("Images/Stage/fullStar.png");

                clearStarCnt++;
            }
            if (star1->isHanded()) {
                star1->drop();
                star1->hide();

            }
            if (star2->isHanded()) {
                star2->drop();
                star2->hide();
            }
            if (star3->isHanded()) {
                star3->drop();
                star3->hide();
            }
            if (star4->isHanded()) {
                star4->drop();
                star4->hide();
            }
            if (star5->isHanded()) {
                star5->drop();
                star5->hide();
            }
            if (clearStarCnt == 5) {
                if (star1->isHanded() || star2->isHanded() || star3->isHanded() || star4->isHanded() || star5->isHanded()) {
                    starBox5->setImage("Images/Stage/fullStar.png");

                    clearStarCnt++;
                }
                if (star1->isHanded()) {
                    star1->drop();
                    star1->hide();

                }
                if (star2->isHanded()) {
                    star2->drop();
                    star2->hide();
                }
                if (star3->isHanded()) {
                    star3->drop();
                    star3->hide();
                }
                if (star4->isHanded()) {
                    star4->drop();
                    star4->hide();
                }
                if (star5->isHanded()) {
                    star5->drop();
                    star5->hide();
                }
                showFake();
                burgerComingDown->start();
            
            }

        }

        return true;
    });

}


void StageComponent::makeStage10() {

    setGameOption(GameOption::GAME_OPTION_INVENTORY_BUTTON, false);

    whiteDoor = Object::create("Images/Stage/doorOpen.png", roomLeftScene, 720, 140);

    gymMan = Object::create("Images/Stage/Æ®·¹ÀÌ³Ê_»ßÁü.png", roomLeftScene, 200, 150);

    hamburger = Object::create("Images/Stage/hamburger.png", roomLeftScene, 600, 50);

    puangEnding = Object::create("Images/Puang/Çª¾Ó_µÞ¸ð½À.png", roomLeftScene, 650, 50);
    puangEnding->hide();
    messageBox = Object::create("Images/Stage/¼û±æµ¥¾ø±ÙÀ°2.PNG", roomLeftScene, 900, 600);
    messageBox->hide();
    puangGoing = Timer::create(3.f);
    gymManGoOut = Timer::create(0.1f);
    gymManGoOutAfter = Timer::create(2.f);
    gymManGoOutBefore = Timer::create(2.f);
    gymManGoOutX = 200;
    gameClearScene = Scene::create("gameClearScene", "Images/Stage/clearBackground.PNG");
    gameClearTimer = Timer::create(2.f);
    hamburger->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)->bool {

        showFake();
        puangEnding->show();
        puangGoing->start();
        return true;
    });

    puangGoing->setOnTimerCallback([&](TimerPtr timer)->bool {
        timer->stop();
        gymManGoOut->start();
        

        return true;
    });

    gymManGoOut->setOnTimerCallback([&](TimerPtr timer)->bool {
        timer->stop();
        if (gymManGoOutX < 900) {
            if (gymManGoOutX == 700) {
                timer->set(2.f);
                messageBox->show();


                gymMan->setImage("Images/Stage/Æ®·¹ÀÌ³Ê_¿ò.png");
            }
            else 
                timer->set(0.1f);
            gymManGoOutX += 10;
            gymMan->locate(roomLeftScene, gymManGoOutX, 150);
            messageBox->locate(roomLeftScene, gymManGoOutX+200, 500);
            timer->start();
        }
        else {

            gymManGoOutBefore->start();
        }


        return true;
    });


    gymManGoOutBefore->setOnTimerCallback([&](TimerPtr timer)->bool {
        timer->stop();
        gymMan->hide();
        whiteDoor->setImage("Images/Stage/doorClose.png");
        messageBox->hide();
        whiteDoor->locate(roomLeftScene, 880, 175);
        gymManGoOutAfter->start();
        return true;
    });

    gymManGoOutAfter->setOnTimerCallback([&](TimerPtr timer)-> bool {
        hideFake();
        setGameOption(GameOption::GAME_OPTION_INVENTORY_BUTTON, false);
        gameClearScene->enter();
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

void StageComponent::resetObject() {

    // stage1
    closet = NULL;

    windowLeft = NULL;
    windowRight = NULL;
    wallCloset =
    sofa = NULL;
    sofaCushionLeft = NULL;
    puangBitjaru = NULL;
    gymMan = NULL;
    plant = NULL;


    drawer = NULL;
    bitjaru = NULL;
    bitjaruTemp = NULL;
    burgerMoved = NULL;
    burgerMovedTimer = NULL;
    burgerMovedTimerAfter = NULL;

    // stage3
    bookshelf = NULL;
    book1 = NULL;
    book2 = NULL;
    book3 = NULL;
    bookTemp = NULL;
    brokenChair = NULL;
    brokenChairTemp = NULL;
    stand = NULL;
    puangJumping = NULL;
    puangFallDown = NULL;
    puangFallDownAfter = NULL;
    puangLovingTimer = NULL;
    burgerReach = NULL;
    wallIsOpen = NULL;
    // stage4
    car = NULL;
    sign = NULL;
    paint = NULL;
    paintTemp = NULL;
    paintingPuang = NULL;
    carMan = NULL;
    puangComePaint = NULL;
    carManComming = NULL;
    carManX = NULL;
    carManInside = NULL;
    carOut = NULL;
    carX = NULL;

    // stage5
    elephant = NULL;
    ballon = NULL;
    ballonGettingBig = NULL;
    gymManGymingFast = NULL;
    elephantBallonGetBig = NULL;
    weight = NULL;
    weightTemp = NULL;
    cntTwo = NULL;
    ballonScale = NULL;
    ballonX = NULL;
    ballonY = NULL;
    gymManDStatus = NULL;
    gymManSpeed = NULL;
    gymManY = NULL;

    // stage6
    bottle = NULL;
    windowStatus = NULL;
    key = NULL;
    cloud = NULL;
    keySpinTimer = NULL;
    gymManSpinTimer = NULL;
    gymManSpin = NULL;
    gymStatus = NULL;
    keySpin = NULL;
    keyStatus = NULL;
    closetUnlocked = NULL;

    // stage7
    refrigeratorUp = NULL;
    refrigeratorDown = NULL;
    watermelon = NULL;
    watermelonDesk = NULL;
    puangHittingStatus = NULL;
    hitCnt = NULL;
    desk = NULL;
    puangHitting = NULL;

    // stage8
    fish = NULL;
    puangGivingFish = NULL;
    fishTemp = NULL;
    chicken = NULL;
    bigFish = NULL;
    dish = NULL;
    gymManFood = NULL;
    fly = NULL;
    flyLeft = NULL;
    comeBigFishX = NULL;
    givingFish = NULL;
    comeBigFish = NULL;
    eatingFish = NULL;
    hamburgerCanClick = NULL;

    //stage 9
    sofaCushion = NULL;
    bat1 = NULL;
    bat2 = NULL;
    bottle1 = NULL;
    bottle2 = NULL;
    gymManTurn = NULL;
    batTemp = NULL;
    gymManBang = NULL;
    gymManTurnStatus = NULL;
    gymManTurnCnt = NULL;

    star1 = NULL; //window
    star2 = NULL; //bingle
    star3 = NULL; //bangsuk
    star4 = NULL; //mainmenu
    star5 = NULL; //bulga
    starBox1 = NULL;
    starBox2 = NULL;
    starBox3 = NULL;
    starBox4 = NULL;
    starBox5 = NULL;
    starMainMenu = NULL;
    clearStarCnt = NULL;
    //starBoxStatus[5];
    starBoxStatus[0] = 0;
    starBoxStatus[1] = 0;
    starBoxStatus[2] = 0;
    starBoxStatus[3] = 0;
    starBoxStatus[4] = 0;
    gymManDead = NULL;
    burgerY = NULL;
    puangBat = NULL;
    puangBatTemp = NULL;
    puangBatHit = NULL;
    puangBatHitAfter = NULL;
    burgerComingDown = NULL;
    bulga = NULL;

    puangEnding = NULL;
    whiteDoor = NULL;
    messageBox = NULL;
    puangGoing = NULL;
    gymManGoOut = NULL;
    gymManGoOutBefore = NULL;
    gymManGoOutAfter = NULL;
    gymManGoOutX = NULL;


    hamburger = NULL;
    gameClearScene = NULL;
    gameClearTimer = NULL;
    puangFail = NULL;
    gameOverScene = NULL;
    puangFailMoving = NULL;
    puangCrying = NULL;
    puangWeightCnt = NULL;
    gameOverPuangWeightUp = NULL;
    gameOverPuangWeightDown = NULL;
    facedGameOver = NULL;

}



