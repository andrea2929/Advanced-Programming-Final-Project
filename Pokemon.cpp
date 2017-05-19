//
// Created by Andrea Halenkamp on 12/14/16.
//

#include "Pokemon.h"

bool Pokemon::compareTypes(string type1, string type2) {
    if (types.size()>1) {
        bool compare = true;
        for (auto i = types.begin(); i != types.end(); ++i) {
            if (*i != type1 && *i != type2) {
                compare = false;
            }
        }
        return compare;
    } else return false;
}

bool Pokemon::compareType(string type) {
    if (types.size()<2) {
        bool compare = true;
        for (auto i = types.begin(); i != types.end(); ++i) {
            if (*i != type) {
                compare = false;
            }
        }
        return compare;
    } else return false;
}

void Pokemon::addType(string t) {
    types.push_back(t);
}

void Pokemon::printTypes()const {
    cout << "Types: ";
    for (auto i = types.begin(); i != types.end(); ++i)
        cout << *i << ' ';
}

void Pokemon::setbase_hp(int h) {
    base_stats[0] = h;
}

void Pokemon::setbase_attack(int a) {
    base_stats[1] = a;
}

void Pokemon::setbase_defense(int d) {
    base_stats[2] = d;
}

void Pokemon::setbase_specialattack(int sa) {
    base_stats[3] = sa;
}

void Pokemon::setbase_specialdefense(int sd) {
    base_stats[4] = sd;
}

void Pokemon::setbase_speed(int s) {
    base_stats[5] = s;
}

int Pokemon::getbase_hp()const {
    return base_stats[0];
}

int Pokemon::getbase_attack()const {
    return base_stats[1];
}

int Pokemon::getbase_defense()const {
    return base_stats[2];
}

int Pokemon::getbase_specialattack()const {
    return base_stats[3];
}

int Pokemon::getbase_specialdefense()const {
    return base_stats[4];
}

int Pokemon::getbase_speed()const {
    return base_stats[5];
}

void Pokemon::addAbility(string a) {
    abilities.push_back(a);
}

void Pokemon::printbase_stats() const {
    cout << "\nStatistics:"
         << "\n\tHP: " << base_stats[0]
         << "\n\tAttack: " << base_stats[1]
         << "\n\tDefense: " << base_stats[2]
         << "\n\tSpecial-Attack: " << base_stats[3]
         << "\n\tSpecial-Defense: " << base_stats[4]
         << "\n\tSpeed: " << base_stats[5] << endl;
}

void Pokemon::printAbilities() const {
    cout << "Abilities: ";
    for (auto i = abilities.begin(); i != abilities.end(); ++i)
        cout << *i << ' ';
}

const void Pokemon::print() const {
    cout << "Pokemon Name: " << name
         << ", ID: " << id << ", ";

    printTypes();
    printbase_stats();

    printAbilities();
    if (!description.empty())
        cout << "\n" << description;
    cout << "\nGender Ratio: "
         << gender_rate << "/8\n" << endl;
}

const string &Pokemon::getName() const {
    return name;
}

void Pokemon::setName(const string &name) {
    Pokemon::name = name;
}

const int Pokemon::getId() const {
    return id;
}

void Pokemon::setId(const int id) {
    Pokemon::id = id;
}

const vector<string> Pokemon::getTypes() const {
    return types;
}

void Pokemon::setTypes(const vector<string> &types) {
    Pokemon::types = types;
}

const int *Pokemon::getBase_stats() const {
    return base_stats;
}

const vector<string> &Pokemon::getAbilities() const {
    return abilities;
}

void Pokemon::setAbilities(const vector<string> &abilities) {
    Pokemon::abilities = abilities;
}

int Pokemon::getGender_rate() const {
    return gender_rate;
}

void Pokemon::setGender_rate(int gender_rate) {
    Pokemon::gender_rate = gender_rate;
}

const string &Pokemon::getDescription() const {
    return description;
}

void Pokemon::setDescription(const string &description) {
    Pokemon::description = description;
}