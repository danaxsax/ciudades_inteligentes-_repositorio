# Control de Semáforos Inteligentes con MQTT y MySQL

Este proyecto implementa un sistema de semáforos inteligentes que utiliza el protocolo **MQTT** para recibir datos de sensores y controlar LEDs que simulan semáforos. Además, registra los datos de tráfico y configuración en una base de datos **MySQL**.

## Descripción del Proyecto

El archivo `main.py` contiene el código para recibir datos de dos clientes MQTT simulando diferentes tipos de semáforos. La información recibida se guarda en una base de datos MySQL para hacer un seguimiento de las detecciones de tráfico y las configuraciones de los LEDs.

Los clientes MQTT se conectan a sensores que envían datos relacionados con el tráfico y el estado de los LEDs (color y tiempo de encendido). El sistema interpreta estos datos y registra:

- La detección de tráfico.
- La configuración del color y tiempo de cada LED.
- Los tipos de semáforos y sus coordenadas.

## Componentes del Proyecto

- **MQTT**: Protocolos de comunicación utilizados para recibir datos de sensores conectados al semáforo.
- **MySQL**: Base de datos para almacenar registros de detección de tráfico y configuraciones de LEDs.

## Bases de Datos y Tablas

El sistema utiliza tres tablas:

1. **traffic_detection**: Registra las detecciones de tráfico.
2. **settings_leds**: Almacena el color y duración de cada LED.
3. **traffic_light**: Guarda las características de cada semáforo, incluyendo su dirección y tipo.

## Coordenadas y Tipos de Semáforos

El sistema define dos semáforos:

- **Client1**: Coordenadas `25.651417, -100.292138` y tipo "Semáforo Vehicular".
- **Client2**: Coordenadas `25.671234, -100.312345` y tipo "Semáforo Peatonal".

## Configuración de la Base de Datos

La función `setup_database()` establece la conexión inicial a la base de datos y asegura que las tablas estén disponibles para almacenar datos.

### Variables de Configuración

- **host**: Dirección del servidor MySQL (por defecto, `localhost`).
- **user**: Usuario de MySQL.
- **password**: Contraseña de MySQL.

## Funciones Principales

- `insert_traffic_light`: Inserta o actualiza la información del semáforo en la tabla `traffic_light`.
- `insert_traffic_detection`: Inserta la detección de tráfico en la tabla `traffic_detection` utilizando el `light_id` del semáforo.
- `insert_settings_leds`: Inserta el color y tiempo de cada LED en la tabla `settings_leds`.
- `insert_data`: Llama a las funciones anteriores para registrar los datos del semáforo, detección de tráfico, y configuración de LEDs en una sola operación.

## Recepción de Mensajes MQTT

El sistema define funciones de manejo de mensajes para recibir datos de detección y configuración de LEDs desde dos canales MQTT diferentes (`arduino_1` y `arduino_2`), cada uno correspondiente a un semáforo:

- **message_handling_1** y **message_handling_2**: Obtienen datos de detección del tráfico.
- **message_handling_color_time**: Recibe y registra el color del LED y el tiempo de encendido.

## Ejecución del Sistema

1. Los clientes MQTT se conectan a un servidor y escuchan datos de detección de tráfico y configuración de LEDs.
2. Los datos se procesan y almacenan en la base de datos para su análisis y monitoreo.
3. Se inicia en modo **multihilo** para que cada cliente MQTT pueda escuchar en paralelo.

## Finalización del Programa

Para finalizar, se desconectan ambos clientes MQTT y se libera la conexión a la base de datos.
