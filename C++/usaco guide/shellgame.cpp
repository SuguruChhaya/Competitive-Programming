#include <iostream>
#include <vector>
using namespace std;

int main(){
    //*We can simulate that the pebble will be under all 3 and see how many points she will get. 

    freopen("shell.in", "r", stdin);
    freopen("shell.out", "w", stdout);

    int numSwaps;
    cin >> numSwaps;

    //*Need to store the swaps in a vector. 
    vector <vector <int>> arr;
    //vector <int> temp;
    int a, b, c;
    for (int i=0;i<numSwaps;i++){
        cin >> a >> b >> c;
        arr.push_back({a, b, c});
    }
    int curr;
    int score;
    int result=0;
    for (int initial=1;initial<=3;initial++){
        score = 0;
        curr = initial;
        for (int j=0;j<numSwaps;j++){
            if (arr[j][0]==curr){
                curr = arr[j][1];
            }
            else if (arr[j][1]==curr){
                curr = arr[j][0];
            }
            if (curr == arr[j][2]){
                score++;
            }
        }
        result = max(result, score);

    }
    cout <<  result;
}