// partition is not fixed....may just try and copy the code in the textbook....

#include<iostream>
#include<vector>

void median_of_three(std::vector<int>& array, int len) {
   int first = array[0];
   int middle = array[len/2];
   int last = array[len-1];

   std::cout << first << " " << middle << " " << last << std::endl;

   int temp_array[3];

   if (first < middle) {
      temp_array[0] = first;
      temp_array[1] = middle;
   } else {
      temp_array[0] = middle;
      temp_array[1] = first;
   }
   if (middle < last) {
      temp_array[2] = last;
   } else {
      temp_array[1] = last;
      temp_array[2] = middle;
   }
   if (last < first) {
      temp_array[0] = last;
      temp_array[1] = first;
   }
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

int partition(std::vector<int>& array, int begin, int end, int len) {
   // create scanners
   int front_scan = begin;
   int rear_scan = end;

   // pivot value is the first digit
   //need to select the median of three as the pivot value
   int pivot_value = array[begin];
   median_of_three(array, len);

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
      break;
    }
    if (front_scan < rear_scan) {
      swap(array, front_scan, rear_scan);
      return rear_scan;
    }
}

void qsort(std::vector<int>& array, int low, int high, int len) {
   if (high <= low) {
      return;
   }
   int pivoted = partition(array, low, high, len);
   qsort(array, low, pivoted-1, len);
   qsort(array, pivoted+1, high, len);
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
   print_array(array_to_sort, len-1);

   // perform quick sort //
   qsort(array_to_sort, 0, len-1, len);

   // print current array
   print_array(array_to_sort, len-1);
}
