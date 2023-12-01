// Day22.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <cassert>
#include <iostream>
#include "Day22Data.h"

typedef long long int inclusiveBool;


//constexpr auto& g_UsedPlayfield = g_TestPlayfield; //g_Playfield 
//constexpr auto& g_UsedPath = g_TestPath; //g_Path
//constexpr int g_PlayFieldWidth = 16; // 16 for test, 150 for playfield... there must be a way to get that value at compile time...

constexpr auto& g_UsedPlayfield = g_Playfield;
constexpr auto& g_UsedPath = g_Path;
constexpr int g_PlayFieldWidth = 150;

constexpr int g_PlayFieldHeight = std::size(g_UsedPlayfield);

char debugOutput[g_PlayFieldHeight][g_PlayFieldWidth];

enum eObstacles : char
{
	SPACE = ' ',
    WALL = '#',
    GROUND = '.',
    UNDEFINED = -1
};

struct CPosition
{
    int x;
    int y;
};

enum eDir
{
    RIGHT = 0,
    DOWN = 1,
    LEFT = 2,
    UP = 3,
    COUNT
};

//some precomputes to make wrapping around easier
int g_FirstPositionForLine[g_PlayFieldHeight];
int g_LastPositionForLine[g_PlayFieldHeight];
eObstacles g_FirstObstacleForLine[g_PlayFieldHeight];
eObstacles g_LastObstacleForLine[g_PlayFieldHeight];

int g_FirstPositionForColumn[g_PlayFieldWidth];
int g_LastPositionForColumn[g_PlayFieldWidth];
eObstacles g_FirstObstacleForColumn[g_PlayFieldWidth];
eObstacles g_LastObstacleForColumn[g_PlayFieldWidth];

class CPlayer
{
public:
    CPlayer(CPosition startPos) : m_Pos(startPos) {}
    const CPosition& GetPosition() const { return m_Pos; }
    eDir GetDirection() const { return m_Direction; }

    void MoveForward(const int stepsToMove)
    {
        switch (m_Direction)
    	{
	    	case RIGHT:
		        for (int i = 0; i < stepsToMove; ++i)
		        {
                    assert(m_Pos.x >= 0 && m_Pos.x <= g_LastPositionForLine[m_Pos.y]);
                    assert(m_Pos.y >= 0 && m_Pos.y <= g_PlayFieldHeight);
                    debugOutput[m_Pos.y][m_Pos.x] = '>';
                    if (!MoveRight())  //move if possible
                        return;
                }
                break;
			case DOWN:
                for (int i = 0; i < stepsToMove; ++i)
                {
                    assert(m_Pos.x >= 0 && m_Pos.x <= g_LastPositionForLine[m_Pos.y]);
                    assert(m_Pos.y >= 0 && m_Pos.y <= g_PlayFieldHeight);
                    debugOutput[m_Pos.y][m_Pos.x] = 'v';
                    if (!MoveDown())  //move if possible
                        return;
                }
                break;
			case LEFT:
                for (int i = 0; i < stepsToMove; ++i)
                {
                    assert(m_Pos.x >= 0 && m_Pos.x <= g_LastPositionForLine[m_Pos.y]);
                    assert(m_Pos.y >= 0 && m_Pos.y <= g_PlayFieldHeight);
                    debugOutput[m_Pos.y][m_Pos.x] = '<';
                    if (!MoveLeft())  //move if possible
                        return;
                }
                break;
			case UP:
                for (int i = 0; i < stepsToMove; ++i)
                {
                    assert(m_Pos.x >= 0 && m_Pos.x <= g_LastPositionForLine[m_Pos.y]);
                    assert(m_Pos.y >= 0 && m_Pos.y <= g_PlayFieldHeight);
                    debugOutput[m_Pos.y][m_Pos.x] = '^';
                    if (!MoveUp())  //move if possible
                        return;
                }
                break;
    	}
    }

    void RotateLeft()
    {
        if (m_Direction == RIGHT)
            m_Direction = UP;
        else
			m_Direction = (eDir)(m_Direction - 1);
    }

    void RotateRight()
    {
    	m_Direction = (eDir)((m_Direction + 1) % COUNT);
    }

private:
    bool MoveRight()
    {
        const eObstacles targetFieldObstacle = (m_Pos.x >= g_LastPositionForLine[m_Pos.y]) ? SPACE : (eObstacles)g_UsedPlayfield[m_Pos.y][m_Pos.x + 1];
        if (targetFieldObstacle == eObstacles::WALL) //wall, we cannot move
            return false;  
        if (targetFieldObstacle == eObstacles::SPACE) //space, we can maybe move
        {
            if (g_FirstObstacleForLine[m_Pos.y] == eObstacles::WALL) //we cannot wrap, other side is blocked
                return false;
            m_Pos.x = g_FirstPositionForLine[m_Pos.y]; //we wrapped to left border
            return true;
        }
        ++m_Pos.x;
        return true;
    }
    bool MoveLeft()
    {
        const eObstacles targetFieldObstacle = (m_Pos.x == 0) ? SPACE : (eObstacles)g_UsedPlayfield[m_Pos.y][m_Pos.x - 1];
        if (targetFieldObstacle == eObstacles::WALL) //wall, we cannot move
            return false;
        if (targetFieldObstacle == eObstacles::SPACE) //space, we can maybe move
        {
            if (g_LastObstacleForLine[m_Pos.y] == eObstacles::WALL) //we cannot wrap, other side is blocked
                return false;
            m_Pos.x = g_LastPositionForLine[m_Pos.y]; //we wrapped to right border
            return true;
        }
        --m_Pos.x;
        return true;
    }
    bool MoveUp()
    {
        const eObstacles targetFieldObstacle = (m_Pos.y == 0) ? SPACE : (eObstacles)g_UsedPlayfield[m_Pos.y - 1][m_Pos.x];
        if (targetFieldObstacle == eObstacles::WALL) //wall, we cannot move
            return false;                
        if (targetFieldObstacle == eObstacles::SPACE) //space, we can maybe move
        {
            if (g_LastObstacleForColumn[m_Pos.x] == eObstacles::WALL) //we cannot wrap, other side is blocked
                return false;
            m_Pos.y = g_LastPositionForColumn[m_Pos.x]; //we wrapped to bottom border
            return true;
        }
        --m_Pos.y;
        return true;
    }
    bool MoveDown()
    {
        const eObstacles targetFieldObstacle = (m_Pos.y >= g_LastPositionForColumn[m_Pos.x]) ? SPACE : (eObstacles)g_UsedPlayfield[m_Pos.y + 1][m_Pos.x];
        if (targetFieldObstacle == eObstacles::WALL) //wall, we cannot move
            return false;                
        if (targetFieldObstacle == eObstacles::SPACE) //space, we can maybe move
        {
            if (g_FirstObstacleForColumn[m_Pos.x] == eObstacles::WALL) //we cannot wrap, other side is blocked
                return false;
            m_Pos.y = g_FirstPositionForColumn[m_Pos.x]; //we wrapped to upper border
            return true;
        }
        ++m_Pos.y;
        return true;
    }


    CPosition m_Pos;
    eDir m_Direction = RIGHT;

};

int main()
{    
    memset(g_FirstObstacleForColumn, UNDEFINED, sizeof(g_FirstObstacleForColumn));

    //precomputing
	for (int y = 0; y < g_PlayFieldHeight; ++y)
	{
        const int numObjectsInLine = (int)strlen(g_UsedPlayfield[y]) - 1;
        for (int x = 0; x <= numObjectsInLine; ++x)
        {
            if (g_UsedPlayfield[y][x] == ' ') //Space, skip
                continue;
            g_FirstObstacleForLine[y] = (eObstacles)g_UsedPlayfield[y][x];
            g_FirstPositionForLine[y] = x;
            break;
        }
        g_LastObstacleForLine[y] = (eObstacles)g_UsedPlayfield[y][numObjectsInLine];
        g_LastPositionForLine[y] = numObjectsInLine;

        for (int x = 0; x <= numObjectsInLine; ++x)
        {
            if (g_UsedPlayfield[y][x] == ' ') //Space, skip
                continue;
            if(g_FirstObstacleForColumn[x] == UNDEFINED)
            {
                g_FirstObstacleForColumn[x] = (eObstacles)g_UsedPlayfield[y][x];
                g_FirstPositionForColumn[x] = y;
            }
            g_LastObstacleForColumn[x] = (eObstacles)g_UsedPlayfield[y][x];
            g_LastPositionForColumn[x] = y;
        }
	}

    CPlayer player(CPosition { g_FirstPositionForLine[0], 0 });  //start most left, on top line

    //memset(debugOutput, ' ', g_PlayFieldWidth * g_PlayFieldHeight);
    //for (int y = 0; y < g_PlayFieldHeight; ++y)
    //{
    //    const int numObjectsInLine = (int)strlen(g_UsedPlayfield[y]) - 1;
    //    for (int x = 0; x <= numObjectsInLine; ++x)
    //    {
    //        debugOutput[y][x] = g_UsedPlayfield[y][x];
    //    }
    //}

    const size_t pathLength = strlen(g_UsedPath);
    for (int i = 0; i < pathLength; ++i)
    {
        if (g_UsedPath[i] == 'L')
            player.RotateLeft();
        else if (g_UsedPath[i] == 'R')
            player.RotateRight();
        else
        {
            int stepsToMove = atoi(g_UsedPath + i);
            if (stepsToMove > 9)
                ++i;
            player.MoveForward(stepsToMove);

            ////if(i % 5 == 0)
            //{
            //    system("cls");
            //    for (int y = 0; y < g_PlayFieldHeight; ++y)
            //    {
            //        const int numObjectsInLine = (int)strlen(g_UsedPlayfield[y]) - 1;
            //        for (int x = 0; x <= numObjectsInLine; ++x)
            //        {
            //            std::cout << debugOutput[y][x];
            //        }
            //        std::cout << "\n";
            //    }
            //}

        }
    }


    //for (int y = 0; y < g_PlayFieldHeight; ++y)
    //{
    //    const int numObjectsInLine = (int)strlen(g_UsedPlayfield[y]) - 1;
    //    for (int x = 0; x <= numObjectsInLine; ++x)
    //    {
    //        std::cout << debugOutput[y][x];
    //    }
    //    std::cout << "\n";
    //}

    std::cout << "Passwort is: " << 1000 * (player.GetPosition().y + 1) + 4 * (player.GetPosition().x + 1) + player.GetDirection();
    int pause = getchar();
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
