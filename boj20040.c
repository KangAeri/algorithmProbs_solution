#include <stdio.h>
#include <stdlib.h>
int par[500001];

int main() {
    int n=0, m=0, t=0, cycle=0, p1=0,p2=0;
	int a=0,b=0,i=0,j=0;
    
    scanf("%d %d", &n, &m);
    //par = (int*)malloc(sizeof(int)*(n));
    for(i=0;i<n;i++){
        par[i] =i;
    }
    
	for(i=1;i<=m;i++){
		scanf("%d %d",&a, &b);
		if(par[a]==par[b]){
			cycle = i;
			break;
		}
		while(par[a]!=a){
			a = par[a];
		}
		while(par[b]!=b){
			b = par[b];
		}
		if(b==a){
			cycle = i;
			break;
		}
		if(b>a){
            par[b] =a;
        } else{
            par[a] =b;
        }	
	}

    printf("%d\n", cycle);
    
  
    return 0;
}
