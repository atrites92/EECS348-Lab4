// @author Aaron Trites
#include<stdio.h>

float celsius_to_fahrenheit(float celsius){
  return (((9/5)*celsius)+32);
}

float fahrenheit_to_celsius(float fahrenheit){
  return ((5/9)*(fahrenheit-32));
}

float celsius_to_kelvin(float celsius){
  return celsius+273.15;
}

float kelvin_to_celsius(float kelvin){
  return kelvin-273.15;
}

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

int main(){
    //Variable declaration
    float user_temperature;
    int user_type;
    int user_conversion;

    //Get user input
    printf("Enter temperature: ");
    scanf("%f", &user_temperature);
    printf("Temperature scale of input:\n");
    printf("(1) Fahrnheit\n");
    printf("(2) Celsius\n");
    printf("(3) Kelvin\n");
    printf("Enter scale (1, 2, 3): ");
    scanf("%d", &user_type);
    printf("Enter scale to convert to (1, 2, 3): ");
    scanf("%d", &user_conversion);

  return 0;
}