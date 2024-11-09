//////////////////////////////////////////////////////////
    Codigo para crear la base de datos, tablas y columnas
/////////////////////////////////////////////////////////

USE ciudadesinteligentes     //Se utiliza este comando en MySQL para elegir la base de datos a utilizar 

-- Modificar la tabla traffic_light, haciendo que light_id sea la clave primaria
CREATE TABLE traffic_light (
    light_id INT AUTO_INCREMENT PRIMARY KEY,   -- light_id como clave primaria
    address_light VARCHAR(100),
    type_light VARCHAR(50)
);

-- Crear la tabla traffic_detection, actualizada para referenciar light_id
CREATE TABLE traffic_detection (
    id INT AUTO_INCREMENT PRIMARY KEY,
    detection BOOLEAN,
    timestamp TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    light_id INT,  
    CONSTRAINT fk_traffic_light FOREIGN KEY (light_id) REFERENCES traffic_light(light_id)  -- Referencia a light_id en traffic_light
);

-- Crear la tabla settings_leds, actualizada para referenciar light_id
CREATE TABLE settings_leds (
    leds_id INT AUTO_INCREMENT PRIMARY KEY,
    led_color VARCHAR(50),
    timestamp TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    time_leds INT,
    light_id INT,  
    CONSTRAINT fk_settings_leds FOREIGN KEY (light_id) REFERENCES traffic_light(light_id)  -- Referencia a light_id en traffic_light
);


//Query para seleccionar cada tabla y ver sus correspondientes datos guardados.

SELECT *
FROM traffic_light

SELECT *
FROM traffic_detection

SELECT *
FROM settings_leds
