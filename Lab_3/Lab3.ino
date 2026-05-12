Codigo lab 3

// C++ code
//
int LED = 3;          // LED conectado al pin 3 (salida PWM)
int BRILLO;           // Variable para guardar el valor del brillo
int POT = 0;          // Pin analógico A0 donde está conectado el potenciómetro

void setup() {
  pinMode(LED, OUTPUT);   // Configura el pin 3 como salida para el LED
}

void loop() {
  BRILLO = analogRead(POT) / 4;   // Lee el valor del potenciómetro
                                  // y lo divide entre 4 para pasarlo al rango 0–255
  									//porque el conversor ADC de Arduino es de 10 bits)
  analogWrite(LED, BRILLO);       // Ajusta el brillo del LED usando PWM
}