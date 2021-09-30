#include <bits/stdc++.h>
using namespace std;


int main(){

    //*I don't think it is the integer type...
    //*Something else that I am missing...
    long long n, temp;
    cin >> n;
    long long queue_size = 0;
    deque <pair <long long, long long>> queue;

    vector <pair <long long, long long>> result;
    long long result_num = 0;
    //*Store the number and the frequency. Try to balance it later. 
    //*Just to make simpler, I could store keys in a separate set. 
    for (long long i=1;i<=2*n;i++){
        cin >> temp;

        //*i is the 1-indexed index. 
        //*If size is 0 then push back or if equal to first element then push back. 
        if (queue.size() ==0 || temp==queue[0].first){
            queue.push_back({temp, i});
            queue_size++;
        }
        //!We don't know until the end so we can store in a vector so we can print at the end. 
        else{
            //*No problem with the size of result...
            result.push_back({i, queue[0].second});
            queue.pop_front();
            result_num++;
            queue_size--;
        }
        //!Probably don't need to push back. 
        //*Have to check all the time whether it exists in the map??
        
        /*
        hashset.insert(temp);
        if (hashmap.count(temp)==0){
            hashmap.insert({temp, 1});
        }
        else{
            hashmap[temp]++;
        }
        */



        //!Probably have to count the frequency. 

        //!Doesn't matter the pairing as long as they are different. 

        //!As we go, we could iterate through dictionary key and then start making the pairings. 

        //*Maybe related to majority stuff. 
        //*How the thing can be balanced maybe. 

    }

    cout << result_num << "\n";
    //*Maybe issue with size. .size() hopefull returns a long long...
    //*Or I could just manually keep track. 
    for (long long i=0;i<result_num;i++){
        cout << result[i].first << " " << result[i].second << "\n";
    }

    //*Cannot forget to output the stuff remaining in the queue. 
    for (long long i=0;i<queue_size;i+=2){
        cout << queue[i].second << " " << queue[i+1].second << "\n";
    }
    /*
    long long first=0;
    long long second=0;
    for (auto element:hashset){
        if (first < second){
            first += hashmap[element];
        }
        else{
            second += hashmap[element];
        }
    }
    */

    //*Need to store the index...

    //!Store it in a queue since all elements in the queue will be the same. 

    //*So if I were to match up, we must be removing from the beginning.
    //*Only need to check the first element in the queue. 
}