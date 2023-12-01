using System.Security.Cryptography.X509Certificates;
using System.Xml;

namespace Day14
{
    class Point
    {
        public Point(Point other)
        {
            x = other.x;
            y = other.y;
        }
        public Point(int _x, int _y)
        {
            x = _x;
            y = _y;
        }
        public int x;
        public int y;
    }

    class Playfield
    {
        //for day1 this is enough
        //private const int START_X = 480;
        //private const int START_Y = 0;
        //private const int HEIGHT = 180;
        //private const int WIDTH = 100;
        public const int START_X = 140;
        public const int START_Y = 0;
        public const int HEIGHT = 180;
        public const int WIDTH = 600;

        private static readonly Point SandStartPos = new(500 - START_X, 0);
        public int AbyssY = 0;

        Point? lastLinePoints;

        public void StartWall()
        {
            lastLinePoints = null;
        }

        private const float numSegmentations = 3000.0f;

        public void AddWallPoint(int _x, int _y)
        {
            if (lastLinePoints != null)
            {
                float dx = ((float)_x - lastLinePoints.x) / numSegmentations;
                float dy = ((float)_y - lastLinePoints.y) / numSegmentations;

                for (int i = 0; i < (int)numSegmentations; i++)
                {
                    playfieldObjects[ (int)Math.Round(lastLinePoints.y + i * dy - START_Y), (int)Math.Round(lastLinePoints.x + i * dx - START_X)] = eObject.WALL;
                }
            }
            lastLinePoints = new Point(_x, _y);
            if(AbyssY - START_Y < _y - START_Y)
                AbyssY = _y - START_Y;
        }

        public void Draw()
        {
            Console.SetCursorPosition(0,0);
            Console.Clear();

            int sandCounter = 0;

            for (int y = 0; y < HEIGHT; y++)
            {
                for (int x = 0; x < WIDTH; x++)
                {
                    if (SandStartPos.x == x && SandStartPos.y == y)
                    {
                        Console.ForegroundColor = ConsoleColor.Red;
                        Console.Write("+");
                    }
                    else if(GetObject(x, y) == eObject.WALL)
                    {
                        Console.ForegroundColor = ConsoleColor.DarkBlue;
                        Console.Write("#");
                    }
                        
                    else if(GetObject(x, y) == eObject.SAND)
                    {
                        Console.ForegroundColor = ConsoleColor.Yellow;
                        Console.Write("o");
                        sandCounter++;
                    }
                    else
                    {
                        Console.ForegroundColor = ConsoleColor.DarkGray;
                        Console.Write(".");
                    }
                        
                }
                Console.Write("\n");
            }
            Console.ResetColor();
        }

        private int numRestingSands = 0;

        private Point? curSandPos;
        public void SimulateSand()
        {
            //for (int i = 0; i < 50000000; i++)
            while(true)
            {
                curSandPos ??= new Point(SandStartPos);
                
                if (curSandPos.y + 1 > AbyssY + 3) //did we reach 'the void'?
                {
                    Draw();
                    Console.WriteLine($"Resting Sand: {numRestingSands}");
                    break;
                }
                else if (GetObject(curSandPos.x, curSandPos.y + 1) == eObject.AIR) //first we try going down
                {
                    curSandPos.y++;
                }
                else if (GetObject(curSandPos.x - 1, curSandPos.y + 1) == eObject.AIR) //second we try diagonal left
                {
                    curSandPos.x--;
                    curSandPos.y++;
                }
                else if (GetObject(curSandPos.x + 1, curSandPos.y + 1) == eObject.AIR) //third we try diagonal right
                {
                    curSandPos.x++;
                    curSandPos.y++;
                }
                else
                {
                    if (curSandPos.y == SandStartPos.y) //we reached the start
                    {
                        Draw();
                        Console.WriteLine($"Resting Sand: {numRestingSands}");
                        break;
                    }

                    //we reached equilibrium
                    SetObject(curSandPos.x, curSandPos.y, eObject.SAND);
                    curSandPos = null;
                    numRestingSands++;
                }
            }
            Draw();
        }

        void SetObject(int x, int y, eObject obstacle) => playfieldObjects[y, x] = obstacle;
        eObject GetObject(int x, int y) => playfieldObjects[y, x];

        enum eObject
        {
            AIR = 0,
            WALL,
            SAND
        }

        eObject[,] playfieldObjects = new eObject[HEIGHT,WIDTH];
    }
    
    internal class Program
    {
        static void Main(string[] args)
        {
            Playfield playfield = new Playfield();

            var wholeInput = File.ReadAllLines("Input.txt");
            var allLines = wholeInput.Select(line => line.Split(" -> ").Select(point => point.Split(',').Select(int.Parse).ToArray()));

            foreach (var line in allLines)
            {
                playfield.StartWall();
                foreach (var point in line)
                {
                    playfield.AddWallPoint(point[0], point[1]);
                }
            }
     
            //part 1
            //playfield.SimulateSand();

            //part 2
            playfield.StartWall();
            playfield.AddWallPoint(Playfield.START_X, playfield.AbyssY + 2);
            playfield.AddWallPoint(Playfield.START_X + Playfield.WIDTH - 1, playfield.AbyssY);
           // playfield.Draw();
            playfield.SimulateSand();


            string notUsed = Console.ReadLine();
        }
    }
}