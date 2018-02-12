//
//  cpp_arrays.cpp
//  Learning_2017
//
//  Created by Surya Sahukar on 3/22/17.
//  Copyright © 2017 Surya Sahukar. All rights reserved.
//

#include "cpp_arrays.hpp"


int array_at(void)
{
    std::array<int,10> myarray;
    
    // assign some values:
    for (int i=0; i<10; i++) myarray.at(i) = i+1;
    
    // print content:
    std::cout << "myarray contains:";
    for (int i=0; i<10; i++)
        std::cout << ' ' << myarray.at(i);
    std::cout << '\n';
    
    return 0;
}

int array_front_back(void)
{
    std::array<int, 3> myarray;
    myarray = { 1,2,3};
    
    std::cout << "my array back =" << myarray.back() <<std::endl;
    std::cout << "my array front =" << myarray.front() << std::endl;
    
    return 0;
}


int array_traversal(void)
{
    std::array<int, 10> myarray;
    
    for(int i=0; i < myarray.size(); i++)
        myarray.at(i) = i*10;
    
    for (auto it = myarray.begin(); it != myarray.end(); it++)
        std::cout << "Value of element =" << *it << std::endl;
    
    /*Reverse Traversal */
    std::cout << "Reverse Traversal" << std::endl;
    for (auto it = myarray.end(); it != myarray.begin(); it--)
        std::cout << "Value of element =" << *it << std::endl;
        
    return 0;
}



