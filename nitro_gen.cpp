#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include <string>
#include <vector>
#include <Windows.h>
#include <unistd.h>
 
using namespace std;
 
bool fromBegining = false;
 
const int DOLZINA = 16;
 
const char KARAKTERI[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
int KARAKTERI_LEN = sizeof(KARAKTERI) - 1;
 
string goagain; 

string genNitro()
{
    string gennitro = "https://discord.gift/";
    for(int i = 0; i <= DOLZINA; i++)
    {
        gennitro += KARAKTERI[rand() % KARAKTERI_LEN];
    }
    return gennitro;
}
 
int main()
{
    do{
        srand(time(NULL));
        setlocale(LC_ALL, "en_US.utf8");
        system("title Discord Nitro Generator by Marche15!");
        cout << "   ______    _   __" << endl;
        cout << "  / ____/   / | / /" << endl;
        cout << " / / __    /  |/ / " << endl;
        cout << "/ /_/ /   / /|  /  " << endl;
        cout << "\\____/   /_/ |_/  " << endl;
 
        cout << "\n\n> Hello! I am Mar4e 15 yo programmer! \n> Here is super fast discord generator!";
        sleep(5);
        system("cls");
 
        cout << "     __  ___                   __ __        " << endl;
        cout << "    /  |/  /  ____ _   _____  / // /   ___  " << endl;
        cout << "   / /|_/ /  / __ `/  / ___/ / // /_  / _ \\" << endl;
        cout << "  / /  / /  / /_/ /  / /    /__  __/ /  __/ " << endl;
        cout << " /_/  /_/   \\ ___/  /_/       /_/    \\___/" << endl;
 
        int VKUPNO;
 
        cout << "\n\n> SOON NITRO CHECKER!" << endl;
        cout << "> How much to generate: " << endl;
        cin >> VKUPNO;
 
        vector<string> generated;
        string line;
        ifstream file("nitros.txt");
        ofstream outputFile;
        outputFile.open("nitros.txt");

        for (int i = 0; i <= VKUPNO; i++) {
            outputFile << genNitro() << endl;
            generated.push_back(genNitro());
            //cout << generated[VKUPNO] << endl;
        }
        while (getline(file, line)) {
            cout << "> " << line << endl;
        }
        //cout << "\n> Generated " << VKUPNO << " codes! \n> Check nitros.txt file!" << endl;
 
        outputFile.close();
 
        cout << "\n> If you want to generate again type Y/y or if you want to exit N/n: ";
        cin >> goagain;
        if(goagain == "Y" || goagain == "y")
        {
            fromBegining = true;
        }
        else if(goagain == "N" || goagain == "n") {
            exit(0);
        }
    } while(fromBegining != false);
    return 0;
}
