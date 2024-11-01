// Definimos los pines para el sensor ultrasónico y los LEDs
const int trigPin = 12;
const int echoPin = 14;
const int ledVerde = 5;
const int ledAmarillo = 4;
const int ledRojo = 0;

// Variables para medir la distancia
long duracion;
int distancia;

// Variables para controlar los tiempos de los LEDs
unsigned long tiempoInicio = 0;
const unsigned long intervaloVerde = 5000;
const unsigned long intervaloAmarillo = 1000;
const unsigned long intervaloRojo = 5000;

// Variable para llevar el estado de los LEDs
int estadoLed = 0;  // 0: verde, 1: amarillo, 2: rojo

void setup() {
  Serial.begin(115200);

  // Configuramos los pines de los LEDs como salida
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAmarillo, OUTPUT);
  pinMode(ledRojo, OUTPUT);

  // Configuramos los pines del sensor ultrasónico
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  manejarLEDs();
  detectarCarro();
}

void manejarLEDs() {
  unsigned long tiempoActual = millis();

  switch (estadoLed) {
    case 0:  // LED verde encendido
      if (tiempoActual - tiempoInicio >= intervaloVerde) {
        digitalWrite(ledVerde, LOW);    // Apagamos el LED verde
        digitalWrite(ledAmarillo, HIGH); // Encendemos el LED amarillo
        tiempoInicio = tiempoActual;     // Reiniciamos el temporizador
        estadoLed = 1;                   // Cambiamos al siguiente estado
      } else {
        digitalWrite(ledVerde, HIGH);    // Aseguramos que el verde está encendido
      }
      break;

    case 1:  // LED amarillo encendido
      if (tiempoActual - tiempoInicio >= intervaloAmarillo) {
        digitalWrite(ledAmarillo, LOW);  // Apagamos el LED amarillo
        digitalWrite(ledRojo, HIGH);     // Encendemos el LED rojo
        tiempoInicio = tiempoActual;     // Reiniciamos el temporizador
        estadoLed = 2;                   // Cambiamos al siguiente estado
      }
      break;

    case 2:  // LED rojo encendido
      if (tiempoActual - tiempoInicio >= intervaloRojo) {
        digitalWrite(ledRojo, LOW);      // Apagamos el LED rojo
        digitalWrite(ledVerde, HIGH);    // Encendemos el LED verde de nuevo
        tiempoInicio = tiempoActual;     // Reiniciamos el temporizador
        estadoLed = 0;                   // Regresamos al primer estado
      }
      break;
  }
}

void detectarCarro() {
  // Medir la distancia usando el sensor ultrasónico
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Calculamos la duración del pulso en el pin echo
  duracion = pulseIn(echoPin, HIGH);

  // Convertimos la duración a distancia en centímetros
  distancia = duracion * 0.034 / 2;

  // Verificamos si hay un objeto a menos de 30 cm
  if (distancia <= 30) {
    Serial.println("Si hay un carro");
  } else {
    Serial.println("No hay un carro");
  }

  // Agregamos un pequeño retardo para la siguiente lectura
  delay(500);
}

