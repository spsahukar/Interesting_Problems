//
//  byte_media.cpp
//  Learning_2017
//
//  Created by Surya Sahukar on 5/4/17.
//  Copyright © 2017 Surya Sahukar. All rights reserved.
//

#include "byte_median.hpp"
#define ARRAY_LEN 700
void randomize_array(uint8_t byte_array[], uint32_t array_len)
{
    srand (time(NULL));
    for (uint32_t i = 0; i < array_len; i++)
    {
        byte_array[i] = rand() % UINT8_MAX;
    }

}

float media_by_sort(uint8_t byte_array[], uint32_t len)
{
    std::sort(byte_array, byte_array + len);
    printf("After Sort \n");
    //print_array(byte_array, len);
    if (len%2)
        return (byte_array[len/2]);
    else
        return((byte_array[len/2] + byte_array[len/2 - 1])/2.0);
}

void print_array(uint8_t byte_array[], uint32_t len)
{
    uint32_t i = 0;
    
    for(i = 0; i < len; i++)
        printf("byte_array[%d]=%d\n", i, byte_array[i]);
}
float median_array(uint8_t byte_array[], uint32_t len)
{
    int hash[UINT8_MAX+1];
    int i,k;
  
    int count = 0;
    float median = 0;
    
    for(i = 0; i <= UINT8_MAX; i++)
        hash[i] = 0;

    
    for(k = 0; k < len; k++)
        hash[byte_array[k]]++;
    
    for(i = 0; i <= UINT8_MAX; i++)
    {
        count = count + hash[i];
        
        if (len%2)
        {
            if (count >= (len/2 + 1))
            {
                median = i;
                goto RETURN;
            }
        }
                
        else
        {
            if (count == len/2)
            {
                uint32_t j = i + 1;
                while(!hash[j])
                    j++;
                median = (i + j)/2.0;
                goto RETURN;
            }

            if (count > (len/2))
            {
                median = i;
                goto RETURN;
            }
            
        }
        
    }
    
RETURN:
    return median;
}
    
void test_median_array(void)
{
    float median;
    uint8_t byte_array[ARRAY_LEN] = {0};
    randomize_array(byte_array, ARRAY_LEN);
    //print_array(byte_array, ARRAY_LEN);
    median = media_by_sort(byte_array, ARRAY_LEN);
    printf("Median by Sort = %f\n", median);
    median = median_array(byte_array, ARRAY_LEN);
    printf("Median by Hash = %f\n", median);
    
}

