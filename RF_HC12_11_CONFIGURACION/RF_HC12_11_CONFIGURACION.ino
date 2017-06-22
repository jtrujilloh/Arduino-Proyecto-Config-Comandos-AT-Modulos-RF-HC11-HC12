/* CONFIGURACION DE MÓDULOS CON COMANDOS AT

COMANDOS:

Detalle: Ingresa en Modo Configuración y Detecta si el Device está OK
Command:    AT
Return:     OK

Detalle: Obtiene la Versión del Firmware
Command:    AT+V
Return:     HC-11_V0.0

Detalle: Setea los Baudios del Puerto Serie
Command:    AT+Bxxxx (9600 19200 38400 57600 2400 48000 115200)
Return:     OK-xxxx

Detalle: Setea el Canal
Command:    AT+Cxxx (001 - 127)
Return:     OK-xxx

Detalle: Setea la Dirección
Command:    AT+Axxx (001 - 255)
Return:     OK-xxx

Detalle: Setea la Potencia de Transmisión y Recepción
Command:    AT+Px (1 - 8)
Return:     OK-x

Module Emission Power Dbm() = 1(-1), 2(2), 3(5), 4(8), 5(11), 6(14), 7(17), 8(20)
*/

#define SET_RF_HC11_12 40

void setup()
{
  Serial.begin(19200);
  Serial2.begin(19200);  
  delay(50);
  pinMode(SET_RF_HC11_12, OUTPUT);
  //SETEA MODULO RF-HC11 - 12 A ENTRAR EN MODO CONFIGURACION
  //HIGH: MODO ENVIO Y RECEPCION DE DATOS
  //LOW: MODO CONFIGURACION
  digitalWrite(SET_RF_HC11_12, HIGH);
  Serial.println("Arduino Iniciado!");
  
  //Serial2.write("a + B9600");
}

void loop() 
{
  
   delay(50);
   while (Serial.available()){
     //Serial.println(DEC, Serial.read()); 
     Serial2.write(Serial.read());
   }
   delay(50);
   
   while (Serial2.available()){
      Serial.write(Serial2.read());
   }
   
}
