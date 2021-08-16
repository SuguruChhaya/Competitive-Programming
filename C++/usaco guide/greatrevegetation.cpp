#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    freopen("revegetate.in", "r", stdin);
    freopen("revegetate.out", "w", stdout);

    long long n, m;
    cin >> n >> m;

    //!How is the fact that no pasture is favorite of more than 4 cows help? 
    //*-> Because if it is favorite of 4 cows, there is a chance that one cannot be available. 
    //!I guess I could just store saying that these are not possible. 

    //!First create an adjacency set with extra length for 1-index. 
    vector <set <long long>> adjacency;
    for (long long i=0;i<n+1;i++){
        adjacency.push_back({});
    }

    for (long long i=0;i<m;i++){
        long long a, b;
        cin >> a >> b;
        //!Need to carefully understand what I am inserting here. 
        //*I am saying that it cannot be what the i-th pasture is and not the specific color. 
        adjacency[a].insert(b);
        adjacency[b].insert(a);
    }
    string result;
    //!Have to initialize this with values since we might go outside of index range. 
    //!1-index and I can print out the substring. 
    for (long long i=0;i<n+1;i++){
        result.push_back('9');
    }
    for (long long pasture = 1;pasture<=n;pasture++){
        for (long long bucket=1;bucket<=4;bucket++){
            bool ok = true;
            for (auto connected:adjacency[pasture]){
                //!Need to convert bucket to char. 
                if (result[connected]==to_string(bucket)[0]){
                    ok = false;
                    break;
                }
            }
            if (ok){
                result[pasture] = to_string(bucket)[0];
                break;
            }
        }
    }

    cout << result.substr(1, n) << endl;



}