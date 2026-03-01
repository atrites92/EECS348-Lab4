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

/* HELPER FUNCTIONS */

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
    printf(">Advisory: Wear full winter gear, avoid activity\n\n");
  } else if (celsius <= 10){
    printf(">>Cold:\n");
    printf(">Advisory: Wear warm jacket, bring gloves\n\n");
  } else if (celsius <= 25){
    printf(">>Comfortable:\n");
    printf(">Advisory: Bring lunch for the park, enjoy the day\n\n");
  } else if (celsius <= 35){
    printf(">>Hot:\n");
    printf(">Advisory: Drink lots of water, wear sunscreen\n\n");
  } else {
    printf(">>Extreme Heat:\n");
    printf(">Advisory: Seek shaded areas, avoid activity\n\n");
  }
}

//Check for valid scale input
//Defenseive check: Valid input (F, C, or K)
int valid_scale(char scale){
          if (scale == 'F' ||
              scale == 'C' || 
              scale == 'K' ){
              return 1;
          } else return 0;
}

/* END HELPER FUNCTIONS */

//Main Program Function
int main(){
    //Variable declaration
    float user_temperature;
    char user_type;
    char user_conversion;
    float converted_temperature;
    int quit = 1;

    //Welcome message
    printf("Welcome to my temperature conversion program\n");
    printf("Note: Temperaute scale input is case-sensitive!\n");

    //Main menu loop
     do {
      /*Getting user input: As a design choice, have the user enter
      the scale of choice first. -- Why?
      If temperature is given first and the value is less than the absolute 
      temperature for Fahrenheit (the lowest numeric value of the three) and 
      then asks for scale, the program will end in an infinite loop since we 
      can backstep. By receiving the input scale first, we can properly check
      for valid inputs above absolute zero.*/
       
        //Get scale of given input
        printf("Temperature scales:\n");
        printf("Fahrnheit\n");
        printf("Celsius\n");
        printf("Kelvin\n");
        printf("Enter input scale (F, C, or K): ");
        while (1){ 
          scanf("%c", &user_type);
          //Defenseive check: Valid input (F, C, or K)
          if (valid_scale(user_type)){
                break;
              //Invalid char
              } else {
                printf("Invalid input. Please enter F, C, or K : ");
              }

          //Clear input buffer
          while(getchar() != '\n');
        }

       //Get temperature
       while (1){
          printf("Enter temperature: ");
          //Defensive check: Invalid input
          while (scanf("%f", &user_temperature) != 1){
            printf("Invalid input. Please enter a numeric temperature: ");
            //Clear input buffer
            while(getchar() != '\n');
          }
  
          //Defensive check: Temperature below absolute zero
          //Kelvin
          if ((user_type == 'K' || user_type == 'k') && user_temperature < absKelvin){
            printf("Error: Input is below absolute zero.\n");
          }
          //Celsius
          else if ((user_type == 'C' || user_type == 'c') && user_temperature < absCelsius){
            printf("Error: Input is below absolute zero.\n");
          }
          //Fahrenheit
          else if ((user_type == 'F' || user_type == 'f') && user_temperature < absFarhenheit){
            printf("Error: Input is below absolute zero.\n");

          //Input given correctly, break loop
          } else break;
        }

        //Get target scale
        printf("Temperature scales:\n");
        printf("Fahrnheit\n");
        printf("Celsius\n");
        printf("Kelvin\n");
        printf("Enter target scale (F, C, or K):");
        while(1){
          scanf("%c", &user_conversion);
          //Defensive check: same scale error
          if (valid_scale(user_conversion) && user_type == user_conversion){
            printf("Error: Can't convert to same scale.\n");
          }
          //Defenseive check: Valid input (F, C, or K)
          if (!valid_scale(user_conversion)){
            printf("Invalid input. Please enter F, C, or K:");
          }
          //Clear input buffer
          while(getchar() != '\n');
        }

      //Conversion branches
      //User entered Fahrenheit
      if (user_type == 'F'){
        if (user_conversion == 'K'){
          converted_temperature = fahrenheit_to_celsius(celsius_to_kelvin(user_temperature));
        } else {
          converted_temperature = fahrenheit_to_celsius(user_temperature);
        }
      }
      //User entered Celsius
      if (user_type == 'C'){
        if (user_conversion == 'K'){
          converted_temperature = celsius_to_kelvin(user_temperature);
        } else {
          converted_temperature = celsius_to_fahrenheit(user_temperature);
        }
      }
      //User entered Kelvin
      if (user_type == 'K'){
        if (user_conversion == 'F'){
          converted_temperature = kelvin_to_celsius(celsius_to_fahrenheit(user_temperature));
        } else {
          converted_temperature = kelvin_to_celsius(user_temperature);
        }
      }

      //Display conversion
      printf("Temperature conversion: %f°%c is %f°%c\n", user_temperature, user_type, user_conversion, converted_temperature);

      //Report category advisory
      if (user_type == 'C'){
        categorize_temperature(user_temperature);
      } else if (user_type == 'F'){
        categorize_temperature(fahrenheit_to_celsius(user_temperature));
      } else {
        categorize_temperature(kelvin_to_celsius(user_temperature));
      }
      
      //Repeat the loop
      printf("Would you like to enter another temperature?\n");
      scanf("Enter 0 to quit or 1 to continue: %d", &quit);
    } while (quit);

  return 0;
}
