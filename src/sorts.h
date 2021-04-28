#pragma once
#include <iostream>
#include <chrono>
#include <math.h>
#include <string>
#include <fstream>
#include <sstream>
extern std::string dataset[50];
double time_sort_hi_low(void (*f)(int ar[], int l, int h), int arr[], int low, int high);
double time_sort_size(void (*f)(int ar[], int size), int arr[], int size);
int get_max(int arr[], int n);
void display_array(int arr[], int size);
void copy_arr(int[], int[],int);
void pos_copy_arr(int[], int[], int);
void randomarr(int arr[], int size);
void write_to_file(int size, std::string name, int arr[]);
void heapify(int arr[], int n, int i);
void _count_sort(int arr[], int n, int exp);
void merge(int arr[], int l, int m, int r);
void quick_sort(int arr[], int low, int high);//iterative // hi low
void bubble_sort(int arr[], int n ); // size
void merge_sort(int arr[], int l, int r); // hi low
void insertion_sort(int arr[], int n); // size
void heap_sort(int arr[], int n); // size
void radix_sort(int arr[], int n); // size
void count_sort(int array[], int size); // size
void selection_sort(int array[], int size); // size

