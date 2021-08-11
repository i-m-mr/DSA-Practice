#include <bits/stdc++.h>
using namespace std;

void rotate(int arr[], int n, int k)
{
    reverse(arr, arr + n - k);
    reverse(arr + n - k, arr + n);
    reverse(arr, arr + n);
}

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    rotate(arr, n, k);
    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= 10)
        {
            cout << arr[i] % 10 << " ";
        }
        else
        {
            cout << 10 - arr[i] << " ";
        }
    }

    return 0;
}