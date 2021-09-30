#include <bits/stdc++.h>
using namespace std;

int main(){
    //*Have a feeling that it would be most beneficial to either remove as many as possible or remove one by one. 

    long long t;
    cin >> t;

    for (long long i=0;i<t;i++){

        //!OK so test 1 did pass. 

        long long n, a, b;
        cin >> n >> a >> b;
        string s;
        cin >> s;
        //*I need to count number of subsequent. 
        //!Oh that is just the length lol. 


        //!Something I am not considering I guess. 
        if (b > 0){
            //*We know we should divide one by one. 
            cout << (a+b) * n << endl;
        }
        else{
            long long numBlocks = 0;
            
            for (long long j=1;j<n;j++){

                if (s[j]!=s[j-1]){
                    numBlocks++;
                }
            }
            numBlocks++;

            cout << a * n + b * (numBlocks/2+1) << endl;
        }

    }
}