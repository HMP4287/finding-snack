#pragma once

#include "SceneBuilder.h"
// Director
class Builder
{
private:
    SceneBuilder* sceneBuilder;
public:
    // 아래코드 이해 필요 
    Builder() : sceneBuilder(NULL) {}
    ~Builder() { }


    void SetSceneBuilder(SceneBuilder* b) { sceneBuilder = b; }

    ScenePtr getScene() { return sceneBuilder->getScene(); }

    // MainMenuSceneBuilder로 구현한 Scene의 로직을 처리하는 부분. 
    void constructScene() {
        // 초기화 진행 
        sceneBuilder->createNewSceneProduct();
        sceneBuilder->update();
        sceneBuilder->draw();
        sceneBuilder->update();
        sceneBuilder->event();

    }
};
