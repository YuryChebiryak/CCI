//
//  main.cpp
//  ex1.6
//
//  Created by Yury Chebiryak on 26/12/16.
//  Copyright © 2016 Yury Chebiryak. All rights reserved.
//

//1.6 Given an image represented by an NxN matrix, where each pixel in the image is 4
// bytes, write a method to rotate the image by 90 degrees. Can you do this in place?

// A B C D
// E F G H
// I J K L
// M N O P

//  M I E A
//  N J F B
//  O K G C
//  P L H D

// 4 bytes = 32 bit int,
// in-place rotation is shifting each M[i,j] (so i * sz + j mod sz * 4) into i * sz + j + sz - 1 mod sz * 4 for i running from 0 to sz, and then recursive call to the inner square (sz - 2)

#include <iostream>

void rotate(char m[], int sz) {
    for (int q = 0; q < 3; ++q) {
        for (int i = 0; i < sz; ++i) {
            for (int j = 0; j < sz; ++j) {
                //            //identify the quadrant
                if ((j >= i) and (i + j < sz - 1) and q == 0) {
                    //top quadrant
                    // the row index becomes the column index
                    std::swap(m[i* sz + j], m[(j* sz + sz - i - 1) % (sz * sz)]);
                }
                if ((j > i) and (i + j >= sz - 1) and q == 1) {
                    // right quadrant
                    std::swap(m[i* sz + j], m[(j* sz + sz - i - 1) % (sz * sz)]);
                }
                if ((j<=i) and (i + j > sz - 1) and q == 2)
                    std::swap(m[i* sz + j], m[(j* sz + sz - i - 1) % (sz * sz)]);
                if ((j < i) and (i + i <= sz -1) and q == 3) // NOT NEEDED!
                    std::swap(m[i* sz + j], m[(j* sz + sz - i - 1) % (sz * sz)]);
            }
        }
                    std::cout << m[0] << m[1] << m[2] << m[3] << std::endl;
                    std::cout << m[4] << m[5] << m[6] << m[7] << std::endl;
                    std::cout << m[8] << m[9] << m[10] << m[11]<< std::endl;
                    std::cout << m[12]<< m[13]<< m[14]<< m[15]<< std::endl;
    }
}

int index(int i, int j, int sz) {
    return (i * sz + j) % (sz * sz);
}

void rotate2(char m[], int sz) {
    for (int offset = 0; offset < sz/2; ++offset) {
        for (int i = 0; offset + i + offset < sz - 1; ++i) {
            std::swap(m[index(offset, i + offset, sz)], m[index(i + offset, sz - offset - 1, sz)]);
            std::swap(m[index(i + offset, sz - offset - 1, sz)], m[index(sz - offset - 1, sz - i - offset -1, sz)]);
            std::swap(m[index(sz - offset - 1, sz - i - offset - 1, sz)], m[index(sz - i - offset - 1, offset, sz)]);
        }
        std::cout << m[0] << m[1] << m[2] << m[3] << std::endl;
        std::cout << m[4] << m[5] << m[6] << m[7] << std::endl;
        std::cout << m[8] << m[9] << m[10] << m[11]<< std::endl;
        std::cout << m[12]<< m[13]<< m[14]<< m[15]<< std::endl;
    }
}

int main(int argc, const char * argv[]) {
    //char* test = "ABCDEFGHIJKLMNOP";
    char test[] = {'A','B','C','D', 'e','f','g','h', 'i','j','k','l', 'm','n','O','p', '_', ' ', '\r','\n'};
    // insert code here...
    std::cout << test << std::endl;
    rotate2(test, 4);
    std::cout << test << std::endl;
    return 0;
}
