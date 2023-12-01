// Day17.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

constexpr char inputJetStreams[] =
//{ ">>><<><>><<<>><>>><<<>>><<<><<<>><>><<>>" };
{">>>><<>>>><<><<<>>><<<>><<>>><<>>>><<<>>><<<>><<<<>>>><<<<>>>><<<>>>><<<<><><>>><<<<>><>>>><<<><<<>><<<<><>><<><<<<>>><>>>><>><>><<><<<><<<<>>><<<>><<<<><<<<>><<<<>><<>><<><>><>>>><><<<><>>><>>><<<><<<<>><<>>>><<<><<<>>><<<<>>><<<>><<>><<<>>><<<>><<<<>>><>><<<<>>>><<<<>>><>>>><>><>>>><<<<><>>><<<<>>><><<<<><<<><>>><<>>>><<<<>>>><<<>><<<<>>><><<>>><<><<><<>>><<<<>>><<<<>>><<<<><<<><<<><<>><<>><><<<><<>>>><<>><<>>>><<<<><<<<>><<<>>>><<>>>><<<<>>><<>><<><<<>>>><<><<>>><<<>><>>><>><<<<>>>><>><><<<<>>><>>><<>>>><<<><>>><>>><<<>><<>>>><<><<>>>><>><>>><<<>><<<>><<<>>><<<<><<<<>>><<>>><<>>>><>><>><<<>>>><<<<>>><<><<>><<>><<<<>>><<>>>><<>>><<<<>>>><>><<<>><>>><<>><<>>>><>><<>>><<<<><<<>>><<<<>>><>>>><<<><<<>>><<<>><<<>><<<<>>><>>><><>><>><>><<<><>>><<<>>><><<<<><<<>>>><><>>>><<>>>><<<>>><<<<>>><<>>>><<<><<>>>><>>><<<><>>>><<<<>><<<><<<>>><<<><<><<>>><<<>><<<><<<<>>><<>><<>>><>><><<<><<><>>><<<>><<>><<<><<<>><<<<><>><<<>>>><<<<>>>><>><<<<>>>><<<<>>><<<><<>><<>><<<><<<<><<<>>>><<><<<>>><<<<><<<><<<<>><<<<><>><<<<>>>><>><<<<><<<<>>><<<<>><<<<>>><<<<>><<>>>><<><<<><>>>><<<<><<<>>>><<>>>><<>>><<<<>><><<<>>>><<>>><>>><<<<>><<><<>>><>>>><>><<<>>>><<<<>>>><<<<>>>><<<>>><><<<><>><<<>>><<<><<<>>>><<<<><<<>>><<<<><<><>>><<<>><<<>>><<<<>>><<<<><<<>><>>>><<<>><>><<<<>><<>><>>>><>>>><<>><<>>>><<<<>>><<<>>><<><<<>>><<>><<<<>>>><<<>><<<<>><><>>><<<<>>><<<>>>><><>>>><<<<>>><<<<>><<<>>><>>><<<><><<>>><>>><<<<>><<<>>>><><<<<>><<>>><<<><<<<><<<><<<><>><<<>>><<<><<>><>><<<<>><<<<>>><<>><<<<>><<><<><<<<>>><<<>><<<>>>><>>><<>><<<<>><<<<>>><<<><>>>><<<>>><<<<><<<<>>>><<><<<<><<<>>>><<>>><>><<>><<<<>>>><><<<<>><<<>><<<><>>><<<<>>><<>>>><><<>>>><<<<>>><<<>>>><<<><<<<>>><<<<>>>><<<><<<>>>><><>><>><<>><<<>>><>>>><>><<>>><<>>>><<<>>>><<<>>>><<<>>>><<<<>>><>>>><<<><<<<>>>><>><<<><<<>>><<>>><<<<>><<<<>>>><>>>><<>>><<><>><>>><<<>>>><<<>>><<<>><<<>>>><<>><<<<>>><<<>>><<<<>><<<<>>><<>><<<>><<<>>><<>>>><>><<>><<<<>>>><<>>>><><<<>>><><><<>>>><<<>><><<><<<<>>>><<<<>><<<<>><><<<<>>>><><<><>>>><>><><>>>><<<<>>><<<<><<>><<<<><<><>>>><<>><>><>>><<><<><<>><<>>>><<<<>>>><>><<<<>>>><<<>><<<><<<>><<<<>><>><<>>><>><>>><<<>>><<<>><<<<>>><<>>><<<<>>><<><>>>><<<<><<<><><<>>><<<<>><<<<>>><<<<>>><<>>><<<<><>>><>>>><<<<>><<<>>>><><<<<><>>><<<<>>><<<>>>><<<>>><<<<>>>><<<<><>><>>><<>>><<<><<<><<<><<<><<>>><<>><<>><<>>>><><<<>>><<><<<<><<<<>><<<>>>><<>><<>>><<<<>><<<>><<<<>>>><<<<>>>><>><<><<<>><<<>>><<>><>>><<>>>><<<>>><><<>>>><<>>>><<<>>>><<<<>>><<>>><<<<><<<<><>>><><<<<>><<<<>>><<>>><>>><<>>>><<<<>><<<><<>><>>>><<<>>><<<<>><<<<><<<<>>>><<<><<<>><<>>>><<<>><>>>><<<>>>><<<<>>>><<<><<<><<<<>>><<>>><<<>>>><<>>>><<<>>><<><>>>><<<>><>>>><<<<><<<<>>><>>><>>>><><<<>>>><<>>><>>><<<<>><<>>><<<><<<<>><<<>>>><<<<><<<<>>>><<<<>><>>><<>>>><<<>>><>>>><>>><<<<>>><<<>>><<<><<>>><>>>><<>>><<>>><<>>><<<>>><<<<>>><>><<<>>><<<<>>><<<>><<<>><<><>><<>><<<<>>><<<>>>><<>>><<>>><<>>><<>><<<>>><<<<>>><<<<>>><<><<<>>><<>><>><<<<>>><>>><<<>>><<<><<<<>>><<<>>><>>>><<<>><<<<><>>><<<>>><<<<>><<<>>>><<>>>><><<<<>>>><<<<>>>><>>><<<>>><<<<><>><<>>>><><>><<<<>>><<<<>>><<>>>><<<<>>><<<>>>><>><<<<>>>><<><<><<<<>><<<<>><<<<>><<<<>>><<>><<<<><<><<>><<<>>>><<<>>>><>>><<>>><>>>><<<<><><<><>>>><<>>>><>>>><><<><<<>><<<><<>>><<><<><<<>>>><<>>>><<<<>>>><>>>><<>>>><<>>><<<><<<<>><<<<><>>><<<<><<>>>><<>>><<>>>><<<<>>><<<>>><<>>><<<>>><<<>>>><<<<><><>>><<<<>>>><<>><<<<>><>><<>>><<<<>>><>><<>>>><<<>>>><<<<><<<>>><<<<>>><>><<<<>>><<<<>>><<<>><<<<>>><<<>>><<>><<<>>>><<<>>><><<<><<<><<<<>><<><<<>>><<<<>>><<<<><<<<><<<<>><<<>>>><<><<>><<<><><<>>>><<<>>><<>>><<<<>>><<><>>><>>><<<><<<<>>><<<<><<>>><<<<>><<>>><<<<>>><><<<>>><<<><>><<<<>>>><<<<>><<<<>>>><<>>><<<<>>>><<<><<<<><<<>>>><<<<>>>><><<<>><<<>>>><<><<<<>><<<>>><><<>>>><<>>>><<<<><>><<<>>>><><<<>>>><><<<><<<>><>>>><<<>><>>>><><>>><<<><<>>>><<>>>><<><>><<>><<>>>><<<<>>>><<<>><<<>>><<<>>>><<>>><<<>>>><<<<>>><<<<>><<><>><<<>>>><<<<>>>><>>>><<<<><<>>>><<<<>>><>>><>>>><<<>>>><<<>>><<<>>>><<<>>><<<<><><<<>>>><>><<<><>>>><<<><<<<><<<>>><><<>>><<<<>><<<>>><<<><<<>>>><<<<><<<<><<<><<<>><<<<>>>><<>><><<<>>><<<<>>>><<<>>><<>><<<>><<<>>><<<><<<<><<<<>>><<>>><><>>>><<<>>>><<>>>><<<<><>>><>>>><<<>>>><<<<>><>>>><<>><<>>>><<<<>>>><>>><<><<<<>>><<<><>><>><<<><<<<>><<<>><><<<<>><>>>><<>><<<>>><>>><<>><<>>><><<<<><<<<>><<<<>>>><<>>><<>><><<<<>>>><<><<<>>>><<<<><<<<>><<>><<<>><>><>><<<>><<<<><>><<<<><<>>>><<<<><>><>><>>>><>><<<<><>><>>>><<<>>>><<<<>><<<<><<<<>>>><>>><<<><>><<>>>><<>>>><<<>><<>><<<<>>><><<<><<<<><<<<>>><<>>>><>>><>>>><<>>>><<<><<<<>><<>>>><<>>>><<<>>><<><<><<>>>><<>>><<<><<<>>>><<<><>>><<>><><<>><<<>>>><<><<<<>><<><<<>><>>><<<>>>><<<<>>>><<<>>>><<<>><<>>>><<><>>>><<<><<>>><<<<>><<<><<<>>><<>>><>>><<>>>><<>><<><>><<<<>>><><><<<<>>>><<>><<<>>>><>>><<<>>><<<<><<>>><>><<<<>>>><>>><<<<>>>><<<<>>>><<<<>>>><<<>><>><<<>>>><<<><<<<>>>><<><<>><<<<>>><<>>>><<<<><<<<>>>><<<<><<<>>><<<>>>><<<<>>>><>>>><>>>><<<>>><<<>>><<<<>>><<<>><<<>>>><<>><<>>>><>>>><>>>><<<>>><>>>><>>><<<<>>><<<<>>>><>>><>>><>><>>><<<>>><<<<>>><<<<><>><<<><>>><<>><<<>>>><<<>><><<<>>><<<><<>><>>>><<<>>><><<><>>><<<<>><<<<><<<>>>><<<>>><><<<<>>><<<><<><<<>>><<><<>>>><<<>>>><<><<<>>>><>>><<>><<<><<<>>>><<<<>><>>>><<>>><<<<>>><<><>>>><<<<>>><<<>>><<><<<<>>><<<<>>><<<<>>>><<<>>>><>>><<<>>><<>><<<>>>><<<><><<<<><<<<>>>><<>>><>>><<<<><<<>><<>>>><><<<><<>>><<<<>>><<>>><<<<><<<>>><<<>>>><>>><>>><<><><<>><<>>><<<<>>><<>><<<>>>><>>>><>><<><<<>>><<><<<<>>>><<>>>><<<<>><<>>><<<<><<<<>>><<>>><<<<><><>>>><<<>>><<<<>>><>>>><<<>><<<>>>><<<<><<<>>>><<><<>>>><<>><<<<>><<<>>><<<>>>><<<<><<>><>>><<<>><<<>>>><<<<>>><<>><<<<>><>>><<>>><<<>>><>><<<>>>><<>>>><<<<>>><<>>><>>><>><>>>><>>>><<>>>><>>><<<><>>>><<<<>>><<<<>>><<<<>>><<<>>>><<>>>><>>><<<>>><<<<>><<<<>><<>>>><<<<><<>>><<<<><<<><<<><<>>>><<<>><<><<>>><<<>>><<>>><<>>>><>>>><><<<<><>>><<>>><<><<<><<<>>><<<>>>><<<>>><>><>>>><<<>>>><<<>>>><>><>>>><<<<>>><<<>>><<<<>><<>><<>>><<<<>>>><<<>>><<><<<<>><>>>><>><<>>>><>>><>>><><<<<>>><<<<>>><<<<><<<<>>>><<<<><<>>>><<<<>>>><<<<>>><<<>>><<>><<>><<<>>><>>>><>>>><<<<>>>><<<>>>><<<<>>>><<<>><<<>>><<<>><<<<>><<>>><<>>><<<<>><<<<><<<<>>>><<<<>>>><<>><<<>>>><><>>><<><<>><<<>>><>>><<>>>><<><>>><<><<>>><<>>>><><>>>><<<<>>>><<<><<>><<>>><<<<>>>><<<<>><<<<>><<>><<><<>><<<>>>><<<<><><<<<>>>><><<>>>><>>><>><<<<>><<<><<<>><<>>>><><>>>><<>><<>>><<<<><<<>><<<<>>><<<<>><<<<>><<<>><<<<><<<>>><<>>><<<<>>>><>>>><<>><<>>>><<>>>><<>>><>>><<<><><<<><<<>><><>>>><<<<>>><<<><<<>><<><<<<><<<<><<><<<<>>>><>><<<<><<>>>><>>>><<<>>><>>><><<<<>><<<>><<>>>><<<<><>>>><<<>>>><<<>><>>>><<>>>><<<>>><<>>><<<>><<<><<<<>>><><<>>>><<<>>><<>>>><>>>><>>><<<>>>><<<>><>><<<<>>><<<>>><><<<><<>><<<>>><<<<><><<<<>>>><<>>>><<<>><<<>><<>>><>><<<>><<<>>><<<><<<>><<>><<>>><<<<>>><<><<<><<>><<<>>><>>><<>><<>><<<<>>>><<><<<<>>><<>>><>>><<><>>>><<<<>><<>>>><>><<<<>>><<><<<>>>><<<><>>>><<<>>><<<><<<>><<<>><<<<>><><<<<>>><>>><<>>>><<<>>><<<>>>><<<<>>><<<<>>>><<<>>>><>>><<<<>>>><>>><<<<><<>>><<>><<<<>><><<>><<<<>><<<>><<><<>>>><><<<<>>><<><<><<<>>>><<<>>>><<><<<>>>><<<><>>>><>><<><<<<>>><>><<<><>><<<>>>><<<><<><<<>>>><<>>><<<<><<><<<>><<<><<<<>>>><<<>>><<<<><<<>><<<>>>><>>>><<<<>>>><<<>>><<<<>>>><<<>><<>><<>><>>>><<<<>><<<><>><<<<><<<<><<>><<<>>><<>>>><<><>>>><<<<>><<><<<>>><<<><<<<>>>><<<>>>><<<>>><<<>>><<<<>>><<<>>><<>><<<>>><><><<<>><>>>><<<<>><<>>><<><<>>><<<<>><<>><><<<<>>><<>>>><<><>><<>>><<><<<>>><<>>>><><>><<><<>><<><<<<>>>><<>>>><>>>><<<<>>>><>><>><<<>>>><<>>>><<><>>>><<<<>>>><<<<>>><<<<><<<<>><<>>>><<<><<<>><<<<><<<<>><<<><<>>>><>><<>>>><<<>>>><<>>><<<<>><<<<><<>>>><>>>><>><><<>><<><<<><<>><<<>>><<<>>>><<<<>>><<<<>>>><<<><>>><<>><<<><<<<><<>>><<<<><<<><<<>><<>>>><><<><<<<>><>><<<>><<<<>>><<<<>>><>>><<<><<<>><<>>><<<>>><<<>><<<<>>>><<<>><<<>><<<<>>><>>>><>><<>><<>><<<>><<>>>><<<<><>><<<>>>><<<<>><<<<><<<<>>><<<<>>><<<<>>><<>><<<><<<>>><<<>><<>>><<>>><<>>>><<>>><<>><><><<<>><<<>>><<<><<>>><>><<><<<<>>>><<<>><>>><<>><>>><<<>>><<<>>><<<>>><>><<>><<>>><><<<>><<>><<>>>><<<<><>>>><>>>><<<<>>><<>>><<<>>><><>><<<<><>><<<>>>><<<>>>><<<<><<<>>><>><<>>>><<<><>>>><<<>><<<>>><<<<><<><<<>>><<><>>>><<<>><<<<>>>><<<<><<<<>>>><<><<<>><<<>>>><>>><<><<>><<>>><>>><<<><<<<>>>><<<<><<<<>><>><>>>><<<>>>><<<><<>>>><><<<<>><<<>><<><<<><<<>>><<<>><<<>>>><<>>><<<<>><<>>><>><<<<>>>><<<<>><>><<>>>><<>>>><<<>>><>>>><<<><<<<>>>><<><<>>><<<<>><<<>>><<<>><>><<<>>><<>>><<><>>>><>>><><>>><<>><>>><<>><<<<>><>><<>><><<<>>>><<>>><<>>>><<<>><<>><<<<>><<<><<<<>><<<<>><>>><<>>>><<<<><<>>><<<><>><<<><<<>>>><<<<>>><>><<<<>>>><<<<>>><<<<>>><>>>><<>>>><<<<>>><<><<><>><><>>>><<<<>><<>>><<><<<>><>>><>>><<<<>>>><<>>><<<><<>>><<<>><<<<><><><<><<<><>>><>>>><>>><>>><<>>>><<>>><<<<>>>><<><>><<>>>><<<><<<>>>><<<>>>><<<<>>>><<<<><<<>>><<<<>>><<<>>><>><<<>>><<>>><<<>>>><>>>><<>><<>>><>><<<<>>>><<<<>><>>>><><<<>>>><>>><<>>>><<<>><<<<><>>>><<<<>><<>><>>><><<<<>>>><<<<>><<<>><>>>><<<<>>>><<<><<<><<<<>>><>><><<<>>>><<>>><<<>><<>>><<>><<>><<<<><<<><><>><>>><<<<>>>><<>>>><<<>><>>>><<<<><>><<>>><<>>>><<>>>><<<<>>><<<><<>><<><>>><>><<>><<<<>>>><<<>>>><<<>>><<>>>><<<<><><<>>>><<<><<>>>><<<><<<<>><<<<>>><<>>><>><<<<><<<>><<<>>>><<<<>>><<<<>><<<>>>><<<<>>>><<<>><>>><>><<>>><<>>>><<<<>><<><<><<>>><>>><<<>>>><<<><<<>><<<>><<<>><<>><<<>>>><<<>>>><>>>><>><<<<>>>><<><<<<>>><>>>><<>>><<<>>>><<<>>><<<<>>>><>>><><<<<>>><<<<>>>><><<<>><><>><<<><<<>>>><<>>>><<<<>>>><>>>><<>>><<<<>><<<><<>>><<<<>><<<<>><>><<<<>>>><<<>>><<<<>>>><<<>>><<>><<<>><<>>><<>>>><<<>>><>>>><<<<>><<<<>>>><>><<<>><<<<>><<>><<<>>>><<<>>><<<>>>><<<<>><<<><><>>><<<<><<<>>>><<<>>><<<<>>>><<<>>>><<>><<><<<>>><<>><><<<>>>><<>><<<>>>><<<>>><<<<><<>>>><<<<><><<<><><<<<>><<><<<><<<>><<>><<>><<>><>>><>>>><><><<<>><<>><<<>><<<<>>><<>>>><<<<>>><<<>><>>><<<>><>>>><<<>>><<<>><<<<>>><<>>>><>>>><<>>><<<><<<>>><<<<>>>><<<<><<<>>>><<>><<<><<><><>>>><<<<>>><>>><<<<>><<<>><<<>>>><<<<>>>><<<>><<<<>>>><<<>>><>>><<<><<<<>>><<<<>><<<>>><<<>><<<<>>>><<<>>><<>>><>>>><<<<>><<>>>><<<<>>>><<>><<>><<<<>>>><<<>>><<<><<<>>>><<<<>>>><<<>>>><<>>>><<<<>>><<>>><<<><<<<>>>><>>>><<>>><<>>><<<<>><<<>><><<>>><>>>><<>>><<<<>>><>>><<<<>>><<>>><<<<>><<>>>><<<>>>><>><<<>><<<<>>>><><<<<>>>><<<>>><>>>><<>><<<>>><<><<<<>><<>>>><>>>><<>>><<>>>><<<>>><>>>><>>>><>>>><<<<>><<<>><<<<>><<<>>>><>>><<<<>><><<<<>>>><<>>>><<>><>><<>>><<>><>>>"};

constexpr int numJetStreams = size(inputJetStreams) - 1; //remove '\0'

int g_CurrentStep = 0;
vector<uint8_t> g_Playfield;
size_t g_PlayfieldHeight;

constexpr uint8_t RockTypes[5][4] =  //the different rockForms as bitfields, already 2 bits shifted to right, because of startpos, and with enough 0 to fill the 7 width of the tunnel
{
	{ 0b0000000, 0b0000000, 0b0000000, 0b0011110 },  // _ - form
	{ 0b0000000, 0b0001000, 0b0011100, 0b0001000 },  // + - form
	{ 0b0000000, 0b0000100, 0b0000100, 0b0011100 },  // _I - form
	{ 0b0010000, 0b0010000, 0b0010000, 0b0010000 },  // I - form
	{ 0b0000000, 0b0000000, 0b0011000, 0b0011000 }   // [] - form
};
int numRocks = 5;

class Rock
{
public:
	void Init(int RockType)
	{
		memcpy(form, RockTypes[RockType], 4 * sizeof(RockTypes[RockType][0]));
		currentY = g_PlayfieldHeight; // we start at the top (we assume the 3 lines of air were already added)
	}

	bool SimulateStep()
	{
		if (inputJetStreams[g_CurrentStep % numJetStreams] == '<')
			MoveLeft();
		else
			MoveRight();
		++g_CurrentStep;
		return MoveDown();
	}

	uint8_t form[4]; // 4 * 7-bit bitmasks, to represent the current form&position inside of the tunnel, example: 00111100 would be the _ piece in the middle
	size_t currentY; //current pos in playfield of our bottom

private:
	bool MoveLeft()
	{
		if (((form[3] & 1 << 6) | (form[2] & 1 << 6)) > 0)
			return false;  //bit at 6 is set, we reached already left border
		ShiftAllLeft();
		if (IsCollidingWithPlayfield())
		{
			ShiftAllRight(); //revert shift
			return false;  //we touched something on the playfield
		}
		return true;
	}
	bool MoveRight()
	{
		if (((form[3] & 1 << 0) | (form[2] & 1 << 0)) > 0)
			return false;  //bit at 0 is set, we already reached right border
		ShiftAllRight();
		if (IsCollidingWithPlayfield())
		{
			ShiftAllLeft(); //revert shift
			return false;  //we touched something on the playfield
		}			
		return true;
	}
	bool MoveDown()
	{
		if(currentY < g_PlayfieldHeight - 2 &&  //still in air over playfield, no way we can hit anything up here
			((g_Playfield[currentY - 1] & form[3]) > 0 ||  //check bottom for contact
			(g_Playfield[currentY] & form[2]) > 0)) //check middle for contact
		{
			return false;
		}
		--currentY;
		return true;
	}

	bool IsCollidingWithPlayfield() const
	{
		const size_t stepsIntoPlayfield = g_PlayfieldHeight - currentY;
		return stepsIntoPlayfield > 2 && //the first 3 lines are air anyway
				((form[3] & g_Playfield[currentY]) > 0 ||  //is our bottom (line 3) line colliding with playfield
				(form[2] & g_Playfield[currentY + 1]) > 0 || //is our line 2 line colliding with playfield
				(form[1] & g_Playfield[currentY + 2]) > 0 ||  //is our line 1 line colliding with playfield
				(stepsIntoPlayfield > 3 && (form[0] & g_Playfield[currentY + 3]) > 0));  ////is our top line colliding with playfield?
	}

	void ShiftAllLeft()
	{
		for (auto& i : form)
			i <<= 1;
	}

	void ShiftAllRight()
	{
		for (auto& i : form)
			i >>= 1;
	}
};



constexpr int unsigned numStonesToDrop = 2022;
constexpr long long unsigned numStonesToDropPart2 = 1000000000000;

void DrawPlayfield()
{
		printf("%c[%d;%df", 0x1B, 0, 0);
		for (size_t lineIndex = g_Playfield.size() - 1; lineIndex >= 1; --lineIndex)
		{
			cout << '|'; //wall
			for (int i = 6; i >= 0; --i)
				cout << (g_Playfield[lineIndex] & 1 << i ? '#' : '.');
			cout << "|     " << lineIndex << '\n'; //wall
		}
		cout << "+-------+";
}

size_t GetCurrentFieldHeight()
{
	size_t currentTowerHeight = g_Playfield.size() - 1; //remove ground
	for (auto i = g_Playfield.size() - 1; i > 0; --i)
	{
		if (g_Playfield[i] == 0)
			currentTowerHeight--; //remove air line
		else break;
	}
	return currentTowerHeight;
}


int main()
{
	if(false)
	{  //part1
		g_Playfield.reserve(2048);
		g_Playfield.push_back(0b1111111); //ground;
		g_Playfield.push_back(0b0000000); //1 row of air;
		g_Playfield.push_back(0b0000000); //1 row of air;
		g_Playfield.push_back(0b0000000); //1 row of air;

		Rock currentRock;
		for (int unsigned currentStep = 0; currentStep < numStonesToDrop; ++currentStep)
		{
			if (*(g_Playfield.end() - 1) != 0)
				g_Playfield.push_back(0b0000000); //1 row of air;
			if (*(g_Playfield.end() - 2) != 0)
				g_Playfield.push_back(0b0000000); //1 row of air;
			if (*(g_Playfield.end() - 3) != 0)
				g_Playfield.push_back(0b0000000); //1 row of air;
			//DrawPlayfield();

			g_PlayfieldHeight = g_Playfield.size();
			currentRock.Init(currentStep % numRocks);

			while (currentRock.SimulateStep()) //remark: will increment stepCounter
			{
			} //while able to move down, do so

		   //rock came to an hold, add to playfield
			g_Playfield[currentRock.currentY] |= currentRock.form[3]; //add our rock to playfield,
			g_Playfield[currentRock.currentY + 1] |= currentRock.form[2];
			g_Playfield[currentRock.currentY + 2] |= currentRock.form[1];
			if (currentRock.form[0] != 0) //our rock uses 4 lines. we then might have to extend the playfield.
			{
				if (currentRock.currentY + 3 > g_Playfield.size() - 1) //our rock is larger than the 3 lines of air that we added. we simple add the rock as new line
					g_Playfield.push_back(currentRock.form[0]);
				else
					g_Playfield[currentRock.currentY + 3] |= currentRock.form[0];
			}
		}

		std::cout << "Height: " << GetCurrentFieldHeight(); //remove ground line
	}

	if(true)
	{
		unsigned long long movesSinceLastCycle = 0;
		unsigned long long heightLastCycle = 0;
		unsigned long long rocksLastCycle = 0;
		unsigned long long skippedAmount = 0;
		unsigned long long lastLinesHash = 0;

		//part2
		g_Playfield.reserve(1000000);
		g_Playfield.push_back(0b1111111); //ground;
		g_Playfield.push_back(0b0000000); //1 row of air;
		g_Playfield.push_back(0b0000000); //1 row of air;
		g_Playfield.push_back(0b0000000); //1 row of air;

		Rock currentRock;
		for (long long unsigned currentRockCount = 0; currentRockCount < numStonesToDropPart2; ++currentRockCount)
		{
			if(currentRockCount % numRocks == 0 && (g_CurrentStep & numJetStreams) == 0 && currentRockCount > 6000 ) // this is the cycle we are waiting for
			{
				const long long unsigned lineCache = *(g_Playfield.end() - 10) + *(g_Playfield.end() - 1) * 100 + *(g_Playfield.end() - 2) * 1000 + *(g_Playfield.end() - 3) * 10000 + *(g_Playfield.end() - 4) * 100000 + *(g_Playfield.end() - 5) * 1000000 + *(g_Playfield.end() - 6) * 10000000 + *(g_Playfield.end() - 7) * 100000000 + *(g_Playfield.end() - 8) * 200000000 + *(g_Playfield.end() - 9) * 3000000000;

				if(heightLastCycle == 0)  //first cycle
				{
					lastLinesHash = lineCache;
					movesSinceLastCycle = currentRockCount - rocksLastCycle;
					heightLastCycle = GetCurrentFieldHeight();
					rocksLastCycle = currentRockCount;
				}
				else if(lineCache == lastLinesHash)
				{
					long long unsigned heightChangeSinceLastCycle = GetCurrentFieldHeight() - heightLastCycle;
					long long unsigned rocksSinceLastCycle = currentRockCount - rocksLastCycle;
					long long unsigned remainingCycles = (numStonesToDropPart2 - currentRockCount) / rocksSinceLastCycle; //Remaining / RocksPerCycle, rounded down
					skippedAmount = remainingCycles * heightChangeSinceLastCycle;
					currentRockCount += rocksSinceLastCycle * remainingCycles;  //fast forward the loop-index, so that the iterations were skipped
				}
			}

			if (*(g_Playfield.end() - 1) != 0)
				g_Playfield.push_back(0b0000000); //1 row of air;
			if (*(g_Playfield.end() - 2) != 0)
				g_Playfield.push_back(0b0000000); //1 row of air;
			if (*(g_Playfield.end() - 3) != 0)
				g_Playfield.push_back(0b0000000); //1 row of air;
			//DrawPlayfield();

			g_PlayfieldHeight = g_Playfield.size();
			currentRock.Init(currentRockCount % numRocks);			

			while (currentRock.SimulateStep()) //remark: will increment stepCounter
			{
			} //while able to move down, do so

		   //rock came to an hold, add to playfield
			g_Playfield[currentRock.currentY] |= currentRock.form[3]; //add our rock to playfield,
			g_Playfield[currentRock.currentY + 1] |= currentRock.form[2];
			g_Playfield[currentRock.currentY + 2] |= currentRock.form[1];
			if (currentRock.form[0] != 0) //our rock uses 4 lines. we then might have to extend the playfield.
			{
				if (currentRock.currentY + 3 > g_Playfield.size() - 1) //our rock is larger than the 3 lines of air that we added. we simple add the rock as new line
					g_Playfield.push_back(currentRock.form[0]);
				else
					g_Playfield[currentRock.currentY + 3] |= currentRock.form[0];
			}
		}

		//DrawPlayfield();
		std::cout << "Height: " << skippedAmount + GetCurrentFieldHeight(); 
	}


	auto pause = getchar();
}
