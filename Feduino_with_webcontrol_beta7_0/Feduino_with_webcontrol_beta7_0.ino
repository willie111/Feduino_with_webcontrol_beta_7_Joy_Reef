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
//*************************************************************************************************
//*************************************************************************************************


// Uncomment the line Corresponding to your language

#define ENGLISH       // If this program is useful for you, make a donation to help with development. Paypal: fefegarcia_1@hotmail.com
// #define FRENCH     // Si ce programme est utile pour vous, faire un don pour aider au développement. Paypal: fefegarcia_1@hotmail.com
// #define GERMAN     // Wenn dieses Programm ist nützlich für Sie, eine Spende an mit Entwicklung zu helfen. Paypal: fefegarcia_1@hotmail.com
// #define ITALIAN    // Se questo programma è utile per voi, fare una donazione per aiutare con lo sviluppo. Paypal: fefegarcia_1@hotmail.com
//#define PORTUGUESE   // Se este programa é útil para você, faça uma doação para ajudar no desenvolvimento. Paypal: fefegarcia_1@hotmail.com
// #define SPANISH    // Si este programa es útil para usted, hacer una donación para ayudar con el desarrollo. Paypal: fefegarcia_1@hotmail.com

//*************************************************************************************************
//********************** libraries used ***********************************************************
//*************************************************************************************************
#include <UTFT.h>    
#include <UTouch.h> 
#include <Wire.h>
#include <EEPROM.h>
#include <writeAnything.h>
//#include <DS1307henning.h>
#include <DS1307.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <SdFat.h>
#include <SdFatUtil.h>
#include <avr/pgmspace.h>
#include <PCF8575.h>
//#include <JeeLib.h>
#include <Base64.h>
#include <SPI.h> 
#include <Ethernet.h>

//****************************************************************************************************
//****************** Variables texts and sources ****************************************************
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
const byte desativarFanPin = 1;     // Pin on/off for heatsink fans................orange wire..Male DB9
// Pin 2 reserved for the INT RFM12B.
// Pins 3, 4, 5, 6 and 7 reserved for the Touch.
// Pin 5 is also the chip select the SD card.
const byte ledPinUV = 8;            // Pin violet LEDs.............................purple wire..Male DB9
const byte ledPinBlue = 9;          // Pin green LEDs..............................green wire...Male DB9
const byte ledPinWhite = 10;        // Pin white LEDs..............................grey wire....Male DB9
const byte ledPinRoyBlue = 11;      // Pin royal blue LEDs.........................blue wire....Male DB9
const byte ledPinRed = 12;          // Pin red LEDs................................red wire.....Male DB9
const byte fanPin = 13;             // Pin that controls Heatsink PWM fan speed....brown wire...Male DB9
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
const int sensor1 = A0;             // Analog pin that checks for voltage from the saltwater mixing tank float.....these 4 lines are for auto water change
const int sensor2 = A1;             // Analog pin that checks for voltage at the bottom of the sump float.      
const int sensor3 = A2;             // Analog pin that checks for voltage at the top of the sump float.         
const int sensor4 = A3;             // Analog pin that checks for voltage at the reservoir float.               
const int sensor5 = A4;             // Analog pin that checks the level of the reef tank sump......................these 2 lines for the ATO 
const int sensor6 = A5;             // Analog pin that checks the level of the ATO reservoir.                    
const int bomba1Pin = A6;           // Pump that draws water from saltwater mixing tank............................these 3 lines for the automatic water change system 
const int bomba2Pin = A7;           // Pump that draws water from the sump.                                      
const int bomba3Pin = A8;           // Pump that draws water from the reservoir to put in the sump.              
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
const byte temporizador1 = 0;      // Pin for timer 1            
const byte temporizador2 = 1;      // Pin for timer 2            
const byte temporizador3 = 2;      // Pin for timer 3            
const byte temporizador4 = 3;      // Pin for timer 4            
const byte temporizador5 = 4;      // Pin for timer 5
const byte solenoide1Pin = 5;      // Pin for turning on RO/DI when reservoir is low

//****************************************************************************************************
//********************** Variables of temperature sensors ********************************************
//****************************************************************************************************
OneWire OneWireBus(sensoresPin);         // Temperature sensor pin
DallasTemperature sensors(&OneWireBus);  // reference to OneWire temperature sensors.
DeviceAddress sensor_agua;               // Assigns the addresses of the temperature sensors.(water)
DeviceAddress sensor_dissipador;         // Assigns the addresses of the temperature sensors.(heatsink)
DeviceAddress sensor_ambiente;           // Assigns the addresses of the temperature sensors.(room/ambient)
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
//        (SDA,SCL) Indica em quais pinos o RTC está conectado.
//DS1307 rtc(20, 21);     // Comente esta linha para usar o Ferduino Mega 2560
DS1307 rtc(18, 19);  // Descomente esta linha para usar o Ferduino Mega 2560
Time t_temp, t;

//*******************************************************************************************************
//********************** Variáveis das fuções do touch screen e tela inicial ****************************
//*******************************************************************************************************
UTFT        myGLCD(CTE70, 38,39,40,41);
UTouch      myTouch(6,5,4,3,2);              // Comente esta linha para usar o Ferduino Mega 2560
// UTouch      myTouch(7,6,5,4,3);           // Descomente esta linha para usar o Ferduino Mega 2560

unsigned long previousMillis = 0;
byte data[56];
String day, ano; 
int whiteLed, blueLed, azulroyalLed, vermelhoLed, violetaLed;    // Valor anterior de PWM.
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
float setTempC = 78;   // desired temperature *F.....float setTempC = 25.5;// desired temperature *C 
float offTempC = 0.5;            // Permissible variation
float alarmTempC = 1;            // Variation to trigger the alarm for water temperature
int contador_temp = 0;
float temperatura_agua_temp = 0; // temporary temperature

//*****************************************************************************************
//************************ Variáveis temporárias de controle de temperatura da água *******
//*****************************************************************************************
float temp2beS;           
float temp2beO;
float temp2beA;

//*****************************************************************************************
//****************** Variables controlling the pH of the aquarium *************************
//*****************************************************************************************
float PHA = 0;               // Aquarium pH
float setPHA = 0;            // Desired Aquarium pH
float offPHA = 0;            // Permissible variation
float alarmPHA = 0;          // Variation to trigger the alarm

//*****************************************************************************************
//************************ Variáveis temporárias de controle do PH do aquário *************
//*****************************************************************************************
float PHA2beS;             
float PHA2beO;
float PHA2beA;

//*****************************************************************************************
//*************************** Variable density control ************************************
//*****************************************************************************************
int DEN = 0;                 // Density
int setDEN = 0;           // Desired Density (1025)
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
//************************ Variáveis temporárias de controle do PH do reator de cálcio ****
//*****************************************************************************************
float PHR2beS;             
float PHR2beO;
float PHR2beA;

//*****************************************************************************************
//************************ variables  ORP **********************************
//*****************************************************************************************
int ORP = 0;                 // ORP
int setORP = 0;            // Desired ORP (420)
byte offORP = 10;            // Permissible variation
byte alarmORP = 10;          // Variation to trigger the alarm

//*****************************************************************************************
//************************ variables  ORP ***********************
//*****************************************************************************************
int ORP2beS;
byte ORP2beO;
byte ORP2beA;

//*****************************************************************************************
//************************ Variáveis temporárias de controle da densidade *****************
//*****************************************************************************************
int DEN2beS;            
byte DEN2beO;
byte DEN2beA;

//*****************************************************************************************
//************************ Variáveis de controle de velocidade dos coolers ****************
//*****************************************************************************************
float HtempMin = 80;    // temperature to start the operation of the heatsink fan °F scale
float HtempMax = 90;    // PWM fans should be at maximum speed when the sink is 90°F
//float HtempMin = 30.5;    // temperature to start the operation of the heatsink fan °c scale /******* changed for Fahrenheit ******************/
//float HtempMax = 40.5;    // PWM fans should be at maximum speed when the sink is 40°c
int fanSpeed = 0;         // PWM dos coolers

//*****************************************************************************************
//************** Variáveis temperárias de controle de velocidade dos coolers **************
//*****************************************************************************************
float HtempMin_temp = 0;    // Declara a temperatura para iniciar o funcionamento das ventoinhas do dissipador 
float HtempMax_temp = 0;    // Declara que as ventoinhas devem estar em sua velocidade máxima quando o dissipador estiver com 40°c

//*****************************************************************************************
//*************************** Control variables of the heat sink temperature **************
//*****************************************************************************************
float tempH = 0;    // Heatsink temperature
byte tempHR =95;   // Temperature to reduce power of leds °F scale
//byte tempHR = 60;   // Temperature to reduce power of leds °C scale  /******************************** changed for Fahrenheit ******************/
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
byte cor_canal1[] = {153, 255, 255};   // White 
byte cor_canal2[] = {0, 255, 0};       // Green   // {0, 125, 255}; // Blue
byte cor_canal3[] = {0, 0, 255};       // Royal Blue
byte cor_canal4[] = {255, 0, 0};       // Red
byte cor_canal5[] = {138, 43, 226};    // Violet

//*****************************************************************************************
//************************ Variables lunar phase ******************************************
//*****************************************************************************************
String LP;
byte MaxI , tMaxI;  // Maximum power at the full moon.             
byte MinI, tMinI;   // Maximum power at the new moon.
byte fase = 0;

//*****************************************************************************************
//************************ Variables automatic AWC ****************************************
//*****************************************************************************************
byte hora = 0;
byte minuto = 0;
byte duracaomaximatpa = 0;
byte semana_e[7]; // Index 0 = segunda-feira, 1 = terça-feira, 2 = quarta-feira, 3 = quinta-feira, 4 = sexta-feira, 5 = sábado, 6 = domingo.
byte tpa = 0;                             // Controla os estágios da TPA automática
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
byte semana[7];

//****************************************************************************************
//*********************** Control variables of the functions that use the SD Card ********
//****************************************************************************************
Sd2Card card;
SdFile file;
SdFile root;
SdVolume volume;
unsigned long log_SD_millis = 0;

//*****************************************************************************************
//*********************** Variable control levels *****************************************
//*****************************************************************************************
boolean nivel_status = 0;             // Sinaliza nível baixo em um dos aquários

//*****************************************************************************************
//************************ Variable control of replenishment of freshwater ****************
//*****************************************************************************************
byte Status = 0x0;
// bit 1 // Sinaliza reposição ligada / desligada
// bit 2 
// bit 3 

//*****************************************************************************************
//************************* Functions ethernet shield ************************************
//*****************************************************************************************
boolean Ethernet_Shield = true; // Altere para "false" caso não tenha um Ethernet Shield conectado ao Arduino.

char *Username  = "br549";   // Coloque aqui o nome de usuário cadastrado no joy-reef.com
char *APIKEY = "eieio";           // Cole aqui a ApiKey gerada pelo joy-reef.com

byte maxima_tentativa = 3;                // Número máximo de tentativas de autenticação.
unsigned long intervalo_tentativa = 15;   // Tempo  de espera (em minutos) para novas tentativas.

byte mac[] = {0x54, 0x55, 0x58, 0x10, 0x00, 0x26 }; // Este MAC deve ser único na sua rede local.
byte ip[] = {209, 97, 81, 183};                     // Configure o IP conforme a sua rede local.
IPAddress dnsServer(8, 8, 8, 8);                    // Configure o IP conforme a sua rede local. Este é o DNS do Google, geralmente não é necessário mudar.
IPAddress gateway(192, 168, 0, 1);                  // Configure o "Gateway" conforme a sua rede local.
IPAddress subnet(255, 255, 255, 0);                 // Configure a máscara de rede conforme a sua rede local.
EthernetServer server(5000);                        // Coloque aqui o número da porta configurada no seu roteador para redirecionamento.
                                                    // O número da porta deverá ser obrigatóriamente um destes: 80, 5000, 6000, 7000, 8000, 8080 ou 9000.

unsigned long intervalo = 0;
char *inParse[25];
boolean web_teste = false;
byte tentativa = 0;
boolean web_dosage = false;
unsigned long millis_dosagem = 0;
unsigned long millis_enviar = 0;
boolean web_calibracao = false;
char *token = ":";
char Auth1[50];
unsigned long teste_led_millis = 0; 

//*****************************************************************************************
//************************** Variáveis de controle do multiplexador ***********************
//*****************************************************************************************
boolean Stamps = false; // Altere para "false" caso não tenha ao menos um dos circuitos de PH, ORP e EC da Atlas Scientific.
unsigned long millis_antes = 0;
short ph1=0; // Y0
short ph2=1; // Y1
short orp=2; // Y2
short ec=3;  // Y3

//*****************************************************************************************
//************************** Variables password request ***********************************
//******* to reactivate password protection, go to processmytouch tab, change case 0: *****
//*****************************************************************************************
char stCurrent[7]="";
char limpar_senha [7] = "";
byte stCurrentLen=0;
char senha [7] = {'0','1','2','8','6','7','\0'}; // Enter your password here. The character '\ 0' and commas should not be changed. change only the number

//*****************************************************************************************
//************************** dosing variables *********************************************
//*****************************************************************************************
boolean dosadoras = false; //Altere para "false" caso não tenha as dosadoras.
const char *arquivo[6] = {"HDP1.TXT","HDP2.TXT","HDP3.TXT","HDP4.TXT","HDP5.TXT","HDP6.TXT"};
unsigned long tempo_dosagem = 0;
unsigned long dosadoras_millis = 0;
boolean modo_manual = false;
boolean modo_personalizado = false;
boolean modo_calibrar = false;
byte dosadora_selecionada = 0; // 0 = false, 1 = true
byte dosadora[6] = {dosadora1, dosadora2, dosadora3, dosadora4, dosadora5, dosadora6}; // Index 0 = dosadora 1 , 1 = dosadora 2, 2 = dosadora 3, 3 = dosadora 4, 4 = dosadora 5, 5 = dosadora 6
byte ativar_desativar = 0x0;     // 0 = false, 1 = true
byte hora_inicial_dosagem_personalizada_e[6];
byte minuto_inicial_dosagem_personalizada_e[6];
byte hora_final_dosagem_personalizada_e[6];
byte minuto_final_dosagem_personalizada_e[6];
byte segunda_dosagem_personalizada_e[6];
byte terca_dosagem_personalizada_e[6];
byte quarta_dosagem_personalizada_e[6]; 
byte quinta_dosagem_personalizada_e[6];
byte sexta_dosagem_personalizada_e[6];
byte sabado_dosagem_personalizada_e[6];
byte domingo_dosagem_personalizada_e[6];
float dose_dosadora_personalizada_e[6] = {101, 102, 103, 104, 105, 106};
byte quantidade_dose_dosadora_personalizada_e[6];
byte modo_personalizado_on_e[6];
float dose_dosadora_manual_e[6] = {20, 20, 20, 20, 20, 20};
float fator_calib_dosadora_e[6] = {35.1, 35.2, 35.3, 35.4, 35.5, 35.6};

//*****************************************************************************************
//************************** Variáveis temporárias das dosadoras **************************
//*****************************************************************************************
byte hora_inicial_dosagem_personalizada[6]; 
byte minuto_inicial_dosagem_personalizada[6];
byte hora_final_dosagem_personalizada[6];
byte minuto_final_dosagem_personalizada[6];
byte segunda_dosagem_personalizada[6];
byte terca_dosagem_personalizada[6];
byte quarta_dosagem_personalizada[6]; 
byte quinta_dosagem_personalizada[6];
byte sexta_dosagem_personalizada[6];
byte sabado_dosagem_personalizada[6];
byte domingo_dosagem_personalizada[6];
float dose_dosadora_personalizada[6];
byte quantidade_dose_dosadora_personalizada[6];
byte modo_personalizado_on[6];
float dose_dosadora_manual[6];
float fator_calib_dosadora[6];
//*****************************************************************************************
//************************** Variables of timers ******************************************
//*****************************************************************************************
byte temporizador = 0;
byte temporizador_e[5] = {temporizador1, temporizador2, temporizador3, temporizador4, temporizador5};

boolean web_timer = false;
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
byte on_hora_e[5]; // Index 0 = timer 1 , 1 = timer 2, 2 = timer 3, 3 = timer 4, 4 = timer 5
byte on_minuto_e[5];
byte off_hora_e[5];
byte off_minuto_e[5];
byte temporizador_ativado_e[5];

//*****************************************************************************************
//************************** Temporary variables of timers ********************************
//*****************************************************************************************
byte on_hora[5];
byte on_minuto[5];
byte off_hora[5];
byte off_minuto[5];
byte temporizador_ativado[5];

//*****************************************************************************************
//************************** Variables PCF8575 ********************************************
//*****************************************************************************************

 boolean PCF8575TS_S = true; // Altere para "false" caso não tenha um PCF8575
 byte endereco_PCF8575TS = 0x20; // Endereço em hexadecimal = 0x20
PCF8575 PCF8575;

//*****************************************************************************************
//************************** RF communication *********************************************
//*****************************************************************************************
byte consumo = 0;
/*boolean RFM12B = false; // Altere para "false" caso não tenha um RFM12B
 #define myNodeID 30          // ID do emissor (intervalo 0-30) 
 #define network     210      // Grupo (pode ser no intervalo de 1-250).
 #define freq RF12_915MHZ     // Frequência de RF12B pode ser RF12_433MHZ, RF12_868MHZ ou RF12_915MHZ. Corresponde a frequência do módulo
 typedef struct { int power1, power2, power3, battery; } PayloadTX;      // Cria uma estrutura
 PayloadTX emontx;  
 const byte emonTx_NodeID = 10;            // ID do receptor*/

//*****************************************************************************************
//************************** SPI devices **************************************************
//*****************************************************************************************
const byte SD_CARD = 0; 
const byte ETHER_CARD = 1;
const byte RFM = 2;
const byte ChipSelect_SD = 53; // Comente esta linha para usar o Ferduino Mega 2560
//const byte ChipSelect_SD = 5;  // Descomente esta linha para usar o Ferduino Mega 2560           
const byte SelectSlave_ETH = 4;
const int ChipSelect_RFM = A15;

//*****************************************************************************************
//************************* Variables room temperature ************************************
//*****************************************************************************************
float tempA = 0; // Temperatura ambiente
float temperatura_ambiente_temp = 0; // Temperatura temporária

//*****************************************************************************************
//************************* Variables of Wave pumps ***************************************
//*****************************************************************************************
byte modo_selecionado = 1; 
byte Pump1PWM_temp = 0;    
byte Pump2PWM_temp = 0;
int periodo = 3500; // default setting 100000
int duracao = 5000; // Duração do ciclo em milisegundos para o modo 3.
unsigned long millis_antes_1 = 0;
byte conta = 0;
byte Pump1PWM = 0;    
byte Pump2PWM = 0;
//*****************************************************************************************
//************************** Control variables power leds *********************************
//*****************************************************************************************
// WHITE Dimming Values (White LED array in RAM)
byte wled[96] = {
  0, 0, 0, 0, 0, 0, 0, 0,                   //0 - 1
  0, 0, 0, 0, 0, 0, 0, 0,                   //2 - 3
  0, 0, 0, 0, 0, 0, 0, 0,                   //4 - 5
  0, 0, 0, 0, 0, 0, 0, 0,                   //6 - 7
  0, 0, 0, 0, 0, 0, 0, 0,                   //8 - 9
  30, 35, 45, 65, 80, 95, 100, 105,         //10 - 11
  110, 115, 120, 125, 130, 130, 135, 140,   //12 - 13
  175, 180, 185, 190, 195, 205, 210, 215,   //14 - 15
  215, 210, 205, 200, 190, 185, 180, 175,   //16 - 17
  140, 140, 130, 125, 120, 115, 105, 100,   //18 - 19
  85, 70, 60, 45, 35, 0, 0, 0,              //20 - 21
  0, 0, 0, 0, 0, 0, 0, 0                    //22 - 23
};

// GREEN Dimming Values
byte bled[96] = {
  0, 0, 0, 0, 0, 0, 0, 0,                   //0 - 1
  0, 0, 0, 0, 0, 0, 0, 0,                   //2 - 3
  0, 0, 0, 0, 0, 0, 0, 0,                   //4 - 5
  0, 0, 0, 0, 0, 0, 0, 0,                   //6 - 7
  0, 0, 0, 0, 0, 0, 0, 0,                   //8 - 9
  30, 35, 45, 65, 80, 95, 100, 105,         //10 - 11
  110, 115, 120, 125, 130, 130, 135, 140,   //12 - 13
  140, 140, 143, 145, 147, 140, 140, 150,   //14 - 15
  150, 140, 140, 130, 137, 135, 133, 120,   //16 - 17
  115, 110, 100, 95, 80, 75, 65, 50,        //18 - 19
  45, 30, 20, 15, 5, 0, 0, 0,               //20 - 21
  0, 0, 0, 0, 0, 0, 0, 0                    //22 - 23
};  

// ROYAL BLUE Dimming Values
byte rbled[96] = {
  0, 0, 0, 0, 0, 0, 0, 0,                   //0 - 1
  0, 0, 0, 0, 0, 0, 0, 0,                   //2 - 3
  0, 0, 0, 0, 0, 0, 0, 0,                   //4 - 5
  0, 0, 0, 0, 0, 0, 28, 28,                 //6 - 7
  30, 30, 32, 55, 70, 70, 75, 80,           //8 - 9
  80, 85, 90, 110, 120, 125, 130, 135,      //10 - 11
  140, 145, 150, 160, 160, 160, 165, 170,   //12 - 13
  175, 180, 185, 195, 210, 225, 240, 255,   //14 - 15
  255, 240, 225, 210, 195, 185, 180, 175,   //16 - 17
  170, 165, 160, 160, 160, 150, 145, 140,   //18 - 19
  135, 130, 125, 115, 100, 75, 60, 30,      //20 - 21
  30, 30, 28, 28, 0, 0, 0, 0                //22 - 23
};
// RED Dimming Values
byte rled[96] = {
  0, 0, 0, 0, 0, 0, 0, 0,                   //0 - 1
  0, 0, 0, 0, 0, 0, 0, 0,                   //2 - 3
  0, 0, 0, 0, 0, 0, 0, 0,                   //4 - 5
  0, 0, 0, 0, 0, 0, 0, 0,                   //6 - 7
  0, 0, 0, 0, 0, 0, 0, 0,                   //8 - 9
  30, 35, 45, 65, 80, 95, 100, 105,         //10 - 11
  110, 115, 120, 125, 130, 130, 135, 140,   //12 - 13
  140, 140, 143, 145, 147, 140, 140, 150,   //14 - 15
  150, 140, 140, 130, 137, 135, 133, 120,   //16 - 17
  115, 110, 100, 95, 80, 75, 65, 50,        //18 - 19
  45, 30, 20, 15, 5, 0, 0, 0,               //20 - 21
  0, 0, 0, 0, 0, 0, 0, 0                    //22 - 23
};
// ULTRA VIOLET (UV) Dimming Values
byte uvled[96] = {
  0, 0, 0, 0, 0, 0, 0, 0,                   //0 - 1
  0, 0, 0, 0, 0, 0, 0, 0,                   //2 - 3
  0, 0, 0, 0, 0, 0, 0, 0,                   //4 - 5
  0, 0, 0, 0, 0, 0, 28, 28,                 //6 - 7
  30, 30, 32, 55, 70, 70, 75, 80,           //8 - 9
  80, 85, 90, 110, 120, 125, 130, 135,      //10 - 11
  140, 145, 150, 160, 160, 160, 165, 170,   //12 - 13
  175, 180, 185, 190, 195, 205, 210, 215,   //14 - 15
  215, 210, 205, 200, 190, 185, 180, 175,   //16 - 17
  170, 165, 160, 160, 160, 150, 145, 140,   //18 - 19
  135, 130, 125, 115, 100, 75, 60, 30,      //20 - 21
  30, 30, 28, 28, 0, 0, 0, 0                //22 - 23
};

byte *cor[5] = {wled, bled, rbled, rled, uvled};
byte *cor_canal[5] = {cor_canal1, cor_canal2, cor_canal3, cor_canal4, cor_canal5};

//*****************************************************************************************
//************************** Textos *******************************************************
//*****************************************************************************************
prog_char string0[] PROGMEM = "POST /api/temp HTTP/1.1";
prog_char string1[] PROGMEM = "Host: www.joy-reef.com";
prog_char string2[] PROGMEM = "Authorization: Basic ";
prog_char string3[] PROGMEM = "Cache-Control: no-cache";
prog_char string4[] PROGMEM = "Content-Type: application/x-www-form-urlencoded";
prog_char string5[] PROGMEM = "Connection: Keep-Alive";
prog_char string6[] PROGMEM = "Content-Length: ";
prog_char string7[] PROGMEM = "{\"response\":\"ok\"}";
prog_char string8[] PROGMEM = "HTTP/1.1 200 OK";
prog_char string9[] PROGMEM = "Content-Type: application/json";
prog_char string10[] PROGMEM = "{\"response\":\"000\"}";
prog_char string11[] PROGMEM = "{\"response\":\"001\",\"interval\":\"";

char* tabela_strings[] PROGMEM = 
{
  string0, string1, string2, string3,
  string4, string5, string6, string7,
  string8, string9, string10, string11
};

