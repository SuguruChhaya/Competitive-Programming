#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("socdist1.in", "r", stdin);
    freopen("socdist1.out", "w", stdout);
    long long n;cin >> n;
    string s;cin >> s;
    long long result = 0;
    for (long long i=0;i<n;i++){
        for (long long j=i+1;j<n;j++){
            //*Just check what happened for the correct answer. 
            /*
            if (i==2 && j==9){
                cout << "";
            }*/
            if (s[i]=='0' && s[j]=='0'){
                s[i] = '1';
                s[j] = '1';
                //cout << s<<endl;
                //!Just count the previous 1. 
                long long prev = -1;
                long long temp = 999999999;
                for (long long k=0;k<n;k++){
                    if (s[k]=='1'){
                        if (prev!=-1){
                            //*Check the distance. 
                            temp = min(temp, k - prev);
                        }
                        prev = k;
                    }
                }
                
                //cout << s[i];
                //cout << s;
                /*
                //*Now count the minimum. 
                long long temp = 9999999999;
                long long curr = 0;
                //!Honestly, I think a 2 pointer approach will be easier. 
                long long l=0, r=0;
                while (r < n){
                    if (s[r]=='1'){
                        //*If it is the first element, 
                        if (l!=0){
                            temp = min(temp, r-l-1);
                        }
                        l = r;
                    }
                    r++;
                }
                */
                /*
                for (long long k=0;k<n;k++){
                    //*I need to at least implement this detection system right. 
                    if (s[k]=='1' && k!=0){
                        temp = min(temp, curr);
                        curr = 0;
                    }
                    else{
                        curr++;
                    }
                }
                */
                result = max(result, temp);
                s[i] ='0';
                s[j] = '0';
            }
        }
    }
    cout << result << endl;
}