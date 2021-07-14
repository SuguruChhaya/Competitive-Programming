#include <bits/stdc++.h>

using namespace std;

int main(){
    //*Generating all possibilities seems to be 10^11 so TLE. 
    //*Maybe use a vector and keep track of the starting and ending?.
    //!'a' is 97. 

    long long t;
    cin >>t;
    
    for (long long i=0;i<t;i++){
        string s;
        cin >> s;
        /*
        vector <char> arr;
        for (long long j=0;j<s.size();j++){
            arr.push_back(' ');
        }
        */
        //!I don't think I have to create it on my own...
        bool ok = true;
        map <char, long long> d;
        for (long long j=0;j<s.size();j++){
            //*If the same character already exists we know it is bad. 
            if (d.count(s[j])==1){
                ok = false;
                //cout << "NO" << endl;
                break;
            }
            else{
                d.insert({s[j], j});
            }
        }
        long long l, r;
        //*Loop through all the lowercase and check where it is located. 
        for (long long j=0;j<s.size();j++){
            //*The char is (char) (97+j)
            if (d.count((char) (97+j))==1){
                if (j==0){
                    l = r =d['a'];
                }
                else{
                    //*Check whether location matches. 
                    if (d[(char) (97+j)] == l-1){
                        l--;
                    }
                    else if (d[(char) (97+j)] == r+1){
                        r++;
                    }
                    else{
                        ok = false;
                        break;
                    }
                }
            }
            else{
                ok = false;
                break;
            }
        }

        if (ok){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
        
    }

}