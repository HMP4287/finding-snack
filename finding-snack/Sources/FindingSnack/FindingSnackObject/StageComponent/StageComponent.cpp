#include "StageComponent.h"

StageComponent::StageComponent(FindingSnackObject* r) {
    root = r;
    root->stageComponent = this;
    //construct();
}

StageComponent::~StageComponent() {};

// 객체가 생성될때 변수 초기화 및 초기 셋팅등 생성자 역할을 하게 된다.
void StageComponent::enter() {
    resetBag();
    // default 요소 초기화 
    char temp[45];
    for (int i = 0; i < 45; i++) {
        temp[i] = 0;
    }
	//sprintf(temp, "Images/Stage/stageStart/%d.PNG", root->getCurrentStage());
    sprintf(temp, "Images/Stage/stageStart/%d.PNG", root->getClickedStage());

    // 가설 
    // 1. 이름이 똑같음녀 (주소는 달랐다.)
    // 2. 기타 코드 오류 
    showStageScene = Scene::create("showStage", temp);

    // 이게 아니지, 아맞지 이거 다음이 문제지 showStageScene에서 2초지나느 타이머가뭐야 
    // 그게중요해 
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
    // 게임옵션은 Stage진입 시 재 등장 
    setGameOption(GameOption::GAME_OPTION_INVENTORY_BUTTON, true);





};

// 객체가 삭제/제거될때 메모리 삭제 등 소멸자 역할을 하게 된다.
void StageComponent::exit() {};


// 객체의 주 행동들을 작성하는 곳으로 특정 시간마다 변하는 애니메이션이나 타이밍을 체크 하며 다음과 같이 작성 할 수 있다.
void StageComponent::update() {};

// 화면에 그려질 부분을 컨트롤 하는 부분이다. 랜더링을 담당한다.
void StageComponent::draw() {};

// 사용자의 조작에 어떤 반응을 할것인지를 컨트롤 할 수 있는 부분이다.
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
        // 초기화가 되었을지 ? 그리고 이 클래스의 엔터가 실행될지 ? 

        enter();
        root->getStage()->enter();
        return true;
    });
    stageRestartBtnR->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)->bool {
        // 초기화가 되었을지 ? 그리고 이 클래스의 엔터가 실행될지 ? 
        enter();
        root->getStage()->enter();
        return true;
    });
    goBackMainMenuBtnL->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)->bool {
        // 초기화가 되었을지 ? 그리고 이 클래스의 엔터가 실행될지 ? 
        setGameOption(GameOption::GAME_OPTION_INVENTORY_BUTTON, false);
        resetBag();
        root->getMainMenuScene()->enter();
        return true;
    });
    goBackMainMenuBtnR->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)->bool {
        // 초기화가 되었을지 ? 그리고 이 클래스의 엔터가 실행될지 ? 
        setGameOption(GameOption::GAME_OPTION_INVENTORY_BUTTON, false);
        resetBag();
        root->getMainMenuScene()->enter();
        return true;
    });
};

void StageComponent::resetBag() {

    // 인벤토리 40박스니까 40번 반복해서 모두 지워야하는지 ?
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


// 만들어 놓은 함수들을 가지고 로직 수행
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
    // default 요소들을 위에 꾸미고 더하면 된다. 

    // 왼쪽 화면에 옷장, 창문    
    // 오른쪽 화면에 벽장안에 헬창, 쇼파 쿠션 밑에 게임기 

    // enter 
    closet = Object::create("Images/Stage/closetClose.png", roomLeftScene, 200, 150);
    windowLeft = Object::create("Images/Stage/curtainClose.png", roomLeftScene, 720, 400); // x = 177, (닫혀있을때는 겹치게 보이려면 좀더 가까이 ) 
    windowRight = Object::create("Images/Stage/curtainClose.png", roomLeftScene, 880, 400); // -17
    
    wallCloset = Object::create("Images/Stage/wallclosetCloseTrainer.PNG", roomRightScene, 250, 250);
    sofa = Object::create("Images/Stage/sofaSide.png", roomRightScene, 550, 25);
    sofaCushionLeft = Object::create("Images/Stage/cushion.png", roomRightScene, 600, 170);
    sofaCushionRight = Object::create("Images/Stage/cushion.png", roomRightScene, 750, 125);

    hamburger = Object::create("Images/Stage/hamburger.png", roomRightScene, 650, 170);
    hamburger->hide();


    facedGameOver = Timer::create(1.f);




    // 성공 요소 
    gameClearScene = Scene::create("gameClearScene", "Images/Stage/clearBackground.PNG");
    gameClearTimer = Timer::create(2.f);

    // 실패 요소
    puangFail = Object::create("Images/Puang/푸앙_뒷모습.png", roomRightScene, 250, 50);
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
        // 초기화가 되었을지 ? 그리고 이 클래스의 엔터가 실행될지 ? 
        closet->setImage("Images/Stage/closetOpen.png");
        return true;
    });

    windowLeft->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)->bool {
        // 초기화가 되었을지 ? 그리고 이 클래스의 엔터가 실행될지 ? 
        windowLeft->setImage("Images/Stage/leftWindow.png");
        return true;
    });

    windowRight->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)->bool {
        // 초기화가 되었을지 ? 그리고 이 클래스의 엔터가 실행될지 ? 
        windowRight->setImage("Images/Stage/rightWindow.png");
        return true;
    });


    sofaCushionLeft->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)->bool {
        // 초기화가 되었을지 ? 그리고 이 클래스의 엔터가 실행될지 ? 
        sofaCushionLeft->locate(roomRightScene, 600, 70);
        hamburger->show(); 
        return true;
    }); 
    sofaCushionRight->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)->bool {
        // 초기화가 되었을지 ? 그리고 이 클래스의 엔터가 실행될지 ? 
        sofaCushionRight->locate(roomRightScene, 700, 25);
        return true;
    });


    // 실패 시
    wallCloset->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)->bool {
        // 초기화가 되었을지 ? 그리고 이 클래스의 엔터가 실행될지 ? 
		//접근한다 
        puangFail->show();
        puangFailMoving->start();

		

		//문열리면, 절규한다.
		//
		//게임오버화면 뜬다.
		//
		//게임오버화면 안에서 운동한다. 

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
        puangFail->setImage("Images/Puang/푸앙_절규.png");
        facedGameOver->start();
        return true;
    });

    facedGameOver->setOnTimerCallback([&](TimerPtr timer)->bool {
        timer->stop();
        
        //root->getStageSelectScene()->enter();
        setGameOption(GameOption::GAME_OPTION_INVENTORY_BUTTON, false);

        gameOverScene->enter();
        puangFail->setImage("Images/Stage/푸앙_운동.png");
        puangFail->locate(gameOverScene, 350, 50);
        gameOverPuangWeightDown->start();

        //puangFail->setImage("Images/Stage/푸앙_운동.png");
        //puangFail->locate(gameOverScene, 250, 250);
        // 실패하는 모션들 
        // 인벤토리 박스 삭제 필요, 
        return true;
    });
    gameOverPuangWeightUp->setOnTimerCallback([&](TimerPtr timer)->bool {
        if (puangWeightCnt < 4) {
            timer->stop();
            timer->set(1.f);
            puangFail->setImage("Images/Stage/푸앙_운동.png");
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
            puangFail->setImage("Images/Stage/푸앙_운동2.png");
            //puangFail->locate(gameOverScene, 250, 250);
            gameOverPuangWeightUp->start();
            puangWeightCnt++;
        }
        else {
            root->getStageSelectScene()->enter();
        }


        return true;
    });
    // 성공 시 
    hamburger->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)-> bool {
        //stage ++ 
        // game clear
        // menu Btn ?
        // go next game ? 
        setGameOption(GameOption::GAME_OPTION_INVENTORY_BUTTON, false);
        gameClearScene->enter();
        // 숫자 추가 
        // 1탄을 계속 깨면 2,3,탄이깨지는문제 발생 
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
    windowLeft = Object::create("Images/Stage/curtainClose.png", roomLeftScene, 710, 400); // x = 177, (닫혀있을때는 겹치게 보이려면 좀더 가까이 ) 
    windowRight = Object::create("Images/Stage/curtainClose.png", roomLeftScene, 900, 400); // -17

    sofa = Object::create("Images/Stage/sofaFront.png", roomLeftScene, 620, 150);

    burgerMovedTimer = Timer::create(1.f);
    burgerMovedTimerAfter = Timer::create(1.f);

    // 화분, 벽, 서랍 
    plant = Object::create("Images/Stage/plantClose.png", roomRightScene, 100, 250);
    wallCloset = Object::create("Images/Stage/wallclosetBitjaru.PNG", roomRightScene, 250, 250);
    drawer = Object::create("Images/Stage/drawerClose.png", roomRightScene, 550, 75);

    bitjaru = Object::create("Images/Stage/bitjaru.png", roomRightScene, 300, 300);
    bitjaru->setScale(1.5f);
    bitjaru->hide();


    // 성공
    
    gameClearScene = Scene::create("gameClearScene", "Images/Stage/clearBackground.PNG");
    gameClearTimer = Timer::create(2.f);




    // 실패 
    puangFail = Object::create("Images/Puang/푸앙_뒷모습.png", roomLeftScene, 650, 50);
    puangFail->hide();
    gameOverScene = Scene::create("gameOverScene", "Images/Stage/gameOverScene.PNG");
    facedGameOver = Timer::create(1.f); // 그냥 실패 절차중 하나임 
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

    // 실패 조건임 -----
    windowRight->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)->bool {

        //windowRight->setImage("Images/Stage/rightWindow.png");
        //gymMan = Object::create("Images/Trainer/trainer.png", roomLeftScene, 880, 150);

        //gymMan->locate(roomLeftScene, 880, 150);
        puangFail->show();
        puangFailMoving->start();
        return true;
    });
    // 실패조건 추가할 것 
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
        puangFail->setImage("Images/Puang/푸앙_절규.png");

        facedGameOver->start();
        return true;
    });

    facedGameOver->setOnTimerCallback([&](TimerPtr timer)->bool {
        timer->stop();
        
        //root->getStageSelectScene()->enter();
        setGameOption(GameOption::GAME_OPTION_INVENTORY_BUTTON, false);

        gameOverScene->enter();
        puangFail->setImage("Images/Stage/푸앙_운동.png");
        puangFail->locate(gameOverScene, 350, 50);
        gameOverPuangWeightDown->start();

        //puangFail->setImage("Images/Stage/푸앙_운동.png");
        //puangFail->locate(gameOverScene, 250, 250);
        // 실패하는 모션들 
        // 인벤토리 박스 삭제 필요, 
        return true;
    });
    gameOverPuangWeightUp->setOnTimerCallback([&](TimerPtr timer)->bool {
        if (puangWeightCnt < 4) {
            timer->stop();
            timer->set(1.f);
            puangFail->setImage("Images/Stage/푸앙_운동.png");
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
            puangFail->setImage("Images/Stage/푸앙_운동2.png");
            //puangFail->locate(gameOverScene, 250, 250);
            gameOverPuangWeightUp->start();
            puangWeightCnt++;
        }
        else {
            root->getStageSelectScene()->enter();
        }


        return true;
    });
    // 실패 여기까지. 
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
        // 빗자루 필요 
        bitjaru->show();



        

        return true;
    });
    drawer->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)->bool {
        drawer->setImage("Images/Stage/drawerOpen.png");
        drawer->locate(roomRightScene, 455, 40);
        return true;
    });

    // 성공 
    hamburger->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)->bool {
        if (burgerMoved) {
            setGameOption(GameOption::GAME_OPTION_INVENTORY_BUTTON, false);
            gameClearScene->enter();
            // 숫자 추가 
            // 1탄을 계속 깨면 2,3,탄이깨지는문제 발생 
            if (root->getCurrentStage() == root->getClickedStage())
                root->setCurrentStage(root->getCurrentStage() + 1);

            gameClearTimer->start();

        }
        else if (bitjaru->isHanded()) {
            // 푸앙이 + 빗자루 등장한다.
            bitjaru->drop();
            bitjaru->hide();
            //bitjaru = Object::create("Images/Stage/bitjaruLeft.png", roomLeftScene, 250, 100);
            bitjaruTemp = Object::create("Images/Stage/bitjaruLeft.png", roomLeftScene, 250, 100);
            bitjaruTemp->setScale(1.5f);
            puangBitjaru = Object::create("Images/Puang/푸앙_뒷모습.png", roomLeftScene, 250, 50);
            // 1초있다가 버거 빗자루로 친 화면 등장 
            // 
            // 빗자루 회전 + 버거 이동 
            
            burgerMovedTimer->start();

            // 퇴장   burgerMoved = true
            
        }
        else {
            showMessage("팔이 안 닿푸앙");
        
        }

        return true;
    });
    gameClearTimer->setOnTimerCallback([&](TimerPtr timer)->bool {
        timer->stop();
        root->getStageSelectScene()->enter();

        root->stageSelectComponent->update();

        return true;
    });
    // 성공여기까지 

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

    // 가방초기화에 브로큰 체어 

    // 왼쪽 화면 
    // 장농 + 장농 속 부서진 사다리 
    // 책장 + 책1, 2, 3층 
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
    // new 실패
    puangFallDown = Timer::create(1.f);
    puangFallDownAfter = Timer::create(1.f);

    // 실패 

    gameOverScene = Scene::create("gameOverScene", "Images/Stage/gameOverScene.PNG");
    facedGameOver = Timer::create(1.f); // 그냥 실패 절차중 하나임 
    puangFailMoving = Timer::create(1.f);
    puangCrying = Timer::create(1.f);
    gameOverPuangWeightUp = Timer::create(1.f);
    gameOverPuangWeightDown = Timer::create(1.f);
    puangWeightCnt = 0;
    // 오른 화면 
    // 장식 용스탠드
    // 높은 게임기 
    //hamburger = Object::create("Images/Stage/hamburger.png", roomRightScene, 380, 750);
    //hamburger->hide();
    wallCloset = Object::create("Images/Stage/wallCloBClosed.PNG", roomRightScene, 250, 220);
    hamburger = Object::create("Images/Stage/hamburger.png", roomRightScene, 340, 580);
    hamburger->hide();
    //hamburger->setScale(0.7f);
    stand = Object::create("Images/Stage/stand.png", roomRightScene, 580, 125);
    wallIsOpen = false;

    puangLovingTimer = Timer::create(1.f);
    puangFail = Object::create("Images/Puang/푸앙_뒷모습.png", roomLeftScene,  750, 150);
    puangFail->hide();
    puangJumping = Object::create("Images/Puang/푸앙_뒷모습.png", roomRightScene, 240, 300);
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
            showMessage("키가 안 닿푸앙");
        }
        // 버거 부러진의자 new 실패 
        else if (burgerReach == 1) {
            //puangFail->show();
            puangJumping->show();

            puangFallDown->start();
            

            
        }
        // 버거 책받침 성공 
        else if (burgerReach == 2) {
            //puangFail->show();
            //puangFail->setImage("Images/Puang/푸앙_사랑.png");

            puangJumping->show();
            puangJumping->setImage("Images/Puang/푸앙_사랑.png");

            //setGameOption(GameOption::GAME_OPTION_INVENTORY_BUTTON, false);
            //gameClearScene->enter();
            //// 숫자 추가 
            //// 1탄을 계속 깨면 2,3,탄이깨지는문제 발생 
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

        // 숫자 추가 
        // 1탄을 계속 깨면 2,3,탄이깨지는문제 발생 
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
        puangJumping = Object::create("Images/Puang/푸앙_눕.png", roomRightScene, 240, 100);
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

    // 실패 시작 접근, 책사라짐 놀람 ... 
    book1->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)->bool {
        //book1->hide();
        puangFail->show();
        puangFailMoving->start();


        return true;
    });
    // 실패조건 추가할 것 
    puangFailMoving->setOnTimerCallback([&](TimerPtr timer)->bool {
        timer->stop();
        book1->hide();
        puangCrying->start();
        return true;
    });

    puangCrying->setOnTimerCallback([&](TimerPtr timer)->bool {
        timer->stop();
        puangFail->setImage("Images/Puang/푸앙_절규.png");

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
        puangFail->setImage("Images/Stage/푸앙_운동.png");
        puangFail->locate(gameOverScene, 350, 50);
        gameOverPuangWeightDown->start();

        //puangFail->setImage("Images/Stage/푸앙_운동.png");
        //puangFail->locate(gameOverScene, 250, 250);
        // 실패하는 모션들 
        // 인벤토리 박스 삭제 필요, 
        return true;
    });
    gameOverPuangWeightUp->setOnTimerCallback([&](TimerPtr timer)->bool {
        if (puangWeightCnt < 4) {
            timer->stop();
            timer->set(1.f);
            puangFail->setImage("Images/Stage/푸앙_운동.png");
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
            puangFail->setImage("Images/Stage/푸앙_운동2.png");
            //puangFail->locate(gameOverScene, 250, 250);
            gameOverPuangWeightUp->start();
            puangWeightCnt++;
        }
        else {
            root->getStageSelectScene()->enter();
        }


        return true;
    });
    // 실패 여기까지. 
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
    // 왼쪽
    // 차, 피켓
    carMan = Object::create("Images/Trainer/trainer.png", roomLeftScene, 1200, 150);
    carMan->hide();
    carManX = 1200;
    car = Object::create("Images/Stage/car.png", roomLeftScene, 400, 150);
    carX = 400;
    sign = Object::create("Images/Stage/canPark.png", roomLeftScene, 200, 150);
    hamburger = Object::create("Images/Stage/hamburger.png", roomLeftScene, 650, 150);
    hamburger->hide();

    // 오른쪽 
    // 서랍 
    // 서랍 속 페인트         550, 75
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
            // drop hide 안하고 시도 
            paint->drop();
            paint->hide();
            // 푸앙 페인트들고 등장
            paintTemp = Object::create("Images/Stage/spray.png", roomLeftScene, 360, 230);

            paintingPuang = Object::create("Images/Puang/푸앙_뒷_손.png", roomLeftScene, 200, 150);
            puangComePaint->start();

            // 깃발 변하기
            // 차주 오기 
            // 차주 들어가기 
            // 차 빼기 
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
        // 재귀적으로 실행될듯 함 오버플로우 ?
        if (carManX > 600) {
            carManX -= 25;
            timer->set(0.1f);
            carMan->locate(roomLeftScene, carManX, 150);
            timer->start();
        }
        // 끝나면 차안에 넣기 
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
        // 끝나면 차안에 넣기 
        
            //carManInside->start();
        return true;
    });




    hamburger->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)->bool {
        setGameOption(GameOption::GAME_OPTION_INVENTORY_BUTTON, false);
        resetBag();
        gameClearScene->enter();
        // 숫자 추가 
        // 1탄을 계속 깨면 2,3,탄이깨지는문제 발생 
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
    // 왼쪽화면 
    // 잠금 옷장
    // 유리병 
    closet = Object::create("Images/Stage/closetLock.png", roomLeftScene, 200, 150);
    bottle = Object::create("Images/Stage/bottle.png", roomLeftScene, 750, 150);


    // 오른화면 
    // 창문 커튼 좌우 
    // 창문 유리 좌우 
    // 창문 오픈 우 
    // 키 회전, 미니헬스맨회전, 구름 안 회전 
    //windowLeft = Object::create("Images/Stage/")
    windowLeft = Object::create("Images/Stage/curtainSide.png", roomRightScene, 500, 330); // x = 177, (닫혀있을때는 겹치게 보이려면 좀더 가까이 ) 
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
    facedGameOver = Timer::create(1.f); // 그냥 실패 절차중 하나임 
    puangFailMoving = Timer::create(1.f);
    puangCrying = Timer::create(1.f);
    gameOverPuangWeightUp = Timer::create(1.f);
    gameOverPuangWeightDown = Timer::create(1.f);
    puangWeightCnt = 0;
    puangFail = Object::create("Images/Puang/푸앙_뒷모습.png", roomRightScene, 480, 100);
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
        // 숫자 추가 
        // 1탄을 계속 깨면 2,3,탄이깨지는문제 발생 
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
        // 끝나면 차안에 넣기 

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
        // 끝나면 차안에 넣기 

        //carManInside->start();
        return true;
    });
    gymMan->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)->bool {
        gymManSpin = false;
        puangFail->show();
        puangFailMoving->start();


        return true;
    });

    // 실패조건 추가할 것 
    puangFailMoving->setOnTimerCallback([&](TimerPtr timer)->bool {
        timer->stop();
        puangCrying->start();
        return true;
    });

    puangCrying->setOnTimerCallback([&](TimerPtr timer)->bool {
        timer->stop();
        puangFail->setImage("Images/Puang/푸앙_절규.png");

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
        puangFail->setImage("Images/Stage/푸앙_운동.png");
        puangFail->locate(gameOverScene, 350, 50);
        gameOverPuangWeightDown->start();

        //puangFail->setImage("Images/Stage/푸앙_운동.png");
        //puangFail->locate(gameOverScene, 250, 250);
        // 실패하는 모션들 
        // 인벤토리 박스 삭제 필요, 
        return true;
    });
    gameOverPuangWeightUp->setOnTimerCallback([&](TimerPtr timer)->bool {
        if (puangWeightCnt < 4) {
            timer->stop();
            timer->set(1.f);
            puangFail->setImage("Images/Stage/푸앙_운동.png");
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
            puangFail->setImage("Images/Stage/푸앙_운동2.png");
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
    // 왼쪽
    // 냉장고에 수박 
    // 책상 
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

    puangHitting = Object::create("Images/Puang/푸앙_자르기1.PNG", roomLeftScene, 840, 120);
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
    facedGameOver = Timer::create(1.f); // 그냥 실패 절차중 하나임 
    puangFailMoving = Timer::create(1.f);
    puangCrying = Timer::create(1.f);
    gameOverPuangWeightUp = Timer::create(1.f);
    gameOverPuangWeightDown = Timer::create(1.f);
    puangWeightCnt = 0;
    puangFail = Object::create("Images/Puang/푸앙_뒷모습.png", roomRightScene, 180, 100);
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
                puangHitting->setImage("Images/Puang/푸앙_자르기2.PNG");
                puangHittingStatus = 1;
            }
            
            else {
                puangHitting->setImage("Images/Puang/푸앙_자르기1.PNG");
                puangHittingStatus = 0;
            }
            
            hitCnt++;     
        }
        else {
            puangHitting->setImage("Images/Stage/푸앙_사랑.png");
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
        // 숫자 추가 
        // 1탄을 계속 깨면 2,3,탄이깨지는문제 발생 
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


    // 오른 
    // 쇼파에 트레이너 
    // 쇼파 쿠션 

    sofaCushionLeft->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)->bool {
        sofaCushionLeft->locate(roomRightScene, 300, 70);
        puangFail->show();
        puangFailMoving->start();
        return true;
    });
    
    // 실패조건 추가할 것 
    puangFailMoving->setOnTimerCallback([&](TimerPtr timer)->bool {
        timer->stop();
        puangCrying->start();
        return true;
    });

    puangCrying->setOnTimerCallback([&](TimerPtr timer)->bool {
        timer->stop();
        puangFail->setImage("Images/Puang/푸앙_절규.png");

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
        puangFail->setImage("Images/Stage/푸앙_운동.png");
        puangFail->locate(gameOverScene, 350, 50);
        gameOverPuangWeightDown->start();

        //puangFail->setImage("Images/Stage/푸앙_운동.png");
        //puangFail->locate(gameOverScene, 250, 250);
        // 실패하는 모션들 
        // 인벤토리 박스 삭제 필요, 
        return true;
    });
    gameOverPuangWeightUp->setOnTimerCallback([&](TimerPtr timer)->bool {
        if (puangWeightCnt < 4) {
            timer->stop();
            timer->set(1.f);
            puangFail->setImage("Images/Stage/푸앙_운동.png");
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
            puangFail->setImage("Images/Stage/푸앙_운동2.png");
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
    // 성공요소 
    gameClearScene = Scene::create("gameClearScene", "Images/Stage/clearBackground.PNG");
    gameClearTimer = Timer::create(2.f);
    // 
    // 
    // 왼쪽화면 
    // 냉장고 
    // 생선
    // 닭가슴살?
    // 그릇에다 주면 ㅇㅋ 
    // 직접주면 헬창 등장 
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
    facedGameOver = Timer::create(1.f); // 그냥 실패 절차중 하나임 
    puangFailMoving = Timer::create(1.f);
    puangCrying = Timer::create(1.f);
    gameOverPuangWeightUp = Timer::create(1.f);
    gameOverPuangWeightDown = Timer::create(1.f);
    puangWeightCnt = 0;
    puangFail = Object::create("Images/Puang/푸앙_뒷모습.png", roomLeftScene, 100, 50);
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

    // 실패 조건 
    chicken->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)->bool {
        //chicken->hide();
        puangFail->show();

        puangFailMoving->start();
        // 실패 조건 
        return true;
    });


    // 실패조건 추가할 것 
    puangFailMoving->setOnTimerCallback([&](TimerPtr timer)->bool {
        timer->stop();
        bigFish->setImage("Images/Stage/bigFishOpenV.png");
        bigFish->setScale(0.6f);
        puangCrying->start();
        return true;
    });

    puangCrying->setOnTimerCallback([&](TimerPtr timer)->bool {
        timer->stop();
        puangFail->setImage("Images/Puang/푸앙_절규.png");
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
        puangFail->setImage("Images/Stage/푸앙_운동.png");
        puangFail->locate(gameOverScene, 350, 50);
        gameOverPuangWeightDown->start();

        //puangFail->setImage("Images/Stage/푸앙_운동.png");
        //puangFail->locate(gameOverScene, 250, 250);
        // 실패하는 모션들 
        // 인벤토리 박스 삭제 필요, 
        return true;
    });
    gameOverPuangWeightUp->setOnTimerCallback([&](TimerPtr timer)->bool {
        if (puangWeightCnt < 4) {
            timer->stop();
            timer->set(1.f);
            puangFail->setImage("Images/Stage/푸앙_운동.png");
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
            puangFail->setImage("Images/Stage/푸앙_운동2.png");
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
        // 먹는 애니 추가 
        if (fish->isHanded()) {
            fish->drop();
            fish->hide();
            // 그릇위에 생성 
            // 새 접근 // 버거생김 
            // 새 먹음 
            puangGivingFish = Object::create("Images/Puang/푸앙_뒷모습.png", roomLeftScene, 130, 50);

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
        // 실패 조건2 
        if (fish->isHanded()) {
            puangFail->show();
            puangFail->locate(roomLeftScene, 600, 150);
            puangFail->setImage("Images/Puang/푸앙_뒷_손.png");
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
            // 숫자 추가 
            // 1탄을 계속 깨면 2,3,탄이깨지는문제 발생 
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




    // 오른쪽 화면 파리하나
    // 잡으면 사라지게 

    
    // 입닫은거 
    // 입벌린거 -> 헬창 
    // 새 먹는거
        

}

