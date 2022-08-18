#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    vector<int> v;
    // To Use Binary Search vector should be sorted
    v.push_back(-9);
    v.push_back(0);
    v.push_back(2);
    v.push_back(8);
    v.push_back(15);
    v.push_back(19);
    v.push_back(34);
    v.push_back(82);

    int find = 34;
    // Binary Search
    cout << "Finding " << find << " : " << binary_search(v.begin(), v.end(), find) << endl;

    // Lower aur upper bound
    cout << "Lower Bound : " << lower_bound(v.begin(), v.end(), 82) - v.begin() << endl;
    cout << "Upper Bound : " << upper_bound(v.begin(), v.end(), 82) - v.begin() << endl;

    // Maximum and Minimum Function
    int a = 6;
    int b = 9;
    cout << "Max : " << max(a, b) << endl;
    cout << "Min : " << min(a, b) << endl;

    // Reverse string

    string s = "Khwaja";

    reverse(s.begin(), s.end());
    cout << "String : " << s << endl;

    // Rotate Any Vector Array etc

    rotate(v.begin(), v.begin() + 3, v.end());

    cout << "After Rotate : ";
    for (int i : v)
    {
        cout << i << " ";
    }
    cout << endl;

    sort(v.begin(), v.end());
    cout << "After SOrting : ";
    for (int i : v)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}