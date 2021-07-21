#include <bits/stdc++.h>
using namespace std;

long long int nPr(int n, int r)
{
    if (r > n)
    {
        return 0;
    }
    long long int ans = 1;
    for (int i = n; i > n - r; i--)
    {
        ans *= i;
    }

    return ans;
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