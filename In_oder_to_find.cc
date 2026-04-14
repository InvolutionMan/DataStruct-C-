#include<iostream>
using namespace std;
auto find(int a[],int n,int k)
{
    for (int i=0;i<n;i++)
    {
        if (a[i]==k) return i;      
    }
    return -1;
}
int main()
{
    int n;

    cout << "请输入数组长度: ";
    cin >> n;

    int arr[100];  // 简单起见，最大100个

    cout << "请输入 " << n << " 个元素:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int key;
    cout << "请输入要查找的值: ";
    cin >> key;

    int result = find(arr, n, key);

    if (result != -1) {
        cout << "找到元素，下标为: " << result << endl;
    } else {
        cout << "未找到该元素" << endl;
    }

    return 0;
}