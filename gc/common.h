#pragma once

#include<stdlib.h>
#include<stdio.h>
//#include<unistd.h>
#include<Windows.h>

typedef void *          pvoid;
typedef unsigned char   byte;
typedef unsigned short  ushort;
typedef unsigned int    uint;
typedef unsigned long   ulong;

typedef union { //ָ��ѹ��
	long    l_dummy; 
	double  d_dummy;
	void *  p_dummy;
}Align;

#define ALIGN_SIZE (sizefo(Align))

typedef enum {
	GC_MARK_CLEAN,
	GC_MARK_COLLECT,
	GC_MARK_COPY,
	GC_G1,
}GC_Type;

#define DEFAULT_GC_TYPE GC_MARK_COPY

/* ======================================
 * �Զ����ӡ���
 * ======================================*/
#define INFO_OUTPUT    3
#define WARNING_OUTPUT 2
#define DEBUG_OUTPUT   1
#define ERROR_OUTPUT   0

#define DEBUG
#define DEBUG_LEVEL INFO_OUTPUT

#define PRINT(info, ...) do{\
if(DEBUG_LEVEL>=INFO_OUTPUT) {\
printf("[ Info] (%s:%d->%s):" info"\n", __FILE__, __LINE__, __FUNCTION__, ##__VA_ARGS__ );\
}\
}while(0)

#define WARNING_PRINT(info, ...) do{ \
if(DEBUG_LEVEL>=WARNING_OUTPUT){ \
printf("[ Warn] (%s:%d->%s):" info"\n", __FILE__, __LINE__, __FUNCTION__, ##__VA_ARGS__); \
} \
}while(0)

#define DEBUG_PRINT(info, ...) do{\
if(DEBUG_LEVEL>=DEBUG_OUTPUT){\
printf("[Debug] (%s:%d->%s):" info"\n",__FILE__,__LINE__,__FUNCTION__, ##__VA_ARGS__);\
}\
}while(0)

#define ERROR_PRINT(info, ...) do{ \
if(DEBUG_LEVEL>=ERROR_OUTPUT){ \
printf("[Error] (%s:%d->%s):" info"\n", __FILE__, __LINE__, __FUNCTION__, ##__VA_ARGS__); \
    } \
}while(0)

#define NULL_POINTER(ptr) do{ \
    if(NULL == ptr){ \
        printf("[Error] (%s:%d->%s):��ָ��\n", __FILE__, __LINE__, __FUNCTION__); \
    } \
}while(0)