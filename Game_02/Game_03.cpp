#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

void printFileContent(const string& fileName) {
    ifstream file(fileName);
    char ch;

    if (!file.is_open()) {
        cerr << "Error opening file" << endl;
        return;
    }

    while (file.get(ch)) {
        cout << ch;
    }

    file.close();
}

int scoreGame_03 = 0;

void displayLogoGame_03() {
    ifstream file("C:\\Users\\mriga\\OneDrive\\Desktop\\Stuff\\QT_Integrated_Terminal_Suite\\Game_02\\Game_3_Ascii.txt");
    char ch;

    if (!file.is_open()) {
        cout << "Error opening the file." << endl;
        return;
    }

    while (file.get(ch)) {
        cout << ch;
    }

    file.close();
}

void playSlotMachine() {
    cout << "                                                                PRESS < ENTER > TO CONTINUE\n\n";
    cin.ignore();

    int x, y, z, num1, num2, num3;
    x = rand();
    y = rand();
    z = rand();
    num1 = 1 + (x % 9);
    num2 = 1 + (y % 9);
    num3 = 1 + (z % 9);
    for (int i = 0; i <= 2; i++) {
        cout << "                                                                   ";
        for (int j = 0; j < 19; j++) {
            if (i == 0) {
                cout << "-";
            } else if ((i > 0 && j == 0) || (i > 0 && j == 18) || (i > 0 && j == 6) || (i > 0 && j == 12)) {
                cout << "|";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
    cout << "                                                                   | -" << num1 << "- | -" << num2 << "- | -" << num3 << "- |\n";
    for (int i = 0; i <= 2; i++) {
        cout << "                                                                   ";
        for (int j = 0; j < 19; j++) {
            if (i == 2) {
                cout << "-";
            } else if ((i < 2 && j == 0) || (i < 2 && j == 18) || (i < 2 && j == 6) || (i < 2 && j == 12)) {
                cout << "|";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
    if (num1 == num2) {
        if (num2 == num3) {
            printFileContent("C:\\Users\\mriga\\OneDrive\\Desktop\\Stuff\\QT_Integrated_Terminal_Suite\\Game_02\\SlotMachine_won.txt");
            scoreGame_03++;
        } else {
            printFileContent("C:\\Users\\mriga\\OneDrive\\Desktop\\Stuff\\QT_Integrated_Terminal_Suite\\Game_02\\SlotMachine_loss.txt");
        }
    } else {
        printFileContent("C:\\Users\\mriga\\OneDrive\\Desktop\\Stuff\\QT_Integrated_Terminal_Suite\\Game_02\\SlotMachine_loss.txt");
    }
}

void Game3() {
    displayLogoGame_03();
    srand(time(NULL));
    char playAgain = 'y';
    while (playAgain == 'y') {
        playSlotMachine(); // GAME
        cout << "YOUR SCORE IS: " << scoreGame_03 << endl << endl;
        cout << "Would you like to play again? (y/n): ";
        cin >> playAgain;
    }
}

int main() {
    Game3();
    return 0;
}
