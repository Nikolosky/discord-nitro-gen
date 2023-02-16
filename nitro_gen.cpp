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
 
        cout << "\n\n> Hello! I am Mar4e 15 yo programmer! \n> Here is super fast discord generator!" << endl;
        sleep(3);
        system("cls");
 
        cout << "     __  ___                   __ __        " << endl;
        cout << "    /  |/  /  ____ _   _____  / // /   ___  " << endl;
        cout << "   / /|_/ /  / __ `/  / ___/ / // /_  / _ \\" << endl;
        cout << "  / /  / /  / /_/ /  / /    /__  __/ /  __/ " << endl;
        cout << " /_/  /_/   \\ ___/  /_/       /_/    \\___/" << endl;
 
        int VKUPNO;
        int OPCIJA;

        cout << "\n\n> 1. Generator \n> 2. Checker \n> 3. Social \n\n> 0. Exit \n> Option: ";
        cin >> OPCIJA;

        if(OPCIJA == 0) {
            exit(0);
        }
        else if(OPCIJA == 1) {
            goto GENERATOR;
        }
        else if(OPCIJA == 2) {
            goto CHECKER;
        }
        else if(OPCIJA == 3) {
            system("start mar4ee.glitch.me");
        }
        else {
            cout << "Wrong option, try again!" << endl;
            sleep(3);
            exit(0);
        }

        GENERATOR: {
            cout << "> How much to generate: " << endl;
            cin >> VKUPNO;
    
            vector<string> generated;
            string line;
            ifstream file("codes.txt");
            ofstream outputFile;
            outputFile.open("codes.txt");

            for (int i = 0; i <= VKUPNO; i++) {
                outputFile << genNitro() << endl;
                generated.push_back(genNitro());
                //cout << generated[VKUPNO] << endl;
            }
            while (getline(file, line)) {
                cout << "> " << line << endl;
            }
            cout << "\n> Generated " << VKUPNO << " codes! \n> Check codes.txt file!" << endl;
    
            outputFile.close();
            string WCHECK;
            cout << "> If you want to check codes type Y/y or N/n to exit: ";
            cin >> WCHECK;
            if(WCHECK == "Y" || WCHECK == "y")
            {
                goto CHECKER;
            }
            else if(WCHECK == "N" || WCHECK == "n") {
                exit(0);
            }
            else {
                cout << "> Wrong option, try again!";
                sleep(3);
                exit(0);
            }
        }

        CHECKER: {
            //system("pip install requests");
            system("python checker.py");
            //cout << "\n> SOON CHECKER!";
        }

        int goagain;
        cout << "\n> 1. Refresh applicacion \n> 2. Soical \n\n> 0. Exit: ";
        cin >> goagain;
        if(goagain == 0) {
            exit(0);
        }
        else if(goagain == 1)
        {
            fromBegining = true;
        }
        else if(goagain == 2) {
            system("start https://mar4ee.glitch.me");
        }
        else {
            cout << "> Wrong option, try again!";
            sleep(3);
            exit(0);
        }
    } while(fromBegining != false);
    return 0;
}