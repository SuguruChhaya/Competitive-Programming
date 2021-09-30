#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n, q;
    cin >> n >> q;
    //*Yeah, way easier just adding another layer. 
    vector <vector <long long>> arr (n+1, vector <long long> (n+1, 0)), prefix (n+1, vector <long long> (n+1, 0));
    
    for (long long i=1;i<=n;i++){
        string s;
        cin >> s;
        for (long long j=1;j<=n;j++){
            if (s[j-1]=='*'){
                arr[i][j] = 1;
            }
            //*Keep adding into the 2D prefix sum array. 
            //!The method of calculating the prefix sums were a little different. 
            prefix[i][j] = prefix[i-1][j]+prefix[i][j-1]-prefix[i-1][j-1]+arr[i][j];
        }
    }
    /*
    for (auto e:arr){
        for (auto b:e){
            cout << b << " ";
        }
        cout << endl;  
    }
    for (auto a:prefix){
        for (auto e:a){
            cout << e << " ";
        }
        cout << endl;
    }
    */
    for (long long i=0;i<q;i++){
        long long y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;
        long long min_x = min(x1, x2), min_y = min(y1, y2), max_x=max(x1, x2), max_y=max(y1, y2);
        long long big = prefix[max_y][max_x];
        long long top = prefix[min_y-1][max_x];
        long long left = prefix[max_y][min_x-1];
        long long overlap = prefix[min_y-1][min_x-1];
        cout << big - top - left + overlap << endl;
    }


}