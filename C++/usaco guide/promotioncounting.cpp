#include <iostream>
#include <fstream>
using namespace std;

int main(){
    //*Kind of a confusing problem because of standing. 
    //*If the starting is larger than the ending, that must mean that some joined from bronze. 
    //!I feel like it doesn't make a difference if one guy moves all the way upto plantinum vs 1 person moving one by one. 
    //!The results don't change either way. 

    ifstream fin("promote.in");
    ofstream fout("promote.out");

    //*I think I can just check from the top and subtract values. 
    //!Wouldn't it be easier if I could store the values in an array instead of so many variables?

    int broze1, bronze2, silver1, silver2, gold1, gold2, plat1, plat2;

    fin >> broze1 >> bronze2 >> silver1 >> silver2 >> gold1 >> gold2 >> plat1 >> plat2;

    //!It can be very well the case that there aren't enough people at silver to fill in platinum. 
    //*I am confused on how to organize the question. 

    //!Pretty logical when I think about it. 
    //*As the guys on top climb, we need that many guys from the bottom to fill up. 
    
    
    fout << silver2 - silver1 + gold2 - gold1 + plat2 - plat1 << endl;
    fout << gold2 - gold1 + plat2 - plat1 << endl;
    fout << plat2 - plat1 << endl;
    //*Don't care about promotion to bronze. 
}