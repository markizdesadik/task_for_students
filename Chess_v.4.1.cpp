#include <iostream>
#include <cstdlib>
#include <iomanip>

const int SIZE_DECK=6;

int HorseStep_X[8] = {  2,  1, -1, -2, -2, -1,  1,  2};
int HorseStep_Y[8] = { -1, -2, -2,  1, -1,  2,  2,  1};

void HorseStep(int Deck[][SIZE_DECK], int posX, int posY, int step = 1);
void DispleyHorseSteps(int Deck[][SIZE_DECK]);
bool immitation(int newPosX, int newPosY)
{
    if (newPosX<0 || newPosX>SIZE_DECK-1 || newPosY<0 || newPosY>SIZE_DECK-1 || Deck[newPosX][newPosY]!=0) return false;
    return true;
}

int main()
{
    int posX;
    int posY;
    bool board = true;

    do{
        std::cout << "Enter from 1 to " << SIZE_DECK << " VERTICAL position : "; std::cin >> posX;
        std::cout << "Enter from 1 to " << SIZE_DECK << " HORIZONT position : "; std::cin >> posY;
        if (posX<1 || posX>SIZE_DECK || posY<1 || posY>SIZE_DECK) {
                board = true;
                std::cout << "\nIncorrect. Your choice goes beyond the size of the board! Reenter your chose.\n";
        }
        else board = false;
        std::cout << '\n';}
    while(board);
        std::cout << "\nYour choise start position : " << posX << '*' << posY << std::endl;

    int Deck_Mas[SIZE_DECK][SIZE_DECK] = {};
    HorseStep(Deck_Mas, posX - 1, posY - 1);

return 0;
}

void HorseStep(int Deck[][SIZE_DECK], int posX, int posY, int numStep)
{
    Deck[posX][posY] = numStep++;
    for (int i=0; i<8; ++i){
        int newPosX=posX+HorseStep_X[i];
        int newPosY=posY+HorseStep_Y[i];

        if (numStep > SIZE_DECK*SIZE_DECK){
            DispleyHorseSteps(Deck);
            exit(0);
        }

        immitation(newPosX, newPosY) {
            continue;
        }
        HorseStep(Deck, newPosX, newPosY, numStep);
        Deck[newPosX][newPosY]=0;
    }
}

void DispleyHorseSteps(int Deck[][SIZE_DECK])
{
    for (int i=0; i<SIZE_DECK; ++i){
        std::cout << "-----";
    }
    std::cout << '\n';
    for (int i=0; i<SIZE_DECK; ++i){
        for (int j=0; j<SIZE_DECK; ++j){
            std::cout << std::setw(3) << Deck[i][j] << " |";
        }
        std::cout << '\n';
        for (int i=0; i<SIZE_DECK; ++i){
            std::cout << "-----";
        }
        std::cout << '\n';
    }
}
