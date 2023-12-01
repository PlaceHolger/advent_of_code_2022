//#define PART2

List<IndexedNumber> originalEncryptedFile;
List<IndexedNumber> mixedEncryptedFile;

short currentIndex = 0;

#if PART2
const int numMixes = 10;
const long magicNumber = 811589153;
#else
const int numMixes = 1;
const long magicNumber = 1;
#endif

var wholeInput = File.ReadAllLines("../../../Input.txt").Select(long.Parse);  //TestInput
originalEncryptedFile = new List<IndexedNumber>(wholeInput.Count());
mixedEncryptedFile = new List<IndexedNumber>(wholeInput.Count());
foreach (var inputNum in wholeInput)
{
    var newEntry = new IndexedNumber() { id = currentIndex++, value = inputNum * magicNumber};
    originalEncryptedFile.Add(newEntry);
    mixedEncryptedFile.Add(newEntry);
}
int mixedMaxIndex = mixedEncryptedFile.Count() - 1;

for (int i = 0; i < numMixes; i++)
{
    foreach (var orgNumber in originalEncryptedFile)
    {
        //todo: optimize: we can probably assume, that the original file is still somewhat nearby the initial position in the array
        for (int iMixedPos = 0; iMixedPos <= mixedMaxIndex; iMixedPos++)
        {
            if (mixedEncryptedFile[iMixedPos].id == orgNumber.id)
            {
                int targetPos = (int)((iMixedPos + orgNumber.value) % (mixedMaxIndex));
                if (targetPos <= 0 && iMixedPos + orgNumber.value != 0) //flip from left
                    targetPos += mixedMaxIndex;

                if (targetPos != iMixedPos)
                {
                    var insertAfterElement = mixedEncryptedFile[targetPos];
                    Console.WriteLine($"Moved '{orgNumber.value}' to position {targetPos}, after number '{insertAfterElement.value}'");
                    mixedEncryptedFile.RemoveAt(iMixedPos);
                    mixedEncryptedFile.Insert(targetPos, orgNumber);
                }
                else 
                    Console.WriteLine($"No Need to Move '{orgNumber.value}' from position {iMixedPos} to position {targetPos}");

                if(mixedMaxIndex < 100)
                    DrawMixedLine();
                break;
            }
        }
    }
}

//find 0
long sum = 0;
for (int iMixedPos = 0; iMixedPos <= mixedMaxIndex; iMixedPos++)
{
    if (mixedEncryptedFile[iMixedPos].value == 0)
    {
        sum += mixedEncryptedFile[(iMixedPos + 1000) % mixedEncryptedFile.Count()].value;
        sum += mixedEncryptedFile[(iMixedPos + 2000) % mixedEncryptedFile.Count()].value;
        sum += mixedEncryptedFile[(iMixedPos + 3000) % mixedEncryptedFile.Count()].value;
        break;
    }
}

Console.WriteLine($"Solution Sum is: {sum}");
return;

void DrawMixedLine()
{
    foreach (var VARIABLE in mixedEncryptedFile)
        Console.Write($"{VARIABLE.value}, ");
    Console.Write("\n");
}

class IndexedNumber
{
    public short id; //the original position in the array
    public long value;
}