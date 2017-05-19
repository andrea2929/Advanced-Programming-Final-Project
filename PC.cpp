//
// Created by Andrea Halenkamp on 12/15/16.
//

#include "PC.h"

/*Function to check if string contains a number, for stoi*/
bool PC::contains_number(const std::string &c) {
    return c.find('0') != std::string::npos ||
    c.find('1') != std::string::npos ||
    c.find('2') != std::string::npos ||
    c.find('3') != std::string::npos ||
    c.find('4') != std::string::npos ||
    c.find('5') != std::string::npos ||
    c.find('6') != std::string::npos ||
    c.find('7') != std::string::npos ||
    c.find('8') != std::string::npos ||
    c.find('9') != std::string::npos;
}

/*Reads each line of a file and inputs pokemon*/
void PC::readfile(string filename) {

    ifstream myfile;
    myfile.open(filename);

    string line;
    string delimiter = ",";

    while(getline(myfile,line)) {

        Pokemon newPokemon;
        int num;

        size_t pos = 0;
        string token;
        int place = 0;
        while (((pos = line.find(delimiter)) != string::npos)&&(place < 20)) {
            token = line.substr(0, pos);

            if (token.empty()) {

            }
            else if (place==0&&contains_number(token)) {
                num = stoi(token);

                if (pokemon.find(num) != pokemon.end()) {
                    break;
                }
            }
            else if (place==1) {
                newPokemon.setName(token);
            }
            else if (place==2&&contains_number(token)) {
                newPokemon.setId(stoi(token));
            }
            else if (place>2&&place<5&&token!="None") {
                newPokemon.addType(token);
            }
            else if (place==5&&contains_number(token)) {
                newPokemon.setbase_hp(stoi(token));
            }
            else if (place==6&&contains_number(token)) {
                newPokemon.setbase_attack(stoi(token));
            }
            else if (place==7&&contains_number(token)) {
                newPokemon.setbase_defense(stoi(token));
            }
            else if (place==8&&contains_number(token)) {
                newPokemon.setbase_specialattack(stoi(token));
            }
            else if (place==9&&contains_number(token)) {
                newPokemon.setbase_specialdefense(stoi(token));
            }
            else if (place==10&&contains_number(token)) {
                newPokemon.setbase_speed(stoi(token));
            }
            else if (place>10&&place<14) {
                newPokemon.addAbility(token);
            }
            else if (place==15&&token.length()>0&&contains_number(token)) {
                newPokemon.setGender_rate(stoi(token));
            }
            line.erase(0, pos + delimiter.length());
            place++;
        }

        if (line.size()>2)
            newPokemon.setDescription(line.substr(1,line.size()-2));

        if (pokemon.find(num) == pokemon.end()) {
            deposit(num, &newPokemon);
        }

    }
}

/*Adds a pokemon to the map*/
void PC::deposit(int i, Pokemon *p){
    pokemon.insert(poke::value_type(i, *p));
}

/*Should return how many pokemon are in the map*/
int PC::howMany() {
    return pokemon.size();
}

void PC::sort(string i) {
    if (i=="hp") {
        typedef map<Pokemon, int, comparebase_hp> newOrder;
        newOrder p;

        for (poke::iterator iter = pokemon.begin(); iter != pokemon.end(); ++iter) {
            p.insert(newOrder::value_type(iter->second, iter->first));
        }

        for (newOrder::iterator iter = p.begin(); iter != p.end(); ++iter) {
            iter->first.print();
        }
    }
    else if (i=="attack") {
        typedef map<Pokemon, int, comparebase_attack> newOrder;
        newOrder p;

        for (poke::iterator iter = pokemon.begin(); iter != pokemon.end(); ++iter) {
            p.insert(newOrder::value_type(iter->second, iter->first));
        }

        for (newOrder::iterator iter = p.begin(); iter != p.end(); ++iter) {
            iter->first.print();
        }
    }
    else if (i=="defense") {
        typedef map<Pokemon, int, comparebase_defense> newOrder;
        newOrder p;

        for (poke::iterator iter = pokemon.begin(); iter != pokemon.end(); ++iter) {
            p.insert(newOrder::value_type(iter->second, iter->first));
        }

        for (newOrder::iterator iter = p.begin(); iter != p.end(); ++iter) {
            iter->first.print();
        }
    }
    else if (i=="special-attack") {
        typedef map<Pokemon, int, comparebase_specialattack> newOrder;
        newOrder p;

        for (poke::iterator iter = pokemon.begin(); iter != pokemon.end(); ++iter) {
            p.insert(newOrder::value_type(iter->second, iter->first));
        }

        for (newOrder::iterator iter = p.begin(); iter != p.end(); ++iter) {
            iter->first.print();
        }
    }
    else if (i=="special-defense") {
        typedef map<Pokemon, int, comparebase_specialdefense> newOrder;
        newOrder p;

        for (poke::iterator iter = pokemon.begin(); iter != pokemon.end(); ++iter) {
            p.insert(newOrder::value_type(iter->second, iter->first));
        }

        for (newOrder::iterator iter = p.begin(); iter != p.end(); ++iter) {
            iter->first.print();
        }
    }
    else if (i=="speed") {
        typedef map<Pokemon, int, comparebase_speed> newOrder;
        newOrder p;

        for (poke::iterator iter = pokemon.begin(); iter != pokemon.end(); ++iter) {
            p.insert(newOrder::value_type(iter->second, iter->first));
        }

        for (newOrder::iterator iter = p.begin(); iter != p.end(); ++iter) {
            iter->first.print();
        }
    }
    else if (i=="all") {
        typedef map<Pokemon, int, comparebase_all> newOrder;
        newOrder p;

        for (poke::iterator iter = pokemon.begin(); iter != pokemon.end(); ++iter) {
            p.insert(newOrder::value_type(iter->second, iter->first));
        }

        for (newOrder::iterator iter = p.begin(); iter != p.end(); ++iter) {
            iter->first.print();
        }
    }
    else cout << "Incorrect Parameter" << endl;
}

vector<Pokemon> PC::searchStatsGreater(int hp, int attk, int def, int spattk, int spdef, int spd) {
    vector<Pokemon> found;

    for (poke::iterator iter = pokemon.begin(); iter != pokemon.end(); ++iter) {
        Pokemon p = iter->second;
        if (p.getbase_hp()>hp && p.getbase_attack()>attk && p.getbase_defense() > def
            && p.getbase_specialattack() > spattk && p.getbase_specialdefense() > spdef
            && p.getbase_speed() > spd) {
            found.push_back(iter->second);
        }
    }

    return found;
}

/*Returns a vector of all the pokemon in the map with those two types*/
vector<Pokemon> PC::getByTypes(string type1, string type2) {
    vector<Pokemon> p;

    for (poke::iterator iter = pokemon.begin(); iter != pokemon.end(); ++iter) {
        if (iter->second.compareTypes(type1,type2)) {
            p.push_back(iter->second);
        }
    }

    return p;
}

/*Returns a vector of all the pokemon in the map with just that one type*/
vector<Pokemon> PC::getByType(string type) {
    vector<Pokemon> p;

    for (poke::iterator iter = pokemon.begin(); iter != pokemon.end(); ++iter) {
        if (iter->second.compareType(type)) {
            p.push_back(iter->second);
        }
    }

    return p;
}

/*Retrieves the pokemon with this name*/
Pokemon PC::getByName(string n) {
    Pokemon p;

    for (poke::iterator iter = pokemon.begin(); iter != pokemon.end(); ++iter) {
        if (iter->second.getName()==n) {
            p = iter->second;
        }
    }

    return p;
}

/*Retrieves the pokemon with this id*/
Pokemon PC::getByNumber(int i) {
    Pokemon p;

    for (poke::iterator iter = pokemon.begin(); iter != pokemon.end(); ++iter) {
        if (iter->second.getId()==i) {
            p = iter->second;
        }
    }

    return p;
}

/*Prints the pokemon in the map with this key*/
void PC::print(int i) {
    pokemon[i].print();
}

/*Prints the first amount of pokemon in the map*/
void PC::printFirst(int i) {
    int n = 0;
    for (poke::iterator iter = pokemon.begin(); iter != pokemon.end() && n < i; ++iter) {
        cout << "Sequence id: " << iter->first << "\n";
        iter->second.print();
        cout << "\n";
        n++;
    }
}

/*Prints all the pokemon in the map*/
void PC::print() {
    for (poke::iterator iter = pokemon.begin(); iter != pokemon.end(); ++iter) {
        cout << "Sequence id: " << iter->first << "\n";
        iter->second.print();
        cout << "\n";
    }
}