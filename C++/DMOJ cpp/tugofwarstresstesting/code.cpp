#include <bits/stdc++.h>
using namespace std;



int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    long long n;
    cin >> n;
    static vector <long long> arr, prefix_sum;
    for (long long i=0;i<n;i++){
        long long temp;
        cin >> temp;
        arr.push_back(temp);
        if (i==0){
            prefix_sum.push_back(temp);
        }
        else{
            prefix_sum.push_back(temp+prefix_sum[i-1]);
        }
    }

    //*Since circular, double the array size. 
    for (long long l=0;l<n;l++){
        //*Make it a double?
        arr.push_back(arr[l]);
        //*Keep adding it on the prefix sum. 
        prefix_sum.push_back(arr[l]+prefix_sum[n+l-1]);

    }


    static vector <long long> result_arr;

    //*Store the previous optimal splitting point. 
    //*Once the absolute value starts increasing compared to prev, I can stop. 
    long long index = 0;
    
    for (long long l=0;l<n;l++){
        //!Just reusing right?
        long long prev = 9999999999999;
        if (l==0){
            //*I need to first calculate in the normal way. 
            //*Store the prev

            while (index < (2*n) && abs(prefix_sum[index]-prefix_sum[n-1]+prefix_sum[index]) < prev){
                prev = abs(prefix_sum[index]-prefix_sum[n-1]+prefix_sum[index]);
                index++;
            }
            //*Went 1 too far. 
            index--;

        }
        else{
            //*Just that I need to subtract a prefix sum index. 
            //!Calculation for team a is wrong. 
            //long long team_a = prefix_sum[index]-prefix_sum[l]+arr[l];
            while (index < (2*n) && abs(prefix_sum[index]-prefix_sum[l]+arr[l] - prefix_sum[n-1]+prefix_sum[index]-prefix_sum[l]+arr[l]) < prev){
                prev = abs(prefix_sum[index]-prefix_sum[l]+arr[l] - prefix_sum[n-1]+prefix_sum[index]-prefix_sum[l]+arr[l]);
                index++;
                //!Once I update index, it could cause a seg error (if index is out of range).
            }
            index--;
        }
        if (l==0){
            cout << prev;
        }
        else{
            cout << " " << prev;
        }
    }
    cout << endl;

}
