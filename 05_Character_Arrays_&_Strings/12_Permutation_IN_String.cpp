// #include <iostream>
// using namespace std;

// bool CountCheck(int count1[], int count2[])
// {
//     for (int i = 0; i < 26; i++)
//     {
//         if (count1[i] != count2[i])
//             return false;
//     }
//     return true;
// }

// bool Permutation(string str, string sub)
// {
//     int count1[26] = {0};

//     char ch;
//     int num;
//     for (int i = 0; i < sub.length(); i++)
//     {
//         ch = sub[i];
//         if (ch >= 'a' && ch <= 'z')
//         {
//             num = ch - 'a';
//         }
//         else if (ch >= 'A' && ch <= 'Z')
//         {
//             num = ch - 'A';
//         }
//         count1[num]++;
//     }
//     for (int i = 0; i < str.length() - sub.length(); i++)
//     {
//         int count2[26] = {0};
//         for (int j = i; j < sub.length(); j++)
//         {
//             ch = str[j];
//             if (ch >= 'a' && ch <= 'z')
//             {
//                 num = ch - 'a';
//             }
//             else if (ch >= 'A' && ch <= 'Z')
//             {
//                 num = ch - 'A';
//             }
//             count2[num]++;
//         }
//         if (CountCheck(count1, count2))
//             return true;
//     }
//     return false;
// }

// int main()
// {
//     string str, sub;
//     cout << "Enter The String : ";
//     cin >> str;
//     cout << "Enter The Sub String : ";
//     cin >> sub;
//     cout << "Permutation Of Substring present in string or not  : " << Permutation(str, sub) << endl;
//     return 0;
// }

#include <iostream>
using namespace std;

bool CountCheck(int count1[], int count2[])
{
    for (int i = 0; i < 26; i++)
    {
        if (count1[i] != count2[i])
            return false;
    }
    return true;
}

bool Permutation(string str, string sub)
{
    if (str.length() < sub.length())
    {
        return 0;
    }

    int count1[26] = {0};

    char ch;
    int num;
    for (int i = 0; i < sub.length(); i++)
    {
        ch = sub[i];
        num = ch - 'a';
        count1[num]++;
    }

    int windowSize = sub.length();
    int count2[26] = {0}, j = 0;

    while (j < windowSize)
    {
        int index = str[j] - 'a';
        count2[index]++;
        j++;
    }
    if (CountCheck(count1, count2))
        return 1;

    while (j < str.length())
    {
        char NewChar = str[j];
        int index = str[j] - 'a';
        count2[index]++;

        char OldChar = str[j - windowSize];
        index = OldChar - 'a';
        count2[index]--;

        j++;

        if (CountCheck(count1, count2))
            return 1;
    }
    return 0;

    return false;
}

int main()
{
    string str, sub;
    cout << "Enter The String : ";
    cin >> str;
    cout << "Enter The Sub String : ";
    cin >> sub;
    cout << "Permutation Of Substring present in string or not  : " << Permutation(str, sub) << endl;
    return 0;
}