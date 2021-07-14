#include <iostream>

using namespace std;

int main(){
    long long a, b, c;
    cin >> a >> b >> c;

    long long temp = max(a+b, a+c);
    cout << max(temp, b+c) << "\n";
}