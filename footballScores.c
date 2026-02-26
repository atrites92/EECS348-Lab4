// @author Aaron Trites
#include<stdio.h>

int main(){
    //Variable Declaration
    int score = 0;

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
        for (int TD2 = 0; TD2 <= score/8; TD2++){
            int temp1 = score - 8*TD2;
            for (int TD1 = 0; TD1 <= score/7; TD1++){
                int temp2 = temp1 - 7*TD1;
                for (int TD = 0; TD <= score/6; TD++){
                    int temp3 = temp2 - 6*TD;
                    for (int FG = 0; FG <= score/3; FG++){
                        int temp4 = temp3 - 3*FG;
                        if (temp4 % 2 == 0){
                            int SFT = temp4 / 2;
                            printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", TD2, TD1, TD, FG, SFT);
                        }
                    }
                }
            }
        }
	}
    return 0;
}