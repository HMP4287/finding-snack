#include "FindingSnack/FindingSnackObject/FindingSnackObject.h"
// FindingSnack을 개발하기 위해서 필요한 Components 들 (부품)
#include "FindingSnack/FindingSnackObject/MainMenuComponent/MainMenuComponent.h"
#include "FindingSnack/FindingSnackObject/StageSelectComponent/StageSelectComponent.h"
#include "FindingSnack/FindingSnackObject/StageComponent/StageComponent.h"
#include "FindingSnack/FindingSnackObject/IntroComponent/IntroComponent.h"

int main()
{

    FindingSnackObject findingSnackGame;

    IntroComponent introComponent(&findingSnackGame);
    MainMenuComponent mainMenuComponent(&findingSnackGame);
    StageSelectComponent stageSelectComponent(&findingSnackGame);
    StageComponent stageComponent(&findingSnackGame);

    findingSnackGame.start();
    
    return 0; 
}
