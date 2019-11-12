const int Trigger = 12;   //Pin digital 2 para el Trigger del sensor
const int Echo = 11;   //Pin digital 3 para el Echo del sensor


int led_verde=4;
int led_amarillo=2;
int led_rojo=3;

void setup() {
 Serial.begin(9600);//iniciailzamos la comunicación
  pinMode(Trigger, OUTPUT); //pin como salida
  pinMode(Echo, INPUT);  //pin como entrada
  digitalWrite(Trigger, LOW);//Inicializamos el pin con 0
  ///semaforo
pinMode(led_verde,OUTPUT);
pinMode(led_amarillo,OUTPUT);
pinMode(led_rojo,OUTPUT);
digitalWrite(led_verde,LOW);
digitalWrite(led_amarillo,LOW);
digitalWrite(led_rojo,HIGH);
}

void loop() { 
  // put your main code here, to run repeatedly:
long t; //timepo que demora en llegar el eco
  long d; //distancia en centimetros

  digitalWrite(Trigger, HIGH);
  delayMicroseconds(10);          //Enviamos un pulso de 10us
  digitalWrite(Trigger, LOW);
  
  t = pulseIn(Echo, HIGH); //obtenemos el ancho del pulso
  d = t/59;             //escalamos el tiempo a una distancia en cm

Serial.print("Distancia: ");
  Serial.print(d);      //Enviamos serialmente el valor de la distancia
  Serial.print("cm");
  Serial.println();
  delay(300);          //Hacemos una pausa de 100ms


if(d>10)
{  
  semaforo(); 
  }
}


void semaforo(){
verde();
amarillo();
rojo();
  }

  void verde()
  {
    digitalWrite(led_rojo,LOW);
    digitalWrite(led_verde,HIGH);
    delay(5000);
    
    for(int i=1; i<4; i++){      
      digitalWrite(led_verde,LOW);
      delay(500);

      digitalWrite(led_verde,HIGH);
        delay(1000);
      
      }
      digitalWrite(led_verde,LOW);
   }

   void amarillo()
  {
    digitalWrite(led_amarillo,HIGH);
    delay(4000);
    digitalWrite(led_amarillo,LOW);
    delay(200);
    digitalWrite(led_amarillo,LOW);

  }

   void rojo()
  {
    digitalWrite(led_rojo,HIGH);
    delay(6000);
  }
