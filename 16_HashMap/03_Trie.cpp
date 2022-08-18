#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

class TrieNode
{
public:
    char c;
    TrieNode *children[26];
    bool isTerminal;

    TrieNode(char ch)
    {
        c = ch;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
            isTerminal = false;
    }
};

class Trie
{

private:
    TrieNode *root = new TrieNode('\0');

    void InsertRecursively(TrieNode *root, string word)
    {
        // Base Case
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }

        TrieNode *child;

        if (root->children[word[0] - 'A'] != NULL)
        {
            child = root->children[word[0] - 'A'];
        }
        else
        {
            child = new TrieNode(word[0]);
            root->children[word[0] - 'A'] = child;
        }

        InsertRecursively(child, word.substr(1));
    }

    bool SearchRecursively(TrieNode *root, string word)
    {
        if (word.length() == 0)
            return (root->isTerminal);

        if (root->children[word[0] - 'A'] != NULL)
        {
            return SearchRecursively(root->children[word[0] - 'A'], word.substr(1));
        }
        return false;
    }

    void DeleteRecursively(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            root->isTerminal = false;
        }
        else if (root->children[word[0] - 'A'] != NULL)
        {
            DeleteRecursively(root->children[word[0] - 'A'], word.substr(1));
        }
    }

public:
    void InsertWord(string word)
    {
        InsertRecursively(root, word);
    }

    bool SearchWord(string word)
    {
        return SearchRecursively(root, word);
    }

    void DeleteWord(string word)
    {
        DeleteRecursively(root, word);
    }
};

int main()
{

    Trie t;

    t.InsertWord("KHWAJA");
    t.InsertWord("ABDUL");
    t.InsertWord("SAMAD");
    cout << t.SearchWord("KHWAJA") << endl;
    cout << t.SearchWord("ABDUL") << endl;
    cout << t.SearchWord("SAMAD") << endl;

    t.DeleteWord("KHWAJA");
    t.DeleteWord("KHWAJADKJHDJ");
    cout << t.SearchWord("KHWAJA") << endl;
    cout << t.SearchWord("KHWAJA") << endl;

    return 0;
}