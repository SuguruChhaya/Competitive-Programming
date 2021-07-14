#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("guess.in", "r", stdin);
    freopen("guess.out", "w", stdout);

    map <string, set <string>> animal_to_feature;
    long long n;
    cin >> n;
    vector <string> allAnimals;

    for (long long i=0;i<n;i++){
        string animal;
        long long k;
        cin >> animal >> k;
        set <string> currFeatures;
        for (long long j=0;j<k;j++){
            string feature;
            cin >> feature;
            currFeatures.insert(feature);
        }
        animal_to_feature.insert({animal, currFeatures});
        allAnimals.push_back(animal);
    }
    long long result = 0;
    for (long long i=0;i<n;i++){
        for (long long j=i+1;j<n;j++){
            //*Don't count same animal and no reverse pair. 
            //*I could iterate through one and check whether the feature exists in the other one. 
            long long matches = 0;
            for (auto element:animal_to_feature[allAnimals[i]]){
                if (animal_to_feature[allAnimals[j]].count(element)==1){
                    matches++;
                }
            }
            result = max(result, matches+1);

        }
    }
    cout << result << endl;
}