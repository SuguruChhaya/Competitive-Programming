#include <bits/stdc++.h>
using namespace std;

int main(){
    long long t;
    cin >> t;
    for (long long t1=0;t1<t;t1++){
        long long n;
        cin >> n;
        vector <long long> arr(n+1);
        arr[0] = 0;
        for (long long i=1;i<=n;i++){
            cin >> arr[i];
        }
        //long long ans = 0;
        sort(arr.begin(), arr.end());
        //!By adding the element itself into the array, we are simulating that there is a 0. 
        set<long long> expanded;
        for (long long i=0;i<=n;i++){
            for (long long j=i+1;j<=n;j++){
                expanded.insert(arr[j]-arr[i]);
            }
        }
        //cout << expanded.size() << endl;
        set <vector <long long>> ans;
        for (auto a:expanded){
            for (auto b:expanded){
                for (auto c:expanded){
                    if (a<=b && b<=c){
                        set <long long> all = {a, b, c, a+b, a+c, b+c, a+b+c};
                        bool ok = true;
                        //!We have to make sure we don't check 0. 
                        for (auto num:arr){
                            if (num!=0 && !all.count(num)){
                                ok = false;
                                break;
                            }
                        }
                        if (ok){
                            ans.insert({a, b, c});
                        }
                    }
                }
            }
        }
        cout << ans.size() << endl;
    }
}