// @author Aaron Trites
#include<stdio.h>

int main(){
    //Variable Declaration
    int score = 0;
    int pointWorth[] = {2, 3, 6, 7, 8}; //SFT, FG, TD, TD1, TD2
    int pointCount[] = {0, 0, 0, 0, 0};

    //Main program loop
	while(1){
        //Get user choice (STOP or score to calculate)
		printf("Enter 0 or 1 to STOP\n");
		printf("Enter the NFL score: ");
        scanf("%d", &score);
        //Score of 2 or higher is required
		if (score < 2){
            break;
        }

        printf("Possible combinations of scoring play if a team's score is %d\n", score);
        //Calculate possible point combinations
        //Check for only one type of score the whole game
        if (score % pointWorth[0] == 0){ //ALL SFTs
            pointCount[0] = score / 2;
            printf("%d TD+2pt, %d TD+FG, %d TD, %d 3pt FG, %d Safety\n", pointCount[4], pointCount[3], pointCount[2], pointCount[1], pointCount[0]);
            pointCount[0] = 0;
        }
        if (score % pointWorth[1] == 0){ //ALL FGs
            pointCount[1] = score / 3;
            printf("%d TD+2pt, %d TD+FG, %d TD, %d 3pt FG, %d Safety\n", pointCount[4], pointCount[3], pointCount[2], pointCount[1], pointCount[0]);  
            pointCount[1] = 0;
        }
        if (score % pointWorth[2] == 0){ //ALL TDs
            pointCount[2] = score / 6;
            printf("%d TD+2pt, %d TD+FG, %d TD, %d 3pt FG, %d Safety\n", pointCount[4], pointCount[3], pointCount[2], pointCount[1], pointCount[0]);
            pointCount[2] = 0;
        }
        if (score % pointWorth[3] == 0){ //ALL TD1s
            pointCount[3] = score / 7;
            printf("%d TD+2pt, %d TD+FG, %d TD, %d 3pt FG, %d Safety\n", pointCount[4], pointCount[3], pointCount[2], pointCount[1], pointCount[0]);
            pointCount[3] = 0;
        }
        if (score % pointWorth[4] == 0){ //ALL TD2s
            pointCount[4] = score / 8;
            printf("%d TD+2pt, %d TD+FG, %d TD, %d 3pt FG, %d Safety\n", pointCount[4], pointCount[3], pointCount[2], pointCount[1], pointCount[0]);
            pointCount[4] = 0;
        }
	}
    return 0;
}