//
// Created by User on 29.07.2024.
//

#ifndef MODS_H
#define MODS_H

#include <iostream>
#include <string>
#include <vector>
#include "Roles.h"

class Mods {

public:
    std::string name;
    std::string nick_name;
    std::string authority;
    int age;

};
class mod_Operations : private Mods{

public:
    int destroy = 0;
    std::string description;
    void nameSetter(std::string);
    void nickSetter(std::string);
    void authoritySetter(std::string);
    void ageSetter(int);

    std::string nameGetter() const;
    std::string nickGetter() const;
    std::string authorityGetter() const;
    int ageGetter() const;

    std::vector<std::string> fields;
    mod_Operations() : fields(10, " ") {}

};

class value_Operations : public mod_Operations {

public:
    int rank_num = 0, get_num = 0;
    role_Operations val_rank;
    void getValues();
    void resetValuesRegardless();
    void organizeValues();
    void resetValues();
    void listValues();
    void addDescription();
    void createMenu();
    void spesificMenu();
    void rankUp();
    void rankDown();
    void writeMod();
    void readMod();
    void removeMod();

};

#endif //MODS_H
