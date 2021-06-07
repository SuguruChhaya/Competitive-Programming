#include <iostream>
using namespace std;

int main(){
    //*Since the number can pretty large, use long long. 
    long long n;
    cin >> n;
    //!How can there be a 0 tho?
    while (n!=1){
        cout << n << " ";
        if (n % 2 == 1){
            n = n * 3 + 1;
        }
        else{
            n /= 2;
        }
    }
    cout << "1";
}