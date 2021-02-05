void setup() {
  // put your setup code here, to run once:
  //Initialize serial and wait for port to open:

  Serial.begin(9600);

  // prints title with ending line break
  Serial.println("Accende e spegne il led con la seriale");
  Serial.println("a accende il led");
  Serial.println("s spegne il led");
  Serial.println("l lampeggia il led");
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()) {
    unsigned char comando = Serial.read();
    if ( 'a' == comando ) {
      digitalWrite(LED_BUILTIN, HIGH);
      Serial.println("led acceso");
    } else if ( 's' == comando ) {
      digitalWrite(LED_BUILTIN, LOW);
      Serial.println("led spento");
    } else if (comando=='l')
      {Serial.println("il led lampeggia");
      while(!Serial.available()){
        ;
      }
        comando=Serial.read();
        if(comando>=49 && comando<=57){
        comando=comando-48;
        }Serial.print(comando);
        Serial.println("volte.");
       
       for(unsigned char i=0;i<comando;i++){
        Serial.println("led acceso");
        digitalWrite(LED_BUILTIN, HIGH);
       delay(500);
        Serial.println("led spento");
        digitalWrite(LED_BUILTIN, LOW);
        delay(500);
    }
     }else
     Serial.println("comando non riconosciuto, inserire 0 o 1 o 2");
  }
}
