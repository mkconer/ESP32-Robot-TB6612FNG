// Simple 2 Wheel robot demonstrating the use of the ESP32 and the TB6612FNG Motor Controller

// This is a modified version of the sparkfun Dual Motor Controller TB6612FNG example sketch
// Which can be found here. https://www.sparkfun.com/products/14450?gclid=Cj0KCQiA6LyfBhC3ARIsAG4gkF8E3EeZWggXUgO7oEWK2d7iwPDjHLctu7CT5xEef9ki6SXmh0vvJ7waAuB7EALw_wcB
// The Library has been modified for the ESP32 by Pablo López
// It can be downloaded from Github https://github.com/pablopeza/TB6612FNG_ESP32
// Download the Zip file and install it in the Arduino IDE by clicking Sketch/ Include Library / Add Zip Library

// #include <Arduino.h>
#include <TB6612_ESP32.h>

// *** Wiring connections from ESP32 to TB6612FNG Motor Controller ***

#define AIN1 13 // ESP32 Pin D13 to TB6612FNG Pin AIN1
#define BIN1 12 // ESP32 Pin D12 to TB6612FNG Pin BIN1
#define AIN2 14 // ESP32 Pin D14 to TB6612FNG Pin AIN2
#define BIN2 27 // ESP32 Pin D27 to TB6612FNG Pin BIN2
#define PWMA 26 // ESP32 Pin D26 to TB6612FNG Pin PWMA
#define PWMB 25 // ESP32 Pin D25 to TB6612FNG Pin PWMB
#define STBY 33 // ESP32 Pin D33 to TB6612FNG Pin STBY

// *** Wiring connections from TB6612FNG Motor Controller to the Motors ***

// Connect the leads from your motors, don't worry if you don't get them correct the first time
// Motor 1 should go to A01 and A02
// Motor 2 should go to B01 and B02
// If the motors are NOT turning in the right direction reverse the pins (for example the A01 and A02) pins
// If the left and right motors are reversed then swap the A01 and A02 wires to the B01 and B02 pins 

// *** Wiring connections from the Battery Pack to the ESP32 and TB6612FNG Motor Controller ***

// A 4 Cell battery pack was used to supply 6 Volts of DC current to the robot and to the ESP32
// A wire splitter was used to connect the Positive (+) side of the Battery pack to the VIN pin of the ESP32,
// and to the VM pin of the TB6612FNG Motor Controller.
// Another wire splitter was used to connect the Negative (-) side of the Battery pack to the GND pin of the ESP32,
// and to the GND pin of the TB6612FNG Motor Controller


// these constants are used to allow you to make your motor configuration
// line up with function names like forward.  Value can be 1 or -1
const int offsetA = 1;
const int offsetB = 1;

Motor motor1 = Motor(AIN1, AIN2, PWMA, offsetA, STBY,5000 ,8,1 );
Motor motor2 = Motor(BIN1, BIN2, PWMB, offsetB, STBY,5000 ,8,2 );

// Initializing motors.  The library will allow you to initialize as many
// motors as you have memory for.  If you are using functions like forward
// that take 2 motors as arguements you can either write new functions or
// call the function more than once.


void setup()
{

}

void loop()
{

     delay(2000); // Short delay to catch your robot
      
     //Use of the drive function which takes as arguements the speed
     //and optional duration.  A negative speed will cause it to go
     //backwards.  Speed can be from -255 to 255.  Also use of the
     //brake function which takes no arguements.
     motor1.drive(255,2000);       // Turn Motor 1 for 2 seconds at full speed
     //motor1.drive(-255,2000);
     motor1.brake();
     delay(2000);

     //Use of the drive function which takes as arguements the speed
     //and optional duration.  A negative speed will cause it to go
     //backwards.  Speed can be from -255 to 255.  Also use of the
     //brake function which takes no arguements.
     motor2.drive(255,2000);        // Turn Motor 2 for 2 seconds at full speed
     //motor2.drive(-255,2000);
     motor2.brake();
     delay(2000);

     //Use of the forward function, which takes as arguements two motors
     //and optionally a speed.  If a negative number is used for speed
     //it will go backwards
     forward(motor1, motor2, 255);        // Forward Motor 1 and Motor 2 for 1 seconds at full speed
     delay(1000);

     // Brake
     brake(motor1, motor2);     // Stop Motor 1 and Motor 2 for 2 seconds 
     delay(2000);       

     //Use of the back function, which takes as arguments two motors
     //and optionally a speed.  Either a positive number or a negative
     //number for speed will cause it to go backwards
     back(motor1, motor2, -255);         // Reverse Motor 1 and Motor 2 for 1 seconds at full speed
     delay(1000);

     // Brake again
     brake(motor1, motor2);       // Stop Motor 1 and Motor 2 for 2 seconds 
     delay(2000);  

     //Use of the left and right functions which take as arguements two
     //motors and a speed.  This function turns both motors to move in
     //the appropriate direction.  For turning a single motor use drive.
     left(motor1, motor2, 255);
     delay(2000);
     brake(motor1, motor2);
     delay(1000); 
     right(motor1, motor2, 255);
     delay(2000);

     // Brake again
     brake(motor1, motor2);       // Stop Motor 1 and Motor 2 for 2 seconds 
     delay(2000); 

}
