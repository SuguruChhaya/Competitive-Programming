#include <bits/stdc++.h>
using namespace std;

vector <vector <long long>> arr;
//*Store all to check for a cycle. 

bool found_cycle(){
    //*Check whether the last element and current element match. 
    //*Only exception is when size is 0 or 1 (since that will always be cycle)
    if (arr.size() > 1 && arr[0]==arr[arr.size()-1]){
        return true;
    }
    return false;
}


int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    //freopen("swap.in", "r", stdin);
    //freopen("swap.out", "w", stdout);

    //*I can not simulate this for 10^9 times since too much time. 
    //!I think the best way is to detect a cycle. 

    long long n, k;
    cin >> n >> k;
    
    vector <long long> curr;
    //!Make it 1-index to avoid confusion?
    for (long long i=0;i<=n;i++){
        curr.push_back(i);
    }

    long long a_1, a_2, b_1, b_2;
    cin >> a_1 >> a_2 >> b_1 >> b_2;

    //!We keep until we hit our goal or we find a cycle. 
    long long count = 0;
    
    while (count < k && (!found_cycle())){
        //cout << (count < k) << endl;
        //cout << !found_cycle() << endl;
        //*Do the reversing. 
        //?How am I gonna reverse??
        //!I don't need to pop back as long as I push the current here. 
        //!Also I cannot forget to push back the initial element. 
        auto next = curr;
        arr.push_back(curr);
        next = curr;
        //!Must be 1-indexed. 
        for (long long i=0;i<=a_2-a_1;i++){
            next[a_2-i] = curr[a_1+i];
        }
        curr = next;
        
        for (long long i=0;i<=b_2-b_1;i++){
            next[b_2-i] = curr[b_1+i];
        }

        //!Need to push back to the vector. 
        
        //*Switch the arrays. 
        curr = next;
        //*Then increment count. 
        count++;
        //cout << "stuck" << endl;
        //!Not a never-ending while loop buck still stuck nevertheless. 
        //cout << found_cycle() << endl;
    }

    //*If the count isn't equal to k, we still have to do some work. 
    if (count!=k){
        //*Firstly, the last element and first element are equal so might want to pop_back that. 
        arr.pop_back();
        curr = arr[k % arr.size()];
    }

    for (long long i=1;i<=n;i++){
        cout << curr[i] << endl;
    }

}