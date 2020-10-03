#include <iostream>
using namespace std;

void countingSortAlgo(int array[], int size)
{

    int result[10];
    int couter[10];
    int max = array[0];

    // largest element
    for (int i = 1; i < size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }

    // assign with all zeros.
    for (int i = 0; i <= max; ++i)
    {
        couter[i] = 0;
    }

    // Store the couter of each element
    for (int i = 0; i < size; i++)
    {
        couter[array[i]]++;
    }

    // Store the cummulative couter of each array
    for (int i = 1; i <= max; i++)
    {
        couter[i] += couter[i - 1];
    }

    // Find the index of each element of the original array in couter array, and
    // place the elements in result array
    for (int i = size - 1; i >= 0; i--)
    {
        result[couter[array[i]] - 1] = array[i];
        couter[array[i]]--;
    }

    // Copy the sorted elements into original array
    for (int i = 0; i < size; i++)
    {
        array[i] = result[i];
    }
}

int main()
{
    int array[] = {5, 4, 3, 2, 1};
    int n = sizeof(array) / sizeof(array[0]);
    countingSortAlgo(array, n);
    for (int i = 0; i < n; i++)
        cout << array[i] << " ";
    cout << endl;
}
