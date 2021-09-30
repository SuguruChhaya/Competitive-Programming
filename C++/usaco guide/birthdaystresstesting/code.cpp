#include <bits/stdc++.h>
using namespace std;
vector <bool> invited;
vector <vector <long long>> arr;
vector <vector <long long>> connections;
long long p, c;
void dfs(long long i){

    if (invited[i]==0){
        invited[i]=1;
        for (long long j=0;j<p;j++){
            if (arr[i][j]==1){

                dfs(j);
            }
        }
    }
}
int main(){
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
    while(true){
        cin >> p >> c;
        if (p==0&&c==0){
            return 1;
        }
        //invited.resize(p, 0);
        //Basically store a matrix of all connections. 
        //arr.resize(p, vector <long long> (p, 0));
        invited.clear();
        invited.resize(p, 0);
        arr.clear();
        arr.resize(p, vector <long long> (p, 0));
        connections.clear();
        
        for (long long i=0;i<c;i++){
            long long a, b;
            cin >> a >> b;
            arr[a][b]=1;
            arr[b][a]=1;
            connections.push_back({a, b});
        }
        //string ans = "YES";
        bool ans =1;

        for (auto pair:connections){
            for (long long i=0;i<p;i++){
                invited[i]=0;
            }
            arr[pair[0]][pair[1]]=0;
            arr[pair[1]][pair[0]]=0;
            dfs(0);

            for (auto e:invited){
                if (e==0){
                    //!I cannot escape from the main loop; 
                    ans = 0;
                }
            }
            arr[pair[0]][pair[1]]=1;
            arr[pair[1]][pair[0]]=1;
        }
        if (!ans){
            cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl;
        }
    }
}