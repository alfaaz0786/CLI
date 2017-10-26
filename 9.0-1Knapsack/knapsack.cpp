#include<stdlib.h>
#include <queue>
#include <iostream>
#include <cstdlib>
using namespace std;

struct node
{
    int level;
    int profit;
    int weight;
    int bound;
};

int bound(node u, int n, int W, vector<int> pVa, vector<int> wVa)
{
    int j = 0, k = 0;
    int totweight = 0;
    int result = 0;

    if (u.weight >= W)
    {
        return 0;
    }
    else
    {
        result = u.profit;
        j = u.level + 1;
        totweight = u.weight;

        while ((j < n) && (totweight + wVa[j] <= W))
        {
            totweight = totweight + wVa[j];
            result = result + pVa[j];
            j++;
        }

        k = j;

        if (k < n)
        {
            result = result + (W - totweight) * pVa[k]/wVa[k];
        }
        return result;
    }
}

int knapsack(int n, int p[], int w[], int W)
{
    queue<node> Q;
    node u, v;
    vector<int> pV;
    vector<int> wV;
    Q.empty();

    for (int i = 0; i < n; i++)
    {
        pV.push_back(p[i]);
        wV.push_back(w[i]);
    }

    v.level = -1; 
    v.profit = 0;
    v.weight = 0;

    int maxProfit = 0;

    //v.bound = bound(v, n, W, pV, wV);
    Q.push(v);

    while (!Q.empty())
    {
        v = Q.front();
        Q.pop();

        if (v.level == -1)
        {
            u.level = 0;
        }
        else if (v.level != (n - 1))
        {
            u.level = v.level + 1;
        }

        u.weight = v.weight + w[u.level];
        u.profit = v.profit + p[u.level];

        u.bound = bound(u, n, W, pV, wV);

        if (u.weight <= W && u.profit > maxProfit)
        {
            maxProfit = u.profit;
        }

        if (u.bound > maxProfit)
        {
            Q.push(u);
        }

        u.weight = v.weight;
        u.profit = v.profit;

        u.bound = bound(u, n, W, pV, wV);

        if (u.bound > maxProfit)
        {
            Q.push(u);
        }
    }
    return maxProfit;
}

int main()
{
    int maxProfit,n,p[10],w[10],W;

    cout << "Enter the number of items in a Knapsack:";
    cin >> n;

    for (int i = 0; i < n; i++)
    {

        cout << "Enter value and weight for item " << i << ": ";

        cin >> p[i];

        cin >> w[i];

    }

    cout << "Enter the capacity of knapsack : ";
    cin >> W;
   


    cout << "Output: "<< knapsack(n, p, w, W) << endl;
cout<<"\n";
    exit(0);
}

/*   OUTPUT 


cl1@ubuntu:~/Desktop$ g++ BranchAndBoundKnapsack.cpp
cl1@ubuntu:~/Desktop$ ./a.out
Enter the number of items in a Knapsack:5   
Enter value and weight for item 0: 1 20
Enter value and weight for item 1: 2 30
Enter value and weight for item 2: 4 06
Enter value and weight for item 3: 9 92
Enter value and weight for item 4: 7 10
Enter the capacity of knapsack : 40
Output: 12

cl1@ubuntu:~/Desktop$ ./a.out
Enter the number of items in a Knapsack:5
Enter value and weight for item 0: 1 20
Enter value and weight for item 1: 2 30
Enter value and weight for item 2: 4 06
Enter value and weight for item 3: 9 92
Enter value and weight for item 4: 7 10
Enter the capacity of knapsack : 50
Output: 13

*/


