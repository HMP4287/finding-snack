#pragma once

#include "../FindingSnackObject.h"

class MainMenuComponent : public FindingSnackObject
{
public:
    FindingSnackObject* root;
   
    MainMenuComponent(FindingSnackObject* r);
    ~MainMenuComponent();

    void enter(); 
    void exit();
    void update();
    void draw();
    void event();

    void construct();
};
