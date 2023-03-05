// partition is not fixed....may just try and copy the code in the textbook....

#include<iostream>
#include<vector>

void print_array(std::vector<int>& array, int len) {
   // print input array
   std::cout << "[";
   for (int i = 0; i < len; i++) {
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

   // pivot value is the first digit
   //need to select the median of three as the pivot value
   int pivot_value = array[begin];

   // partitioning
   while (true) {
      while (array[front_scan] < pivot_value) {
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
    }
    swap(array, front_scan, rear_scan);
    return rear_scan;
}

void sort(std::vector<int>& array, int low, int high) {
   if (high <= low) {
      return;
   }
   int pivoted = partition(array, low, high); 
   sort(array, low, pivoted-1);
   sort(array, pivoted+1, high);
}

int main() {
   
   // get user input to create random array
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
   sort(array_to_sort, 0, len);

   // print current array
   print_array(array_to_sort, len);
}
