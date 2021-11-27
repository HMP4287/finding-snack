#include "StageComponent.h"

StageComponent::StageComponent(FindingSnackObject* r) {
    root = r;
    root->stageComponent = this;
    //construct();
}

StageComponent::~StageComponent() {};

// 객체가 생성될때 변수 초기화 및 초기 셋팅등 생성자 역할을 하게 된다.
void StageComponent::enter() {

    makeStage(root->getCurrentStage());
    // 게임옵션은 Stage진입 시 재 등장 
    setGameOption(GameOption::GAME_OPTION_ROOM_TITLE, true);
    setGameOption(GameOption::GAME_OPTION_MESSAGE_BOX_BUTTON, true);
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

};

// 만들어 놓은 함수들을 가지고 로직 수행
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

