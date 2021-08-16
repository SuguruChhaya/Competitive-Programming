#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n, x;
    cin >> n >> x;
    vector <long long> arr(n);
    //*There could be multiple. so store in a vector. 
    map <long long, long long> d = {{0, 1}};

    for (long long i=0;i<n;i++){
        //*Instead of writing long long temp; cin >> temp; push_back, if I allocate and assign it is way less code.
        cin >> arr[i];

    }
    long long prefix_sum = 0;
    long long ans = 0;
    //!Having to check whether it is in a smaller index is a pain so better to have a guarantee that it is smaller. 
    for (long long num:arr){
        prefix_sum+=num;
        ans += d[prefix_sum-x];
        d[prefix_sum]++;
    }

    cout << ans << endl;
    /*
    for (long long i=1;i<=n;i++){
        long long temp;
        cin >> temp;
        arr.push_back(temp);
        
        if (i==0){
            prefix.push_back(temp);
        }
        else{
            prefix.push_back(prefix[i-1]+temp);
        }
        
        prefix.push_back(prefix[i-1]+temp);

        //*Check whether the current sum exists. 
        //!I don't need to check whether it exists or not. 
        if (d.count(prefix[i])==1){
            d[prefix[i]]++;
        }
        else{
            d.insert({prefix[i], 1});
        }
    } 
    */
    //!My idea is correct. However, I don't need to store an array. 
    //*I just need to add the number 
    //*Loop through the prefix sum. 
    /*
    for (long long i=1;i<=n;i++){
        if (d.count(prefix[i]-x)){
            for (auto index:d[prefix[i]-x]){
                if (index<)
            }
        }

    }
    */
   /*
    for (auto p:d){
        if (d.count(p.first-x)){

        }
    }
    */

}