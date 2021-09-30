#include <bits/stdc++.h>

using namespace std;

int main(){

    //freopen("angry.in", "r", stdin);
    //freopen("angry.out", "w", stdout);

    //!Some WAs why???
    //!Could the blasts go in opposite directions??
    //!Only the fifth one huh?

    long long n;
    cin >> n;
    vector <long long> arr;
    for (long long i=0;i<n;i++){
        long long temp;
        cin >> temp;
        arr.push_back(temp);
    }

    sort(arr.begin(), arr.end());
    
    //*Try blasting every single possibility. 
    long long result = 0;
    for (long long i=0;i<n;i++){
        //*Some kind of while loop. 
        bool ok = true;
        long long left, right, last;
        long long currRadius = 1;
        last = left = right = i;
        
        while (ok){
            
            //*If either we can keep extending to left or right, keep ok=true. 
            //*So initialize ok to false.
            ok = false;
            /*
            if (left != 0){
                if (arr[left] - currRadius <= arr[left-1]){
                    ok = true;
                    //*Move the left pointer to next. 
                    left--; 
                }
            }
            */
            //*I think last should initially be equal to the left variable. 
            last = left;

            while (left != 0 && arr[last] - currRadius <= arr[left-1]){
                ok = true;
                //!I honestly don't know about this problem...
                //*The blasting behaviour is key to understand!!
                left--;
            }

            //!End up being way under what it should be...

            //!I see, simultaneous blows makes it a little more complicated...
            //*I guess I could just change into a while loop...?

            //*Reset the last variable. 
            last = right;

            //!Is it that we have to break at a certain point??
            while (right != n-1 && arr[last]+currRadius>=arr[right+1]){
                ok = true;
                right++;
            }
            /*
            if (right != n-1){
                if (arr[right] + currRadius >= arr[right+1]){
                    right++;
                    ok = true;
                }
            }
            */

            //*Increment radius. 
            currRadius++;

            //*Calculating the range is relatively straightforward: just the difference between right and left. 
            //*This is correct since we always check right+1 or left+1 so we know right and left work. 
            
        }
        //!Doesn't make a difference whether this is inner or outer. 
        result = max(result, right-left+1);
    }
    cout << result << endl;


}
