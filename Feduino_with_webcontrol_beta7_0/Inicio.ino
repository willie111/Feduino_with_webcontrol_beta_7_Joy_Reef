//---------------------------------------Tela inicial ----------------------------------------------tela =0
void mainScreen(boolean refreshAll=false)
{
  int ledLevel, s, u;
  String oldval, rtc1, rtcm, oldano;
  oldval = day;
  oldano = ano;
  int Hour12;
  String ampm;
  day = String(t.date);                             //Atualiza se a data for diferente
  ano = String(t.year);
  int offset = 0;

  setFont(LARGE, 255, 255, 0, 0, 0, 0);
 // myGLCD.print(rtc.getTimeStr(FORMAT_LONG), 630, 454); 
  
      {
      if (t.hour==0) { Hour12 = 12; }                          //12 HR Format
        else {
          if (t.hour>12) { Hour12 = t.hour-12; }
            else { Hour12 = t.hour; }}

      if (Hour12<10)
        { myGLCD.print(" ", 652, 454);
          myGLCD.printNumI(Hour12, 668, 454);}
      else
        { myGLCD.printNumI(Hour12, 652, 454);}
      myGLCD.print(":", 684, 454);
      if (t.min<10)
        { myGLCD.printNumI(0, 700, 454);
          myGLCD.printNumI(t.min, 716, 454);}
      else
        { myGLCD.printNumI(t.min, 700, 454);}
        
   setFont(LARGE, 0, 0, 255, 0, 0, 0);
      if(t.hour < 12){ myGLCD.print(" AM  ", 732, 454); }      //Adding the AM/PM sufffix
        else { myGLCD.print(" PM  ", 732, 454); }
    }
  if ((oldval != day) || refreshAll)
  {
    setFont(LARGE, 255, 255, 0, 0, 0, 0);
    myGLCD.print(rtc.getDOWStr(FORMAT_LONG), 20, 454);
    myGLCD.print("", 70, 454);    
    myGLCD.print(rtc.getMonthStr(FORMAT_SHORT), 198, 454);
    myGLCD.print(".", 252, 454);   
    myGLCD.printNumI(t.date, 270, 454);
    myGLCD.print(",", 308, 454);    
    myGLCD.printNumI(t.year, 328, 454);
    myGLCD.print("REDTOP03", 478, 454);            // I added this line and put in my forum handle, just to help fill the empty space there :)

    char bufferLP[16];
    LP.toCharArray(bufferLP, 16);

    myGLCD.setColor(255, 255, 255);
    myGLCD.print(bufferLP, 196, 426); //Escreve descriÃƒÂ§ÃƒÂ£o da fase lunar

    float lunarCycle = moonPhase(t.year,t.mon, t.date); //get a value for the lunar cycle

      if ((lunarCycle*100) < 0) //Print % of Full to LCD
    { 
      myGLCD.print(" 0.00", 490, 426); 
    }
    else 
    { 
      myGLCD.printNumF(lunarCycle*100, 1, 490, 426);
    }

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[181])));
    myGLCD.print(buffer, 556, 426); // tabela_textos[181] = "% ILUMINADA"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[182])));
    myGLCD.print(buffer, 20, 426); // tabela_textos[182] = "FASE LUNAR:"
  }
   
  if ( refreshAll == true)                                  //Desenha elementos fixos
  {
    myGLCD.setColor(196, 136, 17);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[30])));
    myGLCD.print(buffer, 100, 20); // tabela_textos[30] = "POTENCIA DOS LEDS"

    myGLCD.setColor(192, 236, 255);

    myGLCD.print("100", 48, 40);  

    for (int i = 0; i < 90; i += 10)
    {
      myGLCD.printNumI(90-i, 64, 62 + offset);   // 90 atÃƒÂ© 10
      offset += 22;
    }

    myGLCD.print("0", 80, 260);

    myGLCD.setColor(255, 255, 255);

    myGLCD.drawRect(100, 276, 374, 276);       // Eixo X
    myGLCD.drawRect(100, 56, 100, 276);         // Eixo Y

    for (int i=0; i<10; i++)
    {
      myGLCD.drawLine(102,(i*22)+56,110,(i*22)+56);
    } // Marcador grande 
    myGLCD.setColor(190, 190, 190);  

    for (int i=0; i<10; i++)
    {
      myGLCD.drawLine(102,(i*22)+68,106,(i*22)+68);
    } // Marcador pequeno

    for (int i=0; i<10; i++)
    {
      myGLCD.drawLine(158,(i*22)+56,374,(i*22)+56);
    }// Grade
    
    myGLCD.setColor(255, 255, 255);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[183])));
    myGLCD.print(buffer, 424, 28);  // tabela_textos[183] = "T.DISSIPADOR:"  

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[184])));
    myGLCD.print(buffer, 424, 56); // tabela_textos[184] = "TEMP. AGUA:"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[185])));
    myGLCD.print(buffer, 424, 84); // tabela_textos[185] = "PH DO AQUARIO:"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[186])));
    myGLCD.print(buffer, 424, 112); // tabela_textos[186] =  "PH DO REATOR:"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[187])));
    myGLCD.print(buffer, 424, 140); // tabela_textos[187] = "DENSIDADE:"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[188])));
    myGLCD.print(buffer, 424, 168); // tabela_textos[188] = "ORP:"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[189])));
    myGLCD.print(buffer, 424, 196); // tabela_textos[189] = "CHILLER:"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[190])));
    myGLCD.print(buffer, 424, 224); // tabela_textos[190] = "AQUECEDOR:"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[191])));
    myGLCD.print(buffer, 424, 252); // tabela_textos[191] = "REATOR:"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[192])));
    myGLCD.print(buffer, 424, 280); // tabela_textos[192] = "OZONIO:"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[193])));
    myGLCD.print(buffer, 424, 308); // tabela_textos[193] = "REPOSICAO:"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[194])));
    myGLCD.print(buffer, 424, 336); // tabela_textos[194] = "NIVEL:"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[195])));
    myGLCD.print(buffer, 424, 364); // tabela_textos[195] = "TPA:" // Troca de Ãƒï¿½gua Parcial
    
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[226])));
    myGLCD.print(buffer, 424, 390); // tabela_textos[226] = "T. AMBIENTE:"    

    if(temporizador_1_ativado == 1)
    {
      myGLCD.setColor(0, 130, 255); 
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[31])));
      myGLCD.print(buffer, 24, 288); // tabela_textos[31] = "TIMER 1:"
    }
    else
    {
      myGLCD.setColor(255, 255, 255);
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[31])));
      myGLCD.print(buffer, 24, 288); // tabela_textos[31] = "TIMER 1:"      
    }

    if(temporizador_2_ativado == 1)
    {
      myGLCD.setColor(0, 130, 255); 
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[77])));
      myGLCD.print(buffer, 24, 312); // tabela_textos[77] = "TIMER 2:"
    }
    else
    {
      myGLCD.setColor(255, 255, 255); 
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[77])));
      myGLCD.print(buffer, 24, 312); // tabela_textos[77] = "TIMER 2:"
    }      

    if(temporizador_3_ativado == 1)
    {
     myGLCD.setColor(0, 130, 255); 
     strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[78])));
     myGLCD.print(buffer, 24, 336); // tabela_textos[78] = "TIMER 3:"
    }
    else
    {
     myGLCD.setColor(255, 255, 255); 
     strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[78])));
     myGLCD.print(buffer, 24, 336); // tabela_textos[78] = "TIMER 3:"
    }     

    if(temporizador_4_ativado == 1)
    {
     myGLCD.setColor(0, 130, 255); 
     strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[79])));
     myGLCD.print(buffer, 24, 360); // tabela_textos[79] = "TIMER 4:"
    }
    else
    {
     myGLCD.setColor(255, 255, 255); 
     strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[79])));
     myGLCD.print(buffer, 24, 360); // tabela_textos[79] = "TIMER 4:"
    }    

    if(temporizador_5_ativado == 1)
    {
     myGLCD.setColor(0, 130, 255);
     strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[80])));
     myGLCD.print(buffer, 24, 384); // tabela_textos[80] = "TIMER 5:"
    }
    else
    {
     myGLCD.setColor(255, 255, 255);
     strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[80])));
     myGLCD.print(buffer, 24, 384); // tabela_textos[80] = "TIMER 5:"
    }     

    myGLCD.setColor(0, 255, 0);

    myGLCD.drawCircle(745, 22, 2);                  // Unidade t. dissipador
    myGLCD.print("F", 755, 28);
    //myGLCD.print("C", 374, 14);  /******************************************************** changed for Fahrenheit *******************************************************************/

    myGLCD.drawCircle(745, 50, 2);                  // Unidade t. ÃƒÂ¡gua
    myGLCD.print("F", 755, 56);    /******************************************************** changed for Fahrenheit *******************************************************************/
    //myGLCD.print("C", 374, 28);                     // Unidade t. ÃƒÂ¡gua

    myGLCD.print("G/L", 733, 140);                   // Unidade densidade
    myGLCD.print("MV", 740, 168);                    // Unidade ORP

    myGLCD.drawCircle(745, 384, 2);                  // Unidade t. ambiente
    myGLCD.print("F", 755, 390);
    //myGLCD.print("C", 374, 195); /******************************************************** changed for Fahrenheit *******************************************************************/


    myGLCD.setColor(161, 127, 73);                  
    myGLCD.drawRect(14, 10, 398, 416);                // Desenhar retÃƒÂ¢ngulos
    myGLCD.drawRect(412, 10, 784, 416);
  } // Fim do refreshAll

 
  if ((whiteLed != wled_out) || refreshAll)  // Atualiza grÃƒÂ¡fico led branco    
  {
    whiteLed = wled_out;
    ledLevel = LedToPercent(wled_out);

    myGLCD.setColor(0, 0, 0);
    myGLCD.fillRect(256, 288, 370, 312);   // Apaga potÃƒÂªncia anterior

    myGLCD.setColor(cor_canal1[0], cor_canal1[1], cor_canal1[2]);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(nome_canal[1])));
    myGLCD.print(buffer, 256, 288); // nome_canal[1] = "BRA"

    offset = map(ledLevel, 100, 0, 56, 274);

    myGLCD.print(":", 304, 288);
    myGLCD.fillRect(116, offset, 158, 274);
    myGLCD.print(String(ledLevel), 320, 288);
    myGLCD.print("%", 372, 288); 

    myGLCD.setColor(0, 0, 0);
    myGLCD.fillRect(116, offset -1, 158, 54);      // Apaga barra anterior
  }
  if ((blueLed != bled_out) || refreshAll)       // Atualiza grÃƒÂ¡fico led azul
  {
    blueLed = bled_out;
    ledLevel = LedToPercent(bled_out);

    myGLCD.setColor(0, 0, 0);
    myGLCD.fillRect(256, 312, 370, 336);     // Apaga potÃƒÂªncia anterior

    myGLCD.setColor(cor_canal2[0], cor_canal2[1], cor_canal2[2]);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(nome_canal[2])));
    myGLCD.print(buffer, 256, 312); // nome_canal[2] = "AZU"

    offset = map(ledLevel, 100, 0, 56, 274);
    myGLCD.print(":", 304, 312);
    myGLCD.fillRect(170, offset, 210, 274);
    myGLCD.print(String(ledLevel), 320, 312); 
    myGLCD.print("%", 372, 312); 

    myGLCD.setColor(0, 0, 0);

    myGLCD.fillRect(170, offset - 1, 210, 54);       // Apaga barra anterior
  }
  if ((azulroyalLed != rbled_out) || refreshAll)      // Atualiza grÃƒÂ¡fico led azul royal
  {
    azulroyalLed = rbled_out;
    ledLevel = LedToPercent(rbled_out);

    myGLCD.setColor(0, 0, 0);
    myGLCD.fillRect(256, 336, 370, 360);     // Apaga potÃƒÂªncia anterior

    myGLCD.setColor(cor_canal3[0], cor_canal3[1], cor_canal3[2]);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(nome_canal[3])));
    myGLCD.print(buffer, 256, 336); // nome_canal[3] = "AZR"

    offset = map(ledLevel, 100, 0, 56, 274);
    myGLCD.print(":", 304, 336);
    myGLCD.fillRect(222, offset, 262, 274);
    myGLCD.print(String(ledLevel), 320, 336); 
    myGLCD.print("%", 372, 336); 

    myGLCD.setColor(0, 0, 0);

    myGLCD.fillRect(222, offset - 1, 262, 54);      // Apaga barra anterior
  }
  if ((vermelhoLed != rled_out) || refreshAll)    // Atualiza grÃƒÂ¡fico led  vermelho 
  {
    vermelhoLed = rled_out;
    ledLevel = LedToPercent(rled_out);

    myGLCD.setColor(0, 0, 0);
    myGLCD.fillRect(256, 360, 370, 384);     // Apaga potÃƒÂªncia anterior

    myGLCD.setColor(cor_canal4[0], cor_canal4[1], cor_canal4[2]);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(nome_canal[4])));
    myGLCD.print(buffer, 256, 360); // nome_canal[4] = "VER"

    offset = map(ledLevel, 100, 0, 56, 274);
    myGLCD.print(":", 304, 360);
    myGLCD.fillRect(274, offset, 314, 274);
    myGLCD.print(String(ledLevel), 320, 360); 
    myGLCD.print("%", 372, 360); 

    myGLCD.setColor(0, 0, 0);

    myGLCD.fillRect(274, offset - 1, 314, 54);      // Apaga barra anterior
  }
  if ((violetaLed != uvled_out) || refreshAll)      // Atualiza grÃƒÂ¡fico led violeta
  {
    violetaLed = uvled_out;
    ledLevel = LedToPercent(uvled_out);

    myGLCD.setColor(0, 0, 0);
    myGLCD.fillRect(256, 384, 370, 408);      // Apaga potÃƒÂªncia anterior
    
    myGLCD.setColor(cor_canal5[0], cor_canal5[1], cor_canal5[2]);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(nome_canal[5])));
    myGLCD.print(buffer, 256, 384); // nome_canal[5] = "VIO"

    offset = map(ledLevel, 100, 0, 56, 274);
    myGLCD.print(":", 304, 384);
    myGLCD.fillRect(326, offset, 366, 274);
    myGLCD.print(String(ledLevel), 320, 384); 
    myGLCD.print("%", 372, 384); 
    
    myGLCD.setColor(0, 0, 0);
    myGLCD.fillRect(326, offset - 1, 366, 54);       // Apaga barra anterior
  }  

  myGLCD.setColor(0, 0, 0);                        // do not alter values                  
  myGLCD.fillRect(650, 28, 706, 52);               // Delete heatsink temperature
  myGLCD.fillRect(650, 64, 640, 80);               // Delete water temperature
  myGLCD.fillRect(650, 84, 780, 108);              // Delete pH aquarium 
  myGLCD.fillRect(650, 112, 780, 136);             // Delete pH reactor
  myGLCD.fillRect(650, 140, 660, 164);             // Delete density
  myGLCD.fillRect(650, 168, 554, 192);             // Delete ORP

  myGLCD.fillRect(650, 196, 660, 220);             // Delete notice chiller     on / off
  myGLCD.fillRect(650, 112, 700, 248);             // Delete notice heater      on / off
  myGLCD.fillRect(650, 252, 640, 276);             // Delete notice reactor     on / off
  myGLCD.fillRect(650, 280, 640, 304);             // Delete notice ozone       on / off
  myGLCD.fillRect(650, 308, 700, 332);             // Delete notice Replacement on / off
  myGLCD.fillRect(650, 336, 780, 360);             // Delete notice level   Normal / low
  myGLCD.fillRect(650, 368, 730, 386);             // Delete notice AWC         on / off
  myGLCD.fillRect(650, 390, 720, 414);             // Delete notice power consumption

  myGLCD.fillRect(160, 288, 220, 312);              // Delete notice Timer 1     on / off
  myGLCD.fillRect(160, 312, 220, 336);              // Delete notice Timer 2     on / off
  myGLCD.fillRect(160, 336, 220, 360);              // Delete notice Timer 3     on / off
  myGLCD.fillRect(160, 360, 220, 384);              // Delete notice Timer 4     on / off
  myGLCD.fillRect(160, 384, 220, 408);              // Delete notice Timer 5     on / off

  myGLCD.setColor(0, 255, 0);  
  myGLCD.printNumF(tempH, 2, 650, 28);   // Temperatura dissipador
  myGLCD.printNumF(tempC, 2, 650, 56);   // Temperatura da agua
  myGLCD.printNumF(PHA, 2, 650, 84);     // PH aqua
  myGLCD.printNumF(PHR, 2, 650, 112);    // PH reator
  myGLCD.printNumI(DEN, 650, 140);       // Densidade
  myGLCD.printNumI(ORP, 650, 168);       // ORP 
  myGLCD.printNumF(tempA, 2, 650, 390);  // Temperatura ambiente

  myGLCD.setColor(255, 0, 0);

  if (bitRead(status_parametros,2)==true) 
  {                               
    myGLCD.printNumF( tempC, 2, 650, 56);          // Temperature in red
  }  
  if (bitRead(status_parametros,3) == true) 
  {                               
    myGLCD.printNumF(PHA, 2, 650, 84);             // Aquarium pH in red
  }    
  if (bitRead(status_parametros,6) == true) 
  {                                
    myGLCD.printNumF(PHR, 2, 650, 112);             // Reactor pH in red
  }   
  if (bitRead(status_parametros,4) == true) 
  {                                
    myGLCD.printNumI(DEN, 650, 140);                // Density in red
  }
  if (bitRead(status_parametros_1,0) == true) 
  {       
    myGLCD.printNumI(ORP, 650, 168);                // ORP in red
  }  
  if (bitRead(status_parametros,0) == true) 
  {
    myGLCD.setColor(0, 130, 255);
    myGLCD.print("ON", 650, 196);                   // chiller on
  }
  else 
  {
    myGLCD.setColor(0, 255, 0);
    myGLCD.print("OFF", 650, 196);                  // chiller off
  }
  if (bitRead(status_parametros,1) == true) 
  {
    myGLCD.setColor(0, 130, 255);
    myGLCD.print("ON", 650, 224);                  // Heater on
  } 
  else  
  {
    myGLCD.setColor(0, 255, 0);
    myGLCD.print("OFF", 650, 224);                 // Heater off
  } 
  if (bitRead(status_parametros,5)== true) 
  {              
    myGLCD.setColor(0, 130, 255);
    myGLCD.print("ON", 650, 252);                  // Reactor on
  } 
  else  
  {              
    myGLCD.setColor(0, 255, 0);
    myGLCD.print("OFF", 650, 252);                 // Reactor off
  }
  if (bitRead(status_parametros,7) == true) 
  {             
    myGLCD.setColor(0, 130, 255);
    myGLCD.print("ON", 650, 280);                  // Ozone on
  } 
  else
  {                
    myGLCD.setColor(0, 255, 0);
    myGLCD.print("OFF", 650, 280);                 // Ozone off
  }
  if (bitRead(Status,1) == true) 
  {             
    myGLCD.setColor(0, 130, 255);
    myGLCD.print("ON", 650, 308);                  // ATO freshwater container refill on
  }
  else
  {             
    myGLCD.setColor(0, 255, 0);
    myGLCD.print("OFF", 650, 308);                 // ATO freshwater container refill off
  }
  if (nivel_status==true) 
  {             
    myGLCD.setColor(255, 0, 0);                    // alter placement values for screen "names" for 400x240 screen, format is as follows: myGLCD.print("screen name", 1~400 = left/right, 1~240 = top/bottom )
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[196])));
    myGLCD.print(buffer, 650, 336);                // Low level in red // tabela_textos[196] = "LOW!"
  }
  else 
  {             
    myGLCD.setColor(0, 255, 0);
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[197])));
    myGLCD.print(buffer, 650, 336);                // Level nornal // tabela_textos[197] = "NORMAL"
  } 
  if ((bitRead(tpa_status,1)== true) && (bitRead(tpa_status,2)== false))
  {             
    myGLCD.setColor(0, 130, 255);
    myGLCD.print("ON", 650, 364);                  // AWC in progress //250
  }
  else if ((bitRead(tpa_status,1) == false) && (bitRead(tpa_status,2) == false))
  {             
    myGLCD.setColor(0, 255, 0);
    myGLCD.print("OFF", 650, 364);                 // AWC not in progress //250
  }
  if (bitRead(tpa_status,2) == true)
  {             
    myGLCD.setColor(255, 0, 0);
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[86])));
    myGLCD.print(buffer, 650, 364);                // Signals failure during a AWC // tabela_textos[86] = "FAIL!"
  } //*******************************************************************************************************// Timer control, change to "true" for always off/ "false" for always on
  if (bitRead(temporizador_status,1) == true)      
  {             
    myGLCD.setColor(0, 130, 255);
    myGLCD.print("ON", 160, 288);                   // Timer 1 on
  }
  else
  {             
    myGLCD.setColor(0, 255, 0);
    myGLCD.print("OFF", 160, 288);                  // Timer 1 off
  }

  if (bitRead(temporizador_status,2) == true)     
  {             
    myGLCD.setColor(0, 130, 255);
    myGLCD.print("ON", 160, 312);                   // Timer 2 on
  }
  else
  {             
    myGLCD.setColor(0, 255, 0);
    myGLCD.print("OFF", 160, 312);                  // Timer 2 off
  }
  if (bitRead(temporizador_status,3) == true)       
  {             
    myGLCD.setColor(0, 130, 255);
    myGLCD.print("ON", 160, 336);                   // Timer 3 on
  }
  else
  {             
    myGLCD.setColor(0, 255, 0);
    myGLCD.print("OFF", 160, 336);                  // Timer 3 off
  }
  if (bitRead(temporizador_status,4) == true)        
  {             
    myGLCD.setColor(0, 130, 255);
    myGLCD.print("ON", 160, 360);                   // Timer 4 on
  }
  else
  {             
    myGLCD.setColor(0, 255, 0);
    myGLCD.print("OFF", 160, 360);                  // Timer 4 off
  }
  if (bitRead(temporizador_status,5) == true)        
  {             
    myGLCD.setColor(0, 130, 255);
    myGLCD.print("ON", 160, 384);                   // Timer 5 on
  }
  else
  {             
    myGLCD.setColor(0, 255, 0);
    myGLCD.print("OFF", 160, 384);                  // Timer 5 off
  }  
  if(temperatura_alta == true)
  {
   myGLCD.setColor(255, 0, 0);
   strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[236])));  // "TEMP. HIGH!"
   myGLCD.print(buffer, 116, 180);                   // LED high temp alert.
  }
  if(temperatura_baixou == true) 
    {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[237]))); // "TEMP. LOW!"
    myGLCD.setColor(0, 255, 0);
    myGLCD.print(buffer, 116, 180);                  // Warning that the temperature was high for LEDs.
  }
}






