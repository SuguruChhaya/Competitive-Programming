#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin >> n;
    //*At every addition, I need to make sure the sum becomes max. 
    //!Which data structures?
    //*
    stack <long long> s;
    //*Double ended queue. 
    queue <long long> q;
    deque <long long>d;
    
    for (long long i=0;i<n;i++){
        long long a;
        cin >> a;
        //!Is there anything so special about the deque?
        //*I think deque could be a way to get rid of small numbers by "hiding them".
        //*If number is small, obviously, we don't want to add it to stack. 
        //*If the length of queue is 0, we don't want to add it to queue as well. 
        //*Then the only remaining choice is dequeu. 
        if (a==0){
            vector <string> removal;
            if (!s.empty()){
                removal.push_back("popStack");
                while (!s.empty()){
                    s.pop();
                }
            }
            if (!q.empty()){
                removal.push_back("popQueue");
                while (!q.empty()){
                    q.pop();
                }
            }

            if (!d.empty()){
                if (d[0] >= d[d.size()-1]){
                    removal.push_back("popFront");
                }
                else{
                    removal.push_back("popBack");
                }
            }

            cout << removal.size();
            for (auto e: removal){
                cout << " "<< e;
            }
            cout << "\n";
            
        }

        else{
            //*We cannot just say if it is the smallest one then replace it. 
            //*We have to compare all of the choices we have. 
            pair <string, long long> smallest;
            //*Gonna default it to queue since if nothing is beneficial, it would go to the queue. 
            smallest.first = "Queue";


            //!We have to add it anyways. 
            //*If they are all larger, what choice do I have??
            //!If none of them are empty, I could just hide it behind a queue or deque
            //*If any one of them is empty, push it back there. 
            if (s.empty()){
                smallest.first = "Stack";
            }
            else if (q.empty()){
                smallest.first = "Queue";
            }
            else if (d.empty()){
                //!Would never have to push to front. 
                smallest.first = "Back";
            }
            else{
                //*None of them are empty.
                if (s.top() < a){
                    //*Possibly put it here. 
                    smallest.first = "Stack";
                    smallest.second = a - s.top();
                }
                //!Well we have to consider that we can remove from both front and back. 
                //*No point maxing out the deque and ignoring the stack. 
                //*We can only pop from one anyways. 
                long long max_index;
                if (d[0]>=d[d.size()-1]){
                    max_index = 0;
                }
                else{
                    max_index = d.size()-1;
                }
                //long long max_deque = max(d[0], d[d.size()-1]);
                if (a > d[max_index] && a - d[max_index] > smallest.second){
                    //*More beneficial to add it to the deque. 
                    //*Doesn't matter which side I add it to since I can only pick from one side. 
                    //d.push_back(a);
                    smallest.first = "Back";
                }
                /*
                else{
                    //*If beneficial to add to stack, add it. 
                    if (smallest.first =="Stack"){
                        s.push(a);
                    }
                    else{
                        q.push(a);
                    }
                }
                */
            }

            //*Print the results and push. 
            cout << "push" + smallest.first << "\n";
            if (smallest.first == "Stack"){
                s.push(a);
            }
            else if (smallest.first=="Queue"){
                q.push(a);
            }
            else if (smallest.first == "Back"){
                d.push_back(a);
            }

        }
    }
}