#include <bits/stdc++.h>
using namespace std;
long long n;
vector <vector<char>> arr;
vector <vector <bool>> visited;
vector <vector <long long>> pcls;
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
    //n^2
    visited.resize(n, vector <bool>(n, 0));
    auto temp = not_filled(r1, c1, r2, c2, visited);
    map <char, long long> d;
    vector <long long> negative_one = {-1, -1};
    //n^2
    /*
    while (temp!=negative_one){
        //cout << "stuck" << endl;
        floodfill(r1, c1, r2, c2, temp[0], temp[1], arr[temp[0]][temp[1]]);
        d[arr[temp[0]][temp[1]]]++;
        temp = not_filled(r1, c1, r2, c2, visited);
    }
    */
    for (long long i=r1;i<=r2;i++){
        for (long long j=c1;j<=c2;j++){
            if (!visited[i][j]){
                d[arr[i][j]]++;
                floodfill(r1, c1, r2, c2, i, j, arr[i][j]);
            }
        }
    }
    if (d.size()==2){
        long long one=0, two=0;
        for (auto p:d){
            if (p.second==1){
                one++;
            }
            else if (p.second>=2){
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

bool is_inscribed(long long i, long long j){
    //!For TLE, I should definitely fix this part. 
    //Check if i is inscribed in j
    //*Just color and check whether it is complete overlap.
    /* 
    vector <vector <long long>> overlap(n, vector <long long>(n, -1));
    for (long long a=pcls[i][0];a<=pcls[i][2];a++){
        for (long long b=pcls[i][1];b<=pcls[i][3];b++){
            overlap[a][b]=0;
        }
    }
    
    for (long long a=pcls[j][0];a<=pcls[j][2];a++){
        for (long long b=pcls[j][1];b<=pcls[j][3];b++){
            overlap[a][b]=1;
        }
    }

    for (long long a=0;a<n;a++){
        for (long long b=0;b<n;b++){
            if (overlap[a][b]==0){
                return true;
            }
        }
    }
    return false;
    */
    
    if (pcls[j][0]<=pcls[i][0] && pcls[j][1]<=pcls[i][1] && pcls[j][2]>=pcls[i][2] && pcls[j][3]>=pcls[i][3]){
        return false;
    }
    else{
        return true;
    }
}
int main(){
    //*Other random ideas: match up each of the alphabets. 
    //*group all the connected components and match them somehow?
    //*At a certian cell at the left top, what is the largest connected component I can make?
    freopen("where.in", "r", stdin);
    freopen("where.out", "w", stdout);
    cin >> n;
    arr.resize(n, vector <char>(n));
    for (long long i=0;i<n;i++){
        for (long long j=0;j<n;j++){
            cin >> arr[i][j];
        }
    }
    //n^4 with just loops
    for (long long r1=0;r1<n;r1++){
        for (long long c1=0;c1<n;c1++){
            for (long long r2=r1;r2<n;r2++){
                for (long long c2=c1;c2<n;c2++){
                    if (is_pcl(r1, c1, r2, c2)){
                        //n^2
                        pcls.push_back({r1, c1, r2, c2});
                    }
                }
            }
        }
    }
    //n^6
    long long ans = 0;
    
    
    //n^8
    for (long long i=0;i<pcls.size();i++){
        bool ok = true;
        for (long long j=0;j<pcls.size();j++){
            if (i!=j && !is_inscribed(i, j)){
                ok = false;
                break;
            }
        }
        if (ok){
            ans++;
        }
    }
    cout << ans << endl;
}