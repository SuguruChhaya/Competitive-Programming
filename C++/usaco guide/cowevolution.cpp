#include <bits/stdc++.h>
using namespace std;

long long n;
//!An array of vectors! Stupid I idea. So much inconsistency.
//https://stackoverflow.com/questions/26073735/square-brackets-in-vectors

vector <vector <string>> characteristics;
vector <string> all_characteristics;

bool crossing(long long a, long long b){
    //*Honestly, I think I can set these as bools instead of long long. 
    //!It is not possible to have only has_a == true or has_b==true. They both have to be true after looping through all the cows. 
    //*If has_a==true and has_b==true, none of the cows have both the characteristics. e.g. split into a and b -> These are disjoint. 
    //*If there is ab==true and has_a == true (e.g. there is a and one branch develops B but other branch doesn't develop anything), the pairs are nested but not crossing. 
    //*Really the definition of crossing is where one element has only A, another element has only B, and last element has both A, B. 
    bool A=0, B=0, AB=0;
    for (long long i=0;i<n;i++){
        bool has_a =0, has_b = 0;
        for (auto e:characteristics[i]){
            if (e==all_characteristics[a]){
                has_a = 1;
            }
            if (e==all_characteristics[b]){
                has_b=1;
            }
        }
        if (has_a&&has_b){
            AB = 1;
        }
        else if (has_a){
            A = 1;
        }
        else if (has_b){
            B = 1;
        }
    }
    return AB==1 && A==1 && B==1;
    
}

int main(){
    //*Basically we are tracking the ancestors and seeing how they could have formed. 
    //!No 2 identical: if there were then I guess they evolved in different orders so it would be considered not proper. 
    //!REALLY hard graph problem: basically if 2 characteristics are "crossing" then it is not proper. However, if it is disjointed or nested, it is possible. 

    freopen("evolution.in", "r", stdin);
    freopen("evolution.out", "w", stdout);
    //*First push back to characteristics. 
    for (long long i=0;i<25;i++){
        characteristics.push_back({});
    }

    cin >> n;
    for (long long i=0;i<n;i++){
        long long k;
        cin >> k;
        for (long long j=0;j<k;j++){
            string s;
            cin >> s;
            //*Won't I just be pushing back strings to strings?? What is the point of doing that??
            //!Recording that specific cow. 
            characteristics[i].push_back(s);
            //!Characteristics is some weird kind of data structure...
            //bool found = false;
            //!Recording all the characteristics. 
            //*Can't I do this using a set? 
            //!Seems like index is important factor.
            
            bool found = false;
            for (auto e:all_characteristics){
                if (e==s){
                    found = true;
                    break;
                }
            }

            if (found==false){
                all_characteristics.push_back(s);
            }
            /*
            for (auto e:characteristics){
                length++;
            }
            cout
            */
        }
    }
    long long m = all_characteristics.size();
    bool ok= true;
    for (long long a=0;a<m;a++){
        for (long long b=a+1;b<m;b++){
            if (crossing(a, b)){
                ok = false;
                break;
            }
        }
    }

    if (ok){
        cout << "yes" << endl;
    }
    else{
        cout << "no" << endl;
    }
}