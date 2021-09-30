#include <bits/stdc++.h>
using namespace std;

int main(){
    //*Another interesting On^2 
    long long n, x;
    cin >> n >> x;
    vector <vector <long long>> arr(n, vector <long long>(2));
    for (long long i=0;i<n;i++){
        cin >> arr[i][0];
        arr[i][1] = i;
    }
    sort(arr.begin(), arr.end());

    for (long long i=0;i<n;i++){
        long long left = 0, right = n-1;
        while (left<=right){
            if (left!=right && right!=i && left != i && arr[i][0]+arr[left][0]+arr[right][0]==x){
                //*But if I place everything under this loop, things will be stuck. 
                cout << arr[i][1]+1 << " " << arr[left][1]+1 << " " << arr[right][1]+1 << endl;
                return 0;
            }
            else if (arr[i][0]+arr[left][0]+arr[right][0]<x){
                left++;
            }
            else{
                right--;
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
}