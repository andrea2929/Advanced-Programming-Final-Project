//
// Created by Andrea Halenkamp on 12/15/16.
//

#ifndef PROJECTPOKEMON_PC_H
#define PROJECTPOKEMON_PC_H

#include <iostream>
#include <fstream>
#include<string>
#include<map>

#include"Pokemon.h"

//map does not use pokedex ids, but other id so that we can have mega-evolutions
//which do not have real pokedex ids. Alternate forms/megas have 'pokedex ids' above 1000
typedef map<int, Pokemon, less<int>> poke;
class PC {
private:
    poke pokemon;
public:
    bool contains_number(const std::string &c);

    void readfile(string filename);
    void deposit(int i, Pokemon *p);

    int howMany();
    void sort(string i);

    //Lookups
    vector<Pokemon> getByTypes(string type1, string type2);
    vector<Pokemon> getByType(string type);
    vector<Pokemon> searchStatsGreater(int hp, int attk, int def, int spattk, int spdef, int spd);
    Pokemon getByName(string n);
    Pokemon getByNumber(int i);

    void print(int i);
    void printFirst(int i);
    void print();
};


#endif //PROJECTPOKEMON_PC_H
