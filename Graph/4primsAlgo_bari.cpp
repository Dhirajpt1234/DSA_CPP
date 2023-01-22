#include <bits/stdc++.h>
using namespace std;
const int V = 8;
const int I = 1e5 + 10;

void primsAlgo(int cost[][V], int n)
{
    int near[n + 1];
    int arr[2][n - 1];
    int min = I;

    int u = 0, v = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            if (cost[i][j] < min)
            {
                min = cost[i][j];
                u = i;
                v = j;
            }
        }
    }

    near[u] = 0;
    near[v] = 0;
    arr[0][0] = u;
    arr[1][0] = v;

    for (int i = 1; i <= n; i++)
    {
        if (i != u && i != v)
        {
            if (cost[u][i] < cost[v][i])
            {
                near[i] = u;
            }
            else
            {
                near[i] = v;
            }
        }
    }

    // cout << "hii\n";
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << near[i] << ' ';
    // }
    // cout << endl;

    for (int i = 1; i < (n - 1); i++)
    {
        int k = 0;
        min = I;
        for (int j = 1; j <= n; j++)
        {
            if (near[j] != 0)
            {
                if (cost[j][near[j]] < min)
                {
                    min = cost[j][near[j]];
                    k = j;
                }
            }
        }
        // cout << "\n value of k : " << k << endl;

        arr[0][i] = k;
        arr[1][i] = near[k];
        near[k] = 0;

        for (int j = 1; j <= n; j++)
        {
            if (near[j] != 0)
            {
                if (cost[j][k] < cost[j][near[j]])
                {
                    near[j] = k;
                }
            }
        }

        // to know the changes array(near)
        // for (int j = 1; j <= n; j++)
        // {
        //     cout << near[j] << ' ';
        // }
        // cout << endl;

        // to see the array with prims nodes and weight
        // for (int l = 0; l <= i; l++)
        // {
        //     cout << "\nyo -> ";
        //     cout << arr[0][l] << ' ' << arr[1][l] << endl;
        // }
    }

    cout << "\nMinimum Spanning tree by Prims Algo is as follws : \n";
    for (int i = 0; i < n - 1; i++)
    {
        cout << arr[0][i] << ' ' << arr[1][i] << " --> " << cost[arr[0][i]][arr[1][i]] << endl;
    }
}

int main()
{

    int cost[V][V]{
        {I, I, I, I, I, I, I, I},
        {I, I, 25, I, I, I, 5, I},
        {I, 25, I, 12, I, I, I, 10},
        {I, I, 12, I, 8, I, I, I},
        {I, I, I, 8, I, 16, I, 14},
        {I, I, I, I, 16, I, 20, 18},
        {I, 5, I, I, I, 20, I, I},
        {I, I, 10, I, 14, 18, I, I}};

    primsAlgo(cost, V - 1);

    return 0;
}