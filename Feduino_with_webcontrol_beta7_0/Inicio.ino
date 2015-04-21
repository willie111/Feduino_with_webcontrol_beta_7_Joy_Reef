//---------------------------------------HOME SCREEN ----------------------------------------------tela =0
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

  setFont(LARGE, 192, 192, 192, 0, 0, 0);
 // myGLCD.print(rtc.getTimeStr(FORMAT_LONG), 630, 446); 
  
      {
      if (t.hour==0) { Hour12 = 12; }                          //12 HR Format
        else {
          if (t.hour>12) { Hour12 = t.hour-12; }
            else { Hour12 = t.hour; }}

      if (Hour12<10)
        { myGLCD.print(" ", 320, 450);
          myGLCD.printNumI(Hour12, 336, 450);}
      else
        { myGLCD.printNumI(Hour12, 320, 450);}
      myGLCD.print(":", 355, 450);
      if (t.min<10)
        { myGLCD.printNumI(0, 371, 450);
          myGLCD.printNumI(t.min, 387, 450);}
      else
        { myGLCD.printNumI(t.min, 371, 450);}

      if(t.hour < 12){ myGLCD.print("AM", 410, 450); }      // Adding the AM/PM sufffix
        else { myGLCD.print("PM", 410, 450); }
    }
  if ((oldval != day) || refreshAll)
  {
    setFont(LARGE, 192, 192, 192, 0, 0, 0);
    myGLCD.print(rtc.getDOWStr(FORMAT_SHORT), 10, 450);
    myGLCD.print(".", 68, 450);    
    myGLCD.print(rtc.getMonthStr(FORMAT_SHORT), 95, 450);
    myGLCD.print(".", 149, 450);   
    myGLCD.printNumI(t.date, 167, 450);
    myGLCD.print(",", 205, 450);    
    myGLCD.printNumI(t.year, 225, 450);
    
    myGLCD.setColor(255, 215, 0);
    myGLCD.print("www.CasualReef.com", 489, 450);
    //myGLCD.print("www.reefcentral.com", 489, 450);
    //myGLCD.print("www.reef2reef.com", 489, 450);
    //myGLCD.print("www.bigbluereef.com", 480, 450);           
    char bufferLP[16];
    LP.toCharArray(bufferLP, 16);

    myGLCD.setColor(0, 255, 255);
    myGLCD.print(bufferLP, 205, 425); // Lunar Phase output

    float lunarCycle = moonPhase(t.year,t.mon, t.date); //get a value for the lunar cycle

      if ((lunarCycle*100) < 0) //Print % of Full to LCD
    { 
      myGLCD.print(" 0.00", 700, 425); 
    }
    else 
    { 
      myGLCD.printNumF(lunarCycle*100, 1, 700, 425);
    }

    myGLCD.setColor(0, 255, 255);
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[181])));
    myGLCD.print(buffer, 489, 425); // "Illumination"
    myGLCD.print("%", 770, 425);

    myGLCD.setColor(0, 255, 255);
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[182])));
    myGLCD.print(buffer, 10, 425); // "Lunar Phase:"
  }
   
  if ( refreshAll == true)                                  // Draw fixed elements
  {
    //myGLCD.setColor(196, 136, 17);
    myGLCD.setColor(255, 215, 0);
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[30])));
    myGLCD.print(buffer, 36, 14); // "FERDUINO AQUATROLLER"
    
    myGLCD.print("L", 27, 60);
    myGLCD.print("E", 27, 75);
    myGLCD.print("D", 27, 90);
    
    myGLCD.print("P", 27, 115);
    myGLCD.print("O", 27, 130);
    myGLCD.print("W", 27, 145);
    myGLCD.print("E", 27, 160);
    myGLCD.print("R", 27, 175);
    
    myGLCD.print("G", 27, 200);
    myGLCD.print("R", 27, 215);
    myGLCD.print("A", 27, 230);
    myGLCD.print("P", 27, 245);
    myGLCD.print("H", 27, 260);

    myGLCD.setColor(192, 192, 192);
    
    myGLCD.print("100", 48, 40); 

    for (int i = 0; i < 90; i += 10)
    {
      myGLCD.printNumI(90-i, 64, 62 + offset);   // 90 to 10
      offset += 22;
    }

    myGLCD.print("0", 80, 260);

    myGLCD.setColor(192, 192, 192);

    myGLCD.drawRect(100, 276, 374, 276);       // Eixo X
    myGLCD.drawRect(100, 56, 100, 276);         // Eixo Y

    for (int i=0; i<10; i++)
    {
      myGLCD.drawLine(102,(i*22)+56,110,(i*22)+56);
    } // Marcador grande 
    myGLCD.setColor(192, 192, 192);  

    for (int i=0; i<10; i++)
    {
      myGLCD.drawLine(102,(i*22)+68,106,(i*22)+68);
    } // Marcador pequeno

    for (int i=0; i<10; i++)
    {
      myGLCD.drawLine(158,(i*22)+56,374,(i*22)+56);
    }// Grade
    
    myGLCD.setColor(192, 192, 192);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[183])));
    myGLCD.print(buffer, 395, 18);  // "Heatsink Temp:"  

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[184])));
    myGLCD.print(buffer, 395, 46); // "Aquarium Temp:"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[185])));
    myGLCD.print(buffer, 395, 74); // "Aquarium H2O pH.:"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[186])));
    myGLCD.print(buffer, 395, 102); // "Calcium Rx. pH.:"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[187])));
    myGLCD.print(buffer, 395, 130); // "Water Density:"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[188])));
    myGLCD.print(buffer, 395, 158); // "Redox Potential:"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[189])));
    myGLCD.print(buffer, 395, 186); // "Water Cooler:"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[190])));
    myGLCD.print(buffer, 395, 214); // "Water Heater:"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[191])));
    myGLCD.print(buffer, 395, 242); // "Calcium Rx.:"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[192])));
    myGLCD.print(buffer, 395, 270); // "Ozone Generator:"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[193])));
    myGLCD.print(buffer, 395, 298); // "AutomaticTopOff:"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[194])));
    myGLCD.print(buffer, 395, 326); // "Reservoir Level:"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[195])));
    myGLCD.print(buffer, 395, 354); // "Auto Water Chng"
    
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[226])));
    myGLCD.print(buffer, 395, 380); // "Tank Room Temp:"    

 if((refreshAll == true) || (web_timer == true))
  {
    web_timer = false;
    if(temporizador_ativado) // TIMER 1
    {
      myGLCD.setColor(192, 192, 192); 
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[31])));
      myGLCD.print(buffer, 10, 288); // RETURN:"
    }
    else
    {
      myGLCD.setColor(64, 64, 64);
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[31])));
      myGLCD.print(buffer, 10, 288); // RETURN:"      
    }

    if(temporizador_ativado) // Timer 2
    {
      myGLCD.setColor(192, 192, 192); 
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[77])));
      myGLCD.print(buffer, 10, 312); // SKIMMER:"
    }
    else
    {
      myGLCD.setColor(64, 64, 64); 
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[77])));
      myGLCD.print(buffer, 10, 312); // SKIMMER:"
    }      

    if(temporizador_ativado) // Timer 3
    {
     myGLCD.setColor(192, 192, 192); 
     strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[78])));
     myGLCD.print(buffer, 10, 336); // CL PUMP:"
    }
    else
    {
     myGLCD.setColor(64, 64, 64); 
     strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[78])));
     myGLCD.print(buffer, 10, 336); // CL PUMP"
    }     

    if(temporizador_ativado) // Timer 4
    {
     myGLCD.setColor(192, 192, 192);
     strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[79])));
     myGLCD.print(buffer, 10, 360); // REFUGEM:"
    }
    else
    {
     myGLCD.setColor(64, 64, 64); 
     strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[79])));
     myGLCD.print(buffer, 10, 360); // REFUGEM:"
    }    

    if(temporizador_ativado) // Timer 5
    {
     myGLCD.setColor(192, 192, 192);
     strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[80])));
     myGLCD.print(buffer, 10, 384); // FRAG:"
    }
    else
    {
     myGLCD.setColor(64, 64, 64);
     strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[80])));
     myGLCD.print(buffer, 10, 384); // FRAG:"
    }
  }     

    myGLCD.setColor(0, 255, 255);

    myGLCD.drawCircle(758, 12, 2);                  // Unidade t. dissipador
    myGLCD.print("F", 765, 18);//myGLCD.print("C", 374, 14); changed for Fahrenheit 
    
    myGLCD.drawCircle(758, 40, 2);                  // Unidade t. ÃƒÂ¡gua
    myGLCD.print("F", 765, 46); //myGLCD.print("C", 374, 28); changed for Fahrenheit 
                         
    myGLCD.print("G/L", 740, 130);                   // Unidade densidade
    myGLCD.print("MV", 747, 158);                    // Unidade ORP

    myGLCD.drawCircle(758, 374, 2);                  // Unidade t. ambiente
    myGLCD.print("F", 765, 380); //myGLCD.print("C", 374, 195);  changed for Fahrenheit 
    

    //myGLCD.setColor(161, 127, 73);
    myGLCD.setColor(0, 0, 255);           // section outlines
    myGLCD.drawRect(5, 5, 385, 412);
    myGLCD.drawRect(4, 4, 386, 413);    
    myGLCD.drawRect(387, 5, 795, 412);
    myGLCD.drawRect(386, 4, 796, 413);
    myGLCD.drawRect(5, 414, 795, 475);
    myGLCD.drawRect(4, 415, 796, 476);
    
    myGLCD.drawRect(3, 3, 797, 477);     // parameter outlines
    myGLCD.drawRect(2, 2, 798, 478);
    myGLCD.setColor(255, 215, 0);
    myGLCD.drawRect(1, 1, 799, 479);
  } // Fim do refreshAll

 
  if ((whiteLed != wled_out) || refreshAll)  // Atualiza grÃƒÂ¡fico led branco    
  {
    whiteLed = wled_out;
    ledLevel = LedToPercent(wled_out);

    myGLCD.setColor(0, 0, 0);
    myGLCD.fillRect(256, 288, 370, 312);   // Apaga potÃƒÂªncia anterior

    myGLCD.setColor(cor_canal1[0], cor_canal1[1], cor_canal1[2]);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(nome_canal[6])));
    myGLCD.print(buffer, 200, 288); // "WHITE"

    offset = map(ledLevel, 100, 0, 56, 274);

    myGLCD.print(":", 295, 288);
    myGLCD.fillRect(116, offset, 158, 274);
    myGLCD.print(String(ledLevel), 311, 288);
    myGLCD.print("%", 360, 288); 

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

    strcpy_P(buffer, (char*)pgm_read_word_near(&(nome_canal[7])));
    myGLCD.print(buffer, 200, 312); //  "GREEN"

    offset = map(ledLevel, 100, 0, 56, 274);
    myGLCD.print(":", 295, 312);
    myGLCD.fillRect(170, offset, 210, 274);
    myGLCD.print(String(ledLevel), 311, 312); 
    myGLCD.print("%", 360, 312); 

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

    strcpy_P(buffer, (char*)pgm_read_word_near(&(nome_canal[8])));
    myGLCD.print(buffer, 200, 336); //  "BLUE"

    offset = map(ledLevel, 100, 0, 56, 274);
    myGLCD.print(":", 295, 336);
    myGLCD.fillRect(222, offset, 262, 274);
    myGLCD.print(String(ledLevel), 311, 336); 
    myGLCD.print("%", 360, 336); 

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

    strcpy_P(buffer, (char*)pgm_read_word_near(&(nome_canal[9])));
    myGLCD.print(buffer, 200, 360); //  "RED"

    offset = map(ledLevel, 100, 0, 56, 274);
    myGLCD.print(":", 295, 360);
    myGLCD.fillRect(274, offset, 314, 274);
    myGLCD.print(String(ledLevel), 311, 360); 
    myGLCD.print("%", 360, 360); 

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

    strcpy_P(buffer, (char*)pgm_read_word_near(&(nome_canal[10])));
    myGLCD.print(buffer, 200, 384); //  "VIOLET"

    offset = map(ledLevel, 100, 0, 56, 274);
    myGLCD.print(":", 295, 384);
    myGLCD.fillRect(326, offset, 366, 274);
    myGLCD.print(String(ledLevel), 311, 384); 
    myGLCD.print("%", 360, 384); 
    
    myGLCD.setColor(0, 0, 0);
    myGLCD.fillRect(326, offset - 1, 366, 54);       // Apaga barra anterior
  }  

  myGLCD.setColor(0, 0, 0);                                        
  myGLCD.fillRect(670, 18, 753, 46);               // Delete heatsink temperature
  myGLCD.fillRect(670, 46, 753, 74);               // Delete water temperature
  myGLCD.fillRect(670, 74, 790, 102);              // Delete pH aquarium 
  myGLCD.fillRect(670, 102, 790, 130);             // Delete pH reactor
  myGLCD.fillRect(670, 130, 710, 158);             // Delete density
  myGLCD.fillRect(670, 158, 710, 186);             // Delete ORP

  myGLCD.fillRect(670, 186, 790, 214);             // Delete notice chiller     on / off
  myGLCD.fillRect(670, 214, 790, 242);             // Delete notice heater      on / off
  myGLCD.fillRect(670, 242, 790, 270);             // Delete notice reactor     on / off
  myGLCD.fillRect(670, 270, 790, 278);             // Delete notice ozone       on / off
  myGLCD.fillRect(670, 278, 790, 306);             // Delete notice Replacement on / off
  myGLCD.fillRect(670, 306, 790, 334);             // Delete notice level   Normal / low
  myGLCD.fillRect(670, 334, 790, 362);             // Delete notice AWC         on / off
  myGLCD.fillRect(670, 362, 750, 408);             // Delete notice ambient temp.

  myGLCD.fillRect(135, 288, 195, 312);              // Delete notice Timer 1     on / off
  myGLCD.fillRect(135, 312, 195, 336);              // Delete notice Timer 2     on / off
  myGLCD.fillRect(135, 336, 195, 360);              // Delete notice Timer 3     on / off
  myGLCD.fillRect(135, 360, 195, 384);              // Delete notice Timer 4     on / off
  myGLCD.fillRect(135, 384, 195, 408);              // Delete notice Timer 5     on / off

  myGLCD.setColor(0, 255, 255);  
  myGLCD.printNumF(tempH, 1, 670, 18);              // Heatsink Temp
  myGLCD.printNumF(tempC, 1, 670, 46);              // Aquarium Temp
  myGLCD.printNumF(PHA, 2, 670, 74);                // Aquarium  pH.
  myGLCD.printNumF(PHR, 2, 670, 102);               // Calc. Rx. pH.
  myGLCD.printNumI(DEN, 670, 130);                  // Water Density
  myGLCD.printNumI(ORP, 670, 158);                  // Redox Potent. 
  myGLCD.printNumF(tempA, 1, 670, 380);             // Ambiente Temp

  myGLCD.setColor(255, 0, 0);

  if (bitRead(status_parametros,2)==true) 
  {                               
    myGLCD.printNumF( tempC, 1, 670, 46);           // Temperature in red
  }  
  if (bitRead(status_parametros,3) == true) 
  {                               
    myGLCD.printNumF(PHA, 2, 670, 74);              // Aquarium pH in red
  }    
  if (bitRead(status_parametros,6) == true) 
  {                                
    myGLCD.printNumF(PHR, 2, 670, 102);             // Reactor pH in red
  }   
  if (bitRead(status_parametros,4) == true) 
  {                                
    myGLCD.printNumI(DEN, 670, 130);                // Density in red
  }
  if (bitRead(status_parametros_1,0) == true) 
  {       
    myGLCD.printNumI(ORP, 670, 158);                // ORP in red
  }  
  if (bitRead(status_parametros,0) == true) 
  {
    myGLCD.setColor(0, 255, 255);
    myGLCD.print(" Active ", 665, 186);                   // chiller on
  }
  else 
  {
    myGLCD.setColor(64, 64, 64);
    myGLCD.print("  OFF ", 670, 186);                  // chiller off
  }
  if (bitRead(status_parametros,1) == true) 
  {
    myGLCD.setColor(0, 255, 255);
    myGLCD.print(" Active ", 665, 214);                   // Heater on
  } 
  else  
  {
    myGLCD.setColor(64, 64, 64);
    myGLCD.print("  OFF ", 670, 214);                  // Heater off
  } 
  if (bitRead(status_parametros,5)== true) 
  {              
    myGLCD.setColor(0, 255, 255);
    myGLCD.print(" Active ", 665, 242);                   // Reactor on
  } 
  else  
  {              
    myGLCD.setColor(64, 64, 64);
    myGLCD.print("  OFF ", 670, 242);                  // Reactor off
  }
  if (bitRead(status_parametros,7) == true) 
  {             
    myGLCD.setColor(0, 255, 255);
    myGLCD.print(" Active ", 665, 270);                   // Ozone on
  } 
  else
  {                
    myGLCD.setColor(64, 64, 64);
    myGLCD.print("  OFF ", 670, 270);                  // Ozone off
  }
  if (bitRead(Status,1) == true) 
  {             
    myGLCD.setColor(0, 255, 255);
    myGLCD.print(" Active ", 665, 298);                   // ATO freshwater container refill on
  }
  else
  {             
    myGLCD.setColor(64, 64, 64);
    myGLCD.print("  OFF ", 670, 298);                  // ATO freshwater container refill off
  }
  if (nivel_status==true) 
  {             
    myGLCD.setColor(255, 0, 0);                    
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[196])));
    myGLCD.print(buffer, 670, 326);                // Low level in red // "LOW!"
  }
  else 
  {             
    myGLCD.setColor(0, 255, 255);
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[197])));
    myGLCD.print(buffer, 665, 326);                // Level nornal // "NORMAL"
  } 
  if ((bitRead(tpa_status,1)== true) && (bitRead(tpa_status,2)== false))
  {             
    myGLCD.setColor(0, 255, 255);
    myGLCD.print(" Active", 665, 354);                  // AWC in progress //250
  }
  else if ((bitRead(tpa_status,1) == false) && (bitRead(tpa_status,2) == false))
  {             
    myGLCD.setColor(64, 64, 64);
    myGLCD.print("  OFF ", 670, 354);                 // AWC not in progress //250
  }
  if (bitRead(tpa_status,2) == true)
  {             
    myGLCD.setColor(255, 0, 0);
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[86])));
    myGLCD.print(buffer, 670, 354);                // Signals failure during a AWC // tabela_textos[86] = "FAIL!"
  } //myGLCD.print("C", 374, 195); /* changed for Fahrenheit */
  if (bitRead(temporizador_status,1) == true)      
  {             
    myGLCD.setColor(0, 255, 255);
    myGLCD.print("ON", 135, 288);                   // Timer 1 on
  }
  else
  {             
    myGLCD.setColor(64, 64, 64);
    myGLCD.print("OFF", 135, 288);                  // Timer 1 off
  }

  if (bitRead(temporizador_status,2) == true)     
  {             
    myGLCD.setColor(0, 255, 255);
    myGLCD.print("ON", 135, 312);                   // Timer 2 on
  }
  else
  {             
    myGLCD.setColor(64, 64, 64);
    myGLCD.print("OFF", 135, 312);                  // Timer 2 off
  }
  if (bitRead(temporizador_status,3) == true)       
  {             
    myGLCD.setColor(0, 255, 255);
    myGLCD.print("ON", 135, 336);                   // Timer 3 on
  }
  else
  {             
    myGLCD.setColor(64, 64, 64);
    myGLCD.print("OFF", 135, 336);                  // Timer 3 off
  }
  if (bitRead(temporizador_status,4) == true)        
  {             
    myGLCD.setColor(0, 255, 255);
    myGLCD.print("ON", 135, 360);                   // Timer 4 on
  }
  else
  {             
    myGLCD.setColor(64, 64, 64);
    myGLCD.print("OFF", 135, 360);                  // Timer 4 off
  }
  if (bitRead(temporizador_status,5) == true)        
  {             
    myGLCD.setColor(0, 255, 255);
    myGLCD.print("ON", 135, 384);                   // Timer 5 on
  }
  else
  {             
    myGLCD.setColor(64, 64, 64);
    myGLCD.print("OFF", 135, 384);                  // Timer 5 off
  }  
  if(temperatura_alta == true)
  {
   myGLCD.setColor(255, 0, 0);
   strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[236])));  // "TEMP. HIGH!"
   myGLCD.print(buffer, 116, 155);                   // LED high temp alert.
  }
  if(temperatura_baixou == true) 
    {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[237]))); // "TEMP. DROPPED!"
    myGLCD.setColor(0, 0, 255);
    myGLCD.print(buffer, 116, 155);                  // Warning that the temperature was high for LEDs.
  }
}
