#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<getopt.h>


/* Sequentailly computes a fibonacci number */
int fib_seq(int x){
  int i, rint = (rand()%30); double dummy;
  for(i=0; i<rint*100; i++){
    dummy=2.345*i*8.765/1.234;
  }
  if(x==0){
    return (0);
  }
  else if(x==1){
    return (1);
  }
  else{
    return (fib_seq(x-1)+fib_seq(x-2));
  }
}

int main(int argc, char*argv[]){
  int opt;
  int n;
  int m;
  int result;

  /* Parse command line arguments */
  while((opt = getopt(argc, argv, ":F:S:")) != -1){
    switch(opt){
    case 'F':
      n = atoi(optarg);
      //printf("Got F and my argument is %d\n", n);
      break;
    case 'S':
      m = atoi(optarg);
      //printf("Got S and my argument is %d\n", m);
      break;
    }
  }

  /* Case 2*/
  if((n-1)<=m || (n-2)<= m){
    if(n<1){
      result = 0;
    }
    else result = 1;

    for(int i=1; i<n-1; i++){
      result = result + fib_seq(i);
    }
    printf("%d\n",result);
  }

  /* Case 1*/
  else{
    int i=0, j=0;
    int sum=1;
    int num;
    pid_t pid;

    /*Recursively call fork to have children calculate next number in sequence*/
    for(int x=0; x<n-1; x++){
      printf("Start of fork\n");
      pid=fork();
      if(pid==0){
	i=j;
	j=sum;
	sum=i+j;
	//printf("Im a child an i computed %d\n",sum);
      }
      else{
	wait();
	exit(0);
	//printf("parent is waiting on child\n");
      }
    }
    printf("%d\n", sum);
  }
  return 0;
}
