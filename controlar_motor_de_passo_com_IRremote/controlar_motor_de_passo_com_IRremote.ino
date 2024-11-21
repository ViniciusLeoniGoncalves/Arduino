#include <IRremote.hpp>
#include <Stepper.h>

#define IR_RECEIVE_PIN 7
#define STEPSPERREVOLUTION 500

//objeto motor de passo, usaremos as portas 10, 11, 12 e 13 como ABDC do ponte H
Stepper myStepper(STEPSPERREVOLUTION, 10, 11, 12, 13);

uint64_t key_value = 0;
String firstDigit, secondDigit, thirdDigit, concat;
int steps;
int digitCount=1;
bool inversor = false;

void registerString(String STR, int count){
  switch(count){
  	case 1:
    firstDigit = STR;
    break;
    case 2:
    secondDigit = STR;
    break;
    case 3:
    thirdDigit = STR;
    break;
  }
}

void setup(){
  myStepper.setSpeed(60); //60rpm
  Serial.begin(9600);
  IrReceiver.begin(IR_RECEIVE_PIN,ENABLE_LED_FEEDBACK);
}

void loop(){
 /*
 O programa armazena até 3 dígitos pressionados no controle remoto.
 Cada dígito é registrado nas variáveis correspondentes (firstDigit, secondDigit, thirdDigit)
 através da função registerString(), que mapeia os números pressionados 
 para essas variáveis de acordo com o contador digitCount.
 
 O contador digitCount aumenta a cada dígito registrado e, quando atinge 4
 (indicando que os três dígitos foram recebidos), o programa concatena os três dígitos em uma variável
 concat e a converte para um número inteiro (steps) usando o método toInt(). 
 
 Este valor é então usado para controlar o movimento de um motor de passo 
 (a lógica para o controle do motor ainda precisa ser implementada).

Quando o botão "PLAY/CONFIRM" (0xFA05BF00) é pressionado, o programa
realiza uma operação semelhante: 
ele concatena os três dígitos já registrados nas variáveis 
firstDigit, secondDigit e thirdDigit, converte o valor concatenado
em um número inteiro (steps), e em seguida, executa uma ação
relacionada ao número obtido (como mudar o canal ou mover
o motor de passo). Após essa operação, as variáveis de dígitos são limpas 
e o contador digitCount é resetado, aguardando os próximos dígitos.
 */
  if (IrReceiver.decode()){
    if(IrReceiver.decodedIRData.decodedRawData != 0xFFFFFFFF){
    	key_value = IrReceiver.decodedIRData.decodedRawData;
    }
  	if(digitCount == 4 && key_value != 0xFA05BF00){
      concat = firstDigit + secondDigit + thirdDigit;
      steps= concat.toInt();
      if(inversor == true){
      	steps = -1*steps; 
        inversor = false;
      }
      Serial.println("Muda pro canal por 3 digitos");
      Serial.println(steps);
      
      //incluir lógica de girar o step motor
      myStepper.step(steps);
      
      firstDigit = "";
      secondDigit = "";
      thirdDigit = "";
      digitCount=1;
    }
        switch(key_value){
          case 0xFA05BF00:
          Serial.println("PLAY/CONFIRM");
          Serial.println("Muda pro canal");
          concat = firstDigit + secondDigit + thirdDigit;
          steps= concat.toInt();
          if(inversor == true){
      	    steps = -1*steps; 
            inversor = false;
      	  }
          Serial.println(steps);
          
          //incluir lógica de girar o step motor
          myStepper.step(steps);
         
          firstDigit = "";
          secondDigit = "";
          thirdDigit = "";
          digitCount=1;
          break ;
          
          case 0xF10EBF00:
          Serial.println("Teclou FUNC/STOP");
          Serial.println("invertendo sentido de rotação");
          if(inversor == true)
            inversor = false;
          else
            inversor = true;
          break ; 
          case 0xF30CBF00:
          Serial.println("Teclou 0");
          registerString("0",digitCount);
          digitCount+=1;
          break ;  
          case 0xEF10BF00:
          Serial.println("Teclou 1");
          registerString("1",digitCount);
          digitCount+=1;
          break ;
          case 0xEE11BF00:
          Serial.println("Teclou 2");
          registerString("2",digitCount);
          digitCount+=1;
          break ;
          case 0xED12BF00:
          Serial.println("Teclou 3");
          registerString("3",digitCount);
          digitCount+=1;
          break ;
          case 0xEB14BF00:
          Serial.println("Teclou 4");
          registerString("4",digitCount);
          digitCount+=1;
          break ;
          case 0xEA15BF00:
          Serial.println("Teclou 5");
          registerString("5",digitCount);
          digitCount+=1;
          break ;
          case 0xE916BF00:
          Serial.println("Teclou 6");
          registerString("6",digitCount);
          digitCount+=1;
          break ;
          case 0xE718BF00:
          Serial.println("Teclou 7");
          registerString("7",digitCount);
          digitCount+=1;
          break ;
          case 0xE619BF00:
          Serial.println("Teclou 8");
          registerString("8",digitCount);
          digitCount+=1;
          break ;
          case 0xE51ABF00:
          Serial.println("Teclou 9");
          registerString("9",digitCount);
          digitCount+=1;
          break ;      
        }
        IrReceiver.resume(); 
  }
}