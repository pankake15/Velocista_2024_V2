void setup() {

    // Configuración de pines
    pinMode(LED_DER, OUTPUT);
    pinMode(LED_IZQ, OUTPUT);
    pinMode(ML_IN1, OUTPUT);
    pinMode(ML_IN2, OUTPUT);
    pinMode(ML_PWM, OUTPUT);
    pinMode(MR_IN1, OUTPUT);
    pinMode(MR_IN2, OUTPUT);
    pinMode(MR_PWM, OUTPUT);
    pinMode(BOT_C, INPUT);
    
    attachInterrupt(digitalPinToInterrupt(BOT_C), InterIniciar, RISING);

    
    ledcAttach(MR_PWM, 12000, 8);
    ledcAttach(ML_PWM, 12000, 8);

    WiFi.begin(ssid, password);  // Connect to WiFi - defaults to WiFi Station mode

    // Ensure WiFi is connected
    while (WiFi.status() != WL_CONNECTED) {
      digitalWrite(LED_IZQ, HIGH);
      delay(500);
    }
    digitalWrite(LED_IZQ, LOW);

    Calibrar();

    digitalWrite(LED_DER, HIGH);

    ArduinoOTA.begin();  // Starts OTA
}

void loop() {

    ArduinoOTA.handle();  // Handles a code update request

//-----------------------------------------------------------------------------------------------------------------------------------------------
//---BOTONES------BOTONES------BOTONES------BOTONES------BOTONES------BOTONES------BOTONES------BOTONES------BOTONES------BOTONES------BOTONES---

    Modulos Etapa = Botones;

    if(Etapa == Pid && last_bot == false){
      PID();
    }else{
      Botones = Stop;
    }

//-----------------------------------------------------------------------------------------------------------------------------------------------
}
