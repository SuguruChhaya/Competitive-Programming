#include <bits/stdc++.h>
using namespace std;

int main(){

    freopen("badmilk.in", "r", stdin);
    freopen("badmilk.out", "w", stdout);

    long long n, m, d, s;
    cin >> n >> m >> d >> s;

    //!Obvious knowledge that I need a vector to store the number of people who drank each type of milk. 
    //*Make it 1-indexed for simplicity. 
    vector <set <long long>> milk_arr;

    //!Obviously need to store based on person since check what milk was drunk before. 
    vector <vector <vector <long long>>> person_time_milk;
    //*both person and time will be 1 indexed for simplicity. 
    for (long long i=0;i<=n;i++){
        //*Time is in range 1-100
        vector <vector <long long>> temp;
        for (long long j=0;j<=100;j++){
            temp.push_back({});
        }
        person_time_milk.push_back(temp);
    }

    for (long long i=0;i<=m;i++){
        milk_arr.push_back({});
    }

    //*I need to consider when the dude even drank the milk. 
    //*So if he gets sick at a certain point, it must be the milk before. 

    for (long long i=0;i<d;i++){
        long long p, m, t;
        cin >> p >> m >> t;
        //*Since one guy can drink the same milk multiple times, it is better to store in a set. 
        milk_arr[m].insert(p);

        //*Need a clear table to store data
        //!Get sick if drink at strictly earlier point in time. 

        person_time_milk[p][t].push_back(m);
    }
    set <long long> possible_milk;
    for (long long i=0;i<s;i++){
        long long p, t;
        cin >> p >> t;
        //*Strictly smaller

        if (possible_milk.empty()){
            //!This will become false after the first insertion!!
            for (long long j=0;j<t;j++){
                for (long long k=0;k<person_time_milk[p][j].size();k++){
                    possible_milk.insert(person_time_milk[p][j][k]);
                }
            }
            
        }
        else{
            set <long long> temp;
            //!All the time. 
            for (long long j=0;j<t;j++){
                //*I need to loop through all the milk drunk during the time period too. 
                //!All milk within that time. 
                for (long long k=0;k<person_time_milk[p][j].size();k++){

                    //*If it doesn't exists 
                    //*Only return all common elements. 
                    //*Prepare returning set. 
                    
                    //*We are looking at one at a time so count the individual one. 
                    if (possible_milk.count(person_time_milk[p][j][k])==1){
                        temp.insert(person_time_milk[p][j][k]);
                    }
                    
                }
            }
            //*Now set it to the new one. 
            possible_milk = temp;
        }
    }
    set <long long> result;
    //!Possibilities could overlap!
    for (auto elem:possible_milk){
        //*Number of people who drank that milk. 
        for (auto person:milk_arr[elem]){
            result.insert(person);
        }
    }
    cout << result.size() << endl;


}