#include <iostream>
#include <unordered_map>
using namespace std;

class Node
{
public:
    char data;
    unordered_map<char, Node *> m;
    bool isTerminal;

    Node(char d)
    {
        data = d;
        // Initially map is empty so no initialization
        isTerminal = false;
    }
};

class Trie
{
public:
    Node *root;

    Trie()
    {
        root = new Node('\0');
    }

    void insert(string word)
    {
        Node *temp = root;

        for(char ch : word)
        {
            if(temp->m.count(ch) == 0)
            {
                Node *n = new Node(ch);
                temp->m[ch] = n;
            }
            temp = temp->m[ch];
        }
        temp->isTerminal = true;
    }

    bool search(string word)
    {
        Node *temp = root;
        for(char ch : word)
        {
            if(temp->m.count(ch) == 0)
                return false;
            temp = temp->m[ch];
        }

        return temp->isTerminal;
    }
};

int main()
{
    Trie t;
    string words[] = {"apple", "ape", "news", "new"};
    for(auto word : words)
    {
        t.insert(word);
    }

    int q;
    cin >> q;

    string search_word;
    while(q--)
    {
        cin >> search_word;
        if(t.search(search_word) == true)
            cout << "Yes\n";
        else
            cout << "No\n";
    }

    return 0;
}