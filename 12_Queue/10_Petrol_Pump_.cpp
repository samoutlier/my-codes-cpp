#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

struct petrolPump
{
    int distance, petrol;
};

int Tour(struct petrolPump *&p, int n)
{

    int balance = 0, start = 0, deficit = 0;
    for (int i = 0; i < n; i++)
    {
        balance += (p[i].petrol) - p[i].distance;
        if (balance < 0)
        {
            deficit += balance;
            start = i + 1;
            balance = 0;
        }
    }
    if (balance + deficit >= 0)
        return start;
    else
        return -1;
}

int main()
{
    int n;
    cout << "Enter Number Of Petrol Pumps : ";
    cin >> n;

    struct petrolPump *p = new struct petrolPump[n];
    // struct petrolPump p[n];

    cout << "Enter Petrol of each Pump : ";
    for (int i = 0; i < n; i++)
    {
        cin >> p[i].petrol;
    }

    cout << "Enter Distance of next Pump for current pump: ";
    for (int i = 0; i < n; i++)
    {
        cin >> p[i].distance;
    }

    cout << "Position of petrol Pump to start : " << Tour(p, n);

    return 0;
}
// 6 7 4 10 6 5
// 5 6 7 8 6 4