# genericMergeSort
It's my fully generic merge sort function wrote on C as part of my studying of C language and procedure programming.

This function represents generic implementation of well-known sorting algorithm - merge sort. It gets 4 parameters:
1 - pointer to memory location where the array starts (*base);
2 - number of items in the array (nitems);
3 - size of each item, number of bits that each item takes (size);
4 - pointer to function of comparing two elements of the array (*compar);

This is in-place sorting, i.e. it sorts the array that it gets and don't return the array's sorted copy. This generic sort is useful when you need to sort array of elements of any type by different characteristics. For example, it can sort the array of struct "Human" by human's id, age, name or any other characteristic that the struct "Human" contains, you just need to write the comparing function.
