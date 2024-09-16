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
};

void stats_panel();

Monstre selection(int i);


int damage_calculation(Monstre m1, Monstre m2);

#endif