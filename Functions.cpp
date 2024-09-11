#include "Functions.h"

monstre::monstre(std::string name_, int vie_, int att_, int def_, int vit_)
{
	name = name_;
	vie = vie_;
	att = att_;
	def = def_;
	vit = vit_;
}


void monstre::show_stat(monstre m)
{
	std::cout << m.name << "'s stats.\n";
	std::cout << "attaque :" << m.att << '\n';
	std::cout << "defence :" << m.def << '\n';
	std::cout << "vitesse :" << m.vit << '\n';
	std::cout << "Vie :" << m.vie << "\n\n";
}

void damage_calculation(monstre m1, monstre m2)
{ 
	if(monstre1.vit > monstre2.vit)
	{
		monstre2.vie -= monstre1.att - monstre2.def;
	}
	else
	{
		monstre1.vie -= monstre2.att - monstre1.def;
	}

}

