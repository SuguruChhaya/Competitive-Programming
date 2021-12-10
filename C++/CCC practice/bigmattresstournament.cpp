#include <bits/stdc++.h>
using namespace std;

int main(){
    long long t;
    cin >> t;
    while (t--){
        long long a, b, c;
        cin >> a >> b >> c;
        if ((a==0 && b!=0 && b%2==0 && c==0)||(a!=0&&a%2==0&&b==0&&c==0)||(a!=0&&a%2==0&&b%2==1&&c==0)||(a!=0&&a%2==0&&b!=0&&b%2==0&&c==0)){
            cout << "YES" << endl;
        }
        else if (((a%2==1&&b==0&&c%2==1)||(a%2==1&&b%2==1&&c%2==1)||(a%2==1&&b!=0&&b%2==0&&c%2==1)||(a!=0&&a%2==0&&b==0&&c!=0&&c%2==0)||(a!=0&&a%2==0&&b%2==1&&c!=0&&c%2==0)||(a!=0&&a%2==0&&b!=0&&b%2==0&&c!=0&&c%2==0))&&(a>=c)){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
}