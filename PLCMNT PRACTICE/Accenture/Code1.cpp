#include <iostream>
#include <string>
#include <cmath>

int calculateValue(char vowel, char consonant) 
{
    return std::abs(vowel - consonant);
}

int main() {
    std::cout<<"\nENter a string: ";
    std::string input ;
    std::cin>>input;  
    int vowelCount = 0;
    int valueSum = 0;
    char firstVowel = '\0';
    int sum = 0;

    for (char c : input) 
    {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') 
        {
            if (vowelCount == 0) 
            {
                firstVowel = c;
            }
            vowelCount++;
            
            sum += calculateValue(firstVowel, c) ;
        } 
        else 
        {
            valueSum += 10;
        }
    }

    int output;
    if (vowelCount == 0) 
    {
        output = valueSum;
    } 
    else if (vowelCount == input.length()) 
    {
        output = -1;
    } 
    else 
    {
        output = valueSum + sum;
    }

    std::cout << "Output: " << output << std::endl;

    return 0;
}

/*

if input1 = greiay then output1 = 38. If output2 = iii & output2 = -1. Explaination of working of code: 
if the entered string doesn't have a vowel then the value of that alphabet is considered as 10 & if there 
is a vowel letter in the string then do the | first vowel (ie 'e' here) - nth vowel('e' here)| + 
| first vowel (ie 'e' here) - nth vowel('i ' here) + | first vowel (ie 'e' here) - nth vowel('a' here)| . 
Therefore the answer is 10+10+|'e'-'e'| + |'e'-'i'|+|'e'-'a'|+10 = 38.       
If all the entered alphabets in the syring is a vowel then the output will be -1.


|'e'-'e'| evaluates to 0 because the character 'e' is subtracted from itself, resulting in the difference being 0.
|'e'-'i'| evaluates to 2 because the character 'e' is subtracted from 'i', and the absolute difference is 4.
|'e'-'a'| evaluates to 4 because the character 'e' is subtracted from 'a', and the absolute difference is 4.
So, the final value of the expression |'e'-'e'| + |'e'-'i'|+|'e'-'a'| is 0 + 4 + 4 = 8.

This loop iterates through each character in the input string. It checks if the character is a vowel 
('a', 'e', 'i', 'o', 'u'). If it is, and it's the first vowel encountered, firstVowel is set to that character. 
vowelCount is incremented to keep track of the number of vowels. If the character is not a vowel, valueSum is increased by 10.
*/