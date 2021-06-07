#include <iostream>
#include <vector>

using namespace std;

long long min_difference(vector <long long> arr1, vector <long long> arr2){
    long long result = INT_MAX;
    for (long long i=0;i<arr1.size();i++){
        for (long long j=0;j<arr2.size();j++){
            result = min(result, abs(arr1[i]-arr2[j]));
        }
    }
    return result;
}
int main(){
    vector <long long> red, green, blue;

    long long n;
    cin >> n;
    long long a;
    char c;
    long long numRed = 0;
    long long numGreen = 0;
    long long numBlue = 0;
    //*Getting some weird compilation error should have done in python. 
    //*Even number of dogs. 
    for (long long i=0;i<(2*n);i++){
        cin >> a >> c;
        if (c=='R'){
            numRed++;
            red.push_back(a);
        }
        else if (c=='G'){
            numGreen++;
            green.push_back(a);
        }
        else if (c=='B'){
            numBlue++;
            blue.push_back(a);
        }
    }

    if (numRed % 2==0){
        if (numGreen % 2 ==0){
            //*All are even so return 0;
            cout << 0;
        }
        else{
            //*Green and blue are odd. 
            cout <<min_difference(green, blue);

        }
    }
    else{
        if (numGreen % 2 ==0){
            //*Red and blue are odd. 
            cout << min_difference(red,blue);
        }
        else{
            //*Red and green are odd. 
            cout << min_difference(red, green);
        }
    }

    //*How can I build all the permutations with pairs?
    //*I think the most naive way to do this is by generating permutation and pairing the ones side by side together. 
    //*There will be a ton of duplicates but naive approach so...

    //*Have to pay attention to the fact that if the color is same, dissatisfaction is 0. 
    //*So either even number of same color: just pair all of them up. 
    //*Must be either of these: odd, odd, even or even, even, even
    //*If even, even, even, answer is 0. 
    //*If odd, for the 2 odds, we could either do a nested or we could do like a 2 sum type linear thing. 



}