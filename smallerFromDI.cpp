class Solution {
public:
    void f(int i,int y,vector<bool>& vis,string& pattern,string& s) {
        if (i==s.size()) return;
        if (pattern[i]=='I') {
            for (int j=y+1;j<10;j++) {
                if (!vis[j]) {
                    vis[j]=true;
                    s+=('0'+j);
                    f(i+1,j,vis,pattern,s);
                }
            }
            if (s.size()==pattern.size()+1) return;
            vis[y]=false;
            s.pop_back();
        }
        else {
            for (int j=1;j<y;j++) {
                if (!vis[j]) {
                    vis[j]=true;
                    s+=('0'+j);
                    f(i+1,j,vis,pattern,s);
                }
            }
            if (s.size()==pattern.size()+1) return;
            vis[y]=false;
            s.pop_back();
        }
    }
    string smallestNumber(string pattern) {
        for (int i=1;i<10;i++) {
            string s=to_string(i);
            vector<bool> vis(10,false);
            vis[i]=true;
            f(0,i,vis,pattern,s);
            if (s.size()==pattern.size()+1) return s;
        }
        return "";
    }
};