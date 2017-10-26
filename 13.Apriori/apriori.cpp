#include<iostream>
using namespace std;

int main()
{
int i,j,t1,k,l,f1,f2,f3;


//Initial item-purchase
int a[5][6];
for(i=0;i<5;i++)
{
    cout<<"\n Enter items for Transaction T"<<i+1<<": ";
    for(j=0;j<6;j++)
    {
    cin>>a[i][j];
    }
}
//Defining minimum level for acceptence
int min;
cout<<"\n Enter minimum support : ";
cin>>min;
//Printing initial input
cout<<"Initial Input";
cout<<"\n----------------------------------------------------------";
cout<<"\nTrasaction\t\tItems\n";
cout<<"----------------------------------------------------------\n";
for(i=0;i<5;i++)
{
    cout<<"T"<<i+1<<"\t\t";
    for(j=0;j<6;j++)
    {
    cout<<a[i][j]<<"\t";
    }
    cout<<"\n";
}
cout<<"----------------------------------------------------------\n";
cout<<"\nAssume minimum support: "<<min;

//First pass
int l1[11];
for(i=0;i<11;i++)
{
    t1=0;
    for(j=0;j<5;j++)
    {
        for(k=0;k<6;k++)
        {
            if(a[j][k]==i+1)
            {
            t1++;
            }
        }
    }
    l1[i]=t1;
}
//Printing first pass
cout<<"\n\nGenerating Candidate item (CL1)\n";
cout<<"item set\tSupport\n\n";
for(i=0;i<11;i++)
{
cout<<" "<<i+1<<"\t\t"<<l1[i]<<"\n";
}

//Second pass
//Counting number of possibilities for pass2
int p2pcount=0;
int p2items[11];
int p2pos=0;
for(i=0;i<11;i++)
{
if(l1[i]>=min)
{
p2pcount++;
p2items[p2pos]=i;
p2pos++;
}
}
//Printing selected items for second pass
cout<<"\nGenerating Frequent item set (L1)\n";
cout<<"item set\tSupport\n\n";
for(i=0;i<p2pos;i++)
{
cout<<"  "<<p2items[i]+1<<"\t\t"<<l1[p2items[i]]<<"\n";
}

//Joining items
int l2[5][3];
int l2t1; //will hold first item for join
int l2t2; //will hold second item for join
int l2pos1=0; //position pointer in l2 array
int l2ocount=0; //product join occruance counter
int l2jcount=0; //join counter
for(i=0;i<p2pcount;i++)
{
for(j=i+1;j<p2pcount;j++)
{
l2t1=p2items[i]+1;
l2t2=p2items[j]+1;
if(l2t1==l2t2)
{
//it is self join
continue;
}
//join the elements
l2[l2pos1][0]=l2t1;
l2[l2pos1][1]=l2t2;
l2jcount++;
//count occurances
l2ocount=0; //reset counter
for(k=0;k<5;k++)
{
    f1=f2=0; //resetting flag
    //scan a purcahse
    for(l=0;l<6;l++)
    {
        if(l2t1==a[k][l])
        {
        //one of the element found
        f1=1;
        }
        if(l2t2==a[k][l])
        {
        //second elements also found
        f2=1;
        }
    }
    //one purchase scanned
    if(f1==1&&f2==1) //both items are present in purchase
    {
    l2ocount++;
    }
}
//assign count
l2[l2pos1][2]=l2ocount;
l2pos1++;
}
}
//Printing second pass
cout<<"\n\nGenerating Candidate item (CL2)\n";
cout<<"item set\tSupport\n\n";
for(i=0;i<l2jcount;i++)
{
    for(j=0;j<3;j++)
    {
    cout<<l2[i][j]<<"\t";
    }
    cout<<"\n";
}



//Third pass
int p3pcount=0;
int p3items[11];
int p3pos=0;

for(i=0;i<11;i++)
{
    if(l2[i][2]>=min)
    {
    p3pcount++;
    p3items[p3pos]=i;
    p3pos++;
    }
}
//Printing selected items for second pass
cout<<"\nGenerating Frequent item set (L2)\n";
cout<<"item set\tSupport\n\n";
for(i=1;i<p3pos;i++)
{
cout<<l2[p3items[i]][0]<<"\t"<<l2[p3items[i]][1]<<"\t"<<l2[p3items[i]][2]<<"\n";
}


//Joining
int l3[5][4];
int l3ocount=0; //occurance counter
int l3jcount=0; //join counter
for(i=0;i<p3pcount;i++)
{
for(j=i+1;j<p3pcount;j++)
{
    for(k=j+1;k<p3pcount;k++)
    {
        l3[i][0]=l2[p3items[i]][0];
        l3[i][1]=l2[p3items[i]][1];
        if(l2[p3items[i]][1]==l2[p3items[j]][0])
        {
            l3[i][2]=l2[p3items[j]][1];
            l3jcount++;
        }
       
        //count occurances
        l3ocount=0; //reset counter
        for(k=0;k<5;k++)
        {
            f1=f2=f3=0; //resetting flag
            //scan a purcahse
            for(l=0;l<6;l++)
            {
                if(l3[i][0]==a[k][l])
                {
                //one of the element found
                f1=1;
                }
                if(l3[i][1]==a[k][l])
                {
                //second elements also found
                f2=1;
                }
                if(l3[i][2]==a[k][l])
                {
                //second elements also found
                f3=1;
                }

            }
            //one purchase scanned
            if(f1==1&&f2==1&&f3==1) //all items are present in purchase
            {
            l3ocount++;
            }
        }

        //assign count
        l3[i][3]=l3ocount;
        }
}
}
//Printing second pass
cout<<"\n\nGenerating Candidate item (CL3)\n";
cout<<"Item set\t\tSupport\n\n";
for(i=0;i<l3jcount;i++)
{
    for(j=0;j<4;j++)
    {
    cout<<l3[i][j]<<"\t";
    }
cout<<"\n";
}

//Ending
return 0;
}

/*
     Output
     
unix@unix-HP-280-G1-MT:~/Desktop/30$ g++ apriori.cpp
unix@unix-HP-280-G1-MT:~/Desktop/30$ ./a.out

 Enter items for Transaction T1: 1
2
3
4
5
6

 Enter items for Transaction T2: 7
2
3
4
5
6

 Enter items for Transaction T3: 1
8
4
5
0
0

 Enter items for Transaction T4: 1
9
10
4
6
0

 Enter items for Transaction T5: 10
2
2
4
11
5

 Enter minimum support : 3
Initial Input
----------------------------------------------------------
Trasaction		Items
----------------------------------------------------------
T1		1	2	3	4	5	6	
T2		7	2	3	4	5	6	
T3		1	8	4	5	0	0	
T4		1	9	10	4	6	0	
T5		10	2	2	4	11	5	
----------------------------------------------------------

Assume minimum support: 3

Generating Candidate item (CL1)
item set	Support

 1		3
 2		4
 3		2
 4		5
 5		4
 6		3
 7		1
 8		1
 9		1
 10		2
 11		1

Generating Frequent item set (L1)
item set	Support

  1		3
  2		4
  4		5
  5		4
  6		3


Generating Candidate item (CL2)
item set	Support

1	2	1	
1	4	3	
1	5	2	
1	6	2	
2	4	3	
2	5	3	
2	6	2	
4	5	4	
4	6	3	
5	6	2	

Generating Frequent item set (L2)
item set	Support

2	4	3
2	5	3
4	5	4
4	6	3


Generating Candidate item (CL3)
Item set		Support

1	4	5	2	
2	4	5	3	     

*/
