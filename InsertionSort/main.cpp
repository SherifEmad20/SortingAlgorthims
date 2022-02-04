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

// insertion sort ascending order function (slow algorithm as it is O(n^2))
void insertionSortAsc(int arr[], int n)
{
    int key ,j; // key is to store the index values , j is to iterate

    for (int i = 1; i < n; i++) // to iterate over the array elements
    {
        key = arr[i]; // assigning the second element in the array to the key as we assume that the first element is already sorted
        j = i - 1; // to iterate for the next element

        while(j >= 0 && arr[j] > key) // the first condition is to check the index, the second condition is to check if the element is already sorted or not and for ascending order arr[j] > key while if arr[j] < key therefore descending oreder
        {
            arr[j+1] = arr[j]; // sifting the elements as we found that the element of the array is bigger than the key
            j = j - 1;
        }

        arr[j+1] = key;
    }
}

// insertion sort descending order function (slow algorithm as it is O(n^2))
void insertionSortDsc(int arr[], int n)
{
    int key ,j; // key is to store the index values , j is to iterate

    for (int i = 1; i < n; i++) // to iterate over the array elements
    {
        key = arr[i]; // assigning the second element in the array to the key as we assume that the first element is already sorted
        j = i - 1; // to iterate for the next element

        while(j >= 0 && arr[j] < key) // the first condition is to check the index, the second condition is to check if the element is already sorted or not and for ascending order arr[j] > key while if arr[j] < key therefore descending oreder
        {
            arr[j+1] = arr[j]; // sifting the elements as we found that the element of the array is bigger than the key
            j = j - 1;
        }

        arr[j+1] = key;
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

    //insertion sorted array
    cout << "Insertion sort ascending order: " << endl;
    insertionSortAsc(arr,n);
    printArray(arr,n);

    cout << "Insertion sort descending order: " << endl;
    insertionSortDsc(arr,n);
    printArray(arr,n);
    cout << endl << endl;

    return 0;
}
