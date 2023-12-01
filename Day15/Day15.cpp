// Day15.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

const char* inputData[] =
{
	"Sensor at x=1638847, y=3775370: closest beacon is at x=2498385, y=3565515",
	"Sensor at x=3654046, y=17188: closest beacon is at x=3628729, y=113719",
	"Sensor at x=3255262, y=2496809: closest beacon is at x=3266439, y=2494761",
	"Sensor at x=3743681, y=1144821: closest beacon is at x=3628729, y=113719",
	"Sensor at x=801506, y=2605771: closest beacon is at x=1043356, y=2000000",
	"Sensor at x=2933878, y=5850: closest beacon is at x=3628729, y=113719",
	"Sensor at x=3833210, y=12449: closest beacon is at x=3628729, y=113719",
	"Sensor at x=2604874, y=3991135: closest beacon is at x=2498385, y=3565515",
	"Sensor at x=1287765, y=1415912: closest beacon is at x=1043356, y=2000000",
	"Sensor at x=3111474, y=3680987: closest beacon is at x=2498385, y=3565515",
	"Sensor at x=2823460, y=1679092: closest beacon is at x=3212538, y=2537816",
	"Sensor at x=580633, y=1973060: closest beacon is at x=1043356, y=2000000",
	"Sensor at x=3983949, y=236589: closest beacon is at x=3628729, y=113719",
	"Sensor at x=3312433, y=246388: closest beacon is at x=3628729, y=113719",
	"Sensor at x=505, y=67828: closest beacon is at x=-645204, y=289136",
	"Sensor at x=1566406, y=647261: closest beacon is at x=1043356, y=2000000",
	"Sensor at x=2210221, y=2960790: closest beacon is at x=2498385, y=3565515",
	"Sensor at x=3538385, y=1990300: closest beacon is at x=3266439, y=2494761",
	"Sensor at x=3780372, y=2801075: closest beacon is at x=3266439, y=2494761",
	"Sensor at x=312110, y=1285740: closest beacon is at x=1043356, y=2000000",
	"Sensor at x=51945, y=2855778: closest beacon is at x=-32922, y=3577599",
	"Sensor at x=1387635, y=2875487: closest beacon is at x=1043356, y=2000000",
	"Sensor at x=82486, y=3631563: closest beacon is at x=-32922, y=3577599",
	"Sensor at x=3689149, y=3669721: closest beacon is at x=3481800, y=4169166",
	"Sensor at x=2085975, y=2190591: closest beacon is at x=1043356, y=2000000",
	"Sensor at x=712588, y=3677889: closest beacon is at x=-32922, y=3577599",
	"Sensor at x=22095, y=3888893: closest beacon is at x=-32922, y=3577599",
	"Sensor at x=3248397, y=2952817: closest beacon is at x=3212538, y=2537816"
};

struct CPoint
{
	int x;
	int y;
};

constexpr int targetLineY = 2000000;
constexpr int distressSignalMax = 4000000;
constexpr int numDataEntries = size(inputData);

//unordered_set<int> blockedPosXInTargetLine;
struct CBlockRange
{
	int start;
	int end;
};
vector<CBlockRange> blockedRanges;

CPoint sensors[numDataEntries];
CPoint beacons[numDataEntries];
int radius[numDataEntries];

inline int manhattanDistance(const CPoint& pos1, const CPoint& pos2)
{
	return abs(pos1.x - pos2.x) + abs(pos1.y - pos2.y);
}

bool isPointInScanRange(const int x, const int y)
{
	for (int i = 0; i < numDataEntries; ++i) //check if point is scanned by anyone
	{
		if (abs(x - sensors[i].x) + abs(y - sensors[i].y) <= radius[i])
			return true;		
	}
	return false;
}


unsigned int CountBlockersInLine(int lineToCheck, int forceMin = -666666666, int forceMax = 666666666)
{
	blockedRanges.clear();
	int minX = 0, maxX = 0;

	for (int i = 0; i < numDataEntries; ++i)
	{
		const int distanceToScanLine = abs(sensors[i].y - lineToCheck);
		if (distanceToScanLine < radius[i])
		{
			const int blockedRange = radius[i] - distanceToScanLine; //with each step further away from our scanline, our blocking range gets smaller
			blockedRanges.push_back(CBlockRange{ max(forceMin, sensors[i].x - blockedRange), min(forceMax,sensors[i].x + blockedRange) });
			minX = min(minX, blockedRanges.back().start);
			maxX = max(maxX, blockedRanges.back().end);
		}
	}
	
	unsigned int blockedFields = 0;
	for (int i = minX; i < maxX; ++i)
	{
		for (const auto& curRange : blockedRanges)
		{
			if (i >= curRange.start && i < curRange.end)
			{
				const int rangeSize = (curRange.end - i);
				if(curRange.end < maxX)
					blockedFields += rangeSize + 1;
				else 	
					blockedFields += rangeSize;
				i += rangeSize;
				break;
			}
		}
	}
	return blockedFields;
}

void main()
{
	//parse input
	for (int i = 0; i < numDataEntries; ++i)
	{
		if (sscanf_s(inputData[i], "Sensor at x=%i, y=%i: closest beacon is at x=%i, y=%i", &sensors[i].x, &sensors[i].y, &beacons[i].x, &beacons[i].y) != 4)
			cerr << "Data not fine!";
		radius[i] = manhattanDistance(sensors[i], beacons[i]);
	}

	////part 1: check if radius < distanceToScanline, and if yes, add blocked range
	{
		const auto blockedFields = CountBlockersInLine(targetLineY);
		cout << "Num Blockers: " << blockedFields;
	}

	//part2
	{
		for (int y = 0; y < distressSignalMax; ++y)
		{
			const unsigned int freeSpaces = distressSignalMax - CountBlockersInLine(y, 0, distressSignalMax);
			if (freeSpaces > 0)
			{
				cout << "!!! FreeSpaces in: " << y << std::endl;
				for (int x = 0; x < distressSignalMax; ++x)
				{
					if(!isPointInScanRange(x, y))
						cout << "Found free Field, value " << (unsigned long long)x * (unsigned long long)distressSignalMax + (unsigned long long)y << " Pos: " << x << ":" << y << std::endl;
				}
			}
			else if (y % 10000 == 0)
				cout << "Currently checking Line: " << y << "\n";
		}
	}

	getchar();
}
