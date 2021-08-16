#include <iostream>
#include <numeric>
using namespace std;

int main(){
    long long t;
    cin >> t;
    for (long long i=0;i<t;i++){
        long long a, b;
        cin >> a >> b;
        //!Cannot be proven that we only have to change one of them. 
        //*E.g. 3 and 19. Optimum is to increase 1 in both and make it 4 and 20. 
        //!Reminds me of the 1st problem on atcoder. 

        //!OK so this problem is actually pretty easy. 
        //*In 2 steps I can always make 2 odd numbers even so 2 is GCD. 
        //*But I have to check whether they are already OK or one step will do the trick. 

        if (gcd(a, b) > 1){
            cout << 0 << endl;
        }
        else{
            if ((gcd(a+1, b) > 1) || (gcd(a, b+1) > 1)){
                cout << 1 << endl;
            }
            else{
                cout << 2 << endl;
            }
        }
    }
}