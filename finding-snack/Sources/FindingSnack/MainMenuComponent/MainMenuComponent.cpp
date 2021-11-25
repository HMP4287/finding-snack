#include "MainMenuComponent.h"

MainMenuComponent::MainMenuComponent(FindingSnack* r) {
    root = r;
    construct();
}

MainMenuComponent::~MainMenuComponent() {};

// ��ü�� �����ɶ� ���� �ʱ�ȭ �� �ʱ� ���õ� ������ ������ �ϰ� �ȴ�.
void MainMenuComponent::enter() {
    // MainMenuScene �ʱ�ȭ 
    root->setMainMenuScene(Scene::create("MainMenuScene", "Images/Background/startScene.png"));
    // startBtn �ʱ�ȭ 
    root->setMainMenuStartBtn(Object::create("Images/Button/startBtn.png", root->getMainMenuScene(), 430, 100));

    
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
        //stageSelectScene enter();
		return true;
	});




};



// ����� ���� �Լ����� ������ ���� ����
void MainMenuComponent::construct() {
    enter();

}