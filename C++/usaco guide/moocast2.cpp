#include <bits/stdc++.h>
using namespace std;
long long n;
vector <vector <long long>> arr;
vector <bool> used;
long long temp;
long long result = 0;
int main(){
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);
    cin >> n;
    arr.resize(n, vector <long long>(3));
    for (long long i=0;i<n;i++){
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }
    for (long long i=0;i<n;i++){
        temp=1;
        bool ok = true;
        used.resize(n, 0);
        used[i]=1;
        while (ok){
            ok = false;
            /*
            for (auto e:used){
                cout << e << endl;
            }
            */
            for (long long a=0;a<n;a++){
                for (long long b=a+1;b<n;b++){
                    if (used[a]==true&&used[b]==false && sqrt(pow(arr[a][0]-arr[b][0], 2)+pow(arr[a][1]-arr[b][1], 2))<=arr[a][2]){
                        //cout << a << ' ' << b<<endl;
                        //cout << used[a] << " " << used[b] << endl;
                        //used[b]=1;
                        ok = true;
                        used[b]=true;
                        temp++;
                    }
                }
            }
        }
        
        result = max(result, temp);
    }
    cout << result << endl;
}