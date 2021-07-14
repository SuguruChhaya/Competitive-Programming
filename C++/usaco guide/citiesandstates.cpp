#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin >> n;
    map <string, vector <string>> city_to_state, state_to_city;
    for (long long i=0;i<n;i++){
        string c, s;
        cin >> c >> s;
        //!Need to store in some kind of map??
        //*Multiple cities with same name could exist. 

        //!Need the first 2 letters of the city. 
        //!Then the first 2 lettersof the state as well. 

        //!There could be multiple cities with the same starting. 
        transform(c.begin(), c.end(), c.begin(), ::toupper);
        if (city_to_state.count(c)==1){
            //*State is anyways 2 letters. But I need to convert to lower case. 
            //*Maybe easier to convert to upper. 
            
            city_to_state[c.substr(0, 2)].push_back(s);
        }
        else{
            
            city_to_state.insert({c.substr(0, 2), {s}});
        }
        if (state_to_city.count(s)==1){
            state_to_city[s].push_back(c.substr(0, 2));
        }
        else{
            state_to_city.insert({s, {c.substr(0, 2)}});
        }
    }
    
    for (auto e:city_to_state){
        cout << e.first << " ";
        for (auto f:e.second){
            cout << f << " ";
        }
        cout << endl;
    }
    cout << "a" << endl;
    for (auto e:state_to_city){
        cout << e.first << " ";
        for (auto f:e.second){
            cout << f << " ";
        }
        cout << endl;
    }
    
    /*
    for (auto city:city_to_state){
        //*There could be multiple city to state pairs. 
        for (auto city_state:city){
            //!Check whether the city_state even exists. 
        }
    }
    */
    long long result = 0;
    set <vector <string>> hashset;
    for (auto city:city_to_state){
        if (state_to_city.count(city.first)==1){
            for (auto city_state:city.second){
                for (auto state_city:state_to_city[city.first]){
                    if (city_state==state_city && city_state!=city.first){
                        cout << city_state << " " << state_city << " " << city.first << endl;
                        //!The information we are adding is not the equating thing but rather the 2 cities. 
                        //!But there could be multiple cities with the same starting. 
                        //*I think here I shouldn't cut off the prefixes. 
                        if (hashset.count({state_city, city.first}))
                        result++;

                        //!I guess I have to add the cities to a set so that I don't count the same parings twice. 

                    }
                }
            }
        }
    }

    cout << result << endl;
    
}