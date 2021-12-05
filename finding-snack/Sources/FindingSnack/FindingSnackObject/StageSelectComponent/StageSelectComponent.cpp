#include "StageSelectComponent.h"

StageSelectComponent::StageSelectComponent(FindingSnackObject* r) {
    root = r;
    root->stageSelectComponent = this;
    construct();

}

StageSelectComponent::~StageSelectComponent() {};

void StageSelectComponent::enter() {
    root->setStageSelectScene(Scene::create("StageSelectScene", "Images/Background/stageSelection.png"));
    for (int i = 0; i < STAGE_MAX; i++) {
        root->setClearStage(false, i);
        sprintf(unclearNumImgPath[i], "Images/Button/unclearNumbers/%d.PNG", i + 1);
        sprintf(clearNumImgPath[i], "Images/Button/clearNumbers/%d.PNG", i + 1);
        root->setStagesBtns(Object::create(unclearNumImgPath[i], root->getStageSelectScene(), 100 + 200 * (i % 5), 400 - 200 * (i / 5)), i);
    }
    root->setClearStage(true, 0);
    root->setMainMenuBtn(Object::create("Images/Button/home.png", root->getStageSelectScene(), 1160, 610));
    root->setCurrentStage(1);
    root->setClickedStage(0);
};

void StageSelectComponent::exit() {};
void StageSelectComponent::update() {
    for (int i = 0; i < STAGE_MAX; i++) {
        if (root->getCurrentStage() > i) {
            root->getStagesBtns(i)->setImage(clearNumImgPath[i]);
        }
    }
};
void StageSelectComponent::draw() {};
void StageSelectComponent::event() {
    for (int i = 0; i < STAGE_MAX; i++) {
        root->getStagesBtns(i)->setOnMouseCallback([&, i](auto, auto, auto, auto)->bool {
            if (i < root->getCurrentStage()) {
                root->setClickedStage(i+1);
                root->stageComponent->enter();
                root->getStage()->enter();
                return true;
            }
            return false;
        });
    }
    root->getMainMenuBtn()->setOnMouseCallback([&](auto obj, auto x, auto y, auto action)->bool {
        root->getMainMenuScene()->enter();
        return true;
    });
};

void StageSelectComponent::construct() {
    enter();
    update();
    event();
}