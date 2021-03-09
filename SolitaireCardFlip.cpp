#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

char emptySpot = '.';
char faceUp = '1';
char faceDown = '0';
int choice;

const int totalCards = 10;
const int totalRows = 2;

typedef char CardField[totalCards];
typedef int CardIndex[totalCards];

void displayField(CardField field);
void storeIndex(CardIndex index);
void setCards(CardField field, CardIndex index);
void removeCard(CardField field);
bool playerWin(CardField field);
bool noFaceUp(CardField field);
void gameRules();

int main()
{
    CardField field;
    CardIndex index;
    storeIndex(index);
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
   cout << "Unable to flip anymore cards!\n";
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

void storeIndex(CardIndex index)
{
    srand(unsigned(time(0)));
    for(int i = 0; i < totalCards; i++)
    {
        index[i] = rand() % 17;
    }
}

void setCards(CardField field, CardIndex index)
{
    for(int i = 0; i < totalCards; i++)
    {
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
        if(field[choice] != emptySpot || field[choice - 2] != emptySpot)
        {
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

        }else{
            return;
        }
    }else{
        return;
    }
}

void gameRules()
{
    cout << "Welcome to Card Flip Solitaire!\n";
    cout << "Objective of the game is to remove all cards.\n";
    cout << "Face up cards are 1 and Face down cards are 0\n";
    cout << "You can only choose to flip a face up card\n";
    cout << "If you flip a face up card, the adjacent cards will flip over\n";
    cout << "You can only choose to remove face up cards only. Once removed, the spot becomes an empty spot shown as '.'\n";
    cout << "Press any key to continue\n";
    cin.get();
    cout << "\n";
}
