#include <omp.h>
#include <time.h>
#include <stdio.h>
static long num_steps=100000; double step;
#define NUM_THREADS 10

int main(){
double start_time = omp_get_wtime();
time_t seconds;
seconds=time(NULL)/3600;
int nthreads;
double pi; step=1.0/(double)num_steps;
omp_set_num_threads(NUM_THREADS);
#pragma omp parallel
{
int i,id,nthrds;double x,sum;
id=omp_get_thread_num();
nthrds=omp_get_num_threads();
if(id==0) nthreads=nthrds;
id=omp_get_thread_num();
nthrds=omp_get_num_threads();
for(i=id, sum=0.0;i<num_steps;i=i+nthreads){
x=(i+0.5)*step;
sum+= 4.0/(1.0+x*x);
}
#pragma omp critical
pi+=sum*step;

}
double run_time = omp_get_wtime() - start_time;
printf("pi %f in %.6f seconds\n",pi, run_time);




}