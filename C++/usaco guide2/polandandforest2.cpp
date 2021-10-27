#include <bits/stdc++.h>

using namespace std;

vector<int> adj[10000];
bool visited[10000];

void DFS(int node){
	if(visited[node]) return;
	visited[node] = true;
	for(int adjNode: adj[node]){
		DFS(adjNode);
	}
}

int main(){
	int n; cin >> n;
	for(int i=0; i<n; i++){
		int p; cin >> p; --p;
		adj[p].push_back(i);
		adj[i].push_back(p);
	}
	int numTrees = 0;
	for(int i=0; i<n; i++){
		if(!visited[i]){
			numTrees++;
			DFS(i);
		}
	}
	cout << numTrees << endl;
}
