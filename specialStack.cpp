// { Driver Code Starts
#include<iostream>
#include<stack>
using namespace std;
void push(stack<int>& s,int a);
bool isFull(stack<int>& s,int n);
bool isEmpty(stack<int>& s);
int pop(stack<int>& s);
int getMin(stack<int>& s);
//This is the STL stack (http://quiz.geeksforgeeks.org/stack-container-adaptors-the-c-standard-template-library-stl/).
stack<int> s;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,a;
		cin>>n;
		while(!isEmpty(s)){
		    pop(s);
		}
		while(!isFull(s,n)){
			cin>>a;
			push(s,a);
		}
		cout<<getMin(s)<<endl;
	}
}// } Driver Code Ends


int minele = -1 ;

void push(stack<int>& s, int a)
{
	if(s.empty())
	{
	    s.push(a);
	    minele = a;
	}
	else if(a <= minele)
	{
	    int x = 2*a - minele;
	    minele = a ;
	    s.push(x);
	    
	}
	else
	    s.push(a);
}

bool isFull(stack<int>& s,int n){
	// Your code goes here
	return s.size()==n;
}

bool isEmpty(stack<int>& s){
	// Your code goes here
	return s.empty();
}

int pop(stack<int>& s){
	// Your code goes here
	int t = s.top();
	s.pop();
	if(t<=minele)
	{
	    int x = minele;
	    minele = 2 * minele - t;
	    return x;
	}
	else
	    return t;
}

int getMin(stack<int>& s){
	// Your code goes here
	return minele;
}