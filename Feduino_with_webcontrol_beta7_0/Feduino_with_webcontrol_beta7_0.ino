///*****************************************************************************************************************************************************
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
//***********************              Desenvolvido por Fernando Garcia         ************************************************************************
//******************************************************************************************************************************************************
//******* Dúvidas, sugestões e elogios: info@ferduino.com **********************************************************************************************
//******************************************************************************************************************************************************

// Este programa é compatível com a IDE 1.0.6

// As funções para controle via web foram implementadas graças à preciosa ajuda do Simone Grimaldi e Danilo Castellano.

//---------------------------------------------------------

// Este programa foi desenvolvido com base na versão Stilo 2.1
// Disponível nesta página http://code.google.com/p/stilo/ 

//-----------------------------------------------------------
// Este programa é software livre; Você pode redistribuí-lo e/ou
// modificá-lo sob os termos da GNU General Public License
// como publicada pela Free Software Foundation versão 3
// da licença, ou (por sua opção) qualquer versão posterior.
// Este programa é distribuído na esperança que seja útil,
// mas sem qualquer garantia; sem mesmo a garantia implícita de
// comercialização ou propósito particular. Consulte o
// GNU General Public License para mais detalhes.

//*************************************************************************************************
//*************** Selecionar idioma ***************************************************************
//*************************************************************************************************

// Descomente a linha correspondente ao seu idioma.
// Uncomment the line corresponding to your language.

 #define ENGLISH    // If this program is useful for you, make a donation to help with development. Paypal: fefegarcia_1@hotmail.com



//*************************************************************************************************
//*************** Bibliotecas utilizadas ***********************************************************
//*************************************************************************************************
#include <UTFT.h>    
#include <UTouch.h> 
#include <Wire.h>
#include <EEPROM.h>
#include <writeAnything.h>
//#include <DS1307henning.h> // Comente esta linha para usar a versão em inglês.
#include <DS1307.h>      // Descomente esta linha para usar a versão em inglês.
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
//****************** Variáveis de textos e fontes ****************************************************
//****************************************************************************************************
#define LARGE true
#define SMALL false
extern uint8_t RusFont1[];    // Declara que fontes vamos usar
extern uint8_t BigFont[];     // Declara que fontes vamos usar
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
//       (SDA,SCL)
DS1307 rtc(18, 19);       // Indicates which pins are connected for the RTC. uncomment this line when using PCF8575
//DS1307 rtc(20, 21);       // Indicates which pins are connected for the RTC. comment this line when using PCF8575
Time t_temp, t;
// 18 & 19 pins reserved for the RTC.
// 20 & 21 pins reserved for the PCF8575 I2C communication.

//*******************************************************************************************************
//*********************** Touch screen and display variables ********************************************
//*******************************************************************************************************
UTFT        myGLCD(CTE70, 38,39,40,41);
UTouch      myTouch(6,5,4,3,2); 
//UTouch      myTouch(7,6,5,4,3);

long previousMillis = 0;
byte data[56];
String day, ano; 
int whiteLed, blueLed, azulroyalLed, vermelhoLed, violetaLed;    // Previous value of PWM.
int dispScreen = 0;
//unsigned long previousMillis_2 = 0;
//int interval = 30; // time in seconds til clock screen displays 

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
float temp2beS;           
float temp2beO;
float temp2beA;

//*****************************************************************************************
//************************ Variáveis do controle do PH do aquário *************************
//*****************************************************************************************
float PHA = 0;              // PH do aquário
float setPHA = 0;           // PH desejado do aquário
float offPHA = 0;           // Variaçãoo permitida do PH do aquário
float alarmPHA = 0;         // Variação para acionar o alarme de ph do aquário

//*****************************************************************************************
//************************ Variáveis temporárias de controle do PH do aquário *************
//*****************************************************************************************
float PHA2beS;             
float PHA2beO;
float PHA2beA;

//*****************************************************************************************
//************************ Variáveis de controle de densidade *****************************
//*****************************************************************************************
int DEN = 0;                 // Densidade
int setDEN = 1025;           // Densidade desejada
byte offDEN = 2;             // Variação permitida da densidade
byte alarmDEN = 1;           // Variação para acionar o alarme de densidade

//*****************************************************************************************
//************************ Variáveis de controle do PH do reator de cálcio ****************
//*****************************************************************************************
float PHR = 0;              // Valores PH reator
float setPHR = 0;           // PH do reator desejado
float offPHR = 0;           // Variacao permitida do PH do reator
float alarmPHR = 0;         // Variacao para acionar o alarme do PH do reator de calcio

//*****************************************************************************************
//************************ Variáveis temporárias de controle do PH do reator de cálcio ****
//*****************************************************************************************
float PHR2beS;             
float PHR2beO;
float PHR2beA;

//*****************************************************************************************
//************************ Variáveis de controle da  ORP **********************************
//*****************************************************************************************
int ORP = 0;                // Valores ORP
int setORP = 420;           // ORP desejada
byte offORP = 10;           // Variação permitida da ORP
byte alarmORP = 10;         // Variacão para acionar o alarme da ORP

//*****************************************************************************************
//************************ Variáveis temporárias de controle da ORP ***********************
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
//float HtempMin = 30.5;    // Declara a temperatura para iniciar o funcionamento das ventoinhas do dissipador 
//float HtempMax = 40.5;    // Declara que as ventoinhas devem estar em sua velocidade máxima quando o dissipador estiver com 40°c
int fanSpeed = 0;         // PWM dos coolers

//*****************************************************************************************
//************** Variáveis temperárias de controle de velocidade dos coolers **************
//*****************************************************************************************
float HtempMin_temp = 0;    // Declara a temperatura para iniciar o funcionamento das ventoinhas do dissipador 
float HtempMax_temp = 0;    // Declara que as ventoinhas devem estar em sua velocidade máxima quando o dissipador estiver com 40°c

//*****************************************************************************************
//*********************** Variáveis de controle da temperatura do dissipador **************
//*****************************************************************************************
float tempH = 0;    // Temperatura do dissipador
byte tempHR =95;   // Temperature to reduce power of leds °F scale
//byte tempHR = 60;   // Temperatura para reduzir potência dos leds
byte potR = 30;     // Porcentagem a ser reduzida.

//*****************************************************************************************
//*********** Variáveis temporárias de controle da temperatura do dissipador **************
//*****************************************************************************************
float temperatura_dissipador_temp = 0; // Temperatura temporária
byte tempHR_t = 0;                     // Temperatura temporária para reduzir potência dos leds
byte potR_t = 0;                       // Porcentagem temporária a ser reduzida.
boolean temperatura_alta = false;      // Sinaliza que a temperatura dos leds está alta.
boolean temperatura_baixou = false;    // Sinaliza que a temperatura dos leds esteve alta.

//*****************************************************************************************
//************************ Variáveis de controle da iluminação ****************************
//*****************************************************************************************
int LedChangTime = 0;             // Página de alteração do leds, tempo e valores.
boolean MeanWell = true;          // Se estiver usando drivers cuja potência máxima seja obtida aplicando zero volt e a mínima seja 5 volts altere de "true" para "false".
boolean LEDtestTick = false;      // Acelerar o tempo durante o teste dos leds. 
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
byte y_tocado;
boolean teste_em_andamento = false;
byte cor_selecionada = 0;
// bit 1 = led white
// bit 2 = led green // blue in the program, I changed to green
// bit 3 = led blue  // royal blue
// bit 4 = led red
// bit 5 = led violet
byte setor_selecionado = 0;
boolean mensagem = true;
float suavizar = 0.0; // LEDS iniciam suavemente e chega ao valor especificado em 50 segundos.
byte predefinido = 0;
byte pre_definido_ativado = 0;
byte pwm_pre_definido = 0;
byte led_on_minuto;
byte led_on_hora;
byte led_off_minuto;
byte led_off_hora;
boolean horario_alterado = false;
boolean hora_modificada = false;
byte amanhecer_anoitecer = 60;
boolean teste_iniciado = false;

//*****************************************************************************************
//**************** Variáveis temporárias de controle da iluminação ************************
//*****************************************************************************************
byte predefinido_t = 0;
byte pre_definido_ativado_t = 0;
byte pwm_pre_definido_t = 0;
byte led_on_minuto_t; 
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
//************************ Variáveis da fase lunar ****************************************
//*****************************************************************************************
String LP;
byte MaxI , tMaxI;  // Potência  máxima na Lua cheia.             
byte MinI, tMinI;   // Potência  mínima na Lua nova.
byte fase = 0;

//*****************************************************************************************
//********* Variáveis da TPA (Troca Parcial de Água) automática ***************************
//*****************************************************************************************
byte hora = 0;
byte minuto = 0;
byte duracaomaximatpa = 0;
byte semana_e[7]; // Index 0 = segunda-feira, 1 = terça-feira, 2 = quarta-feira, 3 = quinta-feira, 4 = sexta-feira, 5 = sábado, 6 = domingo.
byte tpa = 0;                             // Controla os estágios da TPA automática
byte tpa_status = 0x0; // 0 = false e 1 = true
// bit 1 = Sinaliza TPA automática em andamento
// bit 2 = Sinaliza falha durante a TPA automática          
unsigned long tempo = 0;                 // Duração de cada estágio da TPA automática
unsigned long marcadoriniciotpa = 0;   // Evita que uma tpa inicie próximo do millis zerar
unsigned long shiftedmillis = 0;       // Evita que uma tpa inicie próximo do millis zerar

//*****************************************************************************************
//********** Variáveis temporárias da TPA (Troca Parcial de Água) automática **************
//*****************************************************************************************
byte temp2hora;
byte temp2minuto;
byte temp2duracaomaximatpa;
byte semana[7];

//****************************************************************************************
//*********************** Variáveis de controle das funções que utilizam o cartao SD *****
//****************************************************************************************
Sd2Card card;
SdFile file;
SdFile root;
SdVolume volume;
unsigned long log_SD_millis = 0;

//*****************************************************************************************
//*********************** Variável do controle de níveis **********************************
//*****************************************************************************************
boolean nivel_status = 0;             // Sinaliza nível baixo em um dos aquários

//*****************************************************************************************
//************************ Variável de controle da reposição de água doce *****************
//*****************************************************************************************
byte Status = 0x0;
// bit 1 // Sinaliza reposição ligada / desligada
// bit 2 
// bit 3 

//*****************************************************************************************
//************************* Funções do ethernet shield ************************************
//*****************************************************************************************
boolean Ethernet_Shield = true; // Altere para "false" caso não tenha um Ethernet Shield conectado ao Arduino.

const char *Username  = "*******";   // user name for joy-reef.com
const char *APIKEY = "******";           // ApiKey generated at joy-reef.com

const byte maxima_tentativa = 3;                // Número máximo de tentativas de autenticação.
const byte intervalo_tentativa = 15;   // Tempo  de espera (em minutos) para novas tentativas.

byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED }; // Este MAC deve ser único na sua rede local.
byte ip[] = {209, 97, 81, 183};                     // Configure o IP conforme a sua rede local.
IPAddress dnsServer(8, 8, 8, 8);                    // Configure o IP conforme a sua rede local. Este é o DNS do Google, geralmente não é necessário mudar.
IPAddress gateway(192, 168, 0, 1);                  // Configure o "Gateway" conforme a sua rede local.
IPAddress subnet(255, 255, 255, 0);                 // Configure a máscara de rede conforme a sua rede local.
EthernetServer server(80);                        // Coloque aqui o número da porta configurada no seu roteador para redirecionamento.
                                                    // O número da porta deverá ser obrigatóriamente um destes: 80, 5000, 6000, 7000, 8000, 8080 ou 9000.
unsigned long intervalo = 0;
char *inParse[25];
boolean web_teste = false;
byte tentativa = 0;
boolean web_dosage = false;
unsigned long millis_dosagem = 0;
unsigned long millis_enviar = 0;
boolean web_calibracao = false;
const char *token = ":";
char Auth1[50];
unsigned long teste_led_millis = 0; 
//*****************************************************************************************
//************************** Variáveis de controle do multiplexador ***********************
//*****************************************************************************************
#define STAMPS_V4X     // Comente esta linha para usar Stamps EZO
//#define STAMPS_EZO     // Descomente esta linha para usar Stamps EZO
boolean Stamps = false; // Altere para "false" caso não tenha ao menos um dos circuitos de PH, ORP e EC da Atlas Scientific.
unsigned long millis_antes = 0;
const byte ph1 = 0; // Y0
const byte ph2 = 1; // Y1
const byte orp = 2; // Y2
const byte ec = 3;  // Y3

//*****************************************************************************************
//************************** Variables password request ***********************************
//******* to reactivate password protection, go to processmytouch tab, change case 0: *****
//*****************************************************************************************
char stCurrent[7]="";
char limpar_senha [7] = "";
byte stCurrentLen=0;
char senha [7] = {'0','1','2','8','6','7','\0'}; // Enter your password here. The character '\ 0' and commas should not be changed. change only the numbers
  
//*****************************************************************************************
//************************** Variáveis dosadoras ******************************************
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
//************************** Variáveis dos timers *****************************************
//*****************************************************************************************
byte temporizador = 0;
byte temporizador_e[5] = {temporizador1, temporizador2, temporizador3, temporizador4, temporizador5};  // Index 0 = timer 1 , 1 = timer 2, 2 = timer 3, 3 = timer 4, 4 = timer 5

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
//******************** Variáveis temporárias dos timers ***********************************
//*****************************************************************************************
byte on_hora[5];
byte on_minuto[5];
byte off_hora[5];
byte off_minuto[5];
byte temporizador_ativado[5];

//*****************************************************************************************
//************************** Variáveis do PCF8575 *****************************************
//*****************************************************************************************

 boolean PCF8575TS_S = true; // Altere para "false" caso não tenha um PCF8575
 byte endereco_PCF8575TS = 0x20; // Endereço em hexadecimal = 0x20
 PCF8575 PCF8575;

//*****************************************************************************************
//************************** Comunicação RF ***********************************************
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
//************************** Dispositivos SPI *********************************************
//*****************************************************************************************
const byte SD_CARD = 0; 
const byte ETHER_CARD = 1;
const byte RFM = 2;
const byte ChipSelect_SD = 53; // Comente esta linha para usar o Ferduino Mega 2560
//const byte ChipSelect_SD = 5;  // Descomente esta linha para usar o Ferduino Mega 2560           
const byte SelectSlave_ETH = 4;
const byte ChipSelect_RFM = 69; // A15

//*****************************************************************************************
//************************* Variáveis da temperatura ambiente *****************************
//*****************************************************************************************
float tempA = 0; // Temperatura ambiente
float temperatura_ambiente_temp = 0; // Temperatura temporária

//*****************************************************************************************
//************************* Variáveis das bombas de circulação ****************************
//*****************************************************************************************
byte modo_selecionado = 1; 
byte Pump1PWM_temp = 0;    
byte Pump2PWM_temp = 0;
int periodo = 10000;
int duracao = 5000; // Duração do ciclo em milisegundos para o modo 3.
unsigned long millis_antes_1 = 0;
byte conta = 0;
byte Pump1PWM = 0;    
byte Pump2PWM = 0;
//*****************************************************************************************
//************************** Control variables power leds *******************
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
