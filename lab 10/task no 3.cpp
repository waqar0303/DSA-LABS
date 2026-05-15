#include <iostream>
using namespace std;

int max(int arr[], int size)
{
	if (size == 0)
	{
		return 0;
	}

	int maxnum = max(arr, size - 1);

	if (arr[size - 1] > maxnum)
	{
		return arr[size - 1];
	}
	else
	{
		return maxnum;
	}
	

}


int main()
{
	int arr[] = { 12,20,19,3,18 };
	int size = 5;

	cout << "Maximum Element " << max(arr, 5);
}