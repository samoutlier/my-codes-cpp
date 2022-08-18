#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int CelebrityIndex(vector<vector<int>> input, int n)
{
    stack<int> store;
    for (int i = 0; i < n ; i++)
    {
        store.push(i);
    }

    while (store.size() > 1)
    {
        int person1 = store.top();
        store.pop();
        int person2 = store.top();
        store.pop();
        if (input[person1][person2] )
        {
            store.push(person2);
        }
        else if(input[person2][person1])
        {
            store.push(person1);
        }
        
    }

    if(store.empty())
    return -1;
    else
    {
        //checking whether The Left person doesnt know anyone  
        for (int i = 0; i < n; i++)
        {
            if(input[store.top()][i] && store.top()!=i )
            {
                return -1;
            }
        }
         
         //checking whether everyone knows the Left person 
        for (int i = 0; i < n; i++)
        {
            if(!input[i][store.top()] && store.top()!=i )
            {
                return -1;
            }
        }
      return store.top();
    }
    
    
}

int main()
{
    vector<vector<int>> input;
    int n, xyz;
    cout << "Enter The Number Of People In Room : ";
    cin >> n;
    cout << "Enter The detail : " << endl;

    for (int i = 0; i < n; i++)
    {
        vector<int> temp;
        for (int j = 0; j < n; j++)
        {
            cin >> xyz;
            temp.push_back(xyz);
        }
        input.push_back(temp);
    }

    cout << "Index of Celebrity : " << CelebrityIndex(input, n);
    return 0;
}