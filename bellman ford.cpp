#include <bits/stdc++.h>
#define MaxN 111111
#define INF 1000000000
using namespace std;
int n, m, s, f;
vector< pair<int, int> > adj[MaxN];
int d[MaxN];
int rear, front;
int queue[MaxN];
bool inqueue[MaxN];
void push(int v){
	if (inqueue[v]) return;
	front = (front + 1) % n;
	queue[front] = v;
	inqueue[v] = true;
}
int pop(){
	rear = (rear + 1) % n;
	int v = queue[rear];
	inqueue[v] = false;
	return v;
}
void Bellman_Ford(){
	int i, u, v, w;
	memset(inqueue, false, sizeof(inqueue));
	for (i = 1; i <= n; i++) d[i] = INF;
	d[s] = 0;
	rear = 0;
	front = 0;
	push(s);
	while(rear!=front){
		u = pop();
		for (i = 0; i < adj[u].size(); i++){
			v = adj[u][i].first;
			w = adj[u][i].second;
			if (d[v] > d[u] + w){
				d[v] = d[u] + w;
				push(v);
			}
		}
	}
	if (d[f] == INF) cout << "-1" << endl; cout << d[f] << endl;
}
int main(){
	int i, u, v, w;
	cin >> n >> m >> s >> f;
	for (i = 1; i <= n; i++) adj[i].clear();
	for (i = 1; i <= m; i++){
		cin >> u >> v >> w;
		adj[u].push_back(make_pair(v, w));
		adj[v].push_back(make_pair(u, w));
	}
	Bellman_Ford();
}
