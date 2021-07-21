#include <bits/stdc++.h>
using namespace std;

int ans = 0;
long long int count(int n)
{
    if (n == 0)
        return 1;
    if (n < 0)
        return 0;

    return count(n) + count(n - 3) + count(n - 5) + count(n - 10);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        long long int ans = count(n);
        cout << ans << endl;
    }
    return 0;
}