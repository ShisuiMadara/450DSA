#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD= 1000000007;



void solve()
{
        
    class myStack {
        struct Node {
            int num;
            Node* next;
            Node* prev;
    
            Node(int num) { this->num = num; }
        };
    
        // Members of stack
        Node* head = NULL;
        Node* mid = NULL;
        int size = 0;
    
    public:
        void push(int data)
        {
            Node* temp = new Node(data);
            if (size == 0) {
                head = temp;
                mid = temp;
                size++;
                return;
            }
    
            head->next = temp;
            temp->prev = head;
    
            // update the pointers
            head = head->next;
            if (size % 2 == 1) {
                mid = mid->next;
            }
            size++;
        }
    
        int pop()
        {
        int data=-1;
            if (size != 0) {
            data=head->num;
                if (size == 1) {
                    head = NULL;
                    mid = NULL;
                }
                else {
                    head = head->prev;
                    head->next = NULL;
                    if (size % 2 == 0) {
                        mid = mid->prev;
                    }
                }
                size--;
            }
        return data;
        }
    
        int findMiddle()
        {
            if (size == 0) {
                return -1;
            }
            return mid->num;
        }
    
        void deleteMiddle()
        {
            if (size != 0) {
                if (size == 1) {
                    head = NULL;
                    mid = NULL;
                }
                else if (size == 2) {
                    head = head->prev;
                    mid = mid->prev;
                    head->next = NULL;
                }
                else {
                    mid->next->prev = mid->prev;
                    mid->prev->next = mid->next;
                    if (size % 2 == 0) {
                        mid = mid->prev;
                    }
                    else {
                        mid = mid->next;
                    }
                }
                size--;
            }
        }
    };
}


int main() 
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

     ll test=1;
cin>>test;
    while(test--)
    {
        
        solve();
    }
    return 0;
}