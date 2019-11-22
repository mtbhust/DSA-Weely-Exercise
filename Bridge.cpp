#include <iostream>
using namespace std;
int loInSub(int c[], int n)
{
	int maxAtNode[n];
	for ( int i =0; i < n; i ++)
	{
		maxAtNode[i] = 1;
	}
	for(int i = 0; i < n; i ++)
	{
		for ( int j = i + 1; j < n; j ++)
		{
			if ( c[j] > c[i] && maxAtNode[j] < maxAtNode[i] + 1)
			{
				maxAtNode[j] = maxAtNode[i] + 1;
			}
		}
	}
	int max = 1;
	for(int i = 0; i < n; i ++)
	{
		max = max < c[i] ?c[i]:max;
	}
	return max;
}
int main ()
{
	cout << "Nhap so cau toi da: " << endl;
	int n;
	cin >> n ;
	int a[n], b[n];
	cout << "Bo song so 1: ";
	for(int i = 0; i < n; i ++)
	{
		cin >> a[i];
	}
	cout << "Bo song so 2: ";
	for(int i = 0; i < n; i ++)
	{
		cin >>b[i];
	}
	int c[n];
	for(int i = 0; i < n; i ++)
	{
		for( int j = 0; j < n; j ++)
		{
			if (b[j] == a[i])
			{
				c[j] = i;
			}
		}
	}
	for ( int i = 0; i < n; i ++)
	{
		cout << c[i] << endl;
	}
	cout << loInSub(c,n);
}
