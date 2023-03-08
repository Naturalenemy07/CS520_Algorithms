#include<iostream>
#include<vector>
#include<random>

int median_of_three(std::vector<int>& array, int begin, int end) {
   /**
    * Input: Array of integers (pointer to array).
    * Output: Index of a chosen integer in the array.
    * Function: Randomly selects three integers in the input array, returns the index of the integer who is the median of the three integers.
   */

   // Random generator used (uniform distribution) for integer selection within array
   std::random_device rd;
   std::mt19937 gen(rd());
   std::uniform_int_distribution<> distrib(begin, end);
   

   // Randomly selects index of three integers, stores in temp array
   int temp[] = {0,0,0};
   for (int i = 0; i < 3; i++) {
      int index = distrib(gen);
      temp[i] = index;
   }

   // chooses the median of the three values, returns the index(in input array) of that median
   int min = 0;
   int max = 0;
   for (int j = 1; j < 3; j++) {
      if (array[temp[j]] < array[temp[min]]) {
         min = j;
      }
      if (array[temp[j]] > array[temp[max]]) {
         max = j;
      }
   }
   return temp[3-(min+max)];
   }

void print_array(std::vector<int>& array, int len) {
   /**
    * Inputs: Array of integers (pointer to array), length of array as an integer.
    * Outputs: Returns nothing.
    * Function: Prints the input array to terminal.
   */

   std::cout << "[";
   for (int i = 0; i < len; i++) {
      std::cout << array[i] << " ";
   }
   std::cout << "]" << std::endl;
}

void swap(std::vector<int>& array, int index_a, int index_b) {
   /**
    * Inputs: Array of integers (pointer to array), two indexes within array that need to have value swapped.
    * Outputs: Returns nothing.
    * Function: Swaps two values within an array, can perform without returning array since operates on array position in memory.
   */

   int temp = array[index_a];
   array[index_a] = array[index_b];
   array[index_b] = temp;
}

int partition(std::vector<int>& array, int begin, int end) {
   /**
    * Inputs: Array of integers (pointer to array), starting index for partition, end index for partition.
    * Outputs: Correct index of the pivot value (if the array was sorted).
    * Function: Uses Hoare's partition to segregate values based on comparison to pivot value. Pivot value is selected using Median of Three method.
   */

   // Create scanners
   int front_scan = begin;
   int rear_scan = end;
 
   // Use median of three method for selection of the pivot value
   int pivot_value_index = median_of_three(array, begin, end);
   int pivot_value = array[pivot_value_index];

   // Swap the first value in subarray with pivot value
   swap(array, begin, pivot_value_index);

   // Partitioning Logic While loop
   while (true) {

      // Front scanner moves up, stopping at any value greater than the pivot value
      while (array[front_scan] <= pivot_value) {
         front_scan++;
         if (front_scan == end) {
            break;
         }
      }

      // Rear scanner moves down, stopping at any value less than the pivot value
      while (array[rear_scan] > pivot_value) {
         rear_scan--;
         if (rear_scan == begin) {
            break;
         }
      }

      /**
       * Makes sure scanners didn't cross, then swaps the front and rear scanner
       * If the scanners did cross, it swaps the pivot value with the value at the rear scanner
       * Swaps are performed in memory position of array
      */
      if (front_scan < rear_scan) {
         swap(array, front_scan, rear_scan);
         std::cout << "Partition value: " << pivot_value << std::endl;
         std::cout << "After swap:" << std::endl;
         print_array(array, array.size());
      } else {
         swap(array, begin, rear_scan);
         std::cout << "Partition value: " << array[rear_scan] << std::endl;
         std::cout << "After partition completion:" << std::endl;
         print_array(array, array.size());
         break;
      }
   }   
   return rear_scan;
}

void qsort(std::vector<int>& array, int low, int high) {
   if (high <= low) {
      return;
   }
   if (high - low == 1) {
      if (array[low] > array[high]) {
         swap(array, low, high);
         return;
      }
   }
   int pivoted = partition(array, low, high);
   qsort(array, low, pivoted-1);
   qsort(array, pivoted+1, high);
}

int main() {
   
   // get user input to create random array
   int len;
   std::cout << "Length: ";
   std::cin >> len;
   std::vector<int> array_to_sort;

   // random number generator for vector creation
   std::random_device rd;
   std::mt19937 gen(rd());
   std::uniform_int_distribution<> distrib(0, len*10);

   // create array
   for (int i = 0; i < len; i++) {
      array_to_sort.push_back(distrib(gen));
   }

   // print current array
   print_array(array_to_sort, len);

   // perform quick sort //
   qsort(array_to_sort, 0, len-1);

   // // print current array
   // print_array(array_to_sort, len);
}
