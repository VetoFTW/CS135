#include "MemoryGame.hpp"
#include <cstdlib> //srand, rand
#include <ctime>
#include <vector>
#include <iomanip>  //setw
#include <iostream> //std
using namespace std;

int *randomize(int numSlots); // function to randomize layout
void swap(int *arr, int i, int j);
void displaySeparateLine(int numSlots);

// TODO: implement by students
MemoryGame::MemoryGame() // default constructor,
                         // set numPairs = 3, numSlots = 2 * numPairs + 2,
                         // put 3 pairs of randomly generated ints in [0, 1000)
                         // randomly in numSlots blocks.
                         // Note that 2 added after 2 * numPairs means number of
                         // two extra blocks without actual data.
{
    // srand(time(NULL)); // TODO: uncomment this line to see
    // different layouts of numbers in different runnings.
    // time(NULL) is the current running time.
    // use the current running time to grow random sequence
    // Since running time differs,
    // the random sequence looks different
    // at different running time.
    // or autograde script cannot handle random input.

    // TODO: your code here
    srand(1);      // TODO: add this before submitting to gradescope,
    numPairs = 3;  // do not write int numPairs = 3;
    numSlots = 8; // 3 pairs residing in 8 spaces,
    // IMPORTANT:
    // generate three random ints in [0, 1000),
    // randomly set them in the layout of the spaces,
    // that is, set up values array.
    // there are two empty spaces
    int randomInts[numPairs]; // contains 3 random ints
    values = new string[numSlots];
    for (int i = 0; i < numPairs; i++)
    {
        randomInts[i] = rand() % 1000;
    }

    string valuesReplication[8];
    for (int i = 0; i < numSlots; i++)
    {
        valuesReplication[i] = values[i]; // make a copy of values array in order to avoid changing indices
    }

    int *randomOrder = randomize(8); // contains random order

    values[randomOrder[0]] = to_string(randomInts[0]);
    values[randomOrder[1]] = to_string(randomInts[0]);
    values[randomOrder[2]] = to_string(randomInts[1]);
    values[randomOrder[3]] = to_string(randomInts[1]);
    values[randomOrder[4]] = to_string(randomInts[2]);
    values[randomOrder[5]] = to_string(randomInts[2]);
    values[randomOrder[6]] = "";
    values[randomOrder[7]] = "";
}

// TODO: implement by students
MemoryGame::~MemoryGame()
{
    // When an object is no longer in need,
    // release dynamically allocated memory by
    // data members of the current object.
    delete[] values;
    values = NULL;
}

// TODO: implement by students
// randomize is not a member function,
// so there is no MemoryGame:: before function name randomize.
// Return an array of randomly allocated 0, 1, .., size-1
// In constructors, randomly assign the data in dataVector
// to array values
int *randomize(int size)
{
    // idea to randomize 0, 1, 2, 3, 4, 5,
    // generate a random int in [0, 6), say 3,
    // then move arr[3] to the end,
    // say, 0, 1, 2, 5, 4, 3
    // generate a random int in [0, 5), say 3 again,
    // then swap arr[3], which is 5 now, with arr[4],
    // get 0, 1, 2, 4, 5, 3
    // generate a random int in [0, 4), say 2,
    // swap arr[2] with the current arr[3]
    // get 0, 1, 4, 2, 5, 3
    // continue to randomize arr[0..2].
    // afterwards, continue to randomize arr[0..1].

    // seed random values
    int *arr = new int[size]; // dynamically create array
    for (int i = 0; i < size; i++)
    {
        arr[i] = i; // 0, 1, 2, 3, 4, 5
    }

    int counter = size;
    int location = size - 1;
    for (int i = size - 1; i >= 0; i--)
    {
        int temp = rand() % (counter); // randomize the order
        swap(arr, temp, location);
        counter--;
        location--;
    }
    return arr;
}

// TODO: implement by students
// int* arr means int array arr, which implies the address
// of the first element of array arr.
// swap arr[i] and arr[j] in array of ints arr.
void swap(int *arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// Display -----+ for numSlots times.
// Add an extra + when for the first block (when index i is 0).
// So suppose numSlots is 8, we get
//+-----+-----+-----+-----+-----+-----+-----+-----+
// followed by a new line.
void displaySeparateLine(int numSlots)
{
    for (int i = 0; i < numSlots; i++) // added equal to sign here
    {
        if (i == 0)
            cout << "+";
        cout << "-----+";
    }
    cout << endl;
}

// TODO: implement by students
// display the items in values array where bShown is true.
void MemoryGame::display(bool *bShown)
{
    cout << " ";
    for (int i = 0; i < numSlots; i++)
        cout << setw(3) << i << setw(3) << " "; // print out index with proper spacing
    cout << "\n";

    displaySeparateLine(numSlots);

    cout << "|"; // show pipe for first character

    for (int i = 0; i < numSlots; i++)
    {
        if (bShown[i])
        {
            cout << setw(5) << right << values[i] << '|'; // pipe after each character with proper indentation / spaces
        }
        else
        {
            cout << setw(5) << " " << '|'; // show nothing when not true
        }
    }

    cout << "\n";
    displaySeparateLine(numSlots);
}

// TODO: implement by students
// rules for a round
//(1) pick a number, flip it
//(2) pick a second number, if the number is the same as
//     previous pick, display the second number,
//     otherwise, unflip the previous pick.
//(3) Finish until every pair are chosen correctly.
void MemoryGame::play()
{
    int index;
    int pairsFound = 0;
    int pairsFound2 = 0;
    int first;
    int numFlips = 0;
    bool *bShown = new bool[numSlots];
    for (int i = 0; i < numSlots; i++)
    {
        bShown[i] = false;
    }
    vector<int> locationToBeTrue;

    while (pairsFound < numPairs)
    {
        if (numFlips == 0)
            display(bShown);

        cout << "Pick a cell to flip: "; // ask user to flip random cell
        cin >> index;
        while (bShown[index] == true || index < 0 || index > 7)
        {
            if (index < 0 || index > 7)
            {
                cout << "index needs to be in range [0, 7].\n";
                cout << "Re-enter an index: ";
                cin >> index;
            }
            else
            {
                cout << "The cell indexed at " << index << " is shown.\n";
                cout << "Re-enter an index: ";
                cin >> index;
            }
        }
        if ((pairsFound2 % 2 == 0) && values[index] != "" && numFlips % 2 == 0)
        {
            bShown[index] = true;
            first = index;
            pairsFound2++;
        }
        else
        {
            if (values[index] == values[first] && values[index] != "")
            {
                bShown[index] = true;
                pairsFound2++;
                locationToBeTrue.push_back(first);
                locationToBeTrue.push_back(index);
            }
            else
            {
                pairsFound2 = 0;

                for (int i = 0; i < numSlots; i++)
                {
                    bShown[i] = false;
                }
                for (int i = 0; i < locationToBeTrue.size(); i++)
                {
                    bShown[locationToBeTrue[i]] = true;
                }
            }
        }
        if (pairsFound2 == 0)
        {
            pairsFound = 0;
        }
        else
        {
            pairsFound = (locationToBeTrue.size() / 2);
        }
        
        display(bShown);
        numFlips++;
    }

    cout << "Congratulations! Take " << numFlips << " steps to find all matched pairs." << endl;

    delete[] bShown;
    bShown = nullptr;
}
