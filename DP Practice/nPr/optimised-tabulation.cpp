#include <bits/stdc++.h>
using namespace std;

long long int nPr(int n, int r)
{
    if (r > n)
        return 0;

    long long int fact[n + 1];
    fact[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        fact[i] = i * fact[i - 1];
    }

    return fact[n] / fact[n - r];
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, r;
        cin >> n >> r;

        long long int ans = nPr(n, r);
        cout << "Ans : " << ans << endl;
    }
    return 0;
}