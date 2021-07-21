#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<pair<int, int>>> get_edges(int nodeCount, int edgeCount)
{
    // Create a list, where each index refers to the edges of the node with the given index.
    vector<vector<pair<int, int>>> edges; // edges[index] = <target, weight>.
    for (int i = 0; i < nodeCount; i++)
        // Initialize list.
        edges.push_back(vector<pair<int, int>>());
    // Read edges.
    while (edgeCount--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges[u].push_back(make_pair(v, w));
    }
    
    return edges;
}

vector<int> get_dists(vector<vector<pair<int, int>>> edges, int startIndex)
{
    vector<int> dist;
    bool done[edges.size()];
    for (int i = 0; i < edges.size(); i++)
    {
        dist.push_back(-1);
        done[i] = false;
    }
    dist[startIndex] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> closest;
    closest.push(make_pair(0, startIndex));
    while (!closest.empty())
    {
        int u = closest.top().second;
        closest.pop();
        if (done[u])
            continue;
        
        for (auto edge : edges[u])
        {
            int v = edge.first,
                w = edge.second;
            if (done[v])
                continue;
            
            if (dist[v] == -1 || dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                closest.push(make_pair(dist[v], v));
            }
        }
        
        done[u] = true;
    }

    return dist;
}

int main()
{
    int n, m, q, s;
    while ((cin >> n >> m >> q >> s) && (n|m|q|s))
    {
        vector<int> dist = get_dists(get_edges(n, m), s);

        while (q--)
        {
            int i;
            cin >> i;
            if (dist[i] == -1)
                cout << "Impossible";
            else
                cout << dist[i];
            cout << endl;
        }
        cout << endl;
    }
}
