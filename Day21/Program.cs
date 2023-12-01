namespace Day21
{
    class Globals
    {
        public const bool IsPart1 = false;

        public static List<Ape> AllApes = new(3000);
        public static Ape? GetApe(string name) => AllApes.FirstOrDefault(ape => ape.name == name);
    }
    
    class Ape
    {
        public string name;
        public char operation = '='; // means directly yells a number
        public Ape? operandApe1;
        public Ape? operandApe2;
        public long number;

        public long GetResult()
        {
            if (name == "humn")
            {
                int k = 2;
            }

            if (operation == '=')
                return number;
            else
            {
                long num1 = operandApe1.GetResult();
                long num2 = operandApe2.GetResult();
                switch (operation)
                {
                    case '+':
                        return num1 + num2;
                    case '-':
                        return num1 - num2;
                    case '*':
                        return num1 * num2;
                    case '/':
                        return num1 / num2;
                }
                return -6666666;  //should never happen!
            }
        }
    }

    internal class Program
    {
        static void Main(string[] args)
        {
            var wholeInput = File.ReadAllLines("../../../Input.txt");  //TestInput
            foreach (var line in wholeInput)  //first we create ALL the apes
            {
                Globals.AllApes.Add(new Ape(){ name = line.Substring(0, 4)});
            }

            for (var index = 0; index < wholeInput.Length; index++)
            {
                var line = wholeInput[index];
                var currentApe = Globals.AllApes[index];
                int yellNumber;
                if (int.TryParse(line.Substring(6), out yellNumber))
                {
                    //cool, its a number-yell-ape
                    currentApe.number = yellNumber;
                }
                else
                {
                    //also cool, its a operation-yell-ape
                    currentApe.operandApe1 = Globals.GetApe(line.Substring(6, 4));
                    currentApe.operation = line.Substring(11, 1)[0];
                    currentApe.operandApe2 = Globals.GetApe(line.Substring(13, 4));
                }
            }

            if (Globals.IsPart1) //part1
            {
                var rootApe = Globals.GetApe("root");
                long result = rootApe.GetResult();
                Console.WriteLine($"Result of Root-Ape is: {result}");
            }
            else
            {
                var rootApe = Globals.GetApe("root"); //we need this for result checking
                var humanApe = Globals.GetApe("humn"); //we need this for result checking
                long number2 = rootApe.operandApe2.GetResult();

                long currentTestNumber = 0;
                long addFactor = 100000000000;
                while (true)
                {
                    humanApe.number = currentTestNumber;
                    long resultPos = rootApe.operandApe1.GetResult();
                    if (resultPos == number2)
                    {
                        Console.WriteLine($"You have to yell: {currentTestNumber}");
                        break;
                    }
                    if (resultPos > number2)
                        currentTestNumber += addFactor;
                    else
                    {
                        currentTestNumber -= addFactor;
                        addFactor /= 10;
                    }
                }
            }
            int pause = Console.Read();
        }
    }
}