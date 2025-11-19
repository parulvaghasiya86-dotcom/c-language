#include<stdio.h>

int main()
{
	int w , x , y , z ;
	printf("W:");
	scanf("%d" , &w);
	printf("X:");
	scanf("%d" , &x);
	printf("Y:");
	scanf("%d" , &y);
	printf("Z:");
	scanf("%d" , &z);
	if(w>x){
		if(w>y){
			if(w>z){
				printf("W is the largest.");
			}else{
				printf("Z is the largest");
			}
		}else{
			if(x>y){
				if(x>z){
					printf("X is the largest");
				}else{
					printf("Z is the largest");
				}
			}else{
				if(y>z){
					printf("Y is the largest");
				}else{
					printf("Z is the largest");
				}
			}
		}
		}
	}





