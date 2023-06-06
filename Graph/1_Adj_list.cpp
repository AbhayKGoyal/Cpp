#include <iostream>
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
};

int main()
{
    Graph g(6);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(0,4);
    g.addEdge(4,5);
    g.addEdge(4,3);
    g.addEdge(5,3);
    g.addEdge(2,3);

    g.print();
    return 0;
}
