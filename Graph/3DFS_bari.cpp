#include <bits/stdc++.h>
#include "stackG.h"
using namespace std;

void DFS(int arr[][8], int n, int i)
{
    static int visited[8] = {0};
    Stack s(10);

    cout << i << " ";
    visited[i] = 1;

    for (int j = 1; j < n; j++)
    {
        if (visited[j] == 0 && arr[i][j] == 1)
        {

            DFS(arr, n, j);
        }
    }
}

int main()
{
    int n = 8;
    int arr[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 1, 1, 1, 0, 0, 0},
                     {0, 1, 0, 1, 0, 0, 0, 0},
                     {0, 1, 1, 0, 1, 1, 0, 0},
                     {0, 1, 0, 1, 0, 1, 0, 0},
                     {0, 0, 0, 1, 1, 0, 1, 1},
                     {0, 0, 0, 0, 0, 1, 0, 0},
                     {0, 0, 0, 0, 0, 1, 0, 0}};
    DFS(arr, n, 4);

    return 0;
}
