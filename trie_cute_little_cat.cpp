/* 
----------------------------------------- Question -----------------------------------
-------------------------------------- Little Cute Cat -------------------------------
Little cute kitten loves to write stories in a Github readme document. One day she is 
given a list of words, you want to help her to check if each of these words are present 
in the readme file.

Sample Input: 
document ="little cute cat loves to code in c++, java &
python"
words = ["cute cat", "ttle", "cat", "quick", "big"] 

Sample Output: 
{"yes", "yes", "yes", "no", "no"}

*/

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Node
{
public:
    char data;
    unordered_map<char, Node *> children;
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

        for (char ch : word)
        {
            if (temp->children.count(ch) == 0)
            {
                Node *n = new Node(ch);
                temp->children[ch] = n;
            }
            temp = temp->children[ch];
        }
        temp->isTerminal = true;
    }

};

void search_helper(Trie t, string &document, int i, unordered_map<string, bool> &m)
{
    Node *temp = t.root;

    for(int j = i; j < document.length(); j++)
    {
        char ch = document[j];
        if(temp->children.count(ch) == 0)
            return;
        temp = temp->children[ch];
        if(temp->isTerminal == true)
        {
            string str = document.substr(i, j-i+1);
            m[str] = true;
        }
    }

}

void document_search(string &document, vector<string> words)
{
    Trie t;
    for(auto w : words)
        t.insert(w);

    unordered_map<string, bool> umap;
    for(int i = 0; i < document[i] != '\0'; i++)
    {
        search_helper(t, document, i, umap);
    }

    for(auto w : words)
    {
        if(umap[w] == true)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return;
}

int main()
{
    cout << "Abhay " << endl;
    
    string document = "little cute cat loves to code in c++, java & python";
    vector<string> words = {"cute cat", "ttle", "cat", "quick", "big"};

    document_search(document, words);

    return 0;
}
