// Day19.cpp: This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>


//constexpr const char* inputData[] =
//{
//"Blueprint 1: Each ore robot costs 4 ore.Each clay robot costs 2 ore.Each obsidian robot costs 3 ore and 14 clay.Each geode robot costs 2 ore and 7 obsidian.",
//"Blueprint 2: Each ore robot costs 2 ore.Each clay robot costs 3 ore.Each obsidian robot costs 3 ore and 8 clay.Each geode robot costs 3 ore and 12 obsidian."
//};

constexpr const char* inputData[] =
{
"Blueprint 1: Each ore robot costs 4 ore.Each clay robot costs 4 ore.Each obsidian robot costs 4 ore and 20 clay.Each geode robot costs 2 ore and 12 obsidian.",
"Blueprint 2: Each ore robot costs 2 ore.Each clay robot costs 2 ore.Each obsidian robot costs 2 ore and 17 clay.Each geode robot costs 2 ore and 10 obsidian.",
"Blueprint 3: Each ore robot costs 3 ore.Each clay robot costs 3 ore.Each obsidian robot costs 4 ore and 19 clay.Each geode robot costs 4 ore and 7 obsidian.",
"Blueprint 4: Each ore robot costs 3 ore.Each clay robot costs 4 ore.Each obsidian robot costs 4 ore and 6 clay.Each geode robot costs 2 ore and 20 obsidian.",
"Blueprint 5: Each ore robot costs 2 ore.Each clay robot costs 4 ore.Each obsidian robot costs 4 ore and 19 clay.Each geode robot costs 2 ore and 18 obsidian.",
"Blueprint 6: Each ore robot costs 4 ore.Each clay robot costs 4 ore.Each obsidian robot costs 3 ore and 14 clay.Each geode robot costs 4 ore and 15 obsidian.",
"Blueprint 7: Each ore robot costs 3 ore.Each clay robot costs 4 ore.Each obsidian robot costs 3 ore and 15 clay.Each geode robot costs 3 ore and 20 obsidian.",
"Blueprint 8: Each ore robot costs 2 ore.Each clay robot costs 4 ore.Each obsidian robot costs 2 ore and 20 clay.Each geode robot costs 3 ore and 15 obsidian.",
"Blueprint 9: Each ore robot costs 2 ore.Each clay robot costs 2 ore.Each obsidian robot costs 2 ore and 20 clay.Each geode robot costs 2 ore and 14 obsidian.",
"Blueprint 10: Each ore robot costs 4 ore.Each clay robot costs 4 ore.Each obsidian robot costs 4 ore and 5 clay.Each geode robot costs 3 ore and 7 obsidian.",
"Blueprint 11: Each ore robot costs 4 ore.Each clay robot costs 3 ore.Each obsidian robot costs 4 ore and 11 clay.Each geode robot costs 3 ore and 15 obsidian.",
"Blueprint 12: Each ore robot costs 4 ore.Each clay robot costs 4 ore.Each obsidian robot costs 3 ore and 20 clay.Each geode robot costs 2 ore and 10 obsidian.",
"Blueprint 13: Each ore robot costs 4 ore.Each clay robot costs 4 ore.Each obsidian robot costs 4 ore and 7 clay.Each geode robot costs 4 ore and 17 obsidian.",
"Blueprint 14: Each ore robot costs 2 ore.Each clay robot costs 4 ore.Each obsidian robot costs 4 ore and 20 clay.Each geode robot costs 3 ore and 14 obsidian.",
"Blueprint 15: Each ore robot costs 4 ore.Each clay robot costs 4 ore.Each obsidian robot costs 2 ore and 17 clay.Each geode robot costs 3 ore and 11 obsidian.",
"Blueprint 16: Each ore robot costs 4 ore.Each clay robot costs 3 ore.Each obsidian robot costs 2 ore and 14 clay.Each geode robot costs 4 ore and 11 obsidian.",
"Blueprint 17: Each ore robot costs 4 ore.Each clay robot costs 3 ore.Each obsidian robot costs 4 ore and 15 clay.Each geode robot costs 4 ore and 9 obsidian.",
"Blueprint 18: Each ore robot costs 3 ore.Each clay robot costs 3 ore.Each obsidian robot costs 3 ore and 19 clay.Each geode robot costs 3 ore and 17 obsidian.",
"Blueprint 19: Each ore robot costs 4 ore.Each clay robot costs 3 ore.Each obsidian robot costs 2 ore and 20 clay.Each geode robot costs 2 ore and 9 obsidian.",
"Blueprint 20: Each ore robot costs 3 ore.Each clay robot costs 4 ore.Each obsidian robot costs 2 ore and 11 clay.Each geode robot costs 2 ore and 10 obsidian.",
"Blueprint 21: Each ore robot costs 4 ore.Each clay robot costs 4 ore.Each obsidian robot costs 4 ore and 10 clay.Each geode robot costs 2 ore and 7 obsidian.",
"Blueprint 22: Each ore robot costs 4 ore.Each clay robot costs 4 ore.Each obsidian robot costs 3 ore and 6 clay.Each geode robot costs 2 ore and 14 obsidian.",
"Blueprint 23: Each ore robot costs 4 ore.Each clay robot costs 4 ore.Each obsidian robot costs 4 ore and 15 clay.Each geode robot costs 3 ore and 8 obsidian.",
"Blueprint 24: Each ore robot costs 4 ore.Each clay robot costs 4 ore.Each obsidian robot costs 4 ore and 8 clay.Each geode robot costs 3 ore and 19 obsidian.",
"Blueprint 25: Each ore robot costs 2 ore.Each clay robot costs 3 ore.Each obsidian robot costs 3 ore and 9 clay.Each geode robot costs 3 ore and 9 obsidian.",
"Blueprint 26: Each ore robot costs 3 ore.Each clay robot costs 3 ore.Each obsidian robot costs 2 ore and 20 clay.Each geode robot costs 2 ore and 20 obsidian.",
"Blueprint 27: Each ore robot costs 4 ore.Each clay robot costs 4 ore.Each obsidian robot costs 3 ore and 10 clay.Each geode robot costs 2 ore and 14 obsidian.",
"Blueprint 28: Each ore robot costs 2 ore.Each clay robot costs 4 ore.Each obsidian robot costs 3 ore and 19 clay.Each geode robot costs 4 ore and 8 obsidian.",
"Blueprint 29: Each ore robot costs 4 ore.Each clay robot costs 4 ore.Each obsidian robot costs 2 ore and 9 clay.Each geode robot costs 3 ore and 19 obsidian.",
"Blueprint 30: Each ore robot costs 4 ore.Each clay robot costs 3 ore.Each obsidian robot costs 2 ore and 13 clay.Each geode robot costs 2 ore and 10 obsidian.",
};

constexpr int numBlueprints = 3; // std::size(inputData);

enum eTypes : int8_t
{
	ORE = 0,
	CLAY = 1,
	OBSIDIAN = 2,
	GEODE = 3,
	NUM_TYPES = 4,
	UNDEFINED = -1
};

int g_CurBlueprint = 0;

struct CState
{
	CState() = default;
	CState(const CState& otherState)
	: robots{otherState.robots[0], otherState.robots[1], otherState.robots[2], otherState.robots[3] }
	, resources{ otherState.resources[0], otherState.resources[1], otherState.resources[2], otherState.resources[3] }
	, currentlyBuilding(otherState.currentlyBuilding) {}

	uint8_t robots[NUM_TYPES] = { 1, 0, 0, 0 }; //amount of robots for each type
	uint8_t resources[NUM_TYPES] = { 0 }; //amount of resources for each type
	eTypes currentlyBuilding = UNDEFINED;

	void GatherResources()
	{
		for (int i = 0; i < NUM_TYPES; ++i)
			resources[i] += robots[i];
	}

	void UpdateBuilding()
	{
		if(currentlyBuilding != UNDEFINED)
			robots[currentlyBuilding]++;
		currentlyBuilding = UNDEFINED;
	}
};

struct CBlueprint
{
	int costRobots[NUM_TYPES][NUM_TYPES - 1] = { {0} }; //4  robots, 4 resources (but geode is not used)
	int maxResourceCosts[NUM_TYPES - 1];

	void CalculateMax()
	{
		for (int resource = ORE; resource < GEODE; ++resource)
			maxResourceCosts[resource] = std::max(std::max(costRobots[ORE][resource], costRobots[OBSIDIAN][resource]), costRobots[GEODE][resource]);
	}
};
CBlueprint g_Blueprints[numBlueprints];

constexpr int g_numMinutesToSimulate = 32;
int g_bestResultForBlueprint[numBlueprints] = { 0 }; //how many geodes were collected
CState g_bestStateForBlueprint[numBlueprints]; //the state that won
uint8_t g_soFarBestGeodeCount[g_numMinutesToSimulate] = { 0 }; //the state that won


class Simulator
{
public:
	static void SimulateStep(CState& state, int minute)
	{
		//todo: check potential, remaining time * geodeBots

		if (g_soFarBestGeodeCount[minute] > state.resources[GEODE] + 2)
			return;  //we are already too much behind

		if (state.robots[ORE] > 10 || state.robots[CLAY] > 10)
			return; //too many low level collectors

		if (state.currentlyBuilding == UNDEFINED)
		{
			for (int type = ORE; type < NUM_TYPES; ++type)  //check if we can build anything, and if yes, then simulate it
			{
				if (EnoughResourcesForRobot(state.resources, (eTypes)type))
				{
					CState newState(state);
					StartBuildingRobot(newState, (eTypes)type);
					SimulateStep(newState, minute);
				}
			}

			if (state.resources[ORE] >= g_Blueprints[g_CurBlueprint].maxResourceCosts[ORE])
				return; //everything needs ore. so if we dont spend it, its wasteful
		}

		state.GatherResources();
		state.UpdateBuilding();
		minute++;

		if (minute == g_numMinutesToSimulate)
		{
			if(g_bestResultForBlueprint[g_CurBlueprint] < state.resources[GEODE])
			{
				g_bestResultForBlueprint[g_CurBlueprint] = state.resources[GEODE];
				g_bestStateForBlueprint[g_CurBlueprint] = state;
			}
		}
		else
		{
			g_soFarBestGeodeCount[minute] = std::max(state.resources[GEODE], g_soFarBestGeodeCount[minute]);
			SimulateStep(state, minute);
		}
	}

private:
	static bool EnoughResourcesForRobot(uint8_t resources[], eTypes type)
	{
		const auto& costForRobot = g_Blueprints[g_CurBlueprint].costRobots[type];
		return costForRobot[ORE] <= resources[ORE] && costForRobot[CLAY] <= resources[CLAY] && costForRobot[OBSIDIAN] <= resources[OBSIDIAN];
	}

	static void StartBuildingRobot(CState& state, eTypes type)  //remark: will not check anything
	{
		const auto& costForRobot = g_Blueprints[g_CurBlueprint].costRobots[type];
		state.resources[ORE] -= costForRobot[ORE];
		state.resources[CLAY] -= costForRobot[CLAY];
		state.resources[OBSIDIAN] -= costForRobot[OBSIDIAN];
		state.currentlyBuilding = type;
	}

	static bool IsStateWastingResources(CState& state) //we have too much for anything from one resource
	{
		for (int type = ORE; type < GEODE; ++type)
			if (state.resources[type] > g_Blueprints[g_CurBlueprint].maxResourceCosts[type])
				return true;
		return false;
	}
};



int main()
{
	//Init Blueprints from data
	for (int i = 0; i < numBlueprints; ++i)
	{
		auto& curBlueprint = g_Blueprints[i];
		int blueprintId;
		const int parsedParams = sscanf_s(inputData[i], "Blueprint %i: Each ore robot costs %i ore.Each clay robot costs %i ore.Each obsidian robot costs %i ore and %i clay.Each geode robot costs %i ore and %i obsidian.",
		                                  &blueprintId, &curBlueprint.costRobots[ORE][ORE], &curBlueprint.costRobots[CLAY][ORE], &curBlueprint.costRobots[OBSIDIAN][ORE], &curBlueprint.costRobots[OBSIDIAN][CLAY], &curBlueprint.costRobots[GEODE][ORE], &curBlueprint.costRobots[GEODE][OBSIDIAN]);
		if (parsedParams != 7 || blueprintId - 1 != i)
			std::cerr << "Something not right with the data! \n";
		curBlueprint.CalculateMax();
	}

	for (int i = 0; i < numBlueprints; ++i)
	{
		std::cout << "now doing blueprint: " << i << std::endl;
		g_CurBlueprint = i;
		CState startState;
		memset(g_soFarBestGeodeCount, 0, sizeof(g_soFarBestGeodeCount));
		Simulator::SimulateStep(startState, 0);
		std::cout << "now finsihed blueprint: " << i << ". Best result: " << g_bestResultForBlueprint[i] << std::endl;
	}

	int resultPart1 = 0;
	int resultPart2 = 1;
	for (int i = 0; i < numBlueprints; ++i)
	{
		std::cout << g_bestResultForBlueprint[i] << std::endl;
		resultPart1 += g_bestResultForBlueprint[i] * (i + 1);
		resultPart2 *= g_bestResultForBlueprint[i];
	}
	std::cout << "Final result: Part1: " << resultPart1 << " Part2:" << resultPart2;
	int test = getchar();

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
