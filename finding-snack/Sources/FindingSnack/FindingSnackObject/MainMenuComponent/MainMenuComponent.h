#pragma once

#include "../FindingSnackObject.h"

// ����� �ڿ� �������� 
// root ����� �ֻ��� �ڿ��� Ȯ���ϰ� ����ϱ� ���� 

// ConcreteBuilder
class MainMenuComponent : public FindingSnackObject
{
public:
    FindingSnackObject* root;
   
    MainMenuComponent(FindingSnackObject* r);
    ~MainMenuComponent();

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
