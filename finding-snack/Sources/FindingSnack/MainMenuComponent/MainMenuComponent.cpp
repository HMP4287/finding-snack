#include "MainMenuComponent.h"

MainMenuComponent::MainMenuComponent(FindingSnack* r) {
    root = r;
    construct();
}

MainMenuComponent::~MainMenuComponent() {};

// 객체가 생성될때 변수 초기화 및 초기 셋팅등 생성자 역할을 하게 된다.
void MainMenuComponent::enter() {
    // MainMenuScene 초기화 
    root->setMainMenuScene(Scene::create("MainMenuScene", "Images/Background/startScene.png"));
    // startBtn 초기화 
    root->setMainMenuStartBtn(Object::create("Images/Button/startBtn.png", root->getMainMenuScene(), 430, 100));

    
};

// 객체가 삭제/제거될때 메모리 삭제 등 소멸자 역할을 하게 된다.
void MainMenuComponent::exit() {};


// 객체의 주 행동들을 작성하는 곳으로 특정 시간마다 변하는 애니메이션이나 타이밍을 체크 하며 다음과 같이 작성 할 수 있다.
void MainMenuComponent::update() {};

// 화면에 그려질 부분을 컨트롤 하는 부분이다. 랜더링을 담당한다.
void MainMenuComponent::draw() {};

// 사용자의 조작에 어떤 반응을 할것인지를 컨트롤 할 수 있는 부분이다.
void MainMenuComponent::event() {
    
    // startBtn 이벤트 등록
    root->getMainMenuStartBtn()->setOnMouseCallback([&](auto, auto, auto, auto)->bool {

        // 마우스 클릭하면 SelectStage 씬으로 넘어갈 것임. 
        //stageSelectScene enter();
		return true;
	});




};



// 만들어 놓은 함수들을 가지고 로직 수행
void MainMenuComponent::construct() {
    enter();

}