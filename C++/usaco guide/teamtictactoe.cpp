#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main(){
    freopen("tttt.in", "r", stdin);
    freopen("tttt.out", "w", stdout);

    //!It was just the duplicates that was causing trouble. 

    //*Really I just have to check all rows/col/diags and check how many cows included. 
    vector <vector <char>> arr;
    vector <char> temp_arr;
    string temp_string;
    for (int i=0;i<3;i++){
        cin >> temp_string;
        temp_arr = {};
        for (int j=0;j<3;j++){
            temp_arr.push_back(temp_string[j]);
        }
        arr.push_back(temp_arr);
    }

    set <char> hashset;
    int num1,num2;
    num1 = 0;
    num2 = 0;

    //*Since the set sorts based on char so only one type I guess. 
    set <char> individual;
    set <vector <char>> team;
    for (int row=0;row<3;row++){
        hashset = {};
        for (int col=0;col<3;col++){
            hashset.insert(arr[row][col]);
        }
        auto it1 = hashset.begin();
        auto it2 = hashset.begin();
        it2++;
        if (hashset.size()==1 && individual.count(*it1)==0){
            individual.insert(*it1);
            num1++;
        }

        else if (hashset.size()==2 && team.count({*it1, *it2})==0){
            team.insert({*it1, *it2});
            num2++; 
        }
    }

    for (int col=0;col<3;col++){
        hashset = {};
        for (int row=0;row<3;row++){
            hashset.insert(arr[row][col]);
        }
        auto it1 = hashset.begin();
        auto it2 = hashset.begin();
        it2++;
        if (hashset.size()==1 &&individual.count(*it1)==0){
            individual.insert(*it1);
            num1++;
        }
        else if (hashset.size()==2 && team.count({*it1, *it2})==0){
            team.insert({*it1, *it2});
            num2++;
        }
    }

    hashset = {};
    hashset.insert(arr[0][0]);
    hashset.insert(arr[1][1]);
    hashset.insert(arr[2][2]);

    auto it1 = hashset.begin();
    auto it2 = hashset.begin();
    it2++;


    if (hashset.size()==1 &&individual.count(*it1)==0){
        individual.insert(*it1);
        num1++;
    }
    
    else if (hashset.size()==2 && team.count({*it1, *it2})==0){
        team.insert({*it1, *it2});
        num2++;
    }



    hashset = {};
    hashset.insert(arr[0][2]);
    hashset.insert(arr[1][1]);
    hashset.insert(arr[2][0]);

    it1 = hashset.begin();
    it2 = hashset.begin();
    it2++;

    if (hashset.size()==1 &&individual.count(*it1)==0){
        individual.insert(*it1);
        num1++;
    }
    else if (hashset.size()==2 && team.count({*it1, *it2})==0){
        team.insert({*it1, *it2});
        num2++;
    }
    //!I might be claiming multiple victories for the same cow!
    //*I could store all the individual cows that claimed vicotry for 1 and 2. 
    //*Each individual can only win once. 

    cout << num1 << "\n";
    cout << num2 << "\n";

}