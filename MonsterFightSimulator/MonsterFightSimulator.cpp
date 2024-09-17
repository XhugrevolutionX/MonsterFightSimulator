// MonsterFightSimulator.cpp : This file contains the 'main' function. Program execution begins and ends there

#include <iostream>
#include "Functions.h"

int main()
{

	intro();

	int reponse;
	int round = 0;
	Monstre m1;
	Monstre m2;

	//User choose both of the monsters
	while (true)
	{
		std::cout << "1: Goblin \n2: Orc \n3: Troll\n";
		std::cout << "Choose the first monster.\n";
		std::cin >> reponse;

		if (reponse == 1 || reponse == 2 || reponse == 3)
		{
			m1 = selection(reponse);
			break;
		}
		else
		{
			std::cout << "Invalid choice\n";
		}
	}

	while (true)
	{
		std::cout << "1: Goblin \n2: Orc \n3: Troll\n";
		std::cout << "Choose the second monster.\n";
		std::cin >> reponse;

		if (reponse == 1 || reponse == 2 || reponse == 3)
		{
			m2 = selection(reponse);
			break;
		}
		else
		{
			std::cout << "Invalid choice\n";
		}
	}

	system("cls");


	//Game loop starts
	do
	{
		std::srand(std::time(nullptr));


		//Damage done to both monsters, first the slowest and then the other one.
		if (m1.vit > m2.vit)
		{
			m2.vie -= m1.attack(m2);
			m1.vie -= m2.attack(m1);
		}
		else if (m2.vit > m1.vit)
		{
			m1.vie -= m2.attack(m1);
			m2.vie -= m1.attack(m2);
		}
		//If they have the same speed we choose randomly between the two
		else
		{
			int i = (std::rand() % 2);

			switch (i)
			{
			case 0:
				m2.vie -= m1.attack(m2);
				m1.vie -= m2.attack(m1);
				break;
			case 1:
				m1.vie -= m2.attack(m1);
				m2.vie -= m1.attack(m2);
				break;
			}
		}
		//If one of the two monster is below 0 hp, reset to 0
		if (m1.vie < 0)
			m1.vie = 0;
		if (m2.vie < 0)
			m2.vie = 0;

		std::cout << "\n";
		m1.show_stat();
		m2.show_stat();

		std::cin.get();
		system("cls");

		round++;

	} while (m1.vie > 0 && m2.vie > 0);
	if (m1.vie == 0)
	{
		std::cout << m2.name << " wins in " << round << " rounds";
	}
	else
	{
		std::cout << m1.name << " wins in " << round << " rounds";
	}
		

}
