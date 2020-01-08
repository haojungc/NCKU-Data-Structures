#include <cstdio>
#include <fstream>
#include <time.h>

using std::fstream;
using std::ios;

void quicksort(int, int);
void validate(int);
void swap(int *, int *);

const int MAX_SIZE = 155000;
int data[MAX_SIZE];

int main() {
    printf("/* Leftmost & Shorter First */\n");

    int count = 0;

    // Open file & read data
    fstream file;
    file.open("test data.txt", ios::in);
    printf("Reading data......");
    while (file >> data[count])
        count++;
    if (count == 0) {
        printf("\nSomething went wrong!\n");
        abort();
    } else
        printf("Done!\n");
    file.close();

    // Set clock
    clock_t start, end;
    double cpu_time_used;

    // Quicksort & calculate time duration
    start = clock();
    quicksort(0, count - 1);
    end = clock();

    // Check if quicksort succeeded
    validate(count);

    // Show time duration
    cpu_time_used = static_cast<double>(end - start) / CLOCKS_PER_SEC;
    printf("Execution time = %lf\n\n", cpu_time_used);

    return 0;
}

void quicksort(int left, int right) {
    if (left >= right)
        return;

    int pivot  = data[left];
    int lIndex = left + 1; // left index
    int rIndex = right;    // right index

    while (true) {
        // Find the first index which its value is smaller than the pivot
        while (rIndex >= lIndex && data[rIndex] >= pivot)
            rIndex--; // <--

        // Find the first index which its value is greater than the pivot
        while (lIndex < rIndex && data[lIndex] < pivot)
            lIndex++; // -->

        if (lIndex >= rIndex)
            break;

        swap(&data[lIndex], &data[rIndex]);
    }

    // Swap pivot with the insertion point
    swap(&data[left], &data[rIndex]);

    // left part is shorter than right part
    if (((rIndex - 1) - left) < (right - (rIndex + 1))) {
        // Quicksort left part
        quicksort(left, rIndex - 1);

        //Quicksort right part
        quicksort(rIndex + 1, right);
    } else {
        //Quicksort right part
        quicksort(rIndex + 1, right);

        // Quicksort left part
        quicksort(left, rIndex - 1);
    }
}

void validate(int length) {
    bool succeeded = true;

    for (int i = 0; i < length - 1; i++) {
        if (data[i] > data[i + 1]) {
            succeeded = false;
            break;
        }
    }

    if (!succeeded) {
        printf("Something went wrong!\n");
        abort();
    } else {
        printf("Quicksort Succeeded\n");
    }
}

void swap(int *a, int *b) {
    int tmp = *a;
    *a      = *b;
    *b      = tmp;
}