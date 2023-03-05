// partition is not fixed....may just try and copy the code in the textbook....

#include<iostream>
#include<vector>

void swap(std::vector<int>& array, int index_a, int index_b) {
   int temp = array[index_a];
   array[index_a] = array[index_b];
   array[index_b] = temp;
}

void sort(std::vector<int>& array, int low, int high) {
   if (high <= low) {
      return;
   }
   int pivoted = partition(array, low, high); 
   sort(array, low, pivoted-1);
   sort(array, pivoted+1, high);
}

void print_array(std::vector<int>& array, int len) {
   // print input array
   std::cout << "[";
   for (int i = 0; i < len; i++) {
      std::cout << array[i] << " ";
   }
   std::cout << "]" << std::endl;
}

int partition(std::vector<int>& array, int begin, int end) {
   // select partition, make temp array.  Only works if subarray is 3 or more
   int a = array[begin];
   int b = array[end-1];
   int c = array[end/2];
   int temp_array[3] = {a, b, c};

   // sort the temp array using insertion sort
   for (int dum_i = 1; dum_i < 3; dum_i++) {
      // compare array[dum_i] to item on left
      int temp = 0;
      int count = dum_i;
      // repeat while array[dum_i] is less than item to its left
      while (temp_array[count] < temp_array[count -1] && count > 0) {
            temp = temp_array[count];
            temp_array[count] = temp_array[count-1];
            temp_array[count-1] = temp;
            count--;
            }
   }

   // create the partition, store the pivot value a position 1
   array[begin] = temp_array[0]; // less than median
   array[begin + 1] = temp_array[1]; // pivot value (median of 3)
   array[end-1] = temp_array[2];   // greater than pivot (at end of array)

   std::cout << "Pivot Value: " << temp_array[1] << std::endl;

   // set up front, rear counters, and pivot value
   int front_scan = begin + 2;
   int rear_scan = end-2;
   int pivot_index = begin + 1;

   // scan left, then right, swap values scanners stopped at
   while (rear_scan >= front_scan) {
      while (array[front_scan] <= array[pivot_index]) {
         front_scan++;
      }
      while (array[rear_scan] > array[pivot_index]) {
         rear_scan--;
      }
      if (rear_scan > front_scan) {
         swap(array, front_scan, rear_scan);
      } else{
         break;
      }
   }

   // swap pivot index with rear_scan
   swap(array, rear_scan, pivot_index);

   std::cout << "Partition Ratio: " << (rear_scan*1.0) / (end - begin)*1.0 << std::endl;

   //return pivot point location (ith spot is now known, serve as end of next partitioning)
   return rear_scan;
}

int main() {
   
   // get user input
   int len;
   std::cout << "Length: ";
   std::cin >> len;
   std::vector<int> array_to_sort;

   // create array
   for (int i = 0; i < len; i++) {
      array_to_sort.push_back(rand() % (len * 10));
   }

   // print current array
   print_array(array_to_sort, len);

   // perform quick sort //
   sort(array_to_sort);

   // print current array
   print_array(array_to_sort, len);
}
