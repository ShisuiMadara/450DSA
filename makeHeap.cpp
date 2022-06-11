#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD= 1000000007;

void heapify(int arr[], int i, int n)
{
	int largest = i; 
	int l = 2 * i + 1; 
	int r = 2 * i + 2; 

	if (l < n && arr[l] > arr[largest])
		largest = l;

	if (r < n && arr[r] > arr[largest])
		largest = r;

	if (largest != i) {
		swap(arr[i], arr[largest]);
        //cout<<"HERE ";
		heapify(arr, largest, n);
	}
}

void make_max_heap(int arr [], int n)
{
    for(int i = n/2 -1; i>=0; i--)
    {
        heapify(arr,i, n);
    }
}

void solve()
{
    int arr [6] = {5,6,7,8,9,10};

    make_max_heap (arr, 6);

    for(int i = 0; i< 6; ++i)
    {
        cout<<arr[i]<<" ";
    }
}



int main() 
{ 
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif

     ll test=1;
//cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
