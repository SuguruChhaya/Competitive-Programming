#include <bits/stdc++.h>

using namespace std;

map <string, set<string>> d;

bool is_valid(vector <string> arr){
    //*Look through all the elements and find them. 

    /*
    for (auto iter = d.begin(); iter!=d.end();iter++){
        //*No idea whether the types here are working properly. 
        for (auto iter2: iter->second){
            for (long long i=0;i<arr.size();i++){
                if (arr[i]==iter->first){
                    //*Check the range. 
                    bool ok = false;
                    if (i>0){
                        if (arr[i-1]==iter->second){
                            ok = true;
                        }
                    }
                    if (i<arr.size()-1){
                        if (arr[i+1]==iter->second){
                            ok = true;
                        }
                    }

                    if (ok==false){
                        //*Since a single mismatch is wrong. 
                        return false;
                    }
                }
            }
        }
    }
    return true;
    */

    //*So first find the element. 
    for (auto iter = d.begin(); iter!=d.end();iter++){
        long long index;
        for (long long i=0;i<arr.size();i++){
            if (arr[i]==iter->first){
                index = i;
                break;
            }
        }

        for (auto element: iter->second){
            bool ok = false;
            if (index>0){
                if (arr[index-1]==element){
                    ok = true;
                }
            }
            if (index <arr.size()-1){
                if (arr[index+1]==element){
                    ok = true;
                }
            }

            if (ok==false){
                return false;
            }
        }
    }
    return true;
}

int main(){
    //!Just went back. HOW??

    //!Gave me a correct answer though...
    freopen("lineup.in", "r", stdin);
    freopen("lineup.out", "w", stdout);

    //!So many wrong answer...
    //*It shouldn't be just one key mapping. 
    //*Since cow A might be next to both cow b and c. 
    //*So I should just keep a set or something for multiple instructions. 

    long long n;
    cin >> n;
    //*I guess I could just brute force through and generate all permutations...
    //*But definitely should get some backtracking practice. 
    
    set <vector <string>> result;
    for (long long i=0;i<n;i++){
        vector <string> temp;
        for (long long j=0;j<6;j++){
            string s;
            cin >> s;
            if (j==0 || j==5){
                temp.push_back(s);
            }
        }
        //*Check whether exists or not. 
        if (d.count(temp[0])==1){
            d[temp[0]].insert(temp[1]);
        }
        else{
            d.insert({temp[0], {temp[1]}});
        }
    }
    set <string> original = {"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"};
    deque <pair <vector <string>, set <string>>> q = {{{}, original}};
    pair <vector <string>, set <string>> curr;

    while (!q.empty()){
        curr = q[0];
        q.pop_front();
        
        if (curr.first.size()==8){
            if (is_valid(curr.first)){
                result.insert(curr.first);
            }
        }
        else{
            //*Keep adding. 
            for (auto element: curr.second){
                auto next = curr;
                next.first.push_back(element);
                next.second.erase(element);
                q.push_back(next);
            }
        }
    }
    auto it = result.begin();
    vector <string> answer = *it;

    for (auto element: answer){
        cout << element << endl;
    }

    
}