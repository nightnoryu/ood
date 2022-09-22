#include "Beverages/Coffee/CCoffee.h"
#include "Beverages/Latte/CLatte.h"
#include "Beverages/Milkshake/CMilkshake.h"
#include "Beverages/Tea/CTea.h"
#include "Condiments/ChocolateCrumbs/CChocolateCrumbs.h"
#include "Condiments/Cinnamon/CCinnamon.h"
#include "Condiments/CoconutFlakes/CCoconutFlakes.h"
#include "Condiments/IceCubes/CIceCubes.h"
#include "Condiments/Lemon/CLemon.h"
#include "Condiments/Syrup/CSyrup.h"

#include <functional>
#include <iostream>
#include <string>

void DialogWithUser();

int main()
{
	DialogWithUser();
	std::cout << std::endl;
	{
		// Наливаем чашечку латте
		auto latte = std::make_unique<CLatte>();
		// добавляем корицы
		auto cinnamon = std::make_unique<CCinnamon>(std::move(latte));
		// добавляем пару долек лимона
		auto lemon = std::make_unique<CLemon>(std::move(cinnamon), 2);
		// добавляем пару кубиков льда
		auto iceCubes = std::make_unique<CIceCubes>(std::move(lemon), 2, IceCubeType::DRY);
		// добавляем 2 грамма шоколадной крошки
		auto beverage = std::make_unique<CChocolateCrumbs>(std::move(iceCubes), 2);

		// Выписываем счет покупателю
		std::cout << beverage->GetDescription() << " costs " << beverage->GetCost() << std::endl;
	}

	{
		auto beverage = std::make_unique<CChocolateCrumbs>( // Внешний слой: шоколадная крошка
			std::make_unique<CIceCubes>( // | под нею - кубики льда
				std::make_unique<CLemon>( // | | еще ниже лимон
					std::make_unique<CCinnamon>( // | | | слоем ниже - корица
						std::make_unique<CLatte>()), // | | |   в самом сердце - Латте
					2), // | | 2 дольки лимона
				2, IceCubeType::DRY), // | 2 кубика сухого льда
			2); // 2 грамма шоколадной крошки

		// Выписываем счет покупателю
		std::cout << beverage->GetDescription() << " costs " << beverage->GetCost() << std::endl;
	}

	// Подробнее рассмотрим работу MakeCondiment и оператора <<
	{
		// lemon - функция, добавляющая "2 дольки лимона" к любому напитку
		auto lemon2 = MakeCondiment<CLemon>(2);
		// iceCubes - функция, добавляющая "3 кусочка льда" к любому напитку
		auto iceCubes3 = MakeCondiment<CIceCubes>(3, IceCubeType::WATER);

		auto tea = std::make_unique<CTea>();

		// декорируем чай двумя дольками лимона и тремя кусочками льда
		auto lemonIceTea = iceCubes3(lemon2(std::move(tea)));
		/* Предыдущая строка выполняет те же действия, что и следующий код:
		auto lemonIceTea =
			std::make_unique<CIceCubes>(
				std::make_unique<CLemon>(
					move(tea),
					2),
				2, IceCubeType::Water);
		*/

		auto oneMoreLemonIceTea = std::make_unique<CTea>() // Берем чай
			<< MakeCondiment<CLemon>(2) // добавляем пару долек лимона
			<< MakeCondiment<CIceCubes>(3, IceCubeType::WATER); // и 3 кубика льда
		/*
		Предыдущая конструкция делает то же самое, что и следующая:
		auto oneMoreLemonIceTea =
			MakeCondiment<CIceCubes>(3, IceCubeType::Water)(
				MakeCondiment<CLemon>(2)(std::make_unique<CTea>())
				);
		*/
	}

	// Аналог предыдущего решения с добавкой синтаксического сахара
	// обеспечиваемого операторами << и функцией MakeCondiment
	{
		auto beverage = std::make_unique<CLatte>() // Наливаем чашечку латте,
			<< MakeCondiment<CCinnamon>() // оборачиваем корицей,
			<< MakeCondiment<CLemon>(2) // добавляем пару долек лимона
			<< MakeCondiment<CIceCubes>(2, IceCubeType::DRY) // бросаем пару кубиков сухого льда
			<< MakeCondiment<CChocolateCrumbs>(2); // посыпаем шоколадной крошкой

		// Выписываем счет покупателю
		std::cout << beverage->GetDescription() << " costs " << beverage->GetCost() << std::endl;
	}

	{
		auto beverage = std::make_unique<CMilkshake>() // Наливаем молочный коктейль
			<< MakeCondiment<CSyrup>(SyrupType::MAPLE) // заливаем кленовым сиропом
			<< MakeCondiment<CCoconutFlakes>(8); // посыпаем кокосовой стружкой

		// Выписываем счет покупателю
		std::cout << beverage->GetDescription() << " costs " << beverage->GetCost() << std::endl;
	}

	return EXIT_SUCCESS;
}

void DialogWithUser()
{
	std::cout << "Type 1 for coffee or 2 for tea\n";
	int beverageChoice;
	std::cin >> beverageChoice;

	std::unique_ptr<IBeverage> beverage;

	if (beverageChoice == 1)
	{
		beverage = std::make_unique<CCoffee>();
	}
	else if (beverageChoice == 2)
	{
		beverage = std::make_unique<CTea>();
	}
	else
	{
		return;
	}

	int condimentChoice;
	for (;;)
	{
		std::cout << "1 - Lemon, 2 - Cinnamon, 0 - Checkout" << std::endl;
		std::cin >> condimentChoice;

		if (condimentChoice == 1)
		{
			// beverage = std::make_unique<CLemon>(move(beverage));
			beverage = std::move(beverage) << MakeCondiment<CLemon>(2);
		}
		else if (condimentChoice == 2)
		{
			// beverage = std::make_unique<CCinnamon>(move(beverage));
			beverage = std::move(beverage) << MakeCondiment<CCinnamon>();
		}
		else if (condimentChoice == 0)
		{
			break;
		}
		else
		{
			return;
		}
	}

	std::cout << beverage->GetDescription() << ", cost: " << beverage->GetCost() << std::endl;
}
