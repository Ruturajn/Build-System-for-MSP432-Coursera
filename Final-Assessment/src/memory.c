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
 * @file memory.c
 * @brief Abstraction of memory read and write operations
 *
 * This implementation file provides an abstraction of reading and
 * writing to memory via function calls. There is also a globally
 * allocated buffer array used for manipulation.
 *
 * @author Ruturaj A. Nanoti
 * @date 28 September, 2021
 *
 */
#include "memory.h"
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stddef.h>

/***********************************************************
 Function Definitions
***********************************************************/

uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length){
  if (dst <= src){
    for (size_t i=0;i<length;i++){
      *(dst+i) = *(src+i);
    }
  }
  else{
    for (size_t i=length;i>0;i--){
      *(dst+i-1) = *(src+i-1);
    }
  }
  return dst;
}

uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length){
  for (size_t i=0;i<length;i++){
    *(dst+i) = *(src+i);
  }
  return dst;
}

uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value){
  for (size_t i=0;i<length;i++){
    *(src+i) = value;
  }
  return src;
}

uint8_t * my_memzero(uint8_t * src, size_t length){
  for (size_t i=0;i<length;i++){
    *(src+i) = 0;
  }
  return src;
}

uint8_t * my_reverse(uint8_t * src, size_t length){
  uint8_t s;
  for (size_t j=0;j<(length/2);j++){
    s = *(src+length-j-1);
    *(src+length-j-1) = *(src+j);
    *(src+j) = s;
  }
  return src;
}

int32_t * reserve_words(size_t length){
  int32_t * ptr;
  ptr = (int32_t *)malloc(4*length);
  if (ptr == NULL){
    return NULL;
  }
  else{
    return ptr;
  }
}

void free_words(uint32_t * src){
  free((uint32_t *) src);
}
/******************************************************************************/

void set_value(char * ptr, unsigned int index, char value){
  ptr[index] = value;
}

void clear_value(char * ptr, unsigned int index){
  set_value(ptr, index, 0);
}

char get_value(char * ptr, unsigned int index){
  return ptr[index];
}

void set_all(char * ptr, char value, unsigned int size){
  unsigned int i;
  for(i = 0; i < size; i++) {
    set_value(ptr, i, value);
  }
}

void clear_all(char * ptr, unsigned int size){
  set_all(ptr, 0, size);
}

/******************************************************************************/