# Control de LEDs y Detección de Proximidad con Sensor Ultrasónico

Este proyecto implementa un sistema básico de control de LEDs en un ciclo de tráfico simulado (verde, amarillo, rojo) con detección de proximidad mediante un sensor ultrasónico. Cuando un objeto (como un carro) se encuentra a menos de 30 cm, el sistema detecta su presencia y muestra un mensaje en el monitor serial.

---

## Descripción del Proyecto

Este código está diseñado para operar un conjunto de tres LEDs (verde, amarillo y rojo) que simulan un semáforo. La secuencia de encendido es la siguiente:
- **Verde:** Encendido durante 5 segundos.
- **Amarillo:** Encendido durante 1 segundo.
- **Rojo:** Encendido durante 5 segundos.

Además, un sensor ultrasónico verifica la presencia de un objeto (carro) dentro de una distancia de 30 cm. Si detecta un objeto en esta proximidad, el sistema muestra el mensaje "Si hay un carro" en el monitor serial, y en caso contrario, muestra "No hay un carro".

---

## Componentes Utilizados

1. **Sensor ultrasónico HC-SR04** para la detección de objetos.
2. **LEDs**:
   - Verde
   - Amarillo
   - Rojo

## Configuración de Pines

- **Sensor ultrasónico**:
  - `trigPin` (pin de disparo): Pin 12
  - `echoPin` (pin de eco): Pin 14
- **LEDs**:
  - `ledVerde`: Pin 5
  - `ledAmarillo`: Pin 4
  - `ledRojo`: Pin 0

## Variables de Configuración

- **Tiempo de los LEDs**:
  - `intervaloVerde`: 5000 ms (5 segundos)
  - `intervaloAmarillo`: 1000 ms (1 segundo)
  - `intervaloRojo`: 5000 ms (5 segundos)
- **Distancia de detección**:
  - Si la distancia medida es menor o igual a 30 cm, se considera que hay un objeto presente.

---

## Estructura del Código

1. **setup()**: Configura los pines de los LEDs como salida y los pines del sensor ultrasónico.
2. **loop()**: Llama a las funciones principales:
   - `manejarLEDs()`: Controla el ciclo de los LEDs.
   - `detectarCarro()`: Realiza la detección de proximidad.
3. **manejarLEDs()**: Realiza el cambio de estado entre los LEDs según el tiempo especificado para cada color.
4. **detectarCarro()**: Calcula la distancia al objeto en frente del sensor ultrasónico y muestra un mensaje en el monitor serial en función de la proximidad detectada.

---

## Uso

1. Conectar los LEDs y el sensor ultrasónico a los pines correspondientes en la placa de control (Arduino o similar).
2. Cargar el código en la placa.
3. Observar la secuencia de LEDs y la salida en el monitor serial para verificar la detección de objetos.
