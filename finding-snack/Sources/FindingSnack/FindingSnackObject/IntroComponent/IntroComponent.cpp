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

// 객체가 생성될때 변수 초기화 및 초기 셋팅등 생성자 역할을 하게 된다.
void IntroComponent::enter() {
    room = Scene::create("introScene", "Images/Stage/room.png");
    root->setIntroScene(room);

    chair = Object::create("Images/Stage/sofaFront.png", room, 200, 150);
    puang = Object::create("Images/Puang/푸앙_뒷모습.png", room, 560, 50);
    //door[0] = Object::create(Images/St)


};

// 객체가 삭제/제거될때 메모리 삭제 등 소멸자 역할을 하게 된다.
void IntroComponent::exit() {};


// 객체의 주 행동들을 작성하는 곳으로 특정 시간마다 변하는 애니메이션이나 타이밍을 체크 하며 다음과 같이 작성 할 수 있다.
void IntroComponent::update() {};

// 화면에 그려질 부분을 컨트롤 하는 부분이다. 랜더링을 담당한다.
void IntroComponent::draw() {};

// 사용자의 조작에 어떤 반응을 할것인지를 컨트롤 할 수 있는 부분이다.
void IntroComponent::event() {

};



// 만들어 놓은 함수들을 가지고 로직 수행
void IntroComponent::construct() {
    enter();

}