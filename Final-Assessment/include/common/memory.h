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
 * @file memory.h
 * @brief Abstraction of memory read and write operations
 *
 * This header file provides an abstraction of reading and
 * writing to memory via function calls.
 *
 * @author Ruturaj A. Nanoti
 * @date 28 September, 2021
 *
 */
#ifndef __MEMORY_H__
#define __MEMORY_H__
#include <stddef.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
/**
 * @brief Moves a byte length from source to destination
 *
 * This function moves a fixed byte length from a source
 * to the destination by taking in the pointer pointing to
 * the source, destination and the length of bytes to
 * be transferred.
 *
 * @param src Pointer to source
 * @param dst Pointer to destination
 * @param length The byte length to be moved
 *
 * @return pointer to the destination
 */
uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length);

/**
 * @brief Copies a byte length from source to destination
 *
 * This function copies a fixed byte length from a source
 * to the destination by taking in the pointer pointing to
 * the source, destination and the length of bytes to
 * be transferred.
 *
 * @param src Pointer to source
 * @param dst Pointer to destination
 * @param length The byte length to be copied
 *
 * @return pointer to the destination
 */
uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length);

/**
 * @brief Sets all locations of a source memory to a given value
 *
 * This function sets all locations of source memory to a given
 * value upto a fixed length of bytes, by taking in the source
 * poiner the length of bytes and the value to be set at the
 * memory locations.
 *
 * @param src Pointer to source
 * @param length The byte length
 * @param value The value to be set
 *
 * @return pointer to the source
 */
uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value);

/**
 * @brief Sets all locations of a source memory to zero
 *
 * This function sets all locations of source memory to zero
 * upto a fixed length of bytes, by taking in the source
 * pointer and the length of bytes.
 *
 * @param src Pointer to source
 * @param length The byte length
 *
 * @return pointer to the source
 */
uint8_t * my_memzero(uint8_t * src, size_t length);

/**
 * @brief Reverses the order of bytes at the source location
 *
 * This functions reverses the order of bytes at a source
 * location upto a fixed length of bytes, by taking in the
 * source pointer and the length of bytes.
 *
 * @param src Pointer to source
 * @param length The byte length
 *
 * @return pointer to the source
 */
uint8_t * my_reverse(uint8_t * src, size_t length);

/**
 * @brief Allocates dynamic memory to a fixed number of words
 *
 * This functions allocates a fixed number of words at a
 * location, by taking in the number of words to be
 * allocated.
 *
 * @param length length of words to be allocated
 *
 * @return pointer to memory
 */
int32_t * reserve_words(size_t length);

/**
 * @brief This function frees the dynamic memor allocated
 *
 * This functions frees the dynamically allocated memory,
 * by taking in the pointer to the source location that
 * needs to be freeed.
 *
 * @param src poiner to the source
 *
 * @return void
 */
void free_words(uint32_t * src);

/**
 * @brief Sets a value of a data array
 *
 * Given a pointer to a char data set, this will set a provided
 * index into that data set to the value provided.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 * @param value value to write the the locaiton
 *
 * @return void.
 */
void set_value(char * ptr, unsigned int index, char value);

/**
 * @brief Clear a value of a data array
 *
 * Given a pointer to a char data set, this will clear a provided
 * index into that data set to the value zero.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return void.
 */
void clear_value(char * ptr, unsigned int index);

/**
 * @brief Returns a value of a data array
 *
 * Given a pointer to a char data set, this will read the provided
 * index into that data set and return the value.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return Value to be read.
 */
char get_value(char * ptr, unsigned int index);

/**
 * @brief Sets data array elements to a value
 *
 * Given a pointer to a char data set, this will set a number of elements
 * from a provided data array to the given value. The length is determined
 * by the provided size parameter.
 *
 * @param ptr Pointer to data array
 * @param value value to write the the locaiton
 * @param size Number of elements to set to value
 *
 * @return void.
 */
void set_all(char * ptr, char value, unsigned int size);

/**
 * @brief Clears elements in a data array
 *
 * Given a pointer to a char data set, this will set a clear a number
 * of elements given the size provided. Clear means to set to zero.
 *
 * @param ptr Pointer to data array
 * @param size Number of elements to set to zero
 *
 * @return void.
 */
void clear_all(char * ptr, unsigned int size);

#endif /* __MEMORY_H__ */
