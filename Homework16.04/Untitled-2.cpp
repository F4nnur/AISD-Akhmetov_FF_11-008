#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;


void binarySearch(int mat[][MAX], int i, int j_low,
								int j_high, int x)
{
	while (j_low <= j_high)
	{
		int j_mid = (j_low + j_high) / 2;

		
		if (mat[i][j_mid] == x)
		{
			cout << "Found at (" << i << ", "
				<< j_mid << ")";
			return;
		}

		else if (mat[i][j_mid] > x)
			j_high = j_mid - 1;

		else
			j_low = j_mid + 1;
	}


	cout << "Element no found";
}

void sortedMatrixSearch(int mat[][MAX], int n,
								int m, int x)
{
	
	if (n == 1)
	{
		binarySearch(mat, 0, 0, m-1, x);
		return;
	}

	
	int i_low = 0;
	int i_high = n-1;
	int j_mid = m/2;
	while ((i_low+1) < i_high)
	{
		int i_mid = (i_low + i_high) / 2;

		
		if (mat[i_mid][j_mid] == x)
		{
			cout << "Found at (" << i_mid << ", "
				<< j_mid << ")";
			return;
		}

		else if (mat[i_mid][j_mid] > x)
			i_high = i_mid;

		else
			i_low = i_mid;
	}

	
	if (mat[i_low][j_mid] == x)
		cout << "Found at (" << i_low << ","
			<< j_mid << ")";
	else if (mat[i_low+1][j_mid] == x)
		cout << "Found at (" << (i_low+1)
			<< ", " << j_mid << ")";

	
	else if (x <= mat[i_low][j_mid-1])
		binarySearch(mat, i_low, 0, j_mid-1, x);

	
	else if (x >= mat[i_low][j_mid+1] &&
			x <= mat[i_low][m-1])
	binarySearch(mat, i_low, j_mid+1, m-1, x);

	
	else if (x <= mat[i_low+1][j_mid-1])
		binarySearch(mat, i_low+1, 0, j_mid-1, x);

	
	else
		binarySearch(mat, i_low+1, j_mid+1, m-1, x);
}

int main()
{
	int x = 8;
	int mat[][MAX] = {{0, 6, 8, 9, 11},
					{20, 22, 28, 29, 31},
					{36, 38, 50, 61, 63},
					{64, 66, 100, 122, 128}};

	sortedMatrixSearch(x);
	return 0;
}
