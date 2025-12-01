#include <iostream>
#include <fstream>

int main()
{
    std::string buffer;
    std::ifstream inFile(R"(..\Resource\Day1\input.txt)");

    int const dialSize = 100;
    int password = 0;
    int currentDialPosition = 50;

    while(std::getline(inFile, buffer))
    {
        char const direction = buffer.at(0);
        int const value = std::stoi(buffer.substr(1));

        if(direction == 'L')
        {
            currentDialPosition = (currentDialPosition - value) % dialSize;
        }
        else if(direction == 'R')
        {
            currentDialPosition = (currentDialPosition + value) % dialSize;
        }

        // mod can be negative, so add 100 if necessary
        if(currentDialPosition < 0)
        {
            currentDialPosition += dialSize;
        }

        if(currentDialPosition == 0)
        {
            password++;
        }
    }

    std::cout << password;

    return 0;
}
