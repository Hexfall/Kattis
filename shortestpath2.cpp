#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    int nodes, edges, queries, source;
    bool first = true;
    while (scanf("%d %d %d %d", &nodes, &edges, &queries, &source),
           (nodes | edges | queries | source))
    {
        if (!first)
            printf("\n");
        else
            first = false;
        int dist[nodes];
        bool done[nodes];
        vector<int> dest[nodes],
                    weight[nodes],
                    opens[nodes],
                    repeat[nodes];
        while (nodes--)
        {
            dist[nodes - 1] = -1;
            done[nodes - 1] = false;
        }
        dist[source] = 0;

        while (edges--)
        {
            int u, v, t, p, d;
            scanf("%d %d %d %d %d", &u, &v, &t, &p, &d);
            dest[u].push_back(v);
            weight[u].push_back(d);
            opens[u].push_back(t);
            repeat[u].push_back(p);
        }

        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > que;
        que.push(make_pair(0, source));
        
        while (!que.empty())
        {
            int u = que.top().second;
            que.pop();
            if (done[u])
                continue;
            done[u] = true;
            for (int e = 0; e < dest[u].size(); e++)
            {
                int v = dest[u][e];
                if (dist[v] <= dist[u] && dist[v] != -1)
                    continue;
                if (repeat[u][e] == 0)
                {
                    if (dist[u] > opens[u][e])
                        continue;
                    if (dist[v] == -1 ||
                        dist[v] < opens[u][e] + weight[u][e])
                    {
                        dist[v] = opens[u][e] + weight[u][e];
                        que.push(make_pair(dist[v], v));
                    }
                }
                else
                {
                    int distTo;
                    if (dist[u] <= opens[u][e])
                        distTo = opens[u][e];
                    else
                    {
                        distTo = opens[u][e] +
                                 (dist[u] - opens[u][e]) -
                                 ((dist[u] - opens[u][e]) % repeat[u][e]);
                        if ((dist[u] - opens[u][e]) % repeat[u][e] != 0)
                            distTo += repeat[u][e];
                    }
                    distTo += weight[u][e];
                    if (dist[v] == -1 ||
                        distTo < dist[v])
                    {
                        dist[v] = distTo;
                        que.push(make_pair(dist[v], v));
                    }
                }
            }
        }
        while (queries--)
        {
            int i;
            scanf("%d", &i);
            if (dist[i] == -1)
                printf("Impossible\n");
            else
                printf("%d\n", dist[i]);
        }
    }
}
