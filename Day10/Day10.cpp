// Day10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

const char* inputData[] = {
"noop",
"noop",
"noop",
"addx 4",
"addx 1",
"addx 5",
"addx 1",
"addx 5",
"noop",
"addx -1",
"addx -6",
"addx 11",
"noop",
"noop",
"noop",
"noop",
"addx 6",
"addx 5",
"noop",
"noop",
"noop",
"addx -30",
"addx 34",
"addx 2",
"addx -39",
"noop",
"addx 5",
"addx 2",
"addx 19",
"addx -18",
"addx 2",
"addx 5",
"addx 2",
"addx 3",
"noop",
"addx 2",
"addx 3",
"noop",
"addx 2",
"addx 3",
"noop",
"addx 2",
"addx 3",
"noop",
"addx 2",
"addx -15",
"addx -22",
"noop",
"noop",
"addx 5",
"addx 2",
"noop",
"noop",
"addx 14",
"addx -11",
"addx 5",
"addx 2",
"addx 3",
"noop",
"addx 2",
"addx -16",
"addx 17",
"addx 2",
"addx 5",
"addx 2",
"addx -6",
"addx -25",
"addx 35",
"addx 1",
"addx -36",
"addx 1",
"addx 22",
"addx -19",
"addx 5",
"addx 2",
"noop",
"noop",
"addx 5",
"noop",
"noop",
"noop",
"addx 1",
"addx 4",
"noop",
"noop",
"noop",
"addx 5",
"noop",
"addx 1",
"addx 2",
"addx 3",
"addx 4",
"addx -34",
"addx 21",
"addx -24",
"addx 2",
"addx 5",
"addx 7",
"addx -6",
"addx 2",
"addx 30",
"addx -23",
"addx 10",
"addx -9",
"addx 2",
"addx 2",
"addx 5",
"addx -12",
"addx 13",
"addx 2",
"addx 5",
"addx 2",
"addx -12",
"addx -24",
"addx -1",
"noop",
"addx 3",
"addx 3",
"addx 1",
"addx 5",
"addx 21",
"addx -16",
"noop",
"addx 19",
"addx -18",
"addx 2",
"addx 5",
"addx 2",
"addx 3",
"noop",
"addx 3",
"addx -1",
"addx 1",
"addx 2",
"addx -18",
"addx 1",
"noop"
};

constexpr int numCycles = 240; //how many cycles to simulate
constexpr int numOperations = sizeof(inputData);

int currentOpIndex = 0;
int currentOpEnd = 0; //at which cycle will the current OP end
int RegisterX = 1;
int RegisterY = 1; //this is were the result of the current running OP is temp-stored

int result;

int main()
{
	for (int cycle = 1; cycle <= numCycles; ++cycle)
	{
		if(cycle >= currentOpEnd)
		{
			RegisterX = RegisterY;
			const auto currentOp = inputData[currentOpIndex];
			if(strncmp(currentOp, "addx", 4) == 0)
			{
				const int valueToAdd = atoi(currentOp + 5);
				RegisterY += valueToAdd;
				currentOpEnd = cycle + 2;
				//std::cout << cycle << ": " << "Add: " << valueToAdd << " to " << RegisterX << std::endl;
			}
			else //NOP
			{
				currentOpEnd = cycle + 1;
				//std::cout << cycle << ": " << "NOP" << " RegisterX is: " << RegisterX << std::endl;
			}
			currentOpIndex++;
		}
		if (cycle == 20 || (20 + cycle) % 40 == 0)
		{
			//std::cout << "     > " << cycle << ": " << RegisterX << std::endl;
			result += (RegisterX * cycle);
		}

		int currentPosX = cycle % 40;
		//if ((cycle - 1) % 5 == 0)
		//	std::cout << " ";
		if (currentPosX - 2<= RegisterX && currentPosX >= RegisterX)
			std::cout << "#";
		else
			std::cout << ".";
		if (currentPosX == 0)
			std::cout << std::endl;
	}

    std::cout << "Hello World!\n";
}
