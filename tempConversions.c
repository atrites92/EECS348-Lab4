// @author Aaron Trites
#include<stdio.h>
/* The primary purpose of this program is to convert a user-entered
temperature and let them choose which temperature scale to 
convert the given temperature. It also features a temperature
category function that relays information about how to prepare
for the weather when going outside at the given temperature. */

//Global constants
const float absFarhenheit = -459.67;
const float absCelsius = -273.15;
const int absKelvin = 0;

//Conversion helper functions
//Converts C to F
float celsius_to_fahrenheit(float celsius){
  return (((9/5)*celsius)+32);
}
//Converts F to C
float fahrenheit_to_celsius(float fahrenheit){
  return ((5/9)*(fahrenheit-32));
}
//Converts C to K
float celsius_to_kelvin(float celsius){
  return celsius+273.15;
}
//Converts K to C
float kelvin_to_celsius(float kelvin){
  return kelvin-273.15;
}

//Temperature Cateorgies
void categorize_temperature(float celsius){
  printf(">>>Weather Category:\n");
  if (celsius < 0){
    printf(">>Freezing:\n");
    printf(">Advisory: Wear full winter gear, wear boots\n");
  } else if (celsius <= 10){
    printf(">>Cold:\n");
    printf(">Advisory: Wear warm jacket, bring gloves\n");
  } else if (celsius <= 25){
    printf(">>Comfortable:\n");
    printf(">Advisory: Bring lunch for the park, enjoy the day\n");
  } else if (celsius <= 35){
    printf(">>Hot:\n");
    printf(">Advisory: Drink lots of water, wear sunscreen\n");
  } else {
    printf(">>Extreme Heat:\n");
    printf(">Advisory: Seek shaded areas, avoid activity\n");
  }
}

//Main Program Function
int main(){
    //Variable declaration
    float user_temperature;
    char user_type;
    char user_conversion;
    int quit = 1;

    //Welcome message
    printf("Welcome to my temperature conversion program\n");

    //Main menu loop
     do {
      //Get user input
        //Get temperature
        printf("Enter temperature: ");
        //Defensive check: invalid input error
        while (scanf("%f", &user_temperature) != 1){
          printf("Invalid input. Please enter a numeric temperature: ");
          //Clear input buffer
          while(getchar() != '\n');
        }
        
        //Get scale of given input
        printf("Temperature scales:\n");
        printf("Fahrnheit\n");
        printf("Celsius\n");
        printf("Kelvin\n");
        printf("Enter input scale (F, C, or K): ");
        while (1){ 
          scanf("%c", &user_type);
          //Defenseive check: Input not F, f, C, c, K or k
          if (user_type == 'F' || 
              user_type == 'f' || 
              user_type == 'C' || 
              user_type == 'c' ||
              user_type == 'K' ||
              user_type == 'k' )
              {
                //Defensive check: below absolute zero error
                //Kelvin
                if ((user_type == 'K' || user_type == 'k') && user_temperature < absKelvin){
                  printf("Error: Input below absolute zero.\n");
                }
                //Celsius
                else if ((user_type == 'C' || user_type == 'c') && user_temperature < absCelsius){
                  printf("Error: Input below absolute zero.\n");
                }
                //Fahrenheit
                else if ((user_type == 'F' || user_type == 'f') && user_temperature < absFarhenheit){
                  printf("Error: Input below absolute zero.\n");

                //If input is valid, break loop
                } else break;
              
              //Invalid char
              } else {
                printf("Invalid input. Please enter F, C, or K: ");
              }

          //Clear input buffer
          while(getchar() != '\n');
        }

        //Get target scale
        printf("Enter target scale (F, C, or K):");
        //Defensive check: same scale error
        scanf("%c", &user_conversion);
        if (user_type == user_conversion){
          printf("Error: Can't convert to same scale.\n");
        }

      //Repeat the loop
      printf("Would you like to enter another temperature?\n");
      scanf("Enter 0 to quit or 1 to continue: %d", &quit);
    } while (quit);

  return 0;
}