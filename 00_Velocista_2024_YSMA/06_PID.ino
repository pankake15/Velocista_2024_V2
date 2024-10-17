void PID(){
  // CALCULA POSICION DE LINEA NEGRA SEGUN LECTURA DE SENSORES (0-7000)
        uint16_t position = qtr.readLineWhite(sensorValues);
        // qtr.read(Valores_rampa);
        
        // CALCULO PID
        float error = position - 3500;
        integral = integral + error;
        integral = constrain(integral, -1200, 1200); //limitamos la integral para no causar problemas
        float motorSpeed = KP * error + KD * (error - lastError) + KI * integral;
        lastError = error;
        
        // Mapeo de motorSpeed a rango de -255 a 255
        MotorF = map(motorSpeed, -maxMotorSpeed, maxMotorSpeed, -255, 255);
        MotorF = constrain(MotorF, -255, 255);


        int m1Speed = Velocidad + MotorF;
        int m2Speed = Velocidad - MotorF;

        right(m1Speed);
        left(m2Speed);

        // VELOCIDAD MOTORES
        if (error > 0) {
            digitalWrite(LED_IZQ, HIGH);
            digitalWrite(LED_DER, LOW);
        } else if (error < 0) {
            digitalWrite(LED_IZQ, LOW);
            digitalWrite(LED_DER, HIGH);
        }
//}
}
