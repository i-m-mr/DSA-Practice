#include <bits/stdc++.h>
using namespace std;

long long int nPr(int n, int r)
{
    if (r > n)
        return 0;
    if (r == 0)
        return 1;

    return r * nPr(n - 1, r - 1) + nPr(n - 1, r);
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