/************************/
 /* ©Phillipp Reim */
/************************/

int LED = 3;                                //Pin 3 (PWM-fähig) wird als LED-Pin definiert.
int LDR = A2;                               //Pin A2 (Analog) wird als LDR-Pin definiert.
int Messwert;                               //Variable Messwert wird als Integer definiert.
void setup() {
  // put your setup code here, to run once:
pinMode(LED,OUTPUT);                        //LED-Pin wird als Output festgelegt.
pinMode(LDR,INPUT);                         //LED-Pin wird als Output festgelegt.
Serial.begin(9600);                         //Serielle Datenübertragungsrate wird auf 9600 festgelegt.
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.read() == 'S')                  //bei Eingabe von S startet die Messung.
  {
    for(int i=0;i<255;i++)                  //die Schleife steigert die Helligkeit der LED in 255 Schritten (PWM) und liest den Messwert aus.
    {
      analogWrite(3,i);                     //Die LED wird mit dem Wert i angesteuert. Umso größer i, desto heller die LED.
      Messwert = analogRead(LDR);           //Messwert wird definiert als im aktuellen Durchlauf gemessener Wert am LDR.
      Serial.print("Messwert: ");           //Messwert, Helligkeit und Text werden im Serial Monitor ausgegeben.
      Serial.println(Messwert);
      Serial.print("Helligkeit der LED:");
      Serial.println(i);
      delay(55);                            //Verzögerung um 55ms.
      } 
    }
}

