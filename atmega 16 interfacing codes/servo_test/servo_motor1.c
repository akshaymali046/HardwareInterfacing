#include <avr/io.h>
#include <util/delay.h>
#include "servo_motor1.h"
#include "main.h"

void increase_speed_pwm1(int increment)
{
  if ( Motor_PWM1 + increment <= upper_bound)
    Motor_PWM1 = Motor_PWM1 + increment;
  else
    Motor_PWM1 = upper_bound;
}

void decrease_speed_pwm1(int decrement)
{
  if (Motor_PWM1 - decrement >= lower_bound)
    Motor_PWM1 = Motor_PWM1 - decrement;
  else
    Motor_PWM1 = lower_bound;  
}

void change_speed_pwm1(int speed)
{
  Motor_PWM1 = speed;
}

//void 

void init_hardware_pwm1(void)
{
  TCCR1A |= (BIT7|BIT5|BIT1);      // configuration for timer on compare mode for pwm configuration
  TCCR1B |= (BIT4|BIT3|BIT1|BIT0);
  
  
  
  ICR1=2499;                      // selecting pwm period to 20 ms 
  
  DDRD|=(BIT4|BIT5);              // Pwm out to output PORTD4 and PORTD5
  
}


