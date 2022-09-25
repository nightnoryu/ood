#include "CCoffeeShop.h"
#include "Beverages/Cappuccino/CCappuccino.h"
#include "Beverages/Latte/CLatte.h"
#include "Beverages/Milkshake/CMilkshake.h"
#include "Beverages/Tea/CTea.h"
#include "Condiments/ChocolateCrumbs/CChocolateCrumbs.h"
#include "Condiments/Cinnamon/CCinnamon.h"
#include "Condiments/Cream/CCream.h"
#include "Condiments/Lemon/CLemon.h"
#include <iostream>

void CCoffeeShop::Start()
{
	std::cout << "Welcome to the VA-11 Hall-B coffee shop! What would you like?\n";

	if (!SelectBeverage())
	{
		std::cout << "Sorry, we don't serve this here\n";
		return;
	}

	std::cout << "Your drink is coming right up.\n"
				 "We have a wide variety of different condiments, feel free to pick anything you like\n";
	for (;;)
	{
		if (SelectCondiment())
		{
			std::cout << "And.. done! Anything else?\n";
		}
		else
		{
			break;
		}
	}

	std::cout << "I guess that's all for now. Here's your beverage, enjoy!\n"
			  << m_beverage->GetDescription()
			  << "\nThat'll will be " << m_beverage->GetCost() << " rubles\n"
			  << "Visit us again!" << std::endl;
}

bool CCoffeeShop::SelectBeverage()
{
	int userChoice;

	std::cout << "1 - Cappuccino\n2 - Latte\n3 - Milkshake\n4 - Tea\n> ";
	std::cin >> userChoice;

	switch (userChoice)
	{
	case 1:
		return SelectCappuccino();
	case 2:
		return SelectLatte();
	case 3:
		return SelectMilkshake();
	case 4:
		return SelectTea();
	default:
		return false;
	}
}

bool CCoffeeShop::SelectCappuccino()
{
	int userChoice;

	std::cout << "1 - Standard, 2 - Double\n> ";
	std::cin >> userChoice;

	switch (userChoice)
	{
	case 1:
		m_beverage = std::make_unique<CCappuccino>(CoffeePortion::Standard);
		return true;
	case 2:
		m_beverage = std::make_unique<CCappuccino>(CoffeePortion::Double);
		return true;
	default:
		return false;
	}
}

bool CCoffeeShop::SelectLatte()
{
	int userChoice;

	std::cout << "1 - Standard, 2 - Double\n> ";
	std::cin >> userChoice;

	switch (userChoice)
	{
	case 1:
		m_beverage = std::make_unique<CLatte>(CoffeePortion::Standard);
		return true;
	case 2:
		m_beverage = std::make_unique<CLatte>(CoffeePortion::Double);
		return true;
	default:
		return false;
	}
}

bool CCoffeeShop::SelectMilkshake()
{
	int userChoice;

	std::cout << "1 - Small, 2 - Standard, 3 - Grand\n> ";
	std::cin >> userChoice;

	switch (userChoice)
	{
	case 1:
		m_beverage = std::make_unique<CMilkshake>(MilkshakePortion::Small);
		return true;
	case 2:
		m_beverage = std::make_unique<CMilkshake>(MilkshakePortion::Standard);
		return true;
	case 3:
		m_beverage = std::make_unique<CMilkshake>(MilkshakePortion::Grand);
		return true;
	default:
		return false;
	}
}

bool CCoffeeShop::SelectTea()
{
	int userChoice;

	std::cout << "1 - Black, 2 - Green, 3 - Thyme, 4 - Karkade\n> ";
	std::cin >> userChoice;

	switch (userChoice)
	{
	case 1:
		m_beverage = std::make_unique<CTea>(TeaType::Black);
		return true;
	case 2:
		m_beverage = std::make_unique<CTea>(TeaType::Green);
		return true;
	case 3:
		m_beverage = std::make_unique<CTea>(TeaType::Thyme);
		return true;
	case 4:
		m_beverage = std::make_unique<CTea>(TeaType::Karkade);
		return true;
	default:
		return false;
	}
}

bool CCoffeeShop::SelectCondiment()
{
	int userChoice;

	std::cout << "1 - Chocolate crumbs\n2 - Chocolate slices\n3 - Cinnamon\n"
				 "4 - Coconut flakes\n5 - Cream\n6 - Ice cubes\n"
				 "7 - Lemon\n8 - Liqueur\n9 - Syrup\n10 - That's all\n> ";
	std::cin >> userChoice;

	switch (userChoice)
	{
	case 1:
		return AddChocolateCrumbs();
	case 2:
		return AddChocolateSlices();
	case 3:
		m_beverage = std::move(m_beverage) << MakeCondiment<CCinnamon>();
		return true;
	case 4:
		return AddCoconutFlakes();
	case 5:
		m_beverage = std::move(m_beverage) << MakeCondiment<CCream>();
		return true;
	case 6:
		return AddIceCubes();
	case 7:
		return AddLemon();
	case 8:
		return AddLiqueur();
	case 9:
		return AddSyrup();
	default:
		return false;
	}
}

bool CCoffeeShop::AddChocolateCrumbs()
{
	return false;
}

bool CCoffeeShop::AddChocolateSlices()
{
	return false;
}

bool CCoffeeShop::AddCoconutFlakes()
{
	return false;
}

bool CCoffeeShop::AddIceCubes()
{
	return false;
}

bool CCoffeeShop::AddLemon()
{
	return false;
}

bool CCoffeeShop::AddLiqueur()
{
	return false;
}

bool CCoffeeShop::AddSyrup()
{
	return false;
}
