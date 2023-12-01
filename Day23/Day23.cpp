// Day23.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

//#define TESTDATA
#include "Day23Data.h"

constexpr bool isPart2 = false;

constexpr int SPACE_AROUND_PLAYFIED = (isPart2) ? 64 : 8;

enum eDirection : uint8_t
{
	North = 0,
	South = 1,
	West = 2,
	East = 3,
	COUNT = 4,
	UNDEFINED = 0xff,
};

//this map holds, where currently an elf is standing (1) and which fields are free (0).
bool playfield[g_DataHeight + 2 * SPACE_AROUND_PLAYFIED][g_DataWidth + 2 * SPACE_AROUND_PLAYFIED] = { { false } };
eDirection plannedMoveDir[g_DataHeight + 2 * SPACE_AROUND_PLAYFIED][g_DataWidth + 2 * SPACE_AROUND_PLAYFIED] = { { UNDEFINED } };
//this map holds for every field, how many elves do want to go there (plannend during Phase 1, in Phase 2 its used to check, if its possible)
uint8_t plannedMoveTargets[g_DataHeight + 2 * SPACE_AROUND_PLAYFIED][g_DataWidth + 2 * SPACE_AROUND_PLAYFIED] = { { 0 } };

eDirection g_CurMoveDir = North;

int g_NumMovesCounter = -1;

void IncrementMoveDir()
{
	g_CurMoveDir = (eDirection)((g_CurMoveDir + 1) % eDirection::COUNT);
}

eDirection FindElfMoveDir(int posX, int posY)
{
	int occupiedFields = 0;
	for (int y = -1; y <= 1; ++y)
	{
		for (int x = -1; x <= 1; ++x)
		{
			occupiedFields += playfield[posY + y][posX + x] ? 1 : 0;
		}
	}
	if (occupiedFields == 1) //only ours
		return UNDEFINED; //no need to move, there is no-one nearby	

	for (int i = 0; i < eDirection::COUNT; ++i)
	{
		const int curDirToCheck = (g_CurMoveDir + i) % eDirection::COUNT;
		if (curDirToCheck == North)
		{
			//check if fields above us are free
			if (!playfield[posY - 1][posX - 1] && !playfield[posY - 1][posX] && !playfield[posY - 1][posX + 1])
				return North;
		}
		else if (curDirToCheck == South)
		{
			//check if fields below us are free
			if (!playfield[posY + 1][posX - 1] && !playfield[posY + 1][posX] && !playfield[posY + 1][posX + 1])
				return South;
		}
		else if (curDirToCheck == West)
		{
			//check if fields left of us are free
			if (!playfield[posY][posX - 1] && !playfield[posY - 1][posX - 1] && !playfield[posY + 1][posX - 1])
				return West;
		}
		else if (curDirToCheck == East)
		{
			//check if fields right of us are free
			if (!playfield[posY][posX + 1] && !playfield[posY - 1][posX + 1] && !playfield[posY + 1][posX + 1])
				return East;
		}
	}
	return UNDEFINED;
}

void ElfPlanMove(int posX, int posY)
{
	const eDirection moveDir = FindElfMoveDir(posX, posY);
	switch (moveDir)
	{
	case North:
		plannedMoveTargets[posY - 1][posX]++;
		break;
	case South:
		plannedMoveTargets[posY + 1][posX]++;
		break;
	case West:
		plannedMoveTargets[posY][posX - 1]++;
		break;
	case East:
		plannedMoveTargets[posY][posX + 1]++;
		break;
	default:
		return; //nothing free. we dont move at all
	}
	plannedMoveDir[posY][posX] = moveDir;
}

void ElfExecuteMove(int posX, int posY)
{
	const int moveDir = plannedMoveDir[posY][posX];
	if (moveDir != UNDEFINED)
		g_NumMovesCounter++;
	switch (moveDir)
	{
	case North:
		if (plannedMoveTargets[posY - 1][posX] == 1) //no one else planned to go there
		{
			playfield[posY][posX] = false; //free our current location
			playfield[posY - 1][posX] = true; //occupy our new location
		}
		break;
	case South:
		if (plannedMoveTargets[posY + 1][posX] == 1) //no one else planned to go there
		{
			playfield[posY][posX] = false; //free our current location
			playfield[posY + 1][posX] = true; //occupy our new location
		}
		break;
	case West:
		if (plannedMoveTargets[posY][posX - 1] == 1) //no one else planned to go there
		{
			playfield[posY][posX] = false; //free our current location
			playfield[posY][posX - 1] = true; //occupy our new location
		}
		break;
	case East:
		if (plannedMoveTargets[posY][posX + 1] == 1) //no one else planned to go there
		{
			playfield[posY][posX] = false; //free our current location
			playfield[posY][posX + 1] = true; //occupy our new location
		}
		break;
	}
}

void DrawPlayfield()
{
	system("cls");
	for (int y = 0; y < g_DataHeight + 2 * SPACE_AROUND_PLAYFIED; ++y)
	{
		std::cout << y << "\t";
		for (int x = 0; x < g_DataWidth + 2 * SPACE_AROUND_PLAYFIED; ++x)
		{
			if (playfield[y][x])
				std::cout << "#";
			else
				std::cout << ".";
		}
		std::cout << "\n";
	}
}

int main()
{
	//copy startstate into our playfield
	for (int y = 0; y < g_DataHeight; ++y)
	{
		for (int x = 0; x < g_DataWidth; ++x)
		{
			playfield[y + SPACE_AROUND_PLAYFIED][x + SPACE_AROUND_PLAYFIED] = g_InputData[y][x] == '#';
		}
	}

	int iteration = 0;
	int maxIteration = (isPart2) ? 1000000 : 10;
	for (; iteration < maxIteration; ++iteration)
	{
		//DrawPlayfield();
		if (g_NumMovesCounter == 0)
			break;
		g_NumMovesCounter = 0;
		memset(plannedMoveTargets, 0, sizeof(plannedMoveTargets));
		memset(plannedMoveDir, eDirection::UNDEFINED, sizeof(plannedMoveDir));

		for (int y = 0; y < g_DataHeight + 2 * SPACE_AROUND_PLAYFIED; ++y)
		{
			for (int x = 0; x < g_DataWidth + 2 * SPACE_AROUND_PLAYFIED; ++x)
			{
				if (playfield[y][x])
					ElfPlanMove(x, y);
			}
		}

		for (int y = 0; y < g_DataHeight + 2 * SPACE_AROUND_PLAYFIED; ++y)
		{
			for (int x = 0; x < g_DataWidth + 2 * SPACE_AROUND_PLAYFIED; ++x)
			{
				if (playfield[y][x])
					ElfExecuteMove(x, y);
			}
		}
		IncrementMoveDir();
	}
	DrawPlayfield();


	//Find Minimum Rect
	int minX = 100;
	int minY = 100;
	int maxX = -100;
	int maxY = -100;

	for (int y = 0; y < g_DataHeight + 2 * SPACE_AROUND_PLAYFIED; ++y)
	{
		for (int x = 0; x < g_DataWidth + 2 * SPACE_AROUND_PLAYFIED; ++x)
		{
			if (playfield[y][x]) //found elf, check if limit
			{
				if (minX > x)
					minX = x;
				if (minY > y)
					minY = y;
				if (maxX < x)
					maxX = x;
				if (maxY < y)
					maxY = y;
			}
		}
	}
	//count free spaces
	int numFreeSpaces = 0;
	for (int y = minY; y <= maxY; ++y)
	{
		for (int x = minX; x <= maxX; ++x)
		{
			if (!playfield[y][x]) //found free space, count it
				numFreeSpaces++;
		}
	}

	std::cout << "Free Spaces in minRect: " << numFreeSpaces << " Finished in Round: " << iteration;
	return 0;
}


