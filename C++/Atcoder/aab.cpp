#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <math.h>
using namespace std;

void showHashset(set <string>hashset){
    string temp;
    for (int i=0;i<hashset.size();i++){
        cout << *next(hashset.begin(), i);
    }
}


    //*I might have to build all the permutations. 
    //*I would try sorting it later but will probably run out of time. 
    //*There is probably some manual way to do it. 
    //*Kind of like let the bs take over the left side little by little. 
    

    /*
    int temp_a, temp_b;
    string next_a, next_b;
    set <string> hashset;
    string curr;
    //*Just generate all and check if matches the conditions. 
    vector <string> queue = {""};

    while (queue.size() > 0){
        curr = queue[0];
        queue.erase(queue.begin());
        if (curr.size()==a+b){
            //*Iterate and check for the occurences. 
            temp_a = 0;
            temp_b = 0;
            for (int i=0;i<a+b;i++){
                if (curr[i]=='a'){
                    temp_a += 1;
                }
                else{
                    temp_b += 1;
                }
            }
            if (temp_a==a && temp_b==b){
                hashset.insert(curr);
            }
        }
        else{
            queue.push_back(curr + "a");
            queue.push_back(curr + "b");
        }
    }
    //showHashset(hashset);
    //!Not gonna work for crazy long examples. 
    //!I shouldn't be generating 2^60 size integer and trying to run a linear search to find. 
    //*Is there some kind of pattern here?
    //*Kind of similar to: using these numbers, generate the kth largest number. 
    //!Possibly useful article: https://www.geeksforgeeks.org/get-the-kth-smallest-number-using-the-digits-of-the-given-number/
    //*Memset just generates the concantenated version of that list. 
    string result = *next(hashset.begin(),k-1);
    cout << result;
    */
    //!Seems like there is this handy function called next_permutation that gets the permutation for me. 
    /*
    int a, b;
    long long k;
    cin >> a >> b >> k;

    string curr;
    for (int i=0;i<a;i++){
        curr += "a";
    }
    for (int i=0;i<b;i++){
        curr += "b";
    }

    //!I guess next permutation still wasn't good enough...
    //!Definitely look at editorial. 
    for (long long i=1;i<k;i++){
        next_permutation(curr.begin(), curr.end());
    }

    cout << curr;
    */

   //!The fact that there are only 2 numbers is significant in my opinion. 
   //*Convert to binary numbers. 

//!Need to only check the first n numbers. 
//*Convert to binary and run iteration to check whether it is a number that falls in the patter. 

int a, b;
long long k;
long long binary_to_decimal (string binary){
    //*I guess the easier way it to start from the end and keep adding. 
    long long result=0;
    int curr; //*Either 1 or 0. 
    for (int i=binary.size()-1; i>=0;i--){
        curr = stoi(string(1, binary[i]));
        if (curr==1){
            result += pow(2, binary.size()-1-i);
        }
    }

    return result;
}

string decimal_to_binary (long long decimal){
    //!I need to make sure I add header 0s. 
    string result;
    string temp;
    for (int i=0;decimal>0;i++){
        //!OK so the << not working is legit. I just need to figure out a better way. 
        //!Definitely not correct. 
        result = to_string(decimal % 2) + result;
        decimal = (decimal - (decimal % 2)) / 2;
    }
    //!Why does it just not return man?

    while (result.size() < (a+b)){
        result = "0" + result;
    }
    //*Wanna prevent reversing but...
    return result;
}

/*
int main(){
    //*Still doesn't run fast enough.
    cin >> a >> b >> k;
    string start = "";
    for (int i=0;i<a;i++){
        start += "0";
    }
    //*Definitely something wrong with the binary to decimal thingy.
    //cout << binary_to_decimal("101");
    for (int j=0;j<b;j++){
        start += "1";
    }

    //*First convert to decimal. 
    //cout << decimal_to_binary(5);
    long long curr = binary_to_decimal(start);
    long long curr_increment = 1;
    //*We start off at the 1st smallest number. 
    string current_binary;
    int num_a;
    int num_b;
    while (curr_increment < k){
        curr++;
        current_binary = decimal_to_binary(curr);
        num_a = 0;
        num_b = 0;
        for (int i=0;i<current_binary.size();i++){
            if (current_binary[i]=='0'){
                num_a++;
            }
            else{
                num_b++;
            }
        }
        if (num_a == a && num_b == b){
            curr_increment++;
        }

    }
    string result;
    for (int i=0;i<current_binary.size();i++){
        if (current_binary[i]=='0'){
            result += "a";
        }
        else{
            result += "b";
        }
    }

    cout << result;
}
*/
vector <vector <long long>> dp;
vector <long long> temp;
vector <vector <int>> queue;
vector <int> curr;
string temp_string;
int recursive(int row, int col){
    if (row==0 || col==0){
        return 0;
    }
    //*Check whether it already exists in the dp array or not. 
    else if (dp[row][col] != 0){
        return dp[row][col];
    }
    else{
        dp[row][col] = recursive(row-1, col) + recursive(row, col-1);
        return dp[row][col];
    }

}

string recursive2(string curr_string, int row, int col, long long curr_k){
    if (row==0){
        //!If row==0 that means we used up all "a"s and we have to start using "b"s.
        for (int i=0;i<col;i++){
            curr_string += 'b';
        }
    }
    else if (col==0){
        for (int i=0;i<row;i++){
            //!Still something wrong anyways. 

            curr_string += 'a';
        }
    }
    else{
        //*I think the way I built this array might be different 
        //!Yep, to if I go 1 below I am using an a so it should be row-1
        //*Still don't understand how my implementation failed. 

        if (dp[row-1][col] >= curr_k){
            //*If we are using a, we would have to subtract 1 from row instead of col just becuase of how I set up the array.  
            //!We are adding on to it right?
            curr_string = recursive2(curr_string+'a', row-1, col, curr_k);
        }
        else{
            curr_string = recursive2(curr_string+'b', row, col-1, curr_k - dp[row-1][col]);
        }
    }
    return curr_string;
}

void showVector (vector <vector <long long>> arr){
    for (int row=0;row<arr.size();row++){
        for (int col=0;col<arr[row].size();col++){
            cout << arr[row][col] << " ";
        }
        cout << endl;
    }
}

int main(){
    //*Determine the first letter whether a or b. 
    //*I understand how it can be represented in a graph and direction. And how I can use DP to store how many ways I can get there using right (adding a) or down (adding b).
    //*I understand that k cannot be larger than top right number. 
    //*Finally kind of get the idea. 
    //*Since moving right at the end move and we are backtracing, we can say that the number on left is when we move "a" first. 
    //*When I draw it out, it actually starts to make more sense. 
    //*If the we doesn't exceed the goal line, we know that we must pick a b or else we will never reach the target. 
    //*When this is the case, for the new consideration, all the values upto the point of the last A must not be considered. 
    //*On the other hand, if the exceed the goal line, we know we must pick "a" to get into the right zone. We don't cut anything for the next consideration. 

    //*Store in a 2d array temporarily. 




    cin >> a >> b >> k;
    //*Initialize the values to 0 to check if pre-calculated. 
    //*Need to include number of rows is a+1 since we have to include case when number of a=0.
    
    for (int row=0;row<=a;row++){
        temp = {};
        for (int col=0;col<=b;col++){
            temp.push_back(0);
        }
        dp.push_back(temp);
    }
    //*Could have build up 1st row and 1st col and went from there. 
    //recursive(a, b);

    //!Just do the entire dp array thing iteratively. 
    for (int row=0;row<=a;row++){
        dp[row][0]=1;
    }
    for (int col=0;col<=b;col++){
        dp[0][col]=1;
    }

    for (int row=1;row<=a;row++){
        for (int col=1;col<=b;col++){
            dp[row][col] = dp[row-1][col] + dp[row][col-1];
        }
    }

    //*Hate recursion now so do everything iteratively. 
    //!We actually have to do this recursively for top down. 

    //showVector(dp);
    //*Better do this one recursively because we need to contain string and cannot include in int vector. 
    //cout << recursive2("", a, b, k);

    //!Since there are no seperate branches, I can just do it iteratively. 


/*
        if (dp[row-1][col] >= curr_k){
            //*If we are using a, we would have to subtract 1 from row instead of col just becuase of how I set up the array.  
            //!We are adding on to it right?
            curr_string = recursive2(curr_string+'a', row-1, col, curr_k);
        }
        else{
            curr_string = recursive2(curr_string+'b', row, col-1, curr_k - dp[row-1][col]);
        }
*/
    //*Do it until we hit a border.
    while (a > 0 && b > 0){
        if (dp[a-1][b] >= k){
            cout << 'a';
            a--;
        }
        else{
            cout << 'b';
            k -= dp[a-1][b];
            b--;
            
        }
    }

    while (a>0){
        cout << 'a';
        a--;
    }
    while (b>0){
        cout << 'b';
        b--;
    }

}