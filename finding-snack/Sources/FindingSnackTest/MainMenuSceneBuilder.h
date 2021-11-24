#pragma once


#include "SceneBuilder.h"

//#include "FindingSnackBuilder.h"


// ConcreteBuilder
class MainMenuSceneBuilder : public SceneBuilder 
{
public:
    // 아래 코드 정확히 이해 X 
    MainMenuSceneBuilder() : SceneBuilder() {}
    ~MainMenuSceneBuilder() {}

    // 아래 코드는 구현 부 내용은 임의로 작성한 예시임
    // 저번에 적어놓은 게임설계 사이트 보고 다시 각각의 역할 정의할 것 
    void enter() { mainMenuScene->enter(); };
    void exit() { mainMenuScene->onLeave(); };
    void update() { printf("updates actions animations movements \n"); };
    void draw() { printf("draws \n"); }
    void event() { printf("event call backs \n"); };

 /*   void buildDough() { pizza->SetDough("cross"); }
    void buildSauce() { pizza->SetSauce("mild"); }
    void buildTopping() { pizza->SetTopping("ham and pineapple"); }*/

};
