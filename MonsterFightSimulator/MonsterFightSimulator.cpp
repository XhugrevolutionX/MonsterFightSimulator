// MonsterFightSimulator.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include "Functions.h"

int main()
{
	Monstre Goblin = Monstre("Goblin", 20, 4, 1, 5);
	Monstre Orc = Monstre("Orc", 30, 5, 2, 2);
	Monstre Troll = Monstre("Troll", 40, 6, 3, 1);

	Monstre m1 = Monstre("", 0, 0, 0, 0);
	Monstre m2 = Monstre("", 0, 0, 0, 0);

	int monstre1;
	int monstre2;

    std::cout << "Bienvenue au simulateur de combat de monstres.\n";
	std::cout << "Veuillez chosir le premier personnage.\n";
	std::cout << "1: Goblin \n2: Orc \n3: Troll\n";
	std::cin >> monstre1;

	switch (monstre1)
	{
		case 1:
			m1 = Goblin;
			break;
		case 2:
			m1 = Orc;
			break;
		case 3:
			m1 = Troll;
			break;
		default:
			std::cout << "valeur invalide\n";
			return 0;
	}

	std::cout << "Veuillez chosir le deuxieme personnage.\n";
	std::cout << "1: Goblin \n2: Orc \n3: Troll\n";
	std::cin >> monstre2;

	switch (monstre2)
	{
	case 1:
		m2 = Goblin;
		break;
	case 2:
		m2 = Orc;
		break;
	case 3:
		m2 = Troll;
		break;
	default:
		std::cout << "valeur invalide\n";
		return 0;
	}


	system("cls");

	do
	{
		std::srand(std::time(nullptr));

		if(m1.vit > m2.vit)
		{
			m2.vie -= damage_calculation(m1, m2);
			m1.vie -= damage_calculation(m2, m1);
		}
		else if(m2.vit > m1.vit)
		{
			m1.vie -= damage_calculation(m2, m1);
			m2.vie -= damage_calculation(m1, m2);
		}
		else
		{

			int i = (std::rand() % 2);

			switch (i)
			{
				case 0:
					m2.vie -= damage_calculation(m1, m2);
					m1.vie -= damage_calculation(m2, m1);
					break;
				case 1:
					m1.vie -= damage_calculation(m2, m1);
					m2.vie -= damage_calculation(m1, m2);
					break;
			}
		}

		if (m1.vie < 0)
			m1.vie = 0;
		if (m2.vie < 0)
			m2.vie = 0;

		m1.show_stat();
		m2.show_stat();
		std::cin.get();
		system("cls");

	} while (m1.vie > 0 && m2.vie > 0);
	
}