#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("milkorder.in","r",stdin);
	freopen("milkorder.out","w",stdout);
    long long n, m, k;
    cin >> n >> m >> k;

    vector <long long> arr (n+1, 0);
    vector <long long> ordering (m);
    for (long long i=0;i<m;i++){
        cin >> ordering[i];
    }
    for (long long i=0;i<k;i++){
        long long c, p;
        cin >> c >> p;
        arr[p] = c;
        //*Now search in the ordering and check if we find. 
        //bool found = false;
        for (long long j=0;j<m;j++){
            //!It isn't necessarily even true that I have to place the other ones in order. 
            //*In fact that may block the other ones that have fixed positions. 
            //*2 approaches:
            //1. Simulate every single position for 1st cow and place the rooted and then the relative and see if fits. 
            //2. But since we know there is always a possibility, we could place everything first??
            //!Basically, I have to try to shift the previous ones as close as possible. 
            //!However, I need to prevent repeating. 
            //*Might use a map to show where the rooted cows are located. 
            
            if (ordering[j]==c){
                //!There may be some overlap. 
                for (long long l=0;l<j;l++){
                    arr[p-j-l] = ordering[l];
                }
            }
        }

    }

    for (long long i=1;i<=n;i++){
        if (arr[i]==0){
            cout << i << endl;
            break;
        }
    }
}