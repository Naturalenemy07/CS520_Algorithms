#include<iostream>
#include<vector>

int partition(std::vector<int>& array, int begin, int end) {
   // select partition, make temp array
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

   // set up front, rear counters, and pivot value
   int front_counter = begin + 2;
   int rear_counter = end-2;
   int pivot_index = begin + 1;
   std::cout << "Pivot Value: " << array[pivot_index] << std::endl;

   bool test = true;

   while (test == true) {
      while (array[front_counter] < array[pivot_index]) {
         std::cout << "Front counter:" << array[front_counter] << std::endl;
         if (front_counter > rear_counter) {
            break;
         }
         front_counter++;
      }
      while (array[rear_counter] > array[pivot_index]) {
         std::cout << "Rear counter:" << array[rear_counter] << std::endl;
         if (rear_counter < front_counter) {
            break;
         }
         rear_counter--;
      }
      if (front_counter > rear_counter) {
         test = false;
         int pivot_swap = array[pivot_index];
         array[pivot_index] = array[rear_counter];
         array[rear_counter] = pivot_swap;
      } else {
         int temp_place = array[front_counter];
         array[front_counter] = array[rear_counter];
         array[rear_counter] = temp_place;
         front_counter++;
         rear_counter--;
      }
   }
   std::cout << "Partition Ratio: " << (rear_counter*1.0) / (end - begin)*1.0 << std::endl;

   //return pivot point location (ith spot is now known, serve as end of next partitioning)
   return rear_counter;
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

   // print input array
   std::cout << "[";
   for (int i = 0; i < len; i++) {
      std::cout << array_to_sort[i] << " ";
   }
   std::cout << "]" << std::endl;

   // perform quick sort //
   int low = 0;
   int high = len;
   int sorted = 0;
   while (sorted <= len) {
      int pivoted = partition(array_to_sort, low, high);
      low = 0;
      high = pivoted-1;

         // print result after selection sort
      std::cout << "\nAfter partition" << std::endl;

      // print input array
      std::cout << "[";
      for (int i = 0; i < len; i++) {
         std::cout << array_to_sort[i] << " ";
      }
      std::cout << "]" << std::endl;

   }

   // print result after selection sort
   std::cout << "\nAfter quicksort sort" << std::endl;

   // print input array
   std::cout << "[";
   for (int i = 0; i < len; i++) {
      std::cout << array_to_sort[i] << " ";
   }
   std::cout << "]" << std::endl;
}
