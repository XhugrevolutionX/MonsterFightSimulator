#include "Functions.h"



Monstre::Monstre(std::string name_, int vie_, int att_, int def_, int vit_)
{
	name = name_;
	vie = vie_;
	att = att_;
	def = def_;
	vit = vit_;
}

Monstre Goblin = Monstre("Goblin", 100, 40, 20, 10);
Monstre Orc = Monstre("Orc", 300, 50, 20, 4);
Monstre Troll = Monstre("Troll", 400, 60, 30, 2);

void Monstre::show_stat()
{
	std::cout << name << "'s stats.\n";
	std::cout << "Attack :" << att << '\n';
	std::cout << "Defence :" << def << '\n';
	std::cout << "Speed :" << vit << '\n';
	std::cout << "Health :" << vie << "\n\n";
}

Monstre selection(int i)
{

	Monstre m = Monstre("", 0, 0, 0, 0);

	switch (i)
	{
	case 1:
		m = Goblin;
		break;
	case 2:
		m = Orc;
		break;
	case 3:
		m = Troll;
		break;
	default:
		std::cout << "Invalid choice\n";
		return m;
	}
}

int damage_calculation(Monstre m1, Monstre m2)
{
	int damage;

	damage = m1.att - m2.def;
	std::cout << m2.name << " loses " << damage << " health.\n";
	m2.show_stat();
	return damage;
}

void intro()
{
	char reponse;
	std::cout << "Welcome to Monster fight simulator\nYou will have to choose 2 monster that will fight each other\n";

	std::cin.get();
	system("cls");

	std::cout << "You have the choice between 3 different beasts\n\n";
	std::cout << "First is the Goblin, a small and fast creature\n\nSecond is the Orc, an average size beast with a thrust worthy stick to smack people with\n\nThird is the Troll, an enormous monster the size of a mountains\n\n";
	std::cout << "If you want ot see their stats press S, if you want to begin the game press any other letter\n";

	std::cin >> reponse;

	if (reponse == 'S' || reponse == 's')
		stats_panel();
	else
		system("cls");

	
}

void stats_panel()
{
	system("cls");
	Goblin.show_stat();
	Orc.show_stat();
	Troll.show_stat();
	std::cin.get();
	std::cin.get();
	system("cls");
}