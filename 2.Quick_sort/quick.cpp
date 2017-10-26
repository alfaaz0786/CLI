#include<iostream>
#include<omp.h>
int a[10],l,u,i,j,k=0,e=0;;
void Quicksort(int *,int,int);
int Partition(int *,int,int);
int main()
{
  std::cout <<"enter 10 elements";
  for(i=0;i<10;i++)
  std::cin >> a[i];
  l=0;
  u=9;
  std::cout <<"\nElements are :\n";
  for(i=0;i<10;i++)
  std::cout <<a[i]<<" ";
  Quicksort(a,l,u);
  std::cout <<"\nsorted elements\n";
  for(i=0;i<10;i++)
  std::cout << a[i] << " ";
  return 0;
}

void Quicksort(int a[],int l, int u)
{
  if(l<u)
  {
   
   j=Partition(a,l,u);
   e++;
   std::cout<<"\nPivot element with index "<<j<< " has been found out by thread"  <<k;
  // std::cout<<"\nElements after iteration "<<e<<" are ";
  
   for(i=0;i<10;i++)
   //std::cout <<a[i]<<" ";

   #pragma omp parallel sections
   {
    #pragma omp section
    { 
    k=k+1;
    Quicksort(a,l,j-1);
    }
    #pragma omp section
    {
	 k=k+1;
  	 Quicksort(a,j+1,u);
    }
  
  }
 }
}
int Partition(int a[],int l,int u)
{
   int p,temp;
   if(l<u)
   {
     p=a[l];
     i=l;
     j=u;
     while(i<j)
    {
      while(a[i] <= p && i<j )
	 i++;
      while(a[j]>= p && i<=j )
	   j--;
      if(i<j)
      {
        temp=a[i];
        a[i]=a[j];
        a[j]=temp;
      }

    }
    temp=a[j];
    a[j]=a[l];
    a[l]=temp;
    return j;
  }
}


/* 
output:

prjlab@prjlab-dx2480-MT:~/Desktop$ g++ -fopenmp quick.cpp
prjlab@prjlab-dx2480-MT:~/Desktop$ ./a.out 
enter 10 elements
100
90
80
70
60
50
40
30
20
10

Elements are :
100 90 80 70 60 50 40 30 20 10 
Pivot element with index 9 has been found out by thread 0
Pivot element with index 0 has been found out by thread 1
Pivot element with index 8 has been found out by thread 3
Pivot element with index 1 has been found out by thread 4
Pivot element with index 7 has been found out by thread 6
Pivot element with index 2 has been found out by thread 7
Pivot element with index 6 has been found out by thread 9
Pivot element with index 3 has been found out by thread 10
Pivot element with index 5 has been found out by thread 12
Pivot element with index 6 has been found out by thread 34
Pivot element with index 7 has been found out by thread 55
Pivot element with index 8 has been found out by thread 76
sorted elements
10 20 30 40 50 60 70 80 90 100
*/
 
