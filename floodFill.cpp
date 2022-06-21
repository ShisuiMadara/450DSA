class Solution {
public:
    
    void recursion(vector<vector<int>>&image, int sr, int sc, int color, int realColor)
    {
        int n = image.size();
        int m = image[0].size();
        
        image[sr][sc] = color;
        
        int di[4] = {1,0,-1,0};
        int dj[4] = {0,1,0, -1};
        //down, right, up, left
        
        for(int i = 0; i< 4; ++i)
        {
            if(sr + di[i] < n && sr + di[i] >= 0 && sc + dj[i] < m && sc + dj[i] >=0)
            {
                if(image[sr + di[i]][sc+dj[i]] == realColor)
                {
                    image[sr + di[i]][sc+dj[i]] = color;
                    recursion(image, sr+di[i], sc+dj[i], color, realColor);
                }
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(color == image[sr][sc])return image;
        recursion(image, sr, sc, color, image[sr][sc]);
        
        return image;
    }
};