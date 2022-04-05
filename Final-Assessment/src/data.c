/******************************************************************************
* Copyright (C) 2021 by Ruturaj A. Nanoti
*
*******************************************************************************/

/******************************************************************************
* @file data.c
* @brief Implementation file for basic data manipulation
*
* This file contains the basic data manipulations that are
* required for the final assesment of the "Introduction to
* Embedded Systems Software and Development Environments".
* It contains the definitions for the functions defined in
* the 'data.h' header file. These functions convert an
* integer value into it's equivalent ASCII value in a
* string format and vice-versa and returns the lenght
* of that string.
*
* @Author: Ruturaj A. Nanoti
* @Date: 26 September 2021
******************************************************************************/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "data.h"

//------------------------------------------------------------------------------
//Function to convert 32-bit integer to ASCII
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base){
  int32_t t = data;
  uint32_t n = 0;
  uint8_t length = 0, i=0;

  //Checking the base and whether the number is negative
  if ((t < 0) && (base!=10)){
    /*If the base is not 10 and number is negative, we comnvert
    the number to its 2s complement representation*/
    n = 1 + (~(uint32_t)(-t));

    //Processing individual digits and getting their ASCII code
    while(n > 0){
      i = n % base;
      n = n/base;
      if (i>9){
        *(ptr+length) = (i-10) + 'A';
      }
      else{
        *(ptr+length) = i + '0';
      }
      length += 1;
    }
  }
  /*Otherwise if one of the above condition is not satisfied then,
   the 'else' block is entered*/
  else{
    //We check again if the number is negative
    if (t<0){
    t = t*(-1);
    }
    //Then process the individual digits
    while(t > 0){
      i = t % base;
      t = t/base;
      if (i>9){
        *(ptr+length) = (i-10) + 'A';
      }
      else{
        *(ptr+length) = i + '0';
      }
      length += 1;
      }
  }
  if ((data < 0) && (base==10)){
    *(ptr+length) = '-';
    length += 1;
  }

  //Reversing the ASCII string
  char s;
  for (int j=0;j<(length/2);j++){
    s = *(ptr+length-j-1);
    *(ptr+length-j-1) = *(ptr+j);
    *(ptr+j) = s;
  }

  //Adding a null terminator at the end of the string
  *(ptr + length) = '\0';

  return length;
}

//-----------------------------------------------------------------------------
//Function to convert ASCII to 32-bit integer
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base){
  uint8_t length = 0;
  /*First we check if there is a negative sign at the beginning
  of the string and process the string accordingly*/
  if (*(ptr+length) != '-'){
  uint8_t r=0;
  int32_t n = 0;
  //Processing individual digits
  for (int i=0;i<digits;i++){
    if (base==16){
          if ((*(ptr+i)>='0') && (*(ptr+i)<='9')){
            r = *(ptr+i) - '0';
          }
          if ((*(ptr+i)>='A') && (*(ptr+i)<='F')){
            r = *(ptr+i) - 'A' + 10;
          }
    }
    else{
          r = *(ptr+i) - '0';
    }
    int mul=1;
    for (int j=0;j<(digits-i-1);j++){
      mul *= base;
    }
    n += (r*mul);
  }
  return n;
  }
  //For cases where a negative sign exists
  else{
      int32_t n = 0;
      uint8_t r = 0;
      //Processing individual digits
      if ((base==10) && (*(ptr+length)=='-')){
        for (int i=1;i<digits;i++){
          r = *(ptr+i) - '0';
          int mul=1;
          for (int j=0;j<(digits-i-1);j++){
            mul *= base;
          }
          n += (r*mul);
        }
      }
      return n*(-1);
    }
}
