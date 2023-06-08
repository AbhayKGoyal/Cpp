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

    void printDFS(int source, vector<bool> &visited)
    {
        visited[source] = true;
        std::cout << source << ", ";

        for(auto nbr : l[source])
        {
            if(!visited[nbr])
                printDFS(nbr, visited);
        }

        return;
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
    g.addEdge(5,3);
    g.addEdge(4,3);
    g.addEdge(5,6);
    g.addEdge(4,5);

    vector<bool> visited(7, false);

    cout << "Adjacency List : \n";
    g.print();

    cout << "\nDFS Traversal : \n";
    g.printDFS(1, visited);
    return 0;
}
