#include <bits/stdc++.h>
using namespace std;

int main(){
    //*Retry the problems that shitted on me. 
    //  freopen("13.in", "r", stdin);
    /*
    Let's suppose that L=0; then we just want to compute the h-index of Bessie's papers with no additional citations. To find this, we can sort the citation counts from largest to smallest, and find the largest h such that the first h papers all have at least h citations. This can be done in one pass through the sorted counts.

Now let's consider how to use L extra citations to increase the h-index. Since the survey cannot cite any one paper multiple times, it's not possible to increase the h-index by more than 1: the (h+1)-st most cited paper before the survey had at most h citations, so afterwards it cannot have more than h+1 citations.

But it's not always possible to increase the h-index by one. When is it possible? Well, out of the top h papers before the survey, some k of them have exactly h citations (and the rest have more than h). We need to cite each of these k papers. Additionally, we need to cite the (h+1)-st most cited paper. So it's necessary that L≥k+1. Finally, if the (h+1)-st most cited paper has less than h citations, then we cannot hope to increase the h-index. Conversely, if it has h citations (it cannot have more than h), and if L≥k+1, then the h-index can be increased to h+1.

Below is Danny Mittal's code, which does a slight variation on the above idea. This program increments the citation counts of the [h−L+2,h+1]-most cited papers (which we've seen is optimal) and checks what the new h-index is.
    */

   //!Only can increase citation count by 1 maximum. 

   //!Intuitively, I understand how it is not possible to increase the citation count by more than one. 
   //?Actually, no I don't get it. Need explanation. 

   //!h+1st most cited paper had at most h citations makes sense. 
   //*This is because the h papers with the most citations had h citations or above. 
   //*Now the h+1st most cited paper could have h citations (e.g. 3,3,3,3 where the 3+1=4th most cited paper has 3=h citations)
   //*Or less (e.g. 1, 3, 3, 100 where the 3+1=4th most cited paper has 1 < h citations). 

   //*Then my most immediate thought is: then unless the h+1st most cited paper is already equal to h, wouldn't it be impossible to get a result of h+1?

   //!Yep, that is one immediate check I can do. 
   //!But to increase to h+1, I also have to increase the k papers that have exactly h citations. 

    long long n, l;
    cin >> n >> l;
    vector <long long> arr;
    for (long long i=0;i<n;i++){
        long long temp;
        cin >> temp;
        arr.push_back(temp);
    }

    sort(arr.begin(), arr.end());
    //cout << arr[0];
    //!My way of calculating the h_score is wrong. 

    
    long long h_score = arr.size();
    //long long index;
    //!Oh well. 
    //*I guess that is the only way I can check for the h_score efficiently without degrading down to O(n^2)
    while (h_score > 0 && arr[arr.size()-h_score] < h_score){
        h_score--;
    }
    
    //!First check whether it even is possible to get the score. 
    //*Basically check the h+1st largest element. 
    if (arr[arr.size()-h_score-1]==h_score){
        //*Now check how many elements have h_scores and check whether the 
        //!We don't have to increase all elements which has the h_score but rather the elements upto arr.size()-h_score
        long long numIncreases = 0;
        for (long long i=0;i<h_score+1;i++){
            if (arr[arr.size()-i-1]==h_score){
                numIncreases++;
            }
        }
        if (numIncreases <= l){
            cout << h_score+1 << endl;
        }
        else{
            cout << h_score << endl;
        }
    }
    else{
        cout << h_score << endl;
    }
}