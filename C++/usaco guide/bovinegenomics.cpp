

//*I think if 1 trait appear in one of the sequence but not in the other than that is good in
//*No if the genetics are well separated then it counts I guess. 

#include <iostream>
#include <vector>
#include <map> 

using namespace std;

int main(){
    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);
    long long n, m;
    cin >> n >> m;
    vector <vector <long long>> spotty, plain;
    vector <long long> temp_vector;
    for (long long i=0;i<n;i++){
        string s;
        cin >> s;
        temp_vector = {};
        for (long long j=0;j<m;j++){
            temp_vector.push_back(s[j]);
        }
        spotty.push_back(temp_vector);
    }

    
    for (long long i=0;i<n;i++){
        string s;
        cin >> s;
        temp_vector = {};
        for (long long j=0;j<m;j++){
            temp_vector.push_back(s[j]);
        }
        plain.push_back(temp_vector);
    }
    long long result = 0;
    for (long long col=0;col<m;col++){
        map <char, bool> hashmap = 
        {
            {'A', 0}, 
            {'G', 0},
            {'C', 0},
            {'T', 0}
        };
        //*Can keep a table of whether visited or not. 
        //*Maybe a map. 
        for (long long spotty_row=0;spotty_row<n;spotty_row++){
            hashmap[spotty[spotty_row][col]] = 1;
        }
        bool ok = true;
        for (long long plain_row=0;plain_row<n;plain_row++){
            if (hashmap[plain[plain_row][col]]==1){
                ok = false;
                break;
            }
        }

        if (ok){
            result++;
        }
    }
    cout << result << endl;     
}