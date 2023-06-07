#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <string>

using namespace std;

class Node
{
public:
    string name;
    list<string> nbrs;

    Node(string n)
    {
        name = n;
    }
};

class Graph
{
private:
    unordered_map<string, Node*> m;
public:
    Graph(vector<string> cities)
    {
        for(auto city: cities)
        {
            m[city] = new Node(city);
        }
    }

    void addEdge(string a, string b, bool undir = false)
    {
        m[a]->nbrs.push_back(b);
        if(undir)
            m[b]->nbrs.push_back(a);
    }

    void print()
    {
        for(auto cityNameNode : m)
        {
            string cityName = cityNameNode.first;
            Node* cityNode = cityNameNode.second;
            std::cout << cityName << " ---> ";
            for(auto s : cityNode->nbrs)
            {
                std::cout << s << ", ";
            }
            std::cout << endl;
        }
    }
    
};



int main()
{
    vector<string> cities = {"London", "Delhi", "Paris", "New-York"};
    Graph g(cities);

    g.addEdge("Delhi", "London");    
    g.addEdge("Delhi", "Paris");    
    g.addEdge("Paris", "New-York");    
    g.addEdge("New-York", "London");

    g.print();

    return 0;
}