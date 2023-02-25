#include <iostream>

int main() 
{
    int arr[] = {6,1,5,3,1};
    int len = 5;
    int min = 0;

    for (int i = 0; i < len-1; i++) {
        min = i;
        int j = i;
        while (j < len-1) {
            j++;
            if (arr[j] < arr[min]) {
                min = j;
            } 
        }
        if (min != i) {
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }

    }

    for (int k = 0; k < len; k++) {
        std::cout << arr[k] << " ";
    }

    return 0;

}
