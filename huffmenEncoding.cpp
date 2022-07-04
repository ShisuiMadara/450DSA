// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class node 
{
    public:
        int data;
        node *left, *right;
        
        node(int x)
        {
            this -> data = x;
            this -> left = NULL;
            this -> right = NULL;
        }
};

struct cmp{
    bool operator()(node *l, node *r)
    {
        return (l -> data > r -> data);
    }
};

class Solution
{
	public:
	    
	    void preorder (node *root, string s, vector<string>&ans)
	    {
	        if(root == NULL)return;
	        
	        if(root->left == NULL && root->right == NULL)
	        {
	            ans.push_back(s); //leaf node
	        }
	        
	        preorder(root->left, s+'0', ans);
	        preorder(root->right, s+'1', ans);
	    }
	    
		vector<string> huffmanCodes(string S,vector<int> f,int N)
		{
		    vector<string>ans;
		    
		    priority_queue<node *, vector<node*>, cmp>pq;
		    
		    for(int i = 0; i< N; ++i)
		    {
		        node *root = new node(f[i]);
		        pq.push(root);
		    }
		    
		    while(pq.size() != 1)
		    {
		        node* left = pq.top();
		        pq.pop();
		        
		        node* right = pq.top();
		        pq.pop();
		        
		        node *parent = new node(left->data + right->data);
		        
		        parent ->left = left;
		        parent -> right = right;
		        
		        pq.push(parent);
		        
		    }
		    
		    node *root = pq.top();
		    
		    preorder(root, "", ans);
		    
		    return ans;
		}
};

// { Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
	    string S;
	    cin >> S;
	    int N = S.length();
	    vector<int> f(N);
	    for(int i=0;i<N;i++){
	        cin>>f[i];
	    }
	    Solution ob;
	    vector<string> ans = ob.huffmanCodes(S,f,N);
	    for(auto i: ans)
	    	cout << i << " ";
	    cout << "\n";
    }
	return 0;
}  // } Driver Code Ends