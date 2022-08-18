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

    void Print(TrieNode *curr, string prefix, vector<string> &temp)
    {
        if (curr->isTerminal)
        {
           temp.push_back(prefix);
        }

        

        for(int i = 0 ; i< 26 ; i++)
        {
            if(curr->children[i] != NULL)
            {   
                prefix.push_back(curr->children[i]->c);
                Print(curr->children[i], prefix, temp);
                prefix.pop_back();
            }
        }
    }

    vector<vector<string>> PhoneDirectory(string &input)
    {
        string prefix = "";
        vector<vector<string>> ans;
        
        TrieNode * prev = root;
        for(int i = 0 ; i< input.length() ; i++)
        {

            // Prefix  badhta jayega yahan 
            prefix.push_back(input[i]);

            
            TrieNode * curr = prev->children[input[i]-'A'];

            if(!curr)
            break;

            vector<string> temp;
            Print(curr, prefix, temp);
            ans.push_back(temp);
            prev = curr ; 
        }
       
        return ans;
    }
};

int main()
{

    Trie *t = new Trie();

    t->InsertWord("COD");
    t->InsertWord("CODING");
    t->InsertWord("CODDING");
    t->InsertWord("CODE");
    t->InsertWord("CODER");
    t->InsertWord("CODINGER");
    t->InsertWord("CODINGERRR");
    t->InsertWord("COLY");

    string input = "CODING";

    vector<vector<string>> ans = t->PhoneDirectory(input);

    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}