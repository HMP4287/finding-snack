#pragma once
#include "../FindingSnackObject.h"

class StageSelectComponent : public FindingSnackObject
{
public:
    FindingSnackObject* root;

    StageSelectComponent(FindingSnackObject* r);
    ~StageSelectComponent();

    void enter();
    void exit();
    void update();
    void draw();
    void event();
    void construct();
};

