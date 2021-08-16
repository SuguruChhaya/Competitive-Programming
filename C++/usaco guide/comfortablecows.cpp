#include <bits/stdc++.h>
using namespace std;
vector <vector <bool>> arr;
vector <vector <bool>> comfortable;

pair <bool, vector <vector<long long>>> is_comfortable(long long x, long long y){
    vector <vector <long long>> adjacent;
    if ((x-1 >= 0 && arr[x-1][y]==1)){
        adjacent.push_back({x-1, y});
    }
    if ((x+1<=1000 && arr[x+1][y]==1)){
        adjacent.push_back({x+1, y});
    }
    if (y-1>=0 && arr[x][y-1]==1){
        adjacent.push_back({x, y-1});
    }
    if (y+1<=1000 && arr[x][y+1]==1){
        adjacent.push_back({x, y+1});
    }
    pair <bool, vector <vector <long long>>> result = {false, adjacent};
    if (adjacent.size()==3){
        result.first = true;
        return result;
    }
    return result;
}

int main(){
    //*I have to only change certain ones. I cannot loop through all of them every time. 
    long long n;
    cin >> n;
    //*Need to create a 1001 x 1001 vector. 
    
    for (long long i=0;i<1000;i++){
        vector <bool> temp;
        for (long long j=0;j<1000;j++){
            //*Whether a cow exists or not. 
            temp.push_back(0);
        }
        arr.push_back(temp);
        comfortable.push_back(temp);
    }
    long long curr = 0;
    for (long long i=0;i<n;i++){
        long long x, y;
        cin >> x >> y;
        arr[x][y] = 1;

        //*First check whether that addition makes things comfortable. 
        //*For future use, store adjacent cows in a 2D vector.
        
        auto temp = is_comfortable(x, y);
        if (temp.first){
            comfortable[x][y] = 1;
            curr++;
        }
        //*Now loop through all and check whether. 
        //*Honestly, I think I should create a function for this. 
        
        //*Now loop through 
        for (auto coord: temp.second){
            //*If it was comfortable and now isn't, I need to subtract. 
            auto temp = is_comfortable(coord[0], coord[1]);
            if (temp.first==false && comfortable[coord[0]][coord[1]]==1){
                curr--;
                comfortable[coord[0]][coord[1]] = 0;
            }
            //*Or if the current one makes a previously not comfortable one comfortable, add 1. 
            if (temp.first==true && comfortable[coord[0]][coord[1]]==0){
                curr++;
                comfortable[coord[0]][coord[1]] = 1;
            }
        }

        cout << curr << endl;
    }
}