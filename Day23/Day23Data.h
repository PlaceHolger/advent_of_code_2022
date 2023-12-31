#pragma once

#ifdef TESTDATA

//constexpr const char* g_InputData[] =
//{
//	".....",
//	"..##.",
//	"..#..",
//	".....",
//	"..##.",
//	"....."
//};
//
//constexpr int g_DataWidth = 5;
//constexpr int g_DataHeight = 6;

constexpr int g_DataWidth = 7;
constexpr int g_DataHeight = 7;

constexpr const char* g_InputData[] =
{"....#..",
"..###.#",
"#...#.#",
".#...##",
"#.###..",
"##.#.##",
".#..#.."};

#else

constexpr int g_DataWidth = 75;
constexpr int g_DataHeight = 75;

constexpr const char* g_InputData[] =
{
	"...#######...####..#........#.#.##...##.##..#.##.####..####.##.##...###..##",
	"##.###.#...##..#....###..#.##.###.##..##..###..#....##.#..##.####..#.#.#.##",
	"..##.#.###.#......#...#....#...#.#.#...##......####..######.##....#####.##.",
	"##.#####.#.###.####.#....#.....####.#####..##.....#.##...###...#.####..#...",
	"...#.....#.#..#.######.###....#.....#.###..##..#.#.###..##..#.#......#..#..",
	".###.#.##.##.##.....##.........#....#.#.#..#....###..####..#.#.###..###..#.",
	".#####.......##.#..#...###.##...#.###...#..##.#.###.......##.#..#..##...##.",
	".###.#.#.###.#.#..#..###..###..###.########.###..#.##.#.##...##.##.###.#...",
	".....######.###.###.......####...##.#.##..#.#.##.#....##.###.#.###...###..#",
	"..#..##...#..#...##.#.#..###...#.##.##.##..##.###.#.#..#...#.#..#......####",
	"##..##.##..#.#.##...#.#.#...###.....#....###....#######.#####..#...#.##..##",
	"####....######.#..##...#....#.##....##.#..#.##..##..#.#.....##..####..#....",
	"....####..#.......##...#........#.##..#.#.#.##.##..##.##.....##..#...#.##.#",
	".####..######.##.#.#.#.##...###..##...######..#.#.#.####.######.#...###....",
	"##..#.#...#.#.#.#.###.#.###.#.#.##.....#..##..##.##...###....#...#.###...#.",
	"#####.##...###..#.#.######..#.###...###..#..###.....#....####..#.####...###",
	"#.#.#....###.##...#.###.#.###.###..###.#.#.....#.##....#.##.##.#####..##..#",
	"...##.#...##....####.#.##.#.####.###...#.##....#..##.###..#......#######.##",
	"....#..#.#.#...##....#.####.##...#..#####...#.##..###..##...#..#.##.#.#.#.#",
	"..#..#####.#..#.#.#..#.###.##...#........#.#.....#.##.....#.##.#..#.#.#.#..",
	"..#.##.###....##.#..#.#####.....#.##.....#.#..###.###..#.#......#..#...#.##",
	"##.#.#...#...#.##..#......###.#.#.####.#...#########.#..#..##...##...##.###",
	"...#.###.#..#######.#.#.##.##..###.##.#.######.#.##.##.##.#########.#...#.#",
	"#..#...##.##.######.#..#.####...####.###.#...##.####..##..#.#...##.#.#.##..",
	".##.###..#####.###.##..#.#.#.#....#.#....#...#....######.##.#...#...#.#...#",
	"#..#.....##....#.#..##.###..#..####..######...##.#..#######....#.#..##.##..",
	"##...#.##.#...#....#.##.##..#####...##.#.#.#.#...#...#.#....#.##..##..##..#",
	"..##....#..###...#.#.#.##....#...##...###.##.#.....#..#####.#####.....##..#",
	".#.##..#.#.###..#...###.....##...###..#.#######.#..#.#.##.##..##.#.#..##.##",
	"#.#...#..###..#...####.#.#..##.#..#....#.#.#.###.#.##.##.#.......#.##....##",
	".#.##.#.#..#.#.#.#.##..#.###..#....#..#...###.#.#.##..#.##..#..#.#..#...###",
	"..#..#.##......#....##.#######..#..##.....#.#.##..#..#..#.#.#..#.#..#.##...",
	"#.#.###.###..######.##....#####.####..#....##.##.##.....##..#..###...##..##",
	".##..#.#.###..##.....###.#.##.#..#.....#.##..#...#...###...#...##...#####.#",
	".....#....######..##.#..##..#...##.#.##.#..##...####.##..#.#.####.###......",
	"#..##....#.#.#.#....##..#....##...##.#...###.##..#....#.#...#.#..###...#..#",
	"...###.#.####..##...###.#.##.#..#.####.#.#.#####....####.#.#.#.##...#.##...",
	".#..##.#...#..##.######.#######.#.#...##...##..#.#.########..#..##.#..###..",
	"..#####.####.#.#.##........###...#..###...##...#...#....####...##.#.#######",
	"#.#####......###.#..###.....##..##...######.#..##.#.#.#######..##.####...#.",
	"#.#.#.#..##..#.##..###....##.#.##.####..#.#####..###......#...#..#..###....",
	"..#...#.##..##.#..#####.######...###...#...##..#.#####..#.###....#..#.#.#..",
	"###..#.#####.##.#.######..##.#####...#...#####.#.#.#.#...#.#.#.#....##....#",
	"#.#...###...#.#...####..........#####..###..#.#...####...#.#.###.#..####.##",
	"..#..##.###.##...####.#....#..##.....####.##.#.#....#..#..##.#..##.#.#..###",
	"..#......##.#.####..###.####..##.####.##...#.#.####.#.#..#..######.##.##.##",
	"....###...#.##.####....#...#.#..#..##.#.####...##...#...#.#.##...##.##..#.#",
	"######....#.#..####.#.#...#####.#.#..##.######.#.###.#.#.#....#...#....##..",
	"....####...#..#.#.#.####.#..#..###..#..#.##.########...#..#.#.........#.#..",
	"##....#.#.##.####.#.#..##.#..##.#.#.#.#.#.#..#######.##..#.##....####...###",
	"##.#.#.##.#...###.#...#...##..#.#.#...#....#...#....#.#..###.##.##...##....",
	".####....#.##...#.#.#.....#.#.#.#..#.....###.##.#..#...#...###.#..#.#..##.#",
	"##..#.#....##....#.##.##.#.###........#.#..#.#....#.#.###...####..##.####.#",
	".##.#..###..#.#...###.###.###.###.#.#...##.#.#.###.#.####.###.##...#.#.#...",
	".#.##.##..#.#.####..##.#####.#..#..####.###..###..####.....###.###.......#.",
	"##.#..#.#..###..#.....#.##.....#.#.#.##..######.#..#.#...#...##..###..##.#.",
	"##..##...#........##..##.######.#.####...#..#..####..#.##.#...#..#.##.#.##.",
	"#..#.##..###.#......####..##.##.#....#.###.##..#.#.#.##.##..#..#.##..##....",
	".....#....#.#.##..#.##....####.####.....#.###.#.#..#.#.....#..##..##.###...",
	".#......##....#.##.#...#.#####...##..##.....#.##.##.....#..#..##.#...#####.",
	"##.#...##...#....#.####.#.#....#.#..######..........####.....#.#.#......#..",
	"#.#.#....###..#..####..#.##...##.#####.#...#.#...###...#..##..##.####.#...#",
	"#...###.##.#..#.###..##...##.##..#...##.#....#.#.##.##....#.#....#...#####.",
	"#....##..####.....#.##.#####.#...##..##....#...###...#...#..#.#...#..#...##",
	"#..##.##.....##..#.###..........###...#.#...#..#..##..#...##.####.#....###.",
	".#....#..#..##.###..########.#......#...#..#..##.##....###.###.....#...##.#",
	"##..###.#....#.#...##.#.###.#.#..#..#..###.#...#.##.#####.#.#..##..#.#..#.#",
	"#.#.#...#....#####.####..#.##.####..#.#.#...#....#..#.###...###.###...#...#",
	".###..##.#..##..#..#...##.#.#...###..##.#.####.#....#.#...##....#....##..##",
	"..#.##..####.##..##...##..#.###.......#..####.##..#.#......#...##..###.....",
	"##....##.####.####..#.#.#..#####.....###.##..###..####.###.#####..#.....#.#",
	".####.#..#####.....#..######...##.#....####......######...###..###..#.#.###",
	".#..#.#.####.#.##........###.#.#.#.##.#..#...#......###.#.##.#..#.#...#...#",
	".#..#.##....#...#...#.##..#...##.....#..######..##.###...#..#..####..#.#.#.",
	"##.#.#.#..#.##..#.#......#.######..#####...#.##.###.######.#...#.###.##...#"
};

#endif