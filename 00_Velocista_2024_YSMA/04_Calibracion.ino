

void Calibrar(){
        // CONFIGURACION INICIAL
        qtr.setTypeAnalog();
        qtr.setSensorPins((const uint8_t[]){8, 18, 17, 16, 15, 7, 6, 5}, SensorCount);
        
        
        // CALIBRACION (10 SEG APROX)
        digitalWrite(LED_DER, HIGH);
        for (uint16_t i = 0; i < 700; i++) {
            qtr.calibrate();
        }
        digitalWrite(LED_DER, LOW);

        
        Botones = Stop;
}
