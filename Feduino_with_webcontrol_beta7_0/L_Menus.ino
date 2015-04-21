//------------------------------------ Menu 1 ----------------------------------------------------------- tela =1
void menuScreen()
{
  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[1])));
  printHeader(buffer); // tabela_textos[1] = "MENU 1";

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[3])));
  printButton(buffer, tanD[0], tanD[1], tanD[2], tanD[3]); // "TIME & DATE"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[201])));
  printButton(buffer, tesT[0], tesT[1], tesT[2], tesT[3]); // "CONFIG. LEDS"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[5])));
  printButton(buffer, temC[0], temC[1], temC[2], temC[3]); // "CONTROL PARAM."

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[6])));
  printButton(buffer, graF[0], graF[1], graF[2], graF[3]); // "GRAPHS"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[160])));
  printButton(buffer, ledW[0], ledW[1], ledW[2], ledW[3]); // "TIMERS"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[8])));
  printButton(buffer, tpaA[0], tpaA[1], tpaA[2], tpaA[3]); // "AUTO WATER CHANGE"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[9])));
  printButton(buffer, dosA[0], dosA[1], dosA[2], dosA[3]); // "DOSERS"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[10])));
  printButton(buffer, wavM[0], wavM[1], wavM[2], wavM[3]); // "WAVEMAKER"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[11])));
  printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3]); // "HOME"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[2])));
  printButton(buffer, menU[0], menU[1], menU[2], menU[3]); // "MENU 2";
}

// ------------------------- RTC ------------------------------------------------------ tela =2
void setClock()
{
  t_temp = rtc.getTime();

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[12])));
  printHeader(buffer); // change date and time"

  printButton ("+", houU[0], houU[1], houU[2], houU[3], true); //hour up
  printButton ("-", houD[0], houD[1], houD[2], houD[3], true); //hour down

  printButton ("+", minU[0], minU[1], minU[2], minU[3], true); //min up
  printButton ("-", minD[0], minD[1], minD[2], minD[3], true); //min down

  printButton ("+", segC[0], segC[1], segC[2], segC[3], true); //segundo mais
  printButton ("-", segB[0], segB[1], segB[2], segB[3], true); //segundo menos

  printButton ("+", yeaU[0], yeaU[1], yeaU[2], yeaU[3], true); //year up
  printButton ("-", yeaD[0], yeaD[1], yeaD[2], yeaD[3], true); //year down

  printButton ("-", dayD[0], dayD[1], dayD[2], dayD[3], true); //day down
  printButton ("+", dayU[0], dayU[1], dayU[2], dayU[3], true); //day up

  printButton ("+", monU[0], monU[1], monU[2], monU[3], true); //month up
  printButton ("-", monD[0], monD[1], monD[2], monD[3], true); //month down

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[13])));
  printButton(buffer, prOK[0], prOK[1], prOK[2], prOK[3]); // "SAVE"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[11])));
  printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3]); // "HOME"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[1])));
  printButton(buffer, menU[0], menU[1], menU[2], menU[3]); // "MENU 1";

  setFont(LARGE, 255, 255, 255, 0, 0, 0);

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[14])));
  myGLCD.print(buffer, 20, 102); // "TIME:"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[15])));
  myGLCD.print(buffer, 20, 268); // "DATE:"

  setFont(LARGE, 255, 255, 255, 0, 0, 0);
  myGLCD.print(":", 240, 102);
  myGLCD.print(":", 420, 102);

  if (t_temp.hour<10)
  {
    myGLCD.printNumI(0, 152, 102);
    myGLCD.printNumI(t_temp.hour, 168, 102);
  }
  else
  {
    myGLCD.printNumI(t_temp.hour, 152, 102);
  } 
  if (t_temp.min<10)
  {
    myGLCD.printNumI(0, 332, 102);
    myGLCD.printNumI(t_temp.min, 348, 102);
  }
  else
  {
    myGLCD.printNumI(t_temp.min, 332, 102);
  } 
  if (t_temp.sec<10)
  {
    myGLCD.printNumI(0, 512, 102);
    myGLCD.printNumI(t_temp.sec, 528, 102);
  }
  else
  {
    myGLCD.printNumI(t_temp.sec, 512, 102);
  }
  if (t_temp.date<10)
  {
    myGLCD.printNumI(0, 152, 268);
    myGLCD.printNumI(t_temp.date, 168, 268);
  }
  else
  {
    myGLCD.printNumI(t_temp.date, 152, 268);
  }
  if (t_temp.mon<10)
  {
    myGLCD.printNumI(0, 332, 268);
    myGLCD.printNumI(t_temp.mon, 348, 268);
  }
  else
  {
    myGLCD.printNumI(t_temp.mon, 332, 268);
  }
  myGLCD.printNumI(t_temp.year, 492, 268);

}

void testScreen(boolean refreshAll=false)//-------------------------------- Teste do leds ------------------------------------- tela =3
{    
  char bufferL[9];
  String led;

  if (refreshAll == true) 
  {  
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[16])));
    printHeader(buffer); // tabela_textos[16] "TESTAR VARIACAO DE LUMINOSIDADE"
    myGLCD.fillRect (1, 30, 636, 74);      //clear 'Test in progress'
    printButton ("", stsT[0], stsT[1], stsT[2], stsT[3], true);   //start/stop
    printButton ("-10s", tenM[0], tenM[1], tenM[2], tenM[3], true);     //-10s
    printButton ("+10s", tenP[0], tenP[1], tenP[2], tenP[3], true);   //+10s

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[17])));
    myGLCD.print(buffer, stsT[0]+10, stsT[1]+15); // "INICIAR"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[18])));
    myGLCD.print(buffer, stsT[0]+25, stsT[1]+40);  // "TESTE"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[11])));    
    printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3]);  // "INICIO"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[1])));
    printButton(buffer, menU[0], menU[1], menU[2], menU[3]); // "MENU 1";

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[66])));
    printButton(buffer, volT[0], volT[1], volT[2], volT[3]);  // tabela_textos[66] = "VOLTAR"
  } 
  else
  {
    if(teste_iniciado == true)
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[19])));
      printHeader(buffer); // "TEST VARIATION OF ILLUMINATION"
      printButton ("", stsT[0], stsT[1], stsT[2], stsT[3], true); //start/stop
      printButton ("-10s", tenM[0], tenM[1], tenM[2], tenM[3], true); //-10s
      printButton ("+10s", tenP[0], tenP[1], tenP[2], tenP[3], true); //+10s

      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[17])));
      myGLCD.print(buffer, stsT[0]+10, stsT[1]+15); // "START"

      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[18])));
      myGLCD.print(buffer, stsT[0]+25, stsT[1]+40); // "TEST"
      min_cnt=0;

      myGLCD.setColor(0, 0, 200);
      myGLCD.fillRect(stsT[0]+10, stsT[1]+10, stsT[2]-10, stsT[3]-80); //clear 'start'
      setFont(LARGE, 255, 255, 255, 0, 0, 200);

      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[20])));
      myGLCD.print(buffer, stsT[0]+25, stsT[1]+15); // "STOP"

      myGLCD.setColor(255, 0, 0);
      myGLCD.fillRect (1, 30, 636, 74);
      myGLCD.drawRoundRect (stsT[0], stsT[1], stsT[2], stsT[3]); //red button during test
      setFont(LARGE, 255, 255, 255, 255, 0, 0);

      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[21])));
      myGLCD.print(buffer, 30, 36); // "TEST IN PROGRESS"

      setFont(LARGE, 255, 255, 255, 0, 0, 0);

      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[22])));
      myGLCD.print(buffer, 66, 80); // "TIME:"

      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[23])));
      myGLCD.print(buffer, 60, 80); // "OUTPUT POWER (0-255):"
    }

    if (LEDtestTick == true)               //test LED and speed up time
    {
      if (millis() - previousMillis > 500)    //change time every 0.5s
      {
        previousMillis = millis();

        min_cnt++;

        if (min_cnt > 1439) 
        {
          min_cnt = 0;
        }

        int hour = min_cnt/60;
        int minut = min_cnt%60;

        setFont(LARGE, 255, 255, 255, 0, 0, 0);

        myGLCD.print(":", 104, 110);

        if(hour >= 10)
        {
          myGLCD.printNumI(hour, 64, 110);
        }
        else
        {
          myGLCD.print("0", 64, 110);
          myGLCD.printNumI(hour, 80, 110);
        }
        if(minut >= 10)
        {
          myGLCD.printNumI(minut, 128, 110);
        }
        else
        {
          myGLCD.print("0", 128, 110);
          myGLCD.printNumI(minut, 144, 110);
        }

        myGLCD.setColor(cor_canal1[0], cor_canal1[1], cor_canal1[2]);
        strcpy_P(buffer, (char*)pgm_read_word_near(&(nome_canal[1])));
        led = buffer + String(":") + String(wled_out) + " "; // Led White
        led.toCharArray(bufferL, 9);
        myGLCD.print(bufferL, 360, 110);

        myGLCD.setColor(cor_canal2[0], cor_canal2[1], cor_canal2[2]);
        strcpy_P(buffer, (char*)pgm_read_word_near(&(nome_canal[2])));
        led = buffer + String(":") + String(bled_out) + " "; // Led Green
        led.toCharArray(bufferL, 9);
        myGLCD.print(bufferL, 360, 150);

        myGLCD.setColor(cor_canal3[0], cor_canal3[1], cor_canal3[2]);
        strcpy_P(buffer, (char*)pgm_read_word_near(&(nome_canal[3])));
        led = buffer + String(":") + String(rbled_out) + " "; // Led Blue
        led.toCharArray(bufferL, 9);
        myGLCD.print(bufferL, 360, 190);

        myGLCD.setColor(cor_canal4[0], cor_canal4[1], cor_canal4[2]);
        strcpy_P(buffer, (char*)pgm_read_word_near(&(nome_canal[4])));
        led = buffer + String(":") + String(rled_out) + " "; // Led Red
        led.toCharArray(bufferL, 9);
        myGLCD.print(bufferL, 360, 230);

        myGLCD.setColor(cor_canal5[0], cor_canal5[1], cor_canal5[2]);
        strcpy_P(buffer, (char*)pgm_read_word_near(&(nome_canal[5])));
        led = buffer + String(":") + String(uvled_out) + " "; // Led Violet
        led.toCharArray(bufferL, 9);
        myGLCD.print(bufferL, 360, 270);
      }
    }
  } 
}

//--------------------------------------------- Temperatura -------------------------------- tela =4 
void tempScreen(boolean refreshAll=false)
{

  if (refreshAll)
  {
    if (setTempC==0) {
      setTempC = tempC;  
    }                  //change to current temp.
    temp2beS = setTempC;
    temp2beO = offTempC;
    temp2beA = alarmTempC;

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[24])));
    printHeader(buffer); //tabela_textos[24] "WATER TEMPERATURE CONTROL"

    setFont(LARGE, 255, 255, 255, 0, 0, 0);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[74])));
    myGLCD.print(buffer, 170, 40); // "DESIRED TEMPERATURE:"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[75])));
    myGLCD.print(buffer, 173, 140); // "ALLOWABLE VARIATION:"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[76])));
    myGLCD.print(buffer, 100, 240); // "VARIATION TO ACTIVATE ALARM:"

    printButton("-", temM[0], temM[1], temM[2], temM[3], true);      //temp minus
    printButton("+", temP[0], temP[1], temP[2], temP[3], true);      //temp plus
    printButton("-", offM[0], offM[1], offM[2], offM[3], true);      //offset minus
    printButton("+", offP[0], offP[1], offP[2], offP[3], true);      //offset plus
    printButton("-", almM[0], almM[1], almM[2], almM[3], true);      //alarm minus
    printButton("+", almP[0], almP[1], almP[2], almP[3], true);      //alarm plus

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[13])));
    printButton(buffer, prOK[0], prOK[1], prOK[2], prOK[3]); // "SAVE"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[11])));
    printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3]);  // "HOME"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[66])));
    printButton(buffer, menU[0], menU[1], menU[2], menU[3]);
  }

  setFont(LARGE, 255, 255, 255, 0, 0, 0);
  myGLCD.printNumF(temp2beS, 1, 282, 80);
  myGLCD.printNumF(temp2beO, 1, 285, 180);
  myGLCD.printNumF(temp2beA, 1, 285, 280);
}
void ledSetScreen()   //-------------------------------- ALTER LED OUTPUT ----------------------------------- tela =5
{
  int a;

  if (cor_selecionada == 0) 
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(nome_canal[17])));
    printHeader(buffer); // "WHITE LED POWER: 255 = 100%"
  }
  else if (cor_selecionada == 1)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(nome_canal[18])));
    printHeader(buffer); // "GREEN LED POWER: 255 = 100%"
  }
  else if (cor_selecionada == 2)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(nome_canal[19])));
    printHeader(buffer); // "BLUE LED POWER: 255 = 100%"
  }
  else if (cor_selecionada == 3)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(nome_canal[20])));
    printHeader(buffer); // "RED LED POWER: 255 = 100%"
  }
  else if (cor_selecionada == 4)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(nome_canal[21])));
    printHeader(buffer); // "VIOLET LED POWER: 255 = 100%"
  } 

  setFont(LARGE, 255, 255, 255, 0, 0, 0);
  for (int i = 0; i < 12; i++) 
  {
    myGLCD.setColor(0, 255, 255);
    myGLCD.printNumI((i*2), (i*52)+26, 44); 
    if(i == 11)
    {
      myGLCD.print("0", (i*52)+34, 72);
    }
    else
    {
      myGLCD.printNumI(((i*2)+2), (i*52)+26, 72);
    }
    for (int j=0; j<8; j++) 
    {
      a = (i*8)+j;         
      myGLCD.setColor(255, 255, 255);
      myGLCD.printNumI(cor[cor_selecionada][a], (i*52)+14, (j*36)+108);
      myGLCD.setColor(100, 100, 100);
      myGLCD.drawRect((i*52)+8, (j*36)+100, (i*52)+60, (j*36)+136);
      myGLCD.drawRect((i*52)+8, 32, (i*52)+60, 100);//
    }
  }

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[81])));
  printButton(buffer, leST[0], leST[1], leST[2], leST[3], SMALL); // "ALTER"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[82])));
  printButton(buffer, savE[0], savE[1], savE[2], savE[3], SMALL); // "SAVE TO EEPROM"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[1])));
  printButton(buffer, menU[0], menU[1], menU[2], menU[3]); // "MENU 1";

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[11])));
  printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3]); // "HOME"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[210])));
  printButton(buffer, leWB[0], leWB[1], leWB[2], leWB[3], SMALL); // "MORE"
}

void ledChangeScreen(boolean refreshAll=false)    //-------------------------- POWER OF LED ------------------------------ tela =6
{
  if(refreshAll == true)
  {
    mensagem = true;
    if (cor_selecionada == 0)
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(nome_canal[12])));
      printHeader(buffer); // nome_canal[12] = "WHITE"
    }
    else if (cor_selecionada == 1)
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(nome_canal[13])));
      printHeader(buffer); // nome_canal[13] = "GREEN"
    }
    else if (cor_selecionada == 2)
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(nome_canal[14])));
      printHeader(buffer); // nome_canal[14] = "BLUE"
    }
    else if (cor_selecionada == 3)
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(nome_canal[15])));
      printHeader(buffer); // nome_canal[15] = "RED"
    }
    else if (cor_selecionada == 4)
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(nome_canal[16])));
      printHeader(buffer); // nome_canal[16] = "VIOLET"
    }

    setFont(LARGE, 0, 255, 255, 0,0,0);
    for (int i=0; i<12; i++) 
    {
      myGLCD.setColor(0, 255, 255);
      myGLCD.printNumI(((i*2)), (i*52)+26, 44);
      if(i == 11)
      {
        myGLCD.print("0", (i*52)+34, 66);
      }
      else
      {
        myGLCD.printNumI(((i*2)+2), (i*52)+26, 66);
      }

      myGLCD.setColor(100, 100, 100);
      myGLCD.drawRect((i*52)+8, 40 , (i*52)+60, 90);
    }

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[13])));
    printButton(buffer, salV[0], salV[1], salV[2], salV[3]); // "SAVE"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[11])));
    printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3]); // "HOME"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[1])));
    printButton(buffer, menU[0], menU[1], menU[2], menU[3]); // "MENU 1";

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[66])));
    printButton(buffer, volT[0], volT[1], volT[2], volT[3]); // "BACK"

    setFont(LARGE, 255, 0, 0, 0, 0, 0);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[203])));
    myGLCD.print(buffer,100, 210); // "SELECT A PERIOD."

  }

  if(periodo_selecionado == true)
  {
    for (int i=0; i<8; i++)
    { 
      printButton("+", (i*76)+10, 100, (i*76)+78, 150, LARGE);
      printButton("-", (i*76)+10, 428, (i*76)+78, 478, LARGE);
    }
  }
  if((mensagem == true) && (periodo_selecionado == true))
  {
    mensagem = false;
    myGLCD.setColor(0, 0, 0);
    myGLCD.fillRect(90, 210, 600, 242); //Apaga mensagem.
  }
}
void tpaScreen(boolean refreshAll = false) //-------------------------------AUTO-WATER CHANGE SCREEN ----
{
  if(refreshAll)
  {
    temp2hora = hora;
    temp2minuto = minuto;
    temp2duracaomaximatpa = duracaomaximatpa;
    for(byte i = 0; i < 7; i++)
    {
      semana[i] = semana_e[i];
    }
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[32])));
    printHeader(buffer); // tabela_textos[32] = "CONF. DIAS E HORARIO PARA TPA AUTOMATICA"

    printButton("+", houU[0], houU[1], houU[2], houU[3], true); //hour up
    printButton("-", houD[0], houD[1], houD[2], houD[3], true); //hour down
    printButton("+", minUT[0], minUT[1], minUT[2], minUT[3], true); //min up
    printButton("-", minDT[0], minDT[1], minDT[2], minDT[3], true); //min down
    printButton("+", durC[0], durC[1], durC[2], durC[3], true); //min up
    printButton("-", durB[0], durB[1], durB[2], durB[3], true); //min down

    setFont(LARGE, 255, 255, 255, 0, 0, 0);
    myGLCD.print(":", 208, 102);
    myGLCD.setFont(BigFont);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[83])));
    myGLCD.print(buffer, 40, 102); // "HORA:"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[84])));
    myGLCD.print(buffer, 320, 82); // "DURACAO MAXIMA"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[85])));
    myGLCD.print(buffer, 350, 122); // "POR ESTAGIO:"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[13])));
    printButton(buffer, prOK[0], prOK[1], prOK[2], prOK[3]); // "SALVAR"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[11])));
    printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3]);  // "INICIO"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[1])));
    printButton(buffer, menU[0], menU[1], menU[2], menU[3]); // "MENU 1";
  }
  if (semana[0] == 1) 
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[59])));
    printButton_verde(buffer, segU[0], segU[1], segU[2], segU[3]); //botao segunda
  } 
  else 
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[59])));
    printButton(buffer, segU[0], segU[1], segU[2], segU[3]); //botao segunda
  }
  if (semana[1] == 2) 
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[60])));
    printButton_verde(buffer, terC[0], terC[1], terC[2], terC[3]); //botao terca
  } 
  else 
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[60])));
    printButton(buffer, terC[0], terC[1], terC[2], terC[3]); //botao terca
  }
  if (semana[2] == 3) 
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[61])));
    printButton_verde(buffer, quaR[0], quaR[1], quaR[2], quaR[3]); //botao quarta
  } 
  else 
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[61])));
    printButton(buffer, quaR[0], quaR[1], quaR[2], quaR[3]); //botao quarta
  }
  if (semana[3] == 4) 
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[62])));
    printButton_verde(buffer, quiN[0], quiN[1], quiN[2], quiN[3]); //botao quinta
  } 
  else
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[62])));
    printButton(buffer, quiN[0], quiN[1], quiN[2], quiN[3]); //botao quinta
  }
  if (semana[4] == 5)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[63])));
    printButton_verde(buffer, sexT[0], sexT[1], sexT[2], sexT[3]); //botao sexta
  } 
  else 
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[63])));
    printButton(buffer, sexT[0], sexT[1], sexT[2], sexT[3]); //botao sexta
  }
  if (semana[5] == 6) 
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[64])));
    printButton_verde(buffer, sabA[0], sabA[1], sabA[2], sabA[3]); //botao sabado
  }
  else 
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[64])));
    printButton(buffer, sabA[0], sabA[1], sabA[2], sabA[3]); //botao sabado
  }
  if (semana[6] == 7) 
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[65])));
    printButton_verde(buffer, domI[0], domI[1], domI[2], domI[3]); //botao domingo
  }
  else 
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[65])));
    printButton(buffer, domI[0], domI[1], domI[2], domI[3]); //botao domingo
  }
  if (bitRead(tpa_status,2) == true) 
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[86])));
    printButton_vermelho(buffer, proX[0], proX[1], proX[2], proX[3]); //Sinaliza que houve uma falha durante a TPA. // "FALHA!!"
  } 
  else
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[87])));
    printButton(buffer, proX[0], proX[1], proX[2], proX[3]); //Sinaliza que a TPA foi realizada normalmente ou não foi realizada. // "NORMAL"
  }

  setFont(LARGE, 255, 255, 255, 0, 0, 0);
  if (temp2hora < 10) 
  {
    myGLCD.printNumI(0, 140, 96);
    myGLCD.printNumI(temp2hora, 172, 96);
  } 
  else
  {
    myGLCD.printNumI(temp2hora, 140, 96);
  }

  if (temp2minuto < 10) 
  {
    myGLCD.printNumI(0, 240, 96);
    myGLCD.printNumI(temp2minuto, 272, 96);
  } 
  else
  {
    myGLCD.printNumI(temp2minuto, 240, 96);
  }
  if (temp2duracaomaximatpa < 10) 
  {
    myGLCD.printNumI(0, 550, 96);
    myGLCD.printNumI(temp2duracaomaximatpa, 590, 96);
  } 
  else 
  {
    myGLCD.printNumI(temp2duracaomaximatpa, 550, 96);
  }
}
void menu_dosadoras()//---------------------------------------------tela =8
{
  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[33])));
  printHeader(buffer); // tabela_textos[33] = "ALTERAR CONFIGURACAO DAS DOSADORAS"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[88])));
  printButton(buffer, manU[0], manU[1], manU[2], manU[3]); // "MANUAL"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[90])));
  printButton(buffer, perS[0], perS[1], perS[2], perS[3]); // "PERSONALIZADO"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[91])));
  printButton(buffer, reV[0], reV[1], reV[2], reV[3]); // "REVER CONFIG."

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[134])));
  printButton(buffer, atiV[0], atiV[1], atiV[2], atiV[3]); // "DESATIVAR MODOS"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[133])));
  printButton(buffer, orP[0], orP[1], orP[2], orP[3]); // "CALIBRAR"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[11])));
  printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3]);  // "INICIO"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[1])));
  printButton(buffer, menU[0], menU[1], menU[2], menU[3]); // "MENU 1";
}

void graficoScreen()//------------------------------------------------------------tela =9
{

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[34])));  
  printHeader(buffer); // tabela_textos[34] = "ESCOLHA UM GRAFICO"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[11])));
  printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3]);  // "INICIO"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[1])));
  printButton(buffer, menU[0], menU[1], menU[2], menU[3]); // "MENU 1";

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[93])));
  printButton(buffer, tempG[0], tempG[1], tempG[2],tempG[3]); // "TEMPERATURA"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[94])));
  printButton(buffer, phA[0], phA[1], phA[2], phA[3]); // "PH AQUARIO"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[95])));
  printButton(buffer, phR[0], phR[1], phR[2], phR[3]); // "PH REATOR"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[96])));
  printButton(buffer, orP[0], orP[1], orP[2], orP[3]); // "ORP"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[97])));
  printButton(buffer, denS[0], denS[1], denS[2], denS[3]); // "DENSIDADE"

}

void waveScreen(boolean refreshAll = false)///--------------tela =10
{
  if(refreshAll == true)
  {
    Pump1PWM_temp = Pump1PWM;
    Pump2PWM_temp = Pump2PWM;

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[10])));
    printHeader(buffer); // tabela_textos[10] = "WAVEMAKER"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[11])));
    printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3]);  // "INICIO"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[1])));
    printButton(buffer, menU[0], menU[1], menU[2], menU[3]); // "MENU 1";

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[13])));
    printButton(buffer, prOK[0], prOK[1], prOK[2], prOK[3]); // "SALVAR"

    myGLCD.setColor(0, 0, 0);
    myGLCD.fillRect(2, 20, 648, 478);

    if(modo_selecionado == 1)
    {       
      printButton("-", peRB[0], peRB[1], peRB[2], peRB[3], true);
      printButton("+", peRC[0], peRC[1], peRC[2], peRC[3], true);
      printButton_verde("1", boT1[0], boT1[1], boT1[2], boT1[3],true);

      setFont(LARGE, 255, 255, 255, 0, 0, 0);

      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[238]))); // "PERIODO"
      myGLCD.print(buffer, 132, 250);

      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[239]))); // "MODO: ONDA SENOIDAL DESSINCRONIZADA" 
      myGLCD.print(buffer, 100, 150);
    }
    else
    {
      printButton("1", boT1[0], boT1[1], boT1[2], boT1[3],true);
    }

    if(modo_selecionado == 2)   
    {
      printButton("-", peRB[0], peRB[1], peRB[2], peRB[3], true);
      printButton("+", peRC[0], peRC[1], peRC[2], peRC[3], true);
      printButton_verde("2", boT2[0], boT2[1], boT2[2], boT2[3],true);

      setFont(LARGE, 255, 255, 255, 0, 0, 0);

      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[238]))); // "PERIODO"
      myGLCD.print(buffer, 132, 250);

      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[240]))); // "MODO: ONDA SENOIDAL SINCRONIZADA" 
      myGLCD.print(buffer, 100, 150); 
    }
    else
    {
      printButton("2", boT2[0], boT2[1], boT2[2], boT2[3],true);
    }
    if(modo_selecionado == 3)
    {
      printButton("-", peRB[0], peRB[1], peRB[2], peRB[3], true);
      printButton("+", peRC[0], peRC[1], peRC[2], peRC[3], true);    
      printButton_verde("3", boT3[0], boT3[1], boT3[2], boT3[3],true); 

      setFont(LARGE, 255, 255, 255, 0, 0, 0);

      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[241]))); // "DURACAO DO INTERVALO EM MS"
      myGLCD.print(buffer, 30, 250);

      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[242]))); // "MODO: MARE CHEIA" 
      myGLCD.print(buffer, 105, 150);
    }
    else
    {
      printButton("3", boT3[0], boT3[1], boT3[2], boT3[3],true);
    }
    if(modo_selecionado == 4)
    {
      printButton("-", peRB[0], peRB[1], peRB[2], peRB[3], true);
      printButton("+", peRC[0], peRC[1], peRC[2], peRC[3], true);    
      printButton_verde("4", boT4[0], boT4[1], boT4[2], boT4[3],true);

      setFont(LARGE, 255, 255, 255, 0, 0, 0);

      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[243]))); // "MODO: CRISTA DA ONDA"
      myGLCD.print(buffer, 105, 150);   

      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[241]))); // "DURACAO DO INTERVALO EM MS"
      myGLCD.print(buffer, 30, 250);
    }
    else
    {
      printButton("4", boT4[0], boT4[1], boT4[2], boT4[3],true);
    }
    if(modo_selecionado == 5)
    {
      printButton("-", PoTEB1[0], PoTEB1[1], PoTEB1[2], PoTEB1[3], true);      
      printButton("+", PoTEC1[0], PoTEC1[1], PoTEC1[2], PoTEC1[3], true);     
      printButton("-", PoTEB2[0], PoTEB2[1], PoTEB2[2], PoTEB2[3], true);      
      printButton("+", PoTEC2[0], PoTEC2[1], PoTEC2[2], PoTEC2[3], true);  
      printButton_verde("M", boT5[0], boT5[1], boT5[2], boT5[3],true);

      setFont(LARGE, 255, 255, 255, 0, 0, 0);

      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[246]))); // "MODO: MANUAL"
      myGLCD.print(buffer, 145, 150);

      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[244]))); // "POTENCIA DA BOMBA 1" 
      myGLCD.print(buffer, 138, 200);

      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[245]))); // "POTENCIA DA BOMBA 2" 
      myGLCD.print(buffer, 138, 310);
    }
    else
    {
      printButton("M", boT5[0], boT5[1], boT5[2], boT5[3],true);   
    }

    setFont(LARGE, 88, 255, 238, 0, 0, 0);

    myGLCD.print("0%", 446, 438);
    myGLCD.print("50%", 434, 312);
    myGLCD.print("100%", 416, 182);

    myGLCD.setColor(190, 190, 190); 
    myGLCD.drawRect(484, 454, 618, 454); // Linha x   
    myGLCD.drawRect(490, 454, 490, 194);  // Linha y1  
    myGLCD.drawRect(612, 454, 612, 194);  // Linha y2

    for (int i=0; i < 10; i++)
    {
      myGLCD.drawLine(484, (i * 26) + 194, 496, (i * 26) + 194); // Marcador esequerdo
      myGLCD.drawLine(606, (i * 26) + 194, 618, (i * 26) + 194); // Marcador central
      myGLCD.drawPixel(552, (i * 26) + 194);                    // Marcador direito
    }  
  }
  setFont(LARGE, 255, 255, 255, 0, 0, 0);

  if((modo_selecionado == 1) || (modo_selecionado == 2))
  {
    myGLCD.print("     ", 145, 300);
    myGLCD.printNumI(periodo, 145, 300); 
  }
  else if((modo_selecionado == 3) || (modo_selecionado == 4)) 
  {
    myGLCD.print(" ", 145, 300);
    myGLCD.printNumI(duracao, 145, 300);
  }
  else if(modo_selecionado == 5)
  {
    myGLCD.print(" ", 160, 255);
    myGLCD.printNumI(Pump1PWM_temp, 160, 250);
    myGLCD.print(" ", 160, 355);
    myGLCD.printNumI(Pump2PWM_temp, 160, 355);
  }
  delay(100);
}


void parametroScreen()//-------------------------------------------------------------------tela =14
{  
  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[36])));
  printHeader(buffer); // tabela_textos[36] = "ESCOLHA UM PARAMETRO"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[11])));
  printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3],false); // "INICIO"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[1])));
  printButton(buffer, menU[0], menU[1], menU[2], menU[3],false); // "MENU 1";

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[93])));
  printButton(buffer, tempG[0], tempG[1], tempG[2],tempG[3]); // "TEMPERATURA"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[94])));
  printButton(buffer, phA[0], phA[1], phA[2], phA[3]); // "PH AQUARIO"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[95])));
  printButton(buffer, phR[0], phR[1], phR[2], phR[3]); // "PH REATOR"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[96])));
  printButton(buffer, orP[0], orP[1], orP[2], orP[3]); // "ORP"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[97])));
  printButton(buffer, denS[0], denS[1], denS[2], denS[3]); // "DENSIDADE"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[98])));
  printButton(buffer, caliB[0], caliB[1], caliB[2], caliB[3]); // "CALIBRAR SONDAS"

}
//---------------------------------------------PH do reator--------------------------------tela =15 ----------
void config_phR_Screen(boolean refreshAll=false)
{

  if (refreshAll)
  {
    if (setPHR==0) {
      setPHR = PHR;  
    }                  //change to current temp.
    PHR2beS = setPHR;
    PHR2beO = offPHR;
    PHR2beA = alarmPHR;

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[37])));
    printHeader(buffer); // tabela_textos[37] = "CONTROLE DE PH DO REATOR DE CALCIO"

    setFont(LARGE, 255, 255, 255, 0, 0, 0);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[99])));
    myGLCD.print(buffer, 220, 40); // "PH DESEJADO:"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[75])));
    myGLCD.print(buffer, 180, 140); // "VARIACAO PERMITIDA:"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[76])));
    myGLCD.print(buffer, 100, 240); // "VARIACAO PARA ACIONAR O ALARME:"

    printButton("-", temM[0], temM[1], temM[2], temM[3], true);      
    printButton("+", temP[0], temP[1], temP[2], temP[3], true);     
    printButton("-", offM[0], offM[1], offM[2], offM[3], true);     
    printButton("+", offP[0], offP[1], offP[2], offP[3], true);     
    printButton("-", almM[0], almM[1], almM[2], almM[3], true);      
    printButton("+", almP[0], almP[1], almP[2], almP[3], true);      


    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[13])));
    printButton(buffer, prOK[0], prOK[1], prOK[2], prOK[3]); // "SALVAR"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[11])));
    printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3]);  // "INICIO"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[66])));
    printButton(buffer, menU[0], menU[1], menU[2], menU[3]);
  }

  setFont(LARGE, 255, 255, 255, 0, 0, 0);
  myGLCD.printNumF(PHR2beS, 1, 280, 80);
  myGLCD.printNumF(PHR2beO, 1, 280, 180);
  myGLCD.printNumF(PHR2beA, 1, 280, 280);
}

//---------------------------------------------ORP--------------------------------tela =16 ----------
void config_orp_Screen(boolean refreshAll=false)
{

  if (refreshAll)
  {
    ORP2beS = setORP;
    ORP2beO = offORP;
    ORP2beA = alarmORP;


    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[38])));
    printHeader(buffer); // tabela_textos[38] = "CONTROLE DE ORP"

    setFont(LARGE, 255, 255, 255, 0, 0, 0);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[100])));
    myGLCD.print(buffer, 230, 40); // "ORP DESEJADA:"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[75])));
    myGLCD.print(buffer, 180, 140); // "VARIACAO PERMITIDA:"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[76])));
    myGLCD.print(buffer, 100, 240); // "VARIACAO PARA ACIONAR O ALARME:"

    printButton("-", temM[0], temM[1], temM[2], temM[3], true);      //temp minus
    printButton("+", temP[0], temP[1], temP[2], temP[3], true);      //temp plus
    printButton("-", offM[0], offM[1], offM[2], offM[3], true);      //offset minus
    printButton("+", offP[0], offP[1], offP[2], offP[3], true);      //offset plus
    printButton("-", almM[0], almM[1], almM[2], almM[3], true);      //alarm minus
    printButton("+", almP[0], almP[1], almP[2], almP[3], true);      //alarm plus


    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[13])));
    printButton(buffer, prOK[0], prOK[1], prOK[2], prOK[3]); // "SALVAR"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[11])));
    printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3]);  // "INICIO"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[66])));
    printButton(buffer, menU[0], menU[1], menU[2], menU[3]);
  }

  myGLCD.setColor(0, 0, 0);
  myGLCD.fillRoundRect (300, 180, 406, 214); 
  myGLCD.fillRoundRect (300, 280, 406, 314);

  setFont(LARGE, 255, 255, 255, 0, 0, 0);
  myGLCD.printNumI(ORP2beS,300, 80);
  myGLCD.printNumI(ORP2beO,300, 180);
  myGLCD.printNumI(ORP2beA, 300, 280);
}
//---------------------------------------------PH do aquario--------------------------------tela =18 ----------

void config_phA_Screen(boolean refreshAll=false)
{

  if (refreshAll)
  {
    if (setPHA==0) {
      setPHA = PHA;  
    }                  //change to current temp.
    PHA2beS = setPHA;
    PHA2beO = offPHA;
    PHA2beA = alarmPHA;

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[39])));
    printHeader(buffer); // tabela_textos[39] = "CONTROLE DE PH DO AQUARIO"

    setFont(LARGE, 255, 255, 255, 0, 0, 0);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[99])));
    myGLCD.print(buffer, 220, 40); // "PH DESEJADO:"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[75])));
    myGLCD.print(buffer, 180, 140); // "VARIACAO PERMITIDA:"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[76])));
    myGLCD.print(buffer, 100, 240); // "VARIACAO PARA ACIONAR O ALARME:"

    printButton("-", temM[0], temM[1], temM[2], temM[3], true);      //temp minus
    printButton("+", temP[0], temP[1], temP[2], temP[3], true);      //temp plus
    printButton("-", offM[0], offM[1], offM[2], offM[3], true);      //offset minus
    printButton("+", offP[0], offP[1], offP[2], offP[3], true);      //offset plus
    printButton("-", almM[0], almM[1], almM[2], almM[3], true);      //alarm minus
    printButton("+", almP[0], almP[1], almP[2], almP[3], true);      //alarm plus

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[13])));
    printButton(buffer, prOK[0], prOK[1], prOK[2], prOK[3]); // "SALVAR"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[11])));
    printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3]);  // "INICIO"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[66])));
    printButton(buffer, menU[0], menU[1], menU[2], menU[3]);
  }

  setFont(LARGE, 255, 255, 255, 0, 0, 0); 
  myGLCD.printNumF(PHA2beS, 1, 280, 80);
  myGLCD.printNumF(PHA2beO, 1, 280, 180);
  myGLCD.printNumF(PHA2beA, 1, 280, 280);
}
//---------------------------------------------configurar densidade--------------------------------tela =20 ----------
void config_dens_Screen(boolean refreshAll=false)
{

  if (refreshAll)
  {
    DEN2beS = setDEN;
    DEN2beO = offDEN;
    DEN2beA = alarmDEN;

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[40])));
    printHeader(buffer); // tabela_textos[40] = "CONTROLE DE DENSIDADE"

    setFont(LARGE, 255, 255, 255, 0, 0, 0);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[101])));
    myGLCD.print(buffer, 180, 40); // "DENSIDADE DESEJADA:"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[75])));
    myGLCD.print(buffer, 180, 140); // "VARIACAO PERMITIDA:"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[76])));
    myGLCD.print(buffer, 100, 240); // "VARIACAO PARA ACIONAR O ALARME:"

    printButton("-", temM[0], temM[1], temM[2], temM[3], true);      //temp minus
    printButton("+", temP[0], temP[1], temP[2], temP[3], true);      //temp plus
    printButton("-", offM[0], offM[1], offM[2], offM[3], true);      //offset minus
    printButton("+", offP[0], offP[1], offP[2], offP[3], true);      //offset plus
    printButton("-", almM[0], almM[1], almM[2], almM[3], true);      //alarm minus
    printButton("+", almP[0], almP[1], almP[2], almP[3], true);      //alarm plus

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[13])));
    printButton(buffer, prOK[0], prOK[1], prOK[2], prOK[3]); // "SALVAR"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[11])));
    printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3]);  // "INICIO"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[66])));
    printButton(buffer, menU[0], menU[1], menU[2], menU[3]);
  }
  myGLCD.setColor(0, 0, 0);
  myGLCD.fillRoundRect (300, 180, 380, 214); 
  myGLCD.fillRoundRect (300, 280, 380, 314);

  setFont(LARGE, 255, 255, 255, 0, 0, 0);

  myGLCD.printNumI(DEN2beS, 300, 80);
  myGLCD.printNumI(DEN2beO, 300, 180);
  myGLCD.printNumI(DEN2beA, 300, 280);
}

void selecionar_dosadora()//---------------------------------------------tela =21
{

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[41])));
  printHeader(buffer); // tabela_textos[41] = "ESCOLHA UMA DOSADORA"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[102])));
  printButton(buffer, dosa1[0], dosa1[1], dosa1[2], dosa1[3]); // tabela_textos[102] = "DOSADORA 1"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[103])));
  printButton(buffer, dosa2[0], dosa2[1], dosa2[2], dosa2[3]); // tabela_textos[103] = "DOSADORA 2"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[104])));
  printButton(buffer, dosa3[0], dosa3[1], dosa3[2], dosa3[3]); // tabela_textos[104] = "DOSADORA 3"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[204])));
  printButton(buffer, dosa4[0], dosa4[1], dosa4[2], dosa4[3]); // tabela_textos[204] = "DOSADORA 4"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[205])));
  printButton(buffer, dosa5[0], dosa5[1], dosa5[2], dosa5[3]); // tabela_textos[205] = "DOSADORA 5"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[206])));
  printButton(buffer, dosa6[0], dosa6[1], dosa6[2], dosa6[3]); // tabela_textos[206] = "DOSADORA 6"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[11])));
  printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3]);  // "INICIO"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[1])));
  printButton(buffer, menU[0], menU[1], menU[2], menU[3]); // "MENU 1";

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[66])));
  printButton(buffer, volT[0], volT[1], volT[2], volT[3]);  // "VOLTAR"
}
//--------------------------- TEST INDIVIDUAL LEDS ----------------------------------------------------- tela =22
void teste_individual_leds()
{
  bled_out_temp = bled_out;
  wled_out_temp = wled_out;
  rbled_out_temp = rbled_out;
  rled_out_temp = rled_out;
  uvled_out_temp = uvled_out;

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[16])));
  printHeader(buffer); // tabela_textos[16] "TEST VARIATION OF ILLUMINATION"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[11])));
  printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3]); // "HOME"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[1])));
  printButton(buffer, menU[0], menU[1], menU[2], menU[3]); // "MENU 1";

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[66])));
  printButton(buffer, volT[0], volT[1], volT[2], volT[3]); // "BACK"

  printButton("+", 98, 36, 186, 82, true); // "+"
  printButton("+", 202, 36, 290, 82, true); // "+"
  printButton("+", 306, 36, 394, 82, true); // "+"
  printButton("+", 410, 36, 498, 82, true); // "+"
  printButton("+", 514, 36, 602, 82, true); // "+"

  printButton("-", 98, 402, 186, 448, true); // "-"
  printButton("-", 202, 402, 290, 448, true); // "-"
  printButton("-", 306, 402, 394, 448, true); // "-"
  printButton("-", 410, 402, 498, 448, true); // "-"
  printButton("-", 514, 402, 602, 448, true); // "-"

  myGLCD.setFont(BigFont);
  myGLCD.setBackColor(0,0,0);

  myGLCD.setColor(cor_canal1[0], cor_canal1[1],cor_canal1[2]);
  myGLCD.drawRect(98, 88, 186, 344); // % bar place holder

  strcpy_P(buffer, (char*)pgm_read_word_near(&(nome_canal[1])));
  myGLCD.print(buffer, 122, 352); // WHITE

  myGLCD.printNumI(wled_out_temp, 122, 372);

  myGLCD.setColor(cor_canal2[0], cor_canal2[1],cor_canal2[2]);
  myGLCD.drawRect(202, 88, 290, 344); // % bar place holder

  strcpy_P(buffer, (char*)pgm_read_word_near(&(nome_canal[2])));
  myGLCD.print(buffer, 226, 352); // GREEN

  myGLCD.printNumI(bled_out_temp, 226, 372);

  myGLCD.setColor(cor_canal3[0], cor_canal3[1],cor_canal3[2]);
  myGLCD.drawRect(306, 88, 394, 344); // % bar place holder

  strcpy_P(buffer, (char*)pgm_read_word_near(&(nome_canal[3])));
  myGLCD.print(buffer, 330, 352); // BLUE

  myGLCD.printNumI(rbled_out_temp, 330, 372);

  myGLCD.setColor(cor_canal4[0], cor_canal4[1],cor_canal4[2]);
  myGLCD.drawRect(410, 88, 498, 344); // % bar place holder;

  strcpy_P(buffer, (char*)pgm_read_word_near(&(nome_canal[4])));
  myGLCD.print(buffer, 434, 352); // RED

  myGLCD.printNumI(rled_out_temp, 434, 372);

  myGLCD.setColor(cor_canal5[0], cor_canal5[1],cor_canal5[2]);
  myGLCD.drawRect(514, 88, 602, 344); // % bar place holder

  strcpy_P(buffer, (char*)pgm_read_word_near(&(nome_canal[5])));
  myGLCD.print(buffer, 538, 352); // VIOLET

  myGLCD.printNumI(uvled_out_temp, 538, 372);

  setFont(LARGE, 255, 255, 255, 0, 0, 0);
  myGLCD.drawRect(60, 346, 630, 346); // Eixo x
  myGLCD.drawRect(60, 346, 60, 88); // eixo y

  myGLCD.setColor(190, 190, 190);
  for (int i=0; i<10; i++){ // Escala %
    myGLCD.drawLine(61, (i*26)+88, 78, (i*26)+88);
  }
  for (int i=0; i<10; i++){
    myGLCD.drawLine(61, (i*26)+102, 69, (i*26)+102);
  }

  myGLCD.setFont(BigFont);
  myGLCD.print("%", 40, 50); // %
  myGLCD.print("100", 10, 82); // 100
  myGLCD.print("90", 24, 108); // 90
  myGLCD.print("80", 24, 134); // 80
  myGLCD.print("70", 24, 160); // 70
  myGLCD.print("60", 24, 186); // 60
  myGLCD.print("50", 24, 212); // 50
  myGLCD.print("40", 24, 238); // 40
  myGLCD.print("30", 24, 264); // 30
  myGLCD.print("20", 24, 290); // 20
  myGLCD.print("10", 24, 316); // 10
  myGLCD.print("0", 40, 342); // 0

  myGLCD.setColor(180, 180, 180);
  for (int i=0; i<10; i++){ // escalas de linhas pontilhadas horizontais
    for(int k=92; k<622; k++){
      myGLCD.drawPixel(k,(i*26)+88);
      k=k+2;
    }
  }

  //void desenhar_barras(int sbR, int sbG, int sbB, int sbX1, int sbY1, int sbX2, int sbY2)

  y_tocado = map(wled_out_temp, 255, 0, 88, 344);
  desenhar_barras(cor_canal1[0], cor_canal1[1],cor_canal1[2], 98, 88, 186, 344);

  y_tocado = map(bled_out_temp, 255, 0, 88, 344);
  desenhar_barras(cor_canal2[0], cor_canal2[1],cor_canal2[2], 202, 88, 290, 344);

  y_tocado = map(rbled_out_temp, 255, 0, 88, 344);
  desenhar_barras(cor_canal3[0], cor_canal3[1],cor_canal3[2], 306, 88, 394, 344);

  y_tocado = map(rled_out_temp, 255, 0, 88, 344);
  desenhar_barras(cor_canal4[0], cor_canal4[1],cor_canal4[2], 410, 88, 498, 344);

  y_tocado = map(uvled_out_temp, 255, 0, 88, 344);
  desenhar_barras(cor_canal5[0], cor_canal5[1],cor_canal5[2], 514, 88, 602, 344);                                                             
}
// ------------------------------------------------------------------ tela =23
//--------------------------------------------------------------------tela =24
//----------------------------------------teste dos leds ---------------------- tela =25
void escolher_teste()
{
  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[49])));
  printHeader(buffer); // "CHOOSE A TEST"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[11])));
  printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3]); // "INICIO"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[1])));
  printButton(buffer, menU[0], menU[1], menU[2], menU[3]); // "MENU 1";

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[67])));
  printButton(buffer, testI[0], testI[1], testI[2], testI[3]); // "TESTE INDIVIDUAL"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[68])));
  printButton(buffer, testT[0], testT[1], testT[2], testT[3]); // "TESTAR TODOS"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[66])));
  printButton(buffer, volT[0], volT[1], volT[2], volT[3]);// "VOLTAR
}
//---------------------------------------- Calibrar dosadoras ---------------------- tela =26
void calibrar_dosadoras(boolean refreshAll=false)
{
  if(refreshAll)
  {
    config_valores_calib_temp();

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[42])));
    printHeader(buffer); // tabela_textos[42] = "CALIBRAR DOSADORA"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[13])));
    printButton(buffer, salV[0], salV[1], salV[2], salV[3]); // "SALVAR"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[11])));
    printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3]); // "INICIO"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[66])));
    printButton(buffer, volT[0], volT[1], volT[2], volT[3]);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[17])));
    printButton(buffer, iniciaR[0], iniciaR[1], iniciaR[2], iniciaR[3]); // "INICIAR"

    printButton("-", almM[0], almM[1], almM[2], almM[3], true); //alarm minus
    printButton("+", almP[0], almP[1], almP[2], almP[3], true); //alarm plus

    myGLCD.setColor(255, 255, 255);
    myGLCD.drawRect(40, 100, 620, 250);
    setFont(LARGE, 255, 255, 255, 0, 0, 0);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[105])));
    myGLCD.print(buffer, 60, 110); // "COLOQUE O RECIPIENTE SOB O BICO"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[106])));
    myGLCD.print(buffer, 60, 140); // "DOSADOR E CLIQUE EM INICIAR."

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[107])));
    myGLCD.print(buffer, 60, 170); // "EM SEGUIDA INSIRA O VALOR OBTIDO"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[108])));
    myGLCD.print(buffer, 60, 200); // "EM ML NO CAMPO ABAIXO."

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[109])));
    myGLCD.print(buffer, 10, 330); // "PARA MELHORES RESULTADOS REPITA O TESTE"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[110])));
    myGLCD.print(buffer, 70, 354); // "ALGUMAS VEZES E USE UMA MEDIA."
  }
  myGLCD.setColor(0, 0, 0);
  myGLCD.fillRect(234, 270, 406, 320);

  if(modo_calibrar == true)
  {
    setFont(LARGE, 255, 255, 255, 0, 0, 0);
    myGLCD.printNumF(fator_calib_dosadora[dosadora_selecionada],2, 260, 280);

    setFont(LARGE, 255, 255, 255, 0, 0, 0);
    if(dosadora_selecionada == 0)
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[111])));
      myGLCD.print(buffer, 160, 60); // tabela_textos[111] = "DOSADORA 1 SELECIONADA"
    }
    if(dosadora_selecionada == 1)
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[112])));
      myGLCD.print(buffer, 160, 60); // tabela_textos[112] = "DOSADORA 2 SELECIONADA"
    }
    if(dosadora_selecionada == 2)
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[113])));
      myGLCD.print(buffer, 160, 60); // tabela_textos[113] = "DOSADORA 3 SELECIONADA"
    }
    if(dosadora_selecionada == 3)
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[207])));
      myGLCD.print(buffer, 160, 60); // tabela_textos[207] = "DOSADORA 4 SELECIONADA"
    }
    if(dosadora_selecionada == 4)
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[208])));
      myGLCD.print(buffer, 160, 60); // tabela_textos[208] = "DOSADORA 5 SELECIONADA"
    }
    if(dosadora_selecionada == 5)
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[209])));
      myGLCD.print(buffer, 160, 60); // tabela_textos[209] = "DOSADORA 6 SELECIONADA"
    }
  }
}

void config_dosagem_manual(boolean refreshAll=false) // ----------tela =27
{
  if(refreshAll)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[43])));
    printHeader(buffer); // tabela_textos[43] = "DOSAGEM MANUAL"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[11])));
    printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3]); // "INICIO"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[66])));
    printButton(buffer, volT[0], volT[1], volT[2], volT[3]);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[17])));
    printButton(buffer, iniciaR[0], iniciaR[1], iniciaR[2], iniciaR[3]); // "INICIAR"

    printButton("-", almM[0], almM[1], almM[2], almM[3], true); //alarm minus
    printButton("+", almP[0], almP[1], almP[2], almP[3], true); //alarm plus

    myGLCD.setColor(255, 255, 255);
    myGLCD.drawRect(40, 100, 620, 250);

    setFont(LARGE, 255, 255, 255, 0, 0, 0);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[114])));
    myGLCD.print(buffer, 60, 110); // "SELECIONE O VOLUME A SER DOSADO"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[115])));
    myGLCD.print(buffer, 60, 140); // "EM ML NO CAMPO ABAIXO E"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[116])));
    myGLCD.print(buffer, 60, 170); // "EM SEGUIDA TOQUE EM INICIAR."

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[117])));
    myGLCD.print(buffer, 60, 200); // "A DOSAGEM INICIARA EM 10 SEGUNDOS"
  }
  myGLCD.setColor(0, 0, 0);
  myGLCD.fillRect(234, 270, 406, 320);

  if(modo_manual == true)
  {
    setFont(LARGE, 255, 255, 255, 0, 0, 0);
    myGLCD.printNumF(dose_dosadora_manual[dosadora_selecionada],2, 260, 280);

    setFont(LARGE, 255, 255, 255, 0, 0, 0);

    if(dosadora_selecionada == 0)
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[111])));
      myGLCD.print(buffer, 160, 60); // tabela_textos[111] = "DOSADORA 1 SELECIONADA"
    }
    if(dosadora_selecionada == 1)
    {    
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[112])));
      myGLCD.print(buffer, 160, 60); // tabela_textos[112] = "DOSADORA 2 SELECIONADA"
    }
    if(dosadora_selecionada == 2)
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[113])));
      myGLCD.print(buffer, 160, 60); // tabela_textos[113] = "DOSADORA 3 SELECIONADA"
    }
    if(dosadora_selecionada == 3)
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[207])));
      myGLCD.print(buffer, 160, 60); // tabela_textos[207] = "DOSADORA 4 SELECIONADA"
    }
    if(dosadora_selecionada == 4)
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[208])));
      myGLCD.print(buffer, 160, 60); // tabela_textos[208] = "DOSADORA 5 SELECIONADA"
    }
    if(dosadora_selecionada == 5)
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[209])));
      myGLCD.print(buffer, 160, 60); // tabela_textos[209] = "DOSADORA 6 SELECIONADA" 
    }    
  }
}
void escolher_canal() //---------------------------------------------------------- tela =28
{
  strcpy_P(buffer, (char*)pgm_read_word_near(&(nome_canal[11])));
  printHeader(buffer); // nome_canal[11] = "ESCOLHA UMA COR"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[11])));
  printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3],false); // "INICIO"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[1])));
  printButton(buffer, menU[0], menU[1], menU[2], menU[3],false); // "MENU 1";

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[66])));
  printButton(buffer, volT[0], volT[1], volT[2], volT[3]);// "VOLTAR"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(nome_canal[6])));
  printButton(buffer, tempG[0], tempG[1], tempG[2],tempG[3]); // "BRANCO"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(nome_canal[7])));
  printButton(buffer, phA[0], phA[1], phA[2], phA[3]); // "AZUL"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(nome_canal[8])));
  printButton(buffer, phR[0], phR[1], phR[2], phR[3]); // "AZUL ROYAL"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(nome_canal[9])));
  printButton(buffer, orP[0], orP[1], orP[2], orP[3]); // "VERMELHO"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(nome_canal[10])));
  printButton(buffer, denS[0], denS[1], denS[2], denS[3]); // "VIOLETA"
}  

void config_dosagem_personalizada(boolean refreshAll=false) // -------------------tela =29
{
  if(refreshAll)
  {   
    config_valores_dosadoras_temp();

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[45])));
    printHeader(buffer); // tabela_textos[45] = "CONFIGURAR DOSAGEM PERSONALIZADA"

    printButton("+", houU[0], houU[1], houU[2], houU[3], true); //hour up
    printButton("-", houD[0], houD[1], houD[2], houD[3], true); //hour down
    printButton("+", minUT[0], minUT[1], minUT[2], minUT[3], true); //min up
    printButton("-", minDT[0], minDT[1], minDT[2], minDT[3], true); //min down
    printButton("+", houU[0]+310, houU[1], houU[2]+310, houU[3], true); //hora mais
    printButton("-", houD[0]+310, houD[1], houD[2]+310, houD[3], true); //hora menos
    printButton("+", minUT[0]+310, minUT[1], minUT[2]+310, minUT[3], true); //minuto mais
    printButton("-", minDT[0]+310, minDT[1], minDT[2]+310, minDT[3], true); //minuto menos

    setFont(LARGE, 255, 255, 255, 0, 0, 0);
    myGLCD.print(":", 210, 96);
    myGLCD.print(":", 210 + 310, 96);
    myGLCD.setFont(BigFont);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[118])));
    myGLCD.print(buffer, 10, 102);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[119])));
    myGLCD.print(buffer, 344, 102);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[135])));
    printButton(buffer, proX[0], proX[1], proX[2], proX[3]); // "PROXIMO"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[11])));
    printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3]);  // "INICIO"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[1])));
    printButton(buffer, menU[0], menU[1], menU[2], menU[3]); // "MENU 1";

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[66])));
    printButton(buffer, volT[0], volT[1], volT[2], volT[3]);
  }

  if (segunda_dosagem_personalizada[dosadora_selecionada] == 1)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[59])));
    printButton_verde(buffer, segU[0], segU[1], segU[2], segU[3]); //botao segunda
  } 
  else 
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[59])));      
    printButton(buffer, segU[0], segU[1], segU[2], segU[3]); //botao segunda
  }
  if (terca_dosagem_personalizada[dosadora_selecionada] == 2)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[60])));
    printButton_verde(buffer, terC[0], terC[1], terC[2], terC[3]); //botao terca
  } 
  else 
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[60])));
    printButton(buffer, terC[0], terC[1], terC[2], terC[3]); //botao terca
  }
  if (quarta_dosagem_personalizada[dosadora_selecionada] == 3)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[61]))); 
    printButton_verde(buffer, quaR[0], quaR[1], quaR[2], quaR[3]); //botao quarta
  } 
  else
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[61])));
    printButton(buffer, quaR[0], quaR[1], quaR[2], quaR[3]); //botao quarta
  }
  if (quinta_dosagem_personalizada[dosadora_selecionada] == 4) 
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[62])));
    printButton_verde(buffer, quiN[0], quiN[1], quiN[2], quiN[3]); //botao quinta
  } 
  else 
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[62])));
    printButton(buffer, quiN[0], quiN[1], quiN[2], quiN[3]); //botao quinta
  }
  if (sexta_dosagem_personalizada[dosadora_selecionada] == 5) 
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[63])));
    printButton_verde(buffer, sexT[0], sexT[1], sexT[2], sexT[3]); //botao sexta
  } 
  else
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[63])));
    printButton(buffer, sexT[0], sexT[1], sexT[2], sexT[3]); //botao sexta
  }
  if (sabado_dosagem_personalizada[dosadora_selecionada] == 6) 
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[64])));
    printButton_verde(buffer, sabA[0], sabA[1], sabA[2], sabA[3]); //botao sabado
  }
  else 
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[64])));
    printButton(buffer, sabA[0], sabA[1], sabA[2], sabA[3]); //botao sabado
  }
  if (domingo_dosagem_personalizada[dosadora_selecionada] == 7) 
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[65])));
    printButton_verde(buffer, domI[0], domI[1], domI[2], domI[3]); //botao sabado
  }
  else 
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[65])));
    printButton(buffer, domI[0], domI[1], domI[2], domI[3]); //botao sabado
  }

  setFont(LARGE, 255, 255, 255, 0, 0, 0);
  if (hora_inicial_dosagem_personalizada[dosadora_selecionada] < 10) 
  {
    myGLCD.printNumI(0, 140, 96);
    myGLCD.printNumI(hora_inicial_dosagem_personalizada[dosadora_selecionada], 156, 96);
  } 
  else
  {
    myGLCD.printNumI(hora_inicial_dosagem_personalizada[dosadora_selecionada], 140, 96);
  }

  if (minuto_inicial_dosagem_personalizada[dosadora_selecionada] < 10)
  {
    myGLCD.printNumI(0, 240, 96);
    myGLCD.printNumI(minuto_inicial_dosagem_personalizada[dosadora_selecionada], 256, 96);
  } 
  else 
  {
    myGLCD.printNumI(minuto_inicial_dosagem_personalizada[dosadora_selecionada], 240, 96);
  }
  if (hora_final_dosagem_personalizada[dosadora_selecionada] < 10)
  {
    myGLCD.printNumI(0, 140 + 310, 96);
    myGLCD.printNumI(hora_final_dosagem_personalizada[dosadora_selecionada], 156 + 310, 96);
  } 
  else
  {
    myGLCD.printNumI(hora_final_dosagem_personalizada[dosadora_selecionada], 140 + 310, 96);
  }

  if (minuto_final_dosagem_personalizada[dosadora_selecionada] < 10)
  {
    myGLCD.printNumI(0, 240 + 310, 96);
    myGLCD.printNumI(minuto_final_dosagem_personalizada[dosadora_selecionada], 256 + 310, 96);
  } 
  else
  {
    myGLCD.printNumI(minuto_final_dosagem_personalizada[dosadora_selecionada], 240 + 310, 96);
  }

  setFont(LARGE, 255, 255, 255, 0, 0, 0);

  if(dosadora_selecionada == 0)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[102])));
    myGLCD.print(buffer, 20, 396); // "DOSADORA 1"; // tabela_textos[102]
  }
  else if(dosadora_selecionada == 1)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[103])));
    myGLCD.print(buffer, 20, 396); // "DOSADORA 2"; // tabela_textos[103]
  }
  else if(dosadora_selecionada == 2)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[104])));
    myGLCD.print(buffer, 20, 396);  // "DOSADORA 3"; // tabela_textos[104]
  }
  else if(dosadora_selecionada == 3)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[204])));
    myGLCD.print(buffer, 20, 396); // "DOSADORA 4"; // tabela_textos[204]
  }
  else if(dosadora_selecionada == 4)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[205])));
    myGLCD.print(buffer, 20, 396); // "DOSADORA 5"; // tabela_textos[205]
  }
  else if(dosadora_selecionada == 5)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[206])));
    myGLCD.print(buffer, 20, 396); // "DOSADORA 6"; // tabela_textos[206]
  }
  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[125])));
  myGLCD.print(buffer, 20, 436); // "SELECIONADA"; // tabela_textos[125]

}

void solicitar_senha()  //---------------tela =30
{
  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[46])));
  printHeader(buffer); // tabela_textos[46] = "DIGITE A SENHA"

  printButton("1", boT1[0], boT1[1], boT1[2], boT1[3],true);
  printButton("2", boT2[0], boT2[1], boT2[2], boT2[3],true);
  printButton("3", boT3[0], boT3[1], boT3[2], boT3[3],true);
  printButton("4", boT4[0], boT4[1], boT4[2], boT4[3],true);
  printButton("5", boT5[0], boT5[1], boT5[2], boT5[3],true);
  printButton("6", boT6[0], boT6[1], boT6[2], boT6[3],true);
  printButton("7", boT7[0], boT7[1], boT7[2], boT7[3],true);
  printButton("8", boT8[0], boT8[1], boT8[2], boT8[3],true);
  printButton("9", boT9[0], boT9[1], boT9[2], boT9[3],true);
  printButton("0", boT0[0], boT0[1], boT0[2], boT0[3],true);

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[136])));
  printButton(buffer, boTL[0], boTL[1], boTL[2], boTL[3],true); // tabela_textos[136] = "LIMPAR"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[137])));
  printButton(buffer, boTE[0], boTE[1], boTE[2], boTE[3],true); // tabela_textos[137] = "ENTRAR"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[11])));
  printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3]);  // tabela_textos[11] = "INICIO"

}

void config_dosagem_personalizada_2(boolean refreshAll=false) // ----------tela =31
{
  if(refreshAll)
  {
    config_valores_dosadoras_temp2();

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[47])));
    printHeader(buffer); // tabela_textos[47] = "CONFIGURAR DOSAGEM PERSONALIZADA"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[11])));
    printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3]);  // "INICIO"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[1])));
    printButton(buffer, menU[0], menU[1], menU[2], menU[3]); // "MENU 1";

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[138])));
    printButton(buffer, anT[0],anT[1], anT[2], anT[3]); // tabela_textos[138] = "ANTERIOR"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[13])));
    printButton(buffer, prOK[0],prOK[1], prOK[2], prOK[3]); // "SALVAR"

    printButton("+", minUT[0], minUT[1], minUT[2], minUT[3], true); //min up
    printButton("-", minDT[0], minDT[1], minDT[2], minDT[3], true); //min down
    printButton("+", durC[0], durC[1], durC[2], durC[3], true); //minuto mais
    printButton("-", durB[0], durB[1], durB[2], durB[3], true); //minuto menos

    setFont(LARGE, 255, 255, 255, 0, 0, 0);
    myGLCD.setFont(BigFont);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[120])));
    myGLCD.print(buffer, 20, 62); // "SELECIONE O"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[121])));
    myGLCD.print(buffer, 20, 110); // "VOLUME "

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[122])));
    myGLCD.print(buffer, 20, 150); // "(ML/DIA):"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[123])));
    myGLCD.print(buffer, 380, 92); // "QUANTIDADE"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[124])));
    myGLCD.print(buffer, 380, 122); // "DE DOSES:"
  }

  if (modo_personalizado == true)
  { 
    setFont(LARGE, 255, 255, 255, 0, 0, 0);
    myGLCD.printNumF(dose_dosadora_personalizada[dosadora_selecionada], 1, 200, 96);  
    if (quantidade_dose_dosadora_personalizada[dosadora_selecionada] < 10) 
    {
      myGLCD.printNumI(0, 550, 96);
      myGLCD.printNumI(quantidade_dose_dosadora_personalizada[dosadora_selecionada], 566, 96);
    } 
    else 
    {
      myGLCD.printNumI(quantidade_dose_dosadora_personalizada[dosadora_selecionada], 550, 96);
    }
    setFont(LARGE, 255, 255, 255, 0, 0, 0);

    if(dosadora_selecionada == 0)
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[111])));
      myGLCD.print(buffer, 250, 426);
    }
    else if(dosadora_selecionada == 1)
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[112])));
      myGLCD.print(buffer, 250, 426);
    }
    else  if(dosadora_selecionada == 2)
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[113])));
      myGLCD.print(buffer, 250, 426);
    }
    else  if(dosadora_selecionada == 3)
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[207])));
      myGLCD.print(buffer, 250, 426);
    }
    else   if(dosadora_selecionada == 4)
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[208])));
      myGLCD.print(buffer, 250, 426);
    }
    else  if(dosadora_selecionada == 5)
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[209])));
      myGLCD.print(buffer, 250, 426);
    }
    if (modo_personalizado_on[dosadora_selecionada] == 1) 
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[126])));
      printButton_verde(buffer, sexT[0], sexT[1], sexT[2], sexT[3]); 
    } 
    else 
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[127])));
      printButton(buffer, sexT[0], sexT[1], sexT[2], sexT[3]); 
    }
  }  
}

void rever_configuracao_dosadoras()//---------------------------------------------tela =32
{
  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[44])));
  printHeader(buffer); // tabela_textos[44] = "REVER CONFIG. DOSADORAS" 

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[140])));
  printButton(buffer, manU[0], manU[1], manU[2], manU[3]); // tabela_textos[140] = "PERSONALIZADO"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[11])));
  printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3]);  // "INICIO"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[1])));
  printButton(buffer, menU[0], menU[1], menU[2], menU[3]); // "MENU 1";

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[66])));
  printButton(buffer, volT[0], volT[1], volT[2], volT[3]); // tabela_textos[66]
} 

void rever_dosagem_personalizada() // ------------------------------------------------------------------tela =34 / 23
{
  byte k = 0;
  byte j = 0;

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[50])));
  printHeader(buffer); // tabela_textos[50] = "REVER CONF. DA DOSAGEM PERSONALIZADA"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[11])));
  printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3]);  // "INICIO"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[1])));
  printButton(buffer, menU[0], menU[1], menU[2], menU[3]); // "MENU 1";

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[66])));
  printButton(buffer, volT[0], volT[1], volT[2], volT[3]); // "VOLTAR"

  myGLCD.setColor(161, 127, 73);                    
  myGLCD.drawLine(2, 176, 638, 176);  
  myGLCD.drawLine(2, 316, 638, 316);
  myGLCD.drawLine(638, 30, 638, 478);

  if(dispScreen == 23)
  {
    k = 3;
    j = 82;
  }

  for(byte i = 0; i < 3; i++)
  {
    if(dispScreen == 34)
    {
      if( i == 0)
      {
        strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[210])));
        printButton(buffer, salV[0], salV[1], salV[2], salV[3]); // "MAIS"
      }
    }
    setFont(LARGE, 255, 255, 255, 0, 0, 0);
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[129 + i + j]))); // tabela_textos[129] = "DOSADORA 1:", tabela_textos[130] = "DOSADORA 2:", tabela_textos[131] = "DOSADORA 3:"
    myGLCD.print(buffer, 20, 60 + (i * 140));                                    // tabela_textos[211] = "DOSADORA 4:", tabela_textos[212] = "DOSADORA 5:", tabela_textos[213] = "DOSADORA 6:"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[118]))); // tabela_textos[118] = "INICIAL:"
    myGLCD.print(buffer, 20, 100 + (i * 140));  

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[119]))); // tabela_textos[119] = "FINAL:"
    myGLCD.print(buffer, 136, 100 + (i * 140));

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[128]))); // tabela_textos[128] = "QUANTIDADE DE DOSES"
    myGLCD.print(buffer, 20, 140 + (i * 140));

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[121]))); // tabela_textos[121] = "VOLUME "
    myGLCD.print(buffer, 430, 100 + (i * 140));

    myGLCD.print(":", 180, 100 + (i * 140));
    myGLCD.print(":", 360, 100 + (i * 140));
    myGLCD.print(":", 526, 100 + (i * 140));

    myGLCD.printNumF(dose_dosadora_personalizada_e[i + k], 1, 530, 100 + (i * 140));
    myGLCD.printNumI(quantidade_dose_dosadora_personalizada_e[i + k], 340, 140 + (i * 140));

    if(hora_inicial_dosagem_personalizada_e[i + k] < 10)
    {
      myGLCD.printNumI(0, 119, 100 + (i * 140));
      myGLCD.printNumI(hora_inicial_dosagem_personalizada_e[i + k], 135, 50 + (i * 140));
    }
    else
    {
      myGLCD.printNumI(hora_inicial_dosagem_personalizada_e[i + k], 119, 100 + (i * 140));
    }
    if(minuto_inicial_dosagem_personalizada_e[i + k] < 10)
    {
      myGLCD.printNumI(0, 166, 100 + (i * 140));
      myGLCD.printNumI(minuto_inicial_dosagem_personalizada_e[i + k], 182, 100 + (i * 140));
    }
    else
    {
      myGLCD.printNumI(minuto_inicial_dosagem_personalizada_e[i + k], 166, 100 + (i * 140));
    }
    if(hora_final_dosagem_personalizada_e[i + k] < 10)
    {
      myGLCD.printNumI(0, 300, 100 + (i * 140));
      myGLCD.printNumI(hora_final_dosagem_personalizada_e[i + k], 316, 100 + (i * 140)); 
    }
    else
    {
      myGLCD.printNumI(hora_final_dosagem_personalizada_e[i + k], 300, 100 + (i * 140));
    }
    if(minuto_final_dosagem_personalizada_e[i + k] < 10)
    {
      myGLCD.printNumI(0, 346, 100 + (i * 140));
      myGLCD.printNumI(minuto_final_dosagem_personalizada_e[i + k], 362, 100 + (i * 140));
    }
    else
    {
      myGLCD.printNumI(minuto_final_dosagem_personalizada_e[i + k], 346, 100 + (i * 140));
    }
    if(segunda_dosagem_personalizada_e[i + k] == 1)
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[70])));
      printButton_verde(buffer, 220, 46 + (i * 140), 275, 86 + (i * 140));
    }
    else
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[70])));
      printButton(buffer, 220, 46 + (i * 140), 275, 86 + (i * 140));
    }
    if(terca_dosagem_personalizada_e[i + k] == 2)
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[71])));
      printButton_verde(buffer, 280, 46 + (i * 140), 335, 86 + (i * 140));
    }
    else
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[71])));
      printButton(buffer, 280, 46 + (i * 140), 335, 86 + (i * 140));
    }
    if(quarta_dosagem_personalizada_e[i + k] == 3)
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[72])));
      printButton_verde(buffer, 340, 46 + (i * 140), 395, 86 + (i * 140));
    }
    else
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[72])));
      printButton(buffer, 340, 46 + (i * 140), 395,86 + (i * 140));
    }    
    if(quinta_dosagem_personalizada_e[i + k] == 4)
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[198])));
      printButton_verde(buffer, 400, 46 + (i * 140), 455, 86 + (i * 140));
    }
    else
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[198])));
      printButton(buffer, 400, 46 + (i * 140), 455, 86 + (i * 140));
    }    
    if(sexta_dosagem_personalizada_e[i + k] == 5)
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[199])));
      printButton_verde(buffer, 460, 46 + (i * 140), 515, 86 + (i * 140));
    }
    else
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[199])));
      printButton(buffer, 460, 46 + (i * 140), 515, 86 + (i * 140));
    }
    if(sabado_dosagem_personalizada_e[i + k] == 6)
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[200])));
      printButton_verde(buffer, 520, 46 + (i * 140), 575, 86 + (i * 140));
    }
    else
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[200])));
      printButton(buffer, 520, 46 + (i * 140), 575, 86 + (i * 140));
    }
    if(domingo_dosagem_personalizada_e[i + k] == 7)
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[73])));
      printButton_verde(buffer, 580, 46 + (i * 140), 635, 86 + (i * 140));
    }
    else
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[73])));
      printButton(buffer, 580,46 + (i * 140), 635, 86 + (i * 140));
    } 
    if (modo_personalizado_on_e[i + k] == true) 
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[126])));
      printButton_verde(buffer, 400, 130 + (i * 140), 490, 170 + (i * 140)); 
    } 
    else 
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[126])));
      printButton(buffer, 400, 130 + (i * 140), 490, 170 + (i * 140)); 
    }
    if (modo_personalizado_on_e[i + k] == false) 
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[127])));
      printButton_verde(buffer, 500, 130 + (i * 140), 590, 170 + (i * 140)); 
    } 
    else 
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[127])));
      printButton(buffer, 500, 130 + (i * 140), 590, 170 + (i * 140)); 
    }
  }
}

//---------------------------------------------Desativar dosadoras--------------------------------tela =35 / 24
void desativar_dosadoras(boolean refreshAll = false)
{
  byte i = 0;
  byte k = 0;

  if(dispScreen == 24)
  {
    i = 3;
  }
  if(refreshAll == true)
  {
    if (modo_personalizado_on_e[i] == true)
    {
      bitWrite(ativar_desativar, i, 1);
    }
    else
    {
      bitWrite(ativar_desativar, i, 0);
    }
    if (modo_personalizado_on_e[i + 1] == true)
    {
      bitWrite(ativar_desativar, (i + 1), 1);
    }
    else
    {
      bitWrite(ativar_desativar, (i + 1), 0);
    }
    if (modo_personalizado_on_e[i + 2] == true)
    {
      bitWrite(ativar_desativar, (i + 2), 1);
    }
    else
    {
      bitWrite(ativar_desativar, (i + 2), 0);
    }
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[51])));
    printHeader(buffer); // tabela_textos[51] =  "DESATIVAR DOSADORAS"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[11])));
    printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3]);  // "INICIO"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[1])));
    printButton(buffer, menU[0], menU[1], menU[2], menU[3]); // "MENU 1";

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[13])));
    printButton(buffer, salV[0], salV[1], salV[2], salV[3]); // "SALVAR"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[66])));
    printButton(buffer, volT[0], volT[1], volT[2], volT[3]); // VOLTAR

    if(dispScreen == 35)
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[210])));
      printButton(buffer, deS[0], deS[1], deS[2], deS[3]); //"MAIS"
    }

    setFont(LARGE, 255, 255, 255, 0, 0, 0); 

    if(dispScreen == 24)
    {
      k = 82;
    }

    for(byte i = 0; i < 3; i++)
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[129 + k + i])));  // tabela_textos[129] = "DOSADORA 1:", tabela_textos[130] = "DOSADORA 2:", tabela_textos[131] = "DOSADORA 3:"
      myGLCD.print(buffer, 240, 60 + (i * 140));                                    // tabela_textos[211] = "DOSADORA 4:", tabela_textos[212] = "DOSADORA 5:", tabela_textos[213] = "DOSADORA 6:"
    }

    setFont(LARGE, 255, 0, 0, 0, 0, 0); 

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[141])));
    myGLCD.print(buffer, 460, 120); //tabela_textos[141] = "USE ESTA"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[142])));
    myGLCD.print(buffer, 460, 150); //tabela_textos[141] = "FUNCAO"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[143])));
    myGLCD.print(buffer, 460, 180); // tabela_textos[143] = "APENAS PARA"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[144])));
    myGLCD.print(buffer, 460, 210); //tabela_textos[144] = "DESATIVAR"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[145])));
    myGLCD.print(buffer, 460, 240);  // tabela_textos[145] = "OS MODOS"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[146])));
    myGLCD.print(buffer, 460, 270); // tabela_textos[146] = "DE DOSAGEM."
  }
  if (bitRead(ativar_desativar, i) == true)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[147])));
    printButton_verde(buffer, 200, 90, 440, 170); // tabela_textos[147]

    myGLCD.setColor(0, 0, 0);
    myGLCD.fillRect (6, 52, 234, 86);
    myGLCD.fillRect (6, 90, 190, 122);
    myGLCD.fillRect (6, 120, 190, 152);
    myGLCD.fillRect (6, 150, 190, 182);

    setFont(LARGE, 255, 255, 255, 0, 0, 0);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[149])));
    myGLCD.print(buffer, 20, 60); // tabela_textos[149] = "UM DOS MODOS"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[150])));
    myGLCD.print(buffer, 20, 90); // tabela_textos[150] = "DE DOSAGEM  "

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[151])));
    myGLCD.print(buffer, 20, 120);  // tabela_textos[151] = "ESTA:"
  } 
  else 
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[152])));
    printButton(buffer, 200, 90, 440, 170);

    setFont(LARGE, 255, 255, 0, 0, 0, 0); 

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[153])));
    myGLCD.print(buffer, 6, 60); 

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[150])));
    myGLCD.print(buffer, 6, 90);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[154])));
    myGLCD.print(buffer, 6, 120);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[155])));
    myGLCD.print(buffer, 6, 150); 
  }
  if (bitRead(ativar_desativar, (i + 1)) == true)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[147])));
    printButton_verde(buffer, 200, 230, 440, 310);

    myGLCD.setColor(0, 0, 0); 
    myGLCD.fillRect (6, 192, 234, 226);
    myGLCD.fillRect (6, 230, 190, 262);
    myGLCD.fillRect (6, 260, 190, 292);
    myGLCD.fillRect (6, 290, 190, 322); 

    setFont(LARGE, 255, 255, 255, 0, 0, 0);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[149])));
    myGLCD.print(buffer, 20, 200); // tabela_textos[149] = "UM DOS MODOS"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[150])));
    myGLCD.print(buffer, 20, 230); // tabela_textos[150] = "DE DOSAGEM  "

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[151])));
    myGLCD.print(buffer, 20, 260); // tabela_textos[151] = "ESTA:"
  } 
  else 
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[152])));
    printButton(buffer, 200, 230, 440, 310);  // tabela_textos[152]

    setFont(LARGE, 255, 255, 0, 0, 0, 0); 

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[153])));
    myGLCD.print(buffer, 6, 200); // tabela_textos[153] = "AMBOS OS MODOS"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[150])));
    myGLCD.print(buffer, 6, 230); //tabela_textos[150] =  "DE DOSAGEM  "

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[154])));
    myGLCD.print(buffer, 6, 260); // tabela_textos[154] = "ESTAO OU"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[155])));
    myGLCD.print(buffer, 6, 290); // tabela_textos[155] = "SERAO:"
  }
  if (bitRead(ativar_desativar, (i + 2)) == true)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[147])));
    printButton_verde(buffer, 200, 370, 440, 450); 

    myGLCD.setColor(0, 0, 0);
    myGLCD.fillRect (6, 332, 234, 366);
    myGLCD.fillRect (6, 370, 190, 402);
    myGLCD.fillRect (6, 400, 190, 432);
    myGLCD.fillRect (6, 430, 190, 462);

    setFont(LARGE, 255, 255, 255, 0, 0, 0); 

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[149])));
    myGLCD.print(buffer, 20, 340);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[150])));
    myGLCD.print(buffer, 20, 370);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[151])));
    myGLCD.print(buffer, 20, 400); 
  } 
  else 
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[152])));
    printButton(buffer, 200, 370, 440, 450);

    setFont(LARGE, 255, 255, 0, 0, 0, 0); 

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[153])));
    myGLCD.print(buffer, 6, 340); 

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[150])));
    myGLCD.print(buffer, 6, 370);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[154])));
    myGLCD.print(buffer, 6, 400);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[155])));
    myGLCD.print(buffer, 6, 430);
  }
}

//--------------------------------- Potência mínima e máxima para a luz noturna ----tela =36 
void luz_noturna(boolean refreshAll=false)
{

  if (refreshAll)
  {
    tMaxI = MaxI;
    tMinI = MinI;

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[52])));
    printHeader(buffer); // tabela_textos[52] = "LUZ NOTURNA   255 = 100 %"

    setFont(LARGE, 255, 255, 255, 0, 0, 0);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[180])));
    myGLCD.print(buffer, 187, 140); // "ILUMINACAO MAXIMA:"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[156])));
    myGLCD.print(buffer, 187, 340); // "ILUMINACAO MINIMA:"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[157])));
    myGLCD.print(buffer, 226, 40); // "LUA CHEIA:"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[158])));
    myGLCD.print(buffer, 225, 240); // "LUA NOVA:"

    printButton("-", temM[0], temM[1], temM[2], temM[3], true);      //Lua cheia menos
    printButton("+", temP[0], temP[1], temP[2], temP[3], true);      //Lua cheia mais
    printButton("-", almM[0], almM[1], almM[2], almM[3], true);      //Lua nova menos
    printButton("+", almP[0], almP[1], almP[2], almP[3], true);      //Lua nova mais

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[13])));
    printButton(buffer, salV[0], salV[1], salV[2], salV[3]); // "SALVAR"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[11])));
    printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3]); // "INICIO"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[1])));
    printButton(buffer, menU[0], menU[1], menU[2], menU[3]);  // "MENU 1";

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[66])));
    printButton(buffer, volT[0], volT[1], volT[2], volT[3]);  // tabela_textos[66] = "VOLTAR";
  }

  setFont(LARGE, 255, 255, 255, 0, 0, 0); 
  myGLCD.printNumI(tMaxI, 300, 85);
  myGLCD.printNumI(tMinI, 300, 285);
}

//--------------------------------------------- Menu 2 -------------------------------- tela =37
void menuScreen_2()
{

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[2])));
  printHeader(buffer); // tabela_textos[2] = "MENU 2"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[227])));
  printButton(buffer, tanD[0], tanD[1], tanD[2], tanD[3]); // "SONDAS DE TEMP."// 1º botão, 1ª coluna
  //  printButton("", tesT[0], tesT[1], tesT[2], tesT[3]); // 2º botão, 1ª coluna 
  //  printButton("", temC[0], temC[1], temC[2], temC[3]); // 3º botão, 1ª coluna
  //  printButton("", graF[0], graF[1], graF[2], graF[3]); // 4º botão, 1ª coluna
  //  printButton("", ledW[0], ledW[1], ledW[2], ledW[3]); // 1º botão, 2ª coluna
  //  printButton("", tpaA[0], tpaA[1], tpaA[2], tpaA[3]); // 2º botão, 2ª coluna
  //  printButton("", dosA[0], dosA[1], dosA[2], dosA[3]); // 3º botão, 2ª coluna
  //  printButton("", wavM[0], wavM[1], wavM[2], wavM[3]); // 4º botão, 2ª coluna
  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[1])));
  printButton(buffer, menU[0], menU[1], menU[2], menU[3]); // "MENU 1";

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[11])));
  printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3]); // "INICIO"
}

//--------------------------------------------- Timers -------------------------------- tela =38
void TimerScreen()
{ 
  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[53])));
  printHeader(buffer); // tabela_textos[53] = "SELECIONE O TIMER"

  if (temporizador_ativado_e[0] == 1) 
  {
    printButton_verde("T 1",14, 44, 112, 100);     // Timer 1 
  }
  else 
  {
    printButton("T 1",14, 44, 112, 100);     // Timer 1 
  }      
  if (temporizador_ativado_e[1] == 1) 
  {
    printButton_verde("T 2",142, 44, 240, 100);     // Timer 2 
  }
  else 
  {
    printButton("T 2",142, 44, 240, 100);     // Timer 2 
  }     
  if (temporizador_ativado_e[2] == 1) 
  {
    printButton_verde("T 3",270, 44, 368, 100);     // Timer 3 
  }
  else 
  {
    printButton("T 3",270, 44, 368, 100);     // Timer 3 
  }    
  if (temporizador_ativado_e[3] == 1) 
  {
    printButton_verde("T 4",398, 44, 498, 100);     // Timer 4 
  }
  else 
  {
    printButton("T 4",398, 44, 498, 100);     // Timer 4 
  }        
  if (temporizador_ativado_e[4] == 1) 
  {
    printButton_verde("T 5",526, 44, 624, 100);     // Timer 5 
  }
  else 
  {
    printButton("T 5",526, 44, 624, 100);     // Timer 5
  } 

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[126])));
  printButton_verde(buffer,14, 110, 112, 194);      // Botão ON 1 

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[126])));
  printButton_verde(buffer,142, 110, 240, 194);    // Botão ON 2

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[126])));
  printButton_verde(buffer,270, 110, 368, 194);   // Botão ON 3

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[126])));
  printButton_verde(buffer,398, 110, 496, 194);   // Botão ON 4

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[126])));
  printButton_verde(buffer,526, 110, 624, 194);   // Botão ON 5

  myGLCD.setColor(255, 255, 255);  // Retângulos ao redor dos horários
  myGLCD.drawRoundRect(14, 204, 112, 288);      // Botão ON 1 
  myGLCD.drawRoundRect(142, 204, 240, 288);    // Botão ON 2 
  myGLCD.drawRoundRect(270, 204, 368, 288);   // Botão ON 3 
  myGLCD.drawRoundRect(398, 204, 496, 288);   // Botão ON 4 
  myGLCD.drawRoundRect(526, 204, 624, 288);   // Botão ON 5  

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[127])));
  printButton_vermelho(buffer, 16, 298, 110, 382);      // Botão OFF 1 

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[127])));
  printButton_vermelho(buffer, 144, 298, 238, 382);    // Botão OFF 2 

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[127])));
  printButton_vermelho(buffer, 272, 298, 366, 382);   // Botão OFF 3 

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[127])));
  printButton_vermelho(buffer, 400, 298, 494, 382);   // Botão OFF 4 

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[127])));
  printButton_vermelho(buffer, 528, 298, 622, 382);   // Botão OFF 5 

  myGLCD.setColor(255, 255, 255);  // Retângulos ao redor dos horários
  myGLCD.drawRoundRect(14, 392, 112, 476);     // Botão OFF 1 
  myGLCD.drawRoundRect(142, 392, 240, 476);   // Botão OFF 2 
  myGLCD.drawRoundRect(270, 392, 368, 476);  // Botão OFF 3 
  myGLCD.drawRoundRect(398, 392, 496, 476);  // Botão OFF 4 
  myGLCD.drawRoundRect(526, 392, 624, 476);  // Botão OFF 5

  myGLCD.setBackColor(0, 0, 0);

  for(byte i = 0; i < 5; i++)
  {
    if (on_hora_e[i] < 10) // Timers on
    { 
      myGLCD.print("0", 24 + (i * 128), 234); 
      myGLCD.printNumI(on_hora_e[i], 42 + (i * 128), 234);
    }
    else
    {
      myGLCD.printNumI(on_hora_e[i], 24 + (i * 128), 234);
    }
    myGLCD.print(":", 58 + (i * 128), 234); 

    if (on_minuto_e[i] < 10)
    { 
      myGLCD.print("0", 74 + (i * 128), 234);
      myGLCD.printNumI(on_minuto_e[i], 92 + (i * 128), 234);
    } 
    else 
    { 
      myGLCD.printNumI(on_minuto_e[i], 74 + (i * 128), 234);
    }      

    if (off_hora_e[i] < 10) // Timers off
    { 
      myGLCD.print("0",24 + (i * 128), 422); 
      myGLCD.printNumI(off_hora_e[i], 42 + (i * 128), 422);
    }
    else
    {
      myGLCD.printNumI(off_hora_e[i], 24 + (i * 128), 422);
    }

    myGLCD.print(":", 58 + (i * 128), 420); 

    if (off_minuto_e[i] < 10)
    { 
      myGLCD.print("0", 74 + (i * 128), 422);
      myGLCD.printNumI(off_minuto_e[i], 92 + (i * 128), 422);
    } 
    else 
    { 
      myGLCD.printNumI(off_minuto_e[i], 74 + (i * 128), 422);
    } 
  }  
  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[1])));
  printButton(buffer, menU[0], menU[1], menU[2], menU[3]); // Volta ao menu 1. // "MENU 1";

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[11])));
  printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3]); // Volta ao início.  // "INICIO"
} 
//--------------------------------------------- Configurar timers -------------------------------- tela =39
void config_timer(boolean refreshAll=false)
{
  if( refreshAll == true)
  {
    config_valores_timers_temp();

    if(temporizador == 0)
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[54])));
      printHeader(buffer); // tabela_textos[54] = "CONFIGURAR TIMER 1"
    }
    else if(temporizador == 1)
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[55])));
      printHeader(buffer); // tabela_textos[55] = "CONFIGURAR TIMER 2"
    }
    else  if(temporizador == 2)
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[56])));
      printHeader(buffer); // tabela_textos[56] = "CONFIGURAR TIMER 3"
    }
    else if(temporizador == 3)
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[57])));
      printHeader(buffer); // tabela_textos[57] = "CONFIGURAR TIMER 4"
    } 
    else if(temporizador == 4)
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[58])));
      printHeader(buffer); // tabela_textos[58] ="CONFIGURAR TIMER 5"
    }

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[161])));
    printButton_verde(buffer, 16, 34, 284, 68); // "LIGAR TIMER"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[162])));
    printButton_vermelho(buffer, 346, 34, 624, 68); // "DESLIGAR TIMER"

    printButton("+", 42, 90, 130, 176, true);    // Botão para cima
    printButton("+", 178, 90, 266, 176, true);    // Botão para cima
    printButton("-", 42, 270, 130, 356, true); // Botão para baixo
    printButton("-", 178, 270, 266, 356, true); // Botão para baixo

    printButton("+", 374, 90, 462, 176, true);    // Botão para cima
    printButton("+", 510, 90, 598, 176, true);    // Botão para cima
    printButton("-", 374, 270, 462, 356, true); // Botão para baixo
    printButton("-", 510, 270, 598, 356, true); // Botão para baixo

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[1])));
    printButton(buffer, menU[0], menU[1], menU[2], menU[3]); // Volta ao menu 1.  // "MENU 1";

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[11])));
    printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3]); // Volta ao início. // "INICIO"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[66])));
    printButton(buffer, volT[0], volT[1], volT[2], volT[3]); // Volta ao menu selecionar timer. // "VOLTAR"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[13])));
    printButton(buffer, salV[0], salV[1], salV[2], salV[3]); // Salva as modificações. // "SALVAR"

    setFont(LARGE, 255, 255, 255, 0, 0, 0);          
    myGLCD.print(":",140, 206);
    myGLCD.print(":",472, 206);
  }
  setFont(LARGE, 255, 255, 255, 0, 0, 0);

  if (on_hora[temporizador] < 10)
  {
    myGLCD.print("0",58, 200);           
    myGLCD.printNumI(on_hora[temporizador], 75, 200);
  } 
  else 
  {
    myGLCD.printNumI(on_hora[temporizador], 58, 200);
  }

  if (on_minuto[temporizador] < 10)
  {                            
    myGLCD.print("0", 190, 200);
    myGLCD.printNumI(on_minuto[temporizador], 207, 200);
  } 
  else 
  {
    myGLCD.printNumI(on_minuto[temporizador], 190, 200);
  }

  if (off_hora[temporizador] < 10)
  {
    myGLCD.print("0",386, 200);            
    myGLCD.printNumI(off_hora[temporizador], 403, 200);
  } 
  else 
  {
    myGLCD.printNumI(off_hora[temporizador], 386, 200);
  }

  if (off_minuto[temporizador] < 10)
  {
    myGLCD.print("0",528, 200); 
    myGLCD.printNumI(off_minuto[temporizador], 545, 200);
  } 
  else 
  {
    myGLCD.printNumI(off_minuto[temporizador], 528, 200);
  }
  if (temporizador_ativado[temporizador] == 1) 
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[147])));
    printButton_verde(buffer, domI[0]-40, domI[1], domI[2]+40, domI[3]); // Ativado 120, 193, 200, 233
  }
  else 
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[148])));
    printButton(buffer, domI[0]-40, domI[1], domI[2]+40, domI[3]); // Desativado
  } 
}

//--------------------------------------- Configurar leds --------------------------- tela =40
void config_leds()
{
  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[202])));
  printHeader(buffer); // tabela_textos[2] = "CONFIGURAR LEDS"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[4])));
  printButton(buffer, tanD[0], tanD[1], tanD[2], tanD[3]); // 1º botaão, 1ª coluna 

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[7])));
  printButton(buffer, tesT[0], tesT[1], tesT[2], tesT[3]); // 2º botão, 1ª coluna 

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[159])));
  printButton(buffer, temC[0], temC[1], temC[2], temC[3]); // 3º botão, 1ª coluna 

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[228])));
  printButton(buffer, graF[0], graF[1], graF[2], graF[3]); // "COOLERS"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[232])));
  printButton(buffer, ledW[0], ledW[1], ledW[2], ledW[3]); // "REDUZIR POT."

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[69])));
  printButton(buffer, tpaA[0],tpaA[1], tpaA[2], tpaA[3]); // "predefinido_t"

  //  printButton("", dosA[0], dosA[1], dosA[2], dosA[3]); // 3º botão, 2ª coluna
  //  printButton("", wavM[0], wavM[1], wavM[2], wavM[3]); // 4º botão, 2ª coluna
  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[1])));
  printButton(buffer, menU[0], menU[1], menU[2], menU[3]); // "MENU 1";

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[11])));
  printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3]); // "INICIO"
}

//------------------------------- Procurar sensores de temperatura -------------------------------- tela =41
void procurar_sensores(boolean refreshAll=false)
{
  int numberOfDevices; // Número de sensores encontrados
  float temperatura;

  if(refreshAll == true)
  {
    sonda_associada_1_temp = sonda_associada_1;
    sonda_associada_2_temp = sonda_associada_2;
    sonda_associada_3_temp = sonda_associada_3;

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[214])));
    printHeader(buffer); // "TEMPERATURE PROBE SETUP"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[215])));
    printButton(buffer, busC[0], busC[1], busC[2], busC[3]); // "FIND PROBES";

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[2])));
    printButton(buffer, menU[0], menU[1], menU[2], menU[3]); // "MENU 2"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[11])));
    printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3]); // "HOME"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[13])));
    printButton(buffer, prOK[0], prOK[1], prOK[2], prOK[3]); // "SAVE"

    setFont(LARGE, 255, 255, 255, 0, 0, 0);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[216])));
    myGLCD.print(buffer,90, 44); // "PROBES FOUND"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[217])));
    myGLCD.print(buffer,35, 80); // "1"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[218])));
    myGLCD.print(buffer,35, 100); // "2"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[219])));
    myGLCD.print(buffer,35, 120); // "3"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[220])));
    myGLCD.print(buffer,65, 240); // "USE FOR WATER TEMP."

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[221])));
    myGLCD.print(buffer,65, 310); // "USE FOR LED TEMP."

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[222])));
    myGLCD.print(buffer,65, 380); // "USE FOR ROOM TEMP."
  }

  myGLCD.setColor(0, 0, 0);
  myGLCD.fillRect(5, 160, 400, 190); //Clear error message: "DO NOT ASSOCIE 2 OR 3 PROBES AT THE SAME PARAMETER"
  myGLCD.fillRect(5, 190, 400, 220); //Clear error message: "DO NOT ASSOCIE 2 OR 3 PROBES AT THE SAME PARAMETER"

  if(sonda_associada_1_temp == 1)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[217]))); // "SONDA 1"
    printButton(buffer, sonD1[0], sonD1[1], sonD1[2], sonD1[3]);
  }
  if(sonda_associada_1_temp == 2)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[218]))); // "SONDA 2"
    printButton_verde(buffer, sonD1[0], sonD1[1], sonD1[2], sonD1[3]); 
  }
  if(sonda_associada_1_temp == 3)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[219]))); // "SONDA 3"
    printButton_vermelho(buffer, sonD1[0], sonD1[1], sonD1[2], sonD1[3]);
  } 

  if(sonda_associada_2_temp == 1)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[217]))); // "SONDA 1"
    printButton(buffer, sonD2[0], sonD2[1], sonD2[2], sonD2[3]);
  }
  if(sonda_associada_2_temp == 2)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[218]))); // "SONDA 2"
    printButton_verde(buffer, sonD2[0], sonD2[1], sonD2[2], sonD2[3]); 
  }
  if(sonda_associada_2_temp == 3)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[219]))); // "SONDA 3"
    printButton_vermelho(buffer, sonD2[0], sonD2[1], sonD2[2], sonD2[3]);
  } 

  if(sonda_associada_3_temp == 1)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[217]))); // "SONDA 1"
    printButton(buffer, sonD3[0], sonD3[1], sonD3[2], sonD3[3]);
  }
  if(sonda_associada_3_temp == 2)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[218]))); // "SONDA 2"
    printButton_verde(buffer, sonD3[0], sonD3[1], sonD3[2], sonD3[3]);
  }
  if(sonda_associada_3_temp == 3)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[219]))); // "SONDA 3"
    printButton_vermelho(buffer, sonD3[0], sonD3[1], sonD3[2], sonD3[3]);
  }

  sensors.begin();
  numberOfDevices = sensors.getDeviceCount();

  setFont(LARGE, 88, 255, 238, 0, 0, 0);
  myGLCD.printNumI(numberOfDevices, 65, 44);  // NUMBER OF PROBES FOUND, IN THIS CASE,"3"

  for(byte k = 0; k < numberOfDevices; k++)
  {
    // Pesquisar endereços
    if(sensors.getAddress(tempDeviceAddress, k))
    {
      temperatura = sensors.getTempC(tempDeviceAddress);
      temperatura = (temperatura * 1.8) + 32;
      if (k == 0)
      { 
        for (byte i=0; i<8; i++) 
        {
          sonda1[i] = tempDeviceAddress[i];
        }
      }
      if (k == 1)
      { 
        for (byte i=0; i<8; i++) 
        {
          sonda2[i] = tempDeviceAddress[i];
        }
      }
      if (k == 2)
      { 
        for (byte i = 0; i < 8; i++) 
        {
          sonda3[i] = tempDeviceAddress[i];
        }
      }      
    }
    myGLCD.setColor(255, 255, 255); 
    myGLCD.print(":", 55, (k * 20) + 80);

    myGLCD.setColor(255, 163, 100); 
    myGLCD.printNumF(temperatura, 1, 278,(k * 18) + 80);    // Imprime as teperaturas.
    myGLCD.print(":", 262, (k * 20) + 80);
    myGLCD.print("F", 360, (k * 20) + 80);//myGLCD.print("C", 315, (k * 15) + 80);
    myGLCD.drawCircle(355, (k * 20) + 82, 1);

    setFont(LARGE, 88, 255, 238, 0, 0, 0);
    for (byte i = 0; i < 8; i++) 
    {
      byte result;
      byte temp = tempDeviceAddress[i];
      result = temp/16;		     //Converte primeiro caracter HEX para ASCII
      if (result == 15) 
      {
        myGLCD.print("F", (i * 24) + 74, (k * 20) + 80);
      }
      if (result == 14) 
      {
        myGLCD.print("E", (i * 24) + 74, (k * 20) + 80);
      } 
      if (result == 13) 
      {
        myGLCD.print("D", (i * 24) + 74, (k * 20) + 80);
      }
      if (result == 12) 
      {
        myGLCD.print("C", (i * 24) + 74, (k * 20) + 80);
      }
      if (result == 11) 
      {
        myGLCD.print("B", (i * 24) + 74, (k * 20) + 80);
      }
      if (result == 10) 
      {
        myGLCD.print("A", (i * 24 + 74), (k * 20) + 80);
      }
      if (result < 10 ) 
      {
        myGLCD.printNumI(result, (i * 24) + 74, (k * 20) + 80);
      }

      result = temp - (temp/16) * 16;           // Converte segundo caracter HEX para ASCII
      if (result == 15) 
      {
        myGLCD.print("F", (i * 24) + 82, (k * 20) + 80);
      }
      if (result == 14) 
      {
        myGLCD.print("E", (i * 24) + 82, (k * 20) + 80);
      }
      if (result == 13) 
      {
        myGLCD.print("D", (i * 24) + 82, (k * 20) + 80);
      }
      if (result == 12) 
      {
        myGLCD.print("C", (i * 24) + 82, (k * 20) + 80);
      } 
      if (result == 11) 
      {
        myGLCD.print("B", (i * 24) + 82, (k * 20) + 80);
      }
      if (result == 10) 
      {
        myGLCD.print("A", (i * 24) + 82, (k * 20) + 80);
      }
      if (result < 10)
      {
        myGLCD.printNumI(result, (i * 24) + 82, (k * 20) + 80);
      }
      if (i<7)
      {
        myGLCD.print(":", (i * 24) + 90, (k * 20) + 80);
      } 
    }
  }
}
//------------------------------- Configurar temperatura para os coolers -------------------------------- tela =42
void configurar_coolers(boolean refreshAll = false)
{
  if(refreshAll == true)
  {
    HtempMin_temp = HtempMin;
    HtempMax_temp = HtempMax;

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[229])));
    printHeader(buffer); // "CONFIG. TEMPERATURAS PARA OS COOLERS"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[1])));
    printButton(buffer, menU[0], menU[1], menU[2], menU[3]); // "MENU 1";

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[11])));
    printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3]); // "INICIO"  

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[13])));
    printButton(buffer, salV[0], salV[1], salV[2], salV[3]); // "SALVAR"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[66])));
    printButton(buffer, volT[0], volT[1], volT[2], volT[3]); // VOLTAR  

    setFont(LARGE, 255, 255, 255, 0, 0, 0);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[230])));
    myGLCD.print(buffer, 220, 40); // "INIACIAR EM:"

    myGLCD.print("(68 ----- 95)", 220, 140); //myGLCD.print("(20 ----- 35)", 220, 140); // interval // interval // CHANGE VALUES FOR F SCALE TO (68 --- 95)

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[231])));
    myGLCD.print(buffer, 160, 240); // "VELOCIDADE MAXIMA EM:"

    myGLCD.print("(85 ---- 122)", 220, 340); //myGLCD.print("(36 ----- 50)", 220, 340); // interval // interval // CHANGE VALUES FOR F SCALE TO (85 --- 122)

    printButton("-", temM[0], temM[1], temM[2], temM[3], true);      // Temperatura para iniciar +
    printButton("+", temP[0], temP[1], temP[2], temP[3], true);      // Temperatura para iniciar -
    printButton("-", almM[0], almM[1], almM[2], almM[3], true);      // Temperatura para velocidade máxima +
    printButton("+", almP[0], almP[1], almP[2], almP[3], true);      // Temperatura para velocidade máxima -
  }

  setFont(LARGE, 255, 255, 255, 0, 0, 0); 
  myGLCD.printNumF(HtempMin_temp, 1, 290, 80);
  myGLCD.printNumF(HtempMax_temp, 1, 290, 280);
}

//------------------------------- Configurar temperatura para os coolers -------------------------------- tela =43
void reduzir_potencia(boolean refreshAll = false)
{
  if(refreshAll == true)
  {
    tempHR_t = tempHR;
    potR_t = potR; 

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[235]))); // "CONFIG. TEMPERATURA E POTENCIA DOS LEDS"
    printHeader(buffer);    

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[1])));
    printButton(buffer, menU[0], menU[1], menU[2], menU[3]); // "MENU 1";

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[11])));
    printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3]); // "INICIO"  

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[13])));
    printButton(buffer, salV[0], salV[1], salV[2], salV[3]); // "SALVAR"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[66])));
    printButton(buffer, volT[0], volT[1], volT[2], volT[3]); // VOLTAR

    printButton("+", tempeC[0], tempeC[1], tempeC[2], tempeC[3], true);
    printButton("-", tempeB[0], tempeB[1], tempeB[2], tempeB[3], true);

    printButton("+", potC[0], potC[1], potC[2], potC[3], true);
    printButton("-", potB[0], potB[1], potB[2], potB[3], true);

    setFont(LARGE, 255, 255, 255, 0, 0, 0);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[233]))); // "SE A TEMPERATURA ALCANCAR"
    myGLCD.print(buffer, 40, 118);  

    myGLCD.drawCircle(593, 119, 2);              
    myGLCD.print(" F ", 595, 118);//myGLCD.print(" C ", 299, 59); /******************************************************** changed for Fahrenheit *******************************************************************/
  
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[234]))); // "REDUZIR POTENCIA EM"
    myGLCD.print(buffer, 130, 280);  
    myGLCD.print("%.", 590, 280);  
  }
  myGLCD.setColor(0, 0, 0);    
  myGLCD.fillRect(450, 270, 520, 310); // Apaga valores

  setFont(LARGE, 0, 255, 0, 0, 0, 0);
  myGLCD.printNumI(tempHR_t, 450, 118);
  myGLCD.printNumI(potR_t, 450, 280); 
}

//------------------------------- Potência pré-definida para os leds -------------------------------- tela =44
void pre_definido(boolean refreshAll = false)
{
  int j = 0;
  int i = 0;

  if(refreshAll == true)
  {
    if(horario_alterado == false)
    {
      predefinido_t = predefinido;
      pre_definido_ativado_t = pre_definido_ativado;
      pwm_pre_definido_t = pwm_pre_definido;
      led_on_minuto_t =led_on_minuto; 
      led_on_hora_t = led_on_hora;
      led_off_minuto_t = led_off_minuto; 
      led_off_hora_t = led_off_hora;
      amanhecer_anoitecer_t = amanhecer_anoitecer;
    }
    horario_alterado = false;

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[249]))); // "CONFIG. VALORES predefinido_tS"
    printHeader(buffer);    

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[1])));
    printButton(buffer, menU[0], menU[1], menU[2], menU[3]); // "MENU 1";

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[11])));
    printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3]); // "INICIO"  

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[13])));
    printButton(buffer, salV[0], salV[1], salV[2], salV[3]); // "SALVAR"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[66])));
    printButton(buffer, volT[0], volT[1], volT[2], volT[3]); // VOLTAR

    printButton("+", 420, 380, 480, 440, true); // Todos pwm + 
    printButton("-", 560, 380, 620, 440, true); // Todos pwm -

    for(i = 0; i < 5; i++)
    {     
      j = i * 5;

      printButton("+", 270, 120 + (i * 60) + j, 330, 180 + (i * 60) + j, true);
      printButton("-", 340, 120 + (i * 60) + j, 400, 180 + (i * 60) + j, true);
    }

    setFont(LARGE, 255, 255, 255, 0, 0, 0);
    myGLCD.print("PWM", 495, 382);

    setFont(LARGE, 255, 255, 255, 0, 0, 0);

    if (led_on_hora_t < 10)
    {
      myGLCD.print("0", 478, 250-10);           
      myGLCD.printNumI(led_on_hora_t, 494, 250-10);
    } 
    else 
    {
      myGLCD.printNumI(led_on_hora_t, 478, 250-10);
    }

    myGLCD.print(":", 512, 240);

    if (led_on_minuto_t < 10)
    {                            
      myGLCD.print("0", 530, 240);
      myGLCD.printNumI(led_on_minuto_t, 546, 240);
    } 
    else 
    {
      myGLCD.printNumI(led_on_minuto_t, 530, 240);
    }

    if (led_off_hora_t < 10)
    {
      myGLCD.print("0", 478, 310);            
      myGLCD.printNumI(led_off_hora_t, 494, 310);
    } 
    else 
    {
      myGLCD.printNumI(led_off_hora_t, 478, 310);
    }

    myGLCD.print(":", 512, 310);

    if (led_off_minuto_t < 10)
    {
      myGLCD.print("0", 530, 310); 
      myGLCD.printNumI(led_off_minuto_t, 546, 310);
    } 
    else 
    {
      myGLCD.printNumI(led_off_minuto_t, 530, 310);
    }

    setFont(LARGE, 0, 255, 0, 0, 0, 0);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[250])));   
    myGLCD.print(buffer, 464, 214); // "SUNRISE"

    myGLCD.setColor(255, 0, 0);
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[251])));   
    myGLCD.print(buffer, 471, 284); // "SUNSET"    

    myGLCD.setColor(255, 255, 0);
    myGLCD.drawRect(420, 190, 620, 364);
    myGLCD.drawRect(422, 192, 618, 362);

  }// fim do refreshAll
  if(horario_alterado == false)
  {
    if((predefinido_t == 0) && (pre_definido_ativado_t == 1)) // Se predefinido_t igual a zero. Controlar individualmente.
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[247])));
      printButton_verde(buffer, 20, 50, 400, 110); // "CONT. INDIVIDUALMENTE"  

      myGLCD.setFont(BigFont);

      for(i = 0; i < 5; i++)
      {     
        j = i * 5;

        if(i == 0)
        {
          myGLCD.setColor(cor_canal1[0], cor_canal1[1], cor_canal1[2]);
          myGLCD.fillRoundRect(20, 120 + (i * 60) + j, 260, 180 + (i * 60) + j);
          myGLCD.setColor(0, 0, 0);
          myGLCD.setBackColor(cor_canal1[0], cor_canal1[1], cor_canal1[2]);
          strcpy_P(buffer, (char*)pgm_read_word_near(&(nome_canal[6])));
          myGLCD.print(buffer, 30, 144  + (i * 60) + j); // "BRANCO"
          myGLCD.print(":", 190, 144  + (i * 60) + j);
          myGLCD.print(" ", 206, 144  + (i * 60) + j);
          myGLCD.printNumI(wled_out_temp, 206, 144  + (i * 60) + j);
        }
        else if(i == 1)
        {
          myGLCD.setColor(cor_canal2[0], cor_canal2[1], cor_canal2[2]);
          myGLCD.fillRoundRect(20, 120 + (i * 60) + j, 260, 180 + (i * 60) + j);
          myGLCD.setColor(0, 0, 0);
          myGLCD.setBackColor(cor_canal2[0], cor_canal2[1], cor_canal2[2]);
          strcpy_P(buffer, (char*)pgm_read_word_near(&(nome_canal[7])));
          myGLCD.print(buffer, 30, 144  + (i * 60) + j); // "AZUL"
          myGLCD.print(":", 190, 144  + (i * 60) + j);
          myGLCD.print(" ", 206, 144  + (i * 60) + j);
          myGLCD.printNumI(bled_out_temp, 206, 144  + (i * 60) + j);
        }
        else if(i == 2)
        {
          myGLCD.setColor(cor_canal3[0], cor_canal3[1], cor_canal3[2]);
          myGLCD.fillRoundRect(20, 120 + (i * 60) + j, 260, 180 + (i * 60) + j);
          myGLCD.setColor(0, 0, 0);
          myGLCD.setBackColor(cor_canal3[0], cor_canal3[1], cor_canal3[2]);
          strcpy_P(buffer, (char*)pgm_read_word_near(&(nome_canal[8])));
          myGLCD.print(buffer, 30, 144  + (i * 60) + j); // "AZUL ROYAL"
          myGLCD.print(":", 190, 144  + (i * 60) + j);
          myGLCD.print(" ", 206, 144  + (i * 60) + j);
          myGLCD.printNumI(rbled_out_temp, 206, 144  + (i * 60) + j);
        }
        else if(i == 3)
        {
          myGLCD.setColor(cor_canal4[0], cor_canal4[1], cor_canal4[2]);
          myGLCD.fillRoundRect(20, 120 + (i * 60) + j, 260, 180 + (i * 60) + j);
          myGLCD.setColor(0, 0, 0);
          myGLCD.setBackColor(cor_canal4[0], cor_canal4[1], cor_canal4[2]);
          strcpy_P(buffer, (char*)pgm_read_word_near(&(nome_canal[9])));
          myGLCD.print(buffer, 30, 144  + (i * 60) + j); // "VERMELHO"
          myGLCD.print(":", 190, 144  + (i * 60) + j);
          myGLCD.print(" ", 206, 144  + (i * 60) + j);
          myGLCD.printNumI(rled_out_temp, 206, 144  + (i * 60) + j);
        }
        else if(i == 4)
        {
          myGLCD.setColor(cor_canal5[0], cor_canal5[1], cor_canal5[2]);
          myGLCD.fillRoundRect(20, 120 + (i * 60) + j, 260, 180 + (i * 60) + j);
          myGLCD.setColor(0, 0, 0);
          myGLCD.setBackColor(cor_canal5[0], cor_canal5[1], cor_canal5[2]);
          strcpy_P(buffer, (char*)pgm_read_word_near(&(nome_canal[10])));
          myGLCD.print(buffer, 30, 144  + (i * 60) + j); // "VIOLETA"
          myGLCD.print(":", 190, 144  + (i * 60) + j);
          myGLCD.print(" ", 206, 144  + (i * 60) + j);
          myGLCD.printNumI(uvled_out_temp, 206, 144  + (i * 60) + j);
        }
        myGLCD.setColor(255, 255, 255);
        myGLCD.drawRoundRect(20, 120 + (i * 60) + j, 260, 180 + (i * 60) + j);
      }
    }
    else // Se predefinido_t igual a um. Controlar todos juntos.
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[247])));
      printButton(buffer, 20, 50, 400, 110); // "CONT. INDIVIDUALMENTE"

      for(i = 0; i < 5; i++)
      {     
        j = i * 5;
        myGLCD.setColor(100, 100, 100);
        myGLCD.fillRoundRect(20, 120 + (i * 60) + j, 260, 180 + (i * 60) + j);

        myGLCD.setColor(255, 255, 255);
        myGLCD.drawRoundRect(20, 120 + (i * 60) + j, 260, 180 + (i * 60) + j);

        myGLCD.setBackColor(100, 100, 100);
        myGLCD.setFont(BigFont);

        if(i == 0)
        {
          strcpy_P(buffer, (char*)pgm_read_word_near(&(nome_canal[6])));
          myGLCD.print(buffer, 30, 144 + (i * 60) + j); // "WHITE"
          myGLCD.print(":", 190, 144 + (i * 60) + j);
          myGLCD.print(" ", 206, 144 + (i * 60) + j);
          myGLCD.printNumI(wled_out_temp, 206, 144 + (i * 60) + j);

        }
        if(i == 1)
        {
          strcpy_P(buffer, (char*)pgm_read_word_near(&(nome_canal[7])));
          myGLCD.print(buffer, 30, 144 + (i * 60) + j); // "GREEN"
          myGLCD.print(":", 190, 144 + (i * 60) + j);
          myGLCD.print(" ", 206, 144 + (i * 60) + j);
          myGLCD.printNumI(bled_out_temp, 206, 144 + (i * 60) + j);
        }
        if(i == 2)
        {
          strcpy_P(buffer, (char*)pgm_read_word_near(&(nome_canal[8])));
          myGLCD.print(buffer, 30, 144 + (i * 60) + j); // "BLUE"
          myGLCD.print(":", 190, 144 + (i * 60) + j);
          myGLCD.print(" ", 206, 144 + (i * 60) + j);
          myGLCD.printNumI(rbled_out_temp, 206, 144 + (i * 60) + j);
        }
        if(i == 3)
        {
          strcpy_P(buffer, (char*)pgm_read_word_near(&(nome_canal[9])));
          myGLCD.print(buffer, 30, 144 + (i * 60) + j); // "RED"
          myGLCD.print(":", 190, 144 + (i * 60) + j);
          myGLCD.print(" ", 206, 144 + (i * 60) + j);
          myGLCD.printNumI(rled_out_temp, 206, 144 + (i * 60) + j);
        }
        if(i == 4)
        {
          strcpy_P(buffer, (char*)pgm_read_word_near(&(nome_canal[10])));
          myGLCD.print(buffer, 30, 144 + (i * 60) + j); // "VIOLET"
          myGLCD.print(":", 190, 144 + (i * 60) + j);
          myGLCD.print(" ", 206, 144 + (i * 60) + j);
          myGLCD.printNumI(uvled_out_temp, 206, 144 + (i * 60) + j);
        }   
      }
    }  

    if((predefinido_t == 1) && (pre_definido_ativado_t == 1))
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[248])));
      printButton_verde(buffer, 420, 50, 620, 110); // "CONT. TODOS"
    }
    else
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[248])));
      printButton(buffer, 420, 50, 620, 110); // "CONT. TODOS"
    }

    if(pre_definido_ativado_t == 1)
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[147]))); 
      printButton_verde(buffer, 420, 120, 620, 180); // "ATIVADO"
    }
    else
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[148])));
      printButton(buffer, 420, 120, 620, 180); // "DESATIVADO" 
    }

    if((predefinido_t == 1) && (pre_definido_ativado_t == 1))
    {
      setFont(LARGE, 255, 255, 255, 0, 0, 0);
    }
    else
    {
      setFont(LARGE, 100, 100, 100, 0, 0, 0); 
    }
    myGLCD.print(" ", 484, 420);
    if(pwm_pre_definido_t >= 100)
    {
      myGLCD.printNumI(pwm_pre_definido_t, 494, 420);
    }
    else if((pwm_pre_definido_t >= 10) && (pwm_pre_definido_t < 100))
    {
      myGLCD.printNumI(pwm_pre_definido_t, 508, 420);
    }
    else
    {
      myGLCD.printNumI(pwm_pre_definido_t, 512, 420); 
    }
  }
  if(horario_alterado == true)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[254]))); // "CONFIG. PHOTOPERIODO"
    printHeader(buffer);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[250])));
    printButton_verde(buffer, 16, 34, 284, 68); // "SUNRISE"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[251])));
    printButton_vermelho(buffer, 346, 34, 624, 68); // "SUNSET"

    setFont(LARGE, 255, 255, 255, 0, 0, 0);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[253])));
    myGLCD.print(buffer, 30, 310); // "DURACAO DO NASCER E POR DO SOL EM MIN."

    printButton("+", 60, 90, 110, 140, true);    // Botão para cima
    printButton("+", 200, 90, 250, 140, true);    // Botão para cima
    printButton("-", 60, 210, 110, 260, true); // Botão para baixo
    printButton("-", 200, 210, 250, 260, true); // Botão para baixo

    printButton("+", 390, 90, 440, 140, true);    // Botão para cima
    printButton("+", 530, 90, 580, 140, true);    // Botão para cima
    printButton("-", 390, 210, 440, 260, true); // Botão para baixo
    printButton("-", 530, 210, 580, 260, true); // Botão para baixo


    printButton("-", 200, 350, 250, 400, true);    // Botão para cima
    printButton("+", 390, 350, 440, 400, true);    // Botão para cima


    setFont(LARGE, 255, 255, 255, 0, 0, 0);          
    myGLCD.print(":",142, 168);
    myGLCD.print(":",474, 168);

    setFont(LARGE, 255, 255, 255, 0, 0, 0);
    if (led_on_hora_t < 10)
    {
      myGLCD.print("0",66, 166);           
      myGLCD.printNumI(led_on_hora_t, 82, 166);
    } 
    else 
    {
      myGLCD.printNumI(led_on_hora_t, 66, 166);
    }

    if (led_on_minuto_t < 10)
    {                            
      myGLCD.print("0", 204, 166);
      myGLCD.printNumI(led_on_minuto_t, 220, 166);
    } 
    else 
    {
      myGLCD.printNumI(led_on_minuto_t, 204, 166);
    }

    if (led_off_hora_t < 10)
    {
      myGLCD.print("0",394, 166);            
      myGLCD.printNumI(led_off_hora_t, 410, 166);
    } 
    else 
    {
      myGLCD.printNumI(led_off_hora_t, 394, 166);
    }

    if (led_off_minuto_t < 10)
    {
      myGLCD.print("0",541, 166); 
      myGLCD.printNumI(led_off_minuto_t, 557, 166);
    } 
    else 
    {
      myGLCD.printNumI(led_off_minuto_t, 541, 166);
    }

    if (amanhecer_anoitecer_t < 100)
    {
      myGLCD.print(" ", 282, 358); // DURATION OF SUNRISE/SUNSET IN MINUTES     
      myGLCD.printNumI(amanhecer_anoitecer_t, 298, 370);
    } 
    else 
    {
      myGLCD.printNumI(amanhecer_anoitecer_t, 298, 375);
    }
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[252])));
    printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3]); // "READY"

    myGLCD.setColor(0, 0, 0);
    myGLCD.fillRoundRect(1, 402, 798, 478);
  }
}
