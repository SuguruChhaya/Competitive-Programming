#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int main(){
    freopen("pails.in", "r", stdin);
    freopen("pails.out", "w", stdout);

    //*How many can fit type thing huh? 
    //*Really, the order doesn't matter. 
    //*We could either add more to the current or move on to the next one and keep adding to that. 
    //*At each step we can record the current max. 
    //*If I could do it recursively, I should be able to do it iteratively as well. 

    long long x, y, m;
    cin >> x >> y >> m;

    vector <long long> x_y = {x, y};
    long long index = 0;
    long long result = 0;
    //*Information to store: the current number and the index. Store it in a vector. 
    deque <vector <long long>> queue = {{0, 0}};
    vector <long long> curr;
    while (!queue.empty()){
        curr = queue.front();
        queue.pop_front();
        if (curr[0] > m || curr[1] > 1){

        }
        else{
            result = max(result, curr[0]);
            queue.push_back({curr[0]+x_y[curr[1]], curr[1]});
            queue.push_back({curr[0], curr[1]+1});
        }
        //cout << "running" << endl;
    }

    cout << result << endl;
}