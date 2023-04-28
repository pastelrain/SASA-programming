// -----------------------------
// AAC_Quiz1_Solution
// Placing: 1/24
// Finished Time: 01:02:31 / 01:50:00
// -----------------------------
// -----------------------------
// -----------------------------
// A - 현석이의 지갑을 지키자 #2927(김태영 출제)
// Difficulty: Silver V
// Algorithm: Greedy 
// Time: 00:06:09 / 13/24
// First Solve: 00:02:43
// -----------------------------
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>

int v[3000001];

int main()
{
    int n,m,W;
    cin>>n>>m>>W;

    ll ans=0;
    ll mx=0;
    for(int i=0;i<n;i++)
    {
        ll w,s,e;
        cin>>w>>s>>e;

        if(s>e) ans+=w*(s-e);
        else ans+=2*w*(e-s);

        mx=max(mx,s);
        mx=max(mx,e);
    }

    ans+=3*W*(mx-1);
    cout<<ans;
}
// -----------------------------
// -----------------------------
// B - 타겟 넘버 #2922(윤태영 출제)
// Difficulty: Silver III
// Algorithm: Combinatorics, Case Work
// Time: 01:02:31 / 16/24
// First Solve: 00:05:13
// -----------------------------
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>


ll v[10001]; // ll 안 쓰면 Overflow, 94% WA

int main()
{
    int n,t;
    cin>>n>>t;

    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        v[x]++;
    }

    ll ans=0;
    for(int i=1;i<=t;i++)
    {
        //1 A
        if(i==t) ans+=v[i];

        //2
        if(i<t-i) ans+=v[i]*v[t-i]; //AB
        if(i*2==t) ans+=v[i]*(v[i]-1)/2; //AA

        //3
        if(v[i]>=3 && i*3==t) ans+=v[i]*(v[i]-1)*(v[i]-2)/6; //AAA
        if(v[i]>=2 && i*2<=t && i*3!=t) ans+=v[i]*(v[i]-1)*v[t-i*2]/2; //AAB or ABB
        if(v[i]) //ABC
        {
            for(int j=i+1;j<t-i-j;j++)
            {
                ans+=v[i]*v[j]*v[t-i-j];
            }
        }
    }

    cout<<ans;
}
// -----------------------------
// -----------------------------
// C - 팰린드롬 소수 데이 #2913(윤형진 출제)
// Difficulty: Silver III
// Algorithm: Number Theory - Sieve of Erastosthenes
// Time: 00:16:17 / 3/24
// First Solve: 00:06:21
// -----------------------------
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>

int v[10000001];

bool palind(int n)
{
    int tmp=0;

    while(n)
    {
        tmp=tmp*10+n%10;
        n/=10;
    }

    return v[tmp];
}

int len(int n)
{
    int tmp=0;
    while(n)
    {
        tmp++;
        n/=10;
    }

    return tmp;
}

int main()
{
    v[0]=v[1]=0;
    for(int i=2;i<=1e7;i++)
    {
        if(v[i]) continue;
        for(int j=i*2;j<=1e7;j+=i) v[j]=1;
    }

    int n,m;
    cin>>n>>m;


    int ans=0;

    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
    {
        int tmp=i*pow(10,len(j))+j;
        if(v[tmp]==0 && palind(tmp)==0) ans++;
    }

    cout<<ans;
}
// -----------------------------
// -----------------------------
// D - 아깝수 #2941(장한진 출제)
// Difficulty: Silver III
// Algorithm: Number Theory - Sieve of Erastosthenes
// Time: 00:04:13 / 2/24
// First Solve: 00:01:56
// -----------------------------
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>

int v[3000001];

int main()
{
    int n,k;
    cin>>n>>k;

    for(int i=1;i<=n;i++)
    {
        for(int j=i*2;j<=n;j+=i) v[j]+=i; // j를 i*1부터 세면 TLE, i*2부터 세면 AC.
    }

    int ans=0;
    for(int i=1;i<=n;i++)
    {
        v[i]-=i;
        if(abs(v[i])<=k) ans++;
    }

    cout<<ans;
}
// -----------------------------
// -----------------------------
// E - SASA 체육대회 #JJH(from #2925:훔쳐보기 by 한지후)
// Difficulty: Silver II
// Algorithm: Greedy
// Time: 00:46:33 / 2/24
// First Solve: 00:33:37
// -----------------------------
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>


queue<int> vd,vs;

int main()
{
    ll n,d,k;
    cin>>n>>d>>k;

    n+=d;

    string s;
    cin>>s;

    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='D') vd.push(i);
        else vs.push(i);
    }

    int ans=0;
    while(!vd.empty()&&!vs.empty())  //queue를 이용한 비교 / 기존 문제와 동일한 풀이 방식을 사용하면 96% TLE.
    {
        int curd=vd.front();
        int curs=vs.front();

        if(abs(curd-curs)<=k)
        {
            vd.pop();
            vs.pop();

            ans++;
        }

        else if(curd<curs)
        {
            vd.pop();
        }
        else vs.pop();
    }

    cout<<ans;
}
// -----------------------------
// -----------------------------
