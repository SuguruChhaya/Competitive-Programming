#include <bits/stdc++.h>
using namespace std;

int main(){
    long long x, n;
    cin >> x >> n;
    vector <vector <long long>> arr (n, vector <long long> (2));
    vector <bool> drunk(n, 0);
    for (long long i=0;i<n;i++){
        cin >> arr[i][0] >> arr[i][1];
    }
    bool ok = true;
    long long result =0, currTime = 0;

    //!Create another brute force because correct.cpp is doing probably incorrect things. 
    while (ok){
        ok = 0;
        long long pick;
        long long min_wait = 999999999, min_fresh = 999999999;
        for (long long i=0;i<n;i++){
            if (drunk[i]==0 && currTime <= arr[i][1]){
                if (arr[i][0]-currTime<=x){
                    if (min_wait != 0 || (min_wait==0 && arr[i][1]<min_fresh)){
                        ok=1;
                        pick=i;
                        min_wait=0;
                        min_fresh=arr[i][1];
                    }
                }
                else{
                    if (arr[i][0]-currTime-x==min_wait){
                        //*I think this is the correct comparison and definition of min_wait
                        if (arr[i][1]<min_fresh){
                            ok=1;
                            pick=i;
                            min_fresh = arr[i][1];
                        }
                    }
                    else if (arr[i][0]-currTime-x<min_wait){
                        ok = 1;
                        pick=i;
                        min_wait = arr[i][0]-currTime-x;
                        min_fresh = arr[i][1];
                    }
                }
            }
        }
        if (ok){
            //*Have to count the time it takes to finish the soup. 
            currTime+=min_wait+1;
            drunk[pick] = 1;
            result++;
        }
        else{
            break;
        }
    }
    cout << result << endl;
}