#include "IntroComponent.h"

IntroComponent::IntroComponent(FindingSnackObject* r) {
    root = r;
    root->introComponent = this;
    construct();
}

IntroComponent::~IntroComponent() {};

// ��ü�� �����ɶ� ���� �ʱ�ȭ �� �ʱ� ���õ� ������ ������ �ϰ� �ȴ�.
void IntroComponent::enter() {

    root->setIntroScene(Scene::create("introSceneStart", "Images/Background/background.PNG"));
    clickToStart = Object::create("Images/Button/start.png", root->getIntroScene(), 560, 150);

    room = Scene::create("introScene", "Images/Stage/room.png");
    chair = Object::create("Images/Stage/sofaFront.png", room, 200, 150);
    puang = Object::create("Images/Puang/Ǫ��_�޸��.png", room, 560, 50);

    door = Object::create("Images/Stage/doorClose.png", room, 920, 170);


    changePuangLove = Timer::create(2.f);
    chagePuangCauBurger = Timer::create(2.f);
    goToMainMenuScene = Timer::create(2.f);
    trainerIn = Timer::create(2.f);
    trainerOut = Timer::create(2.f);

};

// ��ü�� ����/���ŵɶ� �޸� ���� �� �Ҹ��� ������ �ϰ� �ȴ�.
void IntroComponent::exit() {};


// ��ü�� �� �ൿ���� �ۼ��ϴ� ������ Ư�� �ð����� ���ϴ� �ִϸ��̼��̳� Ÿ�̹��� üũ �ϸ� ������ ���� �ۼ� �� �� �ִ�.
void IntroComponent::update() {
    clickToStart->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)->bool {
        room->enter();
        changePuangLove->start();
        return true;
    });

    changePuangLove->setOnTimerCallback([&](TimerPtr timer)->bool {
        puang->setImage("Images/Puang/Ǫ��_���.png");
  
        timer->stop();
        chagePuangCauBurger->start();
        return true;
    });

    chagePuangCauBurger->setOnTimerCallback([&](TimerPtr timer)->bool {
        puang->setImage("Images/Puang/Ǫ��_ī�����.png");
        //door->locate(room, 820, 145);
        timer->stop();
        trainerIn->start();
        //goToMainMenuScene->start();
        return true;
    });

    trainerIn->setOnTimerCallback([&](TimerPtr timer)->bool {
        door->locate(room, 820, 145);
        door->setImage("Images/Stage/doorOpenTrainer.png");
        timer->stop();
        trainerOut->start();
        //goToMainMenuScene->start();
        return true;
    });
    trainerOut->setOnTimerCallback([&](TimerPtr timer)->bool {
        door->locate(room, 920, 170);
        door->setImage("Images/Stage/doorClose.png");
        goToMainMenuScene->start();
        timer->stop();
        return true; 
    });





    goToMainMenuScene->setOnTimerCallback([&](TimerPtr timer)->bool {
        
        timer->stop();
        root->getMainMenuScene()->enter();
        
        return true;
    });

};

// ȭ�鿡 �׷��� �κ��� ��Ʈ�� �ϴ� �κ��̴�. �������� ����Ѵ�.
void IntroComponent::draw() {};

// ������� ���ۿ� � ������ �Ұ������� ��Ʈ�� �� �� �ִ� �κ��̴�.
void IntroComponent::event() {

};



// ����� ���� �Լ����� ������ ���� ����
void IntroComponent::construct() {
    enter();
    update();

}