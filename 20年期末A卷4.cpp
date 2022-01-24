#include<stdio.h>
#include<stdbool.h>
#include<time.h>
#include<stdlib.h> 
int roll_dice();
bool play_game();
int main()
{
	srand((unsigned)time(NULL));
	int w=0,l=0;
	if(play_game())
	{
		printf("You win!\n");
		w++;
	}
	else{
		printf("You lose!\n");
		l++;
	}
	char option;
	while(1){
		printf("Play again?");
		scanf("%c",&option);
		getchar();
		printf("\n");
		if(option=='y'||option=='Y')
		{
			if(play_game())
			{
				printf("You win!\n");
				w++;
			}
			else{
				printf("You lose!\n");
				l++;
			}
		}	
		else break;
	}
	printf("Wins:%d Losses:%d",w,l);
	return 0;
}
int roll_dice()
{
	int a,b;
	a=1+rand()%6;
	b=1+rand()%6;
	return a+b;
}
bool play_game()
{
	int num=roll_dice();
	int point;
	printf("You rolled:%d\n",num);
	if(num==7||num==11)
		return true;
	else if(num==2||num==3||num==12)
		return false;
	else{
		printf("Your point is %d\n",num);
		while(1){
			point=roll_dice();
			printf("You rolled:%d\n",point);
			if(point==num)
				return true;
			else if(point==7)
				return false;
			else continue;
		}
	}
	
} 
