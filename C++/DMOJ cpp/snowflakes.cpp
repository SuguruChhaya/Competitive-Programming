#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    long long n;
    cin >> n;
    map <long long, vector <vector <long long>>> d;
    vector <vector <long long>> arr;
    //!The memory limit kind of concerns me. 
    for (long long i=0;i<n;i++){
        vector <long long> temp_vector;
        for (long long j=0;j<6;j++){
            long long temp;
            cin >> temp;
            temp_vector.push_back(temp);
            if (d.count(temp)==1){
                d[temp].push_back({i, j});
            }
            else{
                d.insert({temp, {{i, j}}});
            }
        }
        arr.push_back(temp_vector);
    }

    //*Loop through all the elements in n^2 time. 
    //!NOT n^2! Find the elements. Create a bool vector to cross off known to be false snowflakes.
    /*
    vector <bool> original_bool;
    for (long long i=0;i<n;i++){
        original_bool.push_back(true);
    }
    */

    //!Technically, 2 pairs are matching so I should be able to do this while reading in data. 
    //!Actually, I do have to store it in array anyways since entire snowflake has to match. 
    
    //*First print out the dictionary.
    /*
    for (auto p:d){
        cout << p.first << endl;
        for (auto a:p.second){
            cout << a[0] << a[1] << endl;
        }
    }
    */
    //!Could it be the dictionary that is the problem?

    
    bool found = false;
    for (long long i=0;i<n;i++){
        if (found==true){
            break;
        }
        /*
        if (i==2){
            cout << "" << endl;
        }
        */
        //auto curr_bool = original_bool;
        for (long long j=0;j<6;j++){
            if (found == true){
                break;
            }
            if (d.count(arr[i][j])==1){
                for (auto starting:d[arr[i][j]]){
                    /*
                    if (starting[0]==7 && starting[1]==2){
                        cout << "" << endl;
                    }
                    */
                    //!Make sure we are not looking at the same snowflake. 
                    if (starting[0] != i){
                        bool ok = false;
                        long long index1 = j;
                        long long index2 = starting[1];
                        //!Cannot remove from consideration just because one of the 0 was not OK. 
                        //*Have to check all, even if it takes time. 
                        //*First check clockwise. 
                        long long num=0;
                        while (num < 6 && arr[i][index1]==arr[starting[0]][index2]){
                            index1 = (index1+1) % 6;
                            index2 = (index2+1) % 6;
                            num++;
                        }
                        if (num==6){
                            ok=true;
                        }

                        //*Then check counter-clock. 
                        index1 = j;
                        index2 = starting[1];
                        num = 0;
                        while (num < 6 && arr[i][index1]==arr[starting[0]][index2]){
                            index1 = (index1+1) % 6;
                            index2 = index2-1;
                            //!For subtraction, I cannot just mod it since it will stay at -1. 
                            if (index2==-1){
                                index2 = 5;
                            }
                            num++;
                        }
                        if (num==6){

                            ok=true;
                        }

                        if (ok){
                            cout << "Twin snowflakes found." << endl;
                            found = true;
                            break;
                        }
                        /*
                        else{
                            curr_bool[starting[0]] = false;
                        }
                        */
                    }
                }
            }
        }
    }

    if (found==false){
        cout << "No two snowflakes are alike." << endl;
    }
}