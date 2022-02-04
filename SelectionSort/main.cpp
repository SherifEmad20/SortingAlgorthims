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

// selection sort ascending order function (slow algorithm as it is O(n^2))
void selectionSortAsc(int arr[],int n)
{
    int temp;

    for (int j = 0 ; j < n ; j++) // loop to rotate around array elements
    {
        for (int k = 0; k < n-1 ; k++) // loop to check if their is an element smaller than the other to sort them
        {
            if (arr[k] > arr[j]) // if it found an smaller element swap the two with each other
            {
                temp = arr[j];  // swap algorithm
                arr[j] = arr[k];
                arr[k] = temp;
            }
        }
    }
}

// selection sort descending order function (slow algorithm as it is O(n^2))
void selectionSortDsc(int arr[],int n)
{
    int temp;

    for (int j = 0 ; j < n ; j++) // loop to rotate around array elements
    {
        for (int k = 0; k < n-1 ; k++) // loop to check if their is an element smaller than the other to sort them
        {
            if (arr[k] < arr[j]) // if it found an smaller element swap the two with each other
            {
                temp = arr[j];  // swap algorithm
                arr[j] = arr[k];
                arr[k] = temp;
            }
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

    //selection sorted array
    cout << "Selection sort ascending order: " << endl;
    selectionSortAsc(arr,n);
    printArray(arr,n);
    cout << "Selection sort descending order: " << endl;
    selectionSortDsc(arr,n);
    printArray(arr,n);
    cout << endl << endl;

    return 0;
}
