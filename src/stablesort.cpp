// stable version of selection sort

#include <string.h>
#include <iostream>

void stablesort(int array[], int length) {
    for(int idx = 0; idx < length-1; idx++) {
        int target = idx;
        for(int tidx = idx; tidx < length; tidx++) {
            if( array[target] > array[tidx] ) {
                target = tidx;
            }
        }
        std::cout << target << std::endl;
        int val = array[target];
        memmove(array+idx+1, array+idx, (target-idx)*sizeof(int));
        array[idx] = val;
    }
}

int main()
{
    int array[10] = {3,4,5,23,7,21,4,7,1,87};
    for(auto a : array) {
        std::cout << a << " ";
    }
    std::cout << std::endl;
    stablesort(array, 10);
    for(auto a : array) {
        std::cout << a << " ";
    }
    std::cout << std::endl;
    return 0;
}
