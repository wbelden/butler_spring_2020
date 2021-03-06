#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>

using namespace std;

int main()
{
    
 //Debug mode
    bool debug = false;
    int choice;
    cout << "Choose play mode: \n";
    cout << "1: Normal mode\n";
    cout << "2: Debug mode \n";
    cin >> choice;
    switch (choice)
    {
    case 1: 
        debug = false;
        break;
    case 2:
        debug = true;
        break;
    default:
        debug = false;
        break;
    }
    
 //introduction & variables
    srand(static_cast<unsigned int>(time(0)));
    cout << "Hello defender!\nWhat is your name?\n";
    string defender;
    cin >> defender;
    cout << defender + ", your home is under attack. Can you withstand the onslaught until help arives?\n";
    int health = 10;
    int attack;
    int block;
    int hit;
    int turns = 0;
    int curr_round = 0;
    
 //make max round random 
    int max_round = (rand() % 3) + 6;
    if (debug == 1)
    {
    cout << "Max round: " << max_round << endl;
    }
    
 //fight loop
    while (health > 0 && curr_round != max_round)
    {
     //increase round and state round
        ++curr_round;
        cout << endl << max_round - curr_round + 1 << " day(s) till help arrives...\n";
        if (debug == 1)
        {
        cout << "Round: " << curr_round << endl;
        }
        
     //attack & defense rolls
        attack = rand() % 5;
        block = rand() % 5;
        if (debug == 1)
        {
        cout << "Attack: " << attack << endl;
        cout << "Block: " << block << endl;
        }
        
     //calculate damage and state block or hit
        hit = attack - block;
        if (hit > 0)
        {
            health -= hit;
            cout << "You were hit for " << hit << " damage!\n";
        }
        else
        {
            cout << "You succesfully blocked the attack!\n";
        }
        if(debug == 1)
        {
        cout << "Health: " << health << endl;
        }
        
     //low health warning
        if (health == 3 || health == 4)
        {
            cout << "Please, " << defender << ", you must rest soon!\n";
        }
        
     //rest for two seconds
        this_thread::sleep_for(chrono::milliseconds(2000));

        continue;
    }
    
 //winning or losing statements
    if (health <= 0) 
    {
        cout << endl << defender << ", your body has failed you...\njust as you have failed your people.\n";
    }
    else
    {
        cout << endl << defender << ", you have held out long enough for help to arrive.\nYour victory will be praised as long as your home stands!\n";    
    }
    
    return 0;
}
