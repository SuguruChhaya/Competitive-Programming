#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin >> n;
    //!Try after come back from run. 
    vector <long long> available(n), arr(n, 0);
    for (long long i=0;i<n;i++){
        cin >> available[i];
        if (available[i]==1 || available[i]==2){
            if (i>0&&available[i-1]!=available[i]){
                arr[i] = available[i];
            }
        }
    }
    for (long long i=0;i<n;i++){
        if (available[i] ==3){
            bool gym=true, contest = true;
            if (i>0){
                if (available[i-1]==1){
                    contest = false;
                }
                else if (available[i-1]==2){
                    gym = false;
                }
            }
            if (i<n-1){
                if (available[i+1]==1){
                    contest = false;
                }
                else if (available[i+1]==2){
                    gym = false;
                }
            }
            if (gym && contest){

            }
            else if (contest){
                arr[i] = 1;
            }
            else if (gym){
                arr[i] = 2;
            }
        }
        
    }

    for (long long i=n-1;i>=0;i--){
        if (available[i] ==3){
            bool gym=true, contest = true;
            if (i>0){
                if (available[i-1]==1){
                    contest = false;
                }
                else if (available[i-1]==2){
                    gym = false;
                }
            }
            if (i<n-1){
                if (available[i+1]==1){
                    contest = false;
                }
                else if (available[i+1]==2){
                    gym = false;
                }
            }
            if (gym && contest){

            }
            else if (contest){
                arr[i] = 1;
            }
            else if (gym){
                arr[i] = 2;
            }
        }
        
    }

    for (long long i=0;i<n;i++){
        if (arr[i]==3){
            //*this time just do whatever. 
            bool contest = true, gym = true;
            if (i>0){
                if (available[i-1]==1){
                    contest = false;
                }
                else if (available[i-1]==2){
                    gym = false;
                }
            }
            if (i<n-1){
                if (available[i+1]==1){
                    contest = false;
                }
                else if (available[i+1]==2){
                    gym = false;
                }
            }

            if (contest){
                arr[i] = 1;
            }
            else if (gym){
                arr[i] = 2;
            }
        }
    }

    long long result = 0;
    for (auto e: arr){
        if (e==0){
            result ++;
        }
    }
    cout << result << endl;
}