#pragma once
#include "../FindingSnackObject.h"

// Component
class StageComponent : public FindingSnackObject
{
public:
    FindingSnackObject* root;

    // Stage elements
    // �������� ���Խ� ���� ó��ȭ�� room == stageScene
    ScenePtr room;
    ScenePtr roomSide;
    
    ObjectPtr window[4]; // �¿� ������, �� ������, �쿭����, �ٿ����� // â�������͵� �߰��ؾ��� ������ 


    StageComponent(FindingSnackObject* r);
    ~StageComponent();

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

    
    void makeStage(int stageNum);


    void makeStage1();

};

