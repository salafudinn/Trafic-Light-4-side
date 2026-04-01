int utara[]   = {13,12,11};
int barat[]   = {10,9,8};
int selatan[] = {7,6,5};
int timur[]   = {4,3,2};

void setup() {
  for (int i = 0; i < 3; i++) {
    pinMode(utara[i], OUTPUT);
    pinMode(timur[i], OUTPUT);
    pinMode(selatan[i], OUTPUT);
    pinMode(barat[i], OUTPUT);
  }
  semuaMerah();
  delay(2000);
}

void semuaMerah() {
  int* arah[] = {utara, timur, selatan, barat};
  for (int i = 0; i < 4; i++) {
    digitalWrite(arah[i][0], HIGH); // merah ON
    digitalWrite(arah[i][1], LOW);  // kuning OFF
    digitalWrite(arah[i][2], LOW);  // hijau OFF
  }
}

void lampuKedip(int lampuKuning) {
  for (int i = 0; i < 3; i++) {
    digitalWrite(lampuKuning, HIGH);
    delay(300);
    digitalWrite(lampuKuning, LOW);
    delay(300);
  }
}

void lampuBagian(int signal[]) {
  semuaMerah();
  delay(1000);

  lampuKedip(signal[1]); // aba-aba kuning sebelum hijau
  delay(500);

  digitalWrite(signal[0], LOW);  // merah OFF
  digitalWrite(signal[2], HIGH); // hijau ON
  delay(5000);

  digitalWrite(signal[2], LOW);  // hijau OFF
  lampuKedip(signal[1]);         // kuning penutup

  digitalWrite(signal[0], HIGH); // merah ON
}

void loop() {
  lampuBagian(utara);
  lampuBagian(timur);
  lampuBagian(selatan);
  lampuBagian(barat);
}