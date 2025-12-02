#include <cmath>
#include <iostream>
#include <fstream>

bool IDIsInvalid(long long id)
{
    bool invalid = false;

    int numberOfDigits = static_cast<int>(floor(log10(id) + 1));

    if(numberOfDigits % 2 == 0)
    {
        // Must have an even number to have an invalid ID

        long long const highHalfID = id / pow(10, (numberOfDigits / 2));
        long long const lowHalfID = id - highHalfID * pow(10, (numberOfDigits / 2));

        if(highHalfID == lowHalfID)
        {
            invalid = true;
        }
        else
        {
            invalid = false;
        }
    }
    else
    {
        invalid = false;
    }


    return invalid;
}

long long FindSumOfInvalidIDs(long long firstID, long long lastID)
{
    long long sum = 0;

    for (long long i = firstID; i <= lastID; i++)
    {
        if(IDIsInvalid(i))
        {
            sum += i;
        }
    }

    return sum;
}

int main()
{
    std::string buffer;
    std::string const rangeDelimiter = ",";
    std::string const idDelimiter = "-";
    std::ifstream inFile(R"(..\Resource\Day2\input.txt)");

    long long sum = 0;

    if(std::getline(inFile, buffer))
    {
        std::string firstIDBuffer;
        std::string lastIDBuffer;

        size_t lastRangeDelimiterPosition = 0;
        size_t rangeDelimiterPosition = 0;
        size_t idDelimiterPosition = 0;

        while((rangeDelimiterPosition = buffer.find(rangeDelimiter, lastRangeDelimiterPosition)) != std::string::npos)
        {
            idDelimiterPosition = buffer.find(idDelimiter, lastRangeDelimiterPosition);

            firstIDBuffer = buffer.substr(lastRangeDelimiterPosition, idDelimiterPosition - lastRangeDelimiterPosition);
            lastIDBuffer = buffer.substr(idDelimiterPosition + 1, rangeDelimiterPosition - idDelimiterPosition - 1);

            sum += FindSumOfInvalidIDs(std::stoll(firstIDBuffer), std::stoll(lastIDBuffer));

            lastRangeDelimiterPosition = rangeDelimiterPosition + 1;
        }

        idDelimiterPosition = buffer.find(idDelimiter, lastRangeDelimiterPosition);

        // Get the last one
        firstIDBuffer = buffer.substr(lastRangeDelimiterPosition, idDelimiterPosition - lastRangeDelimiterPosition);
        lastIDBuffer = buffer.substr(idDelimiterPosition + 1);

        sum += FindSumOfInvalidIDs(std::stoll(firstIDBuffer), std::stoll(lastIDBuffer));

        std::cout << sum << '\n';

        return 0;
    }
    else
    {
        return 1;
    }
}