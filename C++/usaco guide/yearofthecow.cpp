#include <bits/stdc++.h>
using namespace std;

int main(){
    //*I think the loop just has to keep going until I get elsie because the names of the cows are previously mentioned. 
    long long n;
    cin >>n;
    //*I don't even think I need to use a map for this question. 
    //!Actually, doesn't necessarily mean all previous info is useful so keep track. 
    //*Can calculate inside the loop. Just store the results. 
    map <string, long long> d = {{"Bessie", 0}};
    //*Relation of the other animal years compared to the ox years. 
    
    //Dog, Pig, Rat, and then Ox
    map <string, long long> animals = {
        //!Never eqaul so Ox must be 7 away. 
        
        {"Tiger", 1},
        {"Rabbit", 2},
        {"Dragon", 3},
        {"Snake", 4},
        {"Horse", 5},
        {"Goat", 6},
        {"Monkey", 7},
        {"Rooster", 8},
        {"Dog", 9},
        {"Pig", 10},
        {"Rat", 11},
        {"Ox", 12}
    };
    for (long long i=0;i<n;i++){
        string cow1, time, animal, cow2;
        for (long long j=0;j<8;j++){
            string s;
            cin >> s;
            if (j==0){
                cow1 = s;
            }
            else if (j==3){
                time = s;
            }
            else if (j==4){
                animal = s;
            }
            else if (j==7){
                cow2 = s;
            }
        }

        if (time=="previous"){
            //*The mappings are considering they are after so I need to do 12- or something. 
            //!What was the calculation???
            //!This model is really just based on the ox year so need to change that. 
            //*I would have to st
            //!Skip since just a bunch of specific stuff..
            d.insert({cow1, d[cow2]-(12-animals[animal])});
        }
        else{
            d.insert({cow1, d[cow2]+animals[animal]});
        }
    }

    for (auto element:d){
        cout << element.first << " " << element.second << endl;
    }
    cout << abs(d["Elsie"]) << endl;
}