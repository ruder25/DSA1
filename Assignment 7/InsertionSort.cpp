#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 5;
    int arr[5] = {24,67,23,87,43};

    for (int i = 0; i < n; i++)
    {
        int j = i;

        while (j > 0 && arr[j - 1] > arr[j])
        {
            int temp = arr[j - 1];
            arr[j - 1] = arr[j];
            arr[j] = temp;

            j--;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}