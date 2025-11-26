#include <iostream>
using namespace std;

int main()
{
    int n = 5;
    int arr[5] = {22, 67, 24, 43, 23};

    int min;

    for (int i = 0; i <= n - 2; i++)
    {

        min = i;
        for (int j = i; j <= n - 1; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}