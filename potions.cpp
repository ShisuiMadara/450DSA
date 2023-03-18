#include <bits/stdc++.h>
using namespace std;

int main(){

	int n; 
    cin >> n;

	priority_queue<long long, vector<long long>, greater<long long> > pq;

	long long S = 0;
	
	for(int i = 1;i <= n;i++){
		long long x; 
        cin >> x;

		S += x;
		pq.push(x);
		
		while(S < 0){
			S -= pq.top();
            // cout<<pq.top()<<endl;
			pq.pop();
		}
	}
	long long ans = pq.size();
	cout << ans;
}