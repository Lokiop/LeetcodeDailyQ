#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *links[26];
    bool flag = false;
};

class WordDictionary
{
    Node *root;

public:
    WordDictionary()
    {
        root = new Node();
    }

    void addWord(string word)
    {
        Node *node = root;
        for (auto &i : word)
        {
            if (node->links[i - 'a'] == NULL)
            {
                node->links[i - 'a'] = new Node();
            }
            node = node->links[i - 'a'];
        }

        node->flag = true;
    }

    bool search(string word)
    {
        return searchHelper(root, word, 0);
    }

    bool searchHelper(Node *node, string &word, int index)
    {
        if (!node)
            return false;

        if (index == word.length())
        {
            return node->flag;
        }

        char c = word[index];
        if (c == '.')
        {
            for (auto &p : node->links)
            {
                if (searchHelper(p, word, index + 1))
                {
                    return true;
                }
            }
            return false;
        }
        else
        {
            if (node->links[c - 'a'] == NULL)
            {
                return false;
            }
            Node *child = node->links[c - 'a'];
            return searchHelper(child, word, index + 1);
        }
    }
};

int main()
{

    return 0;
}