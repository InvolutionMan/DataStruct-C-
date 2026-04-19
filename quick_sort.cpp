#include<iostream>
using namespace std;
auto partition(int arry[],int low,int high)
{
    int pivot=arry[low];
    int i=low;
    int j=high;
    while (i<j)
    {
        while(i<j&&arry[j]>=pivot) j--;
        arry[j]=arry[i];
        while(i<j&&arry[i]<=pivot) i++;
        arry[i]=arry[j];
    }
    arry[i]=pivot;
    return i;
}
void quick_sort(int arry[],int low,int high )
{
    if(low<high)
    {
        int pivotIndex=partition(arry,low,high);
        quick_sort(arry,low,pivotIndex-1);
        quick_sort(arry,pivotIndex+1,high);
    }
}
int main()
{
    int arry[]={5,4124,12435,6,8,54,9,44,56,43};
    int n=sizeof(arry)/sizeof(arry[0]);
    quick_sort(arry,0,n-1);
    for (int i = 0; i < n; i++) {
        cout << arry[i] << " ";
    }
}
