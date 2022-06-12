#include <algorithm>
#include <chrono>
#include <iostream>
#include<vector>
using namespace std;
using namespace std::chrono;
int pointer=0;
auto start = high_resolution_clock::now();
int check(int array[],int left,int right)
{
	for(int i=left;i<right;i++)
	{
		if(array[i]>array[i+1])
		{
			left = i;
			pointer = left;
			for(int k=i-1;k<right;k++)
			{
				if(array[i-1]>array[k+1])
				{
					pointer = 0;
					break;
				}
			}
			return pointer;
		}
	}
	return -1;
	
}
void OBOsss(int array[],int left,int right)
{
	if(array[left]<array[left+1])
	{
		left++;
		check(array,left,right);
		if(check(array,left,right)==-1)
		{
			return;
		}	
	}
	else
	pointer = 0;
	for(int i=pointer;i<right;i++)
	{
		for(int j=i;j<right;j++)
		{
			if(array[i]>=array[j+1])
			{
				int x = array[j+1];
				array[j+1] = array[i];
				array[i] = x;
			}
		}
	}
}
int main()
{
	auto start = high_resolution_clock::now();
	int testing_arr[10000];
	int arr[5]={4,3,1,8,9};
	//int arr1[5]={9,8,7,6,5};
	//int arr2[5]={1,2,3,4,5};
	//int arr3[5]={4,4,4,4,4};
	//int arr4[5]={7,6,4,3,2};
int x,y;
//generating the random values for the array.
for (x=0;x<10000;x++){
 testing_arr[x]= rand()%10+1;
}

	OBO(testing_arr,0,9999);
	for(int i=0;i<10000;i++)
	{
		cout <<testing_arr[i] << " ";
	}
	cout << endl;
	
	//calculating the time complexity.
	
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;
	return 0;
}
