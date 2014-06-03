//**********************************************************************************************
//*********************** BotÃƒÂµes dos menus *****************************************************
//**********************************************************************************************
const byte temM[]= {
  90, 35, 115, 60};           // temp. minus
const byte temP[]= {
  205,35,230, 60};            // temp. plus
const byte offM[]= {
  90, 85, 115, 110};          // offset minus
const byte offP[]= {
  205, 85, 230, 110};         // offset plus
const byte almM[]= {
  90, 135, 115, 160};         // alarm minus
const byte almP[]= {
  205, 135, 230, 160};        // alarm plus
const int iniC[]= {
  650, 4, 788, 84};           // home
const int menU[]= {
  650, 104, 788, 184};        // menu
const int prOK[]= {
  650, 400, 788, 476};        // ok
const int salV[]= {
  650, 300, 788, 380};        // save 
const int deS[]= {
  650, 204, 788, 284};
//const int xxxx[]= {650, 400, 788, 478};
const byte tanD[]= {
  20, 30, 255, 70};           // Time $ date
const byte tesT[]= {
  20, 80, 255, 120};          // Test LED
const byte temC[]= {
  20, 130, 255, 170};         // Temperature 
const byte graF[]= {
  20, 180, 255, 220};         // Graphs
const int ledW[]= {
  340, 30, 580, 70};          // Timers

const int savE[]= {
  180, 213, 300, 245};         // Save Eeprom
const byte leWB[]= {
  5, 213, 90, 245};           // LED values show whites or blues
const byte leST[]= {
  100, 213, 170, 245};        // LED values change

const int tpaA[]= {
  340, 80, 580, 120};         // auto-water change
const int dosA[]= {
  340, 130, 580, 170};        // dosing pump
const int wavM[]= {
  340, 180, 580, 220};        // Wavemaker
const int volT[]= {
  650, 400, 788, 476};        // back
const int testT[]= {
  20, 30, 255, 70};           // Test all leds
const int testI[]= {
  340, 30, 580, 70};          // Test individual leds
//-----------botoes graficos e parametros--------------------
const byte tempG[]= {
  20, 30, 255, 70};           // parametro/grafico de temperatura
const byte phA[]= {
  20, 80, 255, 120};          // parametro/grafico de ph do aqua
const int phR[]= {
  20, 130, 255, 170};         // parametro/grafico de ph do aqua
const byte orP[]= {
  20, 180, 255, 220};         // parametro/grafico de orp
const int denS[]= {
  340, 30, 580, 70};          // parametro/grafico de densidade
//const int []= {340, 75, 580, 110};         
//const int []= {340, 125, 580, 160};        

const byte manU[]= {
  20, 30, 255, 70};           // Dosagem manual
const byte autO[]= {
  20, 80, 255, 120};          // Dosagem automatica
const byte perS[]= {
  20, 80, 255, 120};          // Dosagem personalizada
const byte reV[]= {
  20, 130, 255, 170};         // rever cofig. dosagem personalizada
const int atiV[]= {
  340, 30, 580, 70};          // Ativar/desativar dosadoras   
//const int []= {340, 80, 580, 120};         
//const int []= {340, 130, 580, 170};          

const byte dosa1[]= {
  20, 30, 255, 70};            // Bomba dosadora 1
const byte dosa2[]= {
  20, 80, 255, 120};           // Bomba dosadora 2
const byte dosa3[]= {
  20, 130, 255, 170};          // Bomba dosadora 3
const int dosa4[]= {
  340, 30, 580, 70};           // Bomba dosadora 4
const int dosa5[]= {
  340, 80, 580, 120};          // Bomba dosadora 5
const int dosa6[]= {
  340, 130, 580, 170};         // Bomba dosadora 6
//----------------------------------------------------

const byte houU[]= {
  70, 18, 95, 43};          // hour up
const byte minU[]= {
  160, 18, 185, 43};        // min up
const byte minUT[]= {
  120, 18, 145, 43};        // minutotpa mais
const byte minDT[]= {
  120, 69, 145, 92};        // minutotpa menos
const byte houD[]= {
  70, 69, 95, 92};          // hour down
const byte minD[]= {
  160, 69, 185, 92};        // min down
const byte dayU[]= {
  70, 102, 95, 127};        // day up
const byte monU[]= {
  160, 102, 185, 127};      // month up
const int yeaU[]= {
  250, 102, 275, 127};      // year up
const byte dayD[]= {
  70, 152, 95, 177};        // day down
const byte monD[]= {
  160, 152, 185, 177};      // month down
const int yeaD[]= {
  250, 152, 275, 177};      // year down
const byte stsT[]= {
  90, 155, 220, 225};       // start/stop
const byte tenM[]= {
  10, 170, 80, 210};        // -10s
const int tenP[]= {
  230, 170, 300, 210};      // +10s
const int segC[]= {
  250, 18, 275, 43};        // segundo para cima
const int segB[]= {
  250, 69, 275, 92};        // segundo para baixo
const int durC[]= {
  275, 18, 300, 43};        // duracao tpa para cima
const int durB[]= {
  275, 69, 300, 92};        // duracao tpa para baixo
const byte segU[]= {
  30, 99, 110, 139};        // Monday
const byte terC[]= {
  120, 99, 200, 139};       // Tuesday
const int quaR[]= {
  210, 99, 290, 139};       // Wednesday
const byte quiN[]= {
  30, 146, 110, 186};       // Thursday
const byte sexT[]= {
  120, 146, 200, 186};      // Friday
const int sabA[]= {
  210, 146, 290, 186};      // Saturday
const byte domI[]= {
  120, 193, 200, 233};      // Sunday
const int caliB[]= {
  340, 80, 580, 120};       // Probe Calibration
const byte iniciaR[]= {
  120, 193, 200, 233};      // start calibration
const byte anT[]= {
  30, 193, 110, 233};       // previous
const int proX[]= {
  210, 193, 290, 233};      // next
const int busC[]= {
  400, 60, 600, 130};       // FIND PROBES
const int sonD1[]= {
  400, 220, 600, 270};      // Probe 1
const int sonD2[]= {
  400, 290, 600, 340};      // Probe 2
const int sonD3[]= {
  400, 360, 600, 410};      // Probe 3
const int tempeC[]= {
  265, 35, 290, 60};        // Temperatura reduzir potÃƒÂªncia +
const int tempeB[]= {
  265, 70, 290, 95};        // Temperatura reduzir potÃƒÂªncia -
const int potC[]= {
  265, 115, 290, 140};      // Reduzir potÃƒÂªncia + 
const int potB[]= {
  265, 150, 290, 175};      // Reduzir potÃƒÂªncia - 
const byte peRB[]= {
  35, 145, 70, 185};        // minus  wavemaker
const byte peRC[]= {        // period/duration buttons
  200, 145, 235, 185};      // plus  wavemaker
const byte PoTEB1[]= {
  35, 115, 70, 155};        // minus wavemaker
const byte PoTEC1[]= {      // pump 1
  200, 115, 235, 155};      // plus wavemaker
const byte PoTEB2[]= {
  35, 185, 70, 225};        // minus wavemaker
const byte PoTEC2[]= {      // pump 2
  200, 185, 235, 225};      // plus wavemaker

//----------------botoes solicitacao de senha-------------------------------------------------
const byte boT1[]= {
  10, 30, 62, 70};          // 1 button
const byte boT2[]= {
  72, 30, 124, 70};         // 2 button
const byte boT3[]= {
  134, 30, 186, 70};        // 3 button
const byte boT4[]= {
  196, 30, 248, 70};        // 4 button
const int boT5[]= {
  258, 30, 310, 70};        // 5 button
const byte boT6[]= {
  10, 80, 62, 120};         // 6 button
const byte boT7[]= {
  72, 80, 124, 120};        // 7 button
const byte boT8[]= {
  134, 80, 186, 120};       // 8 button
const byte boT9[]= {
  196, 80, 248, 120};       // 9 button
const int boT0[]= {
  258, 80, 310, 120};       // zero button 
const byte boTL[]= {
  10, 130, 155, 170};       // cancel button
const int boTE[]= {
  165, 130, 310, 170};      // enter button

//**********************************************************************************************
//***************************** function ********************************************************
//**********************************************************************************************
void clearScreen()
{
  myGLCD.clrScr();
}

void printButton(char* text, int x1, int y1, int x2, int y2, boolean setFont = false)
{
  int stl = strlen(text);
  int fx, fy;

  myGLCD.setColor(0, 0, 200);
  myGLCD.fillRoundRect (x1, y1, x2, y2);
  myGLCD.setColor(255, 255, 255);
  myGLCD.drawRoundRect (x1, y1, x2, y2);

  myGLCD.setBackColor(0, 0, 200);
  //if (setFont) {
    myGLCD.setFont(BigFont); 
    fx = x1+(((x2 - x1+1)-(stl*16))/2);
    fy = y1+(((y2 - y1+1)-16)/2);
    myGLCD.print(text, fx, fy);
 /* }
    else {
    myGLCD.setFont(RusFont1); 
    fx = x1+(((x2 - x1)-(stl*8))/2);
    fy = y1+(((y2 - y1-1)-6)/2);
    myGLCD.print(text, fx, fy);
  }*/
}
void printButton_verde(char* text, int x1, int y1, int x2, int y2, boolean setFont = false)
{
  int stl = strlen(text);
  int fx, fy;

  myGLCD.setColor(0, 150, 86);
  myGLCD.fillRoundRect (x1, y1, x2, y2);
  myGLCD.setColor(255, 255, 255);
  myGLCD.drawRoundRect (x1, y1, x2, y2);

  myGLCD.setBackColor(0, 150, 86);
  if (setFont) {
    myGLCD.setFont(BigFont); 
    fx = x1+(((x2 - x1+1)-(stl*16))/2);
    fy = y1+(((y2 - y1+1)-16)/2);
    myGLCD.print(text, fx, fy);
  }
  else {
    myGLCD.setFont(RusFont1); 
    fx = x1+(((x2 - x1)-(stl*8))/2);
    fy = y1+(((y2 - y1-1)-6)/2);
    myGLCD.print(text, fx, fy);
  }
}
void printButton_vermelho(char* text, int x1, int y1, int x2, int y2, boolean setFont = false)
{
  int stl = strlen(text);
  int fx, fy;

  myGLCD.setColor(255, 0, 0);
  myGLCD.fillRoundRect (x1, y1, x2, y2);
  myGLCD.setColor(255, 255, 255);
  myGLCD.drawRoundRect (x1, y1, x2, y2);

  myGLCD.setBackColor(255, 0, 0);
  if (setFont) {
    myGLCD.setFont(BigFont); 
    fx = x1+(((x2 - x1+1)-(stl*16))/2);
    fy = y1+(((y2 - y1+1)-16)/2);
    myGLCD.print(text, fx, fy);
  }
  else {
    myGLCD.setFont(RusFont1); 
    fx = x1+(((x2 - x1)-(stl*8))/2);
    fy = y1+(((y2 - y1-1)-6)/2);
    myGLCD.print(text, fx, fy);
  }
}

void printHeader(char* headline)
{
  setFont(LARGE, 255, 255, 0, 255, 255, 0);
  myGLCD.fillRect (1, 1, 638, 20);
  myGLCD.setColor(0, 0, 0);
  myGLCD.print(headline, 5, 4);   
}

void setFont(boolean font, byte cr, byte cg, byte cb, byte br, byte bg, byte bb)
{
  myGLCD.setBackColor(br, bg, bb);    //font background black
  myGLCD.setColor(cr, cg, cb);      //font colour white
  if (font==LARGE)
    myGLCD.setFont(BigFont);     //font size LARGE
  else if (font==SMALL)
    myGLCD.setFont(RusFont1);
}

// Draw a red frame while a button is touched
void waitForIt(int x1, int y1, int x2, int y2)
{
  myGLCD.setColor(255, 0, 0);
  myGLCD.drawRoundRect (x1, y1, x2, y2);
  while (myTouch.dataAvailable()) 
  {
    myTouch.read(); 
  }
  myGLCD.setColor(255, 255, 255);
  myGLCD.drawRoundRect (x1, y1, x2, y2);
}

int NumMins(uint8_t ScheduleHour, uint8_t ScheduleMinute)
{
  return (ScheduleHour*60) + ScheduleMinute;
}
//                   cor,       cor,   cor    locaÃƒÂ§ÃƒÂ£o x1, locaÃƒÂ§ÃƒÂ£o y1, locaÃƒÂ§ÃƒÂ£o x2, locaÃƒÂ§ÃƒÂ£o y2
void desenhar_barras(int sbR, int sbG, int sbB, int sbX1, int sbY1, int sbX2, int sbY2)
{ 
  myGLCD.setColor(sbR, sbG, sbB);          
  myGLCD.fillRect(sbX1, y_tocado, sbX2, sbY2);  
  myGLCD.setColor(0, 0, 0);  
  myGLCD.fillRect(sbX1+1, y_tocado, sbX2-1, sbY1);
  myGLCD.setColor(sbR, sbG, sbB);            
  myGLCD.drawLine(sbX1, sbY1, sbX2, sbY1);
  myGLCD.drawLine(sbX1, sbY2, sbX2, sbY2);  
}

void desenhar_barras_periodo ()
{
  myGLCD.setColor(cor_canal [cor_selecionada][0], cor_canal [cor_selecionada][1], cor_canal [cor_selecionada][2]); 
  myGLCD.drawRect((setor_selecionado * 38)+5, 80, (setor_selecionado * 38)+39, 195); 
  desenhar_barras(cor_canal [cor_selecionada][0], cor_canal [cor_selecionada][1], cor_canal [cor_selecionada][2], (setor_selecionado * 38)+5, 80, (setor_selecionado * 38)+39, 195);
}


