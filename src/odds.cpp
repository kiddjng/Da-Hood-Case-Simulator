#include <iostream>
#include <string>
#include <ctime>
#include <chrono>
#include <Windows.h>


using std::cout, std::endl, std::cin;

//Slapped it all into main :facepalm:

int main(int argc, char ** argv)
{
    std::srand(std::time(NULL));

    int _amount;

    auto check = [&](){
        try{
            cin >> _amount;
        }catch(std::invalid_argument){
            return false;
        }catch(std::out_of_range){
            return false;
        }

    if(_amount<0){
        return false;
    }

    return true;

    };

    bool donem = false;
    do{
        
        do{
            

        system("cls");
        cout << "How many cases would you like to open (123 to quit)" << endl;

        }while(!check());

        if(_amount==123){
            return 0;
        }

        //Getting the information
        int displays [4] {0,0,0,0};
        std::string labels[4]{"commons","rares","epics","legendaries"};
        std::chrono::time_point start = std::chrono::steady_clock::now();

        while(_amount>0){

            int randnum = (std::rand()%100)+1;
            int anotherone;
            switch(randnum){
                case 1:
                case 2:
                ++displays[2];
                break;
                //For the legendaries
                case 4:
                anotherone = (std::rand()%1)+1;
                if(anotherone==1){
                    ++displays[3];
                }
                break;
                case 8:
                case 12:
                case 28:
                case 96:
                case 44:
                ++displays[1];
                break;
                default:
                ++displays[0];
                break;
            }

            --_amount;
        }

        std::chrono::time_point end = std::chrono::steady_clock::now();
        std::chrono::duration total = end-start;



        //Displaying the results
        bool viewd = false;
        do{
            HANDLE hconsole = GetStdHandle(STD_OUTPUT_HANDLE);

            system("cls");

        unsigned int count = 0;
        for(size_t i{}; i<std::size(displays); ++i){
            SetConsoleTextAttribute(hconsole,i+1);
            std::cout << labels[i] << " : " << displays[i] << endl;
        }

        SetConsoleTextAttribute(hconsole,7);
        cout << "Time elasped : " << total.count() << endl;
        cout << endl << "Are you done viewing?" << endl;
        
        std::string doneq;

        cin >> doneq;
        viewd = (doneq=="y" || doneq=="yes" || doneq=="YES" || doneq=="yes") ? true : false;

        count = 0;
        
        }while(!viewd);

        //Resetting when done
        for(auto& i : displays){
            i=0;
        }

    
    }while(!donem);
}