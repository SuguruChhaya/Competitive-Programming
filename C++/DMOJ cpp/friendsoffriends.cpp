#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
/*
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    //*Try to code in C++ with iterative first then look at editorial.
    map <int, vector <int>> d;
    int n, q;
    cin >> n >> q;
    int temp;
    int p1, p2;
    for (int i=0; i<q;i++){
        //*I can first check whether the first cin is 1 or 2 then receive as much data as I need. 
        cin >> temp;
        if (temp == 1){
            cin >> p1 >> p2;
            if (d.count(p1) == 0){
                d[p1] = {};
            }
            if (d.count(p2) == 0){
                d[p2] = {};
            }
            d[p1].push_back(p2);
            d[p2].push_back(p1);
        }

        else{
            //*Just in case the person talked to appeared for the first time. 
            cin >> p1;
            if (d.count(p1) == 0){
                d[p1] = {};
            }

            //!I can just set global variable for number of times incrementeed.
            //*If I see a new friend after I branch out, how am I gonna add it to the hashset?

            //*What is an adjacency list (supposed to maintain connection between students)
            //*What is a disjoint set (supposed to maintain connected components.)
            //*Would this be represented as 
            //*2nd number of edges

            //*We have to find all adjacent nodes. 
            //*For CPP, space is not an issue so I can just copy the array so far and mark it off when I visit. And make the marking global.
            //!We won't have a clear row, col 2D matrix structure to mark for. 
            //*I could just use a global hashset. 
            set <int> visited;
            int total=0;
            vector <int> queue = {p1};
            int curr;
            while (queue.size() > 0){
                curr = queue[0];
                queue.erase(queue.begin());

                //*Check for invalid. 
                if (visited.count(curr) == 0){
                    total++;
                    visited.insert(curr);
                    for (int i=0;i<d[curr].size();i++){
                        queue.push_back(d[curr][i]);
                    }
                }
            }

            cout << total << endl;
        }
        
        //*Now I have to use the disjoint set thing. 
        //*What is it? How can I use it in program?
        //*What is kruskal's algo? -> probably don't need to know.
        //!Literally what I was trying during the contest except I didn't know how to implement. 
        //*Probably use union. If they belong to 2 different sets, I union them. 
        //*Cycle in a graph happens when 2 nodes belong to the same disjoint set. 
        //*To implement to this problem, I need to store all the nodes so far so I can find them later. 
        //*I can do it graphically but I will probably need like a linked list ds. 
        //*Some weight stuff but only interested in array representation. 
        //!Have an initial parent graph and when I hit new elements, just mention that that is a parent. 
        //*"-" shows that it is a parent and number shows how many children it has. 
        //*For every value go back until it's original parent.
        //*Could be an array or hashmap probably won't matter. 
    }
}
*/
//!Couldn't I store both the head and child so I can trace back?
map <int, int> d;
int recursive(int curr){
    if (d[curr] <0){
        return curr;
    }
    else{
        //Recursion is memory heavy. 
        d[curr] = recursive(d[curr]);
        return d[curr];
    }
}


int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    //*Try to code in C++ with iterative first then look at editorial.
    //!Will be mapped to an int since it will either be a parent or will lead to a parent. 
    
    int n, q;
    cin >> n >> q;
    int temp;
    int p1, p2;
    int curr1, curr2;
    for (int i=0; i<q;i++){
        cin >> temp;
        if (temp==1){
            cin >> p1 >> p2;

            if (d.count(p1)==0 && d.count(p2)==0){
                d[p1] = -2;
                d[p2] = p1;
            }

            else{
                //*If the value already exists, trace back until I hit a negative number. 
                curr1 = 0;
                curr2 = 0;
                //!Initialize to 0 so I can later check if they have been initialized or not. 
                if (d.count(p1)==1){
                    curr1 = p1;
                    //*None can be exactly 0. 
                    //!Could use recursion to map them as close as possible to head node. 
                    /*
                    while (d[curr1] > 0){
                        curr1 = d[curr1];
                    }
                    */
                    curr1 = recursive(curr1);
                }

                //*Separate check for if p2 exists or not. 
                //!Getting the good ol MLE after implementing recursion. 
                if (d.count(p2)==1){
                    curr2 = p2;
                    /*
                    while (d[curr2] > 0){
                        curr2 = d[curr2];
                    }
                    */
                    curr2 = recursive(curr2);
                }
                //!I think the thing I didn't consider here is whether they were the same or not...
                if (curr1 != 0 && curr2 != 0){
                    //*Unionize both. Just connect curr2 to curr1.
                    //*Add because - plus -. 
                    //!I think I should try to make the graph weigh approximately the same. 
                    if (abs(d[curr1]) > abs(d[curr2])){
                        d[curr2] += d[curr1];
                        d[curr1] = curr2;
                    }
                    else{
                        d[curr1] += d[curr2];
                        d[curr2] = curr1; 
                    }
                }

                else if (curr1 != 0){
                    d[curr1] -= 1;
                    d[curr2] = curr1;
                }
                else if (curr2 != 0){
                    d[curr2] -= 1;
                    d[curr1] = curr2;
                }
            }
        }
        //!Still TLE so I could try balancing it and kind of DP the parent location. 
        
        else{
            cin >> p1;

            //*Trace back until I hit a negative number. 
            //*There could be a case where it does not exist yet. 

            if (d.count(p1)==0){
                cout << 1 << endl;
            }
            else{
                //!I think I could recursively connect the end nodes closer to the original node. 
                //!The recursion return to the original thing maybe
                while (d[p1] > 0){
                    p1 = d[p1];
                }
                cout << abs(d[p1]) << endl;
            }
        }
    }
}