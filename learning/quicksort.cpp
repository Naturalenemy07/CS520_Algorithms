// partition is not fixed....may just try and copy the code in the textbook....

#include<iostream>
#include<vector>
#include<random>

int median_of_three(std::vector<int>& array) {
   int len = array.size();
   std::random_device rd;
   std::mt19937 gen(rd());
   std::uniform_int_distribution<> distrib(0, len-1);

   int temp[] = {0,0,0};

   // randomly selects location of three integers
   for (int i = 0; i < 3; i++) {
      temp[i] = array[distrib(gen)];
   }

   // chooses the middle of the three numbers, returns that number
   int min = 0;
   int max = 0;
   int middle = 0;
   for (int j = 1; j < 3; j++) {
      if (temp[j] < temp[min]) {
         min = j;
      }
      if (temp[j] > temp[max]) {
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

   // pivot value is the first digit
   //need to select the median of three as the pivot value
   int pivot_value = median_of_three(array);

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
   
   return rear_scan;
}

void qsort(std::vector<int>& array, int low, int high) {
   if (high <= low) {
      return;
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
