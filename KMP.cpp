#include<iostream>
using namespace std;
vector<int> getNext(string p) {
    vector<int> next(p.size(), 0);
    for (int i = 1, j = 0; i < p.size(); i++) {
        while (j > 0 && p[i] != p[j]) j = next[j - 1];
        if (p[i] == p[j]) j++;
        next[i] = j;
    }
    return next;
}


int kmp(string s, string p) {
    vector<int> next = getNext(p);
    for (int i = 0, j = 0; i < s.size(); i++) {
        while (j > 0 && s[i] != p[j]) j = next[j - 1];
        if (s[i] == p[j]) j++;
        if (j == p.size()) return i - p.size() + 1;
    }
    return -1;
}


int main()
{

}