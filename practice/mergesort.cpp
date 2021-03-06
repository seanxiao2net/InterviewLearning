#include <cstdlib>
#include <iostream>

void Merge(int arr[], int begin1, int begin2, int end) 
{
	int *buf = new int[end-begin1+1];
	int i=0, j=begin1, k=begin2;

	while (j<begin2 && k<=end)
	{
		if (arr[j]<arr[k])
		{
			buf[i]=arr[j];
			i++; j++;
		}
		else
		{
			buf[i]=arr[k];
			i++; k++;
		}
	}

	while (j<begin2)
	{
		buf[i] = arr[j];
		++j; ++i;
	}

	while (k<=end)
	{
		buf[i] = arr[k];
		++k; ++i;
	}

	for (i=0; i<end-begin1+1; i++)
	{
		arr[begin1+i]=buf[i];
	}

}

void MergeSort(int arr[], int begin, int end)
{
	if (begin == end) return;
	int mid = (begin+end)/2;

	MergeSort(arr, begin, mid);
	MergeSort(arr, mid+1, end);

	Merge(arr, begin, mid+1, end);
}

int main()
{
	int arr[]={3,4,2,5,6,7,1,2,9};
	//printf("%d %d %d %d %d %d %d %d %d\n\n",arr[0],arr[1],arr[2],arr[3],arr[4],arr[5],arr[6],arr[7],arr[8]);

	std::cout<<arr[0]<<arr[1]<<arr[2]<<arr[3]<<arr[4]<<arr[5]<<arr[6]<<arr[7]<<arr[8]<<std::endl;

	MergeSort(arr, 0, 8);
	//printf("%d %d %d %d %d %d %d %d %d\n",arr[0],arr[1],arr[2],arr[3],arr[4],arr[5],arr[6],arr[7],arr[8]);

	std::cout<<arr[0]<<arr[1]<<arr[2]<<arr[3]<<arr[4]<<arr[5]<<arr[6]<<arr[7]<<arr[8]<<std::endl;

	return 0;
}
