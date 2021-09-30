#include <bits/stdc++.h>
using namespace std;
long long n, q;
vector <long long> arr;
long long find_edge(long long target, bool smaller_than){
    long long l=0, r=n-1, result = -1;
    while (l<=r){
        long long mid = (l+r) / 2;
        if (arr[mid]==target){
            return mid;
        }
        else if (arr[mid]<target){
            if (smaller_than){
                result = mid;
            }
            l = mid+1;
        }
        else if (arr[mid]>target){
            if (!smaller_than){
                result = mid;
            }
            r = mid-1;
        }
    }
    return result;
}
int main(){
    freopen("haybales.in", "r", stdin);
    freopen("haybales.out", "w", stdout);
    cin >> n >> q;
    //*Obviously need to sort
    arr.resize(n);
    for (long long i=0;i<n;i++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    
    for (long long i=0;i<q;i++){
        long long a, b;
        cin >> a >> b;
        //*For the lowerbound, we want a haybale that is just above it. 
        long long x = find_edge(a, 0), y = find_edge(b, 1), result=0;
        if (x!=-1 && y!=-1){
            result+=y-x+1;
        }
        cout << result << endl;
        
    }
}