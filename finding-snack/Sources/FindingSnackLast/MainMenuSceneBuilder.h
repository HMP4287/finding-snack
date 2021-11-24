#pragma once


//#include "SceneBuilder.h"
#include "FindingSnackTest.h"

// ����� �ڿ� �������� 
// root ����� �ֻ��� �ڿ��� Ȯ���ϰ� ����ϱ� ���� 
// ConcreteBuilder
class MainMenuSceneBuilder : public FindingSnack
{
public:
    FindingSnack* r; 
    // �Ʒ� �ڵ� ��Ȯ�� ���� X 
    // ���� Ŭ���� ������ ȣ�� �ʿ�? ?  X �̹� �������� ������ �ϳ��� fidningsnack �� ����������� ��.
    //MainMenuSceneBuilder() : FindingSnack() {}
    MainMenuSceneBuilder() {} 
    MainMenuSceneBuilder(FindingSnack* rt) { 
        r = rt; 

        construct();
    }
    ~MainMenuSceneBuilder() {}


    // �Ʒ� �ڵ�� ���� �� ������ ���Ƿ� �ۼ��� ������
    // ������ ������� ���Ӽ��� ����Ʈ ���� �ٽ� ������ ���� ������ �� 
    // private �̱� �����ϵ� 

    void enter() { r->getMainMenuScene()->enter(); };

    void exit() { r->getMainMenuScene()->onLeave(); };
    void update() { printf("updates actions animations movements \n"); };
    void draw() { printf("draws \n"); }
    void event() { printf("event call backs \n"); };

    // ����� ���� �Լ����� ������ ���� ����
    void construct() {
        r->createNewSceneProduct();
        //enter();
        update();
        draw();
        event();
        // �ʱ�ȭ ���� 
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
