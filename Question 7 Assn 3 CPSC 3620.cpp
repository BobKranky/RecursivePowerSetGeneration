// Hasan Raza
// Recursive decrease-by-one algorithm for generating the power set of a set of n elements

#include <iostream>
#include <vector>
#include <queue>
#include <set>

// Question 3
void generateSequence(int N)
{
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq; // Priority queue to get numbers in ascending order because we want to always use the smallest number first for our calculations.
    std::set<int> seen;                                               // To avoid duplicates

    // We will first insert 1 into the priority queue because the first number is: 2^0 * 3^0 = 1
    pq.push(1);
    seen.insert(1);
    std::cout << "First " << N << " numbers in sequence: ";

    while (N > 0)
    {
        N--;

        int curr = pq.top();                      // Gets first/smallest number from priority queue to multiply by 2 and 3
        pq.pop();                                 // Pops it to prevent doing it again
        std::cout << curr << (N > 0 ? ", " : ""); // Prints the number

        // Generates the next possible numbers by multiplying by 2 and 3
        if (seen.find(curr * 2) == seen.end()) // Checks if the number we are currently handling is in the set of already used numbers, meaning we've already had that result
        {
            pq.push(curr * 2);
            seen.insert(curr * 2);
        }
        if (seen.find(curr * 3) == seen.end())
        {
            pq.push(curr * 3);
            seen.insert(curr * 3);
        }
    }
    std::cout << std::endl;
}

// Question 7
// Initialize sets to hold variables, these sets are only for organization and are not the powerset
std::set<std::set<int>> emptyVarSubsets; // List for empty set
std::set<std::set<int>> oneVarSubsets;   // List for single value sets
std::set<std::set<int>> twoVarSubsets;   // List for two value sets
std::set<std::set<int>> threeVarSubsets; // List for three value sets
std::set<std::set<int>> fourVarSubsets;  // List for four value sets
std::set<std::set<int>> fiveVarSubsets;  // List for five value sets

// Power set
std::set<std::set<int>> powerSet;
std::set<int> powersubSet;

void printList(std::set<std::set<int>> &printListVarSubsets) // Function to print the lists. I used a single function for all lists to reduce redundant code
{
    for (const auto &printListsubset : printListVarSubsets)
    {
        std::cout << "{ ";
        for (const auto &elem : printListsubset)
        {
            std::cout << elem << " ";
        }
        std::cout << "}, ";
    }
    std::cout << std::endl;
}

void decreaseByOnePowSet(int numVariables)
{
    // Generates variables based on N
    std::vector<int> variables;
    for (int i = 0; i < numVariables; i++)
    {
        variables.push_back(i + 1);
    }
    std::cout << std::endl;
    // Creates all subsets involving end variable of variables() vector.
    // Accomplishes this by removing the end variable, and using it to create all subsets in which it is present

    int lastVariable = variables.back(); // Assigns the variable at the back of Variables() to lastVariable

    variables.pop_back(); // Pops back of variables() to keep size accurate
                          // Decrements numVariables to account for reduction in size of variables

    std::cout << "End variable is: " << lastVariable << ". Beginning new loop with " << numVariables << " variables. " << std::endl;

    // Creates subset with lastVariable and 4 other variables,
    {
        for (int i = 0; i < numVariables; i++)
        {
            for (int j = i; j < numVariables; j++)
            {
                for (int k = j; k < numVariables; k++)
                {
                    for (int l = k; l < numVariables; l++)
                    {
                        std::set<int> emptysubSet;
                        std::set<int> onesubSet;
                        std::set<int> twosubSet;
                        std::set<int> threesubSet;
                        std::set<int> foursubSet;
                        std::set<int> fivesubSet;

                        emptysubSet = {};
                        onesubSet = {lastVariable};
                        twosubSet = {variables[i], lastVariable};
                        threesubSet = {variables[i], variables[j], lastVariable};
                        foursubSet = {variables[i], variables[j], variables[k], lastVariable};
                        fivesubSet = {variables[i], variables[j], variables[k], variables[l], lastVariable};

                        emptyVarSubsets.insert(emptysubSet);
                        powerSet.insert(emptysubSet);

                        // Safety checks to make sure that nothing is being assigned to the wrong list
                        if (onesubSet.size() == 1)
                        {
                            powerSet.insert(onesubSet);
                            oneVarSubsets.insert(onesubSet);
                        }
                        if (twosubSet.size() == 2)
                        {
                            powerSet.insert(twosubSet);
                            twoVarSubsets.insert(twosubSet);
                        }
                        if (threesubSet.size() == 3)
                        {
                            powerSet.insert(threesubSet);
                            threeVarSubsets.insert(threesubSet);
                        }
                        if (foursubSet.size() == 4)
                        {
                            powerSet.insert(foursubSet);
                            fourVarSubsets.insert(foursubSet);
                        }
                        if (fivesubSet.size() == 5)
                        {
                            powerSet.insert(fivesubSet);
                            fiveVarSubsets.insert(fivesubSet);
                        }
                    }
                }
            }
        }
    }
    numVariables--;
    if (numVariables == 0)
    {
        // Prints the lists so you can see progression of my algorithm
        std::cout << "Printing empty subset" << std::endl;
        printList(emptyVarSubsets);
        std::cout << "Printing subsets of 1 variables" << std::endl;
        printList(oneVarSubsets);
        std::cout << "Printing subsets of 2 variables" << std::endl;
        printList(twoVarSubsets);
        std::cout << "Printing subsets of 3 variables" << std::endl;
        printList(threeVarSubsets);
        std::cout << "Printing subset of 4 variables" << std::endl;
        printList(fourVarSubsets);
        std::cout << "Printing subset of 5 variables" << std::endl;
        printList(fiveVarSubsets);
    }
    else
    {
        // Prints the lists so you can see progression of my algorithm
        std::cout << "Printing empty subset" << std::endl;
        printList(emptyVarSubsets);
        std::cout << "Printing subsets of 1 variables" << std::endl;
        printList(oneVarSubsets);
        std::cout << "Printing subsets of 2 variables" << std::endl;
        printList(twoVarSubsets);
        std::cout << "Printing subsets of 3 variables" << std::endl;
        printList(threeVarSubsets);
        std::cout << "Printing subset of 4 variables" << std::endl;
        printList(fourVarSubsets);
        std::cout << "Printing subset of 5 variables" << std::endl;
        printList(fiveVarSubsets);
        decreaseByOnePowSet(numVariables); // Recuresively calls function
    }

    std::cout << " " << std::endl;

    // Uncomment these lines if you wish to see the full power set.
    // std::cout << "Printing power subset" << std::endl;
    // printList(powerSet);
}

int main()
{
    int N;
    std::cout << "Enter N, input smaller than or equal to 5 are preferable... ";
    std::cin >> N;
    while (N < 0)
    {
        std::cout << "Invalid input, please try again... ";
        std::cin >> N;
    }

    std::cout << "Valid input...";
    decreaseByOnePowSet(N);

    int Y;
    std::cout << "Enter Number: ";
    std::cin >> Y;
    while (Y < 0)
    {
        std::cout << "Invalid input, please try again... ";
        std::cin >> Y;
    }

    std::cout << "Valid input...";
    generateSequence(Y);
    return 0;
}

// Enter N, input smaller than or equal to 5 are preferable... 5
// Valid input...
// End variable is: 5. Beginning new loop with 5 variables. 
// Printing empty subset
// { }, 
// Printing subsets of 1 variables
// { 5 }, 
// Printing subsets of 2 variables
// { 1 5 }, { 2 5 }, { 3 5 }, { 4 5 }, 
// Printing subsets of 3 variables
// { 1 2 5 }, { 1 3 5 }, { 1 4 5 }, { 2 3 5 }, { 2 4 5 }, { 3 4 5 },
// Printing subset of 4 variables
// { 1 2 3 5 }, { 1 2 4 5 }, { 1 3 4 5 }, { 2 3 4 5 },
// Printing subset of 5 variables
// { 1 2 3 4 5 },

// End variable is: 4. Beginning new loop with 4 variables.
// Printing empty subset
// { },
// Printing subsets of 1 variables
// { 4 }, { 5 },
// Printing subsets of 2 variables
// { 1 4 }, { 1 5 }, { 2 4 }, { 2 5 }, { 3 4 }, { 3 5 }, { 4 5 },
// Printing subsets of 3 variables
// { 1 2 4 }, { 1 2 5 }, { 1 3 4 }, { 1 3 5 }, { 1 4 5 }, { 2 3 4 }, { 2 3 5 }, { 2 4 5 }, { 3 4 5 },
// Printing subset of 4 variables
// { 1 2 3 4 }, { 1 2 3 5 }, { 1 2 4 5 }, { 1 3 4 5 }, { 2 3 4 5 },
// Printing subset of 5 variables
// { 1 2 3 4 5 },

// End variable is: 3. Beginning new loop with 3 variables.
// Printing empty subset
// { },
// Printing subsets of 1 variables
// { 3 }, { 4 }, { 5 },
// Printing subsets of 2 variables
// { 1 3 }, { 1 4 }, { 1 5 }, { 2 3 }, { 2 4 }, { 2 5 }, { 3 4 }, { 3 5 }, { 4 5 },
// Printing subsets of 3 variables
// { 1 2 3 }, { 1 2 4 }, { 1 2 5 }, { 1 3 4 }, { 1 3 5 }, { 1 4 5 }, { 2 3 4 }, { 2 3 5 }, { 2 4 5 }, { 3 4 5 },
// Printing subset of 4 variables
// { 1 2 3 4 }, { 1 2 3 5 }, { 1 2 4 5 }, { 1 3 4 5 }, { 2 3 4 5 },
// Printing subset of 5 variables
// { 1 2 3 4 5 },

// End variable is: 2. Beginning new loop with 2 variables.
// Printing empty subset
// { },
// Printing subsets of 1 variables
// { 2 }, { 3 }, { 4 }, { 5 },
// Printing subsets of 2 variables
// { 1 2 }, { 1 3 }, { 1 4 }, { 1 5 }, { 2 3 }, { 2 4 }, { 2 5 }, { 3 4 }, { 3 5 }, { 4 5 },
// Printing subsets of 3 variables
// { 1 2 3 }, { 1 2 4 }, { 1 2 5 }, { 1 3 4 }, { 1 3 5 }, { 1 4 5 }, { 2 3 4 }, { 2 3 5 }, { 2 4 5 }, { 3 4 5 },
// Printing subset of 4 variables
// { 1 2 3 4 }, { 1 2 3 5 }, { 1 2 4 5 }, { 1 3 4 5 }, { 2 3 4 5 },
// Printing subset of 5 variables
// { 1 2 3 4 5 },

// End variable is: 1. Beginning new loop with 1 variables.
// Printing empty subset
// { },
// Printing subsets of 1 variables
// { 1 }, { 2 }, { 3 }, { 4 }, { 5 },
// Printing subsets of 2 variables
// { 1 2 }, { 1 3 }, { 1 4 }, { 1 5 }, { 2 3 }, { 2 4 }, { 2 5 }, { 3 4 }, { 3 5 }, { 4 5 }, 
// Printing subsets of 3 variables
// { 1 2 3 }, { 1 2 4 }, { 1 2 5 }, { 1 3 4 }, { 1 3 5 }, { 1 4 5 }, { 2 3 4 }, { 2 3 5 }, { 2 4 5 }, { 3 4 5 },
// Printing subset of 4 variables
// { 1 2 3 4 }, { 1 2 3 5 }, { 1 2 4 5 }, { 1 3 4 5 }, { 2 3 4 5 },
// Printing subset of 5 variables
// { 1 2 3 4 5 },