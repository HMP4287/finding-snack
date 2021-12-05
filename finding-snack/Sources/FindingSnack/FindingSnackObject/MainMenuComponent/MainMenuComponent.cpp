#include "MainMenuComponent.h"

MainMenuComponent::MainMenuComponent(FindingSnackObject* r) {
    root = r;
    root->mainMenuComponent = this;
    construct();
}

MainMenuComponent::~MainMenuComponent() {};

void MainMenuComponent::enter() {
    root->setMainMenuScene(Scene::create("MainMenuScene", "Images/Background/startScene.png"));
    root->setMainMenuStartBtn(Object::create("Images/Button/start.png", root->getMainMenuScene(), 560, 150));
    root->setGameInfoBtn(Object::create("Images/Button/explain.png", root->getMainMenuScene(), 560, 60));

    root->setGameInfo(Object::create("Images/Stage/explain1.PNG", root->getMainMenuScene(), 280, 55));
    root->setGameInfoOutBtn(Object::create("Images/Stage/closeBtn.PNG", root->getMainMenuScene(), 575, 65));
    root->getGameInfo()->hide();
    root->getGameInfoOutBtn()->hide();

    setGameOption(GameOption::GAME_OPTION_ROOM_TITLE, false);
    setGameOption(GameOption::GAME_OPTION_MESSAGE_BOX_BUTTON, false);
    setGameOption(GameOption::GAME_OPTION_INVENTORY_BUTTON, false);
    


};

void MainMenuComponent::exit() {};
void MainMenuComponent::update() {};
void MainMenuComponent::draw() {};
void MainMenuComponent::event() {
    root->getMainMenuStartBtn()->setOnMouseCallback([&](auto, auto, auto, auto)->bool {

        root->getStageSelectScene()->enter();


		return true;
	});


    root->getGameInfoBtn()->setOnMouseCallback([&](auto, auto, auto, auto)->bool {

        root->getGameInfo()->show();
        root->getGameInfoOutBtn()->show();

        return true;
    });
    root->getGameInfoOutBtn()->setOnMouseCallback([&](auto, auto, auto, auto)->bool {
        
        root->getGameInfo()->hide();
        root->getGameInfoOutBtn()->hide();
        return true;
    });



};



void MainMenuComponent::construct() {
    enter();
    event();


}