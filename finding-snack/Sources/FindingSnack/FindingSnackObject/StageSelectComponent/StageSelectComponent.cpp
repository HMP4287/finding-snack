#include "StageSelectComponent.h"

StageSelectComponent::StageSelectComponent(FindingSnackObject* r) {
    root = r;
    root->stageSelectComponent = this;
    construct();

}

StageSelectComponent::~StageSelectComponent() {};

// ��ü�� �����ɶ� ���� �ʱ�ȭ �� �ʱ� ���õ� ������ ������ �ϰ� �ȴ�.
void StageSelectComponent::enter() {

    root->setStageSelectScene(Scene::create("StageSelectScene", "Images/Background/stageSelection.png"));
    // stageSelectBtn �ʱ�ȭ 
    for (int i = 0; i < STAGE_MAX; i++) {
        root->setClearStage(false, i);

        sprintf(unclearNumImgPath[i], "Images/Button/unclearNumbers/%d.PNG", i + 1);
        sprintf(clearNumImgPath[i], "Images/Button/clearNumbers/%d.PNG", i + 1);
        root->setStagesBtns(Object::create(unclearNumImgPath[i], root->getStageSelectScene(), 100 + 200 * (i % 5), 400 - 200 * (i / 5)), i);
    }
    // stgae1�� Ŭ�������ϰ� ������� ���� 
    root->setClearStage(true, 0);

    // MainMenu�� �̵��ϴ� ��ư �ʱ�ȭ 
    root->setMainMenuBtn(Object::create("Images/Button/home.png", root->getStageSelectScene(), 1160, 610));
    // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!���� �����ؾ��� (1�� �����Ұ�)
    root->setCurrentStage(1);
    root->setClickedStage(0);

    
};

// ��ü�� ����/���ŵɶ� �޸� ���� �� �Ҹ��� ������ �ϰ� �ȴ�.
void StageSelectComponent::exit() {};


// ��ü�� �� �ൿ���� �ۼ��ϴ� ������ Ư�� �ð����� ���ϴ� �ִϸ��̼��̳� Ÿ�̹��� üũ �ϸ� ������ ���� �ۼ� �� �� �ִ�.
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

// ȭ�鿡 �׷��� �κ��� ��Ʈ�� �ϴ� �κ��̴�. �������� ����Ѵ�.
void StageSelectComponent::draw() {};

// ������� ���ۿ� � ������ �Ұ������� ��Ʈ�� �� �� �ִ� �κ��̴�.
void StageSelectComponent::event() {

    // stageSelectBtn 
    for (int i = 0; i < STAGE_MAX; i++) {
        root->getStagesBtns(i)->setOnMouseCallback([&, i](auto, auto, auto, auto)->bool {

            if (i < root->getCurrentStage()) {
                // stage ���� �� �ʱ�ȭ. 
                root->setClickedStage(i+1);

                root->stageComponent->enter();


                // stage �����ϱ� 
                root->getStage()->enter();
                return true;

            }
            return false;
        });
    }



    // MainMenu�� �̵��ϴ� ��ư �ʱ�ȭ 
    root->getMainMenuBtn()->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)->bool {
        root->getMainMenuScene()->enter();
        return true;
    });
    

};



// ����� ���� �Լ����� ������ ���� ����
void StageSelectComponent::construct() {
    enter();
    update();
    event();
}