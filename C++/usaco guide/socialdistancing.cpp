#include <bits/stdc++.h>
using namespace std;

int main(){
    //!This problem is definitely in the same category as the stuck in a rut problem by how annoying it is and the small details I have to pay attention to. 
    
    //freopen("socdist1.in", "r", stdin);
    //freopen("socdist1.out", "w", stdout);
    long long n;
    cin >> n;
    string s;
    cin >> s;
    //*Cannot just simulate all of the places. 
    //*Have to choose a specific placing. 
    //*Either the 2 cows go into the largest 2 gaps or it goes into the largest (when there is only one gap or the smallest and largest have big gap)
    
    //*Detect all the subsequence length. 
    vector <long long> arr;
    //long long curr = 0;
    /*
    for (long long i=0;i<n;i++){
        if (s[i]=='1'){
            if (curr != 0){
                //!curr==0 is actually a very valid case since it just means the distance is 0. 
                //*Have to add it. 
                arr.push_back(curr);
            }
            curr = 0;
        }
        else{
            curr++;
        }
    }
    */
    long long prev = -1;
    //long long temp = 999999999;
    for (long long k=0;k<n;k++){
        if (s[k]=='1'){
            if (prev!=-1){
                //*Check the distance. 
                //!I could do this based on distance or based on consecutive zeros. 
                //*for consistency, I want 0s. 
                //temp = min(temp, k - prev);
                arr.push_back(k-prev);
            }
            prev = k;
        }
    }
    //*Need to consider the endiing. 
    //!I don't think so because we are looking for distance betwen. 
    /*
    if (curr !=0){
        arr.push_back(curr);
    }
    */
    /*
    for (auto e:arr){
        cout << e << endl;
    }
    */
    
    sort(arr.begin(), arr.end());
    long long gap=0;
    auto v1 = arr, v2 = arr;
    bool one = false;
    //!There will be at least 2 open spots 
    //*Some edge cases to consider:
    //00000000
    //100000001
    //000000010100000000

    //*In the initial stage of collecting distances, will I collect based on valid sandwiches or contiguous 0s?
    //!Honestly, I feel like I should just build an imperfect solution and stress test the shit out of it. 
    //*Or consider the edges in a 
    //*Or generate a list of all the ones I could place at. 
    if (arr.size()>=2){
        //*Can try doing to both. 
        //*Not necessary the divided one will become the smallest. 
        v1[arr.size()-1] += 1;
        v1[arr.size()-1] /= 2;
        v1[arr.size()-2] += 1;
        v1[arr.size()-2] /= 2;
        //gap= min((arr[arr.size()-1]-1) / 2, (arr[arr.size()-2]-1) / 2);
        //*Need to check whether it becomes smaller than the first one. 
        //*
        sort(v1.begin(), v1.end());
        one = true;
    }
    //gap = max(gap, (arr[arr.size()-1] - 2) / 3);
    v2[arr.size()-1] += 1;
    v2[arr.size()-1] /= 3;
    sort(v2.begin(), v2.end());
    /*
    for (auto e:v1){
        cout << e << endl;
    }
    */

    /*
    for (auto e:v2){
        cout << e << endl;
    }
    */
    
    if (one){
        cout << max(v1[0], v2[0]) << endl;
    }
    else{
        cout << v2[0] << endl;
    }
    //cout << gap << endl;
}