#include <stdio.h>
#include <string.h>
int cube[6][3][3];

void rotate(int tar,int dir){
	int tmp[3][3];
	int k=0,l=0;
	for(k=0;k<3;k++){
		for(l=0;l<3;l++){
			tmp[k][l]=cube[tar][k][l];
		}
	}
	//
	if(dir==1){//clock-wise
		for(k=0;k<3;k++){
			for(l=0;l<3;l++){
				cube[tar][l][2-k]=tmp[k][l];
			}
		}
	}else{
		for(k=0;k<3;k++){
			for(l=0;l<3;l++){
				cube[tar][2-l][k]=tmp[k][l];
			}
		}
	}

	
}//end func

int main(){
	int T,num=0;
	int i=0,j=0, n=0,m=0;
	int buf=0;
	char tri,cmd,dir;
	char color[6]= {'w','y','r','o','g','b'};
	//	
	//T = getchar();
	//T-=48;
	scanf("%d", &T);
	for (i= 0; i < T; i++){
		for(j=0;j<6;j++){
			for(m=0;m<3;m++){
				for(n=0;n<3;n++){
					cube[j][m][n] = j;
				}
			}
		}
		
		scanf("%d", &num);
		//getchar();
		while (num>0){
			//cmd=getchar();
			//dir=getchar();
			scanf(" %c%c", &cmd,&dir);
			//getchar();
			//printf("cmd=%c /dir=%c / num %d /%d \n", cmd,dir,T,num); 
			switch(cmd){
				case 'U':
					if(dir=='+'){
						rotate(0,1);//
						for(j=0;j<3;j++){
							buf=cube[2][0][j];
							cube[2][0][j]=cube[5][0][j];
							cube[5][0][j]=cube[3][0][j];
							cube[3][0][j]=cube[4][0][j];
							cube[4][0][j]=buf;
						}	
					}else{//
						rotate(0,0);
						for(j=0;j<3;j++){
							buf=cube[2][0][j];
							cube[2][0][j]=cube[4][0][j];
							cube[4][0][j]=cube[3][0][j];
							cube[3][0][j]=cube[5][0][j];
							cube[5][0][j]=buf;
						}
					}
					break;
				case 'D':
					if(dir=='+'){//
						rotate(1,1);
						for(j=0;j<3;j++){
							buf=cube[2][2][j];
							cube[2][2][j]=cube[4][2][j];
							cube[4][2][j]=cube[3][2][j];
							cube[3][2][j]=cube[5][2][j];
							cube[5][2][j]=buf;
						}
					}else{
						rotate(1,0);//
						for(j=0;j<3;j++){
							buf=cube[2][2][j];
							cube[2][2][j]=cube[5][2][j];
							cube[5][2][j]=cube[3][2][j];
							cube[3][2][j]=cube[4][2][j];
							cube[4][2][j]=buf;
						}
					}
					break;
				case 'F':
					if(dir=='+'){
						rotate(2,1);
						for(j=0;j<3;j++){
							buf=cube[0][2][2-j];
							cube[0][2][2-j]=cube[4][j][2];
							cube[4][j][2]=cube[1][2][2-j];
							cube[1][2][2-j]=cube[5][2-j][0];
							cube[5][2-j][0]=buf;
						}
					}else{
						rotate(2,0);
						for(j=0;j<3;j++){
							buf=cube[5][2-j][0];
							cube[5][2-j][0]=cube[1][2][2-j];
							cube[1][2][2-j]=cube[4][j][2];
							cube[4][j][2]=cube[0][2][2-j];
							cube[0][2][2-j]=buf;
						}
					}
					break;
				case 'B':
					if(dir=='+'){
						rotate(3,1);		
						for(j=0;j<3;j++){
							buf=cube[0][0][j];
							cube[0][0][j]=cube[5][j][2];
							cube[5][j][2]=cube[1][0][j];
							cube[1][0][j]=cube[4][2-j][0];
							cube[4][2-j][0]=buf;
						}
					}else{
						rotate(3,0);
						for(j=0;j<3;j++){
							buf=cube[4][2-j][0];
							cube[4][2-j][0]=cube[1][0][j];
							cube[1][0][j]=cube[5][j][2];
							cube[5][j][2]=cube[0][0][j];
							cube[0][0][j]=buf;
						}
					}
					break;
				case 'L':
					if(dir=='+'){//
						rotate(4,1);
						for(j=0;j<3;j++){
							buf=cube[0][j][0];
							cube[0][j][0]=cube[3][2-j][2];
							cube[3][2-j][2]=cube[1][2-j][2];
							cube[1][2-j][2]=cube[2][j][0];
							cube[2][j][0]=buf;
						}
					}else{
						rotate(4,0);
						for(j=0;j<3;j++){
							buf=cube[2][j][0];
							cube[2][j][0]=cube[1][2-j][2];
							cube[1][2-j][2]=cube[3][2-j][2];
							cube[3][2-j][2]=cube[0][j][0];
							cube[0][j][0]=buf;
						}
					}
					break;
				case 'R':
					if(dir=='+'){
						rotate(5,1);
						for(j=0;j<3;j++){
							buf=cube[0][j][2];
							cube[0][j][2]=cube[2][j][2];
							cube[2][j][2]=cube[1][2-j][0];
							cube[1][2-j][0]=cube[3][2-j][0];
							cube[3][2-j][0]=buf;
						}
					}else{
						rotate(5,0);//
						for(j=0;j<3;j++){
							buf=cube[3][2-j][0];
							cube[3][2-j][0]=cube[1][2-j][0];
							cube[1][2-j][0]=cube[2][j][2];
							cube[2][j][2]=cube[0][j][2];
							cube[0][j][2]=buf;
						}
					}
					break;
			}//endswitch
			num--;
			
				
			///
		}//endwhile	
		for(m=0;m<3;m++){
				for(n=0;n<3;n++){
					printf("%c",color[(cube[0][m][n])]);
				}
				printf("\n");
		}
	}//endfor
	
	return 0;
}//endmain
