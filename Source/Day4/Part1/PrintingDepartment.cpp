#include <iostream>
#include <fstream>

constexpr char RollOfPaper = '@';

bool inline RollIsAtPosition(std::string const currentRow, size_t const currentPosition)
{
    return (currentRow.find(RollOfPaper, currentPosition) == currentPosition);
}

int GetNumberOfSurroundingRolls(
    std::string const previousRow,
    std::string const currentRow,
    std::string const nextRow,
    size_t currentPosition)
{
    int numberOfSurroundingRolls = 0;

    // Check the previous row

    if(currentPosition > 0 && RollIsAtPosition(previousRow, currentPosition - 1))
    {
        numberOfSurroundingRolls++;
    }

    if(RollIsAtPosition(previousRow, currentPosition))
    {
        numberOfSurroundingRolls++;
    }

    if((currentPosition < previousRow.size()) && RollIsAtPosition(previousRow, currentPosition + 1))
    {
        numberOfSurroundingRolls++;
    }

    // Check this row

    if(currentPosition > 0 && RollIsAtPosition(currentRow, currentPosition - 1))
    {
        numberOfSurroundingRolls++;
    }

    if((currentPosition < currentRow.size()) && RollIsAtPosition(currentRow, currentPosition + 1))
    {
        numberOfSurroundingRolls++;
    }

    // Check the next row

    if(currentPosition > 0 && RollIsAtPosition(nextRow, currentPosition - 1))
    {
        numberOfSurroundingRolls++;
    }

    if(RollIsAtPosition(nextRow, currentPosition))
    {
        numberOfSurroundingRolls++;
    }

    if((currentPosition < nextRow.size()) && RollIsAtPosition(nextRow, currentPosition + 1))
    {
        numberOfSurroundingRolls++;
    }

    return numberOfSurroundingRolls;
}

int main()
{
    std::string lastBuffer;
    std::string currentBuffer;
    std::string nextBuffer;
    std::ifstream inFile(R"(..\Resource\Day4\input.txt)");
    int NumberOfAccessibleRolls = 0;

    std::getline(inFile, currentBuffer);
    std::getline(inFile, nextBuffer);

    do
    {
        size_t currentPosition = 0;
        while((currentPosition = currentBuffer.find(RollOfPaper, currentPosition)) != std::string::npos)
        {
            if(GetNumberOfSurroundingRolls(lastBuffer, currentBuffer, nextBuffer, currentPosition) < 4)
            {
                NumberOfAccessibleRolls++;
            }

            currentPosition++;
        }

        lastBuffer = currentBuffer;
        currentBuffer = nextBuffer;
    } while(std::getline(inFile, nextBuffer));

    // Do the last one, with an empty next line

    nextBuffer.clear();
    size_t currentPosition = 0;
    while((currentPosition = currentBuffer.find(RollOfPaper, currentPosition)) != std::string::npos)
    {
        if(GetNumberOfSurroundingRolls(lastBuffer, currentBuffer, nextBuffer, currentPosition) < 4)
        {
            NumberOfAccessibleRolls++;
        }

        currentPosition++;
    }

    std::cout << NumberOfAccessibleRolls << std::endl;

    return 0;
}