#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector <char> a;
vector <char> b;

void showVector(vector <char> arr){
    for (long long i=0;i<arr.size();i++){
        cout << arr[i] <<  " ";
    }
    cout << "\n";
}
int main(){
    //*Kind of similar to codejam pancake question. 
    //*I think the only case there is no solution is when there are different number of 0s and 1s. 

    long long n;
    long long a_num0 = 0;
    long long b_num0 = 0;
    cin >> n;
    char temp;
    for (long long i=0;i<n;i++){
        cin >> temp;
        a.push_back(temp);
        if (temp=='0'){
            a_num0++;
        }
    }

    for (long long i=0;i<n;i++){
        cin >> temp;
        b.push_back(temp);
        if (temp=='0'){
            b_num0++;
        }
    }

    if (a_num0 != b_num0){
        cout << -1;
    }
    else{
        //*We could just try naive BFS and hope it passes first batch. 
        vector <pair <vector <char>, vector<vector<long long>>>> queue = {{a, {}}};
        pair <vector <char>, vector<vector<long long>>> curr;
        pair <vector <char>, vector<vector<long long>>> temp;
        //map <vector <char>, vector <char>> came_from;
        //*We need to store where it came from so something like A*. 
        //!Not came from but rather the order of strikes. 

        //*I can store in pair. 
        while (queue.size() > 0){
            curr = queue[0];
            //!cout << curr.first[1]; This indexing works. 
            queue.erase(queue.begin());
            if (curr.first==b){
                //*Just print the remaining. 
                cout << curr.second.size() << "\n";
                for (long long i=0;i<curr.second.size();i++){
                    cout << curr.second[i][0] << " " << curr.second[i][i] << "\n";
                }
                
                break;
                
            }
            else{
                //*Have to copy for every movement. 
                //!Kind of confusing but I think this problem uses 1 indexing. 
                //!The program just somehow stops after the first 5 moves. 
                for (long long i=0;i<curr.first.size();i++){
                    //*No point sorting the same place twice. 
                    //!The sorting index is not inclusive. I will add 1 at the end to cope for that. 
                    for (long long j=i;j<curr.first.size();j++){
                        //*Copy the pair then sort. 
                        temp = curr;
                        sort(temp.first.begin()+i, temp.first.begin()+j+1);
                        //*I should show the vector since cannot access from debug. 
                        showVector(temp.first);
                        //!2 is correct but how can you just swap 00, 56 and reach the answer???
                        temp.second.push_back({i, j});
                        queue.push_back(temp);
                    }
                }
            }
            cout << "running";
        }
        cout << "done";
    }
}