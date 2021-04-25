#include "sorts.h"
#include <iostream>
#include <chrono>
#include <cstdlib>
#include <math.h>
using namespace std::chrono;
using namespace std;
void randomarr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        //arr[i] = (rand() % 10000) * pow(-1,rand()%size);
        arr[i] = rand()%size;
    }
}
double time_sort_hi_low(void (*f)(int ar[], int l, int h),int arr[], int low, int high) 
{
    auto t1 = steady_clock::now();
    f(arr,low,high);
    auto t2 = steady_clock::now();
    auto d1 = duration_cast<nanoseconds>(t2 - t1);
    return (double)d1.count();
}
double time_sort_size(void (*f)(int ar[], int size), int arr[], int size) 
{
    auto t1 = steady_clock::now();
    f(arr, size);
    auto t2 = steady_clock::now();
    auto d1 = duration_cast<nanoseconds>(t2 - t1);
    return (double)d1.count();
}
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int partition(int arr[], int l, int h)
{
    int x = arr[h];
    int i = (l - 1);

    for (int j = l; j <= h - 1; j++)
    {
        if (arr[j] <= x)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[h]);
    return (i + 1);
}
void quick_sort(int arr[], int l, int h)
{
    int* stack = new int[h - l + 1];
    int top = -1;

    stack[++top] = l;
    stack[++top] = h;

    while (top >= 0)
    {

        h = stack[top--];
        l = stack[top--];

        int p = partition(arr, l, h);

        if (p - 1 > l)
        {
            stack[++top] = l;
            stack[++top] = p - 1;
        }

        if (p + 1 < h)
        {
            stack[++top] = p + 1;
            stack[++top] = h;
        }
    }
    delete[] stack;
}
void bubble_sort(int arr[], int n)
{
    int i, j, temp;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
void display_array(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << "\t";
}
void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    int* L = new int[n1];
    int* R = new int[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];


    int i = 0;
    int j = 0;
    int k = l;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
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

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
    delete[] L;
    delete[] R;
}
void merge_sort(int arr[], int l, int r)
{
    if (l >= r)
    {
        return;
    }
    int m = l + (r - l) / 2;
    merge_sort(arr, l, m);
    merge_sort(arr, m + 1, r);
    merge(arr, l, m, r);
}

void insertion_sort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        swap(arr[i], arr[largest]);

        heapify(arr, n, largest);
    }
}

void heap_sort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) 
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
int get_max(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}
void _count_sort(int arr[], int n, int exp)
{
    int* output = new int[n];
    int i, count[10] = { 0 };


    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;


    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = n - 1; i >= 0; i--) 
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (i = 0; i < n; i++)
        arr[i] = output[i];
    delete[] output;
}
void radix_sort(int arr[], int n)
{

    int m = get_max(arr, n);

    for (int exp = 1; m / exp > 0; exp *= 10)
        _count_sort(arr, n, exp);
}
void count_sort(int array[], int size) 
{

    int *output = new int[size + 1];
    int *count = new int[size+1];
    int max = array[0];

    for (int i = 1; i < size; i++) 
    {
        if (array[i] > max)
            max = array[i];
    }

    for (int i = 0; i <= max; ++i) 
    {
        count[i] = 0;
    }

    for (int i = 0; i < size; i++) 
    {
        count[array[i]]++;
    }

    for (int i = 1; i <= max; i++) 
    {
        count[i] += count[i - 1];
    }

    for (int i = size - 1; i >= 0; i--) 
    {
        output[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }


    for (int i = 0; i < size; i++) 
    {
        array[i] = output[i];
    }
    delete[] count;
    delete[] output;
}
void selection_sort(int array[], int size) 
{
    for (int step = 0; step < size - 1; step++) 
    {
        int min_idx = step;
        for (int i = step + 1; i < size; i++) 
        {

            if (array[i] < array[min_idx])
                min_idx = i;
        }

        swap(&array[min_idx], &array[step]);
    }
}