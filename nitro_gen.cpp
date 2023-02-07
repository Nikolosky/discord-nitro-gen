#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include <string>
#include <Windows.h>
#include <unistd.h>

//bool filefound = false;

using namespace std;

const int DOLZINA = 16;

const char KARAKTERI[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
const int KARAKTERI_LEN = sizeof(KARAKTERI) - 1;


string genNitro()
{
    string gennitro = "";
    for(int i = 0; i < DOLZINA; i++)
    {
        gennitro += KARAKTERI[rand() % KARAKTERI_LEN];
    }
    return gennitro;
}

int main()
{

    cout << "   ______    _   __" << endl;
    cout << "  / ____/   / | / /" << endl;
    cout << " / / __    /  |/ / " << endl;
    cout << "/ /_/ /   / /|  /  " << endl;
    cout << "\\____/   /_/ |_/   " << endl; 

    cout << "\n\nHello! I am Mar4e 15 yo programmer! \nHere is super fast discord generator!";
    Sleep(5);
    system("cls");

    cout << "     __  ___                   __ __        " << endl;   
    cout << "    /  |/  /  ____ _   _____  / // /   ___  " << endl;
    cout << "   / /|_/ /  / __ `/  / ___/ / // /_  / _ \\ " << endl;
    cout << "  / /  / /  / /_/ /  / /    /__  __/ /  __/ " << endl;
    cout << " /_/  /_/   \\ ___/  /_/       /_/    \\___/" << endl;

    int VKUPNO;
    
    cout << "\n\nSOON NITRO CHECKER!" << endl;
    cout << "\n\nHow much to generate: ";
    cin >> VKUPNO;

    srand(time(0));

    ofstream outputFile;
    outputFile.open("nitros.txt");

    for (int i = 0; i < VKUPNO; i++) {
        outputFile << "https://discord.gift/" << genNitro() << endl;
    }
    cout << "Generated " << VKUPNO << " codes! \nCheck nitros.txt file!" << endl;

    
    outputFile.close();
    system("PAUSE");
    return 0;
}