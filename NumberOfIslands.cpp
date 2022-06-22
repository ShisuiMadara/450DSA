// { Driver Code Starts
// Initial Template for C

// Program to count islands in boolean 2D matrix
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define COL 501


 // } Driver Code Ends
// User function Template for C

void recursion(int i, int j,int M[][COL], int n, int m, int visited[][COL])
{
    if(i >= n || i<0 || j >= m || j<0)
    {
        
        return;
    }
    if(M[i][j] == 0 || visited[i][j])
    {
        
        return;
    }
    visited[i][j] = 1;
    
   
    
    recursion(i+1, j, M, n,m,visited);
    recursion(i+1, j+1, M, n,m,visited);
    recursion(i, j+1, M, n,m,visited);
    recursion(i-1, j, M, n,m,visited);
    recursion(i, j-1, M, n,m,visited);
    recursion(i-1, j-1, M, n,m,visited);
    recursion(i+1, j-1, M, n,m,visited);
    recursion(i-1, j+1, M, n,m,visited);
    
}

int countIslands(int M[][COL], int n, int m) {
    // your code goes here
    
    int ans = 0;
    
    int visited[COL][COL];
    
    memset(visited, 0, sizeof(visited));
    
    for(int i = 0; i< n; ++i)
    {
        for(int j = 0; j< m; ++j)
        {
            if(M[i][j] == 1 && !visited[i][j])
            {
                
                recursion(i,j, M, n,m,visited);
                ans++;
            }
        }
    }
    
    return ans;
}


// { Driver Code Starts.

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {

        int n, m;
        scanf("%d %d", &n, &m);

        int M[n][COL];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d", &M[i][j]);
            }
        }

        int ans = countIslands(M, n, m);
        printf("%d\n", ans);
    }

    return 0;
}
  // } Driver Code Ends