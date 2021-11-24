#include <iostream>
//#include "FindingSnack/FindingSnack.h"

//#include "Test/Waiter.h" // 필수 
//#include "Test/HawaiianPizzaBuilder.h" // 필수 
//#include "Test/SpicyPizzaBuilder.h" // 필수 
//#include "Test/Pizza.h"
//#include "Test/PizzaBuilder.h"
//
//
//#include "FindingSnackTest/Builder.h"
//#include "FindingSnackTest/MainMenuSceneBuilder.h"
//#include "FindingSnackTest/FindingSnack.h"

//#include "FindingSnackLast/FindingSnackTest.h"

#include "FindingSnackLast/Builder.h"
#include "FindingSnackLast/MainMenuSceneBuilder.h"


int main()
{

    // 파일의 생성을 순서대로 생각해봤을 때 상속을 포기하거나, (MainMenu가 생성 할 때 FindingSnack은 컴퓨터에 아무런 정보가 없는 상태) 
    // 다른파일로 분리하는 것을 포기하던가. 
    // 따라서 -> 상속을 포기하고, 기존 목적인 객체지향적 설계에서 가독성을 위한 설계로 변경 
    // MainMenu 클래스와 findingSnack클래스에서 서로에게 접근할 수 있어야 하기 때문에 아래와 같이 설계. 
    // 더 나은 방안이 있을 수 있음 
    //FindingSnack findingSnackGame; 

    //Builder builder; 
    //MainMenuSceneBuilder mainMenuSceneBuilder;
    //builder.SetSceneBuilder(&mainMenuSceneBuilder);
    //builder.constructScene();
    ////ScenePtr main = builder.getScene();
    //findingSnackGame.setMainMenuScene(builder.getScene());
    //findingSnackGame.start();
    FindingSnack root;

    MainMenuSceneBuilder mainMenuSceneBuilder(&root); // 생성자에서 construct 실행 ?
    // Select. .  .. 같은것도 다 마찬가지. 

    root.start();
    


    //Builder builder; //root 만 박혀있는 상태 
    //builder.setBuilder(&root);


    //MainMenuSceneBuilder mainMenuSceneBuilder(&root);
    //builder.construct();

    // 빌더 생성시 findingSnack의 생성자를 한번 호출함 
    //builder.setBuilder();





    //Waiter waiter;
    //HawaiianPizzaBuilder hawaiianPizzaBuilder;
    //waiter.SetPizzaBuilder(&hawaiianPizzaBuilder);
    //waiter.ConstructPizza();

    //std::auto_ptr<Pizza> pizza = waiter.GetPizza();
    //pizza->ShowPizza();
    //SpicyPizzaBuilder spicyPizzaBuilder;
    //waiter.SetPizzaBuilder(&spicyPizzaBuilder);
    //waiter.ConstructPizza();
    //pizza = waiter.GetPizza();
    //pizza->ShowPizza();




    return 0; 
}
