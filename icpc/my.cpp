#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;

int min_val[4*MAXN], second_min_val[4*MAXN];

void buildTree(int arr[], int v, int tl, int tr) {
    if (tl == tr) {
        min_val[v] = arr[tl];
        second_min_val[v] = INT_MAX;
    } else {
        int tm = (tl + tr) / 2;
        buildTree(arr, 2*v, tl, tm);
        buildTree(arr, 2*v+1, tm+1, tr);
        min_val[v] = min(min_val[2*v], min_val[2*v+1]);
        second_min_val[v] = min(max(min_val[2*v], min_val[2*v+1]), 
                                min(second_min_val[2*v], second_min_val[2*v+1]));
    }
}

pair<int, int> query(int v, int tl, int tr, int l, int r) {
    if (l > r) {
        return {INT_MAX, INT_MAX};
    }
    if (l == tl && r == tr) {
        return {min_val[v], second_min_val[v]};
    }
    int tm = (tl + tr) / 2;
    pair<int, int> left_node = query(2*v, tl, tm, l, min(r, tm));
    pair<int, int> right_node = query(2*v+1, tm+1, tr, max(l, tm+1), r);
    int merged_min_val = min(left_node.first, right_node.first);
    int merged_second_min_val = min(max(left_node.first, right_node.first), 
                                    min(left_node.second, right_node.second));
    return {merged_min_val, merged_second_min_val};
}

int solve(int A[], int n) {
    int sum = 0;
    buildTree(A, 1, 0, n-1);
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            pair<int, int> query_pair = query(1, 0, n-1, i, j);
            sum += query_pair.first ^ query_pair.second;
        }
    }
    return sum;
}

int main() {

    int t;
    cin>>t;

    while(t--) {
        int n;
        cin>>n;

        int A[n];

        for(int i = 0; i<n; ++i) {
            cin>>A[i];
        }

        cout<<solve(A,n)<<endl;
    }
  
}
