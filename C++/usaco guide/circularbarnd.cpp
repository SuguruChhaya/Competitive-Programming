#include <iostream>
#include <vector>
using namespace std;

int main(){
    freopen("cbarn.in", "r", stdin);
    freopen("cbarn.out", "w", stdout);
    //*Why did I fail the last couple??
    int n ,temp;
    cin >> n;
    vector <int> arr;
    for (int i=0;i<n;i++){
        cin >> temp;
        arr.push_back(temp);
    }
    
    for (int i=0;i<n;i++){
        arr.push_back(arr[i]);
    }

    //*I should just simulate for each door. 
    //*I guess it is way easier if I create double sized array and iterate over the first half.
    //!Big boys always use long long. 
    long long result = 9999999999999;
    long long curr;
    for (int i=0;i<n;i++){
        //*Open the ith door. 
        curr = 0;
        for (int j=i;j<i+n;j++){
            curr += arr[j] * (j-i);
        }
        result = min(result, curr);
    }

    cout << result << "\n";

}