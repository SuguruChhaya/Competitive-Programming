#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("lifeguards.in", "r", stdin);
    freopen("lifeguards.out", "w", stdout);
    long long n;
    cin >> n;
    vector<vector<long long>> starting, ending;
    for (long long i=0;i<n;i++){
        long long a, b;
        cin >> a >> b;
        starting.push_back({a, i});
        ending.push_back({b, i});
    }
    sort(starting.begin(), starting.end());
    sort(ending. begin(), ending.end());

    long long currTime, total = 0, currStarting = 0, currEnding = 0, blockStart;
    bool looking = 1;
    set <long long> currCows;
    while (currStarting<n && currEnding<n){
        if (starting[currStarting][0]<ending[currEnding][0]){
            currTime = starting[currStarting][0];
            if (looking){
                blockStart = currTime;
                looking = 0;
            }
            currCows.insert(starting[currStarting][1]);
            currStarting++;
        }
        else{
            currTime = ending[currEnding][0];
            currCows.erase(ending[currEnding][1]);
            if (currCows.size()==0){
                total+=currTime-blockStart;
                looking = 1;
            }
            currEnding++;
        }
    }
    //!Could only be left with endings. 
    while (currEnding<n){
        currTime = ending[currEnding][0];
        currCows.erase(ending[currEnding][1]);
        if (currCows.size()==0){
            total+=currTime-blockStart;
            looking = 1;
        }
        currEnding++;
    }


    vector<long long>aloneTime(n, 0);
    long long prev = -1;
    currStarting = 0, currEnding = 0;
    //set <long long> currCows;
    bool first = 1;
    bool start, end;
    while (currStarting<n && currEnding<n){
        start = 0, end=0;
        if (starting[currStarting][0]<ending[currEnding][0]){
            currTime = starting[currStarting][0];
            /*
            currCows.insert(starting[currStarting][1]);
            currStarting++;
            */
            start = 1;
        }
        else{
            currTime = ending[currEnding][0];
            /*
            currCows.erase(ending[currEnding][1]);
            currEnding++;
            */
            end = 1;
        }
        //!Have to ignore when we first insert the cow. 
        //!Really need to check before adding or erasing. 
        if (currCows.size()==1 && !first){
            aloneTime[*currCows.begin()] += currTime-prev;
        }
        first = 0;
        if (start){
            currCows.insert(starting[currStarting][1]);
            currStarting++;
        }
        else{
            currCows.erase(ending[currEnding][1]);
            currEnding++;
        }
        prev = currTime;

    }  

    //!Only for ending. 
    while (currEnding<n){
        currTime = ending[currEnding][0];
        if (currCows.size()==1){
            aloneTime[*currCows.begin()]+=currTime-prev;
        }
        currCows.erase(ending[currEnding][1]);
        currEnding++;
        prev = currTime;
    }
    /*
    for (auto e:aloneTime){
        cout << e << endl;
    }
    */
    sort(aloneTime.begin(), aloneTime.end());
    //!I think I first need to tally up the time covered by all of the cows. 
    //!While not all ended, we still keep counting. 

    cout << total-aloneTime[0] << endl;
}