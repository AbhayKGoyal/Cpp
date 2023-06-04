#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    Node *left;
    Node *right;
};

class Trie
{
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    void insert(int n)
    {
        Node *temp = root;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (n >> i) & 1;
            if (bit == 0)
            {
                if (temp->left == NULL)
                {
                    temp->left = new Node();
                }
                temp = temp->left;
            }
            else
            {
                if (temp->right == NULL)
                {
                    temp->right = new Node();
                }
                temp = temp->right;
            }
        }
    }

    int max_xor_helper(int value)
    {
        int curr_ans = 0;
        Node *temp = root;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (value >> i) & 1;
            if (bit == 0)
            {
                if (temp->right != NULL)
                {
                    temp = temp->right;
                    curr_ans += (1 << i);
                }
                else
                    temp = temp->left;
            }
            else
            {
                if (temp->left != NULL)
                {
                    temp = temp->left;
                    curr_ans += (1 << i);
                }
                else
                    temp = temp->right;
            }
        }
        return curr_ans;
    }
};

int max_xor_pair(vector<int> arr)
{
    // implement the max xor pair function
    int n = arr.size();
    Trie t;
    int max_xor = 0;
    for (int i = 0; i < n; i++)
    {
        int value = arr[i];
        t.insert(value);
        int current_xor = t.max_xor_helper(value);
        max_xor = max(max_xor, current_xor);
    }

    return max_xor;
}

int main()
{
    cout << "Abhay " << endl;
    vector<int> input = {3, 10, 5, 25, 9, 2};
    Trie t;
    cout << max_xor_pair(input) << endl;

    return 0;
};
