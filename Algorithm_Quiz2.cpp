////////////////////////////////////////////////////////////////
//given time - 01:15:00
//place - 3/31
//first solve in the entire quiz - D (00:07:54)
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// A: https://code.sasa.hs.kr/problem.php?id=2892
// B: https://code.sasa.hs.kr/problem.php?id=2891
// C: https://code.sasa.hs.kr/problem.php?id=2075
// D: https://code.sasa.hs.kr/problem.php?id=2893
// E: https://code.sasa.hs.kr/problem.php?id=2095
// F: https://code.sasa.hs.kr/problem.php?id=2094
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
//A - backtracking. 00:35:24 solved
#include<iostream>
using namespace std;

#define ll long long
#define pii pair<int,int>


int k;
int n,m;
int x1,y1,x2,y2;
int v[22][22];
int vis[22][22];

int cnt=0;

void dfs(int x,int y,int cur)
{
    if(cur>k) return;

    if(x==x2 && y==y2)
    {
        cnt++;
        return;
    }
    
    if(x>1 && vis[x-1][y]==0)
    {
        vis[x-1][y]=1;
        dfs(x-1,y,cur+v[x-1][y]);
        vis[x-1][y]=0;
    }

    if(x<n && vis[x+1][y]==0)
    {
        vis[x+1][y]=1;
        dfs(x+1,y,cur+v[x+1][y]);
        vis[x+1][y]=0;
    }

    if(y<m && vis[x][y+1]==0)
    {
        vis[x][y+1]=1;
        dfs(x,y+1,cur+v[x][y+1]);
        vis[x][y+1]=0;
    }
}

int main()
{
    cin>>k;
    cin>>n>>m;
    cin>>x1>>y1>>x2>>y2;

    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
    cin>>v[i][j];

    vis[x1][y1]=1;
    dfs(x1,y1,v[x1][y1]);

    cout<<cnt;
}

////////////////////////////////////
//B
//unsolved
//////////////////////////////////////////////////////
//C - queue. 00:21:08 solved
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>


int dp[1000001];
 
int main()
{
    int n;
    cin>>n;
 
    int m=4;
    int v[m];
    for(int i=0;i<m;i++) cin>>v[i];
     
    queue<int> q;
    q.push(0);
     
    for(int i=1;i<=n;i++) dp[i]=1e9;
    while(!q.empty())
    {
        int cur=q.front();
        q.pop();
 
        if(cur>n) continue;
 
        for(int i=0;i<m;i++)
        {
            if(cur+v[i]<=n && dp[cur+v[i]]>dp[cur]+1)
            {
                dp[cur+v[i]]=dp[cur]+1;
                q.push(cur+v[i]);
            }
        }
    }
 
    if(dp[n]) cout<<dp[n];
    else cout<<"TT";
}

////////////////////////////////////////////////////////////
//D - dp. 00:07:54 first solved
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>


int dp[1000001];
 
int main()
{
    int n,m;
    cin>>n>>m;
 
    int v[m];
    for(int i=0;i<m;i++) cin>>v[i];
 
    for(int i=1;i<=n;i++)
    {
        dp[i]=1e9;
        for(int j=0;j<m;j++)
        {
            if(i-v[j]>=0) dp[i]=min(dp[i],dp[i-v[j]]+1);
        }
    }
 
    if(dp[n]!=1e9) cout<<dp[n];
    else cout<<"TT";
}




//////////////////////////////////////////////////////////////
//E - kruskal. 00:47:38 solved
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>


struct P
{
    int x,y,cost;
};
 
bool cmp(P a,P b)
{
    return a.cost>b.cost;
}
int root[111];
 
int Find(int x)
{
    if(x==root[x]) return x;
    else return root[x]=Find(root[x]);
}
 
void Union(int x,int y)
{
    x=Find(x);
    y=Find(y);
 
    if(x>y) swap(x,y);
 
    root[y]=x;
}
 
vector<P> v;
int main()
{
    for(int i=0;i<111;i++) root[i]=i;
 
    int n,m;
    cin>>n>>m;
 
    for(int i=0;i<m;i++)
    {
        int x,y,cost;
        cin>>x>>y>>cost;
 
        v.push_back({x,y,cost});
    }
 
    sort(v.begin(),v.end(),cmp);
 
    int ans=0;
    for(auto i:v)
    {
        if(Find(i.x)!=Find(i.y))
        {
            Union(i.x,i.y);
            ans+=i.cost;
        }
    }
 
    cout<<ans;
}


////////////////////////////////////////////////
//F - dijkstra. 00:43:19 solved
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>


vector<pii> v[101];
 
int dijkstra(int st,int ed)
{
    int dist[101];
    for(int i=0;i<101;i++) dist[i]=1e9;
 
    priority_queue<pii,vector<pii>,greater<pii>> pq;
 
    pq.push({0,st});
    dist[st]=0;
 
    while(!pq.empty())
    {
        pii cur=pq.top();
        pq.pop();
 
        if(cur.first>dist[cur.second]) continue;
 
        for(auto i:v[cur.second])
        {
            if(dist[i.second]>i.first+cur.first)
            {
                dist[i.second]=i.first+cur.first;
                pq.push({dist[i.second],i.second});
            }
        }
    }
 
    if(dist[ed]==1e9)
    {
        cout<<"TT";
        exit(0);
    }
    else return dist[ed];
}
 
int main()
{
    int n,m;
    cin>>n>>m;
 
    while(m--)
    {
        int x,y,cost;
        cin>>x>>y>>cost;
 
        v[x].push_back({cost,y});
        v[y].push_back({cost,x});
    }
 
    int st,ed1,ed2;
    cin>>st>>ed1>>ed2;
 
    int ans1=dijkstra(st,ed1)+dijkstra(ed1,ed2);
    int ans2=dijkstra(st,ed2)+dijkstra(ed2,ed1);
 
    cout<<min(ans1,ans2);
}
