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

// heap sort ascending order function ( complexity is n log n )
void maxHeapify(int arr[], int sizee, int index)
{
    int leftChild = 2*index+1;
    int rightChild = 2*index+2;
    int maxi = index;

    if (leftChild < sizee && arr[leftChild] > arr[maxi])
    {
        maxi = leftChild;
    }

    if(rightChild < sizee && arr[rightChild] > arr[maxi])
    {
        maxi = rightChild;
    }

    if (maxi != index)
    {
        int temp;

        temp = arr[index];
        arr[index] = arr[maxi];
        arr[maxi] = temp;

        maxHeapify(arr,sizee,maxi);
    }
}

void maxBuildHeap(int arr[], int sizee)
{
    for (int i = sizee / 2 - 1 ; i >= 0 ; i--)
    {
        maxHeapify(arr,sizee,i);
    }
}

void heapSortAsc(int arr[], int sizee)
{
    int temp;

    maxBuildHeap(arr,sizee);
    for (int i = sizee-1 ; i >= 0 ; i--)
    {
        temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        maxHeapify(arr,i,0);

    }
}

// heap sort descending order function ( complexity is O(n log n) )
void minHeapify(int arr[], int sizee, int index)
{
    int leftChild = 2*index+1;
    int rightChild = 2*index+2;
    int mini = index;

    if (leftChild < sizee && arr[leftChild] < arr[mini])
    {
        mini = leftChild;
    }

    if(rightChild < sizee && arr[rightChild] < arr[mini])
    {
        mini = rightChild;
    }

    if (mini != index)
    {
        int temp;

        temp = arr[index];
        arr[index] = arr[mini];
        arr[mini] = temp;

        maxHeapify(arr,sizee,mini);
    }
}

void minBuildHeap(int arr[], int sizee)
{
    for (int i = sizee / 2 - 1 ; i >= 0 ; i--)
    {
        minHeapify(arr,sizee,i);
    }
}

void heapSortDsc(int arr[], int sizee)
{
    int temp;

    minBuildHeap(arr,sizee);
    for (int i = sizee-1 ; i >= 0 ; i--)
    {
        temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        minHeapify(arr,i,0);

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

    // heap sorted array
    cout << "Heap sort ascending order: " << endl;
    heapSortAsc(arr,n);
    printArray(arr,n);

    cout << "Heap sort descending order: " << endl;
    heapSortDsc(arr,n);
    printArray(arr,n);
    cout << endl << endl;

    return 0;
}
