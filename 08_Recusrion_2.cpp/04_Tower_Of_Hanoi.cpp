#include <iostream>
#include <vector>
using namespace std;
void Solution(int n, char from_rod, char to_rod, char aux_rod)
{
    if (n == 0)
    {
        return;
    }

    Solution(n - 1, from_rod, aux_rod , to_rod);
    cout << "Move Disk " << n << " from rod " << from_rod << " to rod " << to_rod << endl;
    Solution(n - 1, aux_rod, to_rod, from_rod);
}

int main()
{
    int n;
    cout << "Enter The Number Of Disks : ";
    cin >> n;
    Solution(n, 'A', 'C', 'B');
    return 0;
}