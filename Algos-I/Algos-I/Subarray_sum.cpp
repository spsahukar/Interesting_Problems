//
//  Subarray_sum.cpp
//  Learning_2017
//
//  Created by Surya Sahukar on 5/30/17.
//  Copyright © 2017 Surya Sahukar. All rights reserved.
//

#include "Subarray_sum.hpp"

bool subarray_sum(int array[], int arr_len, int K)
{
    int start_idx, end_idx, running_sum;
    int i = 0;
    start_idx = 0;
    end_idx = 0;
    running_sum = 0;
    
    while (i < arr_len)
    {
        running_sum += array[i];
        
        if (running_sum == K)
        {
            end_idx = i;
            printf("TRUE\n");
            printf("Running Sum:%d Start_idx: %d, end_idx: %ds\n", running_sum, start_idx, end_idx);
            return true;
        }
        
        else if (running_sum < K)
            end_idx = i;
        else
        {
            running_sum = running_sum - array[start_idx];
            start_idx++;
        }
        i++;
    }
    
    return false;
}
void subarray_sum_test_stub()
{
    int array[] = {5, 7, 8, 7, 1, 2, 3, 7};
    int arr_len = 8;
    subarray_sum(array, 8, 10);
    
    
}

