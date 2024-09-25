#ifndef INTTYPES_H
#define INTTYPES_H

typedef signed char int8_t;
typedef unsigned char uint8_t;
typedef signed short int16_t;
typedef unsigned short uint16_t;
typedef signed int int32_t;
typedef unsigned uint32_t;
typedef signed long long int64_t;
typedef unsigned long long uint64_t;

#define PRIu8 "uhh"
#define PRIu16 "uh"
#define PRIu32 "u"
#define PRIu64 "ull"

#define PRId8 "dhh"
#define PRId16 "dh"
#define PRId32 "d"
#define PRId64 "dll"

#define PRIi8 "ihh"
#define PRIi16 "ih"
#define PRIi32 "i"
#define PRIi64 "ill"

#define PRIx8 "xhh"
#define PRIx16 "xh"
#define PRIx32 "x"
#define PRIx64 "xll"

#endif

