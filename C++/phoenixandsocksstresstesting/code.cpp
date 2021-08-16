#include <bits/stdc++.h>
using namespace std;

int main(){
    long long t;
    cin >> t;
    for (long long i=0;i<t;i++){
        long long n, l, r; 
        cin >> n >> l >> r;
        map <long long, long long> ld, rd;
        for (long long j=0;j<l;j++){
            long long temp;
            cin >> temp;
            if (ld.count(temp)==1){
                ld[temp]++;
            }
            else{
                ld.insert({temp, 1});
            }
        }
        for (long long j=0;j<r;j++){
            long long temp;
            cin >> temp;
            if (rd.count(temp)==1){
                rd[temp]++;
            }
            else{
                rd.insert({temp, 1});
            }
        }
        //!Pretty sure a greedy approach will work just fine. 
        //*Cannot just change random socks from left to right. Need to change strategically. 
        //*Data structure-wise, I think multiset or dictionary makes sense. 

        //!Make left side larger than right side. 
        if (l<r){
            swap(ld, rd);
            //*l and r are going to be used for counting purposes. 
            swap(l, r);
        }


        //!Cannot do greedy and change right away when nothing exists. 
        //*First have to take care of ones that exist. 
        for (auto left:ld){
            if (rd.count(left.first)==1){
                //*The same sock color exists. 
                long long min_remove = min(left.second, rd[left.first]);
                //!I think my mistake was that I need to use indexing to reduce. 
                ld[left.first]-=min_remove;
                //left.second-=min_remove;
                //*Remove the amount of socks. 
                l-=min_remove;
                rd[left.first]-=min_remove;
                r-=min_remove;
            }
        }
        /*
        for (auto e:ld){
            cout << e.first << " " << e.second << endl;
        }
        cout << "rd" << endl;
        for (auto e:rd){
            cout << e.first << " " << e.second << endl;
        }
        */
        //*How do I make sure I can process all?
        //!Just a normal implementation problem. 
        long long result = 0;
        //!There are gonna be more left socks than right socks at this point. 
        for (auto left:ld){
            /*
            if (left.first==13){
                cout << "";
            }
            */
            //cout << left.first << " " << left.second << endl;

            long long extra = l-r;

            //*How many I can move. 
            long long can_do = left.second / 2;
            long long Do = min(can_do*2, extra);
            //*Basically ensuring that we don't go off and tip off the balance. 
            result += Do / 2;
            l-=Do;
        }

        result += (l-r) / 2 + (l+r) / 2;
        cout << result << "\n";
        //*Iterate but 
        /*
        for (auto left:ld){
            //!I need to make sure l is still larger than r...
            result += left.second / 2;
            left.second = left.second % 2;
            
        }
        */

    }
}