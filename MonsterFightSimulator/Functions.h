#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>

class Monstre {

public:
    Monstre(std::string name, int vie, int att, int def, int vit);
    std::string name;
    int vie;
    int att;
    int def;
    int vit;
    void show_stat();
};

int damage_calculation(Monstre m1, Monstre m2);

#endif