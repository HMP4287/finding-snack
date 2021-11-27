#include "StageComponent.h"

StageComponent::StageComponent(FindingSnackObject* r) {
    root = r;
    root->stageComponent = this;
    //construct();
}

StageComponent::~StageComponent() {};

// ��ü�� �����ɶ� ���� �ʱ�ȭ �� �ʱ� ���õ� ������ ������ �ϰ� �ȴ�.
void StageComponent::enter() {

    makeStage(root->getCurrentStage());
    // ���ӿɼ��� Stage���� �� �� ���� 
    setGameOption(GameOption::GAME_OPTION_ROOM_TITLE, true);
    setGameOption(GameOption::GAME_OPTION_MESSAGE_BOX_BUTTON, true);
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

};

// ����� ���� �Լ����� ������ ���� ����
void StageComponent::construct() {

}

void StageComponent::makeStage(int stageNum) {
    if (stageNum == 1)
        makeStage1();
}

void StageComponent::makeStage1() {
    // enter
    room = Scene::create("room", "Images/Stage/room.PNG");
    root->setStage(room);
    





}

