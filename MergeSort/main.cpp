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

// merge sort ascending order function (faster algorithm as it is O(n log n))
void MergeAsc(int arr[], int l, int m, int r) // l is left , m is middle , r is right
{
    int i,j,k; // i for left , j for right , k for is the final array after merging
    int n1 = m-l+1; // n1 is the left sub-array size arr[l....m]
    int n2 = r-m; // n2 is the right sub-array size arr[m+1....r]
    int *L = new int[n1], *R = new int[n2]; // *L and *R are static arrays to pass the sizes to.

    for (i = 0; i < n1 ; i++)
    {
        L[i] = arr[l + i];
    }

    for (j = 0; j < n2 ; j++)
    {
        R[j] = arr[m + 1 + j];
    }

    i=j=0;
    k=l;

    while(i < n1 && j < n2)
    {
        if(L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while(i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while(j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}


// merge sort ascending order function (faster algorithm as it is O(n log n))
void mergeSortAsc(int arr[], int l, int r)
{
    if(l < r)
    {
        int m = l + (r-l) / 2;

        mergeSortAsc(arr,l,m);
        mergeSortAsc(arr,m+1,r);

        MergeAsc(arr,l,m,r);
    }
}


// merge sort descending order function (faster algorithm as it is O(n log n))
void MergeDsc(int arr[], int l, int m, int r) // l is left , m is middle , r is right
{
    int i,j,k; // i for left , j for right , k for is the final array after merging
    int n1 = m-l+1; // n1 is the left sub-array size arr[l....m]
    int n2 = r-m; // n2 is the right sub-array size arr[m+1....r]
    int *L = new int[n1], *R = new int[n2]; // *L and *R are static arrays to pass the sizes to.

    for (i = 0; i < n1 ; i++)
    {
        L[i] = arr[l + i];
    }

    for (j = 0; j < n2 ; j++)
    {
        R[j] = arr[m + 1 + j];
    }

    i=j=0;
    k=l;

    while(i < n1 && j < n2)
    {
        if(L[i] >= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while(i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while(j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}


// merge sort descending order function (faster algorithm as it is O(n log n))
void mergeSortDsc(int arr[], int l, int r)
{
    if(l < r)
    {
        int m = l + (r-l) / 2;

        mergeSortDsc(arr,l,m);
        mergeSortDsc(arr,m+1,r);

        MergeDsc(arr,l,m,r);
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

    //merge sorted array
    cout << "Merge sort ascending order: " << endl;
    MergeAsc(arr,0,0+(n-1-0)/2,n-1);
    mergeSortAsc(arr,0,n-1);
    printArray(arr,n);

    cout << "Merge sort descending order: " << endl;
    MergeDsc(arr,0,0+(n-1-0)/2,n-1);
    mergeSortDsc(arr,0,n-1);
    printArray(arr,n);
    cout << endl << endl;

    return 0;
}
