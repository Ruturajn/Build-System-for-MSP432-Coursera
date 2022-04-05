/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material.
 *
 *****************************************************************************/
/**
 * @file stats.c
 * @brief Implementation file
 *
 * This is the implementation file for 'stats.h', and
 * thereby computes and prints the statistics like mean,
 * median, maximum, and minimum for an array of numbers.
 *
 * @author Ruturaj A. Nanoti
 * @date 19 September 2021
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};


  /* Other Variable Declarations Go Here */

  unsigned char *array;

  /* Statistics and Printing Functions Go Here */

  array = &test[0];
  unsigned char *r = sort_array(array,SIZE);
  print_statistics(r,SIZE);

}

/* Add other Implementation File Code Here */
void print_statistics(unsigned char *array, unsigned int length){

  unsigned char mean,median,max,min;

  mean = find_mean(array,SIZE);
  median = find_median(array,SIZE);
  max = find_maximum(array,SIZE);
  min = find_minimum(array,SIZE);

  print_array(array,SIZE);
  printf("\nThe Statistics for the dataset are as follows:\n");
  printf("\nThe Median for the dataset is       : %d\n",median);
  printf("The Mean for the dataset is         : %d\n",mean);
  printf("The Maximum value in the dataset is : %d\n", max);
  printf("The Minimum value in the dataset is : %d\n", min);
};

void print_array(unsigned char *array, unsigned int length){
  printf("The following is the Sorted Array:\n\n");
  for(int i=0;i<length;i++){
    printf("The element at position %d is : %d\n",i,*(array+i));
  }
};

unsigned char find_median(unsigned char *array, unsigned int length){
  if ( SIZE%2 == 0)
    return *(array+(SIZE/2));
  else
    return *(array+((SIZE+1)/2));
};

unsigned char find_mean(unsigned char *array, unsigned int length){
  int res=0;

  for (int i=0; i<length; i++){
    res = res+(*(array+i));
  }
  res = res/length;
  res = (unsigned char)res;
  return res;
};

unsigned char find_maximum(unsigned char *array, unsigned int length){
  return *(array+0);
};

unsigned char find_minimum(unsigned char *array, unsigned int length){
  return *(array+SIZE-1);
};

unsigned char * sort_array(unsigned char *array, unsigned int length){

  static unsigned char res[SIZE];
  unsigned char a;

  for (int i=0; i<length; i++){
    for (int j=i+1;j<length;j++){
      if ( *(array+i) < *(array+j) ){
        a = *(array+i);
        *(array+i) = *(array+j);
        *(array+j) = a;
      }
    }
  }
  return array;
};
