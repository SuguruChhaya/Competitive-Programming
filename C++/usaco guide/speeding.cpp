#include <iostream>
#include <vector>
using namespace std;

int main(){
    //*I think it is way easier to just create a vector with 100 and then check after all of that. 
    freopen("speeding.in", "r", stdin);
    freopen("speeding.out", "w", stdout);
    
    int n, m;
    cin >> n >> m;
    int mile, speed;
    vector <int> rules;
    vector <int> actual;
    for (int i=0;i<n;i++){
        cin >> mile >> speed;
        for (int j=0;j<mile;j++){
            rules.push_back(speed);
        }
    }

    for (int i=0;i<m;i++){
        cin >> mile >> speed;
        for (int j=0;j<mile;j++){
            actual.push_back(speed);
        }
    }
    int max_difference = 0;
    for (int i=0;i<100;i++){
        max_difference = max(max_difference, actual[i]-rules[i]);
    }

    cout << max_difference<<"\n";

}