//TITLE: K NEAREST NEIGHBOUR IMPLEMENTATION
#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
 
struct Point
{
    int val;     // Group of point
    double x, y;     // Co-ordinate of point
    double distance; // Distance from test point
};
 
// Used to sort an array of points by increasing order of distance
bool comparison(Point a, Point b)
{
    return (a.distance < b.distance);
}
 
/* This function finds classification of point p using k nearest neighbour algorithm. It assumes only two groups and returns 0 if p belongs to group 0, else 1 (belongs to group 1).*/
int classifyAPoint(Point arr[], int n, int k, Point p)
{
    // Fill distances of all points from p
    for (int i = 0; i < n; i++)
        arr[i].distance = sqrt((arr[i].x - p.x) * (arr[i].x - p.x) + (arr[i].y - p.y) * (arr[i].y - p.y));
 
    // Sort the Points by distance from p
    sort(arr, arr+n, comparison);
 
    // Now consider the first k elements and only two groups
    int freq1 = 0;   // Frequency of group 0
    int freq2 = 0;   // Frequency of group 1
    for (int i = 0; i < k; i++)
    {
        if (arr[i].val == 0)
            freq1++;
        else if (arr[i].val == 1)
            freq2++;
    }
 
    return (freq1 > freq2 ? 0 : 1);
}
 
// Driver code
int main()
{
    int n = 17; // Number of data points
    Point arr[n];
 
    arr[0].x = 1;
    arr[0].y = 12;
    arr[0].val = 0;
 
    arr[1].x = 2;
    arr[1].y = 5;
    arr[1].val = 0;
 
    arr[2].x = 5;
    arr[2].y = 3;
    arr[2].val = 1;
 
    arr[3].x = 3;
    arr[3].y = 2;
    arr[3].val = 1;
 
    arr[4].x = 3;
    arr[4].y = 6;
    arr[4].val = 0;
 
    arr[5].x = 1.5;
    arr[5].y = 9;
    arr[5].val = 1;
 
    arr[6].x = 7;
    arr[6].y = 2;
    arr[6].val = 1;
 
    arr[7].x = 6;
    arr[7].y = 1;
    arr[7].val = 1;
 
    arr[8].x = 3.8;
    arr[8].y = 3;
    arr[8].val = 1;
 
    arr[9].x = 3;
    arr[9].y = 10;
    arr[9].val = 0;
 
    arr[10].x = 5.6;
    arr[10].y = 4;
    arr[10].val = 1;
 
    arr[11].x = 4;
    arr[11].y = 2;
    arr[11].val = 1;
 
    arr[12].x = 3.5;
    arr[12].y = 8;
    arr[12].val = 0;
 
    arr[13].x = 2;
    arr[13].y = 11;
    arr[13].val = 0;
 
    arr[14].x = 2;
    arr[14].y = 5;
    arr[14].val = 1;
 
    arr[15].x = 2;
    arr[15].y = 9;
    arr[15].val = 0;
 
    arr[16].x = 1;
    arr[16].y = 7;
    arr[16].val = 0;
 
    /*Testing Point*/
    Point p;
    p.x = 2.5;
    p.y = 7;
 
    // Parameter to decide groupr of the testing point
    int k = 3;
    cout<< "The value classified to unknown point is "<< classifyAPoint(arr, n, k, p)<<"\n";
    return 0;
}

/*OUTPUT:
The training data is: 
x	y	group
1	12	0
2	5	0
5	3	1
3	2	1
3	6	0
1.5	9	1
7	2	1
6	1	1
3.8	3	1
3	10	0
5.6	4	1
4	2	1
3.5	8	0
2	11	0
2	5	1
2	9	0
1	7	0
The value classified to unknown point is 0 */

//Time Complexity= O(nd+nk)
/* ALGORITHMS LIBRARY: The algorithms library defines functions for a variety of purposes (e.g. searching, sorting, counting, manipulating) that operate on ranges of elements. Note that a range is defined as [first, last) where last refers to the element past the last element to inspect or modify.*/
/*The GNU Standard C++ library, for example, uses a 3-part hybrid sorting algorithm: introsort is performed first (introsort itself being a hybrid of quicksort and heap sort), to a maximum depth given by 2×log2 n, where n is the number of elements, followed by an insertion sort on the result.*/
