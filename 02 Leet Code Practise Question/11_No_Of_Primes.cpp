// #include <iostream>
// #include <vector>
// using namespace std;

// vector<bool> isPrime(vector<bool> prime, int n)
// {
//     for (int i = 2; i * n < prime.size(); i++)
//     {
//         prime[i * n] = false;
//     }
//     return prime;
// }

// int CountPrimes(int n)
// {
//     int count = 0;
//     vector<bool> prime(n, true);
//     prime[0] = prime[1] = false;
//     for (int i = 2; i < n; i++)
//     {
//         if (prime[i])
//         {
//             count++;
//             prime = isPrime(prime, i);
//         }
//     }
//     return count;
// }

// int main()
// {
//     int n;
//     cout << "Enter The Number : ";
//     cin >> n;
//     cout<<CountPrimes(n);
//     return 0;
// }

#include <iostream>
#include <vector>
using namespace std;

int CountPrimes(int n)
{
    int count = 0;
    vector<bool> prime(n, true);
    prime[0] = prime[1] = false;
    for (int i = 2; i < n; i++)
    {
        if (prime[i])
        {
            count++;
            for(int j = 2*i ; j<n ; j = j + i  )
            {
                prime[j] = false;
            }
        }
    }
    return count;
}

int main()
{
    int n;
    cout << "Enter The Number : ";
    cin >> n;
    
    cout<<CountPrimes(n);
    return 0;
}