// BankStimulation.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include "stdafx.h"
#include "Bank.h"


int main()
{
	Bank Bank0(5);
	Bank0.transaction();
	std::cout << "Bank0 total money: " << Bank0.getTotalMoney() << std::endl;

	Bank Bank1(10);
	Bank1.transaction();
	std::cout <<"Bank1 total money: " <<Bank1.getTotalMoney() << std::endl;

	system("pause");
	return 0;
}

