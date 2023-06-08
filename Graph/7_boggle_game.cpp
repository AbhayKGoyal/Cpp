#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

#define M 3
#define N 4

class Node
{
public:
    char ch;
    unordered_map<char, Node *> children;
    bool isTerminal;
    string word;

    Node(char c)
    {
        ch = c;
        isTerminal = false;
        word = "";
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

    void addWord(string w)
    {
        Node *temp = root;
        for (auto ch : w)
        {
            if (temp->children.count(ch) == 0)
                temp->children[ch] = new Node(ch);

            temp = temp->children[ch];
        }
        temp->isTerminal = true;
        temp->word = w;
    }
};

void dfs(char board[M][N], Node *node, int i, int j, vector<vector<bool>> visited, unordered_set<string> &output)
{
    char ch = board[i][j];
    if (node->children.count(ch) == 0)
        return;

    visited[i][j] = true;
    node = node->children[ch];

    if (node->isTerminal)
        output.insert(node->word);

    int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
    int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};

    for(int k = 0; k < 8; k++)
    {
        int ni = i + dx[k];
        int nj = j + dy[k];

        if(ni >= 0 && nj >= 0 && ni < M && nj < N && !visited[ni][nj])
        {
            dfs(board, node, ni, nj, visited, output);
        }
    }

    // last step i.e. Backtracking

    visited[i][j] = false;
    return;
}

int main()
{

    vector<string> words = {"SNAKE", "FOR", "QUEZ", "SNACK", "SNACKS", "GO", "TUNES", "CAT"};

    char board[M][N] = {{'S', 'E', 'R', 'T'},
                        {'U', 'N', 'K', 'S'},
                        {'T', 'C', 'A', 'T'}};

    unordered_set<string> output;
    // 1. Trie
    Trie t;
    for (auto word : words)
    {
        t.addWord(word);
    }

    vector<vector<bool>> visited(M, vector<bool>(N, false));
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            dfs(board, t.root, i, j, visited, output);
        }
    }

    // 4. Print the Output

    for (auto word : output)
    {
        cout << word << endl;
    }

    return 0;
}
