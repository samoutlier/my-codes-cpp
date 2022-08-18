#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class MaxHeap
{

    int arr[1025];
    int size;

public:
    MaxHeap()
    {
        size = 0;
        arr[0] = -1;
    }

    void insert(int val)
    {
        size++;
        int index = size;
        arr[index] = val;

        while (index > 1)
        {
            int parent = index / 2;
            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
                break;
        }
    }

    void deletion()
    {
        if (size == 0)
        {
            cout << "Nothing TO Delete ." << endl;
            return;
        }
        arr[0] = arr[size-1];
        size--;
        int i = 0;

        while (i <= size)
        {
            int leftindex = 2 * i;
            int rightindex = 2 * i + 1;

            if (leftindex <= size && arr[i] < arr[leftindex])
            {
                swap(arr[i], arr[leftindex]);
                i = leftindex;
            }
            else if (rightindex <= size && arr[rightindex] > arr[i])
            {
                swap(arr[i], arr[rightindex]);
                i = rightindex;
            }
            else
                break;
        }
    }

    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i;
    int right = left + 1;

    if (left <= n && arr[largest] < arr[left])
    {
        largest = left;
    }
    if (right <= n && arr[largest] < arr[right])
    {
        largest = right;
    }
    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

int main()

{
    MaxHeap h;
    

    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();

    h.deletion();
    h.print();

    int arr[6] =  {-1, 50 , 55 , 60 , 24 , 85};
    // int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = (sizeof(arr)) / sizeof(int) - 1;
    cout << n << endl;
    for (int i = n / 2; i > 0; i--)
    {
        heapify(arr, n, i);
    }

    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}