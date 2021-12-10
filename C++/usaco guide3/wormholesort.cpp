#include <bits/stdc++.h>
using namespace std;

vector<vector<long long>> d;
vector<bool>visited;

void visit(long long i){
    //!Says that I already visited 2...
    //*Should include in a separate arr. Just in case it isn't connected. 
    if (!visited[i]){
        visited[i] = 1;
        for (auto e:d[i]){
            visit(e);
        }
    }
}

int main(){
    freopen("wormsort.in", "r", stdin);
    freopen("wormsort.out", "w", stdout);
    long long n, m;
    cin >> n >> m;
    vector<long long> arr (n+1);
    for (long long i=1;i<=n;i++){
        cin >> arr[i];
    }
    vector<vector<long long>> wormholes(m, vector<long long>(3));
    for (long long i=0;i<m;i++){
        cin >> wormholes[i][1] >> wormholes[i][2] >> wormholes[i][0];
    }
    //*I still need to sort based on width. 
    sort(wormholes.begin(), wormholes.end());

    auto sorted = arr;
    sort(sorted.begin(), sorted.end());
    if (arr==sorted){
        cout << -1 << endl;
        return 0;
    }
    long long l=0, r = m-1, ans;
    while (l<=r){
        long long mid = (l+r) / 2;
        d = {};
        d.resize(n+1);
        for (long long i=mid;i<m;i++){
            d[wormholes[i][1]].push_back(wormholes[i][2]);
            d[wormholes[i][2]].push_back(wormholes[i][1]);
        }
        /*
        for (auto p:d){
            cout << "p.first: " << p.first << endl;
            cout << "p.second:" << endl;
            for(auto e:p.second){
                cout << e << endl;
            }
        }
        */

        visited = {};
        visited.resize(n+1, 0);
        vector<bool> temp = visited;
        for (long long i=1;i<=n;i++){
            //*Don't think this will make sense. 
            if (arr[i]==i){
                temp[i] = 1;
            }
        }
        for (long long i=1;i<=n;i++){
            if (!visited[i]){
                visit(i);
                break;
            }
        }
        bool ok = true;
        for (long long i=1;i<=n;i++){
            if (!visited[i] && !temp[i]){
                ok = 0;
                break;
            }
        }
        if (ok){
            ans = wormholes[mid][0];
            //*If possible, restrict it even more. 
            l = mid+1;
        }
        else{
            r = mid-1;
        }
    }
    cout << ans << endl;
}