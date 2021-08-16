#include <bits/stdc++.h>
using namespace std;

vector <vector <long long>> getMatch(vector <long long> l){
    vector <vector <long long>> matches (3, vector <long long>(l.size()+1, 0));
    //https://www.codegrepper.com/code-examples/cpp/initialize+2d+vector+c%2B%2B+to+zero
    /*
    for (long long i=0;i<3;i++){
        vector <long long> temp;
        for (long long j=0;j<l.size()+1;j++){
            temp.push_back(0);
        }
        matches.push_back(temp);
    }

    for (long long )
    */
    //*Actually pretty similar to what I did except 1-indexed. 
    for (long long i=0;i<l.size();i++){
        for (long long j=0;j<3;j++){
            matches[j][i+1] = matches[j][i];
        }
        //!We are first copying and then adjusting. 
        matches[l[i]][i+1]++;
    }

    return matches;



}

int main(){
    //!Learning implementation techniques from nick wu.
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);

    long long n;
    cin >> n;
    //*Creating a reversed vector? WHY??



    vector <long long> l, lr;
    for (long long i=0;i<n;i++){
        char s;
        cin >> s;
        if (s=='H'){
            l.push_back(0);
        }
        else if (s=='P'){
            l.push_back(1);
        }
        else if (s=='S'){
            l.push_back(2);
        }
        lr.push_back(l[i]);
    }   
    //*Just reverse it. 
    reverse(lr.begin(), lr.end());
    //*l is just the array that tells which element. 
    auto matchPrefix = getMatch(l);
    auto matchSuffix = getMatch(lr);
    //*making a reverse version makes the calculations easier. 
    long long result = 0;
    for (long long i=0;i<3;i++){
        for (long long j=0;j<3;j++){
            for (long long k=0;k<n;k++){
                //!The 1-indexed can be used here for a nicer implementation!!
                result = max(result, matchPrefix[i][k] + matchSuffix[j][n-k]);
            }
        }
    }

    cout << result << endl;
}