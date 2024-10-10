//
// Created by User on 29.07.2024.
//
#include "Mods.h"
#include <iostream>
#include <fstream>

void mod_Operations::nameSetter(std::string val) {
    name = val;
}
void mod_Operations::nickSetter(std::string val) {
    nick_name = val;
}
void mod_Operations::authoritySetter(std::string val) {
    authority = val;
}
void mod_Operations::ageSetter(int num) {
    age = num;
}

std::string mod_Operations::nameGetter() const{
    return name;
}
std::string mod_Operations::nickGetter() const{
    return nick_name;
}
std::string mod_Operations::authorityGetter() const{
    return authority;
}
int mod_Operations::ageGetter() const{
    return age;
}

void value_Operations::rankUp() {
    if(rank_num == -1) {
        std::cout << "Can't rank up the manuel one." << std::endl;
    }else {
        rank_num += 1;
        authoritySetter(val_rank.roles[rank_num]);
        std::cout << "Rank Up is succesfull !" << std::endl;
    }
}

void value_Operations::rankDown() {
    if(rank_num == -1) {
        std::cout << "Can't rank down the manuel one." << std::endl;
    }else {
        rank_num = rank_num - 1;
        authoritySetter(val_rank.roles[rank_num]);
        std::cout << "Rank Down is succesfull !" << std::endl;
    }
}

void value_Operations::getValues() {
    int num, fnum = 0, fake_num;
    std::string value, answer;
    std::cout << "Please enter the informations below" << std::endl;

    std::cout << "Name: ";
        std::cin >> value;
        nameSetter(value);

    std::cout << "Nick: ";
        std::cin >> value;
        nickSetter(value);

    std::cout << "Authority: ";
    val_rank.listRoles();
    std::cout << "\nIf you want to choose manually press 0"
              <<"\nPlease enter the role number you want to choose: ";
    std::cin >> fake_num;
    rank_num = fake_num - 1;
    if(fake_num == 0) {
        try {
            std::cout << "\nAuthority: " << std::endl;
            if(std::cin >> value) {
                authoritySetter(value);
            }else {
                throw value;
            }
        }catch(...) {
            std::cout << "\nTry Again! False given authority: " << value;
        }
    }else {
        authoritySetter(val_rank.roles[rank_num]);
    }
    std::cout << "\n## Rank Setting is done ! ##\n" << std::endl;

    std::cout << "Age: ";
        std::cin >> num;
        ageSetter(num);

    std::cout << "Fields: " << std::endl;
    while(true) {

        if(fnum == 3) {
            std::cout << "## Maximum field size is 3. ##" << std::endl;
            break;
        }else {
            std::cout << "( " << fnum+1 << " ) Field: ";
            std::cin >> fields[fnum];
            std::cout << "Do you want to continiue ? " << std::endl;
            std::cin >> answer;
            if(answer == "yes" || answer == "YES" || answer == "y" || answer == "Y") {
                fnum++;
            }else {
                break;
            }
        }

    }
    get_num = 1;
}

void value_Operations::organizeValues() {
    int num;
    std::string value, answer, answer1;
    while(true) {
        std::cout << "## What do you want to change ? ##" << std::endl;
        std::cout << "(1) Name\n"
                  << "(2) Nick\n"
                  << "(3) Authority\n"
                  << "(4) Age\n"
                  << "(5) Fields\n"
                  << "(6) Exit\n"<< std::endl;
        std::cin >> num;

        if(num == 1) {
            while(true) {
                try {
                    std::cout << "Please enter the new name: " << std::endl;
                    if(std::cin >> value) {
                        nameSetter(value);
                        break;
                    }else {
                        throw value;
                    }
                }catch(...) {
                    std::cout << "\nTry Again! False given name: " << value;
                }
            }
        }
        if(num == 2) {
            while(true) {
                try {
                    std::cout << "Please enter the new nick: " << std::endl;
                    if(std::cin >> value) {
                        nickSetter(value);
                        break;
                    }else {
                        throw value;
                    }
                }catch(...) {
                    std::cout << "\nTry Again! False given nick: " << value;
                }
            }
        }
        if(num == 3) {
            int fake_num;
            while(true) {
                    val_rank.listRoles();
                    std::cout << "\nIf you want to choose manually press 0"
                              <<"\nPlease enter the role number you want to choose: ";
                    std::cin >> fake_num;
                rank_num = fake_num - 1;
                if(fake_num == 0) {
                    try {
                        std::cout << "Please enter the new authority: " << std::endl;
                        if(std::cin >> value) {
                            authoritySetter(value);
                            break;
                        }else {
                            throw value;
                        }
                    }catch(...) {
                        std::cout << "\nTry Again! False given authority: " << value;
                    }
                }else {
                    authoritySetter(val_rank.roles[rank_num]);
                }
            }
        }
        if(num == 4) {
            while(true) {
                try {
                    std::cout << "Please enter the new age: " << std::endl;
                    if(std::cin >> num) {
                        ageSetter(num);
                        break;
                    }else {
                        throw num;
                    }
                }catch(...) {
                    std::cout << "\nTry Again! False given age: " << num;
                }
            }
        }
        if(num == 5) {
            int num1, count = 0, num2;
            while(true) {
                std::cout << "Here is your fields: " << std::endl;
                for (int i = 0; i < 3; i++) {
                    std::cout << "( " << count + 1 << " ) Field: " << fields[i] << std::endl;
                    count++;
                }
                std::cout << "Which field do you want to change: " << std::endl;
                std::cin >> num1;
                std::cout << "(1) Remove\n"
                          << "(2) Change\n" << std::endl;
                std::cin >> num2;
                if(num2 == 1) {
                    fields[num1-1] = " ";
                    break;
                }
                if(num2 == 2) {
                    while(true) {
                        try {
                            std::cout << "Please enter the new value: " << std::endl;
                            if(std::cin >> value) {
                                fields[num1-1] = value;
                                break;
                            }else {
                                throw value;
                            }
                        }catch(...) {
                            std::cout << "\nTry Again! False given age: " << value;
                        }
                    }
                }
                std::cout << "Do you want to continiue changing fields ?: " << std::endl;
                std::cin >> answer;
                if(answer == "YES" || answer == "yes" || answer == "Y" || answer == "y") {
                    std::cout << "Loading..." << std::endl;
                }else {
                    break;
                }
            }
        }
        std::cout << "Do you want to continiue changing values ?: " << std::endl;
        std::cin >> answer1;
        if(answer1 == "YES" || answer1 == "yes" || answer1 == "Y" || answer == "y") {
            std::cout << "Loading..." << std::endl;
        }else {
            break;
        }
    }
}

void value_Operations::resetValues() {
    std::string answer;
    std::cout << "Do you want to reset all values ? " << std::endl;
    std::cin >> answer;
    if(answer == "yes" || answer == "YES" || answer == "y" || answer == "Y") {
        std::cout << "Deleting everything..." << std::endl;
        nameSetter(" ");
        nickSetter(" ");
        authoritySetter(" ");
        ageSetter(0);
        std::cout << "Deleting is done !" << std::endl;
        destroy = 1;
    }else {
        std::cout << "Did not delet anything..." << std::endl;
    }
}

void value_Operations::resetValuesRegardless() {
    std::cout << "Deleting everything..." << std::endl;
    nameSetter(" ");
    nickSetter(" ");
    authoritySetter(" ");
    ageSetter(0);
    std::cout << "Deleting is done !" << std::endl;
    destroy = 1;
}

void value_Operations::listValues() {
    int count = 0;
    if(ageGetter() != 0) {
        std::cout << "Name: " << nameGetter() << std::endl;
        std::cout << "Nick: " << nickGetter() << std::endl;
        std::cout << "Authority: " << authorityGetter() << std::endl;
        std::cout << "Age: " << ageGetter() << std::endl;
        std::cout << "--------Fields--------" << std::endl;
        for(int k = 0; k < 3; k++) {
            if(fields[k] != " ") {
                std::cout << "( " << count + 1 << " ) Field: " << fields[k] << std::endl;
                count++;
            }
        }
        std::cout << "######################\n" << std::endl;
    }else {
        std::cout << "\nCan't list values before adding them!" << std::endl;
    }
}

void value_Operations::addDescription() {
    std::cout << "Please enter the description: " << std::endl;
    std::cin >> description;
}

void value_Operations::spesificMenu() {
    int input;
    while(1) {
        if(nameGetter() == " ") {
            break;
        }else {
            std::cout << "(1) " << nameGetter() << "'s Change Feature\n"
                      << "(2) " << nameGetter() << "'s Reset Mod\n"
                      << "(3) " << nameGetter() << "'s List Values\n"
                      << "(4) " << nameGetter() << "'s Rank Up\n"
                      << "(5) " << nameGetter() << "'s Rank Down\n"
                      << "(6) Back\n" << std::endl;
            std::cin >> input;
            if(input == 1) {
                organizeValues();
            }
            if(input == 2) {
                resetValues();
                break;
            }
            if(input == 3) {
                listValues();
            }
            if(input == 4) {
                rankUp();
            }
            if(input == 5) {
                rankDown();
            }
            if(input == 6) {
                std::cout << " Quitting from the window..." << std::endl;
                break;
            }
        }
    }
}

void value_Operations::createMenu() {
    int input, val1 = 0, val2 = 0;
    while(true) {
        if(val1 == 1) {
            break;
        }
        if(val1 != 1) {
            if(val2 == 1) {
                std::cout << "You have already entered the mod. " << std::endl;
                continue;
            }
            getValues();
            val1 = 1;
            val2 = 1;
        }
    }
}

void value_Operations::writeMod() {
    int count = 0;
    std::fstream file;
    file.open("maina_mods.txt", std::ios_base::app);
    if(!file) {
        std::cout << "Failed while opening the file" << std::endl;
    }else {
        if(get_num == 1) {
            file << "Name: " << nameGetter() << std::endl;
            file << "Nick: " << nickGetter() << std::endl;
            file << "Authority: " << authorityGetter() << std::endl;
            file << "Age: " << ageGetter() << std::endl;
            file << "--------Fields--------" << std::endl;
            for(int k = 0; k < 3; k++) {
                if(fields[k] != " ") {
                    file << "( " << count + 1 << " ) Field: " << fields[k] << std::endl;
                    count++;
                }
            }
            file << "######################\n" << std::endl;
        }else {
            std::cout << "Can't write mods before adding them" << std::endl;
        }
    }
    file.close();
}

void value_Operations::readMod() {
    std::string line;
    std::fstream file;
    file.open("maina_mods.txt", std::ios_base::in);
    if(!file) {
        std::cout << "Failed while opening the file" << std::endl;
    }else {
        while(!file.eof()) {
            std::getline(file, line);
            std::cout << line << std::endl;
        }
        std::cout << "\n These were the all mods !" << std::endl;
    }
}

void value_Operations::removeMod() {
    std::string answer;
    std::cout << "Are you sure about deleting all the values ?" << std::endl;
    std::cin >> answer;
    if(answer == "y" || answer == "Y" || answer == "yes" || answer == "YES") {
        std::fstream file;
        file.open("maina_mods.txt", std::ios_base::out);
        if(!file) {
            std::cout << "Failed while opening the file" << std::endl;
        }else {
            std::cout << "\nThe values deleted succesfully ! " << std::endl;
        }
        file.close();
    }
}


