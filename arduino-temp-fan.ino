const int A_BTM = 80;
const int A_TOP = 1000;
const int I_BTM = 0;
const int I_TOP = 5;
const int MODE_CNT = 6;
const int P_MODES[] = {0, 50, 100, 150, 200, 255};
const int L_PINS[]  = {0,  8,   9,  10,  11,  12};
const int A_IN_PIN = A5;
const int P_OUT_PIN = 3;
const int FAN_DELAY = 1000;

void setup() {
    Serial.begin(9600);
    pinMode(A_IN_PIN, INPUT);
    pinMode(P_OUT_PIN, OUTPUT);
    for(int i = 0; i < MODE_CNT; i++) {
      pinMode(L_PINS[i], OUTPUT);
    }
    ledsOff();
}

void loop() {
  int aVal = analogRead(A_IN_PIN);
  int iVal = map(aVal, A_BTM, A_TOP, I_BTM, I_TOP);
  iVal = (iVal > I_TOP) ? I_TOP : iVal;
  iVal = (iVal < I_BTM) ? I_BTM : iVal;
  int pVal = P_MODES[iVal];
  int lPin = L_PINS[iVal];
  analogWrite(P_OUT_PIN, pVal);
  ledsOff();
  digitalWrite(lPin, HIGH);
  /**/
  Serial.print("aVal=");
  Serial.print(aVal);
  Serial.print(", pVal=");
  Serial.print(pVal);
  Serial.print(", iVal=");
  Serial.print(iVal);
  Serial.print(", lPin=");
  Serial.println(lPin);
  /**/
  delay(FAN_DELAY);
}

void ledsOff() {
  for(int i = 0; i < MODE_CNT; i++) {
    digitalWrite(L_PINS[i], LOW);
  }
}
