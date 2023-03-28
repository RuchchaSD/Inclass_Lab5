#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void printVector(vector<int> v)
{
    cout << "[";
    for (auto i = 0; i < v.size()-1; i++)
        cout << v[i] << ", ";
    cout << v.back() <<  "]";
}


int main()
{
    cout << "sorted    Median \n";
    int sz;
    double median =0;
    int arr[5] = { 1,3,2,4,5,3,56,7,1,8,16,19};
    vector<int> v;
    for(int element : arr){
        v.push_back(element);
        sort(v.begin(), v.end());
        
        sz = v.size();
        if(sz % 2 == 0)
        {
            median = ((double)v[sz/2] + (double)v[ (sz/2)-1 ]) / 2;

        }else{
            median= (double)v[(sz-1)/2];
        }
        printVector(v);
        cout <<"    "<< floor(10*median)/10 << "\n";
    }
    return 0;
}
