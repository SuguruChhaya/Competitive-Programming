#include <bits/stdc++.h>
using namespace std;

int main(){
    //!Let me at least try to implement a brute force. Maybe some idea might arise from there.
    cin.sync_with_stdio(0);
    cin.tie(0);
    long long t;
    cin >> t;
    for (long long i=0;i<t;i++){
        long long n, k;
        cin >> n >> k;
        vector <long long> arr;
        for (long long j=0;j<n;j++){
            long long temp;
            cin >> temp;
            arr.push_back(temp);
        }

        long long result = -99999999999999999;
        for (long long a=1;a<=n;a++){
            for (long long b=a+1;b<=n;b++){
                result = max(result, (a) * (b) - k*(arr[a-1]|arr[b-1]));
            }
        }
        cout << result << "\n";
    }
    //*Want to minimize a_i | a_j. 
    //*This means we want to pair up zeros with zeros. 

    //!I don't think it is necessarily "smallest difference". 
    //*Because 3 and 4 are small but if I do bitwise or it becomes 7. 
    //*So do I have to pair up everything now?

    //*The fact that all integers are in the range of 0 to n seems fishy. k can be at max 100. If n is smaller, k is equal to n. Really sus conditions. 

     
    
}