// @author Aaron Trites
#include<stdio.h>
int main(){
    //Variable declaration
    float user_temperature;
    int user_type;
    int user_conversion;

    //Get user input
    printf("Enter temperature: ");
    scanf("%d", user_temperature);
    printf("\nTemperature types: ");
    printf("\nFahrnheit (1)");
    printf("\nCelsius (2)");
    printf("\nKelvin (3)");
    printf("\nEnter type (1, 2, 3): ");
    scanf("%d", user_type);
    printf("\nEner type to conver to (1, 2, 3): ");
    scanf("%d", user_conversion);

  return 0;
}
