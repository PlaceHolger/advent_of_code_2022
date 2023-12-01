using Microsoft.VisualBasic;

namespace Day18
{
    public class Playfield
    {
        public enum eType
        {
            AIR = 0,
            LAVA = 1,
            WATER = 2,
        };

        public const uint SIZE = 20;
        public eType[,,] elements = new eType[SIZE, SIZE, SIZE];

        public void InitFromFile(string filename = "Input.txt")
        {
            string[] allLines = File.ReadAllLines(filename);
            var allValues = allLines.Select(line => line.Split(",").Select(int.Parse).ToArray());

            foreach (var pos in allValues)
                elements[pos[0], pos[1], pos[2]] = eType.LAVA;
        }

        public uint CalculateFacesTouching(eType allowedOutside)
        {
            uint[] faces = new uint[6];
            for (uint x = 0; x < SIZE; ++x)
            {
                for (uint y = 0; y < SIZE; ++y)
                {
                    for (uint z = 0; z < SIZE; ++z)
                    {
                        if (elements[x, y, z] == eType.LAVA) //cube at this pos
                        {
                            if(x == SIZE - 1 || elements[x + 1, y, z] == allowedOutside) //right border or no right neighbor => right face
                                faces[0]++;
                            if(x == 0 || elements[x - 1, y, z] == allowedOutside) //left border or no left neighbor => left face
                                faces[1]++;

                            if(y == SIZE - 1 || elements[x, y + 1, z] == allowedOutside) //down face
                                faces[2]++;
                            if(y == 0 || elements[x, y - 1, z] == allowedOutside) //up face
                                faces[3]++;

                            if(z == SIZE - 1 || elements[x, y, z + 1] == allowedOutside) //back face
                                faces[4]++;
                            if(z == 0 || elements[x, y, z - 1] == allowedOutside) //front face
                                faces[5]++;
                        }
                    }
                }
            }
            return faces[0] + faces[1] + faces[2] + faces[3] + faces[4] + faces[5];
        }

        public void FloodFill(int x, int y, int z, eType oldElement, eType newElement)
        {
            if (x >= 0 && x < SIZE && y >= 0 && y < SIZE && z >= 0 && z < SIZE && elements[x, y, z] == oldElement)
            {
                elements[x, y, z] = newElement;
                FloodFill(x + 1, y, z, oldElement, newElement);
                FloodFill(x - 1, y, z, oldElement, newElement);
                FloodFill(x, y + 1, z, oldElement, newElement);
                FloodFill(x, y - 1, z, oldElement, newElement);
                FloodFill(x, y, z + 1, oldElement, newElement);
                FloodFill(x, y, z - 1, oldElement, newElement);
            }
        }
    }

    internal class Program
    {
        static void Main(string[] args)
        {
            Playfield playfield = new Playfield();
            playfield.InitFromFile();

            Console.WriteLine($"Part 1: Amount of faces touching air: {playfield.CalculateFacesTouching(Playfield.eType.AIR)}");    //part 1
            playfield.FloodFill(0,0,0, Playfield.eType.AIR, Playfield.eType.WATER);
            Console.WriteLine($"Amount of faces touching water: {playfield.CalculateFacesTouching(Playfield.eType.WATER)}");  //part 2
        }
    }
}