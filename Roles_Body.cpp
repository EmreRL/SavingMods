//
// Created by User on 31.07.2024.
//
#include "Roles.h"
#include <fstream>
#include <string>

void role_Operations::setRoles() {

    int i = 0;
    set_value = 1;
    std::string answer;
    std::cout << "!!! Please enter the roles by low to high authority order !!!" << std::endl;

    while(true) {
        std::cout << "( " << limit + 1 << " ) Role: " << std::endl;
        std::cin >> roles[limit];
        std::cout << "Do you want to continiue adding roles ?" << std::endl;
        std::cin >> answer;
        if(answer == "yes" || answer == "YES" || answer == "y" || answer == "Y") {
            limit++;
        }else {
            break;
        }
    }
}

void role_Operations::changeRoles() {

    int input, a;
    std::string answer;
    while(true) {
        std::cout << "Here is the all roles in order low to high authority" << std::endl;
        for(int i = 0; i <= limit; i++) {
            std::cout << "( " << i + 1 << " ) Rank: " << roles[i] << std::endl;
        }
        std::cout << "Which rank do you want to change ?: " << std::endl;
        std::cin >> input;
        std::cout << "(1) Remove\n"
                  << "(2) Change\n"
                  << "(3) Back" << std::endl;
        std::cin >> a;
        if(a == 1) {
            std::cout << "Deleting the role you want..." << std::endl;
            for(input; input <= limit + 1; input++) {
                roles[input - 1] = roles[input];
            }
            limit--;
            std::cout << "Role removed succesfully !" << std::endl;
            }
        if(a == 2) {
            std::cout << "\nYou chose: " << roles[input - 1] << std::endl;
            changed_name = roles[input - 1];
            std::cout << "Please enter the new name: ";
            std::cin >> roles[input - 1];
            new_name = roles[input - 1];
        }
        if(a == 3) {
            break;
        }
        std::cout << "Do you want to keep changing roles?: ";
        std::cin >> answer;
        std::cout << "\n";
        if(answer == "yes" || answer == "YES" || answer == "y" || answer == "Y") {
        }else {
            break;
        }
    }
}

void role_Operations::removeRoles() {
    std::string answer;
    while(true) {
        std::cout << "Do you want to delet all roles?: ";
        std::cin >> answer;
        if(answer == "yes" || answer == "YES" || answer == "y" || answer == "Y") {
            std::cout << "Deleting all roles... " << std::endl;
            for(int i = 0; i <= limit; i++) {
                roles[i] = " ";
            }
            limit = 0;
            break;
        }else {
            break;
        }
    }
}

void role_Operations::listRoles() {
    std::cout << "Listing roles..." << std::endl;
    if(roles[0] == " ") {
        std::cout << "There is no role to show !" << std::endl;
    }else {
        for(int i = 0; i<=limit; i++) {
            std::cout << "( " << i + 1 << " ) Rank: " << roles[i] << std::endl;
        }
        std::cout << "\n Listing is done !" << std::endl;
    }
}

void role_Operations::writeRank() {
    std::fstream file;
    file.open("maina_ranks.txt", std::ios_base::app);
    if(!file) {
        std::cout << "Failed while opening the file" << std::endl;
    }else {
        for(int i = 0; i <= limit; i++) {
            file << roles[i] << std::endl;
        }
        std::cout << "All ranks saved succesfully !" << std::endl;
    }
    file.close();
}

void role_Operations::readRank() {
    std::string line;
    std::fstream file;
    file.open("maina_ranks.txt", std::ios_base::in);
    if(!file) {
        std::cout << "Failed while opening the file" << std::endl;
    }else {
        while(!file.eof()) {
            std::getline(file, line);
            std::cout << line << std::endl;
        }
        std::cout << "\n These were the all ranks !" << std::endl;
    }
}

void role_Operations::removeRank() {
    std::string answer;
    std::cout << "Are you sure about deleting all the values ?" << std::endl;
    std::cin >> answer;
    if(answer == "y" || answer == "Y" || answer == "yes" || answer == "YES") {
        std::fstream file;
        file.open("maina_ranks.txt", std::ios_base::out);
        if(!file) {
            std::cout << "Failed while opening the file" << std::endl;
        }else {
            std::cout << "\nThe values deleted succesfully ! " << std::endl;
        }
        file.close();
    }
}







