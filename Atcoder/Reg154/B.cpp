#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#pragma GCC target("popcnt")
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
using namespace std;
//const double pi = acos(-1);
// DEBUG FUNCTIONS 
#ifndef ONLINE_JUDGE
template<typename T>
void __p(T a) {
cout<<a;
}
template<typename T, typename F>
void __p(pair<T, F> a) {
cout<<"{";
p(a.first);
cout<<",";
p(a.second);
cout<<"}";
}
template<typename T>
void __p(std::vector<T> a) {
cout<<"{";
for(auto it=a.begin(); it<a.end(); it++)
__p(*it),cout<<",}"[it+1==a.end()];
}
template<typename T>
void __p(std::set<T> a) {
cout<<"{";
for(auto it=a.begin(); it!=a.end();){
__p(*it); 
cout<<",}"[++it==a.end()];
}
}
template<typename T>
void __p(std::multiset<T> a) {
cout<<"{";
for(auto it=a.begin(); it!=a.end();){
__p(*it); 
cout<<",}"[++it==a.end()];
}
}
template<typename T>
void __p(ordered_set<T> a) {
cout<<"{";
for(auto it=a.begin(); it!=a.end();){
__p(*it); 
cout<<",}"[++it==a.end()];
}
}
template<typename T>
void __p(ordered_multiset<T> a) {
cout<<"{";
for(auto it=a.begin(); it!=a.end();){
__p(*it); 
cout<<",}"[++it==a.end()];
}
}
template<typename T, typename F>
void __p(std::map<T,F> a) {
cout<<"{";
for(auto it=a.begin(); it!=a.end();++it)
{
__p(it->first);
cout << ": ";
__p(it->second);
cout<<"";
}
cout << "}";
}
template<typename T, typename ...Arg>
void __p(T a1, Arg ...a) {
__p(a1);
__p(a...);
}
template<typename Arg1>
void __f(const char *name, Arg1 &&arg1) {
cout<<name<<" : ";
__p(arg1);
cout<<endl;
}
template<typename Arg1, typename ... Args>
void __f(const char *names, Arg1 &&arg1, Args &&... args) {
int bracket=0,i=0;
for(;; i++)
if(names[i]==','&&bracket==0)
break;
else if(names[i]=='(')
bracket++;
else if(names[i]==')')
bracket--;
const char *comma=names+i;
cout.write(names,comma-names)<<" : ";
__p(arg1);
cout<<" | ";
__f(comma+1,args...);
}
#define trace(...) cout<<"Line:"<<_LINE<<" ", __f(#__VA_ARGS__, __VA_ARGS__)
#else
#define trace(...)
#define error(...)
#endif
// DEBUG FUNCTIONS END 
//#define int   long long
#define pb push_back
#define ppb pop_back
#define ll long long
//const int inf=1000000000000000000;
const int mod=998244353; 
//const int mod=1000000007;
#define fr first
#define sc second
#define pii  pair<int,int>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
void pyes(){
cout<<"YES";
}
void pno(){
cout<<"NO";
}
const int N = 1000003;
vector<int> lp(N+1);
vector<int> pr;
void sieve(){
for (int i=2; i <= N; ++i) {
if (lp[i] == 0) {
lp[i] = i;
pr.push_back(i);
}
for (int j = 0; i * pr[j] <= N; ++j) {
lp[i * pr[j]] = pr[j];
if (pr[j] == lp[i]) {
break;
}
}
}
}
bool check(vector<int>&v){
     int n=v.size();
     map<int,int>m;
     for(int i=0; i<n; ++i){
         if(m.count(v[i])){
return true;
}
m[v[i]]=1;
}
return false;
}
int gcdExtended(int a, int b, int* x, int* y)
{
// Base Case
if (a == 0)
{
 *x = 0, *y = 1;
return b;
}
 int x1, y1; // To store results of recursive call
int gcd = gcdExtended(b % a, a, &x1, &y1);
// Update x and y using results of recursive
// call
*x = y1 - (b / a) * x1;
*y = x1;
return gcd;
}
// Function to find modulo inverse of a
ll modInverse(ll a, ll m)
{
int x, y;
int g = gcdExtended(a, m, &x, &y);
if (g != 1)
 return 0;
else
{
// m is added to handle negative x
ll res = (x % m + m) % m;
return res;
}
}
ll nCr(int n, int r){
if(r>n){
return 0;
}
if(r>n-r){
r = n-r;
}
ll ans = 1;
for(int i = 1; i<=r ; i++){
ans *= (n-i+1);
ans%= mod;
ans *= modInverse(i, mod);
ans %= mod;
}
return ans;
}
//BELOW IS GENERL
long long binpow(long long a, long long b) {
ll res=1;
for(int i=0; i<36; ++i){
if((1ll<<i)&b) (res*=a)%=mod;
(a*=a)%=mod;
}
return res;
}

string recurs (string s, string t) {
    if( s == t ) {
        return t;
    }
}



void solve() {

    string s;
    cin>>s;

    string t;
    cin>>t;
    
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);



    ll test=1;
//cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
