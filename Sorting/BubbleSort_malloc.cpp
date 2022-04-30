#include <iostream>
#include <stdlib.h>

using namespace std;

void BubbleSort(int arr[], int n)
{
	int i, j;
	int temp;
	
	for(i=0; i<n-1; i++)
	{
		for(j=0; j<(n-i)-1; j++)
		{
			if(arr[j] > arr[j+1])
			{
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}

int main(void)
{
	int n;
	int i;
	cout << "n: ";
	cin >> n;
	
	int *arr = (int*)malloc(sizeof(int)*n);
	
	for(i=0; i<n; i++)
	{
		cout << "arr[" << i << "] : ";
		cin >> arr[i];
	}
	
	BubbleSort(arr, n);
	
	for(i=0; i<n; i++)
		cout << arr[i] << " ";
	
	printf("\n");
	return 0;
}