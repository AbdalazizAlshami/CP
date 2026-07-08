#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
vector<int> a[N];
int n,k,par,ans=0; 
void dfs1(int node,int p){
	if(node==k) par=p;
	for(auto i:a[node]){
		if(i!=p) dfs1(i,node);
	} 
}
void go(int node,int p){
	ans++;
	for(auto i:a[node]){
		if(i!=p) go(i,node);
	}
}
signed main(){
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin>>n>>k;
	for(int i=0;i<n-1;i++){
		int u,v; cin>>u>>v;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	dfs1(1,0);
	go(k,par);
	cout<<ans<<endl;
	
}
