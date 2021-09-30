#include <bits/stdc++.h>
using namespace std;
long long n;
vector <vector <char>> arr;
vector <vector <vector <vector <bool>>>> checked_rectangle;
long long ans =0;
vector <vector <bool>> visited;

vector <long long> not_filled(long long r1, long long c1, long long r2, long long c2, vector <vector <bool>> visited){
    for (long long i=r1;i<=r2;i++){
        for (long long j=c1;j<=c2;j++){
            if (!visited[i][j]){
                return {i, j};
            }
        }
    }
    return {-1, -1};
}
void floodfill(long long r1, long long c1, long long r2, long long c2, long long i, long long j, char c){
    if (i>=r1 && i<=r2 && j>=c1 && j<=c2 && !visited[i][j] && arr[i][j]==c){
        visited[i][j]=1;
        floodfill(r1, c1, r2, c2, i-1, j, c);
        floodfill(r1, c1, r2, c2, i+1, j, c);
        floodfill(r1, c1, r2, c2, i, j-1, c);
        floodfill(r1, c1, r2, c2, i, j+1, c);
    }
}
bool is_pcl(long long r1, long long c1, long long r2, long long c2){
    visited.clear();
    visited.resize(n, vector <bool>(n, 0));
    auto temp = not_filled(r1, c1, r2, c2, visited);
    map <char, long long> d;
    vector <long long> negative_one = {-1, -1};
    while (temp!=negative_one){
        //cout << "stuck" << endl;
        floodfill(r1, c1, r2, c2, temp[0], temp[1], arr[temp[0]][temp[1]]);
        d[arr[temp[0]][temp[1]]]++;
        temp = not_filled(r1, c1, r2, c2, visited);
    }
    if (d.size()==2){
        long long one=0, two=0;
        for (auto p:d){
            if (p.second==1){
                one++;
            }
            else if (p.second==2){
                two++;
            }
            else{
                return false;
            }
        }
        if (one==1 && two==1){
            return true;
        }
    }
    return false;
}

void shrink(long long r1, long long c1, long long r2, long long c2){
    //*Need to make sure it doesn't go out of bounds 
    if (r1 < n && c1 < n && r2>=0 && c2 >=0 && !checked_rectangle[r1][c1][r2][c2]){
        checked_rectangle[r1][c1][r2][c2]=1;

        if (is_pcl(r1, c1, r2, c2)){
            ans++;
            cout << r1 << " " << c1 << " " << r2 << " " << c2 << endl;
        }
        else{
            shrink(r1+1, c1, r2, c2);
            shrink(r1, c1+1, r2, c2);
            shrink(r1, c1, r2-1, c2);
            shrink(r1, c1, r2, c2-1);
        }
    }
}

int main(){
    cin >> n;
    arr.resize(n, vector <char>(n));
    for (long long i=0;i<n;i++){
        for (long long j=0;j<n;j++){
            cin >> arr[i][j];
        }
    }
    //r1, c1, r2, c2
    checked_rectangle.resize(n, vector <vector <vector <bool>>>(n, vector <vector <bool>>(n, vector <bool>(n, 0))));
    long long r1 = 0, c1 = 0, r2 = n-1, c2 = n-1;
    shrink(r1, c1, r2, c2);
    cout << ans << endl;
}