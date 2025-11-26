#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 5;
    int arr[5] = {34,67,34,63,23};

    int max;
    int Swap = 0;

    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j <= n - i; j++)
        {

            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                Swap = 1;
            }
        }
        if (Swap == 0)
        {
            cout << "the array is  sorted!";
            break;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " " << endl;
    }
    return 0;
}