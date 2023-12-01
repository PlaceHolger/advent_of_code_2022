// Day12.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <algorithm>
#include <iostream>
#include <vector>

const char* inputData[] = {
"abccccccccccccccccccaaaaaaaaacccccccccccccccccccccccccccccccccccccaaaa",
"abcccccccccccccccaaaaaaaaaaacccccccccccccccccccccccccccccccccccccaaaaa",
"abcaaccaacccccccccaaaaaaaaaacccccccccccccccccccccaaacccccccccccccaaaaa",
"abcaaaaaaccccccccaaaaaaaaaaaaacccccccccccccccccccaacccccccccccccaaaaaa",
"abcaaaaaacccaaacccccaaaaaaaaaaaccccccccccccccccccaaaccccccccccccccccaa",
"abaaaaaaacccaaaaccccaaaaaacaaaacccccccccccaaaacjjjacccccccccccccccccca",
"abaaaaaaaaccaaaaccccaaaaaaccccccaccccccccccaajjjjjkkcccccccccccccccccc",
"abaaaaaaaaccaaacccccccaaaccccccaaccccccccccajjjjjjkkkaaacccaaaccaccccc",
"abccaaacccccccccccccccaaccccaaaaaaaacccccccjjjjoookkkkaacccaaaaaaccccc",
"abcccaacccccccccccccccccccccaaaaaaaaccccccjjjjoooookkkkcccccaaaaaccccc",
"abcccccccaacccccccccccccccccccaaaacccccccijjjoooooookkkkccaaaaaaaccccc",
"abccaaccaaaccccccccccccccccccaaaaacccccciijjooouuuoppkkkkkaaaaaaaacccc",
"abccaaaaaaaccccccccccaaaaacccaacaaaccciiiiiooouuuuupppkkklllaaaaaacccc",
"abccaaaaaacccccccccccaaaaacccacccaaciiiiiiqooouuuuuupppkllllllacaccccc",
"abcccaaaaaaaacccccccaaaaaaccccaacaiiiiiqqqqoouuuxuuupppppplllllccccccc",
"abccaaaaaaaaaccaaaccaaaaaaccccaaaaiiiiqqqqqqttuxxxuuuppppppplllccccccc",
"abccaaaaaaaacccaaaaaaaaaaacccaaaahiiiqqqttttttuxxxxuuuvvpppplllccccccc",
"abcaaaaaaacccaaaaaaaaaaacccccaaaahhhqqqqtttttttxxxxuuvvvvvqqlllccccccc",
"abcccccaaaccaaaaaaaaaccccccccacaahhhqqqttttxxxxxxxyyyyyvvvqqlllccccccc",
"abcccccaaaccaaaaaaaacccccccccccaahhhqqqtttxxxxxxxyyyyyyvvqqqlllccccccc",
"SbcccccccccccaaaaaaaaaccccccccccchhhqqqtttxxxxEzzzyyyyvvvqqqmmlccccccc",
"abcccccccccccaaaaaaaacccaacccccccchhhppptttxxxxyyyyyvvvvqqqmmmcccccccc",
"abccccccccccaaaaaaaaaaccaacccccccchhhpppptttsxxyyyyyvvvqqqmmmccccccccc",
"abcaacccccccaaaaaaacaaaaaaccccccccchhhppppsswwyyyyyyyvvqqmmmmccccccccc",
"abaaaacccccccaccaaaccaaaaaaacccccccchhhpppsswwyywwyyyvvqqmmmddcccccccc",
"abaaaaccccccccccaaaccaaaaaaacccccccchhhpppsswwwwwwwwwvvqqqmmdddccccccc",
"abaaaacccccccccaaaccaaaaaaccccccccccgggpppsswwwwrrwwwwvrqqmmdddccccccc",
"abccccccaaaaaccaaaacaaaaaaccccccaacccggpppssswwsrrrwwwvrrqmmdddacccccc",
"abccccccaaaaaccaaaacccccaaccccaaaaaacggpppssssssrrrrrrrrrnmmdddaaccccc",
"abcccccaaaaaaccaaaccccccccccccaaaaaacggppossssssoorrrrrrrnnmdddacccccc",
"abcccccaaaaaaccccccccaaaaccccccaaaaacgggoooossoooonnnrrnnnnmddaaaacccc",
"abccccccaaaaaccccccccaaaacccccaaaaaccgggoooooooooonnnnnnnnndddaaaacccc",
"abccccccaaaccccccccccaaaacccccaaaaacccgggoooooooffennnnnnnedddaaaacccc",
"abcccccccccccccccccccaaacccccccaacccccggggffffffffeeeeeeeeeedaaacccccc",
"abccccccccccccccccccaaacccccaccaaccccccggfffffffffeeeeeeeeeecaaacccccc",
"abccccccccccccccccccaaaacccaaaaaaaaaccccfffffffaaaaaeeeeeecccccccccccc",
"abccccccccaacaaccccaaaaaacaaaaaaaaaaccccccccccaaaccaaaaccccccccccccccc",
"abccccccccaaaaacccaaaaaaaaaaacaaaaccccccccccccaaaccccaaccccccccccaaaca",
"abcccccccaaaaaccccaaaaaaaaaaacaaaaacccccccccccaaaccccccccccccccccaaaaa",
"abcccccccaaaaaacccaaaaaaaaaacaaaaaacccccccccccaaccccccccccccccccccaaaa",
"abcccccccccaaaaccaaaaaaaaaaaaaaccaaccccccccccccccccccccccccccccccaaaaa", };

int constexpr width = 70;
int constexpr height = std::size(inputData);
int constexpr infiniteValue = 9999999;

char GetHeightAt(const int x, const int y)
{
	if (x >= 0 && x < width && y >= 0 && y < height)
		return inputData[y][x];
	return 127;
}

int GetNodeId(const int x, const int y) { return y * 100 + x; }

struct node
{
	int x;
	int y;
	char height;
	int cost = infiniteValue;
	node* prev = nullptr; //the node which is connect

	int neighborIds[4] = { -1, -1, -1, -1 };

	bool operator ==(const int id) const { return GetId() == id; }
	bool operator ==(const node& other) const { return GetId() == other.GetId(); }
	bool operator < (const node& other) const {	return (cost > other.cost); }
	int GetId() const { return GetNodeId(x, y); }
	void UpdateNeighbors();
};

std::vector<node> open;

void node::UpdateNeighbors() //will update the cost for the neighbors, if them were not visited yet
{
	for (int& neighborId : neighborIds)
	{
		if(neighborId != -1)
		{
			const auto& reachableNeighbor = std::find(open.begin(), open.end(), neighborId);
			if(reachableNeighbor != open.end() && reachableNeighbor->cost > cost + 1) //not visited yet and not already has a shorter way
			{
				reachableNeighbor->cost = cost + 1;
				reachableNeighbor->prev = this;
			}
		}
	}
}

int endId;

void InitFromData(int startNodeCost = infiniteValue)
{
	open.clear();
	open.reserve(height * width);
	for (int y = 0; y < height; ++y) //init all nodes as open
	{
		for (int x = 0; x < width; ++x)
		{
			//auto curHeight = GetHeightAt(x, y);
			open.push_back({ x, y, GetHeightAt(x, y) });
			node& addedNode = open.back();
			if (addedNode.height == 'S')
			{
				addedNode.cost = startNodeCost;
				addedNode.height = 'a';
			}
			else if (addedNode.height == 'E')
			{
				endId = addedNode.GetId();
				addedNode.height = 'z';
			}

			if (GetHeightAt(x + 1, y) <= addedNode.height + 1)  //right neighbor reachable
				addedNode.neighborIds[0] = GetNodeId(x + 1, y);
			if (GetHeightAt(x - 1, y) <= addedNode.height + 1)  //left neighbor reachable
				addedNode.neighborIds[1] = GetNodeId(x - 1, y);
			if (GetHeightAt(x, y - 1) <= addedNode.height + 1)  //top neighbor reachable
				addedNode.neighborIds[2] = GetNodeId(x, y - 1);
			if (GetHeightAt(x, y + 1) <= addedNode.height + 1)  //down neighbor reachable
				addedNode.neighborIds[3] = GetNodeId(x, y + 1);
		}
	}
}

const node* FindPath()
{
	while (!open.empty())
	{
		std::sort(open.begin(), open.end()); //sort so that lowest reaching cost at end
		node& currentNode = open.back();
		if (currentNode.cost >= infiniteValue)
			break; //we ran out of reachable nodes... seems like there is no path
		if(currentNode.GetId() == endId)
		{
			return &currentNode;
		}
		currentNode.UpdateNeighbors();
		open.pop_back();
	}
	std::cout << "Target not reachable!\n";
	return nullptr;
}

int main()
{
	{  //part1
		InitFromData(0);
		const node* foundTargetPath = FindPath();
		int numSteps = 1;
		while (foundTargetPath)
		{
			foundTargetPath = foundTargetPath->prev;
			++numSteps;
		}

		std::cout << "Num steps from S to E: " << numSteps << std::endl;
	}

	{ //part2
		int minimumSteps = infiniteValue;

		for (int y = 0; y < height; ++y) //init all nodes as open
		{
			for (int x = 0; x < width; ++x)
			{
				if(GetHeightAt(x, y) == 'a')
				{
					InitFromData(infiniteValue);
					const auto& currentNode = std::find(open.begin(), open.end(), GetNodeId(x, y));
					currentNode->cost = 0;

					const node* foundTargetPath = FindPath();
					if (foundTargetPath)
					{
						int numSteps = 1;
						while (foundTargetPath)
						{
							foundTargetPath = foundTargetPath->prev;
							++numSteps;
						}
						if (numSteps < minimumSteps)
						{
							minimumSteps = numSteps;
							std::cout << "New Min NumSteps from any 'a' to E: " << minimumSteps << std::endl;
						}
					}
				}
			}
		}
		std::cout << "Min NumSteps from any 'a' to E: " << minimumSteps << std::endl;
		std::cin >> minimumSteps;
	}
}
