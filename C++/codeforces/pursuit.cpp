#include <bits/stdc++.h>
using namespace std;

bool keep_adding(vector <long long> a, vector <long long> b){
    //!It is the number that is chosen!!
    //!I should really try these problems on my own too!
    long long numChoose = a.size() - floor(a.size() / 4);
    //*Sum it up and return true or false. 
    long long a_sum =0, b_sum = 0;
    for (long long i=0;i<numChoose;i++){
        a_sum+=a[a.size()-1-i];
        b_sum+=b[i];
    }

    if (a_sum >= b_sum){
        return false;
        //*Aleady achieved goal. 
    }
    else{
        return true;
    }
}

int main(){
    //*The smallest number will remain as the smallest number. I just need to sort once (if I will ever have to). Probably not good idea to use set. 
    //*This is because we will keep adding 100 to our score and 0 to friend's score. 

    //!First just try to implement the most brute force and keep improving from there. 

    long long t;
    cin >> t;
    vector <long long> results;
    for (long long i=0;i<t;i++){
        long long n;
        cin >> n;
        vector <long long> a, b;
        for (long long j=0;j<n;j++){
            long long temp;
            cin >> temp;
            a.push_back(temp);
        }

        for (long long j=0;j<n;j++){
            long long temp;
            cin >> temp;
            b.push_back(temp);
        }

        //!Most brute force so sort naively and push_back naively. 
        sort(a.begin(), a.end());
        sort(b.begin(), b.end(), greater<>());

        long long result = 0;
        while (keep_adding(a, b)){
            a.push_back(100);
            b.insert(b.begin(), 0);
            result++;
        }

        results.push_back(result);
    }

    for (auto e:results){
        cout << e << endl;
    }
}