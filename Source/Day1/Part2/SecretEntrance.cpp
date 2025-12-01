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

        int clicksLeft = value;

        while(clicksLeft > 0)
        {
            if(direction == 'L')
            {
                currentDialPosition--;
            }
            else if(direction == 'R')
            {
                currentDialPosition++;
            }

            clicksLeft--;

            if(currentDialPosition < 0)
            {
                currentDialPosition += dialSize;
            }
            else if(currentDialPosition >= dialSize)
            {
                currentDialPosition -= dialSize;
            }

            if(currentDialPosition == 0)
            {
                password++;
            }
        }
    }

    std::cout << password;

    return 0;
}
