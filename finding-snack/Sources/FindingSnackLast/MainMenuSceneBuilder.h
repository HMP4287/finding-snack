#pragma once


//#include "SceneBuilder.h"
#include "FindingSnackTest.h"

// 상속은 자원 공유위함 
// root 사용은 최상위 자원을 확실하게 사용하기 위함 
// ConcreteBuilder
class MainMenuSceneBuilder : public FindingSnack
{
public:
    FindingSnack* r; 
    // 아래 코드 정확히 이해 X 
    // 상위 클래스 생성자 호출 필요? ?  X 이미 빌더에서 고유한 하나의 fidningsnack 이 만들어져있을 것.
    //MainMenuSceneBuilder() : FindingSnack() {}
    MainMenuSceneBuilder() {} 
    MainMenuSceneBuilder(FindingSnack* rt) { 
        r = rt; 

        construct();
    }
    ~MainMenuSceneBuilder() {}


    // 아래 코드는 구현 부 내용은 임의로 작성한 예시임
    // 저번에 적어놓은 게임설계 사이트 보고 다시 각각의 역할 정의할 것 
    // private 이기 때문일듯 

    void enter() { r->getMainMenuScene()->enter(); };

    void exit() { r->getMainMenuScene()->onLeave(); };
    void update() { printf("updates actions animations movements \n"); };
    void draw() { printf("draws \n"); }
    void event() { printf("event call backs \n"); };

    // 만들어 놓은 함수들을 가지고 로직 수행
    void construct() {
        r->createNewSceneProduct();
        //enter();
        update();
        draw();
        event();
        // 초기화 진행 
        //sceneBuilder->createNewSceneProduct();
        //sceneBuilder->update();
        //sceneBuilder->draw();
        //sceneBuilder->update();
        //sceneBuilder->event();
        temp = 18; 
        stageSelectScene = NULL;
    }
 /*   void buildDough() { pizza->SetDough("cross"); }
    void buildSauce() { pizza->SetSauce("mild"); }
    void buildTopping() { pizza->SetTopping("ham and pineapple"); }*/
};
