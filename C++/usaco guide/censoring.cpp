#include <iostream>
#include <vector>
using namespace std;

int main(){
    //*I should use space to indicate a deleted element and skip over that. 
    //*I should use 2 pointer to do the deletion. 
    //vector <char> curr;
    freopen("censor.in", "r", stdin);
    freopen("censor.out", "w", stdout);

    string s, t;
    cin >> s >> t;
    /*
    for (long long i=0;i<s.size();i++){
        curr.push_back(s[i]);
    }
    */
   
    bool existed = true;
    long long start_index, curr_index;
    //*The issue is that I might get like the "mississipi" example 
    //!Actually for this problem, I could just do brute force because the length is <=100 so it won't exceed time. 
    while (existed==true){
        existed = false;
        for (long long i=0;i<s.size()-t.size()+1;i++){
            //*Check only the starting point. 
            bool ok = true;
            for (long long j=0;j<t.size();j++){
                if (t[j]!=s[i+j]){
                    //*No point checking the rest. //!Never hits this point. 
                    ok = false;
                    break;
                }
            }
            //!We don't wanna check after each letter or no? 
            //*Actually, as soon as we get hit it is good to so we should check.
            string next;
            if (ok){
                //*I have still saved the i index so I can create an empty string and ignore certain interval. 
                for (long long j=0;j<s.size();j++){
                    if (j>=i && j<i+t.size()){
                        
                    }
                    else{
                        next.push_back(s[j]);
                    }
                }
                //*Assign the current to the next. 
                s = next;
                //*To prevent mess ups break from the forloop. 
                existed = true;
                break;
            }
            //!Keeps running for some reason...
        }

        //*Instead of worrying about spaces, I can construct a string every single time (hopefully will not TLE)

    }
    cout << s << "\n";
}