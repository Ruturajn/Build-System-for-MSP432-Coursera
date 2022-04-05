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
 * @file stats.h
 * @brief A header file used in 'stats.c'
 *
 * This is a header file containing the declarations
 * for all the functions used in the implementation file
 * named 'stats.c'.
 *
 * @author Ruturaj A. Nanoti
 * @date 19 September 2021
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */

/**
 * @brief Function to print statistics
 *
 * This function prints the statistics of the numbers
 * in the dataset like the median, mean, maximum and
 * minimum.
 *
 * @param *array The pointer to pass the data in the array
 * @param length The length of the array
 *
 * @return Prints the statistics
 */
void print_statistics(unsigned char *array, unsigned int length);


/**
 * @brief Function to print an array
 *
 * This function prints an array to the screen when,
 * the data and the length of the array are given to it.
 *
 * @param *array The pointer to pass the data in the array
 * @param length The length of the array
 *
 * @return Prints the array passed into the function
 */
 void print_array(unsigned char *array, unsigned int length);


/**
 * @brief Function to find the median
 *
 * This function computes the median of a given set
 * of numbers, by taking in the length and data of
 * the array.
 *
 * @param *array The pointer to pass the data in the array
 * @param length The length of the array
 *
 * @return returns the value of the median
 */
unsigned char find_median(unsigned char *array, unsigned int length);


/**
 * @brief Function to find the mean
 *
 * This function computes the mean of a set of
 * numbers by taking in the data and length of the
 * array consisting of the numbers.
 *
 * @param *array The pointer to pass the data in the array
 * @param length The length of the array
 *
 * @return returns the value of the mean
 */
 unsigned char find_mean(unsigned char *array, unsigned int length);



 /**
 * @brief Function to find the maximum value
 *
 * This function finds the maximum value present
 * in a set of data, by taking in the data and the
 * length of the array consisting of the data.
 *
 * @param *array The pointer to pass the data in the array
 * @param length The length of the array
 *
 * @return returns the maximum value
 */
 unsigned char find_maximum(unsigned char *array, unsigned int length);


 /**
 * @brief Function to find minimum value
 *
 * This function finds the minimum value present
 * in a set of data, by taking in the data and the
 * length of the array consisting of the data.
 *
 * @param *array The pointer to pass the data in the array
 * @param length The length of the array
 *
 * @return returns the minumum value
 */
unsigned char find_minimum(unsigned char *array, unsigned int length);


/**
 * @brief Function to sort an array
 *
 * This function sorts an array in descending order,
 * that is, from largest to lowest, by taking in
 * the data and the length of the array to be sorted.
 *
 * @param *array The pointer to pass the data in the array
 * @param length The length of the array
 *
 * @return returns the sorted array
 */
unsigned char * sort_array(unsigned char *array, unsigned int length);

#endif /* __STATS_H__ */
