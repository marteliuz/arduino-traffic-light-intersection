// Asignación de pines - Semaforo A
const int V1 = 3;
const int AM1 = 4;
const int R1 = 5;
const int PV1 = 6;
const int PR1 = 7;

// Asignación de pines - Semaforo B
const int V2 = 8;
const int AM2 = 9;
const int R2 = 10;
const int PV2 = 11;
const int PR2 = 12;

void setup() {
  // Configurar pines del 3 al 12 como salidas
  for (int i = 3; i <= 12; i++) {
    pinMode(i, OUTPUT);
  }
}

void loop() {
  // ====================================================
  // FASE 1: PASO CALLE A (Autos Calle A avanzan)
  // ====================================================

  // Vehicular A: VERDE | Peatonal A: ROJO
  digitalWrite(V1, HIGH);  digitalWrite(AM1, LOW);  digitalWrite(R1, LOW);
  digitalWrite(PV1, LOW);  digitalWrite(PR1, HIGH);

  // Vehicular B: ROJO | Peatonal B: VERDE
  digitalWrite(V2, LOW);   digitalWrite(AM2, LOW);  digitalWrite(R2, HIGH);
  digitalWrite(PV2, HIGH); digitalWrite(PR2, LOW);

  delay(60000); // 6 segundos de paso

  // Transición Calle A: Amarillo Vehicular / Parpadeo Peatonal B
  digitalWrite(V1, LOW);
  digitalWrite(AM1, HIGH);
  
  // Parpadeo de aviso para peatones en Calle B antes de cambiar
  for(int i = 0; i < 10; i++) {
    digitalWrite(PV2, LOW);  delay(300);
    digitalWrite(PV2, HIGH); delay(300);
  }

  digitalWrite(PV2, LOW); digitalWrite(PR2, HIGH); // Peatonal B a Rojo
  digitalWrite(AM1, LOW);  digitalWrite(R1, HIGH);  // Vehicular A a Rojo

  delay(1000); // Pausa de seguridad (Todos en rojo brevemente)

  // ====================================================
  // FASE 2: PASO CALLE B (Autos Calle B avanzan)
  // ====================================================

  // Vehicular B: VERDE | Peatonal B: ROJO
  digitalWrite(V2, HIGH);  digitalWrite(AM2, LOW);  digitalWrite(R2, LOW);
  digitalWrite(PV2, LOW);  digitalWrite(PR2, HIGH);

  // Vehicular A: ROJO | Peatonal A: VERDE
  digitalWrite(V1, LOW);   digitalWrite(AM1, LOW);  digitalWrite(R1, HIGH);
  digitalWrite(PV1, HIGH); digitalWrite(PR1, LOW);

  delay(60000); // 6 segundos de paso

  // Transición Calle B: Amarillo Vehicular / Parpadeo Peatonal A
  digitalWrite(V2, LOW);
  digitalWrite(AM2, HIGH);
  
  // Parpadeo de aviso para peatones en Calle A
  for(int i = 0; i < 10; i++) {
    digitalWrite(PV1, LOW);  delay(300);
    digitalWrite(PV1, HIGH); delay(300);
  }

  digitalWrite(PV1, LOW); digitalWrite(PR1, HIGH); // Peatonal A a Rojo
  digitalWrite(AM2, LOW);  digitalWrite(R2, HIGH);  // Vehicular B a Rojo

  delay(1000); // Pausa de seguridad antes de reiniciar el ciclo
}