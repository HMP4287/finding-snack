#include "IntroComponent.h"

IntroComponent::IntroComponent(FindingSnackObject* r) {
    root = r;
    root->introComponent = this;
    construct();
}

IntroComponent::~IntroComponent() {};

void IntroComponent::enter() {

    root->setIntroScene(Scene::create("introSceneStart", "Images/Background/background.PNG"));
    clickToStart = Object::create("Images/Button/start.png", root->getIntroScene(), 560, 150);

    room = Scene::create("introScene", "Images/Stage/room.png");
    chair = Object::create("Images/Stage/sofaFront.png", room, 200, 150);
    puang = Object::create("Images/Puang/Çª¾Ó_µÞ¸ð½À.png", room, 560, 50);

    door = Object::create("Images/Stage/doorClose.png", room, 920, 170);


    changePuangLove = Timer::create(3.f);
    chagePuangCauBurger = Timer::create(3.f);
    goToMainMenuScene = Timer::create(3.f);
    trainerIn = Timer::create(3.f);
    trainerOut = Timer::create(3.f);

};

void IntroComponent::exit() {};


void IntroComponent::update() {
    clickToStart->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)->bool {
        room->enter();
        changePuangLove->start();
        
        return true;
    });

    changePuangLove->setOnTimerCallback([&](TimerPtr timer)->bool {
        puang->setImage("Images/Puang/Çª¾Ó_»ç¶û.png");
  
        timer->stop();
        chagePuangCauBurger->start();
        return true;
    });

    chagePuangCauBurger->setOnTimerCallback([&](TimerPtr timer)->bool {
        puang->setImage("Images/Puang/Çª¾Ó_Ä«¿ì¹ö°Å.png");
        timer->stop();
        trainerIn->start();
        return true;
    });

    trainerIn->setOnTimerCallback([&](TimerPtr timer)->bool {
        door->locate(room, 820, 145);
        door->setImage("Images/Stage/doorOpenTrainer.png");
        timer->stop();
        trainerOut->start();
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

void IntroComponent::draw() {};
void IntroComponent::event() {};

void IntroComponent::construct() {
    enter();
    update();

}