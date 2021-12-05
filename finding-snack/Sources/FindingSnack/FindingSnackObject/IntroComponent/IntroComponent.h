#pragma once
#include "../FindingSnackObject.h"

class IntroComponent : public FindingSnackObject
{
public:
    FindingSnackObject* root;

    ObjectPtr clickToStart;

    ScenePtr room;
    ObjectPtr puang;
    ObjectPtr chair;
    ObjectPtr door; 
    TimerPtr changePuangLove;
    TimerPtr chagePuangCauBurger;
    TimerPtr goToMainMenuScene;
    TimerPtr trainerIn;
    TimerPtr trainerOut;



    IntroComponent(FindingSnackObject* r);
    ~IntroComponent();

    void enter();
    void exit();
    void update();
    void draw();
    void event();
    void construct();
};

