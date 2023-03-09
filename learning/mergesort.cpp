#include<iostream>
#include<random>
#include<vector>

void mergesort() {
    /**
     * Inputs:
     * Outputs:
     * Function:
     * 
    */
}

int main() {
   // Main function for sorting using quick sort, use input and output logic
   
   // Get user input to create random array
   int len;
   std::cout << "Length: ";
   std::cin >> len;
   std::vector<int> array_to_sort;

   // Random number generator for vector creation
   std::random_device rd;
   std::mt19937 gen(rd());
   std::uniform_int_distribution<> distrib(0, len*10);

   // Create array
   for (int i = 0; i < len; i++) {
      array_to_sort.push_back(distrib(gen));
   }

   // Performmerge sort
   qsort(array_to_sort, 0, len-1);
}
