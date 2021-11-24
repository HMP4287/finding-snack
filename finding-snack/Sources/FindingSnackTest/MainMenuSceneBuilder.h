#pragma once


#include "SceneBuilder.h"

//#include "FindingSnackBuilder.h"


// ConcreteBuilder
class MainMenuSceneBuilder : public SceneBuilder 
{
public:
    // �Ʒ� �ڵ� ��Ȯ�� ���� X 
    MainMenuSceneBuilder() : SceneBuilder() {}
    ~MainMenuSceneBuilder() {}

    // �Ʒ� �ڵ�� ���� �� ������ ���Ƿ� �ۼ��� ������
    // ������ ������� ���Ӽ��� ����Ʈ ���� �ٽ� ������ ���� ������ �� 
    void enter() { mainMenuScene->enter(); };
    void exit() { mainMenuScene->onLeave(); };
    void update() { printf("updates actions animations movements \n"); };
    void draw() { printf("draws \n"); }
    void event() { printf("event call backs \n"); };

 /*   void buildDough() { pizza->SetDough("cross"); }
    void buildSauce() { pizza->SetSauce("mild"); }
    void buildTopping() { pizza->SetTopping("ham and pineapple"); }*/

};
