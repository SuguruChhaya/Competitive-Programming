#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("cowdance.in", "r", stdin);
    freopen("cowdance.out", "w", stdout);
    long long n, t;
    cin >> n >> t;
    vector <long long> arr (n);
    for (long long i=0;i<n;i++){
        cin >> arr[i];
    }
    long long l = 0, r = n, ans = -1;
    while (l<=r){
        long long mid = (l+r) / 2;
        //cout << mid << endl;
        vector <long long> q;
        //Sort in descending order 
        for (long long i=0;i<mid;i++){
            q.push_back(arr[i]);
        }
        sort(q.begin(), q.end(), greater<long long>());
        //cout << "a" << endl;
        long long curr = mid, time = 0;
        while (curr<n){
            long long first = q[q.size()-1];
            time+= first;
            q.pop_back();
            for (long long i=0;i<q.size();i++){
                q[i]-=first;
            }
            //q.push_back(arr[curr]);
            //*Should be able to insert in the right position in linear time. 
            bool added = false;
            for (long long i=0;i<q.size();i++){
                //Since we are sorting in descending order, opposite direction. 
                if (q[i]<arr[curr]){
                    added = true;
                    q.insert(q.begin()+i, arr[curr]);
                    break;
                }
            }
            //sort(q.begin(), q.end(), greater<long long>());
            if (added==false){
                q.push_back(arr[curr]);
            }
            curr++;
        }
        //*After we use up all, just keep popping back
        //I can actually just remove the largest element. 
        long long currMax = 0;
        for (auto e:q){
            currMax = max(currMax, e);
        }
        time+=currMax;
        //cout << time << endl;
        if (time<=t){
            
            ans = mid;
            //Opposite of standard binary search
            r = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    cout << ans << endl;
}