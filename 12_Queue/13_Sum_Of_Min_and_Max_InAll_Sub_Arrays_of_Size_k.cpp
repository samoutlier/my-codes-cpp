#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

int Solution(int *arr, int k, int n)
{
    deque<int> q, qmin, qmax;
    int sum = 0;

    // qmin.push_front(arr[0]);
    // qmax.push_front(arr[0]);

    // Addition Of First k sized window

    for (int i = 0; i < k; i++)
    {
        while (!qmax.empty() && arr[i] >= arr[qmax.back()])
        {
            qmax.pop_back();
        }
        while (!qmin.empty() && arr[i] <= arr[qmin.back()])
        {
            qmin.pop_back();
        }

        qmax.push_back(i);
        qmin.push_back(i);
    }

    // Storing Sum For first k sized window
    sum += arr[qmin.front()] + arr[qmax.front()];

    cout << qmin.front() << endl;
    cout << qmax.front() << endl;

    for (int i = k; i < n; i++)
    {

        // Removal Of That Max/Min whick doesnt belong to window
        while (!qmax.empty() && i - qmax.front() >= k)
            qmax.pop_front();
        while (!qmin.empty() && i - qmin.front() >= k)
            qmin.pop_front();

        // Addition of next Max/Min for next window

        while (!qmax.empty() && arr[i] >= arr[qmax.back()])
        {
            qmax.pop_back();
        }
        while (!qmin.empty() && arr[i] <= arr[qmin.back()])
        {
            qmin.pop_back();
        }

        qmax.push_back(i);
        qmin.push_back(i);

        cout << qmin.front() << endl;
        cout << qmax.front() << endl;

        // Storing Sum
        sum += arr[qmin.front()] + arr[qmax.front()];
    }

    return sum;
}

int main()
{
    int n, *arr, k;
    cout << "Enter The Number Of elements : ";
    cin >> n;

    arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter The size of Window : ";
    cin >> k;

    cout << Solution(arr, k, n);

    return 0;
}