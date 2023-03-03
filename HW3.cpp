#include<iostream>

int main() {
   
   // get user input
   int len;
   std::cout << "Length: ";
   std::cin >> len;
   int array_to_sort[len];

   // create array
   for (int i = 0; i < len; i++) {
      array_to_sort[i] = rand() % (len * 10);
   }

   // print input array
   std::cout << "[";
   for (int i = 0; i < len; i++) {
      std::cout << array_to_sort[i] << " ";
   }
   std::cout << "]" << std::endl;

   // perform quick sort //

   // select partition, make temp array
   int a = array_to_sort[0];
   int b = array_to_sort[len-1];
   int c = array_to_sort[len/2];
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

   // create the partition
   array_to_sort[0] = temp_array[0];
   array_to_sort[len/2] = temp_array[1];
   array_to_sort[len-1] = temp_array[2];   

   // set up front, rear counters, and pivot value
   int front_counter = 1;
   int rear_counter = len-2;
   int pivot_index = len/2;
   std::cout << "Pivot Value: " << array_to_sort[pivot_index] << std::endl;

   while (bool test = true) {
      while (array_to_sort[front_counter] < array_to_sort[pivot_index]) {
         std::cout << "Front counter:" << array_to_sort[front_counter] << std::endl;
         front_counter++;
         if (front_counter >= rear_counter) {
            break;
         }
      }
      while (array_to_sort[rear_counter] > array_to_sort[pivot_index]) {
         std::cout << "Rear counter:" << array_to_sort[rear_counter] << std::endl;
         rear_counter--;
         if (rear_counter <= front_counter) {
            break;
         }
      }
      if (front_counter >= rear_counter) {
         test = false;
      }
      int temp_place = array_to_sort[front_counter];
      array_to_sort[front_counter] = array_to_sort[rear_counter];
      array_to_sort[rear_counter] = temp_place;

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
