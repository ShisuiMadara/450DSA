#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD= 1000000007;
const int SIZE = 1000000;

vector<int>parent(SIZE);
vector<int>rnk(SIZE);
vector<int>score(SIZE);




int find_set(int a)
{
    if(parent[a] == a)
    {
        return a;
    }

    return parent[a] = find_set(parent[a]);
}

void dfsADD(int a, int b, int n)
{
    for(int i =1; i<=n; ++i)
    {
        if(find_set(i) == a)
        {
            score[i] += b;
        }
    }    
}


void union_set(int a, int b)
{
    a = find_set(a);
    b = find_set(b);

    if(a != b)
    {
        if(rnk[a] < rnk[b])
        {
            swap(a,b);
        }

        parent[b] = a;

        if(rnk[a] == rnk[b])
        {
            rnk[a] ++;
        }
    }
    
}



void solve()
{
    int n, q;
    cin>>n>>q;

    for(int i =0 ;i<=n; ++i)
    {
        parent[i] = i;
        rnk[i] = 0;
        score[i] = 0;
    }

    while(q--)
    {
        string s;
        cin>>s;

        if(s == "join")
        {
            int a, b;
            cin>>a>>b;

            union_set(a, b);
        }
        else if(s == "add")
        {
            int a,b;
            cin>>a>>b;

            a = find_set(a);

            dfsADD(a,b,n);
        }
        else
        {
            int a;
            cin>>a;

            cout<<score[a]<<'\n';
        }
    }
}



int main() 
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);


     ll test=1;
//cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
