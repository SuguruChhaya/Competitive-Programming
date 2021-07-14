#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin >> s;
    vector <char> original;
    //!Cannot use a set because there could be repeating elements. 
    for (auto c:s){
        original.push_back(c);
    }
    deque <pair <string, vector <char>>> q = {{"", original}};
    pair <string, vector <char>>curr;
    set <string> result;
    while (!q.empty()){
        curr = q[0];
        //  cout << q.size() << endl;
        q.pop_front();

        if (curr.first.size() == s.size()){
            //*Just never passes this point. WHY?
            result.insert(curr.first);
        }
        else{
            for (long long i=0;i<curr.second.size();i++){
                auto next = curr;
                next.first.push_back(curr.second[i]);
                next.second.erase(next.second.begin()+i);

                q.push_back(next);
            }
        }
    }

    cout << result.size() << endl;
    for (auto s: result){
        cout << s << endl;
    }
}

//*Interesting approach of doing recursion stuff but not using much extra data by placing back after fully explored. 
//*Maybe I could apply this with a DMOJ problem that I MLEd. 