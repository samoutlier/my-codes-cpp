#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

int main()
{
    // MAx Heap
    priority_queue<int> pq;

    pq.push(1);
    pq.push(4);
    pq.push(2);
    pq.push(3);
    pq.push(5);

    cout << "Top Element in Heap is : " << pq.top() << endl;
    pq.pop();
    cout << "Top Element in Heap after popping is : " << pq.top() << endl;
    cout << "Size is : " << pq.size() << endl;

    if (pq.empty())
        cout << "Priority Queue is Empty ." << endl;
    else
        cout << "Priority Queue is NOT Empty ." << endl;

    // Min Heap

    priority_queue<int, vector<int>, greater<int>> min;

    min.push(4);
    min.push(1);
    min.push(2);
    min.push(5);
    min.push(3);

    cout<<min[min.size()/2]<<endl;

    cout << endl
         << "Top Element in Heap is : " << min.top() << endl;
    min.pop();
    cout << "Top Element in Heap after popping is : " << min.top() << endl;
    cout << "Size is : " << min.size() << endl;

    if (min.empty())
        cout << "Min heap Queue is Empty ." << endl;
    else
        cout << "Min heap Queue is NOT Empty ." << endl;

    return 0;
}