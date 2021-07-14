#include <bits/stdc++.h>

using namespace std;

int main(){
    //*I feel like I need to count the number of characters and deduce the which string fits the missing amount. 

    long long t;
    cin >> t;
    


    for (long long i=0;i<t;i++){
        long long n, m;
        cin >> n >> m;
        //*Some strings may have the same number of each letter: ekek and keke. But if that is the case, we next have to look at the positions. 
        vector <vector <long long>> arr;
        for (long long j=0;j<26;j++){
            vector <long long> temp;
            for (long long k=0;k<m;k++){
                temp.push_back(0);
            }
            arr.push_back(temp);
        }

        for (long long j=0;j<n;j++){
            string s;
            cin >> s;
            for (long long k=0;k<m;k++){
                arr[((int) (s[k])) - 97][k]++;
            }
        }

        for (long long j=0;j<n-1;j++){
            string s;
            cin >> s;
            for (long long k=0;k<m;k++){
                arr[((int) (s[k])) - 97][k]--;
            }
        }
        //*Construct the final string. 
        string result;
        for (long long j=0;j<m;j++){
            result.push_back('.');
        }

        for (long long j=0;j<26;j++){
            for (long long k=0;k<m;k++){
                if (arr[j][k]==1){
                    result[k] = (char) (97+j); 
                }
            }
        }

        cout << result << endl;

    }
}