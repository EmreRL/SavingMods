//
// Created by User on 31.07.2024.
//

#ifndef ROLES_H
#define ROLES_H

#include <iostream>
#include <string>
#include <vector>

class Roles {

public:
    int set_value = 0;
    int limit = 0;
    std::vector<std::string> roles;
    Roles() : roles(50) {}

};

class role_Operations : public Roles {

public:
    std::string changed_name = " ";
    std::string new_name = " ";
    void setRoles();
    void changeRoles();
    void removeRoles();
    void listRoles();
    void writeRank();
    void readRank();
    void removeRank();

};


#endif //ROLES_H
