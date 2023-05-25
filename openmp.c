#include <omp.h>
#include<stdio.h>
int main() {

    #pragma omp parallel
    {
            
            int d = omp_get_thread_num();
            printf("hello (%d)", d);
            printf("world (%d)\n", d);
    }        
}