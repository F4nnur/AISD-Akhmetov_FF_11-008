#include <bits/stdc++.h>
using namespace std;
int binarySearch(int arr[], int l, int r, int x)
{
	if (r >= l) {
		int mid = l + (r - l) / 2;

		
		if (arr[mid] == x)
			return mid;

		
		if (arr[mid] > x)
			return binarySearch(arr, l, mid - 1, x);

	
		return binarySearch(arr, mid + 1, r, x);
	}


	return -1;
}

int main(void)
{
	int arr[] = { 0,0,0,0,1,1,1,1,1,1,1,1,2,2,2,2,3,5,5,5,5,6,9,9,9,9,9,9 };
	int x = 10;
	int n = sizeof(arr) / sizeof(arr[0]);
	int result = binarySearch(arr, 0, n - 1, x);
	(result == -1) ? cout << "Element is not present in array"
				: cout << "Element is present at index " << result;
	return 0;
}
