#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> NextSmallerElement(stack<int> &store, vector<int> &input, vector<int> &output)
{
    for (int i = input.size() - 1; i >= 0; i--)
    {
        while (store.top() >= input.at(i))
        {
            store.pop();
        }
       
        output.push_back(store.top());
        store.push(input.at(i));
    }
    return output;
}

int main()
{
    stack<int> store;
    store.push(-1);
    int n;
    cout << "Enter The Number Of elements : ";
    cin >> n;
    vector<int> input, output;
    int x;

    for (int i = 0; i < n; i++)
    {
        cin >> x;
        input.push_back(x);
    }

    output = NextSmallerElement(store, input, output);

    cout << "Input Elements : ";
    for (int i = 0; i < n; i++)
    {
        cout << input.at(i) << " ";
    }

    cout << "\nTheir Next Smaller Elements : ";
    for (int i = output.size() - 1; i >= 0; i--)
    {
        cout << output.at(i) << " ";
    }

    return 0;
}