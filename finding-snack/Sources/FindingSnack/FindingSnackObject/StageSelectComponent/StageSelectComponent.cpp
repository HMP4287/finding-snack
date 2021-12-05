#include "StageSelectComponent.h"

StageSelectComponent::StageSelectComponent(FindingSnackObject* r) {
    root = r;
    root->stageSelectComponent = this;
    construct();

}

StageSelectComponent::~StageSelectComponent() {};

// 객체가 생성될때 변수 초기화 및 초기 셋팅등 생성자 역할을 하게 된다.
void StageSelectComponent::enter() {

    root->setStageSelectScene(Scene::create("StageSelectScene", "Images/Background/stageSelection.png"));
    // stageSelectBtn 초기화 
    for (int i = 0; i < STAGE_MAX; i++) {
        root->setClearStage(false, i);

        sprintf(unclearNumImgPath[i], "Images/Button/unclearNumbers/%d.PNG", i + 1);
        sprintf(clearNumImgPath[i], "Images/Button/clearNumbers/%d.PNG", i + 1);
        root->setStagesBtns(Object::create(unclearNumImgPath[i], root->getStageSelectScene(), 100 + 200 * (i % 5), 400 - 200 * (i / 5)), i);
    }
    // stgae1은 클릭가능하게 열어놓기 위함 
    root->setClearStage(true, 0);

    // MainMenu로 이동하는 버튼 초기화 
    root->setMainMenuBtn(Object::create("Images/Button/home.png", root->getStageSelectScene(), 1160, 610));
    // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!추후 수정해야함 (1로 수정할것)
    root->setCurrentStage(1);
    root->setClickedStage(0);

    
};

// 객체가 삭제/제거될때 메모리 삭제 등 소멸자 역할을 하게 된다.
void StageSelectComponent::exit() {};


// 객체의 주 행동들을 작성하는 곳으로 특정 시간마다 변하는 애니메이션이나 타이밍을 체크 하며 다음과 같이 작성 할 수 있다.
void StageSelectComponent::update() {
    for (int i = 0; i < STAGE_MAX; i++) {
        if (root->getCurrentStage() > i) {
            root->getStagesBtns(i)->setImage(clearNumImgPath[i]);
        }
   //     if (root->getClearStage(i)) {
			//root->getStagesBtns(i)->setImage(clearNumImgPath[i]);
   //     }
    }
};

// 화면에 그려질 부분을 컨트롤 하는 부분이다. 랜더링을 담당한다.
void StageSelectComponent::draw() {};

// 사용자의 조작에 어떤 반응을 할것인지를 컨트롤 할 수 있는 부분이다.
void StageSelectComponent::event() {

    // stageSelectBtn 
    for (int i = 0; i < STAGE_MAX; i++) {
        root->getStagesBtns(i)->setOnMouseCallback([&, i](auto, auto, auto, auto)->bool {

            if (i < root->getCurrentStage()) {
                // stage 진입 전 초기화. 
                root->setClickedStage(i+1);

                root->stageComponent->enter();


                // stage 진입하기 
                root->getStage()->enter();
                return true;

            }
            return false;
        });
    }



    // MainMenu로 이동하는 버튼 초기화 
    root->getMainMenuBtn()->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)->bool {
        root->getMainMenuScene()->enter();
        return true;
    });
    

};



// 만들어 놓은 함수들을 가지고 로직 수행
void StageSelectComponent::construct() {
    enter();
    update();
    event();
}