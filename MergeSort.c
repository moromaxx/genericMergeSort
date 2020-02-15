//
//  MergeSort.c
//  Matala 7
//
//  Created by Maks Moroshek on 1/10/20.
//  Copyright © 2020 Maks Moroshek. All rights reserved.
//

#include "MergeSort.h"

/*
 
 My own implementation of function memcpy(void *__dest, void *__src, size_t __n) for fun
 
 */
void copyFromTo(void* dest, void* src, size_t size){
    char* d = (char*)dest;
    char* s = (char*)src;
    for (int i=0; i < size; i++){
        d[i] = s[i];
    }
}

void* merge(void* left, size_t lsize, void* right, size_t rsize, size_t size, int (*compar)(const void *, const void*)){
    
    char* sorted = (char*)malloc((lsize + rsize)*size);
    char* l = (char*)left;
    char* r = (char*)right;
    
    int scounter = 0;
    int lcounter = 0;
    int rcounter = 0;
    
    while (lcounter < lsize && rcounter < rsize){
        if ((compar(l + (lcounter * size), r + (rcounter * size))) < 0){
            copyFromTo(sorted + (scounter * size), left + (lcounter * size), size);
            lcounter++;
        }
        else {
            copyFromTo(sorted + (scounter * size), right + (rcounter * size), size);
            rcounter++;
        }
        scounter++;
    }
    
    while (lcounter < lsize){
        copyFromTo(sorted + (scounter * size), left + (lcounter * size), size);
        lcounter++;
        scounter++;
    }
    
    while (rcounter < rsize){
        copyFromTo(sorted + (scounter * size), right + (rcounter * size), size);
        rcounter++;
        scounter++;
    }
    return sorted;
}






void mergeSort(void* base, size_t nitems, size_t size, int (*compar)(const void *, const void*)){
    
    if (nitems <= 1){
        return;
    }
    
    char* array = (char*)base;
    char* left = (char*)malloc(sizeof(char) * size * (nitems / 2));
    char* right = (char*)malloc(size * (nitems - (nitems / 2)));
    
    copyFromTo(left, array, size * (nitems / 2));
    copyFromTo(right, array + (nitems / 2) * size, size * (nitems - nitems / 2));
    
    mergeSort(left, nitems / 2, size, compar);
    mergeSort(right, nitems - (nitems / 2), size, compar);
    void* merged = merge(left, nitems / 2, right, nitems - (nitems / 2), size, compar);
    copyFromTo((void*)array, merged, nitems * size);
    
    free(merged);
    free(left);
    free(right);
}
