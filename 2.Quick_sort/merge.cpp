#include <iostream>
#include<omp.h>
using namespace std;
int a[50];
void merge(int,int,int);
void merge_sort(int low,int high)
{
 	int mid;
 	if(low<high)
 	{
  		mid=(low+high)/2;
  		merge_sort(low,mid);
  		merge_sort(mid+1,high);
  		merge(low,mid,high);
 	}
}

void merge(int low,int mid,int high)
{
 	int h,i,j,b[50],k;
 	h=low;
 	i=low;
 	j=mid+1;

 	while((h<=mid)&&(j<=high))
 	{
  		if(a[h]<=a[j])
  		{
  			b[i]=a[h];
   			h++;
  		}
  		else
  		{
   			b[i]=a[j];
   			j++;
  		}
  		i++;
 	}
 	if(h>mid)
 	{
  		for(k=j;k<=high;k++)
  		{
   			b[i]=a[k];
   			i++;
  		}
 	}
	else
	{
  		for(k=h;k<=mid;k++)
  		{
   			b[i]=a[k];
   			i++;
  		}
 	}
 	for(k=low;k<=high;k++) 
 	a[k]=b[k];
}

int main()
{
 	int num,i;
 	int start_time , end_time , total_time;
	cout<<"**MERGE SORT PROGRAM** \n";
	cout<<"Enter the number of elements: \n";
	cin>>num;
	cout<<"Enter the elements: \n";
	for(i=1;i<=num;i++)
	{
  		cin>>a[i] ;
	}
	#pragma omp parallel sections
	{
	#pragma omp section
	{
		merge_sort(1,num);
	}
	}
	cout<<"Sorted Array :\n ";
	for(i=1;i<=num;i++)
	cout<<a[i]<<"	";
	start_time = omp_get_wtime();
	total_time = end_time - start_time;

	return 0;
}

/*
output:

prjlab@prjlab-dx2480-MT:~$ cd Desktop
prjlab@prjlab-dx2480-MT:~/Desktop$ g++ merge.cpp
prjlab@prjlab-dx2480-MT:~/Desktop$ ./a.out
**MERGE SORT PROGRAM**
Enter the number of elements:
5

Enter the elements:
10
23
85
4
9    

Sorted Array :


4	9	10	23	85	
*/ 

