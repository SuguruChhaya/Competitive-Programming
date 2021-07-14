#include <bits/stdc++.h>

using namespace std;

int main(){
    //*I think the point is to find 3 positions and all the orders in that is not inluded in the other
    //*Does 'G' and 'C' have to be in a specific order or they don't count or what?
    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);
    long long n, m;
    cin >> n >> m;

    //!Microefficiency...
    //*Could create hashmap instead of set if that helps...

    vector <vector <long long>> spotty, plain;
    for (long long i=0;i<n;i++){
        string s;
        cin >> s;
        vector <long long> temp_vector;
        for (long long j=0;j<m;j++){
            temp_vector.push_back(s[j]);
        }
        spotty.push_back(temp_vector);
    }

    for (long long i=0;i<n;i++){
        string s;
        cin >> s;
        vector <long long> temp_vector;
        for (long long j=0;j<m;j++){
            temp_vector.push_back(s[j]);
        }
        plain.push_back(temp_vector);
    }

    long long result = 0;

    map <vector <char>, bool> original;
    vector <char> genomes = {'A', 'C', 'G', 'T'};

    for (auto e1:genomes){
        for (auto e2:genomes){
            for (auto e3:genomes){
                if (original.count({e1, e2, e3})==0){
                    original.insert({{e1, e2, e3}, 0});
                }
                //*Otherwise already inserted so I don't have to do anything. 
            }
        }
    }

    for (long long col1 = 0;col1<m;col1++){
        for (long long col2=col1+1;col2<m;col2++){
            for (long long col3=col2+1;col3<m;col3++){
                //*No reverse pairs. 
                //*Need to store the permutations in a set. 
                /*
                set <vector <char>> spotty_set, plain_set;
                for (long long spotty_row=0;spotty_row<n;spotty_row++){
                    spotty_set.insert({spotty[spotty_row][col1], spotty[spotty_row][col2], spotty[spotty_row][col3]});
                }

                bool ok = true;
                for (long long plain_row=0;plain_row<n;plain_row++){
                    if (spotty_set.count({plain[plain_row][col1], plain[plain_row][col2], plain[plain_row][col3]})==1){
                        ok = false;
                        break;
                    }
                }
                if (ok){
                    result++;
                }
                */

                auto temp_map = original;
                for (long long spotty_row=0;spotty_row<n;spotty_row++){
                    temp_map[{spotty[spotty_row][col1], spotty[spotty_row][col2], spotty[spotty_row][col3]}]=1;
                }

                bool ok = true;
                for (long long plain_row=0;plain_row<n;plain_row++){
                    if (temp_map[{plain[plain_row][col1], plain[plain_row][col2], plain[plain_row][col3]}]==1){
                        ok = false;
                        break;
                    }
                }
                if (ok){
                    result++;
                }

            }
            
        }
    }
    cout << result << endl;
}