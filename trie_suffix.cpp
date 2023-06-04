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

class SuffixTrie
{
public:
    Node *root;

    SuffixTrie()
    {
        root = new Node('\0');
    }

    void insert_helper(string word)
    {
        Node *temp = root;

        for (char ch : word)
        {
            if (temp->m.count(ch) == 0)
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
        for (char ch : word)
        {
            if (temp->m.count(ch) == 0)
                return false;
            temp = temp->m[ch];
        }

        return temp->isTerminal;
    }

    void insert(string s)
    {
        for (int i = 0; s[i] != '\0'; i++)
        {
            insert_helper(s.substr(i));
        }
    }
};

int main()
{
    system("cls");
    cout << "Abhay " << endl
         << endl;

    SuffixTrie ST;
    string s = "hello";
    ST.insert(s);

    string suffixes[] = {"lo", "ell", "hello"};
    for (auto word : suffixes)
    {
        if (ST.search(word))
            cout << "Yes\n";
        else
            cout << "No\n";
    }

    return 0;
}