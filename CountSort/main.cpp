#include <iostream>
#include <string>

using namespace std;


// function to print arrays
void insertArray(int arr[],int n)
{
    cout << "enter your array: " << endl;
    for (int i = 0 ; i < n ; i++)
    {
        cout << "Enter element number - " << i+1 << ":";
        cin >> arr[i];
    }
}

// function to print arrays
void printArray(int arr[],int n)
{
    cout << "Array elements are: [ ";
    for (int i = 0 ; i < n ; i++)
        cout << arr[i] << " ";
    cout << "]" << endl << endl;
}

// count sort ascending order function ( complexity is O(n + k) )
void countSortAsc(int arr[], int n)
{
    int output[10];
    int countt[10];
    int maxi = arr[0];

    for(int i = 0 ; i < n ; i++)
        if(arr[i] > maxi)
            maxi = arr[i];

    for(int i = 0 ; i <= maxi ; i++)
        countt[i] = 0;

    for(int i = 0 ; i < n ; i++)
        countt[arr[i]]++;

    for (int i = 1; i <= maxi; i++)
        countt[i] += countt[i - 1];

    for (int i = n - 1; i >= 0; i--)
    {
        output[countt[arr[i]] - 1] = arr[i];
        countt[arr[i]]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];

}

int main()
{
    int n;
    cout << "Enter your array size: ";
    cin >> n;

    int arr[n];
    insertArray(arr,n);

    cout << endl << "Array before sorting: " << endl;
    printArray(arr,n);

    // heap sorted array
    cout << "Count sort ascending order: " << endl;
    countSortAsc(arr,n);
    printArray(arr,n);
    cout << endl << endl;

    return 0;
}
