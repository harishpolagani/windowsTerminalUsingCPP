#ifndef _DECLARATIONS_FILE
 #define _DECLARATIONS_FILE


//define boolean 
#ifndef _BOOLEAN_DEFINED
typedef unsigned char boolean;
#define _BOOLEAN_DEFINED
#endif

//defining TRUE or FALSE
#ifndef _TRUE
#define TRUE 1
#endif

#ifndef _FALSE
#define FALSE 0
#endif





typedef enum wrdcnt_e{

WORD_COUNT_NONE  = -1,
WORD_COUNT_ZERO  = 0,
WORD_COUNT_ONE   = 1,
WORD_COUNT_TWO   = 2,
WORD_COUNT_THREE = 3,
WORD_COUNT_FOUR  = 4,

WORD_COUNT_MAX


} wrdcnt_e_type;



//end of header file
#endif
