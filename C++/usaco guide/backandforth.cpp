#include <bits/stdc++.h>

using namespace std;

int main(){
    //*Really just simulate the process. 
    //*Number of buckets matter since I might have multiple of the same. 
    freopen("backforth.in", "r", stdin);
    freopen("backforth.out", "w", stdout);

    map <long long, long long> first, second;
    long long temp;
    for (long long i=0;i<10;i++){
        cin >> temp;
        if (first.count(temp)==0){
            first.insert({temp, 1});
        }
        else{
            first[temp]++;
        }
    }

    for (long long i=0;i<10;i++){
        cin >> temp;
        if (second.count(temp)==0){
            second.insert({temp, 1});
        }
        else{
            second[temp]++;
        }
    }

    long long first_amount, second_amount;
    first_amount = second_amount = 1000;

    //*2 first to seconds and 2 second to firsts. 
    //*4 movements in total. 
    //*Cannot do loop since need to evaluate all possibilities. 
    //*Could do brute force but want some practice with dicts too. 
    //*Deque will contain tuple of (turn, first_amount, second_amount, first, second)

    deque <tuple <long long, long long, long long, map <long long, long long>, map <long long, long long>>> q = {{0, first_amount, second_amount, first, second}};
    tuple <long long, long long, long long, map <long long, long long>, map <long long, long long>> curr;
    set <long long> result;
    while (!q.empty()){
        curr = q[0];
        q.pop_front();

        //Make sure correct indexing. 
        //At the end of monday:0, tuesday:1, wed: 2, thu: 3, friday:4
        if (get <0> (curr)==4){
            result.insert(get <1> (curr));
        }
        else{
            if (get <0> (curr) % 2==0){
                //*Moving from 1 to 2. 
                for (auto iter = (get<3> (curr)).begin(); iter!=(get<3>(curr)).end(); iter++){
                    if (iter->second>0){
                        auto next = curr;
                        //*Do all the re-assigning. 
                        get <1> (next) -= iter->first;
                        get <2> (next) += iter->first;
                        (get <3> (next))[iter->first]--;
                        //*If it doesn't exist in second, create it. 
                        if ((get <4> (next)).count(iter->first)==0){
                            (get <4> (next)).insert({iter->first, 1});
                        }
                        else{
                            (get <4> (next))[iter->first]++;
                        }

                        //*Add it to the queue. 
                        get <0> (next)++;
                        q.push_back(next);
                    }
                    
                }

            }
            else{
                for (auto iter = (get<4> (curr)).begin(); iter!=(get<4>(curr)).end(); iter++){
                    if (iter->second>0){
                        auto next = curr;
                        //*Do all the re-assigning. 
                        get <2> (next) -= iter->first;
                        get <1> (next) += iter->first;
                        get <4> (next)[iter->first]--;
                        //*If it doesn't exist in second, create it. 
                        if ((get <3> (next)).count(iter->first)==0){
                            (get <3> (next)).insert({iter->first, 1});
                        }
                        else{
                            (get <3> (next))[iter->first]++;
                        }

                        //*Add it to the queue. 
                        get <0> (next)++;
                        q.push_back(next);
                    }
                    
                }
            }
        }

    }

    cout << result.size() << endl;
    

}