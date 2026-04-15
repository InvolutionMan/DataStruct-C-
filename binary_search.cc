#include<iostream>
using namespace std;
#include<cmath>
int binarySearch(const vector<int> &arr, int key)
{
    int low=0,hight=arr.size()-1;
    while(low<=hight)
    {
        int mid=low+abs((low-hight))/2;//避免溢出
        if(arr[mid]==key) return mid;
        else if(arr[mid]<key) low=mid+1;
        else hight=mid-1;
    }
    return -1;
}
int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11, 13};
    int key = 7;
    int index = binarySearch(arr, key);
    if (index != -1)
        cout << "找到，下标为: " << index << endl;
    else
        cout << "未找到" << endl;
    return 0;
}