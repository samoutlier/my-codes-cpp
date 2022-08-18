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
    int childcount;

    TrieNode(char ch)
    {
        c = ch;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
            isTerminal = false;
        }
        childcount = 0;
    }
};

class Trie
{
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode('\0');
    }

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
            root->childcount++;
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

    string LongestCommonPrefix(string word)
    {  
        string ans = "";
        TrieNode * temp = root;
        int i = 0;
        while(temp->childcount == 1 && i<word.size())
        {
            int index = word[i++]-'A';
           ans.push_back(temp->children[index]->c);
           temp =  temp->children[index];
        }
        return ans;
    }
};

int main()
{

    Trie *t = new Trie();

    t->InsertWord("CODING");
    t->InsertWord("CODED");
    t->InsertWord("CODER");
    t->InsertWord("CODDDDDD");

    cout << t->LongestCommonPrefix("CODING");

    return 0;
}