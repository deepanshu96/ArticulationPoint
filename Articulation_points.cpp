
//ARTICULATION POINTS

/*
        ________________
       /.,------------,.\
      ///  .=^^^^^^^\__|\\
      \\\   `------.   .//
       `\\`--...._  `;//'
         `\\.-,___;.//'
           `\\-..-//'
             `\\//'
               ""
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <climits>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <iomanip>

using namespace std;

/*******  All Required define Pre-Processors and typedef Constants *******/
#define SCD(t) scanf("%d",&t)
#define SCLD(t) scanf("%ld",&t)
#define SCLLD(t) scanf("%lld",&t)
#define SCC(t) scanf("%c",&t)
#define SCS(t) scanf("%s",t)
#define SCF(t) scanf("%f",&t)
#define SCLF(t) scanf("%lf",&t)
#define MEM(a, b) memset(a, b, sizeof a)
#define FOR(i, j, k, in) for ( i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for ( i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define IN(A, B, C) assert( B <= A && A <= C)
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define INF (int)1e9
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 100000000
#define read(type) readInt<type>()
const double pi=acos(-1.0);
typedef vector<int> vint;
typedef vector<long long> vLL;
typedef double dbl;
typedef long double ldbl;
typedef vector<pair<int, int> > vpii;
typedef long ll;
typedef pair<int, int> pii;

/****** Template of some basic operations *****/
template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }
//variables
ll n,m;
vector<vector<ll> >v;
ll lev[12000];
ll tim[12000];
ll vis[12000];
ll ans[12000];
//func
void dfs(ll st,ll prev,ll t)
{

 if(vis[st]==1)
  return;
 
 vis[st]=1;
 tim[st]=t;
 lev[st]=t;
 
 
 ll kid=0;
 
 ll x = (ll)v[st].size();
 
 for(ll i=0;i<x;i++)
 {
  if(v[st][i]!=prev)
   {
    if(vis[ v[st][i] ]!=1)
     {
       dfs(v[st][i],st,t+1);
       kid+=1;
       
       if(st==1 && kid>1)
       ans[st]=1;
       else if(lev[v[st][i]]>=tim[st] && st!=1)
       ans[st]=1;
       
       lev[st]=min(lev[ v[st][i] ],lev[st]);
       
     }
    else
    lev[st]=min(lev[st],tim[v[st][i]]);

    //if not prev       
   }
   //for
 }
 
 lev[st]=min(lev[st],tim[st]);
 
 
 //dfs   
}
//main

int main()
{
 ll a,b,i;    
 while(1)
 {
  MEM(lev,0);     
  MEM(tim,0);
  MEM(vis,0);
  MEM(ans,0);
  
  v.clear();
  v.resize(11000);
     
  cin>>n>>m;
  if(n==0)
   break;
   
  FOR(i,0,m,1)
  {
    cin>>a>>b;     
    v[a].pb(b);
    v[b].pb(a);
  }
  dfs(1,-1,1);
  ll cnt=0;
  
  
  //cout<<lev[2]<<" "<<lev[5]<<" "<<lev[3]<<" "<<tim[3];
  
  FOR(i,1,n+1,1)
   if(ans[i]==1)
    cnt+=1;
   cout<<cnt<<endl;
 } 
  return 0;    
}