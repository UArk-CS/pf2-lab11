// Created by Ben Worthington 4/13/21

#include <iostream>
using namespace std;

// Global variables
int ARRAY_SIZE = 1000;
int COMPARE_COUNTER = 0;
int MOVE_COUNTER = 0;

// Declare functions
void create_random_data(int data[], int count, int range);
void create_mostly_sorted_data(int data[], int count, int swaps);
void insertion_sort(int data[], int low, int high);
void partition(int data[], int low, int high, int &mid);
void quick_sort(int data[], int low, int high);
void merge_sort(int data[], int low, int high);

int main() {

    int data[ARRAY_SIZE];

    // INSERTION SORT TESTS
    cout << "INSERTION SORT TESTS" << endl;
    cout << endl;

    for (int i = 0; i < 3; i++) {

        cout << "Array Size: " << ARRAY_SIZE << endl;
        cout << endl;

        // Random data
        create_random_data(data, ARRAY_SIZE, ARRAY_SIZE - 1);
        insertion_sort(data, 0, ARRAY_SIZE - 1);
        cout << "Random Data: " << endl;
        cout << "Compares: " << COMPARE_COUNTER << endl;
        cout << "Moves: " << MOVE_COUNTER << endl;
        cout << endl;

        // Reset counters
        COMPARE_COUNTER = 0;
        MOVE_COUNTER = 0;

        // Mostly sorted data
        create_mostly_sorted_data(data, ARRAY_SIZE, ARRAY_SIZE / 10);
        insertion_sort(data, 0, ARRAY_SIZE - 1);
        cout << "Mostly Sorted Data: " << endl;
        cout << "Compares: " << COMPARE_COUNTER << endl;
        cout << "Moves: " << MOVE_COUNTER << endl;
        cout << endl;

        // Reset counters
        COMPARE_COUNTER = 0;
        MOVE_COUNTER = 0;

        insertion_sort(data, 0, ARRAY_SIZE - 1);
        cout << "Sorted Data: " << endl;
        cout << "Compares: " << COMPARE_COUNTER << endl;
        cout << "Moves: " << MOVE_COUNTER << endl;
        cout << endl;

        // Reset counters
        COMPARE_COUNTER = 0;
        MOVE_COUNTER = 0;

        ARRAY_SIZE /= 10;

    }

    // Reset array size
    ARRAY_SIZE = 1000;

    // MERGE SORT TESTS
    cout << "MERGE SORT TESTS" << endl;
    cout << endl;

    for (int i = 0; i < 3; i++) {

        cout << "Array Size: " << ARRAY_SIZE << endl;
        cout << endl;

        // Random data
        create_random_data(data, ARRAY_SIZE, ARRAY_SIZE - 1);
        merge_sort(data, 0, ARRAY_SIZE - 1);
        cout << "Random Data: " << endl;
        cout << "Compares: " << COMPARE_COUNTER << endl;
        cout << "Moves: " << MOVE_COUNTER << endl;
        cout << endl;

        // Reset counters
        COMPARE_COUNTER = 0;
        MOVE_COUNTER = 0;

        // Mostly sorted data
        create_mostly_sorted_data(data, ARRAY_SIZE, ARRAY_SIZE / 10);
        merge_sort(data, 0, ARRAY_SIZE - 1);
        cout << "Mostly Sorted Data: " << endl;
        cout << "Compares: " << COMPARE_COUNTER << endl;
        cout << "Moves: " << MOVE_COUNTER << endl;
        cout << endl;


        // Reset counters
        COMPARE_COUNTER = 0;
        MOVE_COUNTER = 0;

        merge_sort(data, 0, ARRAY_SIZE - 1);
        cout << "Sorted Data: " << endl;
        cout << "Compares: " << COMPARE_COUNTER << endl;
        cout << "Moves: " << MOVE_COUNTER << endl;
        cout << endl;

        // Reset counters
        COMPARE_COUNTER = 0;
        MOVE_COUNTER = 0;

        ARRAY_SIZE /= 10;

    }

    // Reset array size
    ARRAY_SIZE = 1000;

    return 0;

}

void create_random_data(int data[], int count, int range)
{
    // Put specified count of random numbers into data array
    for (int index = 0; index < count; index++)
        data[index] = rand() % range;
}

void create_mostly_sorted_data(int data[], int count, int swaps)
{
    // Put sorted data values into array
    for (int index = 0; index < count; index++)
        data[index] = index;

    // Shuffle data by swapping random pairs of values
    for (int index = 0; index < swaps; index++)
    {
        int pos1 = rand() % count;
        int pos2 = rand() % count;
        int temp = data[pos1];
        data[pos1] = data[pos2];
        data[pos2] = temp;
    }
}

void insertion_sort(int data[], int low, int high)
{
    // Insert each element of unsorted list into sorted list
    for (int unsorted = low+1; unsorted <= high; unsorted++)
    {

        // Select unsorted value to be inserted
        int value = data[unsorted];
        int posn = unsorted;

        // Make room for new data value
        while ((posn > 0) && (data[posn - 1] > value))
        {

            COMPARE_COUNTER++;

            data[posn] = data[posn - 1];
            posn--;

        }

        // Put new value into array
        data[posn] = value;

        MOVE_COUNTER++;

    }
}

void quick_sort(int data[], int low, int high)
{
    // Check terminating condition
    if (low < high)
    {
        // Partition data into two parts
        int mid = 0;
        partition(data, low, high, mid);

        // Recursive calls to sort array
        quick_sort(data, low, mid - 1);
        quick_sort(data, mid + 1, high);
    }
}

void partition(int data[], int low, int high, int &mid)
{
    // Select pivot value
    int pivot = data[high];
    int left = low;
    int right = high;

    // Partition array into two parts
    while (left < right)
    {
        // Scan left to right
        while ((left < right) && (data[left] < pivot))
            left++;

        // Scan right to left
        while ((left < right) && (data[right] >= pivot))
            right--;

        // Swap data values
        int temp = data[left];
        data[left] = data[right];
        data[right] = temp;
    }

    // Swap pivot to mid
    mid = left;
    data[high] = data[mid];
    data[mid] = pivot;
}

void merge_sort(int data[], int low, int high)
{
    // Check terminating condition
    int range = high - low + 1;
    if (range > 1)
    {
        // Divide the array and sort both halves
        int mid = (low + high) / 2;
        merge_sort(data, low, mid);
        merge_sort(data, mid + 1, high);

        // Create temporary array for merged data
        int *copy = new int[range];

        // Initialize array indices
        int index1 = low;
        int index2 = mid + 1;
        int index = 0;

        // Merge smallest data elements into copy array
        while (index1 <= mid && index2 <= high)
        {
            if (data[index1] < data[index2]) {

                COMPARE_COUNTER++;

                copy[index++] = data[index1++];

                MOVE_COUNTER++;

            } else {

                copy[index++] = data[index2++];

                MOVE_COUNTER++;

            }
        }

        // Copy any remaining entries from the first half
        while (index1 <= mid) {

            copy[index++] = data[index1++];

            MOVE_COUNTER++;

        }

        // Copy any remaining entries from the second half
        while (index2 <= high) {

            copy[index++] = data[index2++];

            MOVE_COUNTER++;

        }

        // Copy data back from the temporary array
        for (index = 0; index < range; index++) {

            data[low + index] = copy[index];

            MOVE_COUNTER++;

        }
        delete []copy;
    }
}