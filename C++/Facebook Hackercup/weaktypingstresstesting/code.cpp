#include <bits/stdc++.h>
using namespace std;

void solve(){
    long long n;
    string s;
    cin >> n >> s;
    vector <long long> starting = {0}, ending;
    bool left = 0;
    long long curr =0, ans = 0;
    while (curr<n&&s[curr]=='F'){
        curr++;
    }
    if (curr!=n){
        if (s[curr]=='O'){
            left=1;
        }
        for (long long i=0;i<n;i++){
            if (left && s[i]=='X'){
                starting.push_back(i);
                left = 0;
            }
            else if (!left && s[i]=='O'){
                starting.push_back(i);
                left=1;
            }
        }
        starting.push_back(n);
        for (long long i=1;i<starting.size();i++){
            long long curr = starting[i]-1;
            while (curr>=0&&s[curr]=='F'){
                curr--;
            }
            //!Based on how I am structuring, there must be at least one X or O behind curr. 
            //*Want to end at that non-F location. 
            //*Cannot be smaller than 0. 
            //curr++;
            ending.push_back(curr);
        }

        //!ending is 1 shorter than starting. 
        for (long long i=0;i<ending.size();i++){
            long long before_ending = ending[i] - starting[i]+1;
            //?How will this size thing work 
            //!Think it should be <= because if there is 1 starting point, 2 blocks to compare.
            //!Not considering how many of the next ones exist. Just multiplying by 1 doesn't work.  
            for (long long j=i+1;j<starting.size()-1;j++){
                ans += before_ending * (j-i) * (starting[j+1]-starting[j]);
            }
            long long after_ending = starting[i+1]-ending[i]-1;
            for (long long j=i+1;j<starting.size()-1;j++){
                //!I didn't get a seg fault or anything??
                ans += after_ending * (j-i-1) * (starting[j+1]-starting[j]);
            }
        }
    }
    cout << (ans % 10000007) << endl;
}
int main(){
    /*
    long long t;
    cin >> t;
    while (t--){
        solve();
    }
    */
    solve();
}
/*
int main(){
    long long t;
    cin >> t;
    for (long long a=1;a<=t;a++){
        long long n;
        string s;
        cin >> n >> s;
        vector <long long> starting = {0}, ending;
        bool left = 0;
        long long curr =0, ans = 0;
        while (curr<n&&s[curr]=='F'){
            curr++;
        }
        if (curr!=n){
            if (s[curr]=='O'){
                left=1;
            }
            for (long long i=0;i<n;i++){
                if (left && s[i]=='X'){
                    starting.push_back(i);
                    left = 0;
                }
                else if (!left && s[i]=='O'){
                    starting.push_back(i);
                    left=1;
                }
            }
            starting.push_back(n);
            for (long long i=1;i<starting.size();i++){
                long long curr = starting[i]-1;
                while (curr>=0&&s[curr]=='F'){
                    curr--;
                }
                //!Based on how I am structuring, there must be at least one X or O behind curr. 
                //*Want to end at that non-F location. 
                //*Cannot be smaller than 0. 
                //curr++;
                ending.push_back(curr);
            }

            //!ending is 1 shorter than starting. 
            for (long long i=0;i<ending.size();i++){
                long long before_ending = ending[i] - starting[i]+1;
                //?How will this size thing work 
                //!Think it should be <= because if there is 1 starting point, 2 blocks to compare.
                //!Not considering how many of the next ones exist. Just multiplying by 1 doesn't work.  
                for (long long j=i+1;j<starting.size()-1;j++){
                    ans += before_ending * (j-i) * (starting[j+1]-starting[j]);
                }
                long long after_ending = starting[i+1]-ending[i]-1;
                for (long long j=i+1;j<starting.size()-1;j++){
                    //!I didn't get a seg fault or anything??
                    ans += after_ending * (j-i-1) * (starting[j+1]-starting[j]);
                }
            }
        }
        cout << "Case #" << a << ": " << (ans % 10000007) << endl;
    }
}
*/