// To Find Pivot In numsay which shows
//  suppose nums = 6 7 1 2 3
// Pivot  = 2 ;

#include <iostream>
using namespace std;

int PivotIndexOfSmallest(int nums[], int n)
{

    int start = 0, end = n - 1;
    int mid = start + (end - start) / 2;
    while (start < end)
    {
        if (nums[mid] >= nums[0] && nums[end] < nums[0])
            start = mid;
        else
            end = mid;
        mid = start + (end - start) / 2;
    }
    cout<<"Returned "<<start<<endl;
    return start;
}

int PivotIndexOfLargest(int nums[], int n)
{

    int start = 0, end = n - 1;
    int mid = start + (end - start) / 2;
    while (start < end)
    {
        if (nums[mid] > nums[0] && nums[n - 1] < nums[0])
            start = mid;
        else
            end = mid-1;
        cout << mid << " ";
        mid = start + (end - start) / 2;
    }
    return start;
}

int main()
{
    int n;
    cout << "Enter The Size OF numsay : ";
    cin >> n;
    int nums[n];
    cout << "Enter The Elements : ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    cout << "The Pivot is : " << PivotIndexOfSmallest(nums, n);
    return 0;
}