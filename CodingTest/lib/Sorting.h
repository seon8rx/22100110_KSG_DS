#include <iostream>
using namespace std;

void printarray(int *arr, int n);
void selectionSort(int *arr, int n);
void insertionSort(int *arr, int n);
void bubbleSortAsc(int *arr, int n);
void bubbleSortDes(int *arr, int n);
void quickSort(int *arr, int low, int high, int arrsize);
int isSorted(char *a, int i, int j);
void merge(int *a, int *aux, int lo, int mi, int hi);
void mergeSort(int *a, int *aux, int N, int lo, int hi);