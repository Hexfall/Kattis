#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <cstring>

using namespace std;

int main()
{
    int L, R, C;
    while (cin >> L >> R >> C && L|R|C)
    {
        int dist[L][R][C];
        bool unblocked[L][R][C];
        vector<tuple<int, int, int>> edges[L][R][C];
        memset(dist, -1, sizeof(dist));
        memset(unblocked, false, sizeof(unblocked));
        tuple<int, int, int> source, target;
        for (int i = 0; i < L; i++)
        {
            for (int j = 0; j < R; j++)
            {
                for (int k = 0; k < C; k++)
                {
                    char c = getchar();
                    if (c == '#')
                        continue;

                    unblocked[i][j][k] = true;
                    if (i != 0 && unblocked[i-1][j][k])
                    {
                        edges[i][j][k].push_back(make_tuple(i-1, j, k));
                        edges[i-1][j][k].push_back(make_tuple(i, j, k));
                    }
                    if (j != 0 && unblocked[i][j-1][k])
                    {
                        edges[i][j-1][k].push_back(make_tuple(i, j, k));
                        edges[i][j][k].push_back(make_tuple(i, j-1, k));
                    }
                    if (k != 0 && unblocked[i][j][k-1])
                    {
                        edges[i][j][k-1].push_back(make_tuple(i, j, k));
                        edges[i][j][k].push_back(make_tuple(i, j, k+1));
                    }
                    if (c == 'S')
                    {
                        source = make_tuple(i, j, k);
                        dist[i][j][k] = 0;
                    }
                    else if (c == 'E')
                        target = make_tuple(i, j, k);
                }
                getchar();
            }
            getchar();
        }

        queue<tuple<int, int, int>> q;
        q.push(source);
        int* tardist = &dist[get<0>(target)][get<1>(target)][get<2>(target)];
        while (!q.empty() /*&& *tardist == -1*/)
        {
            int i, j, k;
            tie(i, j, k) = q.front();
            q.pop();
            int d = dist[i][j][k];
            for (auto e : edges[i][j][k])
            {
                int l, r, c;
                tie(l, r, c) = e;
                if (dist[l][r][c] != -1)
                    continue;
                dist[l][r][c] = d + 1;
                q.push(make_tuple(l, r, c));
            }
        }

        if (*tardist == -1)
            cout << "Trapped!" << endl;
        else
            cout << "Escaped in " << *tardist << " minute(s)." << endl;
        for (int i = 0; i < L; i++)
        {
            for (int j = 0; j < R; j++)
            {
                for (int k = 0; k < C; k++)
                    cout << dist[i][j][k] << " ";
                cout << endl;
            }
            cout << endl;
        }
    }
}
