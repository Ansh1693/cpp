
// 1. Implement operations(traverse, insert, delete, linear search, selection sort) on an array

#include <stdio.h>

int arr[100];
int count = 0;
void tra();
void ins();
void del();
void ser1();
int ser2(int f);
void selsort();
void prr();
void swp(int *xp, int *yp);

int main()
{
    int tt = true;
    while (tt)
    {
        char c;
        printf("\nSelect an operation \nA : Traverse \nB : Insert \nC : Delete \nD : Search\nE : Selection Sort \nF : Exit\n");
        scanf("%c", &c);
        fflush(stdin);

        switch (c)
        {
        case 'F':
            tt = false;
            break;
        case 'A':
            tra();
            break;
        case 'B':
            ins();
            break;
        case 'C':
            del();
            break;
        case 'D':
            ser1();
            break;
        case 'E':
            selsort();
            break;
        default:
            printf("Entered instruction is not a valid operation");
        }
    }
    return 0;
}
void prr()
{
    printf("Number of Elements in the array : %d\n", count);
    for (int i = 0; i < count; i++)
    {
        printf("%d ", arr[i]);
    }
}
void tra()
{
    if (count == 0)
    {
        printf("Array is Empty");
        return;
    }
    else
    {
        prr();
    }
}
void ins()
{

    if (count >= 100)
    {
        printf("Array is Full");
        return;
    }
    int n;
    printf("Enter an integral value : ");
    scanf("%d", &n);
    fflush(stdin);
    if (count == 0)
    {
        arr[0] = n;
        count++;
        prr();
        return;
    }
    char posi;
    prr();
    printf("\nWhere to input \nS : Start \nE : End\nP : Enter at a certain position\n");
    scanf("%c", &posi);
    fflush(stdin);
    if (posi == 'E')
    {
        arr[count] = n;
        count++;
        prr();
        return;
    }
    else if (posi == 'S')
    {
        for (int i = count; i >= 1; i--)
        {
            arr[i] = arr[i - 1];
        }
        arr[0] = n;
        count++;
        prr();
    }
    else if (posi == 'P')
    {
        int q;
        printf("Enter the index where you want to input : ");
        scanf("%d", &q);
        fflush(stdin);
        if (q > count || q < 0)
        {
            printf("Entered index is not a valid input");
            return;
        }
        for (int i = count - 1; i >= q - 1; i--)
        {
            arr[i + 1] = arr[i];
        }
        arr[q - 1] = n;
        count++;
        prr();
    }

    else
    {
        printf("Entered instruction is not a valid operation");
    }
}
void del()
{
    if (count == 0)
    {
        printf("Array is empty");
        return;
    }
    int n;
    printf("Enter a no. to be deleted : \n");
    scanf("%d", &n);
    fflush(stdin);
    int index = ser2(n);
    if (index == -1)
    {
        printf("Entered number is not present in Array\n");
        prr();
        return;
    }
    for (int i = index; i < count - 1; i++)
    {
        arr[i] = arr[i + 1];
    }

    count--;
    prr();
}

void ser1()
{
    if (count == 0)
    {
        printf("Array is empty");
        return;
    }
    int f;
    printf("Enter a number to search : ");
    scanf("%d", &f);
    fflush(stdin);
    int po = ser2(f);
    if (po != -1)
    {
        printf("Entered number is present in Array at index %d", po + 1);
    }
    else
    {
        printf("Entered number is not present in Array");
    }
}
int ser2(int f)
{
    for (int i = 0; i < count; i++)
    {
        if (arr[i] == f)
        {
            return i;
        }
    }
    return -1;
}
void swp(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selsort()
{
    int minindex;
    for (int i = 0; i < count - 1; i++)
    {
        minindex = i;
        for (int j = i + 1; j < count; j++)
        {
            if (arr[j] < arr[minindex])
            {
                minindex = j;
            }
        }
        if (minindex != i)
        {
            swp(&arr[minindex], &arr[i]);
        }
    }
    prr();
}
