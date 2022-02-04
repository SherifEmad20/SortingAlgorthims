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

//to arrange the elements of the array in ascending order
int partitioningAsc(int arr[], int l, int h)
{
    int p = arr[l];
    int i = l;
    int j = h;
    int temp;

    while (i < j)
    {
        do
        {
            i++;
        }while(arr[i] <= p);

        do
        {
            j--;
        }while(arr[j] > p);

        if (i < j)
        {
            temp = arr[i];  // swap algorithm
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    temp = arr[l];  // swap algorithm
    arr[l] = arr[j];
    arr[j] = temp;
    return j;
}

// quick sort ascending order function (faster algorithm as it is O(n log n))
void quickSortAsc(int arr[], int l, int h)
{
    if (l < h)
    {
        int piv = partitioningAsc(arr,l,h);
        quickSortAsc(arr,l,piv);
        quickSortAsc(arr,piv+1,h);
    }
}

//to arrange the elements of the array in descending order
int partitioningDsc(int arr[], int l, int h)
{
    int p = arr[l];
    int i = l;
    int j = h;
    int temp;

    while (i < j)
    {
        do
        {
            i++;
        }while(arr[i] >= p);

        do
        {
            j--;
        }while(arr[j] < p);

        if (i < j)
        {
            temp = arr[i];  // swap algorithm
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    temp = arr[l];  // swap algorithm
    arr[l] = arr[j];
    arr[j] = temp;
    return j;
}

// quick sort descending order function (faster algorithm as it is O(n log n))
void quickSortDsc(int arr[], int l, int h)
{
    if (l > h)
    {
        int piv = partitioningAsc(arr,l,h);
        quickSortAsc(arr,l,piv);
        quickSortAsc(arr,piv+1,h);
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

    //quick sorted array
    cout << "Quick sort ascending order: " << endl;
    partitioningAsc(arr,0,n);
    quickSortAsc(arr,0,n);
    printArray(arr,n);

    cout << "Merge sort descending order: " << endl;
    partitioningDsc(arr,0,n);
    quickSortDsc(arr,0,n);
    printArray(arr,n);
    cout << endl << endl;

    return 0;
}
