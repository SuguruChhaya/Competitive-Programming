#include <bits/stdc++.h>
using namespace std;

//*Obviously we need to keep track of all cows. 
//*probably will need a struct to indicate who is the mother of who. 
//!I need to create a struct with a mother class. 
//*Need to deal with a lot of pointers. 

struct Cow{
    unique_ptr<Cow> mother;
    long long val=0;
};
/*
struct Cow2{
    Cow2* mother;
    long long val;
};
*/
vector <Cow*> all_cows;
//vector <Cow2*> all_cows2;


int main(){
    //*Pretty damn challenging but somewhat manageable maybe. 
    Cow a;
    
    all_cows.push_back(&a);
    unique_ptr<Cow> curr = all_cows[0];
    for (long long i=0;i<5;i++){
        //*I need to know how to traverse through this thing. 
        curr->mother = make_unique<Cow>();
        (*(curr->mother)).val = i;
        curr = curr->mother;
    }

    all_cows[0]->mother = make_unique<Cow>();
    (*(all_cows[0]->mother)).val = 5;
    cout << (*(all_cows[0]->mother)).val << endl;
    cout << (*(a.mother)).val << endl;

    Cow2 b;
    all_cows2.push_back(&b);
    Cow2 next;
    all_cows2[1]->mother = &next;
    (*(all_cows2[1]->mother)).val = 5;
    cout << (*(all_cows2[1]->mother)).val << endl;
    cout << (*(a.mother)).val << endl;
}