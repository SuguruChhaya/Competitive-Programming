#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    freopen("highcard.in", "r", stdin);
    freopen("highcard.out", "w", stdout);
    //*Obviously want to find the card that is just a little larger than the other card. 
    //*Don't know if I will have to use binary search but
    long long n;
    cin >> n;
    //0-> Bessie, 1-> Elsie
    vector <long long> arr (2*n+1, 0);
    vector <long long> elsie;
    for (long long i=0;i<n;i++){
        long long temp;
        cin >> temp;
        elsie.push_back(temp);
        arr[temp]=1;
    }
    //!I can see how this process can be binary searched. 
    //!Don't really think I can binary search because there are gonna be weird spaces. 
    //*I could just make an array for bessie's cards. 
    long long ans = 0;
    for (auto e:elsie){
        for (long long j=e+1;j<=2*n;j++){
            if (arr[j]==0){
                //*Use it. 
                ans++;
                arr[j]=1;
                break;
            }
        }
    }
    cout << ans << endl;
}