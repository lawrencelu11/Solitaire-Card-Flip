#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

char emptySpot = '.';
char faceUp = '1';
char faceDown = '0';
int choice;

const int totalCards = 10;

typedef char CardField[totalCards];
typedef int CardIndex[totalCards];

void displayField(CardField field);
void setCards(CardField field, CardIndex index);
void removeCard(CardField field);
bool playerWin(CardField field);
bool noFaceUp(CardField field);
void gameRules();

int main()
{
    CardField field;
    CardIndex index;
    setCards(field, index);
    gameRules();
    while(playerWin(field) == false && noFaceUp(field) == false)
    {
        displayField(field);
        cin >> choice;
        cout << "\n";
        removeCard(field);
    }

    return 0;
}

bool noFaceUp(CardField field)
{
   for(int i = 0; i < totalCards; i++)
   {
       if(field[i] == faceUp)
       {
           return false;
       }
   }
   cout << "Unable to remove every card! You Lose!\n";
   return true;
}

void displayField(CardField field)
{
    for(int i = 0; i < totalCards; i++)
    {

        cout << field[i] << " ";
    }
    cout <<"\n";
    for(int j = 1; j <= totalCards; j++)
    {
        cout << j << " ";
    }
    cout << "\n\n";
}

void setCards(CardField field, CardIndex index)
{
    srand(unsigned(time(0)));
    for(int i = 0; i < totalCards; i++)
    {
        index[i] = rand() % 17;
        field[i] = emptySpot;
        field[index[i]] = faceDown;
        if(field[i] == emptySpot)
        {
            field[i] = faceUp;
        }
    }
}

bool playerWin(CardField field)
{
    int counter = 0;
    for(int i = 0; i < totalCards; i++)
    {
        if(field[i] == emptySpot)
        {
            counter++;
        }
    }
    if(counter == totalCards)
    {
        cout<< "You win!\n";
        return true;
    }else{
        return false;
    }
}


void removeCard(CardField field)
{
    if(field[choice - 1] == faceUp)
    {
        field[choice - 1] = emptySpot;
        if(field[choice - 2] == faceDown)
        {
            field[choice - 2] = faceUp;
        }else if(field[choice - 2] == faceUp)
        {
            field[choice - 2] = faceDown;
        }
        if(field[choice] == faceDown)
        {
            field[choice] = faceUp;
        }else if(field[choice] == faceUp)
        {
            field[choice] = faceDown;
        }
    }
}

void gameRules()
{
    cout << "Objective of the game is to remove all cards.\n";
    cout << "Face up cards are 1 and Face down cards are 0\n";
    cout << "You can only remove face up cards, which will flip the cards next to it over.\n";
    cout << "Press any key to continue\n";
    cin.get();
    cout << "\n";
}

