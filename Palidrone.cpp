#include <iostream>
#include <fstream>
#include <string>
using namespace std;
bool check_palidrome(string s)
{
	int n = s.length();
	for(int i = 0; i < n/2; i ++)
	{
		if (s[i] != s[n-i - 1])
		{
			return 0;
		}
	}
	return 1;
}
bool check_palidrome2(string s)
{
	int n = s.length();
	if (n%2 ==1 || n < 4)
	{
		return 0;
	}
	else
	{
		for(int i = 0; i < n/2; i= i + 2)
		{
			if (s[i] != s[n-i-2] || s[i+1] != s[n-i-1])
			{
				return 0;
			}
		}
		return 1;
	}
}
int main()
{
	ifstream myfile("10kwords.txt");
	for(int i = 0 ; i < 10000; i ++)
	{
		string a;
		myfile >> a;
		if(check_palidrome(a) || check_palidrome2(a))
		{
			cout << a << "    " << endl;
		}
	}
	myfile.close();
}
