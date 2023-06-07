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
    
    void printBFS(int n)
    {
        vector<bool> visited(V, false);
        queue<int> q;
        q.push(n);
        visited[n] = true;

        while(!q.empty())
        {
            int k = q.front();
            cout << k << " ";
            q.pop();

            for(auto a : l[k])
            {
                if(!visited[a])
                {
                    q.push(a);
                    visited[a] = true;
                }
            }
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

    g.printBFS(1);
    return 0;
}
