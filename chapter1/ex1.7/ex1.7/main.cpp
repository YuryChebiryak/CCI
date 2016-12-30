//
//  main.cpp
//  ex1.7
//
//  Created by Yury Chebiryak on 30/12/16.
//  Copyright © 2016 Yury Chebiryak. All rights reserved.
//

//1.7 Write an algorithm such that if an element in an MxN matrix is 0, its entire row and column are set to 0.

#include <iostream>

int index(int i, int j, int N) {
    return i * N + j;
}

void transform(int m[], int M, int N) {
    // first pass mark rows and columns
    bool zero_in_first_row = false;
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            if (m[index(i,j,N)] == 0) {
                if (i == 0) {
                    zero_in_first_row = true;
                    m[index(0, j, N)] = 0;
                } else {
                    m[index(i, 0, N)] = 0;
                    m[index(0, j, N)] = 0;
                }
            }
        }
    }
    for (int i = 1; i < M; ++i)
        if (m[index(i, 0, N)] == 0)
            for (int j = 1; j < N; ++j)
                m[index(i, j, N)] = 0;
    for (int j = 0; j < N; ++j)
        if (m[index(0, j, N)] == 0)
            for (int i = 1; i < M; ++i)
                m[index(i, j, N)] = 0;
    if (zero_in_first_row)
        for (int j = 0; j < N; ++j)
            m[index(0, j, N)] = 0;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    int m[] = {1,1,3,0, 4,5,6,7, 7,8,1,9, 1, 1, 1, 1};
    transform(m, 4, 4);
    std::cout << m[0] << m[1] << m[2] << m[3] << std::endl;
    std::cout << m[4] << m[5] << m[6] << m[7] << std::endl;
    std::cout << m[8] << m[9] << m[10] << m[11]<< std::endl;
    std::cout << m[12]<< m[13]<< m[14]<< m[15]<< std::endl << std::endl;
    return 0;
}
