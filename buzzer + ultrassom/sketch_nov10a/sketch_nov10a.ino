// Defina os pinos de conexão do sensor
int trigPin = 10;  // Pino TRIG do sensor
int echoPin = 11; // Pino ECHO do sensor
int buzzer = 2;
// Variável para armazenar a distância

long getDistance(int trigger, int echo){
  // Função que calcula a distância entre o sensor HC-SR04 e um sólido próximo dele 
  long duration;
  int distance;

  // Gera um pulso de 10µs no pino trigger
  // O sensor HC-SR04 está projetado para ser acionado com um pulso de exatamente 10 microssegundos (µs) no pino TRIG
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);
  // Lê o tempo que o pulso leva para retornar
  duration = pulseIn(echoPin, HIGH);
  // Calcula a distância em centímetros
  distance = duration * 0.034 / 2; // Velocidade do som = 340 m/s ou 0.034 cm/µs // Divisão por 2 pois a duração tem ida e volta
  return distance;
  }

void setup() {
  Serial.begin(9600);
  // Configura os pinos TRIG e ECHO
  pinMode(trigPin, OUTPUT); //saída
  pinMode(echoPin, INPUT);  //entrada
}

void loop() {

  // Exibe a distância no monitor serial
  long dist = getDistance(trigPin,echoPin);
  Serial.print("Distância: ");
  Serial.print(dist);
  Serial.println(" cm");
  delay(500);
  if(dist<=10){
    tone(buzzer,2000);
    delay(500);
    tone(buzzer,500);
    
  }
  else{
    noTone(buzzer);
    }
  

}
