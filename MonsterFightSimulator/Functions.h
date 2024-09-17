#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>

void intro();

class Monstre {

public:
    Monstre(){}
    Monstre(std::string name, int vie, int att, int def, int vit);
    std::string name;
    int vie;
    int att;
    int def;
    int vit;
    void show_stat();
    int attack(Monstre m);
};

void stats_panel();

Monstre selection(int i);


#endif