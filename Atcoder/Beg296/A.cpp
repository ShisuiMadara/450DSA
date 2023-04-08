#include<bits/stdc++.h>
using namespace std;

string solve(int n, vector<int> speeds) {
    if (n < 3) {
        return "YES"; 
    }
    vector<int> prev_speeds = {-1, -1}; 
    for (int i = 0; i < n; i++) {
        vector<int> valid_speeds;
        for (int j = 0; j < 10; j++) {
            if (speeds[j] == 1 && j != prev_speeds.back()) {
                valid_speeds.push_back(j+1);
            }
        }
     

        if (valid_speeds.empty()) {
            return "NO"; 
        }

        int chosen_speed = *min_element(valid_speeds.begin(), valid_speeds.end(),
                                        [&](int a, int b) {
                                            return (a + prev_speeds.back()) - (prev_speeds[0] + prev_speeds[1]) <
                                                   (b + prev_speeds.back()) - (prev_speeds[0] + prev_speeds[1]);
                                        });

        prev_speeds.erase(prev_speeds.begin());
        prev_speeds.push_back(chosen_speed);
    }
    return "YES";
}

int main() {
    int n ;

    cin>>n;

    vector<int> speeds (10);

    for(auto&c:speeds){
        cin>>c;
    }

    string result = solve(n, speeds);
    cout << result << endl; 
    return 0;
}