vector<int> Solution::solve(int A, int B, int C, int D) {

    int ar[] = {0, 0, 0};

    vector<int> v;

    v.push_back(1);

    for(int i = 0; i < D; ++i){

        int m = min( v[ar[0]] * A, min( v[ar[1]] * B , v[ar[2]] * C) );

        v.push_back(m);

        if(m == v[ar[0]] * A)

            ar[0]++;

        if(m == v[ar[1]] * B)

            ar[1]++;

        if(m == v[ar[2]] * C)

            ar[2]++;

    }

    v.erase(v.begin());

    return v;

}
