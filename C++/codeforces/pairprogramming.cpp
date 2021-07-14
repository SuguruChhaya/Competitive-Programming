#include <bits/stdc++.h>

using namespace std;

int main(){
    //*So the sequence should make sense. 
    //!Adding a newline is always acceptable but the line must exists before editing the line. 
    //!Can't I just put all the newlines together and then make them edit? 
    //*Easiest solution + easy to know if there is no solution. 
    //*Has to maintain the initial order. 
    //*2^200 is tough but I could 
    //!I guess the best solution: if I have a choice to pick a 0, pick it. If I don't, check if the number is valid (or check it later). 
    long long t;
    cin >> t;
    for (long long i=0;i<t;i++){
        long long k, n, m;
        cin >> k >> n >> m;
        vector <long long> a;
        vector <long long> b;
        vector <long long> result;
        for (long long j=0;j<n;j++){
            long long temp;
            cin >> temp;
            a.push_back(temp);
        }
        for (long long j=0;j<m;j++){
            long long temp;
            cin >> temp;
            b.push_back(temp);
        }

        long long a_index =0;
        long long b_index = 0;

        //!Actually, better design in the while loop thingy. 
        while (a_index < n && b_index <m){
            if (a[a_index]==0){
                result.push_back(0);
                a_index++;
            }
            else if (b[b_index]==0){
                result.push_back(0);
                b_index++;
            }
            else{
                if (a[a_index] <= b[b_index]){
                    result.push_back(a[a_index]);
                    a_index++;
                }
                else{
                    result.push_back(b[b_index]);
                    b_index++;
                }
            }
        }

        while (a_index < n){
            result.push_back(a[a_index]);
            a_index++;
        }
        while (b_index < m){
            result.push_back(b[b_index]);
            b_index++;
        }

        long long currLine = k;
        bool ok = true;
        for (auto e:result){
            if (e==0){
                currLine++;
            }
            else{
                if (e <= currLine){}
                else{
                    ok = false;
                    break;
                }
            }
        }
        if (ok==false){
            cout << -1 << endl;
        }
        else{
            for (auto e:result){
                cout << e << " ";
            }
            cout << endl;
        }

    }
}