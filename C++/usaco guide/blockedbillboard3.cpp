#include <bits/stdc++.h>
using namespace std;
int main(){
    //freopen("billboard.in", "r", stdin);
    //freopen("billboard.out", "w", stdout);
    vector <vector <bool>> arr (2001, vector <bool> (2001, 0));
    vector <long long> lawn (4), feed(4);
    for (long long i=0;i<8;i++){
        if (i<4){
            cin >> lawn[i];
            lawn[i]+=1000;
        }
        else{
            cin >> feed[i-4];
            feed[i-4]+=1000;
        }
    }

    for (long long i=lawn[0];i<=lawn[2];i++){
        for (long long j=lawn[1];j<=lawn[3];j++){
            arr[i][j]=1;
        }
    }
    for (long long i=feed[0];i<=feed[2];i++){
        for (long long j=feed[1];j<=feed[3];j++){
            arr[i][j]=0;
        }
    }

    vector <long long> edges = {9999, 9999, 0, 0};
    bool found = false;
    for (long long i=0;i<=2000;i++){
        for (long long j=0;j<=2000;j++){
            if (arr[i][j]){
                found=1;
                edges[0] = min(edges[0], i);
                edges[1] = min(edges[1], j);
                edges[2] = max(edges[2], i);
                edges[3] = max(edges[3], j);
            }
        }
    }

    for (auto e: edges){
        cout << e << endl;
    }

    if (found){
        cout << (edges[2]-edges[0]) * (edges[3]-edges[1]) << endl;
    }
    else{
        cout << 0 << endl;
    }
}