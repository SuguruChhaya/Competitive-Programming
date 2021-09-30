#include <bits/stdc++.h>
using namespace std;

vector <long long> visited;
map <long long, vector <long long>> d;
void dfs(long long index){
    //cout << index << endl;
    visited[index] = 1;
    for (auto neighbor:d[index]){
        if (!visited[neighbor]){
            dfs(neighbor);
        }
    }
}
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    long long n, m;
    cin >> n >> m;
    //!This resize function is what I was looking for. 
    visited.resize(n+1, 0);
    visited[0]=-1;
    
    for (long long i=0;i<m;i++){
        long long a, b;
        cin >> a >> b;
        d[a].push_back(b);
        d[b].push_back(a);
    }
    //!I need to store one of the index that was used. 
    vector <long long> pairs;
    auto it = find(visited.begin(), visited.end(), 0);
    long long first_zero = -1;
    for (long long i=0;i<n;i++){
        if (visited[i]==0){
            first_zero = i;
            break;
        }
    }
    //*Instead of finding this all time, I could point at the last value. 
    while (first_zero!=-1){
        //auto it = find(visited.begin(), visited.end(), 0);
        //cout << first_zero << endl;
        dfs(first_zero);
        pairs.push_back(first_zero);
        while (first_zero <= n && visited[first_zero]==1){
            first_zero++;
        }
        if (first_zero==n+1){
            first_zero =-1;
        }
    }
    /*
    for (auto e:pairs){
        cout << e << endl;
    }
    */
    cout << pairs.size()-1 << endl;;
    for (long long i=0;i<pairs.size()-1;i++){
        cout << pairs[i] << " " << pairs[i+1] << endl;
    }
}
