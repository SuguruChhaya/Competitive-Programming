#include <bits/stdc++.h>
using namespace std;

int main(){
    //*Really fun informatics question. 
    //*Can compare each with each. 
    
    long long k, n;
    cin >> k >> n;

    vector <string> names;
    //*Stores the index of that certain guy. 
    map <string, long long> location;
    for (long long i=0;i<n;i++){
        string s;
        cin >> s;
        names.push_back(s);
        location.insert({s, i});
    }

    //*Construct the resulting array with all ? except when row==col. 
    vector <vector <char>> result;
    for (long long i=0;i<n;i++){
        vector <char> temp;
        for (long long j=0;j<n;j++){
            if (i==j){
                temp.push_back('B');
            }
            else{
                temp.push_back('?');
            }
        }
        result.push_back(temp);
    }

    for (long long i=0;i<k;i++){
        vector <string> order;
        for (long long j=0;j<n;j++){
            string s;
            cin >> s;
            order.push_back(s);
        }  

        for (long long p1=0;p1<n;p1++){
            for (long long p2=p1+1;p2<n;p2++){
                //!No point checking same pair twice 
                //!Really easy to figure out if first letter of p2 is smaller than first letter of p1. 
                //*Not guaranteed that the first character is different so have to compare whole string. 
                if (order[p1] > order[p2]){
                    //*p2 is definitely more senior. 
                    //!I need to properly find this guy's place using a hashtable or something. 

                    result[location[order[p2]]][location[order[p1]]] = '1';
                    result[location[order[p1]]][location[order[p2]]] = '0';
                }
                else{
                    //*If the sequence of array is in ascending order, we will never know. 
                    //*However, if there is some difference, we don't know. 
                    //*I could consturct a new vector of strings, sort it, and check. 
                    /*
                    if (order[p1]=="elsie" && order[p2]=="mildred"){
                        cout << "";
                    }
                    */
                    
                    //!Mentions how seniors never put more effort but they could put in equal effort as junior I think. 
                    bool ok = true;
                    //!All we have to know is whether it is sorted or not. 
                    for (long long new_index=p1;new_index<p2;new_index++){
                        if (order[new_index] > order[new_index+1]){
                            ok = false;
                            break;
                        }
                    }

                    /*

                    vector <string> sorted;
                    for (long long new_index=p1;new_index<=p2;new_index++){
                        sorted.push_back(order[new_index]);
                    }
                    sort(sorted.begin(), sorted.end());
                    
                    //!Cannot just naively compare since they are of different sizes. 
                    
                    for (long long index = p1;index<=p2;index++){
                        if (sorted[index-p1]!=order[index]){
                            ok = false;
                            break;
                        }
                    }
                    */
                    //!Shouldn't this be ok==false since if it is sorted, they all could be same senior level. 
                    //*But if not sorted then it works out. 
                    if (ok==false){
                        result[location[order[p2]]][location[order[p1]]] = '1';
                        result[location[order[p1]]][location[order[p2]]] = '0';
                    }

                    //!Either we should try to use already gathered information or we could run the loop again. 
                    //*IDK if either will even work. 

                    //!But if there is a more senior guy in the middle, we know that the remaning people should be more senior. 
                }
            }
        }
    }

    for (long long i=0;i<n;i++){
        for (long long j=0;j<n;j++){
            cout << result[i][j];
        }
        cout << endl;
    }
}