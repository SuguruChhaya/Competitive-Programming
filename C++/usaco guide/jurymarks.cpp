#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    long long n, k;
    cin >> k >> n;

    //*Basically there could have been a lot of pairings. 
    vector <long long> k_arr, prefix_sum;
    
    for (long long i=0;i<k;i++){
        
        long long temp;
        cin >> temp;
        k_arr.push_back(temp);

        if (i==0){
            prefix_sum.push_back(temp);
        }
        else{
            prefix_sum.push_back(prefix_sum[i-1]+temp);
        }
    }
    vector <long long> b_arr;
    for (long long i=0;i<n;i++){
        long long temp;
        cin >> temp;
        b_arr.push_back(temp);
    }

    //*There are many permutations but because of the increasing and decreasing, it has to have similar relationship. 
    //*Overcomplcating things. 
    //*We just need to know the starting number and then when we hit that, we can backtrack and find the previous. 


    //*So many spots the first one can come into. 
    //!Distinct integers actually help the case. So I can do set removal or something. 
    //*I guess I have to iterate through k not n since it is not guaranteed that there is an n at the first index. 
    //*But there should be b_0 at some point. 
    set <long long> starting;
    for (long long i=0;i<k;i++){
        starting.insert(b_arr[0]-prefix_sum[i]);
    }
    long long result = 0;
    for (auto element:starting){
        long long curr = element;
        set <long long> temp;
        //*Have to iterate through the prefix sum array anyways...
        for (long long i=0;i<k;i++){
            //*Iterate and check whether that point exists. 
            curr+=k_arr[i];
            //*Could be multiple spots so basically I just have to construct all and check whether exists. 
            temp.insert(curr);
        }
        bool ok = true;
        for (auto e:b_arr){
            if (temp.count(e)==0){
                ok = false;
                break;
            }
        }
        if (ok){
            result++;
        }
    }
    cout << result << endl;
}