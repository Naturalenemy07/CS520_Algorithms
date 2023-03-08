#include<iostream>
#include<vector>
#include<random>

void print_array(int array[], int len) {
   // print input array
   std::cout << "[";
   for (int i = 0; i < len; i++) {
      std::cout << array[i] << " ";
   }
   std::cout << "]" << std::endl;

   return;
}

void swap(int array[], int index_a, int index_b) {
   int temp = array[index_a];
   array[index_a] = array[index_b];
   array[index_b] = temp;

   return;
}

int median_of_three(int array[]) {
   int len = 15; // change when 
   std::random_device rd;
   std::mt19937 gen(rd());
   std::uniform_int_distribution<> distrib(0, len-1);

   int temp[] = {0,0,0};

   // randomly selects location of three integers
   for (int i = 0; i < 3; i++) {
      //  add so that index is returned
      int index = distrib(gen);
      temp[i] = index;
   }

   // chooses the middle of the three numbers, returns that number
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
   std::cout << array[temp[0]] << " " << array[temp[1]] << " " << array[temp[2]] << std::endl;
   std::cout << "MoT Index: " << temp[3-(min+max)] << std::endl;
   std::cout << "MoT Value: " << array[temp[3-(min+max)]] << std::endl;
   return temp[3-(min+max)];
   
}

int partition(int array[], int begin, int end) {
   // create scanners
   int front_scan = begin;
   int rear_scan = end;
 
   //need to select the median of three as the pivot value
   int pivot_value_index = median_of_three(array);
   int pivot_value = array[pivot_value_index];

   // swap first number with pivot value
   //swap(array, front_scan, rear_scan);
   array[pivot_value_index] = array[0];
   array[0] = pivot_value;
   // delete above, just use swap function

   // partitioning
   while (true) {
      while (array[front_scan] <= pivot_value) {
         front_scan++;
         if (front_scan == end) {
            break;
         }
      }
      while (array[rear_scan] > pivot_value) {
         rear_scan--;
         if (rear_scan == begin) {
            break;
         }
      }
   
      if (front_scan < rear_scan) {
         //swap(array, front_scan, rear_scan);
         ////////////////////////////////////////
         int temp = array[front_scan];
         array[front_scan] = array[rear_scan];
         array[rear_scan] = temp;
         
         std::cout << "Partition value: " << pivot_value << std::endl;
         std::cout << "After swap:" << std::endl;
         print_array(array, 15);
         ///  remove above code and uncomment swap
      } else {
         //swap(array, 0, rear_scan)
         array[0] = array[rear_scan];
         array[rear_scan] = pivot_value;
         
         std::cout << "Partition value: " << array[rear_scan] << std::endl;
         std::cout << "After partition completion:" << std::endl;
         print_array(array, 15);
         break;
      }
   }
   return rear_scan;
}

int main() {
   int array[15] = {7, 12, 4, 3, 1, 21, 17, 6, 22, 9, 15, 1, 19, 20, 25}; //
   int len = sizeof(array)/4;
   std::cout << "Before Partition: " << std::endl;
   print_array(array,len);
   int partition_index = partition(array, 0, len-1);
   std::cout << "After Partitions with partition value of: " << array[partition_index] << std::endl;
   print_array(array, len);
   return 0;
   }
