#include <bits/stdc++.h>
using namespace std;

void solve(){
    long long n, k; cin >> n >> k;
    //!Difference between subarray and subsequence also exists. 
    //!3, 5, 4 will not work. This has to be splitted into 3 places.
    //!All numbers are distinct must mean something. 
    //*Should I store a map containing the location of all the numbers?
    //!Compare it with a sorted one 
    map <long long, long long> d;
    vector <long long> sorted;
    for (long long i=0;i<n;i++){
        long long temp;
        cin >> temp;
        sorted.emplace_back(temp);
        d.insert({temp, i});
    }
    sort(sorted.begin(), sorted.end());
    long long prev = -1, num = 0;
    for (auto e:sorted){
        if (prev==-1){
            //*Nothing has been counted yet so increase num. 
            num++;
        }
        else{
            
        }
    }


    /*
    //*Just have to count the maximum number of breaks that exist. 
    long long prev, num = 0;
    for (long long i=0;i<n;i++){
        long long temp;
        cin >> temp;
        if (i==0){
            num = 1;
        }
        else{
            if (temp>=prev){}
            else{
                num++;
            }
        }
        prev = temp;
    }
    if (num<=k){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
    */
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long t; cin >> t;
    while (t--){
        solve();
    }
}