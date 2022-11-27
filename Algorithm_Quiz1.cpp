/////////////////////////////////
//------A Solution---------------
#include<stdio.h>
#include<iostream>
using namespace std;

#define swap(a,b) {int t=a;a=b;b=t;}

int main()
{
	int n;
	cin>>n;

	int v[n];
	for(int i=0;i<n;i++) cin>>v[i];

	int cnt=0;
	for(int i=1;i<n;i++)
	{
		int tmp=v[i];
		int j;
		for(j=i-1;j>=0;j--)
		{
			if(v[j]>=tmp) {v[j+1]=v[j]; cnt++;}
			else break;
		}

		swap(v[j+1],tmp);
	}

	cout<<cnt;
}
//////////////////////////////////
//------B Solution----------------
#include<stdio.h>
#include<iostream>
using namespace std;

#define swap(a,b) {int t=a;a=b;b=t;}

int main()
{
	int n;
	cin>>n;

	int v[n];
	for(int i=0;i<n;i++) cin>>v[i];

	int m;
	cin>>m;

	for(int i=1;i<n;i++)
	{
		int tmp=v[i];
		int j;
		for(j=i-1;j>=0;j--)
		{
			if(v[j]>=tmp) v[j+1]=v[j];
			else break;
		}

		swap(v[j+1],tmp);
	}

	for(int i=0;i<m;i++)
	{
		for(int j=0;j<=i;j++) cout<<v[j]<<" ";
		cout<<"\n";
	}
}
/////////////////////////////////////////////
//------C Solution--------------------------
#include<stdio.h>
#include<iostream>
using namespace std;

#define swap(a,b) {int t=a;a=b;b=t;}

int ans=0;

int partition(int *v,int st,int ed)
{
	int p=st;

	for(int i=st;i<ed;i++)
	{
		if(v[i]<v[ed]) {swap(v[p],v[i]); p++;}
	}

	swap(v[p],v[ed]);

	return p;
}

void quickSort(int *v,int st,int ed)
{
	if(st>=ed) return;

	int idx=partition(v,st,ed);

	int a=ed-idx,b=idx-st;
	
	if(a>b?(a<=2*b):(b<=2*a)) ans++;

	quickSort(v,st,idx-1);
	quickSort(v,idx+1,ed);
}

int main()
{
	int n;
	cin>>n;

	int v[n];
	for(int i=0;i<n;i++) cin>>v[i];

	quickSort(v,0,n-1);
	cout<<ans;
}
///////////////////////////////////////////////
//------D Solution-----------------------------
#include<stdio.h>
#include<iostream>
using namespace std;

#define swap(a,b) {int t=a;a=b;b=t;}

int cnt1,cnt2=0;

void merge(int *v,int st,int ed)
{
	int mid=(st+ed)/2;

	int tmp[ed-st+1];
	int p1=st,p2=mid+1;
	int p=0;

	while(p1<=mid&&p2<=ed)
	{
		if(v[p1]>v[p2]) tmp[p++]=v[p2++];
		else tmp[p++]=v[p1++];
	}

	if(p1>mid) cnt1++;
	if(p2>ed) cnt2++;

	while(p1<=mid) tmp[p++]=v[p1++];
	while(p2<=ed) tmp[p++]=v[p2++];
}

void mergeSort(int *v,int st,int ed)
{
	if(st>=ed) return;

	int mid=(st+ed)/2;

	mergeSort(v,st,mid);
	mergeSort(v,mid+1,ed);
	merge(v,st,ed);
}

int main()
{
	int n;
	cin>>n;

	int v[n];
	for(int i=0;i<n;i++) cin>>v[i];

	mergeSort(v,0,n-1);
	cout<<cnt1<<" "<<cnt2;
}
////////////////////////////////////////////////
//------E Solution------------------------------
#include<stdio.h>
#include<iostream>
using namespace std;

#define swap(a,b) {int t=a;a=b;b=t;}

int ans=0;

void heapify(int *v,int k,int n)
{
	int left=k*2,right=k*2+1;
	int x;

	if(left>n) return;

	if(right>n) x=left;
	else x=v[left]<v[right]?left:right;

	if(v[x]<v[k])
	{
	    ans++;
		swap(v[x],v[k]);
		heapify(v,x,n);
	}
}

void buildHeap(int *v,int n)
{
	for(int i=(n+1)/2;i>=1;i--)
	{
		heapify(v,i,n);
	}
}

void heapSort(int *v,int n)
{
	buildHeap(v,n);
	ans=0;

	for(int i=n;i>1;i--)
	{

		swap(v[1],v[i]);
		heapify(v,1,i-1);
	}
}

int main()
{
	int n;
	cin>>n;

	int v[n+1];
	for(int i=1;i<=n;i++) cin>>v[i];

	heapSort(v,n);
	cout<<ans;
}
