
#define MOTOR1_IN1 11
#define MOTOR1_IN2 12
#define MOTOR2_IN1 9
#define MOTOR2_IN2 10

// Definição do PWM para controle de velocidade se a ponte H permitir
//#define MOTOR1_PWM 6    // Motor 1 - PWM
//#define MOTOR2_PWM 5    // Motor 2 - PWM

void setup() {                                        
  pinMode(MOTOR1_IN1, OUTPUT);
  pinMode(MOTOR1_IN2, OUTPUT);
  pinMode(MOTOR2_IN1, OUTPUT);
  pinMode(MOTOR2_IN2, OUTPUT);
//  pinMode(MOTOR1_PWM, OUTPUT);
//  pinMode(MOTOR2_PWM, OUTPUT);
  Serial.begin(9600);
  Serial.println("Iniciando os motores...");
}

void loop() {
  // Motor 1 - Girando no sentido horário
  digitalWrite(MOTOR1_IN1, HIGH);
  digitalWrite(MOTOR1_IN2, LOW);
 // analogWrite(MOTOR1_PWM, 255);  // Velocidade máxima
  Serial.println("Motor 1 girando no sentido horário");
  delay(2000);

  // Motor 1 - Girando no sentido anti-horário
  digitalWrite(MOTOR1_IN1, LOW);
  digitalWrite(MOTOR1_IN2, HIGH);
 // analogWrite(MOTOR1_PWM, 255);  // Velocidade máxima
  Serial.println("Motor 1 girando no sentido anti-horário");
  delay(2000);

  // Motor 2 - Girando no sentido horário
  digitalWrite(MOTOR2_IN1, HIGH);
  digitalWrite(MOTOR2_IN2, LOW);
 // analogWrite(MOTOR2_PWM, 255);  // Velocidade máxima
  Serial.println("Motor 2 girando no sentido horário");
  delay(2000); 

  // Motor 2 - Girando no sentido anti-horário
  digitalWrite(MOTOR2_IN1, LOW);
  digitalWrite(MOTOR2_IN2, HIGH);
  //analogWrite(MOTOR2_PWM, 255);  // Velocidade máxima
  Serial.println("Motor 2 girando no sentido anti-horário");
  delay(2000);

  // Parando ambos os motores
  digitalWrite(MOTOR1_IN1, LOW);
  digitalWrite(MOTOR1_IN2, LOW);
  digitalWrite(MOTOR2_IN1, LOW);
  digitalWrite(MOTOR2_IN2, LOW);
  //analogWrite(MOTOR1_PWM, 0);  // Parar motor 1
  //analogWrite(MOTOR2_PWM, 0);  // Parar motor 2
  Serial.println("Parando ambos os motores");
  delay(2000);
}
