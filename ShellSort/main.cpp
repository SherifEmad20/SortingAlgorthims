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

// shell sort ascending order function (faster algorithm as it is O(n log n))
void shellSortAsc(int arr[], int n)
{
    // Rearrange elements at each n/2, n/4, n/8, ... intervals
    for (int interval = n / 2; interval > 0; interval /= 2) // divides the size by two to find the gap between each element
    {
        for (int i = interval; i < n; i++) // revolves around the element
        {
            int temp = arr[i];
            int j;
            for (j = i; j >= interval && arr[j - interval] > temp; j -= interval) // loop as when the i and j replace directions means that the element where they switch places is in its right place
            {
                arr[j] = arr[j - interval];
            }
            arr[j] = temp;
        }
    }
}

// shell sort descending order function (faster algorithm as it is O(n log n))
void shellSortDsc(int arr[], int n)
{
    // Rearrange elements at each n/2, n/4, n/8, ... intervals
    for (int interval = n / 2; interval > 0; interval /= 2) // divides the size by two to find the gap between each element
    {
        for (int i = interval; i < n; i++) // revolves around the element
        {
            int temp = arr[i];
            int j;
            for (j = i; j >= interval && arr[j - interval] < temp; j -= interval) // loop as when the i and j replace directions means that the element where they switch places is in its right place
            {
                arr[j] = arr[j - interval];
            }
            arr[j] = temp;
        }
    }
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

    // shell sorted array
    cout << "Shell sort ascending order: " << endl;
    shellSortAsc(arr,n);
    printArray(arr,n);

    cout << "Shell sort descending order: " << endl;
    shellSortDsc(arr,n);
    printArray(arr,n);
    cout << endl << endl;

    return 0;
}
