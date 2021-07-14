#include <iostream>

using namespace std;

int main(){
    int s, x;
    cin >> s >> x;

    if ((s+2)*3+16>x){
        cout << "No, it's too small :(" << endl;
    }
    else{
        cout << "Yes it fits!" << endl;
    }
}