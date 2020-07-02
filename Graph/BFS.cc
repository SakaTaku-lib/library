#include<iostream>
#include<queue>
using namespace std;

const int white = 0, gray = 1, black = 2, N = 101, INF = -1;
bool G[N][N];
int n, color[N], d[N];

void init(){
    for (int i = 1; i <= n; i++)
    {
        color[i] = white;
        d[i] = INF;
    }
}

void bfs(int v){
    queue<int> q;
    q.push(v);
    d[v] = 0;
    int u;
    while (!q.empty())
    {
        u = q.front(); q.pop();
        for (int i = 1; i <= n; i++)
        {
            if (G[u][i] && color[i] == white)
            {
                d[i] = d[u] + 1;
                q.push(i);
                color[i] = gray;
            }
        }
    color[u] = black;
    }
}
