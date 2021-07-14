#include <bits/stdc++.h>

using namespace std;

int main(){
    //*The number can be upto 10^9 so impossible to store in a 2D vector. 
    //*The tricky part must be to identify infinite. 

    long long n;
    cin >>n;
    vector <tuple <char, long long, long long>> arr;
    for (long long i=0;i<n;i++){
        char c;
        long long x, y;
        cin >> c >> x >> y;
        arr.push_back({c, x, y});
        //*If it goes out of bounds I guess that will be infinity??
        //!I think I can just match up all the points and see whether they intersect. 
        //*I can find the points that intersect first. 
        //*2 points can only be intersecting once. 
        //!Have to consider all the cases. E.g. even if 2 points are both going east, if they are on same y-value, they will still intersect.


    }
    //!To avoid "thought it intersected but it was stopped earlier" issues:
    //*Add all the points it could intersect with. 
    //!But that number could still be 1 and how can we "cancel out" when we know it wouldn't work out?

    


    //!Constructing a grid is just impossible since could take 10^18 time. 
    for (auto (p1):arr){
        //*Printing results. 
        bool infinity = true;
        long long distance = 99999999999999999999;
        for (auto (p2):arr){
            //*Firstly they cannot be equal to each other. 
            //!Does auto even check for equality??
            if ((p1) != (p2)){
                if (get <0> (p1)=='N'){
                    if (get <0> (p2)=='N'){
                        //*Only concerned about (p1) at this point. 
                        //!All starts out at a different cell. 
                        //*If the x-value is the same and (p1) is at lower position, it would intersect. 
                        if (get <1> (p1)==get<1> (p2) && get<2> (p1) < get<2> (p2)){
                            infinity = false;
                            distance = min(distance, get<2> (p2) - get <2> (p1));
                        }
                        //*Otherwise no chance. 
                    }
                    //!Only north and east lol!! 
                    else if (get <0> (p2) =='E'){
                        //*If the east one starts to the right there is no point. 
                        //!X is not strict because it could intersect starting point. 
                        //!But Y must be strict because otherwise (p1) won't intersect. 
                        if (get <1> (p1) >= get <1> (p2) && get <2> (p1) < get <2> (p2)){
                            //*Pretty much the condition is the same but the calculation is different. 
                            //*If the distance from intersecting point is equal then no point. 
                            vector <long long> intersect = {get <1> (p1), get <2> (p2)};
                            if (intersect[1]-get <2> (p1) > intersect[0]-get<1> (p2)){
                                //*If (p2) gets there faster, that means (p1) will intersect. Strict. 
                                infinity = false;
                                distance = min(distance, intersect[1]-get <2> (p1));
                            }
                        }

                        
                    }
                }
                else if (get <0> (p1) == 'E'){
                    if (get <0> (p2) == 'E'){
                        //*Similar to NN. 
                        if (get <2> (p1) == get <2> (p2) && get<1> (p1) < get <1> (p2)){
                            infinity = false;
                            distance = min(distance, get <1> (p2) - get <1> (p1));
                        }
                    }
                    else if (get <0> (p2) == 'N'){
                        if (get <1> (p1) < get <1> (p2) && get <2> (p1) >= get <2> (p2)){
                            vector <long long> intersect = {get <1> (p2), get <2> (p1)};
                            if (intersect[0]-get<1> (p1) > intersect[1]-get<2> (p2)){
                                //cout << get <0> (p1) << " " << get <1> (p1) << " " << get <2> (p1) << endl;
                                //cout << get <0> (p2) << " " << get <1> (p2) << " " << get <2> (p2) << endl;
                                infinity = false;
                                distance = min(distance, intersect[0]-get<1> (p1));
                            }
                        }
                    }
                }

                //*Now we update and can print the values. 

            }
        }

        if (infinity==false){
            cout << distance << endl;
        }
        else{
            cout << "Infinity" << endl;
        }
    }
}