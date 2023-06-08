#include <iostream>
#include <set>
#include <list>
#include <utility>
#include <climits>
#include <vector>

using namespace std;

class Graph
{
public:
    int V;
    list<pair<int, int>> *l;

    Graph(int v)
    {
        V = v;
        l = new list<pair<int, int>>[V];
    }

    void addEdge(int u, int v, int wt)
    {
        l[u].push_back({wt, v});
        l[v].push_back({wt, u});
    }

    int dijkshtra(int src, int dest)
    {
        set<pair<int, int>> s;
        vector<int> dist(V, INT_MAX);
        s.insert({0, src});
        dist[src] = 0;

        while(!s.empty())
        {
            auto it = s.begin();
            int curr_edge = it->first;
            int node = it->second;
            s.erase(it);

            for(auto nbr_pair : l[node])
            {
                int nbr_dist = nbr_pair.first;
                int nbr = nbr_pair.second;

                if(curr_edge + nbr_dist < dist[nbr])
                {
                    pair<int, int> f = {dist[nbr], nbr};
                    if(s.find(f) != s.end())
                    {
                        s.erase(f);
                    }

                    dist[nbr] = curr_edge + nbr_dist;
                    s.insert({dist[nbr], nbr});
                }
            }
        }

        for(int i = 0; i < V; i++)
        {
            cout << "Shortest distance from " << src << "th to " << i << "th vertex is " << dist[i] << endl;
        }

        return dist[dest];
    }
};

int main()
{
    Graph g(5);

    g.addEdge(0, 1, 1);
    g.addEdge(0, 2, 4);
    g.addEdge(0, 3, 7);
    g.addEdge(1, 2, 2);
    g.addEdge(2, 3, 2);
    g.addEdge(3, 4, 3);

    cout << g.dijkshtra(0, 4) << endl;
    return 0;
}