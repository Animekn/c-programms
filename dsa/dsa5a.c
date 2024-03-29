#include<stdio.h>

// Function to print array
void display(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Main function to run the program
int main()
{
    int array[] = {8, 6, 4, 20, 24, 2, 10, 12};
    int size = sizeof(array)/sizeof(array[0]);

    printf("Before Insertion sort: \n");
    display(array, size);

    int i, key, j;
    for (i = 1; i < size; i++)
    {
        key = array[i];
        j = i - 1;

        /* Here the elements in b/w array[0 to i-1]
        which are greater than key are moved ahead
        by 1 position each*/
        while (j >= 0 && array[j] > key)
        {
            array[j + 1] = array[j];
            j = j - 1;
        }
        // placing element at its correct position
        array[j + 1] = key;
    }

    printf("After Insertion sort: \n");
    display(array, size);

    return 0;
}
