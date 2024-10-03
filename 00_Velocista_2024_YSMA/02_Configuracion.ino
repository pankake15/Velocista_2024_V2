//INSTALAR ANTES DE SEGUIR!!
#include <QTRSensors.h>
#include <WiFi.h>        // For connecting ESP32 to WiFi
#include <ArduinoOTA.h>  // For enabling over-the-air updates

//DECLARO QTR
QTRSensors qtr;

//Configuracion de WiFi
const char* ssid = "Junior";  // Change to your WiFi Network name
const char* password = "diegos:)";  // Change to your password

//VARIABLES DEL SENSOR
const uint8_t SensorCount = 8;
uint16_t sensorValues[SensorCount];

//VARIABLES DEL PID
float lastError = 0; 
float KP = 1, KD = 0, KI = 0;
int Velocidad = 30;
float integral = 0;
int maxMotorSpeed = 7000; // Valor máximo teórico para motorSpeed basado en tu sistema
int MotorF; 

// hice float a integral, error, lasterror

//VARIABLE DE LAS INTERRUPCIONES
volatile int Start = 0;

bool last_bot = true;

typedef enum {
  Stop,        //0
  Pid,         //1
  Limpiar_R,   //3
  Bluetooth    //4
} Modulos;

volatile Modulos Botones;
