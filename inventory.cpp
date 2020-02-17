#include <iostream>
#include <string>

using namespace std;

int main() {
    string adventurer;
    cout << "Hello adventurer. What is your name?\n";
    cin >> adventurer;
    cout << "You are escorting a trader to The Capital.\n";
    cout << "You are equipped with a longsword, a shield, and chainmail.\n"; 
    
    //Create array of items
    string inventory[10];
    //create a variable for how many items player has
    int numItems = 0;
    //give 3 items
    inventory[numItems++] = "Longsword";
    inventory[numItems++] = "Shield";
    inventory[numItems++] = "Chainmail";


    //print the player's items
    cout << "\nYour inventory:\n";
    for (int i = 0; i < numItems; ++i){
        if (inventory[i] != ""){
                cout << inventory[i] << endl;
        }
    }

    cout << "\nYou are new to this kind of work and are not sure you are well enough prepared.\n";
    cout << "You ask the trader if he has any equipment he can part with. He tosses you a small dagger.\n";
    cout << "The dagger has a very faint glow to it. It seems that this weapon deserves a name.\n";
    cin >> inventory[numItems++];
    cout << "\nYour inventory:\n";
    for (int i = 0; i < numItems; ++i){
        if (inventory[i] != ""){
                cout << inventory[i] << endl;
        }
    }

    cout << "About an hour passes and you notice a glint behind a tree. You go to investigate.\n";
    cout << "As you get closer you notice that it is a body! This is unsettling...\n";
    cout << "Off to the side of the body you see a helmet with an intricate design and a sturdy bow.\n";
    cout << "You decide the items are of better use to you than the poor soul they were lying next to.\n";
    cout << "What will you call the helmet?\n";
    cin >> inventory[numItems++];
    cout << "And the bow?\n";
    cin >> inventory[numItems++];
    cout << "\nYour inventory:\n";
    for (int i = 0; i < numItems; ++i){
        if (inventory[i] != ""){
                cout << inventory[i] << endl;
        }
    }

    cout << "\nComing to the edge of a forrest that you must traverse to get to The Capital. You notice a man waiting.\n";
    cout << "As you aproach, the man begins to tell you that he is a collector for his guild. He says that the guild is responsible for clearing the forrest of dangerous wildlife.\n";
    cout << "The Capital as decided this was a necesity and to pay the guild, he requests a tax from anyone who wishes to continue through.\n";
    cout << "You do not have any coin and the trader is refusing to give up his own.\n";
    cout << "The man says that if you part with a piece of equipment he will grant you passage.\n";

    //ask for item until valid item is input
    string useItem;
    int remove = false;
    do{
        cout << "Which piece of equipment do you decide to give up?\n";
        cin >> useItem;
        for(int i = 0; i < numItems; ++i){
            if(useItem == inventory[i]){
                inventory[i].erase();
                remove = true;
                break;
            }
            else{
                if(i == numItems - 1){
                    cout << "You do not have anything with that name.\n";
                    break;
                }
            }
        }
    }while (remove != true);
    //print the player's items
    cout << "\nYour inventory: \n";
    for (int i = 0; i < numItems; ++i){
        if (inventory[i] != ""){
                cout << inventory[i] << endl;
        }
    }
    cout << "\nThe rest of the journey is fairly calm and you arrive at The Capital before nightfall.\n";
    cout << "The trader pays his dues and you part ways, ready to find more work.";
    return(0);
}