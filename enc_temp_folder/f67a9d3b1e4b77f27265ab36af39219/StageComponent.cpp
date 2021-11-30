#include "StageComponent.h"

StageComponent::StageComponent(FindingSnackObject* r) {
    root = r;
    root->stageComponent = this;
    //construct();
}

StageComponent::~StageComponent() {};

// 객체가 생성될때 변수 초기화 및 초기 셋팅등 생성자 역할을 하게 된다.
void StageComponent::enter() {
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
        root->getMainMenuScene()->enter();
        return true;
    });
    goBackMainMenuBtnR->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)->bool {
        // 초기화가 되었을지 ? 그리고 이 클래스의 엔터가 실행될지 ? 
        setGameOption(GameOption::GAME_OPTION_INVENTORY_BUTTON, false);
        root->getMainMenuScene()->enter();
        return true;
    });
};

// 만들어 놓은 함수들을 가지고 로직 수행
void StageComponent::construct() {

}

void StageComponent::makeStage(int stageNum) {
    if (stageNum == 1)
        makeStage1();
    else if (stageNum == 2)
        makeStage2();
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


    wallClosetGameOver = Timer::create(1.f);

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
        wallClosetGameOver->start();
        return true;
    });

    wallClosetGameOver->setOnTimerCallback([&](TimerPtr timer)->bool {
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

    gymMan = Object::create("Images/Trainer/trainer.png", roomLeftScene, 880, 150);
    closet = Object::create("Images/Stage/closetClose.png", roomLeftScene, 200, 150);
    windowLeft = Object::create("Images/Stage/curtainClose.png", roomLeftScene, 720, 400); // x = 177, (닫혀있을때는 겹치게 보이려면 좀더 가까이 ) 
    windowRight = Object::create("Images/Stage/curtainClose.png", roomLeftScene, 880, 400); // -17

    sofa = Object::create("Images/Stage/sofaFront.png", roomLeftScene, 620, 150);

  

    // 화분, 벽, 서랍 
    wallCloset = Object::create("Images/Stage/wallclosetBitjaru.PNG", roomRightScene, 250, 250);

}
