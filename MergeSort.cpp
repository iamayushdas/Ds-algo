#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int l, int r)
{
    int m = (l + r) / 2;

    //first half
    vector<int> arr1;
    int p = l;
    int q = m;

    //second half
    vector<int> arr2;
    int x = m + 1;
    int y = r;

    for (int i = p; i <= q; i++)
    {
        arr1.push_back(arr[i]);
    }

    for (int i = x; i <= y; i++)
    {
        arr2.push_back(arr[i]);
    }

    int i = 0;
    int j = 0;
    int k = l;

    while (i < arr1.size() and j < arr2.size())
    {
        if (arr1[i] < arr2[j])
        {
            arr[k++] = arr1[i++];
        }
        else
        {
            arr[k++] = arr2[j++];
        }
    }

    while (i < arr1.size())
    {
        arr[k++] = arr1[i++];
    }

    while (j < arr2.size())
    {
        arr[k++] = arr2[j++];
    }
}

void mergeSort(vector<int> &arr, int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, r);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    mergeSort(arr, 0, arr.size() - 1);

    //print elements after sorting
    for (auto x : arr)
        cout << x << " ";
}