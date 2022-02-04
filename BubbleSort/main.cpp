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
// bubble sort ascending order function (slow algorithm as it is O(n^2))
void bubbleSortAsc(int arr[], int n)
{
    int temp = 0; // temp for the swap algorithm

    for(int i = 0; i < n-1; i++) // iterates n-1 as the last element will be the biggest one
    {
        for(int j = 0; j < n-i-1; j++) // iterates n-i-1 as to not iterate on the last element as its already been sorted
        {
            if (arr[j] > arr[j+1]) // condition to check the elements value, ex: if element 1 is bigger than element 2 swap between then to sort ascending. (>) for ascending, (<) for descending
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// bubble sort descending order function (slow algorithm as it is O(n^2))
void bubbleSortDsc(int arr[], int n)
{
    int temp; // temp for the swap algorithm

    for(int i = 0; i < n-1; i++) // iterates n-1 as the last element will be the biggest one
    {
        for(int j = 0; j < n-i-1; j++) // iterates n-i-1 as to not iterate on the last element as its already been sorted
        {
            if (arr[j] < arr[j+1]) // condition to check the elements value, ex: if element 1 is bigger than element 2 swap between then to sort ascending. (>) for ascending, (<) for descending
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
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

    //bubble sorted array
    cout << "Bubble sort ascending order: " << endl;
    bubbleSortAsc(arr,n);
    printArray(arr,n);
    cout << "Bubble sort descending order: " << endl;
    bubbleSortDsc(arr,n);
    printArray(arr,n);
    cout << endl << endl;

    return 0;
}
