#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() 
{
    std::string input;
    std::cout << "Enter a string: ";
    std::cin >> input;

    int length = input.length();
    std::string output;

    for (int i = 0; i < length; i++) 
    {
        char currentChar = input[i];
        int count = 0;
        
        for (int j = i + 1; j < length; j++) 
        {
            if (input[j] == currentChar) 
            {
                count++;
            }
        }
        output += std::to_string(count);
    }
    std::cout << "Output: " << output << std::endl;

    return 0;
}
