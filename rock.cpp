#include <iostream>
#include <cstdlib>
#include <windows.h>
using namespace std;
short GameRounds = 0, Player1Won = 0, ComputerWon = 0, DrawTimes = 0;
string LastWinner;
bool PlayAgain = true;
short ReadNumber() {
    short Number;
    cin >> Number;
    return Number;
}
int RandomNumber(int From, int To) {
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}
short ReadHowManyRounds() {
    cout << "How many rounds ( 1 to 10)? ";
    short HowMany = ReadNumber();
    return HowMany;
}
string whoWin(short userInput, short Computer) {
    // Stone   = 1;
    // Paper   = 2;
    // Scissor = 3;
    switch (Computer) {
        case 1: // Stone
            switch (userInput)
            {
                case 1: // 
                     return "[No winner]";
                case 2: // Paper
                    return "[Player1]";
                case 3: // Scissor
                    return "[Computer]";
            }
        case 2: // Paper
            switch (userInput)
            {
            case 1: // Stone
                return "[Computer]";
            case 2: // Paper
                return "[No winner]";
            case 3: // Scissor
                return "[Player1]";
            }
        case 3: // Scissor
            switch (userInput)
            {
            case 1: // Stone
                return "[Player1]";
            case 2: // Paper
                return "[Computer]";
            case 3: // Scissor
                return "[No winner]";
            }
    }
}
void ChangeColor(string Winner) {
    if (Winner == "[Player1]")
    {
        system("color 2F");
        LastWinner = "Player1";
        Player1Won++;
    }
    else if (Winner == "[Computer]") {
        system("color 4F");
        ComputerWon++;
        LastWinner = "Computer";

    }
    else if (Winner == "[No winner]") {
        system("color 6F");
        DrawTimes++;
        LastWinner = "No winner";
    }
}
void covertNumberTOsoAsmo(short value) {
    switch (value) {
    case 1:
        cout << "Stone\n";
        break;
    case 2:
        cout << "Paper\n";
        break;
    case 3:
        cout << "Scissor\n";
        break;
    default:
        cout << "You chose something wrong.\n";
    }
}
void PrintTheRuseltOfTheRound(short userInput, short round) {
    cout << "\n\n________________________Round [" << round << "]" << "________________________\n" << endl;
    cout << "Player 1 choice: ";
    covertNumberTOsoAsmo(userInput);
    cout << "Computer choice: ";
    short computer= RandomNumber(1, 3);
    covertNumberTOsoAsmo(computer);
    cout << "Round Winner: ";
    string Winner = whoWin(userInput, computer);
    ChangeColor(Winner);
    cout << Winner << endl;
    cout << "_________________________________________________________\n\n";
}
void StartRounds(short rounds) {
    int userInput;
    GameRounds = rounds;
    for (unsigned short i = 1; i <= rounds; i++)
    {
        cout << "\n\nRound [" << i << "] begins:\n" << endl;
        cout << "Your choice: [1]:Stone, [2]:Paper, [3]Scissors: ";
        cin >> userInput;
        PrintTheRuseltOfTheRound(userInput, i);
    }
    char again;
    cout << "\t\t\t\t_________________________________________________________\n\n";
    cout << "\t\t\t\t\t\t + + + G a m e O v e r +++\n\n";
    cout << "\t\t\t\t_________________________________________________________\n\n";
    cout << "\t\t\t\t________________________[Game Results]___________________\n\n";
    cout << "\t\t\t\tGame Rounds\t\t: " << GameRounds << endl;
    cout << "\t\t\t\tPlayer1 won times\t: " << Player1Won << endl;
    cout << "\t\t\t\tComputer won times\t: " << ComputerWon << endl;
    cout << "\t\t\t\tDraw times\t\t: " << DrawTimes << endl;
    cout << "\t\t\t\tFinal winner\t\t: " << LastWinner << endl << endl;
    cout << "\t\t\t\t_________________________________________________________\n\n";
    cout << "\t\t\t\tDo you want to play again? (Y/N): ";
    cin >> again;
    cout << endl << endl;
    cout << endl << endl;
    if (again == 'N' || again == 'n')
        PlayAgain = false;
    else {
        system("cls");
        system("color 0F");
    }
}
void StartGame() {
    while (PlayAgain) {
        StartRounds(ReadHowManyRounds());
    }
}

int main()
{
    srand((unsigned)time(NULL));
    StartGame();
    return 0;
}