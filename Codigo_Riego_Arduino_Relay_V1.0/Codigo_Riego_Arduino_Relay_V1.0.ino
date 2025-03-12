// Producto de ZACETREX TECHNOLOGIES S.A.C
// Este código se hizo con fin de compartirlo con la comunidad y tiene fines educativos

//declaramos nuestra variable
int relay = 8;//pin para el modulo relay

void setup() {
Serial.begin(9600);//Configuramos la velocidad
pinMode(relay,OUTPUT);//Declaramos a relay como salida
}

void loop() {
int valor = analogRead(A0);//Leemos el voltaje analógico del pin A0
//Y almacenamos el resultado en nuestra variable "valor"
//Convertiendo el voltaje analógico en un valor digital

if (valor >= 1000){//Si el valor es mayor/igual a 1000
  Serial.println("El sensor esta fuera");//Se mostrará en pantalla
}
else if(valor <1000 && valor >= 600){//Si valor es menor o mayor/igual que 600
  digitalWrite(relay,HIGH);//El relay se prenderá para activar la bomba
  Serial.println("Seco");//Se mostrará en el monitor serial
}
else if(valor < 600 && valor >= 370){//Si valor es menor o mayor/igual que 370
  digitalWrite(relay,LOW);//Entonces el relay se apagará
  Serial.println("humedo");//Se mostrará en el monitor serial
}
else if (valor < 370){//Si valor es menor que 370
  Serial.println("Está en agua");//Se mostrará en pantalla
  digitalWrite(relay,LOW);//El relay se apagará
}
delay(1000);//Damos un tiempo de 1sg
}
//Aclaraciones: Si es con pwm, tiene que estar al minimo antes de subirlo al maximo, si desenchufa
//estando al max. debe hacer el mismo procedimiento para que la bomba active
