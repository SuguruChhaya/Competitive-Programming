#include <bits/stdc++.h>
using namespace std;

int main(){

    //freopen("outofplace.in", "r", stdin);
    //freopen("outofplace.out", "w", stdout);

    long long n;
    cin >> n;
    vector <long long> arr;
    for (long long i=0;i<n;i++){
        long long temp;
        cin >> temp;    
        //*We don't know which one is the out of place one because could be increasing but still out of place. 
        arr.push_back(temp);
    }

    //*Every move, we have to check whether it is sorted. 
    //*Only 1-index is out. 

    //!If the number decreased, it is clearly out of place. 
    //*If it increases, we have to check the next element to make sure it is larger. 

    //!There is a chance that bessie moved but it is already sorted. 
    //*In that case, the wrong_index will be -1. 
    long long wrong_index = -1;
    for (long long i=0;i<n;i++){
        bool ok = true;
        if (i > 0){
            //*Check back.
            if (arr[i] < arr[i-1]){
                ok = false;
            } 
        }
        if (i < n-1){
            //*Check front. 
            if (arr[i] > arr[i+1]){
                ok = false;
            }
        }

        if (ok==false){
            wrong_index = i;
            //!Need to break since the next one would also fall into the false category but we know it is the first one that is the troublemaker. 
            break;
        }
    }

    if (wrong_index==-1){
        cout << 0 << endl;
    }
    //!I could do this while loop thing but I think it is easier to count the number of unique elements to the correct position. 
    
    
    else{
        //cout << wrong_index << endl;
        long long result =0;
        while (!(arr[wrong_index] <= arr[wrong_index+1] && arr[wrong_index-1] <= arr[wrong_index])){
            //*Consider smaller case too. 
            //*I can try going both ways and either will work. 
            if (!arr[wrong_index-1] <= arr[wrong_index]){
                long long l = wrong_index-1, left_value = arr[wrong_index-1];
                while (l >= 0 && arr[l]==left_value){
                    //*Small element got pushed to the right. 
                    //!At least moves 1 to the right all the time. 
                    l--;
                }
                l++;
                long long temp = arr[l];
                arr[l] = arr[wrong_index];
                arr[wrong_index] = temp;
                wrong_index = l;
                //cout << "stuck" << endl;
            }
            else{
                long long r = wrong_index+1, right_value = arr[wrong_index+1];
                while (r < n && arr[r]==right_value){
                    r++;
                }
                r--;
                long long temp = arr[r];
                arr[r] = arr[wrong_index];
                arr[wrong_index] = temp;
                wrong_index = r;
                //cout << "stuck2" << endl;
            }
            result++;
            

        }
        cout << result << endl;
    }
    

}