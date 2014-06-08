//*****************************************************************************************************************************************************/
//......................................................................................................................................................
//...............           .           ...           .....         . .....     ..... .   ...     ...     .....     .....           ....................
//..............                                       ...             . .       ....      .       .         .       ...     ...     . .................
//.............  2@B@B@B@B@.  @B@B@B@B@B,  N@B@B@@@BN:  . iB@B@B@@@B5:     .@@@i .... vB@@   .@B@i   N@B@B:   . OB@;  .  :qB@@@B@BM7   .................
//.............  ZB@BXqGZ8Z  .B@BMX00GGM.  BB@BXNZB@B@q   r@@@N00MB@B@B:   ,B@Br ...  L@B@   .B@B7   @B@B@B:    B@B7    8@B@M1JUO@B@B: .................
//.............  S@BO         @B@.         G@Bk    j@B@.  iB@B     ,@B@B.  .@B@:  ... vB@B   .@B@i   O@@YB@B.   M@@i   B@B@.      BB@B  ................
//.............  XB@O         @@B:         8B@F    J@@B   i@B@       @B@G  .B@Bi ...  7@B@   .B@Bi   MB@ rB@B   G@@i  r@B@,       .@B@v  ...............
//.............  F@B@q8OMB5   @B@B@B@@@,   Z@BBJ2UMB@B:   iB@@  . .  P@B@  .@B@i  ... vB@B   .@B@i   M@@, E@@B  GB@i  qB@B  .....  B@BN  ...............
//.............. kB@B@@@B@M   B@@8XZGOO.   8B@B@B@B@v     i@B@   .   qB@B  .B@B: ...  r@B@   .B@B;   MB@:  MB@G S@Bi  q@B@   ...   @B@k  ...............
//.............  S@BM         @B@,         Z@Bq  :@@@5    iB@B       B@BZ  .@B@:      7B@B   .@B@i   O@Bi   @B@7uB@i  uB@@.   .   ,@@B7 ................
//.............  kB@M      .  B@B:         8B@N   :@B@Y   i@@@      O@B@.   B@@0      M@BM   .B@B;   MB@i    @@@B@@i  .@B@G       B@B@   ...............
//.............  q@@@   ....  @B@Nju1UFk.  M@BM    1@B@:  rB@B2u1X@B@B@:    r@@B@Jrr2B@B@.   .@B@r   B@Br    ,@B@B@r   i@B@BS777NB@@@   ................
//.............. NB@B  ..... .B@B@B@B@@@:  MB@O  .  B@B@  i@B@B@B@B@q;   ..  ,P@B@B@B@Bu   . ,@@B7   @@@;  .  i@B@Bi     1B@B@B@B@O7   .................
//.............   ..  .......   . ... ..    ..  ...  ...   ..   .       ....    .:::,     ... ...     ..  ...   . .  ..     ,:::.     ..................
//..............     .........           .     .....     .           ....... .         . ....     ..     .....     .......         .....................
//................................... ................. ......... ............... . ........... ................. ........... . . ......................
//******************************************************************************************************************************************************
//*********************** Developed by Fernando Garcia *************************************************************************************************
//******************************************************************************************************************************************************
//******* Questions, suggestions and praise: fefegarcia_1@hotmail.com **********************************************************************************
//******************************************************************************************************************************************

// This program is compatible with IDE 1.0.5

// Functions for control via web were implemented thanks to the precious help of Simone Grimaldi.

//---------------------------------------------------------

// This program was developed based on version 2.1 Stilo
// Available http://code.google.com/p/stilo/ this page 

//-----------------------------------------------------------
// This program is free software; You can redistribute and / or
// Modify it under the terms of the GNU General Public License
// As published by the Free Software Foundation version 3
// The License, or (at your option) any later version.
// This program is distributed in the hope that it will be useful,
// But without any warranty; without even the implied warranty of
// Merchantability or particular purpose. Refer to
// GNU General Public License for more details.

//*************************************************************************************************
//*************** select Language ***************************************************************
//*************************************************************************************************


// Uncomment the line Corresponding to your language

#define ENGLISH
//#define FRENCH
//#define GERMAN
//#define ITALIAN
//#define PORTUGUESE
//#define SPANISH

//*************************************************************************************************
//********************** libraries used ***********************************************************
//*************************************************************************************************
#include <UTFT.h>    
#include <UTouch.h> 
#include <Wire.h>
#include <EEPROM.h>
#include <writeAnything.h>
#include <DS1307henning.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <SdFat.h>
#include <SdFatUtil.h>
#include <avr/pgmspace.h>
//#include <PCF8575.h>
//#include <JeeLib.h>
#include <Base64.h>
#include <UIPEthernet.h>   // Comment this line to use the W5100.
//#include <SPI.h>           // Uncomment this line to use the W5100.
//#include <Ethernet.h>      // Uncomment this line to use the W5100

//****************************************************************************************************
//******************* Variables texts and sources ****************************************************
//****************************************************************************************************
#define LARGE true
#define SMALL false
extern uint8_t RusFont1[];    // Declares fonts used
extern uint8_t BigFont[];     // Declares fonts used
char buffer[50];

//****************************************************************************************************
//****************** Defines functions of digital and analog pins ************************************
//****************************************************************************************************
// Pins 0 and 1 reserved for serial port 0.
const byte alarmPin = 0;            // Pin to trigger alarm
const byte desativarFanPin = 1;     // Pin that disables the fan...................orange wire..Male DB9
// Pin 2 reserved for the INT RFM12B.
// Pins 3, 4, 5, 6 and 7 reserved for the Touch.
// Pin 5 is also the chip select the SD card.
const byte ledPinUV = 8;            // Pin violet LEDs.............................purple wire..Male DB9
const byte ledPinBlue = 9;          // Pin green LEDs..............................green wire...Male DB9
const byte ledPinWhite = 10;        // Pin white LEDs..............................grey wire....Male DB9
const byte ledPinRoyBlue = 11;      // Pin royal blue LEDs.........................blue wire....Male DB9
const byte ledPinRed = 12;          // Pin red LEDs................................red wire.....Male DB9
const byte fanPin = 13;             // Pin that controls the fan speed Heatsink....brown wire...Male DB9
// 14 & 15 pins reserved for serial port 3 that communicates with the "Stamps"
const byte multiplexadorS0Pin = 16; // Pin S0 control of stamps
const byte multiplexadorS1Pin = 17; // Pin S1 control of stamps
// 18 & 19 pins reserved for the RTC.
// 20 & 21 pins reserved for the PCF8575 I2C communication.
// Pins 22 ~ 41 reserved for LCD.
const byte aquecedorPin = 42;       // Pin heater..................................purple wire..........Female DB9...Relay channel 1
const byte chillerPin = 43;         // Pin chiller.................................red wire.............Female DB9...Relay channel 2
const byte ledPinMoon = 44;         // Pin moon light..............................yellow wire..Male DB9
const byte wavemaker1 = 45;         // Pin wavemaker 1
const byte wavemaker2 = 46;         // Pin wavemaker 2
const byte ozonizadorPin = 47;      // Pin ozone
const byte reatorPin = 48;          // Pin calcium reactor
const byte sensoresPin = 49;        // Pin one wire temperature sensors
// Pins 50, 51, & 52 reserved for SPI communication
// Pin 53 reserved for "slave select the ethernet shield.
const int sensor1 = A0;             // Analog pin that checks for voltage from the saltwater mixing tank float. // for the auto water change
const int sensor2 = A1;             // Analog pin that checks for voltage at the bottom of the sump float.      // for the auto water change
const int sensor3 = A2;             // Analog pin that checks for voltage at the top of the sump float.         // for the auto water change
const int sensor4 = A3;             // Analog pin that checks for voltage at the reservoir float.               // for the ATO container
const int sensor5 = A4;             // Analog pin that checks the level of the reef tank sump.                  // for the ATO 
const int sensor6 = A5;             // Analog pin that checks the level of the ATO reservoir.                   // for the ATO 
const int bomba1Pin = A6;           // Pump that draws water from saltwater mixing tank.                        // these pumps for the automatic water change system 
const int bomba2Pin = A7;           // Pump that draws water from the sump.                                     // these pumps for the automatic water change system 
const int bomba3Pin = A8;           // Pump that draws water from the reservoir to put in the sump.             // these pumps for the automatic water change system 
const int dosadora1 = A9;           // Dosing pump 1.....................................blue wire........Female DB9..Relay channel 3                                                          
const int dosadora2 = A10;          // Dosing pump 2.....................................grey wire........Female DB9..Relay channel 4                                                         
const int dosadora3 = A11;          // Dosing pump 3.....................................yellow wire......Female DB9..Relay channel 5                                                          
const int dosadora4 = A12;          // Dosing pump 4.....................................orange wire......Female DB9..Relay channel 6
const int dosadora5 = A13;          // Dosing pump 5.....................................brown wire.......Female DB9..Relay channel 7
const int dosadora6 = A14;          // Dosing pump 6.....................................green wire.......Female DB9..Relay channel 8
// Pin A15 reserved for SS RFM12B
//*****************************************************************************************************
//***************************************** PCF8575TS *************************************************
//*****************************************************************************************************
const byte temporizador1 = 80;      // P0   Pin for timer 1            
const byte temporizador2 = 81;      // P1   Pin for timer 2            
const byte temporizador3 = 82;      // P2   Pin for timer 3            
const byte temporizador4 = 83;      // P3   Pin for timer 4            
const byte temporizador5 = 84;      // P4   Pin for timer 5            
const byte solenoide1Pin = 85;      // P5   Connects to CO2 tank,Ca Rx 

//****************************************************************************************************
//********************** Variables of temperature sensors ********************************************
//****************************************************************************************************
OneWire OneWireBus(sensoresPin);         // Temperature sensor pin
DallasTemperature sensors(&OneWireBus);  // reference to OneWire temperature sensors.
DeviceAddress sensor_agua;               // Assigns the addresses of the temperature sensors.(water)
DeviceAddress sensor_dissipador;         // Assigns the addresses of the temperature sensors.(heatsink)
DeviceAddress sensor_ambiente;           // Assigns the addresses of the temperature sensors.(room/ambiente)
byte sonda_associada_1 = 1;
byte sonda_associada_2 = 2;
byte sonda_associada_3 = 3;

//****************************************************************************************************
//************************ Temporary variables of temperature sensors ********************************
//****************************************************************************************************
DeviceAddress tempDeviceAddress;   // Temporary address probe.
DeviceAddress sonda1;              // Temporary address probe1.
DeviceAddress sonda2;              // Temporary address probe2.
DeviceAddress sonda3;              // Temporary address probe3.
byte sonda_associada_1_temp = 0;
byte sonda_associada_2_temp = 0;
byte sonda_associada_3_temp = 0;

//*******************************************************************************************************
//********************** Functions of the RTC ***********************************************************
//*******************************************************************************************************
//       (SDA,SCL)
DS1307 rtc(20, 21);       // Indicates which pins are connected to the RTC.
Time t_temp, t;

//*******************************************************************************************************
//********************** VariÃƒÂ¡veis das fuÃƒÂ§ÃƒÂµes do touch screen e tela inicial ****************************
//*******************************************************************************************************
//UTFT        myGLCD(X, 38,39,40,41); // "X" is the screen you are using 
//UTFT        myGLCD(ITDB32WD, 38,39,40,41);
//UTFT        myGLCD(ITDB50, 38,39,40,41);
UTFT        myGLCD(CTE70, 38,39,40,41);
UTouch      myTouch(6,5,4,3,2); 
//UTouch      myTouch(7,6,5,4,3);

long previousMillis = 0;
byte data[56];
String day, ano; 
int whiteLed, blueLed, azulroyalLed, vermelhoLed, violetaLed;    // Previous value of PWM.
int dispScreen = 0;

//*****************************************************************************************
//*********************** parameters ******************************************************
//*****************************************************************************************
byte status_parametros = 0x0;
//bit 0;   // Signals that the heater is switched on / off
//bit 1;   // Signals that the chiller is switched on / off
//bit 2;   // Signals that the temperature alarm is active
//bit 3;   // Indicates that the PH of the tank is outside the specified
//bit 4;   // Indicates that the density is outside the specified
//bit 5;   // Signals that this CO2 on / off
//bit 6;   // Signals that the pH of the calcium reactor is outside the specified
//bit 7;   // Signals that the ozonator is on / off
byte status_parametros_1 = 0x0;
//bit 0    // Signals that the ORP is outside the specified

//*****************************************************************************************
//*********************** Variable water temperature control ******************************
//*****************************************************************************************
float tempC = 0;                 // Water temperature
//float setTempC = 25.5;           // desired temperature *C /******************************************************** changed for Fahrenheit *******************************************************************/
float setTempC = 78;             // desired temperature *F
float offTempC = 0.5;            // Permissible variation
float alarmTempC = 1;            // Variation to trigger the alarm for water temperature
int contador_temp = 0;
float temperatura_agua_temp = 0; // temporary temperature

//*****************************************************************************************
//****************** Variables controlling the pH of the aquarium *************************
//*****************************************************************************************
float PHA = 0;               // Aquarium pH
float setPHA = 0;            // Desired Aquarium pH
float offPHA = 0;            // Permissible variation
float alarmPHA = 0;          // Variation to trigger the alarm

//*****************************************************************************************
//*************************** Variable density control ************************************
//*****************************************************************************************
int DEN = 0;                 // Density
int setDEN = 1025;           // Desired Density
byte offDEN = 2;             // Permissible variation
byte alarmDEN = 1;           // Variation to trigger the alarm

//*****************************************************************************************
//************************ variables pH calcium reactor ***********************************
//*****************************************************************************************
float PHR = 0;               // Reactor pH
float setPHR = 0;            // Desired Reactor pH
float offPHR = 0;            // Permissible variation
float alarmPHR = 0;          // Variation to trigger the alarm

//*****************************************************************************************
//*************************** variables  ORP **********************************************
//*****************************************************************************************
int ORP = 0;                 // ORP
int setORP = 420;            // Desired ORP
byte offORP = 10;            // Permissible variation
byte alarmORP = 10;          // Variation to trigger the alarm

//*****************************************************************************************
//************************ Variable speed control of heatsink cooling fans ****************
//*****************************************************************************************
float HtempMin = 80;    // temperature to start the operation of the heatsink fan Ã‚Â°F scale
float HtempMax = 90;    // PWM fans should be at maximum speed when the sink is 90Ã‚Â°F
//float HtempMin = 30.5;    // temperature to start the operation of the heatsink fan Ã‚Â°c scale /******************************************************** changed for Fahrenheit *******************************************************************/
//float HtempMax = 40.5;    // PWM fans should be at maximum speed when the sink is 40Ã‚Â°c

//*****************************************************************************************
//**************** Temporary variable speed control of heatsink cooling fans **************
//*****************************************************************************************
float HtempMin_temp = 0;    // Declares the temperature to start the operation of the heatsink fans 
float HtempMax_temp = 0;    // Declares that the fans should be at maximum speed when the sink is 40Ã‚Â°c

//*****************************************************************************************
//*************************** Control variables of the heat sink temperature **************
//*****************************************************************************************
float tempH = 0;    // Heatsink temperature
byte tempHR =95;   // Temperature to reduce power of leds Ã‚Â°F scale
//byte tempHR = 60;   // Temperature to reduce power of leds Ã‚Â°C scale  /******************************************************** changed for Fahrenheit *******************************************************************/
byte potR = 30;     // Percentage to be reduced.



//*****************************************************************************************
//*********** Temporary variables control the heat sink temperature ***********************
//*****************************************************************************************
float temperatura_dissipador_temp = 0; // temporary temperature
byte tempHR_t = 0;                     // Temporary temperature to reduce power of leds
byte potR_t = 0;                       // Temporary percentage to be reduced.
boolean temperatura_alta = false;      // Signals that the temperature of the LEDs is high.
boolean temperatura_baixou = false;    // Signals that the temperature of the LEDs was high.

//*****************************************************************************************
//************************ Temporary variables to control water temperature ***************
//*****************************************************************************************
float temp2beS;           
float temp2beO;
float temp2beA;

//*****************************************************************************************
//************************ Temporary variables control the pH of calcium reactor **********
//*****************************************************************************************
float PHR2beS;             
float PHR2beO;
float PHR2beA;

//*****************************************************************************************
//************************ Temporary variables control the pH of the aquarium *************
//*****************************************************************************************
float PHA2beS;             
float PHA2beO;
float PHA2beA;

//*****************************************************************************************
//************************ Temporary control variables of ORP *****************************
//*****************************************************************************************
int ORP2beS;               // temporary orp
byte ORP2beO;
byte ORP2beA;

//*****************************************************************************************
//************************ Temporary variables control the density *****************
//*****************************************************************************************
int DEN2beS;            
byte DEN2beO;
byte DEN2beA;

//*****************************************************************************************
//************************ Control variables lighting *************************************
//*****************************************************************************************
int LedChangTime = 0;             // Change page of the LED's, and time valuesÃ¢â‚¬â€¹Ã¢â‚¬â€¹.
boolean MeanWell = true;          // If using drivers whose maximum power is obtained by applying zero volts and 5 volts is minimal change "true" to "false".
boolean LEDtestTick = false;      // Accelerate time during testing of LEDs.
int min_cnt ;
byte bled_out;
byte wled_out;
byte rbled_out;
byte rled_out;
byte uvled_out;
byte bled_out_temp;
byte wled_out_temp;
byte rbled_out_temp;
byte rled_out_temp;
byte uvled_out_temp;
byte moonled_out;
boolean periodo_selecionado = false;
int y_tocado;
boolean teste_em_andamento = false;
byte cor_selecionada = 0;
// bit 1 = led white
// bit 2 = led green // blue in the program, I changed to green
// bit 3 = led blue  // royal blue
// bit 4 = led red
// bit 5 = led violet
byte setor_selecionado = 0;
boolean mensagem = true;
float suavizar = 0.0; // LEDs start smoothly and reaches the specified value in 50 seconds.
byte predefinido = 0;
byte pre_definido_ativado = 0;
byte pwm_pre_definido = 0;
byte led_on_minuto; // Time to turn on leds.
byte led_on_hora;
byte led_off_minuto; // Time to turn off leds.
byte led_off_hora;
boolean horario_alterado = false;
boolean hora_modificada = false;
byte amanhecer_anoitecer = 60;
boolean teste_iniciado = false;

//*****************************************************************************************
//**************** Temporary variables to control lighting ************************
//*****************************************************************************************
byte predefinido_t = 0;
byte pre_definido_ativado_t = 0;
byte pwm_pre_definido_t = 0;
byte led_on_minuto_t;           // temporary schedule
byte led_on_hora_t;
byte led_off_minuto_t;
byte led_off_hora_t;
byte amanhecer_anoitecer_t = 0;

//*****************************************************************************************
//************************* LED design RGB channel colors *********************************
//*****************************************************************************************     
byte cor_canal1[] = {
  230, 246, 255};   // Cool White 
byte cor_canal2[] = {
50,205,50};         // Green
byte cor_canal3[] = {
  65,105,225};      // Royal Blue
byte cor_canal4[] = {
  255, 0, 0};       // Red
byte cor_canal5[] = {
  238,130,238};     // Violet

//*****************************************************************************************
//************************ Variables lunar phase ******************************************
//*****************************************************************************************
String LP;
byte MaxI , tMaxI;  // Maximum power at the full moon.             
byte MinI, tMinI;   // Maximum power at the new moon.

//*****************************************************************************************
//************************ Variables automatic AWC ****************************************
//*****************************************************************************************
byte hora = 0;
byte minuto = 0;
byte duracaomaximatpa = 0;
byte segunda = 0;
byte terca = 0;
byte quarta = 0;
byte quinta = 0;
byte sexta = 0;
byte sabado = 0;
byte domingo = 0;
byte tpa = 0;                             // Controls the automatic stages of AWC
byte tpa_status = 0x0; // 0 = false e 1 = true
// bit 1 = Automatic signals AWC in progress
// bit 2 = Signals failure during automatic AWC        
unsigned long tempo = 0;                 // Duration of each stage of AWC automatic
unsigned long marcadoriniciotpa = 0;   // Prevent a tpa millis start near the zero
unsigned long shiftedmillis = 0;       // Prevent a tpa millis start near the zero

//*****************************************************************************************
//************* Automatic temporary variables AWC (Partial Exchange of Water) *************
//*****************************************************************************************
byte temp2hora;
byte temp2minuto;
byte temp2duracaomaximatpa;
byte temp2segunda;
byte temp2terca;
byte temp2quarta;
byte temp2quinta;
byte temp2sexta;
byte temp2sabado;
byte temp2domingo;

//****************************************************************************************
//*********************** Control variables of the functions that use the SD Card ********
//****************************************************************************************
Sd2Card card;
SdFile file;
SdFile root;
SdVolume volume;
char time1;
char time2;
char time3;
char time4;
char time5;

//*****************************************************************************************
//*********************** Variable control levels **********************************
//*****************************************************************************************
boolean nivel_status = 0;             // Signals of a low level of aquariums

//*****************************************************************************************
//************************ Variable control of replenishment of freshwater *****************
//*****************************************************************************************
byte Status = 0x0;
// bit 1 // Replenishment signals on / off
// bit 2 
// bit 3 

//*****************************************************************************************
//************************* Functions ethernet shield ************************************
//*****************************************************************************************
boolean Ethernet_Shield = true;                     // Change to "false" if you do not have an Ethernet Shield connected to Arduino.

char *credencial = "username:password";              // Put here your username and password registered on www.joy-reef.com. User and password should be separated by a colon (:);
                                                    // Use lowercase apena.
                                              
byte maxima_tentativa = 3;                          // Maximum number of authentication attempts.
unsigned long intervalo_tentativa = 15;             // Time to wait (in minutes) to retry.

byte mac[] = { 0x54, 0x55, 0x58, 0x10, 0x00, 0x26 }; // The MAC must be unique on your local network.

byte ip[] = {192,168,0, 0};                         // ENC28J60 Ethernet Shield--Configure the IP as its local network.

IPAddress gateway(192,168,0,1);                     // Configure the "Gateway" as your local network.
IPAddress subnet(255, 255, 255, 0);                 // Configure the network mask according to your local network.

EthernetServer server(21);                          // Put here the number of configured port on your router for redirection.
                                                    // The port number should be obligatorily of these: 21, 25, 53, 80, 110, 143 or 443.
                          
unsigned long intervalo = 0;
char *inParse[50];
boolean web_teste = false;
byte tentativa = 0;
boolean web_dosage = false;
unsigned long millis_dosagem = 0;
boolean web_calibracao = false;

//*****************************************************************************************
//************************** Control variables multiplexer ***********************
//*****************************************************************************************
boolean Stamps = false;     // Change to "false" if you do not have at least one of pH, ORP and EC Atlas Scientific circuits.
long millis_antes = 0;
int DENT;                   // Densidade temporÃƒÂ¡ria.
float PHT;                  // PH temporÃƒÂ¡rio.
int ORPT;                   // ORP temporÃƒÂ¡ria
char sensorstring[15];
byte holding;
short ph1=0;      // Y0
short ph2=1;      // Y1
short orp=2;      // Y2
short ec=3;       // Y3
int done = 0;

//*****************************************************************************************
//************************** Variables password request ***********************************
//*****************************************************************************************
char stCurrent[7]="";
char limpar_senha [7] = "";
byte stCurrentLen=0;
char senha [7] = {'\0'}; // Enter your password here. The character '\ 0' should not be changed.
//char senha [7] = {'0','1','2','8','6','7','\0'}; // my birth date

//*****************************************************************************************
//************************** dosing variables ******************************************
//*****************************************************************************************
boolean dosadoras = false; //Altere para "false" caso nÃƒÂ£o tenha as dosadoras.
char *arquivo[6] = {"HDP1.TXT","HDP2.TXT","HDP3.TXT","HDP4.TXT","HDP5.TXT","HDP6.TXT"};

float fator_calib_dosadora_1 = 35.1; // Initial calibration factor 
float fator_calib_dosadora_2 = 35.2; // Initial calibration factor  
float fator_calib_dosadora_3 = 35.3; // Initial calibration factor  
float fator_calib_dosadora_4 = 35.4; // Initial calibration factor  
float fator_calib_dosadora_5 = 35.5; // Initial calibration factor  
float fator_calib_dosadora_6 = 35.6; // Initial calibration factor  
float dose_dosadora_1_personalizada = 100.0;
float dose_dosadora_2_personalizada = 100.0;
float dose_dosadora_3_personalizada = 100.0;
float dose_dosadora_4_personalizada = 100.0;
float dose_dosadora_5_personalizada = 100.0;
float dose_dosadora_6_personalizada = 100.0;
char time9;
char time10;
char time11;
char time15;
char time16;
char time17;
long tempo_dosagem = 0;
float dose_dosadora_1_manual = 20.0; // Dose predefined.
float dose_dosadora_2_manual = 20.0; // Dose predefined.
float dose_dosadora_3_manual = 20.0; // Dose predefined.
float dose_dosadora_4_manual = 20.0; // Dose predefined.
float dose_dosadora_5_manual = 20.0; // Dose predefined.
float dose_dosadora_6_manual = 20.0; // Dose predefined.
boolean modo_manual = false;
boolean modo_personalizado = false;
boolean modo_calibrar = false;
byte dosadora_selecionada = 0; // 0 = false, 1 = true
byte dosadora[6] = {dosadora1, dosadora2, dosadora3, dosadora4, dosadora5, dosadora6};
byte ativar_desativar = 0x0;     // 0 = false, 1 = true
byte modo_personalizado_on_1 = 0;
byte modo_personalizado_on_2 = 0;
byte modo_personalizado_on_3 = 0;
byte modo_personalizado_on_4 = 0;
byte modo_personalizado_on_5 = 0;
byte modo_personalizado_on_6 = 0;
byte segunda_dosagem_personalizada_1 = 0;
byte segunda_dosagem_personalizada_2 = 0;
byte segunda_dosagem_personalizada_3 = 0;
byte segunda_dosagem_personalizada_4 = 0;
byte segunda_dosagem_personalizada_5 = 0;
byte segunda_dosagem_personalizada_6 = 0;
byte hora_inicial_dosagem_personalizada_1 = 0;
byte minuto_inicial_dosagem_personalizada_1 = 0;
byte hora_final_dosagem_personalizada_1 = 0;
byte minuto_final_dosagem_personalizada_1 = 0;
byte terca_dosagem_personalizada_1 = 0;
byte quarta_dosagem_personalizada_1 = 0;
byte quinta_dosagem_personalizada_1 = 0;
byte sexta_dosagem_personalizada_1 = 0;
byte sabado_dosagem_personalizada_1 = 0;
byte domingo_dosagem_personalizada_1 = 0;
byte hora_inicial_dosagem_personalizada_2 = 0;
byte minuto_inicial_dosagem_personalizada_2 = 0;
byte hora_final_dosagem_personalizada_2 = 0;
byte minuto_final_dosagem_personalizada_2 = 0;
byte terca_dosagem_personalizada_2 = 0;
byte quarta_dosagem_personalizada_2 = 0;
byte quinta_dosagem_personalizada_2 = 0;
byte sexta_dosagem_personalizada_2 = 0;
byte sabado_dosagem_personalizada_2 = 0;
byte domingo_dosagem_personalizada_2 = 0;
byte hora_inicial_dosagem_personalizada_3 = 0;
byte minuto_inicial_dosagem_personalizada_3 = 0;
byte hora_final_dosagem_personalizada_3 = 0;
byte minuto_final_dosagem_personalizada_3 = 0;
byte terca_dosagem_personalizada_3 = 0;
byte quarta_dosagem_personalizada_3 = 0;
byte quinta_dosagem_personalizada_3 = 0;
byte sexta_dosagem_personalizada_3 = 0;
byte sabado_dosagem_personalizada_3 = 0;
byte domingo_dosagem_personalizada_3 = 0;
byte quantidade_dose_dosadora_1_personalizada = 0;
byte quantidade_dose_dosadora_2_personalizada = 0;
byte quantidade_dose_dosadora_3_personalizada = 0;
byte hora_inicial_dosagem_personalizada_4 = 0;
byte minuto_inicial_dosagem_personalizada_4 = 0;
byte hora_final_dosagem_personalizada_4 = 0;
byte minuto_final_dosagem_personalizada_4 = 0;
byte terca_dosagem_personalizada_4 = 0;
byte quarta_dosagem_personalizada_4 = 0;
byte quinta_dosagem_personalizada_4 = 0;
byte sexta_dosagem_personalizada_4 = 0;
byte sabado_dosagem_personalizada_4 = 0;
byte domingo_dosagem_personalizada_4 = 0;
byte hora_inicial_dosagem_personalizada_5 = 0;
byte minuto_inicial_dosagem_personalizada_5 = 0;
byte hora_final_dosagem_personalizada_5 = 0;
byte minuto_final_dosagem_personalizada_5 = 0;
byte terca_dosagem_personalizada_5 = 0;
byte quarta_dosagem_personalizada_5 = 0;
byte quinta_dosagem_personalizada_5 = 0;
byte sexta_dosagem_personalizada_5 = 0;
byte sabado_dosagem_personalizada_5 = 0;
byte domingo_dosagem_personalizada_5 = 0;
int hora_inicial_dosagem_personalizada_6 = 0;
byte minuto_inicial_dosagem_personalizada_6 = 0;
byte hora_final_dosagem_personalizada_6 = 0;
byte minuto_final_dosagem_personalizada_6 = 0;
byte terca_dosagem_personalizada_6 = 0;
byte quarta_dosagem_personalizada_6 = 0;
byte quinta_dosagem_personalizada_6 = 0;
byte sexta_dosagem_personalizada_6 = 0;
byte sabado_dosagem_personalizada_6 = 0;
byte domingo_dosagem_personalizada_6 = 0;
byte quantidade_dose_dosadora_4_personalizada = 0;
byte quantidade_dose_dosadora_5_personalizada = 0;
byte quantidade_dose_dosadora_6_personalizada = 0;

//*****************************************************************************************
//************************** Temporary variables of dosing ********************************
//*****************************************************************************************
byte  modo_personalizado_on_1_temp2;
byte  modo_personalizado_on_2_temp2;
byte  modo_personalizado_on_3_temp2;
byte  modo_personalizado_on_4_temp2;
byte  modo_personalizado_on_5_temp2;
byte  modo_personalizado_on_6_temp2;
float fator_calib_dosadora_1_temp2;
float fator_calib_dosadora_2_temp2;
float fator_calib_dosadora_3_temp2;
float dose_dosadora_1_personalizada_temp2;
float dose_dosadora_2_personalizada_temp2;
float dose_dosadora_3_personalizada_temp2;
byte temp2hora_inicial_dosagem_personalizada_1;
byte temp2minuto_inicial_dosagem_personalizada_1;
byte temp2hora_final_dosagem_personalizada_1;
byte temp2minuto_final_dosagem_personalizada_1;
byte temp2segunda_dosagem_personalizada_1;
byte temp2terca_dosagem_personalizada_1;
byte temp2quarta_dosagem_personalizada_1;
byte temp2quinta_dosagem_personalizada_1;
byte temp2sexta_dosagem_personalizada_1;
byte temp2sabado_dosagem_personalizada_1;
byte temp2domingo_dosagem_personalizada_1;
byte temp2hora_inicial_dosagem_personalizada_2;
byte temp2minuto_inicial_dosagem_personalizada_2;
byte temp2hora_final_dosagem_personalizada_2;
byte temp2minuto_final_dosagem_personalizada_2;
byte temp2segunda_dosagem_personalizada_2;
byte temp2terca_dosagem_personalizada_2;
byte temp2quarta_dosagem_personalizada_2;
byte temp2quinta_dosagem_personalizada_2;
byte temp2sexta_dosagem_personalizada_2;
byte temp2sabado_dosagem_personalizada_2;
byte temp2domingo_dosagem_personalizada_2;
byte temp2hora_inicial_dosagem_personalizada_3;
byte temp2minuto_inicial_dosagem_personalizada_3;
byte temp2hora_final_dosagem_personalizada_3;
byte temp2minuto_final_dosagem_personalizada_3;
byte temp2segunda_dosagem_personalizada_3;
byte temp2terca_dosagem_personalizada_3;
byte temp2quarta_dosagem_personalizada_3;
byte temp2quinta_dosagem_personalizada_3;
byte temp2sexta_dosagem_personalizada_3;
byte temp2sabado_dosagem_personalizada_3;
byte temp2domingo_dosagem_personalizada_3;
byte quantidade_dose_dosadora_1_personalizada_temp2;
byte quantidade_dose_dosadora_2_personalizada_temp2;
byte quantidade_dose_dosadora_3_personalizada_temp2;
float fator_calib_dosadora_4_temp2;
float fator_calib_dosadora_5_temp2;
float fator_calib_dosadora_6_temp2;
float dose_dosadora_4_personalizada_temp2;
float dose_dosadora_5_personalizada_temp2;
float dose_dosadora_6_personalizada_temp2;
byte temp2hora_inicial_dosagem_personalizada_4;
byte temp2minuto_inicial_dosagem_personalizada_4;
byte temp2hora_final_dosagem_personalizada_4;
byte temp2minuto_final_dosagem_personalizada_4;
byte temp2segunda_dosagem_personalizada_4;
byte temp2terca_dosagem_personalizada_4;
byte temp2quarta_dosagem_personalizada_4;
byte temp2quinta_dosagem_personalizada_4;
byte temp2sexta_dosagem_personalizada_4;
byte temp2sabado_dosagem_personalizada_4;
byte temp2domingo_dosagem_personalizada_4;
byte temp2hora_inicial_dosagem_personalizada_5;
byte temp2minuto_inicial_dosagem_personalizada_5;
byte temp2hora_final_dosagem_personalizada_5;
byte temp2minuto_final_dosagem_personalizada_5;
byte temp2segunda_dosagem_personalizada_5;
byte temp2terca_dosagem_personalizada_5;
byte temp2quarta_dosagem_personalizada_5;
byte temp2quinta_dosagem_personalizada_5;
byte temp2sexta_dosagem_personalizada_5;
byte temp2sabado_dosagem_personalizada_5;
byte temp2domingo_dosagem_personalizada_5;
byte temp2hora_inicial_dosagem_personalizada_6;
byte temp2minuto_inicial_dosagem_personalizada_6;
byte temp2hora_final_dosagem_personalizada_6;
byte temp2minuto_final_dosagem_personalizada_6;
byte temp2segunda_dosagem_personalizada_6;
byte temp2terca_dosagem_personalizada_6;
byte temp2quarta_dosagem_personalizada_6;
byte temp2quinta_dosagem_personalizada_6;
byte temp2sexta_dosagem_personalizada_6;
byte temp2sabado_dosagem_personalizada_6;
byte temp2domingo_dosagem_personalizada_6;
byte quantidade_dose_dosadora_4_personalizada_temp2;
byte quantidade_dose_dosadora_5_personalizada_temp2;
byte quantidade_dose_dosadora_6_personalizada_temp2;

byte hora_inicial_dosagem_personalizada[6] = {
  temp2hora_inicial_dosagem_personalizada_1, temp2hora_inicial_dosagem_personalizada_2, temp2hora_inicial_dosagem_personalizada_3,
  temp2hora_inicial_dosagem_personalizada_4, temp2hora_inicial_dosagem_personalizada_5, temp2hora_inicial_dosagem_personalizada_6};
  
byte minuto_inicial_dosagem_personalizada[6] = {
  temp2minuto_inicial_dosagem_personalizada_1, temp2minuto_inicial_dosagem_personalizada_1, temp2minuto_inicial_dosagem_personalizada_1,
  temp2minuto_inicial_dosagem_personalizada_1, temp2minuto_inicial_dosagem_personalizada_1,temp2minuto_inicial_dosagem_personalizada_1};
  
byte hora_final_dosagem_personalizada[6] = {
  temp2hora_final_dosagem_personalizada_1, temp2hora_final_dosagem_personalizada_2, temp2hora_final_dosagem_personalizada_3,
  temp2hora_final_dosagem_personalizada_4, temp2hora_final_dosagem_personalizada_5, temp2hora_final_dosagem_personalizada_6};
  
byte minuto_final_dosagem_personalizada[6] = {
  temp2minuto_final_dosagem_personalizada_1, temp2minuto_final_dosagem_personalizada_1, temp2minuto_final_dosagem_personalizada_1,
  temp2minuto_final_dosagem_personalizada_1, temp2minuto_final_dosagem_personalizada_1,temp2minuto_final_dosagem_personalizada_1};

byte segunda_dosagem_personalizada[6] = {
  temp2segunda_dosagem_personalizada_1, temp2segunda_dosagem_personalizada_2, temp2segunda_dosagem_personalizada_3,
  temp2segunda_dosagem_personalizada_4, temp2segunda_dosagem_personalizada_5, temp2segunda_dosagem_personalizada_6};
  
byte terca_dosagem_personalizada[6] = {
  temp2terca_dosagem_personalizada_1, temp2terca_dosagem_personalizada_2, temp2terca_dosagem_personalizada_3,
  temp2terca_dosagem_personalizada_4, temp2terca_dosagem_personalizada_5, temp2terca_dosagem_personalizada_6};
  
byte quarta_dosagem_personalizada[6] = {
  temp2quarta_dosagem_personalizada_1, temp2quarta_dosagem_personalizada_2, temp2quarta_dosagem_personalizada_3,
  temp2quarta_dosagem_personalizada_4, temp2quarta_dosagem_personalizada_5, temp2quarta_dosagem_personalizada_6}; 
  
byte quinta_dosagem_personalizada[6] = {
  temp2quinta_dosagem_personalizada_1, temp2quinta_dosagem_personalizada_2, temp2quinta_dosagem_personalizada_3,
  temp2quinta_dosagem_personalizada_4, temp2quinta_dosagem_personalizada_5, temp2quinta_dosagem_personalizada_6};
  
byte sexta_dosagem_personalizada[6] = {
  temp2sexta_dosagem_personalizada_1, temp2sexta_dosagem_personalizada_2, temp2sexta_dosagem_personalizada_3,
  temp2sexta_dosagem_personalizada_4, temp2sexta_dosagem_personalizada_5, temp2sexta_dosagem_personalizada_6};
  
byte sabado_dosagem_personalizada[6] = {
  temp2sabado_dosagem_personalizada_1, temp2sabado_dosagem_personalizada_2, temp2sabado_dosagem_personalizada_3,
  temp2sabado_dosagem_personalizada_4, temp2sabado_dosagem_personalizada_5, temp2sabado_dosagem_personalizada_6};
  
byte domingo_dosagem_personalizada[6] = {
  temp2domingo_dosagem_personalizada_1, temp2domingo_dosagem_personalizada_2, temp2domingo_dosagem_personalizada_3,
  temp2domingo_dosagem_personalizada_4, temp2domingo_dosagem_personalizada_5, temp2domingo_dosagem_personalizada_6};

float dose_dosadora_personalizada[6] = {
  dose_dosadora_1_personalizada_temp2, dose_dosadora_2_personalizada_temp2, dose_dosadora_3_personalizada_temp2,
  dose_dosadora_4_personalizada_temp2, dose_dosadora_5_personalizada_temp2, dose_dosadora_6_personalizada_temp2};

byte quantidade_dose_dosadora_personalizada[6] = {
  quantidade_dose_dosadora_1_personalizada_temp2, quantidade_dose_dosadora_2_personalizada_temp2, quantidade_dose_dosadora_3_personalizada_temp2,
  quantidade_dose_dosadora_4_personalizada_temp2, quantidade_dose_dosadora_5_personalizada_temp2, quantidade_dose_dosadora_6_personalizada_temp2};

byte modo_personalizado_on[6] = {
  modo_personalizado_on_1_temp2, modo_personalizado_on_1_temp2, modo_personalizado_on_1_temp2,
  modo_personalizado_on_1_temp2, modo_personalizado_on_1_temp2, modo_personalizado_on_1_temp2};
  
float dose_dosadora_manual[6] = {
  dose_dosadora_1_manual, dose_dosadora_2_manual, dose_dosadora_3_manual, dose_dosadora_4_manual, dose_dosadora_5_manual, dose_dosadora_6_manual};
  
float fator_calib_dosadora[6] = {
  fator_calib_dosadora_1, fator_calib_dosadora_2, fator_calib_dosadora_3, fator_calib_dosadora_4, fator_calib_dosadora_5, fator_calib_dosadora_6};
//*****************************************************************************************
//************************** Variables of timers *****************************************
//*****************************************************************************************
byte temporizador = 0;
byte temporizador_status = 0x0; // 1 = true e 0 = false
//bit 1 = temporizador 1
//bit 2 = temporizador 2
//bit 3 = temporizador 3
//bit 4 = temporizador 4
//bit 5 = temporizador 5
byte temporizador_modificado = 0x0;
//bit 1 = temporizador 1
//bit 2 = temporizador 2
//bit 3 = temporizador 3
//bit 4 = temporizador 4
//bit 5 = temporizador 5
byte temporizador_1_ativado = 0;
byte temporizador_2_ativado = 0;
byte temporizador_3_ativado = 0;
byte temporizador_4_ativado= 0;
byte temporizador_5_ativado= 0;
byte on1_minuto = 0;
byte on1_hora = 0;
byte on2_minuto = 0;
byte on2_hora = 0;
byte on3_minuto = 0;
byte on3_hora = 0;
byte on4_minuto = 0;
byte on4_hora = 0;
byte on5_minuto = 0;
byte on5_hora = 0;
byte off1_minuto = 0;
byte off1_hora = 0;
byte off2_minuto = 0;
byte off2_hora = 0;
byte off3_minuto = 0;
byte off3_hora = 0;
byte off4_minuto = 0;
byte off4_hora = 0;
byte off5_minuto = 0;
byte off5_hora= 0;

//*****************************************************************************************
//************************** Temporary variables of timers ********************************
//*****************************************************************************************
byte on1_minuto_temp2;
byte on1_hora_temp2;
byte on2_minuto_temp2;
byte on2_hora_temp2;
byte on3_minuto_temp2;
byte on3_hora_temp2;
byte on4_minuto_temp2;
byte on4_hora_temp2;
byte on5_minuto_temp2;
byte on5_hora_temp2;
byte off1_minuto_temp2;
byte off1_hora_temp2;
byte off2_minuto_temp2;
byte off2_hora_temp2;
byte off3_minuto_temp2;
byte off3_hora_temp2;
byte off4_minuto_temp2;
byte off4_hora_temp2;
byte off5_minuto_temp2;
byte off5_hora_temp2;
byte temporizador_1_ativado_temp2;
byte temporizador_2_ativado_temp2;
byte temporizador_3_ativado_temp2;
byte temporizador_4_ativado_temp2;
byte temporizador_5_ativado_temp2;

byte on_hora[5] = {on1_hora_temp2, on2_hora_temp2, on3_hora_temp2, on4_hora_temp2, on5_hora_temp2};
byte on_minuto[5] = {on1_minuto_temp2, on2_minuto_temp2, on3_minuto_temp2, on4_minuto_temp2, on5_minuto_temp2};
byte off_hora[5] = {off1_hora_temp2, off2_hora_temp2, off3_hora_temp2, off4_hora_temp2, off5_hora_temp2};
byte off_minuto[5] = {off1_minuto_temp2, off2_minuto_temp2, off3_minuto_temp2, off4_minuto_temp2, off5_minuto_temp2};
byte temporizador_ativado[5] = {temporizador_1_ativado_temp2, temporizador_2_ativado_temp2, temporizador_3_ativado_temp2, temporizador_4_ativado_temp2, temporizador_5_ativado_temp2};

//*****************************************************************************************
//************************** Variables PCF8575 ********************************************
//*****************************************************************************************
/*boolean PCF8575TS_S = false;   // Change to "false" if you do not have a PCF8575
 byte endereco_PCF8575TS = 0x20; // Address in hex = 0x20
 PCF8575 PCF8575;*/
 
//*****************************************************************************************
//************************** RF communication *********************************************
//*****************************************************************************************
byte consumo = 0;
/*boolean RFM12B = false;     // Change to "false" if you do not have a RFM12B
 #define myNodeID 30          // Caller ID (range 0-30) 
 #define network     210      // Group (may be in the range 1-250).
 #define freq RF12_915MHZ     // Frequency can be RF12B RF12_433MHZ, RF12_868MHZ or RF12_915MHZ. Corresponds to frequency module
 typedef struct { int power1, power2, power3, battery; } PayloadTX;      // Create a framework
 PayloadTX emontx;  
 const byte emonTx_NodeID = 10;            // ID do receptor*/

//*****************************************************************************************
//************************** SPI devices **************************************************
//*****************************************************************************************
const byte SD_CARD = 0; 
const byte ETHER_CARD = 1;
const byte RFM = 2;
const byte ChipSelect_SD = 4;            
const byte SelectSlave_ETH = 53;
const int ChipSelect_RFM = A15;

//*****************************************************************************************
//************************* Variables room temperature *****************************
//*****************************************************************************************
float tempA = 0; // Temperatura ambiente
float temperatura_ambiente_temp = 0; // Temperatura temporÃƒÂ¡ria

//*****************************************************************************************
//************************* Variables of circulators ****************************
//*****************************************************************************************
byte modo_selecionado = 1; 
byte Pump1PWM_temp = 0;    
byte Pump2PWM_temp = 0;
int periodo = 3500; // default setting 100000 
int duracao = 5000; //Cycle time in milliseconds for mode 3.
long millis_antes_1 = 0;
byte conta = 0;
byte Pump1PWM = 0;    
byte Pump2PWM = 0;
//*****************************************************************************************
//************************** Control variables power leds *******************
//*****************************************************************************************
byte wled[96] = {                         //Output of white LEDs Power 255 = 100% power
  0, 0, 0, 0, 0, 0, 0, 0,       // 0 e 2
  0, 0, 0, 0, 0, 0, 0, 0,       // 2 e 4
  0, 0, 0, 0, 12, 21, 30, 39,       // 4 e 6
  48, 57, 66, 75, 84, 93, 102, 111,     // 6 e 8 
  120, 129, 138, 147, 156, 165, 174, 183, // 8 e 10
  192, 201, 210, 219, 228, 237, 246, 255, // 10 e 12
  255, 246, 237, 228, 219, 210, 201, 192, // 12 e 14
  183, 174, 165, 156, 147, 138, 129, 120,  // 14 e 16
  111, 102, 93, 84, 75, 66, 57, 48,       // 16 e 18
  39, 30, 21, 12, 0, 0, 0, 0,         // 18 a 20
  0, 0, 0, 0, 0, 0, 0, 0,         // 20 e 22
  0, 0, 0, 0, 0, 0, 0, 0          // 22 a 0
};

byte bled[96] = {                       // Output of blue LEDs Power 255 = 100% power
  0, 0, 0, 0, 0, 0, 0, 0,       // 0 e 2
  0, 0, 0, 0, 0, 0, 0, 0,       // 2 e 4
  0, 0, 0, 0, 12, 21, 30, 39,       // 4 e 6
  48, 57, 66, 75, 84, 93, 102, 111,     // 6 e 8 
  120, 129, 138, 147, 156, 165, 174, 183, // 8 e 10
  192, 201, 210, 219, 228, 237, 246, 255, // 10 e 12
  255, 246, 237, 228, 219, 210, 201, 192, // 12 e 14
  183, 174, 165, 156, 147, 138, 129, 120,  // 14 e 16
  111, 102, 93, 84, 75, 66, 57, 48,       // 16 e 18
  39, 30, 21, 12, 0, 0, 0, 0,         // 18 a 20
  0, 0, 0, 0, 0, 0, 0, 0,         // 20 e 22
  0, 0, 0, 0, 0, 0, 0, 0          // 22 a 0
};  

byte rbled[96] = {                         // Output of royal blue LEDs Power 255 = 100% power
  0, 0, 0, 0, 0, 0, 0, 0,       // 0 e 2
  0, 0, 0, 0, 0, 0, 0, 0,       // 2 e 4
  0, 0, 0, 0, 12, 21, 30, 39,       // 4 e 6
  48, 57, 66, 75, 84, 93, 102, 111,     // 6 e 8 
  120, 129, 138, 147, 156, 165, 174, 183, // 8 e 10
  192, 201, 210, 219, 228, 237, 246, 255, // 10 e 12
  255, 246, 237, 228, 219, 210, 201, 192, // 12 e 14
  183, 174, 165, 156, 147, 138, 129, 120,  // 14 e 16
  111, 102, 93, 84, 75, 66, 57, 48,       // 16 e 18
  39, 30, 21, 12, 0, 0, 0, 0,         // 18 a 20
  0, 0, 0, 0, 0, 0, 0, 0,         // 20 e 22
  0, 0, 0, 0, 0, 0, 0, 0          // 22 a 0
};
byte rled[96] = {                         // Output of red LEDs Power 255 = 100% power
  0, 0, 0, 0, 0, 0, 0, 0,       // 0 e 2
  0, 0, 0, 0, 0, 0, 0, 0,       // 2 e 4
  0, 0, 0, 0, 12, 21, 30, 39,       // 4 e 6
  48, 57, 66, 75, 84, 93, 102, 111,     // 6 e 8 
  120, 129, 138, 147, 156, 165, 174, 183, // 8 e 10
  192, 201, 210, 219, 228, 237, 246, 255, // 10 e 12
  255, 246, 237, 228, 219, 210, 201, 192, // 12 e 14
  183, 174, 165, 156, 147, 138, 129, 120,  // 14 e 16
  111, 102, 93, 84, 75, 66, 57, 48,       // 16 e 18
  39, 30, 21, 12, 0, 0, 0, 0,         // 18 a 20
  0, 0, 0, 0, 0, 0, 0, 0,         // 20 e 22
  0, 0, 0, 0, 0, 0, 0, 0          // 22 a 0
};
byte uvled[96] = {                         // Output of white LEDs Power 255 = 100% power
  0, 0, 0, 0, 0, 0, 0, 0,       // 0 e 2
  0, 0, 0, 0, 0, 0, 0, 0,       // 2 e 4
  0, 0, 0, 0, 12, 21, 30, 39,       // 4 e 6
  48, 57, 66, 75, 84, 93, 102, 111,     // 6 e 8 
  120, 129, 138, 147, 156, 165, 174, 183, // 8 e 10
  192, 201, 210, 219, 228, 237, 246, 255, // 10 e 12
  255, 246, 237, 228, 219, 210, 201, 192, // 12 e 14
  183, 174, 165, 156, 147, 138, 129, 120,  // 14 e 16
  111, 102, 93, 84, 75, 66, 57, 48,       // 16 e 18
  39, 30, 21, 12, 0, 0, 0, 0,         // 18 a 20
  0, 0, 0, 0, 0, 0, 0, 0,         // 20 e 22
  0, 0, 0, 0, 0, 0, 0, 0          // 22 a 0
};

byte *cor[5] = {wled, bled, rbled, rled, uvled};
byte *cor_canal[5] = {cor_canal1, cor_canal2, cor_canal3, cor_canal4, cor_canal5};





