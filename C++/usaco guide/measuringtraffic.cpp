#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

int main(){
    freopen("traffic.in", "r", stdin);
    freopen("traffic.out", "w", stdout);

    //*Failing a couple, what am I not considering? 

    int n;
    cin >> n;

    int lower;
    int upper;
    string type;
    int l, u;
    vector <tuple <string, int, int>> arr;
    //!Actually, I have to find the first none anyways. 
    /*
    for (int i=0;i<n;i++){
        //*If "on" then traffic can enter the highway. 
        //*If "off" then traffic can leave the highway. 

        //*On the on ramp, between a to b cars entered. 
        //*I guess the trick for the first one is that 10-14 doesn't shift to 9-13. Never mentions that it was 10 that's why. 
        //*But it couldn't have been 14 before ramp because even if it was 14 after ramp, maximum is 14-1=13 so no chance it could have been that. 

        //*I think a good strategy is to look at the first none and move both ends from there. 
        //*Until then, store the values in a tuple maybe. 

        //*At least one of the highway segments is desgined as "none" so don't have to worry about upper bound. 

        cin >> type >> l >> u;

        if (type=="none"){
            //*Squeeze the range. 
            lower = max(lower, l);
            upper = min(upper, u);
        }
        else if (type=="on"){

        }
    }
    */

    for (int i=0;i<n;i++){
        cin >> type >> l >> u;
        arr.push_back({type, l, u});
    }
    int index;
    int start_low, start_high, end_low, end_high;
    end_low = 0;
    end_high = 99999999;

    
    /*
    for (int i=index;i>=0;i--){
        //*Deduct one by one. 
        if (get <0> (arr[i])=="none"){
            start_low = max(start_low, get <1> (arr[i]));
            start_high = min(start_high, get <2> (arr[i]));
        }

        else if (get <1> (arr[i])=="on"){
            //*Wait tho why isn't it 9-13 instead of 10-13? It could have been 9-13 right? 
            //*I think in the opposite way "on" really acts like an off but I guess somewhat different...


        }
    }
    */

    //!I see why now!!
    //*Cannot just go back from where it started. 
    //*Then wouldn't I have to revise the information provided a lot of times??
    //*Since it could have become more accurate as I go. 
    //*I think the best way it to first figure out the most specific ending and then backtrack to figure out most specific starting. 
    
    for (int i=0;i<n;i++){
        //*end_low and high are already initialized. 
        if (get <0> (arr[i])=="none"){
            end_low = max(end_low, get<1> (arr[i]));
            end_high = min(end_high, get <2> (arr[i]));
            end_low = max(0, end_low);
            end_high = max(0,end_high);

        }
        else if (get <0> (arr[i])=="off"){
            //*Can just plug into the formula. 
            end_low -= get <2> (arr[i]);
            end_high -= get<1> (arr[i]);
            end_low = max(0, end_low);
            end_high = max(0,end_high);
        }

        else{
            end_low += get <1> (arr[i]);
            end_high += get <2> (arr[i]);

        }
    }

    //*After we get, we can reverse and get first. 
    start_low = end_low;
    start_high = end_high;
    for (int i=(n-1);i>=0;i--){
        if (get <0> (arr[i])=="none"){
            start_low = max(start_low, get<1> (arr[i]));
            start_high = min(start_high, get <2> (arr[i]));
            start_low = max(0, start_low);
            start_high = max(0, start_high);
        }
        else if (get <0> (arr[i])=="on"){
            //*Can just plug into the formula. 
            start_low -= get <2> (arr[i]);
            start_high -= get<1> (arr[i]);
            start_low = max(0, start_low);
            start_high = max(0, start_high);
        }
        //?No idea wtf I got wrong...
        //!I have to accomodate for the case of negative. 
        
        //*I really don't understand why this version can fail...
        //!Doesn't have to be the same values going and coming back. 
        //*Did become more accurate but still no...
        //*Actually, if there were at least 5000 cars that came in and the range is 3000, 6000 -> should be 5000. 
        //*That's why I have to consider that as well. 
        //?But what if I first derive the end and use that info to derive the start? Will it give me the same result? 
        //!Did get the correct one anyways. 
        else{
            start_low += get <1> (arr[i]);
            start_high += get <2> (arr[i]);

        }
    }

    cout << start_low << " " << start_high << "\n";
    cout << end_low << " " << end_high << "\n";    
}