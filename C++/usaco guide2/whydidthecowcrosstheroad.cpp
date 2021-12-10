#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("helpcross.in", "r", stdin);
    //freopen("helpcross.out", "w", stdout);
    //*When creating a brute force match-up, I have 4 choices: 
    //1. Pair the two and increment both. 2. Increment cow, 3. Increment chicken, 4. Increment both. 
    long long c, n;
    cin >> c >> n;
    vector <long long> chickens (c);
    vector <vector<long long>> cows(n, vector<long long>(2));
    for (long long i=0;i<c;i++){
        cin >> chickens[i];
    }
    for (long long i=0;i<n;i++){
        cin >> cows[i][0] >> cows[i][1];
    }
    //cout << "new" << endl;
    //*Information to store in the queue. 
    //1. the current pairs in vector <vector<long long>>
    //2. The current cow index
    //3. The current chicken index. 
    queue <tuple<vector<vector<long long>>, long long, long long>>q;
    q.push({{}, 0, 0});
    long long ans = 0;
    while (!q.empty()){
        auto curr = q.front();
        q.pop();
        long long temp = get<0>(curr).size();
        if (temp>ans){
            ans = max(temp, ans);
            /*
            for (auto e:get<0>(curr)){
                cout << e[0] << " " << e[1] << endl;
            }
            */
        }
        
        //cout << curr.first.size();
        //!get<1> is for chicken and get<2> is for cows. 
        if (get<1>(curr)<c && get<2>(curr)<n){
            //*Skipping both is just the same as skipping one then skipping the other. 
            //long long second0 = curr.second[0], second1 = curr.second[1];
            //!Ultimately nothing fixed. 
            /*
            if (cow[get<1>(curr)][0]<=chicken[get<2>(curr)] && chicken[get<2>(curr)] <= cow[get<1>(curr)][1]){
                auto next1 = curr;
                get<0>(next1).push_back({curr.second[0], curr.second[1]});
                get<1>(curr)++;
                get<2>(curr)++;
                q.push(next1);
            }
            */
            if (cows[get<2>(curr)][0] <= chickens[get<1>(curr)] && chickens[get<1>(curr)]<=cows[get<2>(curr)][1]){
                auto next1 = curr;
                get<0>(next1).push_back({get<1>(curr), get<2>(curr)});
                get<1>(next1)++;
                get<2>(next1)++;
                q.push(next1);
            }


            auto next2 = curr;
            get<1>(next2)++;
            q.push(next2);

            auto next3 = curr;
            get<2>(next3)++;
            q.push(next3);

            //!Always better to pair if we face same consequences. 
        }
        //
    }
    cout << ans << endl;
}