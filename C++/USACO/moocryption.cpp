#include <bits/stdc++.h>
using namespace std;

int main(){
    //Try every single pairing of M and O. 
    long long n, m;
    cin >> n >> m;
    vector <vector <char>> arr (n, vector <char> (m));
    set <char> hashset;
    for (long long i=0;i<n;i++){
        for (long long j=0;j<m;j++){
            cin >> arr[i][j];
            hashset.insert(arr[i][j]);
        }
    }
    char m_map, o_map;
    for (auto a:hashset){
        for (auto b:hashset){
            if (a!=b && a!='M' && b!='O'){
                m_map = a;
                o_map = b;
            }
            //*Now change the characters. 
            auto copy = arr;
            for (long long i=0;i<n;i++){
                for (long long j=0;j<m;j++){
                    if (copy[i][j]==m_map){
                        copy[i][j] = 'M';
                    }
                    if (copy[i][j]==o_map){
                        copy[i][j] = 'O';
                    }
                }
            }
            //*Now check all the vertical and diagonal starting from that index. 
            for (long long i=0;i<n;i++){
                for (long long j=0;j<m;j++){
                    //*Since it can go in any direction
                    
                    //!I guess I can just implement the last part as a trick
                    if (copy[i][j]=='M'){
                        for (long long k=0;k<8;k++){
                            if (get )
                        }
                    }
                }
            }
        }
    }
}