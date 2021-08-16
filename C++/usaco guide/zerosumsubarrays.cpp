#include <bits/stdc++.h>
using namespace std;

long long solve(vector <long long> arr, long long n){
    long long result = 0, sum=0;
    set <long long> s;
    for (long long i=0;i<n;i++){
        sum+=arr[i];
        //*Now check the result. 
        //!If the sum is 0 then add. 
        if (sum==0){
            result++;
        }
        if (s.count(sum)==1){
            result++;
        }
        else{
            //*Add it to the hashset. 
            s.insert(sum);
            //
        }
    }
    return result;
}

int main(){
    long long n;
    cin >> n;
    vector <long long> arr;
    for (long long i=0;i<n;i++){
        long long temp;
        cin >> temp;
        arr.push_back(temp);
    }

    auto result = solve(arr, n);
    cout << result << endl;

}