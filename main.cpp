#include <iostream>

#include "Pokemon.h"
#include "PC.h"

//Allows the user to lookup pokemon by type(s)
void typeLookup(PC p) {
    vector<Pokemon> typecheck;
    int numStore = 0;

    cout << "How many types?" << endl;
    cin >> numStore;

    if (numStore==2) {
        string type1;
        string type2;
        cout << "Give first type: " << endl;
        cin >> type1;
        cout << "Give second type: " << endl;
        cin >> type2;

        typecheck = p.getByTypes(type1, type2);
        if (typecheck.empty()) {
            cout << "\nThere are no pokemon with that typing" << endl;
        }
        else {
            cout << "\nPokemon with the types:" << endl;
            for (Pokemon i : typecheck)
                i.print();
        }
    }
    else if (numStore==1) {
        string type;
        cout << "Give type: " << endl;
        cin >> type;
        cout << "\nPokemon with the type:" << endl;
        typecheck = p.getByType(type);
        for (Pokemon i : typecheck)
            i.print();
    }
    else {
        cout << "Invalid Number, a pokemon can only have 1 or 2 types. Please try again." << endl;
        typeLookup(p);
    }
}

//Check which pokemon have the stats you want
void statsLookup(PC p) {
    int hp= 0,attk= 0,def= 0,spattk= 0,spdef= 0,spd = 0;
    string store;

    bool stats = true;
    while(stats) {
        cout << "Stat to change: " << endl;
        cin >> store;

        std::transform(store.begin(), store.end(), store.begin(), ::tolower);

        cout << "Change to what: " << endl;
        if (store=="hp") {
            cin >> hp;
        }
        else if (store=="attack") {
            cin >> attk;
        }
        else if (store=="defense") {
            cin >> def;
        }
        else if (store=="special-attack") {
            cin >> spattk;
        }
        else if (store=="special-defense") {
            cin >> spdef;
        }
        else if (store=="speed") {
            cin >> spd;
        }

        cout << "Change more?" << endl;
        cin >> store;

        if (store=="No" || store=="no" || store=="N" || store=="n")
            stats = false;
    }

    vector<Pokemon> list = p.searchStatsGreater(hp,attk,def,spattk,spdef,spd);

    if (!list.empty()) {
        cout << "Pokemon found: " << endl;
        for (Pokemon i : list) {
            i.print();
        }
    } else cout << "Could not find any Pokemon with those stats" << endl;
}

//Allows the user to lookup pokemon by name
void nameLookup(PC p) {
    cout << "What is the name?" << endl;
    string name;
    cin >> name;

    std::transform(name.begin(), name.end(), name.begin(), ::tolower);

    Pokemon found = p.getByName(name);

    if (!found.getName().empty()) {
        cout << "\nPokemon with name:" << endl;
        found.print();
    }
    else {
        cout << "\nNo Pokemon was found" << endl;
    }
}

//Allows the user to lookup pokemon by pokedex number (not map id)
void numberLookup (PC p) {
    cout << "What is the id?" << endl;
    int id;
    //Not looking up by map id, but by pokedex id
    cin >> id;

    //Tries to find Pokemon by the id given
    Pokemon found = p.getByNumber(id);

    //Check if Pokemon was found
    if (!found.getName().empty()) {
        cout << "\nPokemon with id:" << endl;
        found.print();
    }
    else {
        cout << "\nNo Pokemon was found" << endl;
    }
}

//Allows the user to decide what to do
void userInput(PC p) {
    string store; //stores user input

    cout << "\nWhat do you want to do?"
         << "\n1:Lookup By Type"
         << "\n2:Lookup By Name"
         << "\n3:Lookup By ID"
         << "\n4:Lookup By Stats"
         << "\n5:Print All Pokemon" << endl;
    cin >> store; //takes in the user's answer

    //For lookup either one type or multiple types
    if (store == "1") {
        typeLookup(p);
    }
    //For lookup by a name
    else if (store == "2") {
        nameLookup(p);
    }
    //For lookup by a number (id)
    else if (store == "3") {
        numberLookup(p);
    }
    //
    else if (store == "4") {
        statsLookup(p);
    }
    //To print everything
    else if (store == "5") {
        p.print();
    }

    cout << "\nRun another task?" << endl;
    cin >> store;

    if (store=="yes")
        userInput(p);
}

int main() {

    PC p;

    //Loading dataset that has been preformatted through R into the PC
    p.readfile("/Users/andreahalenkamp/ClionProjects/ProjectPokemon/pokemon.txt");

    //Run the program using the PC created
    //userInput(p);

    p.sort("all");

}