#include <bits/stdc++.h>;
using namespace std;
//*Diagnosing a problem of a guy who replied. 


void merge(int arr1[], int arr2[], int n, int m)
{ 
    //code here
    int gap=ceil((n+m)/2);
    while(gap>0){
        int i=0;
        int j=i+gap;
        while(j<n+m){
            if(j<n){
                if(arr1[i]>arr1[j]){
                    //swap(arr1[i],arr1[j]);
                    int temp = arr1[i];
                    arr1[i] = arr2[j];
                    arr2[j] = temp;
                }
            }
            else if(i<n && j>=n){
                if(arr1[i]>arr2[j-n]){
                    //swap(arr1[i],arr2[j-n]);
                    int temp = arr1[i];
                    arr1[i] = arr2[j-n];
                    arr2[j-n] = temp;
                }
            }
            else if(i>=n+m){
                if(arr2[i-n]>arr2[j-n]){
                    //swap(arr2[i-n],arr2[j-n]);
                    int temp = arr1[i-n];
                    arr1[i-n] = arr2[j-n];
                    arr2[j-n] = temp;
                }
            }
            i++;j++;
        }
        gap=ceil(gap/2);
    }
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n,m;
		scanf("%d", &n);
		scanf("%d", &m);
		int *arr1;
		arr1 = (int*)malloc(n * sizeof(int));
		for(int i=0;i<n;i++)
    		scanf("%d", &arr1[i]);
		int *arr2;
		arr2 = (int*)malloc(m * sizeof(int));
		for(int i=0;i<m;i++)
    		scanf("%d", &arr2[i]);
    	
    	merge(arr1,arr2,n,m);
    	for(int i=0;i<n;i++)
    		printf("%d ", arr1[i]);
		for(int i=0;i<m;i++)
    		printf("%d ", arr2[i]);
    	printf("\n");
	}
	return 0;
}