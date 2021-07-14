#include <bits/stdc++.h>

using namespace std;

/*
int main(){
    //*Way easier if the question was to check whether a flag is canadian or not...
    //*First of all if the edges are not red then we obviously have to change that. 
    //!I think it is more of an issue of which gaps can I fill in. 
    //*Let me see whether this stragtegy might work. Something on those lines. 
    long long t;
    cin >> t;
    for (long long i=0;i<t;i++){
        long long n;
        string s;
        cin >> n >> s;

        long long result = 0;
        if (s[0]!='R'){
            result++;
            s[0]='R';
        }
        if (s[n-1]!='R'){
            result++;
            s[n-1]='R';
        }

        //*Create the changing array. 
        vector <long long> arr;
        for (long long j=0;j<n;j++){
            if (j==0 || s[j] != s[j-1]){
                arr.push_back(j);
            }
        }

        //*Now what do I do? 
        //!First of all a special case is where all elements are red. 
        //*If that is the case, there is no point trying to eliminate bumps so return 0. 
        //!Special case I need to deal with... (WRR)
        if (arr.size()==1){
            cout << result+1 << "\n";
        }
        else{
            while (arr.size()!=3){
                //*Cannot change the last 2 so loop through the middle ones. 
                long long minIndex;
                long long minValue = 99999999999;
                for (long long j=1;j<arr.size()-1;j++){
                    //*Compare the distance to the next. 
                    if (arr[j+1]-arr[j] < minValue){
                        minIndex = j;
                        minValue = arr[minIndex];
                    }
                }

                //*Remove some elements. 
                //!If I have to shave off time, it may be easier to remove elements from as back as possible. 
                result += arr[minIndex+1] - arr[minIndex];
                //*Since remaining shifts, I can erase at minIndex 2 times. 
                arr.erase(arr.begin()+minIndex);
                arr.erase(arr.begin()+minIndex);

            }
        }
        cout << result << "\n";
    }

    //!More of a generate permutation type approach? 
    
}
*/

/*
int main(){
    //!More of a generate permutation type approach? 
    //*To pass batch 1, I need to generate all permutations of R, W -> check whether they are canadian and compare with original string and see how many changes I need to make.
    //*Then minimize that. 
    long long t;
    cin >> t;
    
    for (long long i=0;i<t;i++){
        long long n;
        string s;
        cin >> n >> s;
        
        deque<string> q = {""};
        //*Queue of that certain length. Store the current string. 
        string curr;
        vector <string> all_perms;
        while (!q.empty()){
            curr = q[0];
            q.pop_front();

            if (curr.size()==n){
                all_perms.push_back(curr);
            }
            else{
                auto temp1 = curr;
                auto temp2 = curr;
                temp1.push_back('R');
                temp2.push_back('W');
                q.push_back(temp1);
                q.push_back(temp2);
            }
        }

        long long result = 999999999;

        for (auto perm: all_perms){
            if (perm=="RWR"){
                cout << "";
            }
            bool is_flag = true;
            long long curr_index = 0;
            while (perm[curr_index]=='R'){
                curr_index++;
            }
            //*After we break, we shouldn't be at 0. 
            if (curr_index==0){
                is_flag = false;
            }
            else{
                long long last_red = curr_index;
                while (perm[curr_index]=='W'){
                    curr_index++; //!Indexing just doesn't seem to be working...
                }
                //*When end, we should have moved. 
                //!Also, we should still not be at the end. 
                if (curr_index==last_red || curr_index == n){
                    is_flag = false;
                }
                else{
                    while (perm[curr_index]=='R'){
                        curr_index++;
                    }
                    //*Must end at a red. 
                    if (curr_index!=n){
                        is_flag= false;
                    }
                }
            }

            if (is_flag){
                long long differences = 0;
                for (long long j=0;j<n;j++){
                    if (perm[j] != s[j]){
                        differences++;
                    }
                }
                result = min(result, differences);
            }
        }

        cout << result << "\n";
    }

}
*/

//!Try to produce only canadian flag ones instead of all which become 2^n. 

int main(){
    long long t;
    cin >> t;
    
    for (long long i=0;i<t;i++){
        long long n;
        string s;
        cin >> n >> s;

        //*Information to store: current char, whether we can switch or not (relevant for red), and the actual string. 

        deque <tuple <char, bool, string>> q = {{'R', 1, ""}};
        tuple <char, bool, string> curr;

        vector <string> all_perms;
        
        while (!q.empty()){
            curr = q[0];
            q.pop_front();

            if ((get <2> (curr)).size()==n){
                all_perms.push_back((get <2> (curr)));
            }
            else{
                if (get <0> (curr)=='R'){
                    if (get <1> (curr) == 1){
                        auto temp1 = curr;
                        get <2> (temp1).push_back('R');
                        q.push_back(temp1);

                        auto temp2 = curr;
                        get <2> (temp2).push_back('W');
                        get <1> (temp1) = 0;
                        q.push_back(temp2);
                    }
                    else{
                        //*Cannot switch. 
                        auto temp1 = curr;
                        get <2> (temp1).push_back('R');
                        q.push_back(temp1);
                    }
                }
                else{
                    auto temp1 = curr;
                    get <2> (temp1).push_back('W');
                    q.push_back(temp1);

                    auto temp2 = curr;
                    get <2> (temp2).push_back('R');
                    q.push_back(temp2);
                }
            }
        }

        long long result = 999999999;
        //!WHY 0? IS it haunting me or what??
        for (auto perm: all_perms){

                long long differences = 0;
                for (long long j=0;j<n;j++){
                    if (perm[j] != s[j]){
                        differences++;
                    }
                }
                result = min(result, differences);
            
        }

        cout << result << "\n";


    }
}