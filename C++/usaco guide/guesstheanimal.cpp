#include <bits/stdc++.h>

using namespace std;

//!Yeah we have so many possibilities then I guess it would be impossible. 

int main(){
    //*Basically I have to keep the game as long as possible. 
    //*No need to do any "no" BS. Just keep getting yes. 
    //*I wouldn't be able to pre-create all the permutations because there could be way more than 15. 
    //*I have to just keep going and see which attributes I can choose from. 
    //!I can think of 2 structures I could use. 
    //*One is based on the animal to characteristics attributes. 
    //*Second is characteristic to animal attribute.
    
    //*So I can start of with a certain characteristic (for loop). 
    //*I can keep adding to queue storing the information of the characteristics used, and the list of current remaining animals. 
    //*Probably makes snese to filter out the applicable animals before placing in the queue. 

    freopen("guess_data/3.in", "r", stdin);
    freopen("guess_data/3m.out", "w", stdout);


    //!Both WA and TLEs that's tuff. 
    //*Firstly why WA? 
    //!Still TLE and WA... TLE is probably because I am stuck in an infinite loop. 

    map <string, vector <string>> animal_to_feature;
    map <string, vector <string>> feature_to_animal;
    long long n;
    cin >> n;
    vector <string> allAnimals;


    for (long long i=0;i<n;i++){
        string animal;
        long long k;
        cin >> animal >> k;
        vector <string> currFeatures;
        for (long long j=0;j<k;j++){
            string feature;
            cin >> feature;
            currFeatures.push_back(feature);

            if (feature_to_animal.count(feature)==0){
                feature_to_animal.insert({feature, {animal}});
            }
            else{
                feature_to_animal[feature].push_back(animal);
            }
        }
        //*We know we must insert the animal because no animal comes twice. 
        animal_to_feature.insert({animal, currFeatures});
        allAnimals.push_back(animal);
    }

    //*Queue information:
    //*We don't even have to store the order of attributes, just store as a number. 
    //*And a vector of all the animals left. 

    //*Why printing 2 instead of 3?
    //*Instead of long long, store in vector of all steps. 

    deque <pair <set <string>, vector <string>>> q;
    pair <set <string>, vector <string>> curr;
    auto result = curr;
    
    //!First element is the number of times we chose. 
    q.push_back({{}, allAnimals});
    while (!q.empty()){
        curr = q[0];
        q.pop_front();
        //!Cow and goat stuck at eats grass. 
        //*If the size didn't change then we shouldn't add. 

        //*Let me try printing out every the animals. 
        /*
        for (auto animal: curr.second){
            cout << animal << endl;
        }
        */
        if (curr.second.size()==1){
            long long temp1 = curr.first.size();
            long long temp2 = result.first.size();
            //result = max(result, temp);
            if (temp1 > temp2){
                result = curr;
            }
            
        }
        //*I didn't take care of case when the length of curr.second becomes 0.
        else if (curr.second.size()==0){

        }
        else{
            set<string> available_features;
            for (auto animal: curr.second){
                //!To find available features, we should use the animal-to_feature map. 
                for (auto feature: animal_to_feature[animal]){
                    //*Looking through all the dictionaries and inserting all the available features in set. 
                    //!Check whether we already looked at that feature or not. 
                    if (curr.first.count(feature)==0){
                        available_features.insert(feature);
                    //cout << feature << endl;
                    }
                }
            }
            //cout << available_features.size();
            //*Need to copy into a vector or else I cannot iterate through them. 

            for (auto element:available_features){
                vector <string> next_arr;
                //*Number of yes increases. 
                //*For the next_arr, I will just not include the animals that don't contain the feature.
                //!Easier if I just erase from the next.  

                //!I don't have to erase shit!!

                //*Iterate throught eh current animal list. 
                //*Check whether each animal exists in that feature. 
                //*If it does, add in the next_arr. 
                for (auto animal:curr.second){
                    for (auto animal2:feature_to_animal[element]){
                        if (animal==animal2){
                            next_arr.push_back(animal);
                            break;
                        }
                    }
                }
                /*
                for (long long j=0;j<curr.second.size();j++){
                    //*Honestly, I could probably just iterate through to find it. 
                    for (long long k=0;k<feature_to_animal[element].size();k++){
                        if (feature_to_animal[element][k]==curr.second[j]){
                            //*Feature exists in that animal. 
                            next_arr.push_back(curr.second[j]);
                            break;
                        }
                    }
                }
                */

                //!Stuck for some weird reason. 
                /*
                for (long long j=0;j<feature_to_animal[element].size();j++){
                    //*The index is just the index in the feature_to_animal vector so I need to find the element. 
                    for (long long k=0;k<next.second.size();k++){
                        if (next.second[k]==feature_to_animal[element][j]){
                            next.second.erase(next.second.begin()+k);
                        }
                    }
                }
                */

                //!Doesn't necessarily mean that if the size is same then it is no longer possible. 
                //!I guess I have to keep a set of all used features so that they don't repeat. 
                //*Otherwise won't give me accurate answer. 

                auto first = curr.first;
                first.insert(element);
                pair <set <string>, vector <string>> next = {first, next_arr};
                q.push_back(next);
                
            }
        }
    }

    //!Change the result data type to vector. 
    cout << result.first.size() << endl;
    /*
    for (auto element:result.first){
        cout << element << endl;
    }
    */

    
}