#include <iostream>
using namespace std;

bool inpalindrome(string str, int start, int end)
{
	if (start >= end)
	{
		return true;
	}
	if (str[start] != str[end])
	{
		return false;
	}
	return inpalindrome(str, start + 1, end - 1);
}

int main()
{

	string str;
	cout << "Enter the String ";
	cin >> str;

	if (inpalindrome(str, 0, str.length() - 1))
	{
		cout << "Palindrome "<< endl;
	}
	else
	{
		cout << "Not Palindrome" << endl;
	}


	return 0;

}