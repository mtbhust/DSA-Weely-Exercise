#include<iostream>
#include<cstdlib>
#include <iomanip>

using namespace std;


int findmax( int mid, int matrix[][10])
{
	int max = INT_MIN;
	int temp;
	for(int i = 0; i <10; i ++)
	{
		if (max < matrix[i][mid])
		{
			max = matrix[i][mid];
			temp = i;
		}
		
	}
	return temp;
	
}

void findPeak(int fcol, int lcol, int matrix[][10])
{
	int mid = (fcol + lcol)/2;
	int mc_index = findmax(mid,matrix);
	int maxcur = matrix[mc_index][mid];;
	if(mid == 0|| mid == lcol - 1 )
	{
		cout << maxcur << "   " << mc_index << "  " << mid ;
	}
	
	
	
	if ((matrix[mc_index][mid-1] <= maxcur) and  (matrix[mc_index][mid+1] <= maxcur))
	{
		cout << maxcur << "   " << mc_index << "  " << mid ;
	}
	if (matrix[mc_index][mid-1]> maxcur)
	{
		return findPeak(fcol, mid-1,matrix);
	}
	if (matrix[mc_index][mid+1] > maxcur)
	{
		return findPeak(mid+1, lcol,matrix);
	}
}
int main()
{	
	int matrix[10][10];
	//initiate data
	for ( int i = 0; i < 10; i ++)
	{
		for (int j = 0; j < 10; j++)
		{
			matrix[i][j] =200-rand()%100;
		}
	}
	//
	for ( int i = 0; i < 10; i ++)
	{
		for (int j = 0; j < 10; j++)
		{
			cout << setw(5) << matrix[i][j] ;
		}
		cout << endl;
	}
	// 
	findPeak(0,9, matrix);
		
}
