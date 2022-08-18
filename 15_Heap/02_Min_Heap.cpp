#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class MinHeap
{

    int *arr;
    int size;

public:
    MinHeap(int s)
    {
        this->arr = new int[s];
        size = 0;
    }

    void insert(int val)
    {
        if (size == 0)
            arr[size++] = val;

        else
        {
            int index = size++;
            arr[index] = val;

            while (index > 0)
            {
                int parent = (index - 1) / 2;
                if (arr[index] < arr[parent])
                {
                    swap(arr[index], arr[parent]);
                    index = parent;
                }
                else
                    break;
            }
        }
    }

    void deletion()
    {
        if (size == 0)
        {
            cout << "Nothing TO Delete ." << endl;
            return;
        }
        arr[0] = arr[size - 1];
        size--;
        int i = 0;

        while (i < size)
        {
            int leftindex = 2 * i + 1;
            int rightindex = 2 * i + 2;

            if (leftindex <= size && arr[i] > arr[leftindex])
            {
                swap(arr[i], arr[leftindex]);
                i = leftindex;
            }
            else if (rightindex <= size && arr[rightindex] < arr[i])
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
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

void heapify(int arr[], int n, int i)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = left + 1;

    if (left < n && arr[smallest] > arr[left])
    {
        smallest = left;
    }
    if (right < n && arr[smallest] > arr[right])
    {
        smallest = right;
    }
    if (smallest != i)
    {
        swap(arr[smallest], arr[i]);
        heapify(arr, n, smallest);
    }
}

int main()

{
    MinHeap h(10);

    h.insert(50);
    h.print();
    h.insert(55);
    h.print();
    h.insert(49);
    h.print();
    h.insert(52);
    h.print();
    h.insert(54);
    h.print();

    h.deletion();
    h.print();

    cout<<h[h.size()/2];

    int arr[6] = {100, 50, 55, 60, 24, 85};

    int n = (sizeof(arr)) / sizeof(int);
    cout << n << endl;
    for (int i = (n / 2) - 1 ; i >= 0; i--)
    {
        heapify(arr, n, i);
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}