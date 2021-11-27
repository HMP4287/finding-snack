#include "IntroComponent.h"

IntroComponent::IntroComponent(FindingSnackObject* r) {
    root = r;
    root->introComponent = this;
    construct();

    //ScenePtr room;
    //ObjectPtr chair;
    //ObjectPtr door[2]; // close open
    //ScenePtr nextDay;
    //ObjectPtr thinkingPuang;
    //ObjectPtr nowhere;
    //ObjectPtr puangFinding;
    //ObjectPtr myBurgerIsLost;
}

IntroComponent::~IntroComponent() {};

// ��ü�� �����ɶ� ���� �ʱ�ȭ �� �ʱ� ���õ� ������ ������ �ϰ� �ȴ�.
void IntroComponent::enter() {
    room = Scene::create("introScene", "Images/Stage/room.png");
    root->setIntroScene(room);

    chair = Object::create("Images/Stage/sofaFront.png", room, 200, 150);
    puang = Object::create("Images/Puang/Ǫ��_�޸��.png", room, 560, 50);
    //door[0] = Object::create(Images/St)


};

// ��ü�� ����/���ŵɶ� �޸� ���� �� �Ҹ��� ������ �ϰ� �ȴ�.
void IntroComponent::exit() {};


// ��ü�� �� �ൿ���� �ۼ��ϴ� ������ Ư�� �ð����� ���ϴ� �ִϸ��̼��̳� Ÿ�̹��� üũ �ϸ� ������ ���� �ۼ� �� �� �ִ�.
void IntroComponent::update() {};

// ȭ�鿡 �׷��� �κ��� ��Ʈ�� �ϴ� �κ��̴�. �������� ����Ѵ�.
void IntroComponent::draw() {};

// ������� ���ۿ� � ������ �Ұ������� ��Ʈ�� �� �� �ִ� �κ��̴�.
void IntroComponent::event() {

};



// ����� ���� �Լ����� ������ ���� ����
void IntroComponent::construct() {
    enter();

}