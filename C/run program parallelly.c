#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define nothreads 5

void *myFun(void *x)
{
  int tid;
  tid = *((int *) x);
  printf("Cube of number %d is %lld\n",tid ,tid*tid*tid);
  return NULL;
}

int main()
{
  pthread_t threads[nothreads];
  int thread_args[nothreads];
  int rc, i;

    //enter values for cube
    printf("enter %d numbers\n",nothreads);
  for (i=0; i<nothreads; ++i)
  {
      scanf("%d",&thread_args[i]);
  }
    
  //create threads
  for (i=0; i<nothreads; ++i)
    {
      rc = pthread_create(&threads[i], NULL, myFun, (void *) &thread_args[i]);
    }

  //wait for thread for result
  for (i=0; i<nothreads; ++i) {
    rc = pthread_join(threads[i], NULL);
  }

  return 1;
}
