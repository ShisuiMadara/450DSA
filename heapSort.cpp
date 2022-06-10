#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD= 1000000007;

void heapify (int arr [], int index, int n)
{
    int larger = index;

    int left = 2*index + 1;
    int right = 2*index + 2;

    if(left < n && arr[left] > arr[larger])
    {
        larger = left;
    }
    
    if(right < n && arr[right] > arr[larger])
    {
        larger = right;
    }

    if(larger != index)
    {
        swap(arr[larger], arr[index]);
        //cout<<"HI";
        heapify(arr, larger, n);
    }
}

void make_max_heap(int arr [] , int n)
{
    for(int i = n/2 - 1; i >= 0; i--)
    {
        heapify(arr, i, n);
    }
}

void heap_sort(int arr [], int n)
{
    make_max_heap(arr, n);

    for(int i = n-1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, 0,i);
    }
}

void solve()
{
    int arr [6] = {10,9,8,7,6,5};

    heap_sort(arr, 6);

    for(int i = 0; i< 6; ++i)
    {
        cout<<arr[i]<<" ";
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
