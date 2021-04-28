#include "sorts.h"

using namespace std::chrono;
using namespace std;
string dataset[] =
{ "Almost_50.txt","Almost_100.txt","Almost_500.txt","Almost_1000.txt","Almost_5000.txt","Almost_10000.txt","Almost_50000.txt",
"Almost_100000.txt","Almost_500000.txt","Almost_1000000.txt","Sorted_50.txt","Sorted_100.txt","Sorted_500.txt","Sorted_1000.txt",
"Sorted_5000.txt","Sorted_10000.txt","Sorted_50000.txt","Sorted_100000.txt","Sorted_500000.txt","Sorted_1000000.txt","Random_50.txt",
"Random_100.txt","Random_500.txt","Random_1000.txt","Random_5000.txt","Random_10000.txt","Random_50000.txt","Random_100000.txt",
"Random_500000.txt","Random_1000000.txt","Reverse_50.txt","Reverse_100.txt","Reverse_500.txt","Reverse_1000.txt","Reverse_5000.txt",
"Reverse_10000.txt","Reverse_50000.txt","Reverse_100000.txt","Reverse_500000.txt","Reverse_1000000.txt","Small_range_50.txt",
"Small_range_100.txt","Small_range_500.txt","Small_range_1000.txt","Small_range_5000.txt","Small_range_10000.txt","Small_range_50000.txt",
"Small_range_100000.txt","Small_range_500000.txt","Small_range_1000000.txt" };
void randomarr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        //arr[i] = (rand() % 10000) * pow(-1,rand()%size);
        arr[i] = size - i;
    }
}
void copy_arr(int source[], int dest[], int size)
{
    for (int i = 0; i < size; i++)
    {
        dest[i] = source[i];
    }
}
void pos_copy_arr(int source[], int dest[], int size)
{
    for (int i = 0; i < size; i++)
    {
        dest[i] = abs(source[i]);
    }
}
void write_to_file(int size, string name, int arr[])
{
    ofstream fp("times.csv", std::ios::app);
    double time;
    int* copy = new int[size+1];
    copy_arr(arr, copy, size);
    time = time_sort_hi_low(merge_sort, copy, 0, size - 1) / 1000000000;
    fp << fixed << "Merge Sort," << name << " sorted," << size << "," << time << "," << endl;
    copy_arr(arr, copy, size);
    time = time_sort_hi_low(quick_sort, copy, 0, size - 1) / 1000000000;
    fp << fixed << "Quick Sort," << name << " sorted," << size << "," << time << "," << endl;
    copy_arr(arr, copy, size);
    time = time_sort_size(bubble_sort, copy, size) / 1000000000;
    fp << fixed << "Bubble Sort," << name << " sorted," << size << "," << time << "," << endl;
    copy_arr(arr, copy, size);
    time = time_sort_size(insertion_sort, copy, size) / 1000000000;
    fp << fixed << "Insertion Sort," << name << " sorted," << size << "," << time << "," << endl;
    copy_arr(arr, copy, size);
    time = time_sort_size(selection_sort, copy, size) / 1000000000;
    fp << fixed << "Selection Sort," << name << " sorted," << size << "," << time << "," << endl;
    copy_arr(arr, copy, size);
    time = time_sort_size(heap_sort, copy, size) / 1000000000;
    fp << fixed << "Heap Sort," << name << " sorted," << size << "," << time << "," << endl;
    pos_copy_arr(arr, copy, size);
    time = time_sort_size(radix_sort, copy, size) / 1000000000;
    fp << fixed << "Radix Sort," << name << " sorted," << size << "," << time << "," << endl;
    fp.close();
    delete[] copy;
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
    int* stack = new int[h - l + 2];
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
        cout << arr[i] << "\n";
}
void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    int* L = new int[n1+1];
    int* R = new int[n2+1];

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
void _count_sort(int array[], int size , int place)
{
    int max = get_max(array, size);
    int* output = new int[size+1];
    int* count = new int[max+1];

    for (int i = 0; i < max; ++i)
        count[i] = 0;


    for (int i = 0; i < size; i++)
        count[(array[i] / place) % 10]++;


    for (int i = 1; i < max; i++)
        count[i] += count[i - 1];

    for (int i = size - 1; i >= 0; i--) {
        output[count[(array[i] / place) % 10] - 1] = array[i];
        count[(array[i] / place) % 10]--;
    }

    for (int i = 0; i < size; i++)
        array[i] = output[i];
    delete[] output, count;
}
void radix_sort(int arr[], int n)
{

    int m = get_max(arr, n);

    for (int exp = 1; m / exp > 0; exp *= 10)
        _count_sort(arr, n, exp);
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