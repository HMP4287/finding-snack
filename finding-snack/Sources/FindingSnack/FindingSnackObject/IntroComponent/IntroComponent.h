#pragma once
#include "../FindingSnackObject.h"

// Component
class IntroComponent : public FindingSnackObject
{
public:
    FindingSnackObject* root;

    ObjectPtr clickToStart;

    ScenePtr room;
    ObjectPtr puang;
    ObjectPtr chair;
    ObjectPtr door; // close open
    TimerPtr changePuangLove;
    TimerPtr chagePuangCauBurger;
    TimerPtr goToMainMenuScene;
    TimerPtr trainerIn;
    TimerPtr trainerOut;



    IntroComponent(FindingSnackObject* r);
    ~IntroComponent();

    // ��ü�� �����ɶ� ���� �ʱ�ȭ �� �ʱ� ���õ� ������ ������ �ϰ� �ȴ�.
    void enter();

    // ��ü�� ����/���ŵɶ� �޸� ���� �� �Ҹ��� ������ �ϰ� �ȴ�.
    void exit();

    // ��ü�� �� �ൿ���� �ۼ��ϴ� ������ Ư�� �ð����� ���ϴ� �ִϸ��̼��̳� Ÿ�̹��� üũ �ϸ� ������ ���� �ۼ� �� �� �ִ�.
    void update();

    // ȭ�鿡 �׷��� �κ��� ��Ʈ�� �ϴ� �κ��̴�. �������� ����Ѵ�.
    void draw();

    // ������� ���ۿ� ������� �Ұ������� ��Ʈ�� �� �� �ִ� �κ��̴�.
    void event();


    // ����� ���� �Լ����� ������ ���� ����
    void construct();
};

