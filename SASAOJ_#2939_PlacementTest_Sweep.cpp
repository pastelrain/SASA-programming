#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<ll,ll>


ll n,m,c;
ll ans;

pii v[100001];
ll tree[1<<18];

ll query(ll node,ll st,ll ed,ll left,ll right)
{
    if(!(st<=right && left<=ed)) return 0;
    if(left<=st && ed<=right) return tree[node];

    return max(query(node*2,st,(st+ed)/2,left,right),query(node*2+1,(st+ed)/2+1,ed,left,right));
}

void update(ll node,ll st,ll ed,ll idx,ll val)
{
    if(!(st<=idx && idx<=ed)) return;

    if(st==ed)
    {
        tree[node]=max(tree[node],val);
        return;
    }

    update(node*2,st,(st+ed)/2,idx,val);
    update(node*2+1,(st+ed)/2+1,ed,idx,val);

    tree[node]=max(tree[node*2],tree[node*2+1]);
}


bool safe(int x,int y)
{
    return 0<=x&&x<=n&&0<=y&&y<=m;
}


int main()
{
    cin>>n>>m>>c;

    vector<ll> tmpv;

    for(int i=0;i<c;i++)
    {
        int x,y;
        cin>>x>>y;

        if(safe(x,y))
        {
            v[tmpv.size()]={x,y};
            tmpv.push_back(y);
        }
    }

    c=tmpv.size();

    //coord compress
    sort(tmpv.begin(),tmpv.end());
    tmpv.erase(unique(tmpv.begin(),tmpv.end()),tmpv.end());

    for(int i=0;i<c;i++)
    {
        v[i].second=lower_bound(tmpv.begin(),tmpv.end(),v[i].second)-tmpv.begin()+1;
    }

    sort(v,v+c); //x first

    //query
    ll N=tmpv.size(); //compressed size
    for(int i=0;i<c;i++) //left to right
    {
        ll curscore=query(1,1,N,1,v[i].second); //before the point
        update(1,1,N,v[i].second,curscore+1); //including point itself

        ans=max(ans,curscore+1);
    }

    cout<<ans;
}
