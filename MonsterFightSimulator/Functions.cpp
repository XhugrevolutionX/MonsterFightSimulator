#include "Functions.h"


Monstre::Monstre(std::string name_, int vie_, int att_, int def_, int vit_)
{
	name = name_;
	vie = vie_;
	att = att_;
	def = def_;
	vit = vit_;
}


void Monstre::show_stat()
{
	std::cout << name << "'s stats.\n";
	std::cout << "attaque :" << att << '\n';
	std::cout << "defence :" << def << '\n';
	std::cout << "vitesse :" << vit << '\n';
	std::cout << "Vie :" << vie << "\n\n";
}

int damage_calculation(Monstre m1, Monstre m2)
{
	int damage;

	damage = m1.att - m2.def;
	std::cout << m2.name << " perd " << damage << " point de vie.\n";
	return damage;
}

