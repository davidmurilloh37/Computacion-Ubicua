#include <LiquidCrystal_I2C.h>      //Importamos libreria LiquidCrystal con I2C
LiquidCrystal_I2C lcd(0x27,16,2);      //Declaramos el I2C con la direccion 0x27, junto con las 16 columnas y 2 filas del LCD

int SENSOR;      // Declaracion de Entero para almacenar informacion de SENSOR
float TEMPERATURA;      //Declaracion de Real para almacenar TEMPERATURA

void setup() {            //Bloque de Declaraciones
  Serial.begin(9600);      //Declaracion de monitor serial
  lcd.init();        //Declaracion de inicializacion LCD
  lcd.backlight();      //Enciende fondo de pantalla LCD
  lcd.clear();          //Inicializacion 
}

void loop() {         //Bloque de procesos
  SENSOR = analogRead(A0);        //Variable SENSOR recibe informacion de Pin analogo A0
  TEMPERATURA = ((SENSOR * 5000.0) / 1023) / 10;        //Variable TEMPERATURA transforma el valor del sensor a grados celcius (°C)
  
  Serial.print("Temperatura: ");         //Imprime "Temperatura: " en monitor serial
  Serial.println(TEMPERATURA,1);        //Imprime valor de TEMPERATURA con un solo numero decimal en el monitor serial

  lcd.setCursor(0,0);        //Selecciona la primera columna de la primera fila para iniciar a escribir texto
  lcd.print("Temp: ");      //Escribe "Temp: " en la pantalla LCD
  lcd.print(TEMPERATURA, 1);      //Escribe el valor de TEMPERATURA con un solo numero decimal en la pantalla LCD
  lcd.print("C");      //Escribe "C" en la pantalla LCD

  //La pantalla LCD mostrara algo como Temp: 29.5C

  delay(1000);      //Tiempo de espera de 1 segundo (1000ms)
}