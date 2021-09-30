#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin >> n;
    vector <vector <long long>> arr (n, vector <long long> (3));
    for (long long i=0;i<n;i++){
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
        //*Just brute forces I guess
        //!Just make everything inclusive. 
        if (arr[i][0]==2){
            arr[i][2]--;
        }
        else if (arr[i][0]==3){
            arr[i][1]++;
        }
        else if (arr[i][0]==4){
            arr[i][1]++;
            arr[i][2]--;
        }
    }
    long long result = 0;
    //cout << arr.size() << endl;
    for (long long i=0;i<n;i++){
        for (long long j=i+1;j<n;j++){
            //*Need to check whether the values are in between. 
            if ((arr[i][2]>=arr[j][1] && arr[i][2]<=arr[j][2]) || (arr[j][2]>=arr[i][1] && arr[j][2]<=arr[i][2])){
                result++;
            }
        }
    }
    cout << result << endl;
}