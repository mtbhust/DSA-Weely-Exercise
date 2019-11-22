#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string.h>

using namespace std;
int max(int a, int b, int c, int d)
{
	int max = 0;
	if (max < a) max = a;
	if (max < b) max = b;
	if (max < c) max = c;
	if (max < d) max = d;
	return max;
}

int a[12][12];

int dyPro(int matrix[][12], int rows, int columns)
{
	if(a[rows][columns] == 0)
	{
		a[rows][columns] = 1;
		int up = 0, down = 0, left = 0, right = 0;
		if(matrix[rows][columns] == matrix[rows][columns-1] + 1)
		{
			left = dyPro(matrix,rows, columns - 1) + 1;
		}
		if(matrix[rows][columns] == matrix[rows][columns-1] + 1)
		{
			right = dyPro(matrix, rows, columns + 1) + 1;
		}
		if(matrix[rows][columns] == matrix[rows-1][columns] + 1)
		{
			up = dyPro(matrix, rows, columns - 1) + 1;
		}
		if(matrix[rows][columns] == matrix[rows+1][columns] + 1)
		{
			down = dyPro(matrix, rows, columns - 1) + 1;
		}
		a[rows][columns]= max(up, down, left, right);
	}	
	return a[rows][columns];
}



int main()
{
	int matrix[12][12];
	memset(matrix, INT_MIN, sizeof(matrix));
	//initiate data
	for ( int i = 1; i < 11; i ++)
	{
		for (int j = 1; j < 11; j++)
		{
			matrix[i][j] = -5 + rand()%10;;
		}
	}
	//
	for ( int i = 1; i < 11; i ++)
	{
		for (int j = 1; j < 11; j++)
		{
			cout << setw(5) << matrix[i][j] ;
			a[i][j] = 0;
		}
		cout << endl;
	}
	cout <<"==========================";
	for ( int i = 0; i < 12; i ++)
	{
		for (int j = 0; j < 12; j++)
		{
			dyPro(matrix,i,j) ;
		}
	}
	int max = 0, x ,y;
	cout << endl;
	for ( int i = 1; i < 11; i ++)
	{
		for (int j = 1 ; j < 11; j ++ )
		{
			
			if (max < a[i][j]) 
			{
				max = a[i][j];
				x=  i;
				y = j;
			}
		}
	}
	cout << max << "   " << x << "  " << y;
	
	}
