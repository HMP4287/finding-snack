#pragma once

//#include "SceneBuilder.h"
#include "FindingSnackTest.h"
// Director
class Builder
{
private:
    //FindingSnack* sceneBuilder;
    // ��� ������ ���⿡ 
    FindingSnack* findingSnackGame; 
    
    // �������ϵ� ������ ���ΰ� ? -> ������ �ѹ� ������ �������� ���� �������� �����ʿ�.
    // �Ǵ��� Ȯ�� �ʿ� .
    //MainMenuSceneBuilder m;

public:
    // �Ʒ��ڵ� ���� �ʿ� 
    Builder() : findingSnackGame(NULL) {}
    ~Builder() {}


    void setBuilder(FindingSnack* f) { findingSnackGame = f; }

    // 
    //ScenePtr getScene() { return sceneBuilder->getScene(); }





    // MainMenuSceneBuilder�� ������ Scene�� ������ ó���ϴ� �κ�. 
    // 
    //void constructScene() {
    //    // �ʱ�ȭ ���� 
    //    sceneBuilder->createNewSceneProduct();
    //    sceneBuilder->update();
    //    sceneBuilder->draw();
    //    sceneBuilder->update();
    //    sceneBuilder->event();

    //}
};
