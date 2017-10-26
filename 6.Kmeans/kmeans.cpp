ROLL NO:
BATCH:B2
CLASS: BE-B

TITLE: K-MEANS CLUSTERING

#include <iostream>
#include <stdlib.h>
#include<math.h>
#include<vector>
using namespace std;

int min(int arr[], int maxIndex)
{
int min=100;
for(int i=0;i<maxIndex;i++)
{
if(arr[i]<min)
min=arr[i];
}
return min;
}
int indexOf(int number,int arr[], int maxIndex)
{
int index;
for(int i=0;i<maxIndex;i++)
{
if(number==arr[i])
{
index=i;
break;  
}
}
return index;
}
int mean(vector<int> vc )
{
int sum=0;
for(int i=0;i<vc.size();i++)
sum=sum+vc[i];
return sum/vc.size();
}
void show(vector<int> vc )
{
for(int i=0;i<vc.size();i++){
cout<<vc[i]<<",";  
}
}
bool isEqual(int arr1[], int arr2[], int maxIndex){
for(int i=0;i<maxIndex;i++)
{
if(arr1[i]!=arr2[i])
return false;
}
return true;
}

int main()
{
int noOfItems;
int k;  
cout<<"Enter n objects: ";
cin>> noOfItems;
cout<<"Enter K cluster: ";
cin>> k;
int cluster[k];
int oldCluster[k];
int objects[noOfItems];
int row[k];
vector< vector<int> > groups;
for(int i=0;i<noOfItems;i++)
{
cout<<endl;
cout<<"Enter Value"<<"("<<(i+1)<<")"<<": ";

cin>>objects[i];
if(i<k)
cluster[i]=objects[i];
}
for(int i=0;i<k;i++)
{
vector<int> newGroup;
groups.push_back(newGroup);
}
int iter =1;
do
{
for(int i=0;i<noOfItems;i++)
{
for(int j=0;j<k;j++){
row[j] = abs(cluster[j]-objects[i]);
}  
    groups[indexOf(min(row,k),row,k)].push_back(objects[i]);
}
for(int j=0;j<k;j++)
{
     if(!groups[j].empty())
{
oldCluster[j]=cluster[j];
cluster[j] = mean(groups[j]);
}
}
if(!isEqual(oldCluster,cluster,k))
{
for(int i=0;i<k;i++)
groups[i].clear();
}
iter++;  
}while(!isEqual(oldCluster,cluster,k));
cout<<"\n\n";
for(int i=0;i<k;i++)
{
cout<<"C"<<(i+1)<<" : "<<cluster[i]<<endl;
}
for(int i=0;i<k;i++)
{
cout<<"\n\nGroup "<<(i+1)<<" : \n"<<endl;
show(groups[i]);
}
cout<<"\n\nNumber of Iterations:  "<<iter<<endl;

return 0;
}


/*
    output

unix@unix-HP-280-G1-MT:~/Desktop/30$ g++ kmeans.cpp
unix@unix-HP-280-G1-MT:~/Desktop/30$ ./a.out
Enter n objects: 10
Enter K cluster: 3

Enter Value(1): 2

Enter Value(2): 5

Enter Value(3): 3

Enter Value(4): 1

Enter Value(5): 9

Enter Value(6): 4

Enter Value(7): 3

Enter Value(8): 10

Enter Value(9): 15

Enter Value(10): 6


C1 : 1
C2 : 11
C3 : 4


Group 1 : 

2,1,

Group 2 : 

9,10,15,

Group 3 : 

5,3,4,3,6,

Number of Iterations:  5

*/
