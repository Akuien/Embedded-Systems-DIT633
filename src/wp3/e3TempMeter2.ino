// (C) Anton Golubenko, Aditya Khadkikar, Akuien Deng - Group: 27 
// Work package 3 
// Exercise 3
// Submission code: XXXXXX (provided by your TA-s) 


// maximum limit of the temp sensor range
int TEMP_SENSOR_MAX = 1024;

void setup()
{
  // Initate the serial port
  Serial.begin(9600);
}

void loop()
{
  // Get the analog reading info for the voltage from the pin A0(analog in pin)
  double analog_reading = analogRead(A0);
  
  //Convert the analog value into voltage(0-5V)
  double voltage = (analog_reading / TEMP_SENSOR_MAX)*5.0;
  
  //Calculate the temperature
  // 5 for the volts the sensor is connected 
  //0.5 for the offset value
  double temp = (voltage - 0.5) * 100;



  // Print the voltage to the serial output
  Serial.print("Voltage: ");
  Serial.println(analog_reading * (5000 / TEMP_SENSOR_MAX));

  // Print the temperature to the serial output
  Serial.print("Current Temperature in degrees C: ");
  Serial.println(temp);

  // Add a delay of 500ms
  delay(500);
  
}