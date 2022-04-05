/******************************************************************************
 * Copyright (C) 2021 by Ruturaj A. Nanoti
 *
 *****************************************************************************/
/**
 * @file stats.h
 * @brief A header file used in 'data.c'
 *
 * This is a header file containing the declarations
 * for all the functions used in the implementation file
 * named 'data.c'.
 *
 * @author Ruturaj A. Nanoti
 * @date 26 September 2021
 *
 */
#ifndef __DATA_H__
#define __DATA_H__

/**
 * @brief Function to convert a signed integer to its
 * ASCII value
 *
 * This function takes a signed integer and converts it
 * into its ASCII value in a string format, and returns
 * the length of that string, and also puts that string
 * into the pointer passed as a parameter to the function.
 *
 * @param data The 32-bit signed integer to be converted
 * @param ptr  The pointer which will store the converted
 *             ASCII value in a string format
 * @param base The base value for the converted ASCII (2 to 16)
 *
 * @return length of the converted ASCII string
 */
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);


/**
 * @brief Function to convert a ASCII value to its
 * corresponding integer value
 *
 * This function takes an ASCII value string and converts it
 * into its integer format, and returns the 32-bit signed
 * integer representing that ASCII string. The ASCII string
 * is passed into the function with a pointer.
 *
 * @param digits The number of digits in the character set
 * @param ptr  The pointer which will pass the ASCII string
 * @param base The base value for the coonverted integer (2 to 16)
 *
 * @return the converted 32-bit integer
 */
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);

#endif /* __DATA_H__ */
