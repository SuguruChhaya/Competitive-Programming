#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n, k;
    cin >> n >> k;
    vector <pair<long long, long long>> greedy;
    vector<long long> arr (n);
    for (long long i=0;i<n;i++){
        cin >> arr[i];
    }
    arr.push_back(0);
    sort(arr.begin(), arr.end(), greater<long long>());
    long long currYear = arr[0]+12-arr[0]%12;
    //*<= because adding 0. 
    greedy.push_back({0, currYear});
    //!For simplicity, I can add 0 moving down to 
    for (long long year=0;year<=n;year++){
        
        //?Why does it automatically jump to 101?
        //!Should jump to 108
        if (arr[year]>currYear-(currYear%12)){
            currYear = arr[year];
        }  
        else{
            currYear -= currYear % 12;
            if (currYear-arr[year]<12){
                currYear = arr[year];
            }
            else{
                long long jumpYear ;
                if (arr[year]==0){
                    jumpYear = 0;
                }
                else{
                    jumpYear = arr[year]+(12-arr[year]%12);
                }
                
                greedy.push_back({currYear, jumpYear});
                currYear=arr[year];
            }
        }
        
    }
    /*
    for (auto p:greedy){
        cout << p.first << " " << p.second << endl;
    }
    */

    long long years = 0;
    vector <long long> timeArr;
    for (long long j=0;j<greedy.size();j++){
        if (j!=0){
            //!Make sure the result is +ive
            years+=greedy[j-1].second-greedy[j].first;
        }
        timeArr.push_back(greedy[j].first-greedy[j].second);
    }
    /*
    cout << endl;
    for (auto e:timeArr){
        cout << e << endl;
    }
    */

    sort(timeArr.begin(), timeArr.end());
    long long index = 1;
    //!The first move is going back in time so ignore it. 
    while(timeArr.size()-index+1>k){
        years-=timeArr[index];
        index++;
    }
    cout << years << endl;
    //!Gives out a crazy negative number. 
}