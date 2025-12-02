#include <cmath>
#include <iostream>
#include <fstream>

bool IDIsInvalid(std::string const id)
{
    bool invalid = false;

    for(int n = 2; n <= id.size(); n++)
    {
        if(id.size() % n == 0)
        {
            // Number of digits is divisible by n
            std::string lastSubStr = id.substr(0, (id.size() / n));
            std::string nextSubStr;

            int i = 1;

            for(; i < n; i++)
            {
                nextSubStr = id.substr(i * (id.size() / n), (id.size() / n));

                if(lastSubStr != nextSubStr)
                {
                    break;
                }

                lastSubStr = nextSubStr;
            }

            if(i == n)
            {
                // made it all the way through the loop
                invalid = true;
            }
        }

        if(invalid == true)
        {
            break;
        }
    }

    return invalid;
}

long long FindSumOfInvalidIDs(std::string const firstID, std::string const lastID)
{
    long long sum = 0;

    for (long long i = std::stoll(firstID); i <= std::stoll(lastID); i++)
    {
        if(IDIsInvalid(std::to_string(i)))
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

            sum += FindSumOfInvalidIDs(firstIDBuffer, lastIDBuffer);

            lastRangeDelimiterPosition = rangeDelimiterPosition + 1;
        }

        idDelimiterPosition = buffer.find(idDelimiter, lastRangeDelimiterPosition);

        // Get the last one
        firstIDBuffer = buffer.substr(lastRangeDelimiterPosition, idDelimiterPosition - lastRangeDelimiterPosition);
        lastIDBuffer = buffer.substr(idDelimiterPosition + 1);

        sum += FindSumOfInvalidIDs(firstIDBuffer, lastIDBuffer);

        std::cout << sum << '\n';

        return 0;
    }
    else
    {
        return 1;
    }
}