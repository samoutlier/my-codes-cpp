#include <iostream>
#include <vector>
using namespace std;

void PrintVector(vector<int> v)
{

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

vector<int> MergeSort(vector<int> v1, vector<int> v2, int n, int m)
{
    vector<int> ans;
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (v1[i] <= v2[j])
            ans.push_back(v1[i++]);
        else
            ans.push_back(v2[j++]);
    }

    while (i < n)
        ans.push_back(v1[i++]);

    while (j < m)
        ans.push_back(v2[j++]);

    return ans;
}

int main()
{
    int n, m;
    cout << "Enter The sizes Of two arrays : ";
    cin >> n >> m;
    vector<int> vec1, vec2;

    cout << "Enter The Elements OF First array : ";
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        vec1.push_back(temp);
    }cout<<endl;
    cout << "Enter The Elements OF Second array : ";
    for (int i = 0; i < m; i++)
    {
        int temp;
        cin >> temp;
        vec2.push_back(temp);
    }cout<<endl;
    
    PrintVector(vec1);
    PrintVector(vec2);
    vector<int> ans = MergeSort(vec1, vec2, n, m);
    PrintVector(ans);

    return 0;
}