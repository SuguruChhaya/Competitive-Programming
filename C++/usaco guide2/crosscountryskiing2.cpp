#include <bits/stdc++.h>
using namespace std;
long long n, m, curr;
vector <vector <long long>> arr, visited, points;

void floodfill(long long i, long long j, long long mid, long long prev){
    if (i>=0 && i<n && j>=0 && j<m && !visited[i][j] && abs(arr[i][j]-prev)<=mid){
        visited[i][j]=1;
        if (points[i][j]){
            curr--;
        }
        floodfill(i+1, j, mid, arr[i][j]);
        floodfill(i-1, j, mid, arr[i][j]);
        floodfill(i, j+1, mid, arr[i][j]);
        floodfill(i, j-1, mid, arr[i][j]);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //!Probably shouldn't use set 
    freopen("ccski.in", "r", stdin);
    freopen("ccski.out", "w", stdout);
    cin >> n >> m;
    arr.resize(n, vector <long long>(m));
    long long mini = 99999999999999, maxi =-1;
    for (long long i=0;i<n;i++){
        for (long long j=0;j<m;j++){
            cin >> arr[i][j];
            mini = min(mini, arr[i][j]);
            maxi = max(maxi, arr[i][j]);
        }
    }
    vector <long long> first_point;
    long long numPoints =0;
    points.resize(n, vector <long long>(m));
    for (long long i=0;i<n;i++){
        for (long long j=0;j<m;j++){
            cin >> points[i][j];
            if (points[i][j]){
                numPoints++;
                first_point = {i, j};
            }
        }
    }
    long long l=0, r= maxi-mini, ans;
    while (l<=r){
        long long mid = (l+r)/2;
        visited.clear();
        visited.resize(n, vector <long long>(m));
        curr = numPoints;
        floodfill(first_point[0], first_point[1], mid, arr[first_point[0]][first_point[1]]);
        bool ok = true;
        //!This iteration could eat up steps. 
        //*Just use the total number of points. 
        
        /*
        for (auto e:points){
            if (!visited[e[0]][e[1]]){
                ok = false;
                break;
            }
        }
        */
        if (curr==0){
            ans = mid;
            r = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    cout << ans << endl;
}   