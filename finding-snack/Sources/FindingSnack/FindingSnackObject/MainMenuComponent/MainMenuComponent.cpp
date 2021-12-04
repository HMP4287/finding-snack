#include "MainMenuComponent.h"

MainMenuComponent::MainMenuComponent(FindingSnackObject* r) {
    root = r;
    root->mainMenuComponent = this;
    //mainMenuComponent = this;
    construct();
}

MainMenuComponent::~MainMenuComponent() {};

// ��ü�� �����ɶ� ���� �ʱ�ȭ �� �ʱ� ���õ� ������ ������ �ϰ� �ȴ�.
void MainMenuComponent::enter() {
    // MainMenuScene �ʱ�ȭ 
    root->setMainMenuScene(Scene::create("MainMenuScene", "Images/Background/startScene.png"));
    // startBtn �ʱ�ȭ 
    root->setMainMenuStartBtn(Object::create("Images/Button/start.png", root->getMainMenuScene(), 560, 150));
    // gameInfoBtn �ʱ�ȭ 
    root->setGameInfoBtn(Object::create("Images/Button/explain.png", root->getMainMenuScene(), 560, 60));

    root->setGameInfo(Object::create("Images/Stage/explain1.PNG", root->getMainMenuScene(), 280, 55));
    root->setGameInfoOutBtn(Object::create("Images/Stage/closeBtn.PNG", root->getMainMenuScene(), 575, 65));
    root->getGameInfo()->hide();
    root->getGameInfoOutBtn()->hide();


    // ���ӿɼ��� Stage���� �� �� ���� 
    setGameOption(GameOption::GAME_OPTION_ROOM_TITLE, false);
    setGameOption(GameOption::GAME_OPTION_MESSAGE_BOX_BUTTON, false);
    setGameOption(GameOption::GAME_OPTION_INVENTORY_BUTTON, false);
    


};

// ��ü�� ����/���ŵɶ� �޸� ���� �� �Ҹ��� ������ �ϰ� �ȴ�.
void MainMenuComponent::exit() {};


// ��ü�� �� �ൿ���� �ۼ��ϴ� ������ Ư�� �ð����� ���ϴ� �ִϸ��̼��̳� Ÿ�̹��� üũ �ϸ� ������ ���� �ۼ� �� �� �ִ�.
void MainMenuComponent::update() {};

// ȭ�鿡 �׷��� �κ��� ��Ʈ�� �ϴ� �κ��̴�. �������� ����Ѵ�.
void MainMenuComponent::draw() {};

// ������� ���ۿ� � ������ �Ұ������� ��Ʈ�� �� �� �ִ� �κ��̴�.
void MainMenuComponent::event() {
    
    // startBtn �̺�Ʈ ���
    root->getMainMenuStartBtn()->setOnMouseCallback([&](auto, auto, auto, auto)->bool {

        // ���콺 Ŭ���ϸ� SelectStage ������ �Ѿ ����. 
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



// ����� ���� �Լ����� ������ ���� ����
void MainMenuComponent::construct() {
    enter();
    event();


}