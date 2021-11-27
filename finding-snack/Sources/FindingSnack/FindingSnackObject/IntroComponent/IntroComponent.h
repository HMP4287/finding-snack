#pragma once
#include "../FindingSnackObject.h"

// Component
class IntroComponent : public FindingSnackObject
{
public:
    FindingSnackObject* root;

    ScenePtr room;
    ObjectPtr puang;
    ObjectPtr chair;
    ObjectPtr door[2]; // close open
    ScenePtr nextDay;
    ObjectPtr thinkingPuang;
    ObjectPtr nowhere;
    ObjectPtr puangFinding;
    ObjectPtr myBurgerIsLost;


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

