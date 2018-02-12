//
//  histogram_area.cpp
//  Learning_2017
//
//  Created by Surya Sahukar on 12/8/17.
//  Copyright © 2017 Surya Sahukar. All rights reserved.
//

#include "histogram_area.hpp"

int max_hist_area(int hist[], int n)
{
    
    std::stack<int> s;
    
    int max_area = 0;
    int tp;
    int area_with_top;
    
    int i = 0;
    while (i < n)
    {
        if (s.empty() || hist[s.top()] <= hist[i])
            s.push(i++);
        else
        {
            tp = s.top();  // store the top index
            s.pop();  // pop the top
            area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1);
            if (max_area < area_with_top)
            {
                max_area = area_with_top;
            }
        }
    }
    
    while (!s.empty())
    {
        tp = s.top();
        s.pop();
        area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1);
        
        if (max_area < area_with_top)
            max_area = area_with_top;
    }
    
    return max_area;
}

void test_histogram_area(void)
{
    int myarray[] = { 5, 2, 3, 7, 4, 1, 7, 9};
    int area = max_hist_area(myarray, 8);
    
    printf("Max Histogram Area = %d\n", area);
    
}
