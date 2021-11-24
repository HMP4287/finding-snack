#pragma once

//#include "SceneBuilder.h"
#include "FindingSnackTest.h"
// Director
class Builder
{
private:
    //FindingSnack* sceneBuilder;
    // 모든 데이터 여기에 
    FindingSnack* findingSnackGame; 
    
    // 빌더패턴들 저장할 것인가 ? -> 어차피 한번 생성한 다음에는 쓸모 없을듯함 검증필요.
    // 되는지 확인 필요 .
    //MainMenuSceneBuilder m;

public:
    // 아래코드 이해 필요 
    Builder() : findingSnackGame(NULL) {}
    ~Builder() {}


    void setBuilder(FindingSnack* f) { findingSnackGame = f; }

    // 
    //ScenePtr getScene() { return sceneBuilder->getScene(); }





    // MainMenuSceneBuilder로 구현한 Scene의 로직을 처리하는 부분. 
    // 
    //void constructScene() {
    //    // 초기화 진행 
    //    sceneBuilder->createNewSceneProduct();
    //    sceneBuilder->update();
    //    sceneBuilder->draw();
    //    sceneBuilder->update();
    //    sceneBuilder->event();

    //}
};
