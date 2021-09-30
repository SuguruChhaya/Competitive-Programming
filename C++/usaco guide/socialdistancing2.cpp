#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("socdist2.in", "r", stdin);
    freopen("socdist2.out", "w", stdout);
    long long n;cin >> n;
    //*Sort the vector later so that I get it in number line form. 
    vector <vector <long long>> arr(n, vector <long long> (2, 0));
    vector <vector <long long>> infected;
    for (long long i=0;i<n;i++){
        cin >> arr[i][0] >> arr[i][1];
        /*
        if (arr[i][1]==1){
            infected.push_back({arr[i], i});
        }
        */
    }
    sort(arr.begin(), arr.end());
    //!I think this infected thing is what is causing issues. 
    //*Basically it just keeps things in the original order. 
    //*Instead, sort it based on arr[i][0] and then keep the i so that I still know where it is located. 

    //sort(infected.begin(), infected.end());
    long long large = 999999999, maxr = large;
    //Have to consider the case where all cows are infected and no cows are infected. 
    bool healthyexists = false;
    for (long long i=0;i<n;i++){
        if (arr[i][1]==0){
            healthyexists=true;
            //*Actually, if the non-infected cow doesn't have any non-infected neighbors, that means there must still be healthy cows with infected neighbors. 
            //So don't have to worry about that. 
            //*Actually have to check whether there is cow to the left or right so need to loop by index. 
            if (i-1>=0 && arr[i-1][1]==1){
                maxr = min(maxr, arr[i][0]-arr[i-1][0]-1);
            }
            if (i+1<n && arr[i+1][1]==1){
                maxr = min(maxr, arr[i+1][0]-arr[i][0]-1);
            }

        }
    }

    if (maxr==large){
        //*Either all infected or all are healthy. 
        if (healthyexists){
            cout << 0 << endl;
        }
        else{
            cout << n << endl;
        }
    }
    else{
        //*I have to ignore the healthy cows when detecting clusters. 
        //!Maybe keep vector of index of infected. 
        long long result =0;
        /*
        for (auto e:arr){
            cout << e[0] << e[1] << endl;
        }
        for (auto e:infected){
            cout << e<< endl;
        }
        */
        /*
        for (long long i=0;i<infected.size()-1;i++){
            if (arr[infected[i]][0]+maxr>=arr[infected[i+1]][0]){
                //
            }
            else{
                result++;
            }
        }
        result ++;
        cout << result << endl;
        */

        //!Just use pointers to exclude the others. 
        long long prev = 0, curr = 1;
        while (curr <n){
            if (arr[curr][1]==1){
                if (arr[prev][0]+maxr<arr[curr][0]){
                    result++;
                }
                prev = curr;
            }
            curr++;
        }
        result++;
        cout << result << endl;

    }
}