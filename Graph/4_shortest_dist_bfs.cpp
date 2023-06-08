#include <iostream>
#include <queue>
#include <list>
using namespace std;

class Graph
{
public:
    int V;
    list<int> *l;

    Graph(int v)
    {
        V = v;
        l = new list <int> [V];
    }

    void addEdge(int i, int j, bool undir = true)
    {
        l[i].push_back(j);
        if(undir)
            l[j].push_back(i);
    }
    
    void print()
    {
        for(int i = 0; i < V; i++)
        {
            cout << i << " ---> ";
            for(int a : l[i])
            {
                cout << a << ", ";
            }
            cout << endl;
        }
    }

    void ShortestPath(int source, int dest = -1) // dest -> destination
    {
        vector<bool> visited(V, false);
        queue<int> q;
        int *dist = new int[V]{0};
        int *parent = new int[V]{-1};

        q.push(source);
        dist[source] = 0;
        parent[source] = source;
        visited[source] = true;

        while(!q.empty())
        {
            int k = q.front();
            // cout << k << " ";
            q.pop();

            for(auto nbr : l[k])
            {
                if(!visited[nbr])
                {
                    q.push(nbr);
                    visited[nbr] = true;
                    parent[nbr] = k;
                    dist[nbr] = dist[k] + 1;
                }
            }
        }
        cout << endl;
        for(int i = 0; i < V; i++)
            cout << "Shortest distance to node " << i << " is " << dist[i] << endl;
        cout << endl;

        if(dest != -1)
        {
            int temp = dest;
            while(temp != source)
            {
                cout << temp << " -- ";
                temp = parent[temp];
            }
            cout << source << endl;
        }
    }
};
/*   Graph:-
               2 ---- 3
              /       | \
             /        |  \
            1         |   5
             \        |  / \ 
              \       | /   \
               0 ---- 4      6
 */
int main()
{
    Graph g(7);
    g.addEdge(1,2);
    g.addEdge(0,1);
    g.addEdge(2,3);
    g.addEdge(0,4);
    g.addEdge(4,3);
    g.addEdge(5,3);
    g.addEdge(4,5);
    g.addEdge(5,6);
    // cout << "Adjacency List : \n";
    // g.print();

    // cout << "\nBFS Traversal : \n";
    g.ShortestPath(1, 6);
    cout << endl;
    return 0;
}
