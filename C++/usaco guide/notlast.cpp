#include <bits/stdc++.h>
using namespace std;


//*Create new data structure after filling in the info. 
int main(){
    freopen("notlast.in", "r", stdin);
    freopen("notlast.out", "w", stdout);

    map <string, long long> d = {
        {"Bessie", 0},
        {"Elsie", 0},
        {"Daisy", 0},
        {"Gertie", 0},
        {"Annabelle", 0},
        {"Maggie", 0},
        {"Henrietta", 0}
    };

    long long n;
    cin >> n;
    for (long long i=0;i<n;i++){
        string s;
        long long j;
        cin >> s >> j;
        d[s] += j;
    }

    vector <pair <long long, string>> arr;
    for (auto element:d){
        arr.push_back({element.second, element.first});
    }

    sort(arr.begin(), arr.end());

    //*Some more extra work to do after sorting.. That is what makes this problem a medium. 

    long long smallest = arr[0].first;
    long long index = 0;
    while (index < arr.size() && arr[index].first==smallest){
        index++;
    }

    //!I could use a custom algo but I could also use the other data structure: multiset. 
    //*But I cannot use multiset since index is extra info. 
    //*Now if the index is at the end, we know it is a tie. 
    if (index==arr.size()){
        cout << "Tie" << "\n";
    }
    else{
        long long last_index = index;
        long long second_smallest = arr[index].first;

        while (index<arr.size() && arr[index].first==second_smallest){
            index++;
        }

        //*If there are more than one than tie otherwise just return index-1 I guess. 
        if (index-last_index!=1){
            cout << "Tie" << "\n";
        }
        else{
            cout << arr[index-1].second << endl;
        }
    }


    //cout << arr[1].second << endl;   

}