//
// Created by Andrea Halenkamp on 12/14/16.
//

#ifndef PROJECTPOKEMON_POKEMON_H
#define PROJECTPOKEMON_POKEMON_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Pokemon {
public:

    /*Constructors*/
    Pokemon() {};

    /*Checks*/
    bool compareTypes(string type1, string type2);
    bool compareType(string type);

    /*Getters and Setters*/
    const string &getName() const;
    void setName(const string &name);
    const int getId() const;
    void setId(const int id);
    const vector<string> getTypes() const;
    void setTypes(const vector<string> &types);
    const int *getBase_stats() const;
    const vector<string> &getAbilities() const;
    void setAbilities(const vector<string> &abilities);
    int getGender_rate() const;
    void setGender_rate(int gender_rate);

    /*Custom Getters and Setters*/
    void addType(string t);
    void setbase_hp(int h);
    void setbase_attack(int a);
    void setbase_defense(int d);
    void setbase_specialattack(int sa);
    void setbase_specialdefense(int sd);
    void setbase_speed(int s);
    int getbase_hp()const;
    int getbase_attack()const;
    int getbase_defense()const;
    int getbase_specialattack()const;
    int getbase_specialdefense()const;
    int getbase_speed()const;
    void addAbility(string a);
    const string &getDescription() const;
    void setDescription(const string &description);

    /*Print statements*/
    void printTypes()const;
    void printbase_stats()const;
    void printAbilities()const;
    const void print()const;

private:
    string name;
    int id;
    vector<string> types;
    int base_stats[6];
    // Order: {hp, attack, defense, special-attack, special-defense, speed}
    vector<string> abilities;
    int gender_rate;
    string description;

};

class comparebase_hp {
public:
    bool operator()(const Pokemon & lhs, const Pokemon & rhs) const {
        return lhs.getbase_hp() > rhs.getbase_hp();
    }
};

class comparebase_attack {
public:
    bool operator()(const Pokemon & lhs, const Pokemon & rhs) const {
        return lhs.getbase_attack() > rhs.getbase_attack();
    }
};

class comparebase_defense {
public:
    bool operator()(const Pokemon & lhs, const Pokemon & rhs) const {
        return lhs.getbase_defense() > rhs.getbase_defense();
    }
};

class comparebase_specialattack {
public:
    bool operator()(const Pokemon & lhs, const Pokemon & rhs) const {
        return lhs.getbase_specialattack() > rhs.getbase_specialattack();
    }
};

class comparebase_specialdefense {
public:
    bool operator()(const Pokemon & lhs, const Pokemon & rhs) const {
        return lhs.getbase_specialdefense() > rhs.getbase_specialdefense();
    }
};

class comparebase_speed {
public:
    bool operator()(const Pokemon & lhs, const Pokemon & rhs) const {
        return lhs.getbase_speed() > rhs.getbase_speed();
    }
};

class comparebase_all {
public:
    bool operator()(const Pokemon & lhs, const Pokemon & rhs) const {
        return (lhs.getbase_hp()+lhs.getbase_attack()+
                 lhs.getbase_defense()+lhs.getbase_specialattack()+
                lhs.getbase_specialdefense()+lhs.getbase_speed())
               > (rhs.getbase_hp()+rhs.getbase_attack()+
                  rhs.getbase_defense()+rhs.getbase_specialattack()+
                  rhs.getbase_specialdefense()+rhs.getbase_speed());
    }
};

#endif //PROJECTPOKEMON_POKEMON_H
