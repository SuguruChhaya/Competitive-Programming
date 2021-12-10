#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("measurement.in", "r", stdin);
    //freopen("measurement.out", "w", stdout);
    long long n, g;
    cin >> n >> g;
    vector <long long> arr (n+1, g);
    //!arr size shouldn't be n+1 but in range 10^9. So ditch the idea of storing all the values. 
    vector <vector <long long>> measurements (n, vector<long long>(3));
    for (long long i=0;i<n;i++){
        cin >> measurements[i][0] >> measurements[i][1] >> measurements[i][2];
    }
    sort(measurements.begin(), measurements.end());
    long long ans = 0;
    set <long long> prev;
    long long currMax = g;
    for (auto e:measurements){
        arr[e[1]]+=e[2];
        if (prev.count(e[1])){
            //*Was included, remove. 
            //!Check whether it increased or decreased from total. 
            //!Have to check whether it is the only one. 
            if (prev.size()==1){
                //!We cannot simply just assume. 
                if (arr[e[1]]>currMax){
                    currMax = arr[e[1]];
                }
                else{
                    //*If it gets smaller, naive way is to just look for the smallest. 
                    long long currMin = 99999999999;
                    vector <long long> minIndex;
                    for (long long i=0;i<n;i++){

                    }
                }
                currMax = arr[e[1]];
            }
            else{
                ans++;
                if (arr[e[1]]>currMax){
                    currMax = arr[e[1]];
                    prev = {e[1]};
                }
                else{
                    prev.erase(e[1]);
                    
                }
            }
        }
        else if (arr[e[1]]==currMax){
            ans++;
            prev.insert(e[1]);
        }
        else if (arr[e[1]]>currMax){
            ans++;
            currMax = arr[e[1]];
            prev = {e[1]};
        }
        /*
        long long currMax = 0;
        vector <long long> maxIndex;
        for (long long i=0;i<n;i++){
            if (arr[i]>currMax){
                currMax = arr[i];
                maxIndex = {i};
            }
            else if (arr[i]==currMax){
                maxIndex.push_back(i);
            }
        }
        if (prev!=maxIndex){
            ans++;
        }
        prev = maxIndex;
        */
    }
    cout << ans << endl;
}