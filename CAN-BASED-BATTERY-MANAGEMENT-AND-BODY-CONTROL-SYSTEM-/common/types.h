#ifndef TYPES_H
#define TYPES_H

#include <LPC21xx.H>

typedef unsigned char  u8;
typedef signed char    s8;
typedef unsigned int   u32;
typedef signed int     s32;
typedef unsigned short u16;
typedef signed short   s16;

typedef struct CAN2
{
    u32 id;
    u32 rtr;
    u32 dlc;
    u32 byteA;
    u32 byteB;
} CAN2_MSG;

#endif
