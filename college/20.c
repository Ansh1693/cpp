#include <stdio.h>
#include <stdlib.h>
int big(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
void copy(int a[], int b[],int n){
  for(int i=0;i<n;i++){
    b[i]=a[i];
  }
}
void SwapValue(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void traverse(int ar[], int n)
{
    for (int i = 0; i < n; i++)
    { 
        printf("%d ", ar[i]);
    }
}
void heapify(int arr[], int n, int i)
{
     int largest = i;
     int left = 2 * i;
     int right = 2 * i + 1;

     

     if (left < n && arr[largest] < arr[left])
     {
          largest = left;
     }
     if (right < n && arr[largest] < arr[right])
     {
          largest = right;
     }

     if (largest != i)
     {
          SwapValue(&arr[largest], &arr[i]);
          heapify(arr, n, largest);
     }
}

void buildHeap(int arr[], int n)
{
     for(int i=(n-2)/2;i>=0;i--){
        heapify(arr,n,i);
     }
}

void heapSort(int arr[],int n){
    buildHeap(arr,n);
    for(int i=n-1;i>=1;i--){
        SwapValue(&arr[0],&arr[i]);
        heapify(arr,i,0);
    }

}

void selection(int arr[], int n)
{
    int small;
    for (int i = 0; i < n - 1; i++)
    {
        small = i;
        for (int j = i + 1; j < n; j++){

            if (arr[j] <= arr[small])
                small = j;
        }
        int temp = arr[small];
        arr[small] = arr[i];
        arr[i] = temp;


        printf(" %d pass -> " , i+1);
        traverse(arr,n);
        printf("\n");
    }
}

void merge(int a[], int beg, int mid, int end)
{
    int i, j, k;
    int n1 = mid - beg + 1;
    int n2 = end - mid;

    int LeftArray[n1], RightArray[n2];
    for (int i = 0; i < n1; i++)
        LeftArray[i] = a[beg + i];
    for (int j = 0; j < n2; j++)
        RightArray[j] = a[mid + 1 + j];

    i = 0;
    j = 0;
    k = beg;

    while (i < n1 && j < n2)
    {
        if (LeftArray[i] <= RightArray[j])
        {
            a[k] = LeftArray[i];
            i++;
        }
        else
        {
            a[k] = RightArray[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        a[k] = LeftArray[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        a[k] = RightArray[j];
        j++;
        k++;
    }
}

void mergeSort(int a[], int beg, int end)
{
    if (beg < end)
    {
        int mid = (beg + end) / 2;
        mergeSort(a, beg, mid);
        mergeSort(a, mid + 1, end);
        merge(a, beg, mid, end);
    }
}

void shell(int a[], int n)
{
    for (int interval = n / 2; interval > 0; interval /= 2)
    {
        for (int i = interval; i < n; i++)
        {
            int temp = a[i];
            int j;
            for (j = i; j >= interval && a[j - interval] > temp; j -= interval)
                a[j] = a[j - interval];
            a[j] = temp;
        }

        printf(" %d pass -> " , interval );
        traverse(a,n);
        printf("\n");

    }
}

void bubble(int a[], int n)
{
    int i, j, temp;
    for (i = 0; i < n-1; i++)
    {
        for (j = 0; j < n -1; j++)
        {
            if (a[j] > a[j+1])
            {
                SwapValue(&a[j],&a[j+1]);
            }
        }


        printf(" %d pass -> " , i+1);
        traverse(a,n);
        printf("\n");
    }
}

int partition(int a[], int start, int end)
{
    int pivot = a[end];
    int i = (start-1);

    for (int j = start; j <= end - 1; j++)
    {
        if (a[j] < pivot)
        {
            i++;
            SwapValue(&a[i],&a[j]); 
        }
    }
    SwapValue(&a[i+1],&a[end]);

    return (i + 1);
}

void quick(int a[], int start, int end)
{
    if (start < end)
    {
        int p = partition(a, start, end);
        printf("Partition for %d to %d is %d and element %d  \n ",start , end, p , a[p]);
        quick(a, start, p - 1);
        quick(a, p + 1, end);
    }
}
void insert(int a[], int n) 
{  
    int i, j, temp;  
    for (i = 1; i < n; i++) {  
        temp = a[i];  
        j = i - 1;  
  
        while(j>=0 && temp <= a[j])
        {    
            a[j+1] = a[j];     
            j = j-1;    
        }    
        a[j+1] = temp;    

        
    }  
}  
int main()
{
    int n;
        printf("\n\nEnter the size of array : ");
        scanf("%d", &n);
        if(n==0) return 0; 
        int arr[n];
        int barr[n];
        printf("Enter the array\n");
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);

        }
        copy(arr,barr,n);
    while (1)
    {
        printf("\n1.Heap sort\n2.Merge sort\n3.Shell sort\n");
        printf("4.Selection sort\n5.Quick sort\n6.Bubble sort\n7.Insertion sort\n");
        printf("Enter your choice : ");
        int choice;
        scanf("%d", &choice);
        printf("\nBefore Sorting Array is\n");
        traverse(arr, n);
        printf("\n");
      
        switch (choice)
        {
        case 1:
            heapSort(arr, n);
              printf("\n\nAfter sorting Array is\n");
            traverse(arr, n);
            break;
        case 2:
            mergeSort(arr, 0, n - 1);
              printf("\n\nAfter sorting Array is\n");
            traverse(arr, n);
            break;
        case 3:
            shell(arr, n);
              printf("\n\nAfter sorting Array is\n");
            traverse(arr, n);
            break;
        case 4:
            selection(arr, n);
              printf("\n\nAfter sorting Array is\n");
            traverse(arr, n);
            break;
        case 5:
            quick(arr, 0, n - 1);
              printf("\n\nAfter sorting Array is\n");
            traverse(arr, n);
            break;
        case 6:
            bubble(arr, n);
              printf("\n\nAfter sorting Array is\n");
            traverse(arr, n);
            break;
        case 7:
            insert(arr, n);
              printf("\n\nAfter sorting Array is\n");
            traverse(arr, n);
            break;
        default:
            printf("Enter a valid input");
            break;
        }
        printf("\nDo you want to continue\n");
        printf("1.Yes\n2.No\n\n");
        int what;
        scanf("%d",&what);
        if(what==1){
            copy(barr,arr,n);
            continue;
        }else{
          break;
        }
        // exit(0);
    }

    return 0;
}