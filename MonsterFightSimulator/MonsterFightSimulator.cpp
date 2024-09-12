// MonsterFightSimulator.cpp : This file contains the 'main' function. Program execution begins and ends there

#include <iostream>
#include "Functions.h"

int main()
{

	intro();

	int monstre1;
	int monstre2;

	//User choose both of the monsters
	std::cout << "1: Goblin \n2: Orc \n3: Troll\n";
	std::cout << "Choose the first monster.\n";
	std::cin >> monstre1;

	Monstre m1 = selection(monstre1);

	std::cout << "1: Goblin \n2: Orc \n3: Troll\n";
	std::cout << "Choose the second monster.\n";
	std::cin >> monstre2;

	Monstre m2 = selection(monstre2);

	system("cls");


	//Game loop starts
	do
	{
		std::srand(std::time(nullptr));


		//Damage done to both monsters, first the slowest and then the other one.
		if (m1.vit > m2.vit)
		{
			m2.vie -= damage_calculation(m1, m2);
			m1.vie -= damage_calculation(m2, m1);
		}
		else if (m2.vit > m1.vit)
		{
			m1.vie -= damage_calculation(m2, m1);
			m2.vie -= damage_calculation(m1, m2);
		}
		//If they have the same speed we choose randomly between the two
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
		//If one of the two monster is below 0 hp, reset to 0
		if (m1.vie < 0)
			m1.vie = 0;
		if (m2.vie < 0)
			m2.vie = 0;

		std::cin.get();
		system("cls");

	} while (m1.vie > 0 && m2.vie > 0);
}
