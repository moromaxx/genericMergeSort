//
//  MergeSort.h
//  Matala 7
//
//  Created by Maks Moroshek on 1/10/20.
//  Copyright © 2020 Maks Moroshek. All rights reserved.
//

#ifndef MergeSort_h
#define MergeSort_h

#include <stdio.h>
#include <stdlib.h>

void mergeSort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*));

#endif /* MergeSort_h */
