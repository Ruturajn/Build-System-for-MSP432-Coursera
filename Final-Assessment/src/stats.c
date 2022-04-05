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
 * @date 28 September 2021
 *
 */



#include <stdio.h>
#include "stats.h"
#include "platform.h"
/* Size of the Data Set */
#define SIZE (40)


//The print_array function is modified to print only if the
//VERBOSE flag is mentioned
void print_array(unsigned char *array, unsigned int length){
  #ifdef VERBOSE
  PRINTF("Printing Array : \n");
  for(int i=0;i<length;i++){
    PRINTF("The element at position %d is : %d\n",i,*(array+i));
  }
  #endif
};

// The following functions are commented out since
// they are not required, for this implementation.
/*
void print_statistics(unsigned char *array, unsigned int length){

  unsigned char mean,median,max,min;

  mean = find_mean(array,SIZE);
  median = find_median(array,SIZE);
  max = find_maximum(array,SIZE);
  min = find_minimum(array,SIZE);

  print_array(array,SIZE);
  PRINTF("\nThe Statistics for the dataset are as follows:\n");
  PRINTF("\nThe Median for the dataset is       : %d\n",median);
  PRINTF("The Mean for the dataset is         : %d\n",mean);
  PRINTF("The Maximum value in the dataset is : %d\n", max);
  PRINTF("The Minimum value in the dataset is : %d\n", min);
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
*/