#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("measurement.in", "r", stdin);
    freopen("measurement.out", "w", stdout);

    long long n;
    long long result = 0;
    cin >> n;
    //*We need to keep track of the highest milk score. 

    vector <tuple <long long, string, long long>> arr;
    for (long long i=0;i<n;i++){
        //?Does +1 and -1 able to convert to long long? 
        long long day;
        string cow;
        long long change;
        cin >> day >> cow >> change;
        arr.push_back({day, cow, change});
    }
    sort(arr.begin(), arr.end());

    vector <string> current_standings;
    vector <string> previous_standings = {"Bessie", "Elsie", "Mildred"};
    
    //*The vector should contain a pair for easy. 
    //vector <pair <string, long long>> order;
    //!Or I could put these into maps so I don't even need the if statements. 
    map <string, long long> d = 
    {
        {"Bessie", 7},
        {"Elsie", 7},
        {"Mildred", 7}

    };
    for (long long i=0;i<n;i++){
        d[get <1> (arr[i])] += get <2> (arr[i]);

        //*We could construct the 
        //temp = {};
        //*Create the new standings. 
        //!I could hardcode and add stuff. 
        vector <pair <long long, string>> order =
        {
            {d["Bessie"], "Bessie"},
            {d["Elsie"], "Elsie"},
            {d["Mildred"], "Mildred"},
        };
        sort(order.begin(), order.end());
        
        //*Check whether the line up is different from previous. 
        long long largestValue = order[2].first;
        long long currIndex = 2;
        current_standings = {};
        //!Need to make sure currIndex doesn't go out of bounds. 
        while (currIndex >=0 && order[currIndex].first==largestValue){
            current_standings.push_back(order[currIndex].second);
            //*Should be in reverse alphabetical order since counting from the end. 
            currIndex--;
        }
        if (current_standings!=previous_standings){
            result++;
        }
        previous_standings = current_standings;
        
    }
    cout << result << endl;
}