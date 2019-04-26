#include <stdint.h>
#include "stdio.h"
// headers

int main(void);

int32_t foo_0sfn(const char* msg);

void bar_01sfn(void);

// source
#ifndef SEA_HEADER

void bar_01sfn(void){
}

int32_t foo_0sfn(const char* msg){

printf("%s\n", msg);
return 0;
}

int main(void){

bar();
return foo_0sfn("Hello World");;
}


#undef SEA_HEADER
#endif // SEA_HEADER
