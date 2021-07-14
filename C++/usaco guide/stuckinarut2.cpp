#include <bits/stdc++.h>

using namespace std;




int main(){
    /*
    freopen("stuckinrut/3.in", "r", stdin);
    freopen("stuckinrut/3m.out", "w", stdout);
    */
    ifstream question("stuckinrut/3.in");
    ofstream my_answer("stuckinrut/3m.out");

    long long n;
    question >> n;

    //*Store all the visited index in a set

    //!For the "interesting event" approach, I need to keep track of the current locations for each point. 
    //!Don't know whether I should remove the list but if not I at least need some kind of boolean value. 

    vector <tuple <char, long long, long long, bool>> arr;
    vector <long long> result;
    for (long long i=0;i<n;i++){
        char c;
        long long x, y;
        question >> c >> x >> y;
        arr.push_back({c, x, y, true});
        result.push_back(-1);
        //!I guess I can say if -1 then it goes upto infinity. 
    }

    //*While there are still interesting moves remaining keep running the loop. 
    bool ok = true;

    long long numIterations = 0;
    long long addTime = 0;
    while (ok){

        //!Some kind of north-east mistake. 

        //*I am really close though...
        ok = false;
        //!Stores the next time it is gonna intersect. 
        //*I also have to store the index of the element I am gonna remove. 
        
        //*Increment the time based on the distance. 
        long long distance = 99999999999;
        //!Vector contains the indexes of the points that will be removed next. 
        set <long long> next_remove;
        for (long long i=0;i<arr.size();i++){
            //*Check whether I intersects with j. 
            //*Meaning whether i would get removed or not. 
            //!What if multiple intersections will happen at once??
            //*I guess I can keep a vector for that...
            for (long long j=0;j<arr.size();j++){

                if (i==3 && j==8){
                    //cout << get <1> (arr[i]) <<  " " << get <2> (arr[i]) << endl;
                    //cout << get <1> (arr[j]) <<  " " << get <2> (arr[j]) << endl;
                }


                if (i!=j && get <3> (arr[i])==true && get <3> (arr[j])==true){
                    //*I guess I could define the variable so I can replace all. 

                    //*The location alse depends on the direction. 
                    long long x_i, y_i, x_j, y_j;

                    //!The problem wasn't initialization...
                    x_i = get <1> (arr[i]);
                    y_i = get <2> (arr[i]);
                    x_j = get <1> (arr[j]);
                    y_j = get <2> (arr[j]);
                    if (get <0> (arr[i])=='E'){
                        x_i += addTime;
                    }
                    //!Shit the values need to be updated otherwise it is gonna keep random values. y_i will remain undefined otherwise!!
                    else{
                        y_i += addTime;
                    }

                    if (get <0> (arr[j])=='E'){
                        x_j += addTime;
                    }
                    else{
                        y_j += addTime;
                    }

                    //!Wouldn't adding the time literally be the same concept though? 
                    //*I guess the distance calculation is the only thing that has to be done using the updated values. 
                    //*Other than that, all the points will be preserved and intersect-able. 
                    if (get <0> (arr[i])=='N'){
                        if (get <0> (arr[j])=='N'){
                            if (get <1> (arr[i])==get<1> (arr[j]) && get<2> (arr[i]) < get<2> (arr[j])){
                                //*There will be at least one intersection. 
                                //!I also have to make sure they don't overlap. 
                                //!For N and N it isn't a problem since it will never overlap. 
                                //!No but I still need the accurate distance though. 
                                ok = true;
                                vector <long long> intersect = {get <1> (arr[j]), get <2> (arr[j])};
                                //!N and N doesn't have a big trouble since it is intersecting its original starting point. 
                                if (intersect[1] - y_i < distance){
                                    //*If smaller that replace the entire vector and change the value. 
                                    distance = intersect[1] - y_i;
                                    next_remove = {i};
                                }

                                else if (intersect[1] - y_i == distance){
                                    next_remove.insert(i);
                                }
                                //!If larger then don't do anything. 
                            }
                        }
                        else if (get <0> (arr[j])=='E'){
                            if (get <1> (arr[i]) >= get <1> (arr[j]) && get <2> (arr[i]) < get <2> (arr[j])){
                                //!Check the intersect-ablility. 
                                vector <long long> intersect = {get <1> (arr[i]), get <2> (arr[j])};
                                if (intersect[1]-get <2> (arr[i]) > intersect[0]-get<1> (arr[j])){
                                    //*If (p2) gets there faster, that means (p1) will intersect. Strict. 
                                    //!Could intersect. 
                                    ok = true;
                                    if (intersect[1] - y_i < distance){
                                        //*If smaller that replace the entire vector and change the value. 
                                        distance = intersect[1] - y_i;
                                        next_remove = {i};
                                    }

                                    else if (intersect[1] - y_i == distance){
                                        next_remove.insert(i);
                                    }
                                }
                            }
                        }
                    }

                    else if (get <0> (arr[i])=='E'){
                        if (get <0> (arr[j])=='E'){
                            if (get <2> (arr[i])==get <2> (arr[j]) && get <1> (arr[i]) < get <1> (arr[j])){
                                ok = true;
                                //!Could intersect. 
                                //*Checking the distance should happen a little differently. 
                                vector <long long> intersect = {get <1> (arr[j]), get<2> (arr[j])};
                                if (intersect[0] - x_i < distance){
                                    //*If smaller that replace the entire vector and change the value. 
                                    distance = intersect[0] - x_i;
                                    next_remove = {i};
                                }

                                else if (intersect[0] - x_i == distance){
                                    next_remove.insert(i);
                                }
                            }
                        }
                        else if (get <0> (arr[j])=='N'){
                            //!Height is not strict. 
                            if (get <1> (arr[i]) < get <1> (arr[j]) && get <2> (arr[i]) >= get <2> (arr[j])){
                                vector <long long> intersect = {get <1> (arr[j]), get <2> (arr[i])};
                                if (intersect[0]-get <1> (arr[i]) > intersect[1] - get <2> (arr[j])){
                                    ok = true;
                                    //!Could intersect. 
                                    if (intersect[0] - x_i < distance){
                                        //*If smaller that replace the entire vector and change the value. 
                                        distance = intersect[0] - x_i;
                                        next_remove = {i};
                                    }

                                    else if (intersect[0] - x_i == distance){
                                        next_remove.insert(i);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        //!After all the forloop, I have the distance and the indexes to remove. 
        //*I cannot just erase based on the original index because that changes. 
        //*Rather, I should be constructing a new array. 
        //*So I should make the next_remove a set for lookup. 

        //!Because the size of the array changes. '
        //cout << next_remove.size() << " " << distance << endl;
        for (auto e:next_remove){
            //cout << e << endl;
        } //!The issue could be that the code doesn't track the trailing stuff. I think a better approach is to not move the point but only the time that has passed. 
        //!Kinda confusing shit. 
        //*
        addTime+=distance; //!Cannot add distance if it is equal to the large one! However, since the set will be 0, no result array would be marked that way...
        numIterations++;
        
        //!Why does addTime==30 only appear once though? 
        if (addTime==30){
            for (auto e:next_remove){
                //cout << e << endl;
            }
        }

        //!Maybe I can find my first mistake reading in from the answer and comparing. 
        //*Totally not how I should solve the problem but no choice. 

        ifstream correct_answer ("stuckinrut/3.out");
        vector <long long> answer;
        for (long long i=0;i<n;i++){
            string temp;
            long long number;
            correct_answer >> temp;
            if (temp=="Infinity"){
                number=-1;
            }
            else{
                number = stoi(temp);
            }
            answer.push_back(number);
        }

        //!I don't even know if it is reading in the correct information. 


        for (long long i=0;i<arr.size();i++){
            if (next_remove.count(i)==1){
                get <3> (arr[i]) = false;
                //!If I remove then indexing won't be accurate. 
                //!Rather, it might be better to keep a bool value to show whether stopped or not. 

                //?Am I ever overmodifying something? 
                //!OK so not overwriting anything. 
                if (result[i] != -1){
                    cout << "Overwriting: " << i<<endl;
                }
                result[i] = addTime;
                //*Distance must reset back to 0 every iteration. 
                //!Not 0 but 9999999. 
                //!Doesn't correct infinity on my end but correct number on their end. 
                if (result[i] != answer[i]){
                    cout << i  << endl;
                }
            }
    
        }

        //!Infinity is correct but the remaining is wrong. 

        //!Only increment the time. 
        

        //!I am pretty sure the coordinate system was something weird. 
        //*Now increment all by the distance. 
        /*
        for (auto point: arr){
            if (get <0> (point) == 'N'){
                get <2> (point) += distance;
            }
            else{
                get <1> (point) += distance;
            }
        }
        */
    }

    for (auto point:result){
        if (point==-1){
            my_answer << "Infinity" << endl;
        }
        else{
            my_answer << point << endl;
        }
    }


}