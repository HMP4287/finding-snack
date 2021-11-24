#pragma once

#include "SceneBuilder.h"
// Director
class Builder
{
private:
    SceneBuilder* sceneBuilder;
public:
    // �Ʒ��ڵ� ���� �ʿ� 
    Builder() : sceneBuilder(NULL) {}
    ~Builder() { }


    void SetSceneBuilder(SceneBuilder* b) { sceneBuilder = b; }

    ScenePtr getScene() { return sceneBuilder->getScene(); }

    // MainMenuSceneBuilder�� ������ Scene�� ������ ó���ϴ� �κ�. 
    void constructScene() {
        // �ʱ�ȭ ���� 
        sceneBuilder->createNewSceneProduct();
        sceneBuilder->update();
        sceneBuilder->draw();
        sceneBuilder->update();
        sceneBuilder->event();

    }
};
