#include <iostream>
#include <vector>
using namespace std;

vector<char> Reverse(vector<char> word)
{
    int start = 0;
    int end = word.size()-1;
    while(start<end)
    {
        swap(word[start],word[end]);
        start++;
        end--;
    }
    return word;
}

int main()
{
    vector<char> word;
    char name[80];
    cout << "Enter The Name : ";
    cin>>name;
    for (int i = 0; name[i] != '\0'; i++)
    { 
        word.push_back(name[i]);    
    }
    
    word = Reverse(word);

    for (int i = 0; i < word.size(); i++)
    {
        cout << word[i];
    }

    return 0;
}