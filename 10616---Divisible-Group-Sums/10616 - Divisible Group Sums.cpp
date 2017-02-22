/*
         +-+ +-+ +-+
         |R| |.| |S|
         +-+ +-+ +-+
 */
 
#include <bits/stdc++.h>
 
#define pii             pair <int,int>
#define sc              scanf
#define pf              printf
#define Pi              2*acos(0.0)
#define ms(a,b)         memset(a, b, sizeof(a))
#define pb(a)           push_back(a)
#define MP              make_pair
#define db              double
#define ll              long long
#define EPS             10E-10
#define ff              first
#define ss              second
#define sqr(x)          (x)*(x)
#define D(x)            cout<<#x " = "<<(x)<<endl
#define VI              vector <int>
#define DBG             pf("Hi\n")
#define MOD             100007
#define MAX             10000
#define CIN             ios_base::sync_with_stdio(0); cin.tie(0)
#define SZ(a)           (int)a.size()
#define sf(a)           scanf("%d",&a)
#define sfl(a)          scanf("%lld",&a)
#define sff(a,b)        scanf("%d %d",&a,&b)
#define sffl(a,b)       scanf("%lld %lld",&a,&b)
#define sfff(a,b,c)     scanf("%d %d %d",&a,&b,&c)
#define sfffl(a,b,c)    scanf("%lld %lld %lld",&a,&b,&c)
#define loop(i,n)       for(int i=0;i<n;i++)
#define REP(i,a,b)      for(int i=a;i<b;i++)
#define TEST_CASE(t)    for(int z=1;z<=t;z++)
#define PRINT_CASE      printf("Case %d: ",z)
#define all(a)          a.begin(),a.end()
#define intlim          2147483648
#define inf             1000000
#define ull             unsigned long long
 
using namespace std;
 
 
/*----------------------Graph Moves----------------*/
//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
//const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
//const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
/*------------------------------------------------*/
 
/*-----------------------Bitmask------------------*/
//int Set(int N,int pos){return N=N | (1<<pos);}
//int reset(int N,int pos){return N= N & ~(1<<pos);}
//bool check(int N,int pos){return (bool)(N & (1<<pos));}
/*------------------------------------------------*/
 
int n, q,d,m;
int ara[300];
ll dp[210][11][22];
 
ll func(int idx, int cnt, int sum)
{
 
    if(cnt==m)
    {
        if(sum==0) return 1;
        return 0;
    }
    if(idx>=n) return 0;
 
    ll &ret=dp[idx][cnt][sum];
 
    if(ret!=-1) return ret;
 
 
    ll xx=0,yy=0;
 
    ll temp=sum+ara[idx];
    temp%=d;
    if(temp<0) temp+=d;
 
    xx=func(idx+1,cnt+1,temp);
 
    yy=func(idx+1,cnt,(sum)%d);
 
    return ret=xx+yy;
}
 
int main()
{
    ///freopen("in.txt","r",stdin);
    ///freopen("out.txt","w",stdout);
 
    int z=0;
 
    while(sff(n,q)==2 && (n && q))
    {
        z++;
        pf("SET %d:\n",z);
        loop(i,n) sf(ara[i]);
        loop(i,q)
        {
 
            sff(d,m);
            ms(dp,-1);
            printf("QUERY %d: %lld\n",i+1,func(0,0,0));
        }
    }
 
    return 0;
}
