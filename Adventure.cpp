#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    srand(static_cast<unsigned int>(time(0)));
    cout << "Hello defender!\nWhat is your name? ";
    string defender;
    cin >> defender;
    cout << defender + ", your home is under attack. Can you withstand the onslaught until help arives?\n";
    int health = 10;
    int attack;
    int block;
    int hit;
    int turns = 0;
    int curr_round = 0;
    int max_round = (rand() % 3) + 6;
    cout << "max round " << max_round << endl;

    while (health > 0 && curr_round != max_round)
    {
        ++curr_round;
        cout << "round " << curr_round << endl;
        attack = rand() % 5;
        block = rand() % 5;
        cout << "attack " << attack << endl;
        cout << "block " << block << endl;
        hit = attack - block;
        if (hit > 0)
        {
            health -= hit;

        }
        

        cout << "health " << health << endl;


        if (health <= 4)
        {
            cout << "Please, " << defender << ", you must rest soon!\n";
        }

        continue;
    }
    if (health <= 0) 
    {
        cout << defender << ", your body has failed you...\njust as you have failed your people.\n";
    }
        
    if (curr_round == max_round)
    {
        cout << defender << ", you have held out long enough for help to arrive.\nYour victory will be praised as long as your home stands!\n";    
    }
}
