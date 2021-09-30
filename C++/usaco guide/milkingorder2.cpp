#include <bits/stdc++.h>
using namespace std;
//!Kind of similar to the acowdemia 1 question in the sense that my code just gets complicated and more complicated until it doesn't work. 
//*Without testcases, there isn't a way that I can get to this point anyways. 
int main(){
	//freopen("milkorder.in","r",stdin);
	//freopen("milkorder.out","w",stdout);
    long long n, m, k;
    cin >> n >> m >> k;
    vector <long long> arr (n+1, 0);
    vector <long long> order (n);
    long long oneOrder = -1;
    for (long long i=0;i<m;i++){
        cin >> order[i];
        if (order[i]==1){
            oneOrder = i;
        }
    }
    bool found = false;
    long long prevOrder = -1;
    for (long long i=0;i<k;i++){
        long long c, p;
        cin >> c >> p;
        if (c==1){
            cout << p << endl;
            found = true;
        }
        arr[p]=c;
        

        for (long long j=0;j<m;j++){
            if (order[j]==c){
                long long currOrder = j-1,currIndex=p-1;
                while (currOrder>prevOrder){
                    if (arr[currIndex]==0){
                        arr[currIndex]=order[currOrder];
                        currOrder--;
                    }
                    currIndex--;
                }
                prevOrder = j;
            }
            
        }
    }
    /*
    for (auto e:arr){
        cout << e << endl;
    }
    */
    /*
    for (long long i=1;i<=n;i++){
        if (arr[i]==0){
            cout << i << endl;
            break;
        }
    }
    */
    if (found==false){
        if (oneOrder != -1){
            long long currOrder = 0, currIndex = 1;
            while (currOrder < oneOrder){
                if (arr[currIndex]==order[currOrder]){
                    currOrder++;
                }
                currIndex++;
            }
            for (long long i=currIndex;i<=n;i++){
                if (arr[i]==0){
                    cout << i << endl;
                    break;
                }
            }
        }
        else{
            for (long long i=1;i<=n;i++){
                if (arr[i]==0){
                    cout << i << endl;
                    break;
                }
            }
        }
    }
}