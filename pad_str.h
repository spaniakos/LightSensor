/*
 Copyright (C) 2014 G. Spanos <spaniakos@gmail.com

 This program is free software; you can redistribute it and/or
 modify it under the terms of the GNU General Public License
 version 2 as published by the Free Software Foundation.
 */

#ifndef __PAD_STR__
#define __PAD_STR__
 
#include <stdint.h>
#include <stdio.h>
#include <string.h>
  
void Pad_Str(String* my_str,int size){
  unsigned int i;
  for (i=my_str->length();i<=size;i++){
    my_str->concat(" ");
  }
}
#endif
