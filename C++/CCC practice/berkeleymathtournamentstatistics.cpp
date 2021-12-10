#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n, q;
    cin >> n >> q;
    vector <long long> arr(n+1);
    vector <map<long long, long long>> freq(n+1);
    for (long long i=1;i<=n;i++){
        cin >> arr[i];
        freq[i] = freq[i-1];
        freq[i][arr[i]]++;
    }
    /*
    for (long long i=0;i<=n;i++){
        for (auto p:freq[i]){
            cout << p.first << " " << p.second << endl;
        }
        cout << endl;
    }
    */
    for (long long i=0;i<q;i++){
        long long l, r;
        cin >> l >> r;
        long long maxFreq = 0;
        vector <long long> scores;
        for (auto p:freq[r]){
            //cout << p.first << endl;
            if (freq[l-1].count(p.first)){
                long long temp = p.second-freq[l-1][p.first];
                if (temp>maxFreq){
                    maxFreq = temp;
                    scores = {p.first};
                }
                else if (temp==maxFreq){
                    scores.push_back(p.first);
                }
            }
            //*If it is not there, don't subtract
            else{
                if (p.second>maxFreq){
                    maxFreq = p.second;
                    scores = {p.first};
                }
                else if (p.second==maxFreq){
                    scores.push_back(p.first);
                }
            }
        }
        sort(scores.begin(), scores.end(), greater<long long>());
        cout << scores[0] << endl;
    }
}