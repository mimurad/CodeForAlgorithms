#include<stdio.h>
int left(int i)
{
    return 2*i;
}
int right(int i)
{
    return 2*i+1;
}
int parent(int i)
{
    return (int)(i/2);
}
void HeapSort(int nums[], int total);
void BuildHeap(int nums[], int heapSize);
void Heapify(int nums[], int heapSize, int i);
int main()
{
    int arr[100], i, n;
    printf("enter how many numbers :");
    scanf("%d", &n);
    printf("\nenter numbers :\n");
    for(i=1;i<=n;i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Input Array:\n");
    for(i=1;i<=n;i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    HeapSort(arr, n);
    printf("Sorted:\n");
    for(i=1;i<=n;i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}

void HeapSort(int nums[], int total)
{
    int temp, i;
    int heapSize = total;
    BuildHeap(nums, heapSize);
    for(i=total;i>=2;i--)
    {
        temp = nums[1];
        nums[1] = nums[i];
        nums[i] = temp;
        heapSize = heapSize - 1;
        Heapify(nums, heapSize, 1);
    }
}
void BuildHeap(int nums[], int heapSize)
{
    int i;
    for(i=heapSize/2;i>=1;i--)
    {
        Heapify(nums, heapSize, i);
    }
    printf("After BuildHeap\n");
    for(i=1;i<=heapSize;i++)
    {
        printf("%d ", nums[i]);
    }
    printf("\n");
}
void Heapify(int nums[], int heapSize, int i)
{
    int l, r, largest, temp;
    l = left(i);
    r = right(i);
    if(l<=heapSize && nums[l] > nums[i])
        largest = l;
    else
        largest = i;
    if(r<=heapSize && nums[r] > nums[largest])
        largest = r;
    if(largest != i)
    {
        temp = nums[i];
        nums[i] = nums[largest];
        nums[largest] = temp;
        Heapify(nums, heapSize, largest);
    }
}
