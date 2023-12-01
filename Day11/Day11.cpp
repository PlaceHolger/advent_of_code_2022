// Day11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <algorithm>
#include <iostream>
#include <list>
#include <vector>

struct monkey
{
	int operationAdd = 0;
	int operationMul = 0;
	int pow = 1;
	int TestDivisor;
	int monkeyIdTrue;
	int monkeyIdFase;
	std::list<unsigned long long int> items;
	int numInspections = 0;
};

std::vector <monkey> monkeys;

constexpr bool IS_PART1 = false;

int main()
{
	monkeys.push_back(monkey{ 0, 11, 1, 5, 7, 4, {61} });  //monkey0
	monkeys.push_back(monkey{ 4, 1, 1, 2, 2, 6, {76, 92, 53, 93, 79, 86, 81} });  //monkey1
	monkeys.push_back(monkey{ 0, 19, 1, 13, 5, 0, {91, 99} });  //monkey2
	monkeys.push_back(monkey{ 0, 1, 2, 7, 6, 1, {58, 67, 66} });  //monkey3
	monkeys.push_back(monkey{ 1, 1, 1, 19, 3, 7, {94, 54, 62, 73} });  //monkey4
	monkeys.push_back(monkey{ 3, 1, 1, 11, 0, 4, {59, 95, 51, 58, 58} });  //monkey5
	monkeys.push_back(monkey{ 8, 1, 1, 3, 5, 2, {87, 69, 92, 56, 91, 93, 88, 73} });  //monkey6
	monkeys.push_back(monkey{ 7, 1, 1, 17, 3, 1, {71, 57, 86, 67, 96, 95} });  //monkey7

	constexpr int numRounds = (IS_PART1) ? 20 : 10000;
	for (int curRound = 0; curRound < numRounds; ++curRound)
	{
		for (auto& monkey : monkeys)
		{
			while (!monkey.items.empty()) //inspect and throw all the items
			{
				auto& currentItem = monkey.items.front();
				currentItem *= monkey.operationMul;
				currentItem += monkey.operationAdd;
				if(monkey.pow == 2)
					currentItem = currentItem * currentItem;
				//currentItem = pow(currentItem, monkey.pow);
				if (IS_PART1)
					currentItem /= 3; //worry level divided after inspection
				else
					currentItem %= (5 * 2 * 13 * 7 * 19 * 11 * 3 * 17); //magic-from reddit... the numbers get really big, but since all Divisors are prim-numbers, this will work
				if (currentItem % monkey.TestDivisor == 0)
					monkeys[monkey.monkeyIdTrue].items.push_back(currentItem);
				else
					monkeys[monkey.monkeyIdFase].items.push_back(currentItem);
				monkey.items.pop_front();
				monkey.numInspections++;
			}
		}
	}

	std::vector<unsigned long long int> sortedVisits;

	for (const auto& monkey : monkeys)
	{
		std::cout << monkey.numInspections << std::endl;
		sortedVisits.push_back(monkey.numInspections);
	}
	std::sort(sortedVisits.begin(), sortedVisits.end());
	std::reverse(sortedVisits.begin(), sortedVisits.end());
	std::cout << sortedVisits[0] * sortedVisits[1];
}