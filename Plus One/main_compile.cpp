#include <iostream>
#include <vector>

using namespace std;

vector<int> plusOne(vector<int>& digits) {
    int carry = 1;
    for (int i = digits.size() - 1; i >= 0; i--) {
        digits[i] += carry;
        carry = digits[i] / 10;
        digits[i] %= 10;
    }

    if (carry) {
        digits.insert(digits.begin(), 1);
    }

    return digits;
}

int main() {
    int n;
    cout << "Enter the number of digits: ";
    cin >> n;

    vector<int> digits(n);
    cout << "Enter the digits (from left to right): ";
    for (int i = 0; i < n; i++) {
        cin >> digits[i];
    }

    vector<int> result = plusOne(digits);

    cout << "Result: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}






//#include <iostream>
//#include <vector>
//using namespace std;
//
//void plusOne(vector<int>& digits)
//{
//	int carry = 1;
//	int i = digits.size() - 1;
//	
//	while(carry>0 && i>= 0)
//	{
//		if(digits[i] == 9)
//		{
//			digits[i] = 0;
//			carry = 1;
//		}
//		else
//		{
//			digits[i]++;
//			carry = 0;
//		}
//		i--;
//	}
//	if(carry > 0)
//	{
//		vector<int> newDigits(digits.size() + 1);
//		newDigits[0] = 1;
//		for(int j=1; j<newDigits.size(); j++)
//		{
//			newDigits[j] = digits[j-1];
//		}
//		digits = newDigits;
//	}
//}
//int main()
//{
//	vector<int> digits;
//	cout<<"Enter digits: ";
//	string digitsStr;
//	cin >> digitsStr;
//	
//	for(int i=0; i<digitsStr.length(); i++)
//	{
//		digits.push_back(digitsStr[i] - '0');
//	}
//	plusOne(digits);
//	for(int i=0; i<digits.size(); i++)
//	{
//		cout<<digits[i];
//	}
//	cout<<endl;
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//

