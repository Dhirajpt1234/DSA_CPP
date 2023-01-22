#include <bits/stdc++.h>
#include "queueG.h"
using namespace std;

void BFS(int arr[][8], int n, int i)
{
    cout << "\nBFS traversal is as follows : ";
    int visited[8] = {0};
    Queue q(10);

    cout << i << ' ';
    visited[i] = 1;
    q.enqueue(i);

    while (!q.isEmpty())
    {
        int j = q.dequeue();
        for (int k = 1; k < n; k++)
        {
            if (arr[j][k] == 1 && visited[k] == 0)
            {
                cout << k << ' ';
                visited[k] = 1;
                q.enqueue(k);
            }
        }
    }

    cout << " Finish!";
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
    BFS(arr, n, 4);

    return 0;
}
