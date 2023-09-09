#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// deliveries_len�� �迭 deliveries�� �����Դϴ�.
// pickups_len�� �迭 pickups�� �����Դϴ�.
long long solution(int cap, int n, int deliveries[], size_t deliveries_len, int pickups[], size_t pickups_len) {
    long long answer = 0;
    int del=0,pick=0,loc=deliveries_len-1;
    
	while(loc>=0){
    	if(deliveries[loc]==0 && pickups[loc]==0){
    		loc--;///////////��  
    		continue;
		}
		
		while(!(del>=deliveries[loc] && pick>=pickups[loc])){//fillin&dropin for loc ..//makes lowerBound 0
			del+=cap;
			pick+=cap;
			answer+=2*(loc+1);
		}
    	del-=deliveries[loc];//>=0
    	pick-=pickups[loc];//>=0
    	loc--;
	}
 
    return answer;
}
