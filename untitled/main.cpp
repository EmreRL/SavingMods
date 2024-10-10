#include <iostream>
#include "Mods.h"
#include <vector>

class mod_List {
public:
    value_Operations mod;
};
std::vector<mod_List> mods(50);
int count = 0;

int main() {
    int input, num, p, valo = 0, role_input, mode_input;
    std::string name;
    role_Operations rank;
    while(true) {
        std::cout << "(1) Mod Operations\n"
                  << "(2) Rank Operations\n"
                  << "(3) File Operations\n"
                  << "(4) Exit\n" << std::endl;
        std::cin >> input;
        if(input == 1) {
            while(true) {
                if(valo == 1) {
                    mods[count].mod.val_rank.limit = rank.limit;
                    mods[count].mod.val_rank.roles = rank.roles;
                }
                if(valo == 0) {
                std::cout << "You have to add the ranks first !" << std::endl;
                    break;
                }else {
                std::cout << "(1) Add Mod\n"
                          << "(2) Search Mod\n"
                          << "(3) List Mods\n"
                          << "(4) Back " << std::endl;

                std::cin >> mode_input;

                if(mode_input == 1) {
                    mods[count].mod.createMenu();
                    mods[count].mod.spesificMenu();
                    if(mods[count].mod.destroy == 1) {
                        mods[count].mod = mods[count + 1].mod;
                        count--;
                    }
                    count++;
                }

                if(mode_input == 2) {
                    int k = 0;
                    std::cout << "Enter the name you want to search for: " << std::endl;
                    std::cin >> name;
                    while(true) {
                        if(name == mods[k].mod.nameGetter()) {
                            std::cout << "Found the mod!" << std::endl;
                            while(true) {
                                mods[k].mod.spesificMenu();
                                if(mods[k].mod.destroy == 1) {
                                    for(k; k < count; k++) {
                                        mods[k].mod = mods[k + 1].mod;
                                    }
                                    count--;
                                    std::cout << "Deleting is done !" << std::endl;
                                }
                                break;
                            }
                            break;
                        }
                        if(k == count && name != mods[k].mod.nameGetter()) {
                            std::cout << "Couldn't find the mod you are looking for" << std::endl;
                            break;
                        }else {
                            k++;
                        }
                    }
                }

                if(mode_input == 3) {
                    std::cout << "Listing values..." << std::endl;
                    for(p = 0; p < count; p++) {
                        std::cout << "----------------------" << std::endl;
                        std::cout << " " << p+1 << ". MOD\n" << std::endl;
                        mods[p].mod.listValues();
                        if(p + 1 == count) {
                            std::cout << "--> Listing is done ! <--\n" << std::endl;
                        }
                    }
                }

                if(mode_input == 4) {
                    break;
                }

            }
            }
        }
        if(input == 2) {
            while(true) {
                std::cout << "(1) Add Roles\n"
                          << "(2) Reset Roles\n"
                          << "(3) Edit Roles\n"
                          << "(4) List Roles\n"
                          << "(5) Back" << std::endl;
                std::cin >> role_input;
                if(role_input == 1) {
                    rank.setRoles();
                    mods[count].mod.val_rank.limit = rank.limit;
                    mods[count].mod.val_rank.roles = rank.roles;
                    valo = 1;
                }
                if(role_input == 2) {
                    std::string is_reset;
                    if(valo != 1) {
                        std::cout << "Can't reset roles before adding them." << std::endl;
                    }else {
                        mods[count].mod.val_rank.removeRoles();
                        rank.roles = mods[count].mod.val_rank.roles;
                        rank.limit = mods[count].mod.val_rank.limit;
                        valo = 0;
                        if(count != 0) {
                            std::cout << "Do you want to reset all mods too ?";
                            std::cin >> is_reset;
                            if(is_reset == "y" || is_reset == "Y" || is_reset == "yes" || is_reset == "YES") {
                                for(int i = 0; i < count; i++) {
                                    mods[i].mod.resetValuesRegardless();
                                }
                                count = 0;
                                std::cout << "\nReseting mods is done !" << std::endl;
                            }else {
                                std::cout << "\nReseting ranks is done !" << std::endl;
                            }
                        }
                    }
                }
                if(role_input == 3) {
                    if(valo != 1) {
                        std::cout << "Can't change roles before adding them." << std::endl;
                    }else {
                        mods[count].mod.val_rank.changeRoles();
                        rank.roles = mods[count].mod.val_rank.roles;
                        rank.limit = mods[count].mod.val_rank.limit;
                        rank.changed_name = mods[count].mod.val_rank.changed_name;
                        rank.new_name = mods[count].mod.val_rank.new_name;
                        if(mods[count].mod.val_rank.changed_name != " ") {
                            for(int i = 0; i <= count; i++) {
                                if(mods[i].mod.authorityGetter() == rank.changed_name) {
                                    mods[i].mod.authoritySetter(rank.new_name);
                                }
                            }
                        }
                     }
               }
                if(role_input == 4) {
                    if(valo != 1) {
                        std::cout << "Can't list roles before adding them." << std::endl;
                    }else {
                        mods[count].mod.val_rank.listRoles();
                    }
                }
                if(role_input == 5) {
                    break;
                }
            }
        }
        if(input == 3) {
            int input1, input2, input3;
            int i;
                while(true) {
                    std::cout << "(1) Mod Files\n"
                              << "(2) Rank Files\n"
                              << "(3) Back" << std::endl;
                    std::cin >> input1;
                    if(input1 == 1) {
                        while(true) {
                            std::cout << "(1) Write Mods\n"
                                      << "(2) Show Mods\n"
                                      << "(3) Remove Mods\n"
                                      << "(4) Back" << std::endl;
                            std::cin >> input2;
                            if(input2 == 1) {
                                if(valo == 0) {
                                    std::cout << "You have to add the ranks first !" << std::endl;
                                }
                                else if(count == 0) {
                                    std::cout << "You have to add the ranks first !" << std::endl;
                                }
                                else {
                                    for(i = 0; i < count; i++) {
                                        mods[i].mod.writeMod();
                                    }
                                    std::cout << "Values writed succesfully !" << std::endl;
                                }
                            }
                            if(input2 == 2) {
                                mods[i].mod.readMod();
                            }
                            if(input2 == 3) {
                                mods[0].mod.removeMod();
                                std::cout << "Mods removed succesfully !" << std::endl;
                            }
                            if(input2 == 4) {
                                break;
                            }
                        }
                    }
                    if(input1 == 2) {
                        while(true) {
                            std::cout << "(1) Write Ranks\n"
                                      << "(2) Show Ranks\n"
                                      << "(3) Remove Ranks\n"
                                      << "(4) Back" << std::endl;
                            std::cin >> input3;
                            if(input3 == 1) {
                                if(valo == 0) {
                                    std::cout << "You have to add the ranks first !" << std::endl;
                                }else {
                                    mods[0].mod.val_rank.writeRank();
                                    std::cout << "Ranks writed succesfully !" << std::endl;
                                }
                            }
                            if(input3 == 2) {
                                mods[i].mod.val_rank.readRank();
                            }
                            if(input3 == 3) {
                                mods[0].mod.val_rank.removeRank();
                                std::cout << "Ranks removed succesfully !" << std::endl;
                            }
                            if(input3 == 4) {
                                break;
                            }
                        }
                    }
                    if(input1 == 3) {
                        break;
                    }
                }
        }
        if(input == 4) {
            break;
        }
    }
}
