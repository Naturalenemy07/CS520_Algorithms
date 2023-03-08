#include<iostream>
#include<vector>
#include<random>

int median_of_three(std::vector<int>& array) {
   int len = array.size();
   std::random_device rd;
   std::mt19937 gen(rd());
   std::uniform_int_distribution<> distrib(0, len-1);

   // randomly selects index of three integers, stores in temp array
   int temp[] = {0,0,0};
   for (int i = 0; i < 3; i++) {
      int index = distrib(gen);
      temp[i] = index;
   }

   // chooses the middle of the three values, returns the index(in input array) of that median
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
   // print input array
   std::cout << "[";
   for (int i = 0; i <= len; i++) {
      std::cout << array[i] << " ";
   }
   std::cout << "]" << std::endl;
}

void swap(std::vector<int>& array, int index_a, int index_b) {
   int temp = array[index_a];
   array[index_a] = array[index_b];
   array[index_b] = temp;
}

int partition(std::vector<int>& array, int begin, int end) {
   // create scanners
   int front_scan = begin;
   int rear_scan = end;
 
   //need to select the median of three as the pivot value
   int pivot_value_index = median_of_three(array);
   int pivot_value = array[pivot_value_index];

   // swap the first value in array with pivot value
   swap(array, 0, pivot_value_index);

   // partitioning
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
      // Makes sure scanners didn't cross, then swaps the front and rear scanner
      // If the scanners did cross, it swaps the pivot value with the value at the rear scanner
      if (front_scan < rear_scan) {
         swap(array, front_scan, rear_scan);
         std::cout << "Partition value: " << pivot_value << std::endl;
         std::cout << "After swap:" << std::endl;
         print_array(array, array.size());
      } else {
         swap(array, 0, rear_scan);
         std::cout << "Partition value: " << array[rear_scan] << std::endl;
         std::cout << "After partition completion:" << std::endl;
         print_array(array, array.size());
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
   print_array(array_to_sort, len-1);

   // perform quick sort //
   qsort(array_to_sort, 0, len-1);

   // print current array
   print_array(array_to_sort, len-1);
}
