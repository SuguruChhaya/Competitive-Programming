#include <bits/stdc++.h>

using namespace std;
int main(){
    //*Cannot generate all subarrays because 10^5. 
    //*Need a linear solution. 
    long long t;
    cin >> t;

    for (long long i=0;i<t;i++){
        vector <long long> arr;
        vector <long long> prefix_sum;
        long long n;
        cin>>n;
        string s;
        cin >> s;
        
        //*Quadratic might work. 
        for (long long j=0;j<n;j++){
            string temp_string;
            temp_string.push_back(s[j]);
            long long temp = stoi(temp_string);
            arr.push_back(temp);
            if (j==0){
                prefix_sum.push_back(0);
            }
            else{
                prefix_sum.push_back(prefix_sum[prefix_sum.size()-1]+temp);
            }
        }
        long long result = 0;
        for (long long a=0;a<n;a++){
            for (long long b=a;b<n;b++){
                if (prefix_sum[b]-prefix_sum[a]+arr[a]==b-a+1){
                    result++;
                }
                //*If the sum is already exceeding the length, there is no point checking others because it will just keep getting bigger. 
                if (prefix_sum[b]-prefix_sum[a]+arr[a] > n){
                    break;
                }
            }
        }
        cout << result << endl;
        //!Just stops for some reason. 
    }
}