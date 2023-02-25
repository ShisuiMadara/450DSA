#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, k;
ll a[100000], b[100000];
bool check(ll x)
{
    ll temp = k;
    for (ll i = 0; i < n; i++)
    {
        ll z = (long long) a[i] * x;
        if (z > b[i])
        {
            temp -= (z - b[i]);
        }
        if (temp < 0)
        {
            return false;
        }
    }
    return true;
}
 
void solve()
{
 
    cin >> n >> k;
 
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (ll i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    ll low = 1;
    ll high = 2e9 + 1;
    ll ans = 0;
    while (low <= high)
    {
        ll mid = (high + low) / 2;
        if (check(mid))
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    cout << ans << endl;
}

int main() {
    solve();
}