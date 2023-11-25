#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;

string reverseWords(string s) 
{
    stringstream ss(s);         //The stringstream is used to tokenize the input string into words.
    ////word to store each word during iteration, and reversedString to store the final reversed strin
    string word, reversedString; 
    //This is a loop that reads each word from the stringstream and continues until there are no more words. 
    //The >> operator is used to extract words from the stringstream.
    while (ss >> word) 
    {
        //each word is concatenated with the existing reversedString, along with a space. 
        reversedString = word + " " + reversedString;
    }
    reversedString.pop_back(); // Remove the extra space at the end
    return reversedString;
}

int main() 
{
    string inputString;
    cout << "Enter a string: ";
    getline(cin, inputString);

    string reversedString = reverseWords(inputString);
    cout << "Output: " << reversedString << endl;

    return 0;
}




=================================================================================================





// JAVA CODE :- 

import java.util.Scanner;

public class ReverseWords {
    public static String reverseWords(String s) {
        Scanner sc = new Scanner(s);
        String word, reversedString = "";
        while (sc.hasNext()) {
            word = sc.next();
            reversedString = word + " " + reversedString;
        }
        reversedString = reversedString.trim(); // Remove the extra space at the end
        return reversedString;
    }

    public static void main(String[] args) {
        Scanner inputScanner = new Scanner(System.in);
        System.out.print("Enter a string: ");
        String inputString = inputScanner.nextLine();

        String reversedString = reverseWords(inputString);
        System.out.println("Output: " + reversedString);
    }
}
