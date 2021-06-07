#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main(){
    //*Number of variables is even.
    //*I think the fact that the numbers are even is some kind of hint. 
    //*Kind of tricky that it's not like right after I modify a value I use it. 

    //!The naive idea is to create a BFS that stores all values. 
    //*Kind of similar to yesterday's DMOJ problem. But there must be some kind of better way. 

    int numTests;
    cin >> numTests;

    //*i<j should hold. 
    long long n;
    vector <long long> start;
    vector <long long> end;
    long long temp;
    //*Data I need to store in the queue: current array, all the moves I have made so far. 
    //*pair <vector <long long>, vector <vector<long long>>>
    vector <pair <vector <long long>, vector <vector <long long>>>> queue;
    pair <vector <long long>, vector <vector <long long>>> curr;
    pair <vector <long long>, vector <vector <long long>>> temp1;
    pair <vector <long long>, vector <vector <long long>>> temp2;
    set <vector <long long>> hashset;
    //!Like yesterday, I am running into this infinite loop.


    vector <long long> reached1 = {1, 0, 1, 1}; 
    vector <long long> reached2 = {1, -1, 1, 1}; 
    vector <long long> reached3 = {1, -1, 0, 1}; 
    vector <long long> reached4 = {1, -1, -1, 1}; 
    vector <long long> reached5 = {1, -1, -1, 0}; 
    vector <long long> reached6 = {1, -1, -1, -1}; 
    vector <long long> reached7 = {0, -1, -1, -1}; 
    vector <long long> reached8 = {-1, -1, -1, -1}; 
    for (int i=0;i<numTests;i++){
        cin >> n;
        for (long long j=0;j<n;j++){
            cin >> temp;
            start.push_back(temp);
            end.push_back(-temp);
        }
        queue = {{start, {}}};
        hashset = {};
        while (queue.size() > 0){
            curr = queue[0];
            queue.erase(queue.begin());
            //*I guess I have to explicitly create the vector to compare. 
            //!I think it really is some kind of C++ specific issue. 

            if (curr.first == end){
                cout << curr.second.size() << "\n";
                for (long long j=0;j<curr.second.size();j++){
                    cout << curr.second[j][0] << " " << curr.second[j][1] << " " << curr.second[j][2] << "\n";
                }
                break;
            }
            //!Why is the hashset not working??
            else if (hashset.count(curr.first) == 0){
                if (curr.first == reached1){
                    cout << "reached1" << "\n";
                }
                else if (curr.first == reached2){
                    cout << "reached2" << "\n";
                }
                else if (curr.first == reached3){
                    cout << "reached3" << "\n";
                }
                else if (curr.first == reached4){
                    cout << "reached4" << "\n";
                }
                else if (curr.first == reached5){
                    cout << "reached5" << "\n";
                }
                else if (curr.first == reached6){
                    cout << "reached6" << "\n";
                }
                else if (curr.first == reached7){
                    cout << "reached7" << "\n";
                }
                else if (curr.first == reached8){
                    cout << "reached8" << "\n";
                } //!C++ is just having a real hard time reaching to the eigth. 
                hashset.insert(curr.first);
                for (long long a=0;a<n;a++){
                    for (long long b=a;b<n;b++){
                        //*Must satisfy condition. 
                        if (a < b){
                            temp1 = curr;
                            temp2 = curr;
                            //*Temp 1 is just the first operation. 
                            //!HOW can C++ be slower than python in this case?
                            temp1.first[a] += temp1.first[b];
                            temp2.first[b] -= temp2.first[a];
                            temp1.second.push_back({1, a, b});
                            temp2.second.push_back({2, a, b});
                            queue.push_back(temp1);
                            queue.push_back(temp2);
                        }
                    }
                }
            }
        }
    }
}