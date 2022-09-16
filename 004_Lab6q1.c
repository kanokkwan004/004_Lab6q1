#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>

int csum ;
int upper ;
void *runner(void *param) ;

int main(int argc , char *argv[]) {

	pthread_t tid; 
	pthread_attr_t attr;
	pthread_attr_init(&attr);

	pthread_create(&tid , &attr , runner , argv[1]);
	int msum ;
	
	pthread_join(tid , NULL) ;
	if(upper>0) {
		for(int i=0 ; i<=upper ; i++) {
			msum += i ;
		}
	}
	printf("msum = %d\n",msum) ;
	printf("csum - msum = %d\n",csum-msum) ;
	return 0 ;
}

void *runner (void *param) {

	upper = atoi(param) ;
	int i ;
	csum = 0 ;

	if(upper > 0 ) {
		for(i=0 ; i<=upper*2 ; i++)
			csum += i ;
	}
	printf("csum = %d\n",csum) ;
	pthread_exit(0) ;
}

// ข้อ 2.5 เกิดได้ 2 แบบ คือ 1. sumของแม่ออกก่อน sum ของลูก 2.sumของลูกออกก่อน sum ของแม่
