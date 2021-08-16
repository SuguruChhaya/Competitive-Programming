#include <iostream>

using namespace std;

int main(){
    double a, b, c, d;
    cin >> a >> b >> c >> d;

    //*Start off with 0 or 1? 
    long long result = 0;
    long long numCyan = a;
    long long numRed = 0;

    if (b / c >=d){
        cout << -1 << endl;
    }
    else{
        while (!(numCyan <= numRed * d)){
            result++;
            numCyan+=b;
            numRed+=c;
        }
        cout << result << "\n";
    }

    /*
    while (!(numCyan <= numRed * d)){
        result++;
        numCyan+=b;
        numRed+=c;
    }
    cout << result << "\n";
    */

    //*How am I gonna detect a -1 though? 
    //!If the initial division rate is smaller than it won't work. 
    //*9/2 = 4.5 which is greater than 3 so it will never reach. 

    //!If b / c >=d, it is impossible. 
    //*>= because A>1 so even if equal to d, it will always be slightly off. 


}