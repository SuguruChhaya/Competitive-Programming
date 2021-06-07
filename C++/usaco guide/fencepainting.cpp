#include <iostream>
#include <fstream>
using namespace std;

int main(){
    int a, b, c, d;
    int total = 0;
    ifstream fin("paint.in");
    ofstream fout("paint.out");
    fin >> a >> b >> c >> d;

    //!Kind  of a shame I cannot even get basic logic right but an array is a better strat. 
    //*The interval mixing. 
    /*
    if (c < a){
        if (d<=a){
            total = (d-c) + (b-a);
        }
        else if (a <= d <= b){
            total = (a-c) + (b-a);
        }
        else if (d > b){
            total = (d-c);
        }
    else if (a <= c <= b){
        if (d <= b){
            total = (b-a);
        }
        else{
            total = (b-a) + (d-b);
        }
    }
    else{
        total = (b-a) + (d-c);
    }
    fout << total;
    */
    //!I now understand why I got initial one wrong. 
    //*Interval and doesn't include the node. 
    //!Still some cases aren't included lol. 
    //?How am I gonna make sure these things represent intervals?
    //!OK the length should be 100 because 0-100 inclusive means 101 and there are 100 inteverals. 
    //*Interval between 0-1 is index 0. 
    int arr [100];

    for (int i=0;i<100;i++){
        arr[i] =0;
    }
    
    for (int i=a; i<b;i++){
        arr[i] = 1;
    }

    for (int i=c;i<d;i++){
        arr[i] = 1;
    }
    
    for (int i=0;i<100;i++){
        total += arr[i];
    }
    fout << total;

    //*Make sure no trailing space. 
}

