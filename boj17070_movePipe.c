#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int que[32000000];
int state[32000000]; //1:h 2:v 3:diago

bool moveR(int **arr, int n, int s){
	if(s%n+1<n && arr[s/n][s%n+1]==0){
		return true;
	} else{
		return false;
	}
	
}
bool moveD(int **arr, int n, int s){
	if(s/n+1<n && arr[s/n+1][s%n]==0){
		return true;
	} else{
		return false;
	}
}
bool moveRD(int **arr, int n, int s){
	if(s%n+1<n && s/n+1<n && arr[s/n][s%n+1]==0 && arr[s/n+1][s%n]==0 && arr[s/n+1][s%n+1]==0){
		return true;
	} else{
		return false;
	}
}
int main(){
	
	int n=0,i=0,j=0,ans=0;
	int front=0,rear=1,curr=1,curS=0;
	int **home; //for array
	
	scanf("%d", &n);
	
	//que = (int *)malloc(sizeof(int)*max); //arr init
	//state = (int *)malloc(sizeof(int)*max);
	que[0]=1;
	state[0]=1;
	
	home = (int **)malloc(sizeof(int*)*n);	//mem alloc
	for(i=0;i<n;i++){
		home[i] = (int *)malloc(sizeof(int)*n); //arr init
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d", &home[i][j]); //arr init
		}
	}
	///////
	while (front < rear){
		curr = que[front];
		curS= state[front++];
		if(curr==n*n-1){
			ans++;
			continue;
		}
		
		switch (curS){
			case 1: 
				if(moveR(home, n, curr)){
					que[rear]=curr+1;
					state[rear++] = 1;		
				}
				if(moveRD(home, n, curr)){
					que[rear]=curr+n+1;
					state[rear++] = 3;			
				}
				break;
				
			case 2:
				if(moveD(home, n, curr)){
					que[rear]=curr+n;
					state[rear++] = 2;
				}
				if(moveRD(home, n, curr)){
					que[rear]=curr+n+1;
					state[rear++] = 3;			
				}
				break;
			case 3:
				if(moveR(home, n, curr)){
					que[rear]=curr+1;
					state[rear++] = 1;		
				}
				if(moveD(home, n, curr)){
					que[rear]=curr+n;
					state[rear++] = 2;
				}
				if(moveRD(home, n, curr)){
					que[rear]=curr+n+1;
					state[rear++] = 3;			
				}
				break;		
		}
	
	}
	//////
	printf("%d",ans);
	//
	for(i=0;i<n;i++){
		free(home[i]);
	}
	free(home); //mem freeeeeeee
	//free(que);
	//free(state); 
    
	return 0;
}
