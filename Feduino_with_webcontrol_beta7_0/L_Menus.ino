//------------------------------------ Menu 1 ----------------------------------------------------------- tela =1
void menuScreen()
{
  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[1])));
  printHeader(buffer); // tabela_textos[1] = "MENU 1";

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[3])));
  printButton(buffer, tanD[0], tanD[1], tanD[2], tanD[3]); // "HORA E DATA"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[201])));
  printButton(buffer, tesT[0], tesT[1], tesT[2], tesT[3]); // "CONFIG. LEDS"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[5])));
  printButton(buffer, temC[0], temC[1], temC[2], temC[3]); // "CONTROLE PARAM."

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[6])));
  printButton(buffer, graF[0], graF[1], graF[2], graF[3]); // "GRAFICOS"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[160])));
  printButton(buffer, ledW[0], ledW[1], ledW[2], ledW[3]); // tabela_textos[160] = "TIMERS"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[8])));
  printButton(buffer, tpaA[0], tpaA[1], tpaA[2], tpaA[3]); // "TPA AUTOMATICA"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[9])));
  printButton(buffer, dosA[0], dosA[1], dosA[2], dosA[3]); // "DOSADORAS"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[10])));
  printButton(buffer, wavM[0], wavM[1], wavM[2], wavM[3]); // "WAVEMAKER"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[11])));
  printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3]); // "INICIO"

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
  printButton(buffer, prOK[0], prOK[1], prOK[2], prOK[3]); // "SALVAR"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[11])));
  printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3]); // "INICIO"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[1])));
  printButton(buffer, menU[0], menU[1], menU[2], menU[3]); // "MENU 1";

  setFont(LARGE, 255, 255, 255, 0, 0, 0);

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[14])));
  myGLCD.print(buffer, 20, 102); // "time:"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[15])));
  myGLCD.print(buffer, 20, 268); // "DATE:"

  setFont(LARGE, 255, 255, 255, 0, 0, 0);
  myGLCD.print(":", 240, 96);
  myGLCD.print(":", 420, 96);

  if (t_temp.hour<10)
  {
    myGLCD.printNumI(0, 156, 96);
    myGLCD.printNumI(t_temp.hour, 172, 96);
  }
  else
  {
    myGLCD.printNumI(t_temp.hour, 156, 96);
  }
  if (t_temp.min<10)
  {
    myGLCD.printNumI(0, 336, 96);
    myGLCD.printNumI(t_temp.min, 352, 96);
  }
  else
  {
    myGLCD.printNumI(t_temp.min, 336, 96);
  }
  if (t_temp.sec<10)
  {
    myGLCD.printNumI(0, 516, 102);
    myGLCD.printNumI(t_temp.sec, 532, 96);
  }
  else
  {
    myGLCD.printNumI(t_temp.sec, 516, 96);
  }
  if (t_temp.date<10)
  {
    myGLCD.printNumI(0, 156, 264);
    myGLCD.printNumI(t_temp.date, 172, 264);
  }
  else
  {
    myGLCD.printNumI(t_temp.date, 156, 264);
  }
  if (t_temp.mon<10)
  {
    myGLCD.printNumI(0, 336, 264);
    myGLCD.printNumI(t_temp.mon, 352, 264);
  }
  else
  {
    myGLCD.printNumI(t_temp.mon, 336, 264);
  }
  myGLCD.printNumI(t_temp.year, 492, 264);

}

void testScreen(boolean refreshAll=false)//-------------------------------- Teste do leds ------------------------------------- tela =3
{
  char bufferL[9];
  String led;

  if (refreshAll == true)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[16])));
    printHeader(buffer); // tabela_textos[16] "TESTAR VARIACAO DE LUMINOSIDADE"
    myGLCD.fillRect (1, 30, 636, 74); //clear 'Test in progress'
    printButton ("", stsT[0], stsT[1], stsT[2], stsT[3], true); //start/stop
    printButton ("-10s", tenM[0], tenM[1], tenM[2], tenM[3], true); //-10s
    printButton ("+10s", tenP[0], tenP[1], tenP[2], tenP[3], true); //+10s

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[17])));
    myGLCD.print(buffer, stsT[0]+10, stsT[1]+15); // "START"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[18])));
    myGLCD.print(buffer, stsT[0]+25, stsT[1]+40); // "TEST"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[11])));
    printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3]); // "HOME"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[1])));
    printButton(buffer, menU[0], menU[1], menU[2], menU[3]); // "MENU 1";

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[66])));
    printButton(buffer, volT[0], volT[1], volT[2], volT[3]); // tabela_textos[66] = "VOLTAR"
  }
  else
  {
    if(teste_iniciado == true)
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[19])));
      printHeader(buffer); // tabela_textos[19] = "TESTAR VARIACAO DE LUMINOSIDADE"
      printButton ("", stsT[0], stsT[1], stsT[2], stsT[3], true); //start/stop
      printButton ("-10s", tenM[0], tenM[1], tenM[2], tenM[3], true); //-10s
      printButton ("+10s", tenP[0], tenP[1], tenP[2], tenP[3], true); //+10s

      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[17])));
      myGLCD.print(buffer, stsT[0]+10, stsT[1]+15); // "INICIAR"

      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[18])));
      myGLCD.print(buffer, stsT[0]+25, stsT[1]+40); // "TEST"
      min_cnt=0;

      myGLCD.setColor(0, 0, 200);
      myGLCD.fillRect(stsT[0]+10, stsT[1]+10, stsT[2]-10, stsT[3]-80); //clear 'start'
      setFont(LARGE, 255, 255, 255, 0, 0, 200);

      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[20])));
      myGLCD.print(buffer, stsT[0]+25, stsT[1]+15); // "PARAR"

      myGLCD.setColor(255, 0, 0);
      myGLCD.fillRect (1, 30, 636, 74);
      myGLCD.drawRoundRect (stsT[0], stsT[1], stsT[2], stsT[3]); //red button during test
      setFont(LARGE, 255, 255, 255, 255, 0, 0);

      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[21])));
      myGLCD.print(buffer, 30, 36); // "TESTE EM ANDAMENTO"

      setFont(LARGE, 255, 255, 255, 0, 0, 0);

      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[22])));
      myGLCD.print(buffer, 66, 80); // "TEMPO:"

      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[23])));
      myGLCD.print(buffer, 60, 80); // "POTENCIA DE SAIDA (0-255):"
    }

    if (LEDtestTick == true) //test LED and speed up time
    {
      if (millis() - previousMillis > 500) //change time every 0.5s
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
    } //change to current temp.
    temp2beS = setTempC;
    temp2beO = offTempC;
    temp2beA = alarmTempC;

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[24])));
    printHeader(buffer); //tabela_textos[24] "WATER TEMPERATURE CONTROL"

    setFont(LARGE, 255, 255, 255, 0, 0, 0);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[74])));
    myGLCD.print(buffer, 170, 40); // "DESIRED TEMPERATURE:"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[75])));
    myGLCD.print(buffer, 180, 140); // "ALLOWABLE VARIATION:"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[76])));
    myGLCD.print(buffer, 100, 240); // "VARIATION TO ACTIVATE ALARM:"

    printButton("-", temM[0], temM[1], temM[2], temM[3], true); //temp minus
    printButton("+", temP[0], temP[1], temP[2], temP[3], true); //temp plus
    printButton("-", offM[0], offM[1], offM[2], offM[3], true); //offset minus
    printButton("+", offP[0], offP[1], offP[2], offP[3], true); //offset plus
    printButton("-", almM[0], almM[1], almM[2], almM[3], true); //alarm minus
    printButton("+", almP[0], almP[1], almP[2], almP[3], true); //alarm plus

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[13])));
    printButton(buffer, prOK[0], prOK[1], prOK[2], prOK[3]); // "SALVAR"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[11])));
    printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3]); // "INICIO"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[66])));
    printButton(buffer, menU[0], menU[1], menU[2], menU[3]);
  }

  setFont(LARGE, 255, 255, 255, 0, 0, 0);
  myGLCD.printNumF(temp2beS, 1, 280, 80);
  myGLCD.printNumF(temp2beO, 1, 280, 180);
  myGLCD.printNumF(temp2beA, 1, 280, 280);
}
void ledSetScreen() //-------------------------------- Alterar valores ----------------------------------- tela =5
{
  int a;

  if (cor_selecionada == 0) 
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(nome_canal[17])));
    printHeader(buffer); // "POTENCIA DOS LEDS BRANCOS: 255 = 100%"
  }
  else if (cor_selecionada == 1) 
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(nome_canal[18])));
    printHeader(buffer); // "POTENCIA LEDS AZUIS: 255 = 100%"
  }  
  else if (cor_selecionada == 2) 
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(nome_canal[19])));
    printHeader(buffer); // "POTENCIA LEDS AZUIS ROYAL: 255 = 100%"
  } 
  else if (cor_selecionada == 3) 
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(nome_canal[20])));
    printHeader(buffer); // "POTENCIA LEDS VERMELHOS: 255 = 100%"
  } 
  else if (cor_selecionada == 4) 
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(nome_canal[21])));
    printHeader(buffer); // "POTENCIA LEDS VIOLETAS: 255 = 100%"
  } 

  setFont(SMALL, 255, 255, 255, 0, 0, 0);
  for (int i = 0; i < 12; i++) 
  {
    myGLCD.setColor(0, 255, 255);
    myGLCD.printNumI((i*2), (i*26)+13, 22); 
    if(i == 11)
    {
      myGLCD.print("0", (i*26)+17, 36);
    }
    else
    {
      myGLCD.printNumI(((i*2)+2), (i*26)+13, 36);
    }
    for (int j=0; j<8; j++) 
    {
      a = (i*8)+j;         
      myGLCD.setColor(255, 255, 255);
      myGLCD.printNumI(cor[cor_selecionada][a], (i*26)+7, (j*18)+54);
      myGLCD.setColor(100, 100, 100);
      myGLCD.drawRect((i*26)+4, (j*18)+50, (i*26)+30, (j*18)+68);
      myGLCD.drawRect((i*26)+4, 16, (i*26)+30, 50);//
    }
  }

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[81])));
  printButton(buffer, leST[0], leST[1], leST[2], leST[3], SMALL); // "ALTERAR"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[82])));
  printButton(buffer, savE[0], savE[1], savE[2], savE[3], SMALL); // "SALVAR EEPROM"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[1])));
  printButton(buffer, menU[0], menU[1], menU[2], menU[3]); // "MENU 1";

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[11])));
  printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3]);  // "INICIO"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[210])));
  printButton(buffer, leWB[0], leWB[1], leWB[2], leWB[3], SMALL); // tabela_textos[210] = "MAIS"
}

void ledChangeScreen(boolean refreshAll=false)    //--------------------------------------- PotÃƒÂªncia dos leds------------------------------ tela =6
{
  if(refreshAll == true)
  {
    mensagem = true;
    if (cor_selecionada == 0)
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(nome_canal[12])));
      printHeader(buffer); // nome_canal[12] = "ALTERAR POTENCIAS DOS LEDS BRANCOS"
    }
    else if (cor_selecionada == 1)
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(nome_canal[13])));
      printHeader(buffer); // nome_canal[13] = "ALTERAR POTENCIA DOS LEDS AZUIS"
    }
    else if (cor_selecionada == 2)
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(nome_canal[14])));
      printHeader(buffer); // nome_canal[14] = "ALTERAR POTENCIA DOS LEDS AZUL ROYAL"
    }
    else if (cor_selecionada == 3)
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(nome_canal[15])));
      printHeader(buffer); // nome_canal[15] = "ALTERAR POTENCIA DOS LEDS VERMELHOS"
    }
    else if (cor_selecionada == 4)
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(nome_canal[16])));
      printHeader(buffer); // nome_canal[16] = "ALTERAR POTENCIA DOS LEDS VIOLETA"
    }

    setFont(SMALL, 0, 255, 255, 0,0,0);
    for (int i=0; i<12; i++) 
    {
      myGLCD.setColor(0, 255, 255);
      myGLCD.printNumI(((i*2)), (i*26)+13, 22);
      if(i == 11)
      {
        myGLCD.print("0", (i*26)+17, 33);
      }
      else
      {
        myGLCD.printNumI(((i*2)+2), (i*26)+13, 33);
      }

      myGLCD.setColor(100, 100, 100);
      myGLCD.drawRect((i*26)+4, 20 , (i*26)+30, 45);
    }

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[13])));
    printButton(buffer, salV[0], salV[1], salV[2], salV[3]); // "SALVAR"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[11])));
    printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3]); // "INICIO"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[1])));
    printButton(buffer, menU[0], menU[1], menU[2], menU[3]);  // "MENU 1";

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[66])));
    printButton(buffer, volT[0], volT[1], volT[2], volT[3]);  // tabela_textos[66] = "VOLTAR"

    setFont(SMALL, 255, 0, 0, 0, 0, 0);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[203])));
    myGLCD.print(buffer,50, 105);  // tabela_textos[203] = "SELECIONE UM PERIODO."

  }

  if(periodo_selecionado == true)
  {
    for (int i=0; i<8; i++)
    { 
      printButton("+", (i*38)+5, 50, (i*38)+39, 75, LARGE);
      printButton("-", (i*38)+5, 214, (i*38)+39, 239, LARGE);
    }
  }
  if((mensagem == true) && (periodo_selecionado == true))
  {
    mensagem = false;
    myGLCD.setColor(0, 0, 0);
    myGLCD.fillRect(45, 105, 300, 121); //Apaga mensagem.
  }
}

void tpaScreen(boolean refreshAll = false) //-------------------------------------------------------- tela =7
{
  if(refreshAll)
  {
    temp2hora = hora;
    temp2minuto = minuto;
    temp2duracaomaximatpa = duracaomaximatpa;
    temp2segunda = segunda;
    temp2terca = terca;
    temp2quarta = quarta;
    temp2quinta = quinta;
    temp2sexta = sexta;
    temp2sabado = sabado;
    temp2domingo = domingo;

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[32])));
    printHeader(buffer); // tabela_textos[32] = "CONF. DIAS E HORARIO PARA TPA AUTOMATICA"

    printButton("+", houU[0], houU[1], houU[2], houU[3], true); //hour up
    printButton("-", houD[0], houD[1], houD[2], houD[3], true); //hour down
    printButton("+", minUT[0], minUT[1], minUT[2], minUT[3], true); //min up
    printButton("-", minDT[0], minDT[1], minDT[2], minDT[3], true); //min down
    printButton("+", durC[0], durC[1], durC[2], durC[3], true); //min up
    printButton("-", durB[0], durB[1], durB[2], durB[3], true); //min down

    setFont(LARGE, 255, 255, 255, 0, 0, 0);
    myGLCD.print(":", 105, 48);
    myGLCD.setFont(RusFont1);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[83])));
    myGLCD.print(buffer, 10, 51); // "HORA:"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[84])));
    myGLCD.print(buffer, 157, 31); // "DURACAO MAXIMA"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[85])));
    myGLCD.print(buffer, 170, 46); // "POR ESTAGIO:"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[13])));
    printButton(buffer, prOK[0], prOK[1], prOK[2], prOK[3]); // "SALVAR"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[11])));
    printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3]); // "INICIO"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[1])));
    printButton(buffer, menU[0], menU[1], menU[2], menU[3]); // "MENU 1";
  }
  if (temp2segunda == 1)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[59])));
    printButton_verde(buffer, segU[0], segU[1], segU[2], segU[3]); //botao segunda
  }
  else
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[59])));
    printButton(buffer, segU[0], segU[1], segU[2], segU[3]); //botao segunda
  }
  if (temp2terca == 2)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[60])));
    printButton_verde(buffer, terC[0], terC[1], terC[2], terC[3]); //botao terca
  }
  else
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[60])));
    printButton(buffer, terC[0], terC[1], terC[2], terC[3]); //botao terca
  }
  if (temp2quarta == 3)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[61])));
    printButton_verde(buffer, quaR[0], quaR[1], quaR[2], quaR[3]); //botao quarta
  }
  else
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[61])));
    printButton(buffer, quaR[0], quaR[1], quaR[2], quaR[3]); //botao quarta
  }
  if (temp2quinta == 4)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[62])));
    printButton_verde(buffer, quiN[0], quiN[1], quiN[2], quiN[3]); //botao quinta
  }
  else
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[62])));
    printButton(buffer, quiN[0], quiN[1], quiN[2], quiN[3]); //botao quinta
  }
  if (temp2sexta == 5)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[63])));
    printButton_verde(buffer, sexT[0], sexT[1], sexT[2], sexT[3]); //botao sexta
  }
  else
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[63])));
    printButton(buffer, sexT[0], sexT[1], sexT[2], sexT[3]); //botao sexta
  }
  if (temp2sabado == 6)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[64])));
    printButton_verde(buffer, sabA[0], sabA[1], sabA[2], sabA[3]); //botao sabado
  }
  else
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[64])));
    printButton(buffer, sabA[0], sabA[1], sabA[2], sabA[3]); //botao sabado
  }
  if (temp2domingo == 7)
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
    printButton(buffer, proX[0], proX[1], proX[2], proX[3]); //Sinaliza que a TPA foi realizada normalmente ou nÃƒÂ£o foi realizada. // "NORMAL"
  }

  setFont(LARGE, 255, 255, 255, 0, 0, 0);
  if (temp2hora < 10)
  {
    myGLCD.printNumI(0, 70, 48);
    myGLCD.printNumI(temp2hora, 86, 48);
  }
  else
  {
    myGLCD.printNumI(temp2hora, 70, 48);
  }

  if (temp2minuto < 10)
  {
    myGLCD.printNumI(0, 120, 48);
    myGLCD.printNumI(temp2minuto, 136, 48);
  }
  else
  {
    myGLCD.printNumI(temp2minuto, 120, 48);
  }
  if (temp2duracaomaximatpa < 10)
  {
    myGLCD.printNumI(0, 275, 48);
    myGLCD.printNumI(temp2duracaomaximatpa, 291, 48);
  }
  else
  {
    myGLCD.printNumI(temp2duracaomaximatpa, 275, 48);
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
  printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3]); // "INICIO"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[1])));
  printButton(buffer, menU[0], menU[1], menU[2], menU[3]); // "MENU 1";
}

void graficoScreen()//------------------------------------------------------------tela =9
{

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[34])));
  printHeader(buffer); // tabela_textos[34] = "ESCOLHA UM GRAFICO"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[11])));
  printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3]); // "INICIO"

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

void waveScreen(boolean refreshAll = false)///------------------------------------------------------------------tela =10
{
  if(refreshAll == true)
  {
    Pump1PWM_temp = Pump1PWM;
    Pump2PWM_temp = Pump2PWM;

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[10])));
    printHeader(buffer); // tabela_textos[10] = "WAVEMAKER"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[11])));
    printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3]); // "HOME"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[1])));
    printButton(buffer, menU[0], menU[1], menU[2], menU[3]); // "MENU 1";

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[13])));
    printButton(buffer, prOK[0], prOK[1], prOK[2], prOK[3]); // "SAVE"

    myGLCD.setColor(0, 0, 0);
    myGLCD.fillRect(2, 20, 648, 478);

    if(modo_selecionado == 1)
    {
      printButton("-", peRB[0], peRB[1], peRB[2], peRB[3], true);
      printButton("+", peRC[0], peRC[1], peRC[2], peRC[3], true);
      printButton_verde("1", boT1[0], boT1[1], boT1[2], boT1[3],true);

      setFont(LARGE, 255, 255, 255, 0, 0, 0);

      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[238]))); // "PERIOD"
      myGLCD.print(buffer, 132, 250);

      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[239]))); // "ALTERNATING"
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

      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[238]))); // "PERIOD"
      myGLCD.print(buffer, 132, 250);

      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[240]))); // "SYNCRONIZED"
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

      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[241]))); // "DURATION OF INTERVAL IN MS"
      myGLCD.print(buffer, 30, 250);

      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[242]))); // "TIDAL SWELL"
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

      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[243]))); // "REEF CREST"
      myGLCD.print(buffer, 105, 150);

      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[241]))); // "DURATION/MILLISECONDS"

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

      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[246]))); // "MANUAL"
      myGLCD.print(buffer, 145, 150);

      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[244]))); // "PUMP 1"
      myGLCD.print(buffer, 138, 200);

      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[245]))); // "PUMP 2"
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
    myGLCD.drawRect(490, 454, 490, 194); // Linha y1
    myGLCD.drawRect(612, 454, 612, 194); // Linha y2

    for (int i=0; i < 10; i++)
    {
      myGLCD.drawLine(484, (i * 26) + 194, 496, (i * 26) + 194); // Marcador esequerdo
      myGLCD.drawLine(606, (i * 26) + 194, 618, (i * 26) + 194); // Marcador central
      myGLCD.drawPixel(552, (i * 26) + 194); // Marcador direito
    }
  }
  setFont(LARGE, 255, 255, 255, 0, 0, 0);

  if((modo_selecionado == 1) || (modo_selecionado == 2))
  {
    myGLCD.print(" ", 145, 300);
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
    } //change to current temp.
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
    printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3]); // "INICIO"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[66])));
    printButton(buffer, menU[0], menU[1], menU[2], menU[3]); // "BACK"
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

    printButton("-", temM[0], temM[1], temM[2], temM[3], true); //temp minus
    printButton("+", temP[0], temP[1], temP[2], temP[3], true); //temp plus
    printButton("-", offM[0], offM[1], offM[2], offM[3], true); //offset minus
    printButton("+", offP[0], offP[1], offP[2], offP[3], true); //offset plus
    printButton("-", almM[0], almM[1], almM[2], almM[3], true); //alarm minus
    printButton("+", almP[0], almP[1], almP[2], almP[3], true); //alarm plus


    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[13])));
    printButton(buffer, prOK[0], prOK[1], prOK[2], prOK[3]); // "SALVAR"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[11])));
    printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3]); // "INICIO"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[66])));
    printButton(buffer, menU[0], menU[1], menU[2], menU[3]); // "BACK"
  }

  myGLCD.setColor(0, 0, 0);
  myGLCD.fillRoundRect (300, 180, 406, 214);
  myGLCD.fillRoundRect (300, 280, 406, 314);

  setFont(LARGE, 255, 255, 255, 0, 0, 0);
  myGLCD.printNumI(ORP2beS, 300, 80);
  myGLCD.printNumI(ORP2beO, 300, 180);
  myGLCD.printNumI(ORP2beA, 300, 280);
}
//---------------------------------------------PH do aquario--------------------------------tela =18 ----------

void config_phA_Screen(boolean refreshAll=false)
{

  if (refreshAll)
  {
    if (setPHA==0) {
      setPHA = PHA;
    } //change to current temp.
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

    printButton("-", temM[0], temM[1], temM[2], temM[3], true); //temp minus
    printButton("+", temP[0], temP[1], temP[2], temP[3], true); //temp plus
    printButton("-", offM[0], offM[1], offM[2], offM[3], true); //offset minus
    printButton("+", offP[0], offP[1], offP[2], offP[3], true); //offset plus
    printButton("-", almM[0], almM[1], almM[2], almM[3], true); //alarm minus
    printButton("+", almP[0], almP[1], almP[2], almP[3], true); //alarm plus

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[13])));
    printButton(buffer, prOK[0], prOK[1], prOK[2], prOK[3]); // "SALVAR"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[11])));
    printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3]); // "INICIO"

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

    printButton("-", temM[0], temM[1], temM[2], temM[3], true); //temp minus
    printButton("+", temP[0], temP[1], temP[2], temP[3], true); //temp plus
    printButton("-", offM[0], offM[1], offM[2], offM[3], true); //offset minus
    printButton("+", offP[0], offP[1], offP[2], offP[3], true); //offset plus
    printButton("-", almM[0], almM[1], almM[2], almM[3], true); //alarm minus
    printButton("+", almP[0], almP[1], almP[2], almP[3], true); //alarm plus

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[13])));
    printButton(buffer, prOK[0], prOK[1], prOK[2], prOK[3]); // "SALVAR"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[11])));
    printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3]); // "INICIO"

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
  printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3]); // "INICIO"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[1])));
  printButton(buffer, menU[0], menU[1], menU[2], menU[3]); // "MENU 1";

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[66])));
  printButton(buffer, volT[0], volT[1], volT[2], volT[3]); // "VOLTAR"
}
//--------------------------- teste manual dos leds ----------------------------------------------------- tela =22
void teste_individual_leds()
{
  bled_out_temp = bled_out;
  wled_out_temp = wled_out;
  rbled_out_temp = rbled_out;
  rled_out_temp = rled_out;
  uvled_out_temp = uvled_out;

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[16])));
  printHeader(buffer); // tabela_textos[16] "TESTAR VARIACAO DE LUMINOSIDADE"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[11])));
  printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3]);  // "INICIO"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[1])));
  printButton(buffer, menU[0], menU[1], menU[2], menU[3]); // "MENU 1";

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[66])));
  printButton(buffer, volT[0], volT[1], volT[2], volT[3]);  // "VOLTAR"

  printButton("+", 49, 18, 93, 41, true);    // "+"
  printButton("+", 101, 18, 145, 41, true);  // "+"
  printButton("+", 153, 18, 197, 41, true);  // "+"
  printButton("+", 205, 18, 249, 41, true);  // "+"
  printButton("+", 257, 18, 301, 41, true);  // "+"

  printButton("-", 49, 201, 93, 224, true);    // "-"
  printButton("-", 101, 201, 145, 224, true);  // "-"
  printButton("-", 153, 201, 197, 224, true);  // "-"
  printButton("-", 205, 201, 249, 224, true);  // "-"
  printButton("-", 257, 201, 301, 224, true);  // "-"

  myGLCD.setFont(RusFont1);
  myGLCD.setBackColor(0,0,0);

  myGLCD.setColor(cor_canal1[0], cor_canal1[1],cor_canal1[2]); 
  myGLCD.drawRect(49, 44, 93, 172);   // % bar place holder 

  strcpy_P(buffer, (char*)pgm_read_word_near(&(nome_canal[1])));
  myGLCD.print(buffer, 61, 176);   //  Branco

  myGLCD.printNumI(wled_out_temp, 61, 186);

  myGLCD.setColor(cor_canal2[0], cor_canal2[1],cor_canal2[2]); 
  myGLCD.drawRect(101, 44, 145, 172);  // % bar place holder

  strcpy_P(buffer, (char*)pgm_read_word_near(&(nome_canal[2])));
  myGLCD.print(buffer, 113, 176);    // Azul

  myGLCD.printNumI(bled_out_temp, 113, 186);

  myGLCD.setColor(cor_canal3[0], cor_canal3[1],cor_canal3[2]); 
  myGLCD.drawRect(153, 44, 197, 172); //  % bar place holder 

  strcpy_P(buffer, (char*)pgm_read_word_near(&(nome_canal[3])));
  myGLCD.print(buffer, 165, 176);   // Azul Royal

  myGLCD.printNumI(rbled_out_temp, 165, 186);

  myGLCD.setColor(cor_canal4[0], cor_canal4[1],cor_canal4[2]); 
  myGLCD.drawRect(205, 44, 249, 172); // % bar place holder;

  strcpy_P(buffer, (char*)pgm_read_word_near(&(nome_canal[4])));
  myGLCD.print(buffer, 217, 176);   // Vermelho

  myGLCD.printNumI(rled_out_temp, 217, 186);

  myGLCD.setColor(cor_canal5[0], cor_canal5[1],cor_canal5[2]);  
  myGLCD.drawRect(257, 44, 301, 172); // % bar place holder

  strcpy_P(buffer, (char*)pgm_read_word_near(&(nome_canal[5])));
  myGLCD.print(buffer, 269, 176);   // Violeta  

  myGLCD.printNumI(uvled_out_temp, 269, 186);   

  setFont(SMALL, 255, 255, 255, 0, 0, 0); 
  myGLCD.drawRect(30, 173, 315, 173);     // Eixo x
  myGLCD.drawRect(30, 173, 30, 44);       // eixo y  

  myGLCD.setColor(190, 190, 190);
  for (int i=0; i<10; i++){               // Escala % 
    myGLCD.drawLine(31, (i*13)+44, 38, (i*13)+44); 
  } 
  for (int i=0; i<10; i++){              
    myGLCD.drawLine(31, (i*13)+51, 34, (i*13)+51); 
  } 

  myGLCD.setFont(RusFont1);
  myGLCD.print("%", 20, 25);     // %
  myGLCD.print("100", 5, 41);   // 100
  myGLCD.print("90", 12, 54);   // 90
  myGLCD.print("80", 12, 67);   // 80
  myGLCD.print("70", 12, 80);   // 70
  myGLCD.print("60", 12, 93);   // 60
  myGLCD.print("50", 12, 106);  // 50
  myGLCD.print("40", 12, 119);  // 40
  myGLCD.print("30", 12, 132);  // 30
  myGLCD.print("20", 12, 145);  // 20
  myGLCD.print("10", 12, 158);  // 10
  myGLCD.print("0", 20, 171);   // 0

  myGLCD.setColor(180, 180, 180);                  
  for (int i=0; i<10; i++){                      // escalas de linhas pontilhadas horizontais 
    for(int k=46; k<311; k++){ 
      myGLCD.drawPixel(k,(i*13)+44); 
      k=k+2;
    } 
  } 

  //void desenhar_barras(int sbR, int sbG, int sbB, int sbX1, int sbY1, int sbX2, int sbY2)

  y_tocado = map(wled_out_temp, 255, 0, 44, 172);
  desenhar_barras(cor_canal1[0], cor_canal1[1],cor_canal1[2], 49, 44, 93, 172);

  y_tocado = map(bled_out_temp, 255, 0, 44, 172);
  desenhar_barras(cor_canal2[0], cor_canal2[1],cor_canal2[2], 101, 44, 145, 172);

  y_tocado = map(rbled_out_temp, 255, 0, 44, 172);
  desenhar_barras(cor_canal3[0], cor_canal3[1],cor_canal3[2], 153, 44, 197, 172);

  y_tocado = map(rled_out_temp, 255, 0, 44, 172);
  desenhar_barras(cor_canal4[0], cor_canal4[1],cor_canal4[2], 205, 44, 249, 172);

  y_tocado = map(uvled_out_temp, 255, 0, 44, 172);
  desenhar_barras(cor_canal5[0], cor_canal5[1],cor_canal5[2], 257, 44, 301, 172);                                                             
}
void rever_dosagem_personalizada_2() // ------------------------------------------------------------------ tela =23
{
  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[50])));
  printHeader(buffer); // tabela_textos[50] = "REVER CONF. DA DOSAGEM PERSONALIZADA"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[11])));
  printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3]); // "INICIO"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[1])));
  printButton(buffer, menU[0], menU[1], menU[2], menU[3]); // "MENU 1";

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[66])));
  printButton(buffer, volT[0], volT[1], volT[2], volT[3]); // "VOLTAR"

  myGLCD.setColor(161, 127, 73);
  myGLCD.drawLine(1, 176, 638, 176);
  myGLCD.drawLine(1, 316, 638, 316);
  myGLCD.drawLine(638, 30, 638, 478);

  setFont(LARGE, 255, 255, 255, 0, 0, 0);

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[211])));
  myGLCD.print(buffer, 20, 60); // tabela_textos[129]

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[118])));
  myGLCD.print(buffer, 20, 100);

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[119])));
  myGLCD.print(buffer, 236, 100);

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[128])));
  myGLCD.print(buffer, 20, 140);

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[121])));
  myGLCD.print(buffer, 430, 100); //PosiÃƒÂ§ÃƒÂ£o correta

  myGLCD.print(":", 180, 100);
  myGLCD.print(":", 360, 100);

  myGLCD.printNumF(dose_dosadora_4_personalizada, 1, 550, 100); //PosiÃƒÂ§ÃƒÂ£o correta
  myGLCD.printNumI(quantidade_dose_dosadora_4_personalizada, 340, 140);

  if(hora_inicial_dosagem_personalizada_4 < 10)
  {
    myGLCD.printNumI(0, 144, 100);
    myGLCD.printNumI(hora_inicial_dosagem_personalizada_4, 160, 100);
  }
  else
  {
    myGLCD.printNumI(hora_inicial_dosagem_personalizada_4, 72, 50);
  }
  if(minuto_inicial_dosagem_personalizada_4 < 10)
  {
    myGLCD.printNumI(0, 98, 50);
    myGLCD.printNumI(minuto_inicial_dosagem_personalizada_4, 106, 50);
  }
  else
  {
    myGLCD.printNumI(minuto_inicial_dosagem_personalizada_4, 98, 50);
  }
  if(hora_final_dosagem_personalizada_4 < 10)
  {
    myGLCD.printNumI(0, 165, 50);
    myGLCD.printNumI(hora_final_dosagem_personalizada_4, 173, 50);
  }
  else
  {
    myGLCD.printNumI(hora_final_dosagem_personalizada_4, 165, 50);
  }
  if(minuto_final_dosagem_personalizada_4 < 10)
  {
    myGLCD.printNumI(0, 188, 50);
    myGLCD.printNumI(minuto_final_dosagem_personalizada_4, 196, 50);
  }
  else
  {
    myGLCD.printNumI(minuto_final_dosagem_personalizada_4, 188, 50);
  }
  if(segunda_dosagem_personalizada_4 == 1)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[70])));
    printButton_verde(buffer, 110, 23, 130, 43);
  }
  else
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[70])));
    printButton(buffer, 110, 23, 130, 43);
  }
  if(terca_dosagem_personalizada_4 == 2)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[71])));
    printButton_verde(buffer, 140, 23, 160, 43);
  }
  else
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[71])));
    printButton(buffer, 140, 23, 160, 43);
  }
  if(quarta_dosagem_personalizada_4 == 3)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[72])));
    printButton_verde(buffer, 170, 23, 190, 43);
  }
  else
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[72])));
    printButton(buffer, 170, 23, 190, 43);
  }
  if(quinta_dosagem_personalizada_4 == 4)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[198])));
    printButton_verde(buffer, 200, 23, 220, 43);
  }
  else
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[198])));
    printButton(buffer, 200, 23, 220, 43);
  }
  if(sexta_dosagem_personalizada_4 == 5)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[199])));
    printButton_verde(buffer, 230, 23, 250, 43);
  }
  else
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[199])));
    printButton(buffer, 230, 23, 250, 43);
  }
  if(sabado_dosagem_personalizada_4 == 6)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[200])));
    printButton_verde(buffer, 260, 23, 280, 43);
  }
  else
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[200])));
    printButton(buffer, 260, 23, 280, 43);
  }
  if(domingo_dosagem_personalizada_4 == 7)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[73])));
    printButton_verde(buffer, 290, 23, 310, 43);
  }
  else
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[73])));
    printButton(buffer, 290, 23, 310, 43);
  }
  if (modo_personalizado_on_4 == true)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[126])));
    printButton_verde(buffer, 200, 65, 245, 85);
  }
  else
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[126])));
    printButton(buffer, 200, 65, 245, 85);
  }
  if (modo_personalizado_on_4 == false)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[127])));
    printButton_verde(buffer, 250, 65, 295, 85);
  }
  else
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[127])));
    printButton(buffer, 250, 65, 295, 85);
  }
  setFont(SMALL, 255, 255, 255, 0, 0, 0);

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[212])));
  myGLCD.print(buffer, 10, 100);

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[118])));
  myGLCD.print(buffer, 10, 120);

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[119])));
  myGLCD.print(buffer, 118, 120);

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[128])));
  myGLCD.print(buffer, 10, 140);

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[121])));
  myGLCD.print(buffer, 215, 120);

  myGLCD.print(":", 90, 120);
  myGLCD.print(":", 180, 120);

  myGLCD.printNumF(dose_dosadora_5_personalizada, 1, 275, 120);
  myGLCD.printNumI(quantidade_dose_dosadora_5_personalizada, 170, 140);

  if(hora_inicial_dosagem_personalizada_5 < 10)
  {
    myGLCD.printNumI(0, 72, 120);
    myGLCD.printNumI(hora_inicial_dosagem_personalizada_5, 80, 120);
  }
  else
  {
    myGLCD.printNumI(hora_inicial_dosagem_personalizada_5, 72, 120);
  }
  if(minuto_inicial_dosagem_personalizada_5 < 10)
  {
    myGLCD.printNumI(0, 98, 120);
    myGLCD.printNumI(minuto_inicial_dosagem_personalizada_5, 106, 120);
  }
  else
  {
    myGLCD.printNumI(minuto_inicial_dosagem_personalizada_5, 98, 120);
  }
  if(hora_final_dosagem_personalizada_5 < 10)
  {
    myGLCD.printNumI(0, 165, 120);
    myGLCD.printNumI(hora_final_dosagem_personalizada_5, 173, 120);
  }
  else
  {
    myGLCD.printNumI(hora_final_dosagem_personalizada_5, 165, 120);
  }
  if(minuto_final_dosagem_personalizada_5 < 10)
  {
    myGLCD.printNumI(0, 188, 120);
    myGLCD.printNumI(minuto_final_dosagem_personalizada_5, 196, 120);
  }
  else
  {
    myGLCD.printNumI(minuto_final_dosagem_personalizada_5, 188, 120);
  }
  if(segunda_dosagem_personalizada_5 == 1)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[70])));
    printButton_verde(buffer, 110, 93, 130, 113);
  }
  else
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[70])));
    printButton(buffer, 110, 93, 130, 113);
  }
  if(terca_dosagem_personalizada_5 == 2)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[71])));
    printButton_verde(buffer, 140, 93, 160, 113);
  }
  else
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[71])));
    printButton(buffer, 140, 93, 160, 113);
  }
  if(quarta_dosagem_personalizada_5 == 3)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[72])));
    printButton_verde(buffer, 170, 93, 190, 113);
  }
  else
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[72])));
    printButton(buffer, 170, 93, 190, 113);
  }
  if(quinta_dosagem_personalizada_5 == 4)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[198])));
    printButton_verde(buffer, 200, 93, 220, 113);
  }
  else
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[198])));
    printButton(buffer, 200, 93, 220, 113);
  }
  if(sexta_dosagem_personalizada_5 == 5)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[199])));
    printButton_verde(buffer, 230, 93, 250, 113);
  }
  else
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[199])));
    printButton(buffer, 230, 93, 250, 113);
  }
  if(sabado_dosagem_personalizada_5 == 6)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[200])));
    printButton_verde(buffer, 260, 93, 280, 113);
  }
  else
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[200])));
    printButton(buffer, 260, 93, 280, 113);
  }
  if(domingo_dosagem_personalizada_5 == 7)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[73])));
    printButton_verde(buffer, 290, 93, 310, 113);
  }
  else
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[73])));
    printButton(buffer, 290, 93, 310, 113);
  }
  if (modo_personalizado_on_5 == true)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[126])));
    printButton_verde(buffer, 200, 135, 245, 155);
  }
  else
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[126])));
    printButton(buffer, 200, 135, 245, 155);
  }
  if (modo_personalizado_on_5 == false)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[127])));
    printButton_verde(buffer, 250, 135, 295, 155);
  }
  else
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[127])));
    printButton(buffer, 250, 135, 295, 155);
  }
  setFont(SMALL, 255, 255, 255, 0, 0, 0);

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[213])));
  myGLCD.print(buffer, 10, 170);

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[118])));
  myGLCD.print(buffer, 10, 190);

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[119])));
  myGLCD.print(buffer, 118, 190);

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[128])));
  myGLCD.print(buffer, 10, 210); // tabela_textos[128] = "QUANTIDADE DE DOSES:"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[121])));
  myGLCD.print(buffer, 215, 190);

  myGLCD.print(":", 90, 190);
  myGLCD.print(":", 180, 190);

  myGLCD.printNumF(dose_dosadora_6_personalizada, 1, 275, 190);
  myGLCD.printNumI(quantidade_dose_dosadora_6_personalizada, 170, 210);

  if(hora_inicial_dosagem_personalizada_6 < 10)
  {
    myGLCD.printNumI(0, 72, 190);
    myGLCD.printNumI(hora_inicial_dosagem_personalizada_6, 80, 190);
  }
  else
  {
    myGLCD.printNumI(hora_inicial_dosagem_personalizada_6, 72, 190);
  }
  if(minuto_inicial_dosagem_personalizada_6 < 10)
  {
    myGLCD.printNumI(0, 98, 190);
    myGLCD.printNumI(minuto_inicial_dosagem_personalizada_6, 106, 190);
  }
  else
  {
    myGLCD.printNumI(minuto_inicial_dosagem_personalizada_6, 98, 190);
  }
  if(hora_final_dosagem_personalizada_6 < 10)
  {
    myGLCD.printNumI(0, 165, 190);
    myGLCD.printNumI(hora_final_dosagem_personalizada_6, 173, 190);
  }
  else
  {
    myGLCD.printNumI(hora_final_dosagem_personalizada_6, 165, 190);
  }
  if(minuto_final_dosagem_personalizada_6 < 10)
  {
    myGLCD.printNumI(0, 188, 190);
    myGLCD.printNumI(minuto_final_dosagem_personalizada_6, 196, 190);
  }
  else
  {
    myGLCD.printNumI(minuto_final_dosagem_personalizada_6, 188, 190);
  }
  if(segunda_dosagem_personalizada_6 == 1)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[70])));
    printButton_verde(buffer, 110, 163, 130, 183);
  }
  else
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[70])));
    printButton(buffer, 110, 163, 130, 183);
  }
  if(terca_dosagem_personalizada_6 == 2)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[71])));
    printButton_verde(buffer, 140, 163, 160, 183);
  }
  else
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[71])));
    printButton(buffer, 140, 163, 160, 183);
  }
  if(quarta_dosagem_personalizada_6 == 3)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[72])));
    printButton_verde(buffer, 170, 163, 190, 183);
  }
  else
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[72])));
    printButton(buffer, 170, 163, 190, 183);
  }
  if(quinta_dosagem_personalizada_6 == 4)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[198])));
    printButton_verde(buffer, 200, 163, 220, 183);
  }
  else
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[198])));
    printButton(buffer, 200, 163, 220, 183);
  }
  if(sexta_dosagem_personalizada_6 == 5)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[199])));
    printButton_verde(buffer, 230, 163, 250, 183);
  }
  else
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[199])));
    printButton(buffer, 230, 163, 250, 183);
  }
  if(sabado_dosagem_personalizada_6 == 6)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[200])));
    printButton_verde(buffer, 260, 163, 280, 183);
  }
  else
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[200])));
    printButton(buffer, 260, 163, 280, 183);
  }
  if(domingo_dosagem_personalizada_6 == 7)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[73])));
    printButton_verde(buffer, 290, 163, 310, 183);
  }
  else
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[73])));
    printButton(buffer, 290, 163, 310, 183);
  }
  if (modo_personalizado_on_6 == true)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[126])));
    printButton_verde(buffer, 200, 205, 245, 225);
  }
  else
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[126])));
    printButton(buffer, 200, 205, 245, 225);
  }
  if (modo_personalizado_on_6 == false)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[127])));
    printButton_verde(buffer, 250, 205, 295, 225);
  }
  else
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[127])));
    printButton(buffer, 250, 205, 295, 225);
  }
}
//---------------------------------------------Desativar dosadoras--------------------------------tela =24
void desativar_dosadoras_2(boolean refreshAll = false)
{
  if(refreshAll == true)
  {
    if (modo_personalizado_on_4 == true)
    {
      bitWrite(ativar_desativar,4,1);
    }
    else
    {
      bitWrite(ativar_desativar,4,0);
    }
    if (modo_personalizado_on_5 == true)
    {
      bitWrite(ativar_desativar,5,1);
    }
    else
    {
      bitWrite(ativar_desativar,5,0);
    }
    if (modo_personalizado_on_6 == true)
    {
      bitWrite(ativar_desativar,6,1);
    }
    else
    {
      bitWrite(ativar_desativar,6,0);
    }
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[51])));
    printHeader(buffer); // tabela_textos[51] = "DESATIVAR DOSADORAS"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[11])));
    printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3]); // "INICIO"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[1])));
    printButton(buffer, menU[0], menU[1], menU[2], menU[3]); // "MENU 1";

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[13])));
    printButton(buffer, salV[0], salV[1], salV[2], salV[3]); // "SALVAR"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[66])));
    printButton(buffer, volT[0], volT[1], volT[2], volT[3]);

    setFont(SMALL, 255, 255, 255, 0, 0, 0);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[211])));
    myGLCD.print(buffer, 120, 30);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[212])));
    myGLCD.print(buffer, 120, 100);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[213])));
    myGLCD.print(buffer, 120, 170);

    setFont(SMALL, 255, 0, 0, 0, 0, 0);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[141])));
    myGLCD.print(buffer, 230, 60); //tabela_textos[141] = "USE ESTA"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[142])));
    myGLCD.print(buffer, 230, 75); //tabela_textos[141] = "FUNCAO"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[143])));
    myGLCD.print(buffer, 230, 90); // tabela_textos[143] = "APENAS PARA"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[144])));
    myGLCD.print(buffer, 230, 105); //tabela_textos[144] = "DESATIVAR"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[145])));
    myGLCD.print(buffer, 230, 120); // tabela_textos[145] = "OS MODOS"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[146])));
    myGLCD.print(buffer, 230, 135); // tabela_textos[146] = "DE DOSAGEM."
  }
  if (bitRead(ativar_desativar,4) == true)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[147])));
    printButton_verde(buffer, 100, 45, 220, 85); // tabela_textos[147]

    myGLCD.setColor(0, 0, 0);
    myGLCD.fillRect (3, 26, 114, 43);
    myGLCD.fillRect (3, 45, 95, 61);
    myGLCD.fillRect (3, 60, 95, 76);
    myGLCD.fillRect (3, 75, 95, 91);

    setFont(SMALL, 255, 255, 255, 0, 0, 0);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[149])));
    myGLCD.print(buffer, 10, 30); // tabela_textos[149] = "UM DOS MODOS"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[150])));
    myGLCD.print(buffer, 10, 45); // tabela_textos[150] = "DE DOSAGEM "

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[151])));
    myGLCD.print(buffer, 10, 60); // tabela_textos[151] = "ESTA:"
  }
  else
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[152])));
    printButton(buffer, 100, 45, 220, 85);

    setFont(SMALL, 255, 255, 0, 0, 0, 0);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[153])));
    myGLCD.print(buffer, 3, 30);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[150])));
    myGLCD.print(buffer, 3, 45);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[154])));
    myGLCD.print(buffer, 3, 60);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[155])));
    myGLCD.print(buffer, 3, 75);
  }
  if (bitRead(ativar_desativar,5) == true)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[147])));
    printButton_verde(buffer, 100, 115, 220, 155);

    myGLCD.setColor(0, 0, 0);
    myGLCD.fillRect (3, 96, 117, 113);
    myGLCD.fillRect (3, 115, 95, 131);
    myGLCD.fillRect (3, 130, 95, 146);
    myGLCD.fillRect (3, 145, 95, 161);

    setFont(SMALL, 255, 255, 255, 0, 0, 0);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[149])));
    myGLCD.print(buffer, 10, 100); // tabela_textos[149] = "UM DOS MODOS"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[150])));
    myGLCD.print(buffer, 10, 115); // tabela_textos[150] = "DE DOSAGEM "

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[151])));
    myGLCD.print(buffer, 10, 130); // tabela_textos[151] = "ESTA:"
  }
  else
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[152])));
    printButton(buffer, 100, 115, 220, 155); // tabela_textos[152]

    setFont(SMALL, 255, 255, 0, 0, 0, 0);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[153])));
    myGLCD.print(buffer, 3, 100); // tabela_textos[153] = "AMBOS OS MODOS"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[150])));
    myGLCD.print(buffer, 3, 115); //tabela_textos[150] = "DE DOSAGEM "

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[154])));
    myGLCD.print(buffer, 3, 130); // tabela_textos[154] = "ESTAO OU"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[155])));
    myGLCD.print(buffer, 3, 145); // tabela_textos[155] = "SERAO:"
  }
  if (bitRead(ativar_desativar,6) == true)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[147])));
    printButton_verde(buffer, 100, 185, 220, 225);

    myGLCD.setColor(0, 0, 0);
    myGLCD.fillRect (3, 166, 117, 183);
    myGLCD.fillRect (3, 185, 95, 201);
    myGLCD.fillRect (3, 200, 95, 216);
    myGLCD.fillRect (3, 215, 95, 231);

    setFont(SMALL, 255, 255, 255, 0, 0, 0);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[149])));
    myGLCD.print(buffer, 10, 170);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[150])));
    myGLCD.print(buffer, 10, 185);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[151])));
    myGLCD.print(buffer, 10, 200);
  }
  else
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[152])));
    printButton(buffer, 100, 185, 220, 225);

    setFont(SMALL, 255, 255, 0, 0, 0, 0);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[153])));
    myGLCD.print(buffer, 3, 170);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[150])));
    myGLCD.print(buffer, 3, 185);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[154])));
    myGLCD.print(buffer, 3, 200);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[155])));
    myGLCD.print(buffer, 3, 215);
  }
}
//---------------------------------------- OpÃƒÂ§ÃƒÂµes de teste dos leds ---------------------- tela =25
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
    myGLCD.drawRect(20, 50, 310, 125);
    setFont(SMALL, 255, 255, 255, 0, 0, 0);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[105])));
    myGLCD.print(buffer, 30, 55); // "COLOQUE O RECIPIENTE SOB O BICO"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[106])));
    myGLCD.print(buffer, 30, 70); // "DOSADOR E CLIQUE EM INICIAR."

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[107])));
    myGLCD.print(buffer, 30, 85); // "EM SEGUIDA INSIRA O VALOR OBTIDO"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[108])));
    myGLCD.print(buffer, 30, 100); // "EM ML NO CAMPO ABAIXO."

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[109])));
    myGLCD.print(buffer, 5, 165); // "PARA MELHORES RESULTADOS REPITA O TESTE"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[110])));
    myGLCD.print(buffer, 35, 177); // "ALGUMAS VEZES E USE UMA MEDIA."
  }
  myGLCD.setColor(0, 0, 0);
  myGLCD.fillRect(117, 135, 203, 160);

  if(modo_calibrar == true)
  {
    setFont(LARGE, 255, 255, 255, 0, 0, 0);
    myGLCD.printNumF(fator_calib_dosadora[dosadora_selecionada],1, 130, 140);

    setFont(SMALL, 255, 255, 255, 0, 0, 0);
    if(dosadora_selecionada == 0)
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[111])));
      myGLCD.print(buffer, 80, 30); // tabela_textos[111] = "DOSADORA 1 SELECIONADA"
    }
    if(dosadora_selecionada == 1)
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[112])));
      myGLCD.print(buffer, 80, 30); // tabela_textos[112] = "DOSADORA 2 SELECIONADA"
    }
    if(dosadora_selecionada == 2)
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[113])));
      myGLCD.print(buffer, 80, 30); // tabela_textos[113] = "DOSADORA 3 SELECIONADA"
    }
    if(dosadora_selecionada == 3)
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[207])));
      myGLCD.print(buffer, 80, 30); // tabela_textos[207] = "DOSADORA 4 SELECIONADA"
    }
    if(dosadora_selecionada == 4)
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[208])));
      myGLCD.print(buffer, 80, 30); // tabela_textos[208] = "DOSADORA 5 SELECIONADA"
    }
    if(dosadora_selecionada == 5)
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[209])));
      myGLCD.print(buffer, 80, 30); // tabela_textos[209] = "DOSADORA 6 SELECIONADA"
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
    myGLCD.drawRect(20, 50, 310, 125);

    setFont(SMALL, 255, 255, 255, 0, 0, 0);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[114])));
    myGLCD.print(buffer, 30, 55); // "SELECIONE O VOLUME A SER DOSADO"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[115])));
    myGLCD.print(buffer, 30, 70); // "EM ML NO CAMPO ABAIXO E"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[116])));
    myGLCD.print(buffer, 30, 85); // "EM SEGUIDA TOQUE EM INICIAR."

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[117])));
    myGLCD.print(buffer, 30, 100); // "A DOSAGEM INICIARA EM 10 SEGUNDOS"
  }
  myGLCD.setColor(0, 0, 0);
  myGLCD.fillRect(117, 135, 203, 160);

  if(modo_manual == true)
  {
    setFont(LARGE, 255, 255, 255, 0, 0, 0);
    myGLCD.printNumF(dose_dosadora_manual[dosadora_selecionada],1, 130, 140);

    setFont(SMALL, 255, 255, 255, 0, 0, 0);

    if(dosadora_selecionada == 0)
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[111])));
      myGLCD.print(buffer, 80, 30); // tabela_textos[111] = "DOSADORA 1 SELECIONADA"
    }
    if(dosadora_selecionada == 1)
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[112])));
      myGLCD.print(buffer, 80, 30); // tabela_textos[112] = "DOSADORA 2 SELECIONADA"
    }
    if(dosadora_selecionada == 2)
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[113])));
      myGLCD.print(buffer, 80, 30); // tabela_textos[113] = "DOSADORA 3 SELECIONADA"
    }
    if(dosadora_selecionada == 3)
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[207])));
      myGLCD.print(buffer, 80, 30); // tabela_textos[207] = "DOSADORA 4 SELECIONADA"
    }
    if(dosadora_selecionada == 4)
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[208])));
      myGLCD.print(buffer, 80, 30); // tabela_textos[208] = "DOSADORA 5 SELECIONADA"
    }
    if(dosadora_selecionada == 5)
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[209])));
      myGLCD.print(buffer, 80, 30); // tabela_textos[209] = "DOSADORA 6 SELECIONADA"
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
    printButton("+", houU[0]+155, houU[1], houU[2]+155, houU[3], true); //hora mais
    printButton("-", houD[0]+155, houD[1], houD[2]+155, houD[3], true); //hora menos
    printButton("+", minUT[0]+155, minUT[1], minUT[2]+155, minUT[3], true); //minuto mais
    printButton("-", minDT[0]+155, minDT[1], minDT[2]+155, minDT[3], true); //minuto menos

    setFont(LARGE, 255, 255, 255, 0, 0, 0);
    myGLCD.print(":", 105, 48);
    myGLCD.print(":", 105 + 155, 48);
    myGLCD.setFont(RusFont1);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[118])));
    myGLCD.print(buffer, 5, 51);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[119])));
    myGLCD.print(buffer, 172, 51);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[135])));
    printButton(buffer, proX[0], proX[1], proX[2], proX[3]); // "PROXIMO"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[11])));
    printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3]); // "INICIO"

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
    myGLCD.printNumI(0, 70, 48);
    myGLCD.printNumI(hora_inicial_dosagem_personalizada[dosadora_selecionada], 86, 48);
  }
  else
  {
    myGLCD.printNumI(hora_inicial_dosagem_personalizada[dosadora_selecionada], 70, 48);
  }

  if (minuto_inicial_dosagem_personalizada[dosadora_selecionada] < 10)
  {
    myGLCD.printNumI(0, 120, 48);
    myGLCD.printNumI(minuto_inicial_dosagem_personalizada[dosadora_selecionada], 136, 48);
  }
  else
  {
    myGLCD.printNumI(minuto_inicial_dosagem_personalizada[dosadora_selecionada], 120, 48);
  }
  if (hora_final_dosagem_personalizada[dosadora_selecionada] < 10)
  {
    myGLCD.printNumI(0, 70 + 155, 48);
    myGLCD.printNumI(hora_final_dosagem_personalizada[dosadora_selecionada], 86 + 155, 48);
  }
  else
  {
    myGLCD.printNumI(hora_final_dosagem_personalizada[dosadora_selecionada], 70 + 155, 48);
  }

  if (minuto_final_dosagem_personalizada[dosadora_selecionada] < 10)
  {
    myGLCD.printNumI(0, 120 + 155, 48);
    myGLCD.printNumI(minuto_final_dosagem_personalizada[dosadora_selecionada], 136 + 155, 48);
  }
  else
  {
    myGLCD.printNumI(minuto_final_dosagem_personalizada[dosadora_selecionada], 120 + 155, 48);
  }

  setFont(SMALL, 255, 255, 255, 0, 0, 0);

  if(dosadora_selecionada == 0)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[102])));
    myGLCD.print(buffer, 10, 198); // "DOSADORA 1"; // tabela_textos[102]
  }
  else if(dosadora_selecionada == 1)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[103])));
    myGLCD.print(buffer, 10, 198); // "DOSADORA 2"; // tabela_textos[103]
  }
  else if(dosadora_selecionada == 2)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[104])));
    myGLCD.print(buffer, 10, 198); // "DOSADORA 3"; // tabela_textos[104]
  }
  else if(dosadora_selecionada == 3)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[204])));
    myGLCD.print(buffer, 10, 198); // "DOSADORA 4"; // tabela_textos[204]
  }
  else if(dosadora_selecionada == 4)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[205])));
    myGLCD.print(buffer, 10, 198); // "DOSADORA 5"; // tabela_textos[205]
  }
  else if(dosadora_selecionada == 5)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[206])));
    myGLCD.print(buffer, 10, 198); // "DOSADORA 6"; // tabela_textos[206]
  }
  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[125])));
  myGLCD.print(buffer, 10, 218); // "SELECIONADA"; // tabela_textos[125]

}

void solicitar_senha() //---------------tela =30
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
  printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3]); // tabela_textos[11] = "INICIO"

}

void config_dosagem_personalizada_2(boolean refreshAll=false) // ----------tela =31
{
  if(refreshAll)
  {
    config_valores_dosadoras_temp2();
    
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[47])));
    printHeader(buffer); // tabela_textos[47] = "CONFIGURAR DOSAGEM PERSONALIZADA"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[11])));
    printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3]); // "INICIO"

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
    myGLCD.setFont(RusFont1);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[120])));
    myGLCD.print(buffer, 10, 31); // "SELECIONE O"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[121])));
    myGLCD.print(buffer, 10, 55); // "VOLUME "

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[122])));
    myGLCD.print(buffer, 10, 75); // "(ML/DIA):"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[123])));
    myGLCD.print(buffer, 190, 46); // "QUANTIDADE"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[124])));
    myGLCD.print(buffer, 190, 61); // "DE DOSES:"
  }

  if (modo_personalizado == true)
  {
    setFont(LARGE, 255, 255, 255, 0, 0, 0);
    myGLCD.printNumF(dose_dosadora_personalizada[dosadora_selecionada], 1, 100, 48);
    if (quantidade_dose_dosadora_personalizada[dosadora_selecionada] < 10)
    {
      myGLCD.printNumI(0, 275, 48);
      myGLCD.printNumI(quantidade_dose_dosadora_personalizada[dosadora_selecionada], 291, 48);
    }
    else
    {
      myGLCD.printNumI(quantidade_dose_dosadora_personalizada[dosadora_selecionada], 275, 48);
    }
    setFont(SMALL, 255, 255, 255, 0, 0, 0);

    if(dosadora_selecionada == 0)
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[111])));
      myGLCD.print(buffer, 125, 213);
    }
    else if(dosadora_selecionada == 1)
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[112])));
      myGLCD.print(buffer, 125, 213);
    }
    else if(dosadora_selecionada == 2)
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[113])));
      myGLCD.print(buffer, 125, 213);
    }
    else if(dosadora_selecionada == 3)
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[207])));
      myGLCD.print(buffer, 125, 213);
    }
    else if(dosadora_selecionada == 4)
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[208])));
      myGLCD.print(buffer, 125, 213);
    }
    else if(dosadora_selecionada == 5)
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[209])));
      myGLCD.print(buffer, 125, 213);
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
  printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3]); // "INICIO"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[1])));
  printButton(buffer, menU[0], menU[1], menU[2], menU[3]); // "MENU 1";

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[66])));
  printButton(buffer, volT[0], volT[1], volT[2], volT[3]); // tabela_textos[66]
}
void rever_dosagem_personalizada() // ------------------------------------------------------------------tela =34
{
  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[50])));
  printHeader(buffer); // tabela_textos[50] = "REVER CONF. DA DOSAGEM PERSONALIZADA"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[11])));
  printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3]); // "INICIO"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[1])));
  printButton(buffer, menU[0], menU[1], menU[2], menU[3]); // "MENU 1";

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[210])));
  printButton(buffer, salV[0], salV[1], salV[2], salV[3]); // "MAIS"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[66])));
  printButton(buffer, volT[0], volT[1], volT[2], volT[3]); // "VOLTAR"

  myGLCD.setColor(161, 127, 73);
  myGLCD.drawLine(1, 88, 319, 88);
  myGLCD.drawLine(1, 158, 319, 158);
  myGLCD.drawLine(319, 15, 319, 239);

  setFont(SMALL, 255, 255, 255, 0, 0, 0);

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[129])));
  myGLCD.print(buffer, 10, 30); // tabela_textos[129]

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[118])));
  myGLCD.print(buffer, 10, 50);

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[119])));
  myGLCD.print(buffer, 118, 50);

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[128])));
  myGLCD.print(buffer, 10, 70);

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[121])));
  myGLCD.print(buffer, 215, 50); //PosiÃƒÂ§ÃƒÂ£o correta

  myGLCD.print(":", 90, 50);
  myGLCD.print(":", 180, 50);

  myGLCD.printNumF(dose_dosadora_1_personalizada, 1, 275, 50); //PosiÃƒÂ§ÃƒÂ£o correta
  myGLCD.printNumI(quantidade_dose_dosadora_1_personalizada, 170, 70);

  if(hora_inicial_dosagem_personalizada_1 < 10)
  {
    myGLCD.printNumI(0, 72, 50);
    myGLCD.printNumI(hora_inicial_dosagem_personalizada_1, 80, 50);
  }
  else
  {
    myGLCD.printNumI(hora_inicial_dosagem_personalizada_1, 72, 50);
  }
  if(minuto_inicial_dosagem_personalizada_1 < 10)
  {
    myGLCD.printNumI(0, 98, 50);
    myGLCD.printNumI(minuto_inicial_dosagem_personalizada_1, 106, 50);
  }
  else
  {
    myGLCD.printNumI(minuto_inicial_dosagem_personalizada_1, 98, 50);
  }
  if(hora_final_dosagem_personalizada_1 < 10)
  {
    myGLCD.printNumI(0, 165, 50);
    myGLCD.printNumI(hora_final_dosagem_personalizada_1, 173, 50);
  }
  else
  {
    myGLCD.printNumI(hora_final_dosagem_personalizada_1, 165, 50);
  }
  if(minuto_final_dosagem_personalizada_1 < 10)
  {
    myGLCD.printNumI(0, 188, 50);
    myGLCD.printNumI(minuto_final_dosagem_personalizada_1, 196, 50);
  }
  else
  {
    myGLCD.printNumI(minuto_final_dosagem_personalizada_1, 188, 50);
  }
  if(segunda_dosagem_personalizada_1 == 1)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[70])));
    printButton_verde(buffer, 110, 23, 130, 43);
  }
  else
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[70])));
    printButton(buffer, 110, 23, 130, 43);
  }
  if(terca_dosagem_personalizada_1 == 2)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[71])));
    printButton_verde(buffer, 140, 23, 160, 43);
  }
  else
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[71])));
    printButton(buffer, 140, 23, 160, 43);
  }
  if(quarta_dosagem_personalizada_1 == 3)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[72])));
    printButton_verde(buffer, 170, 23, 190, 43);
  }
  else
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[72])));
    printButton(buffer, 170, 23, 190, 43);
  }
  if(quinta_dosagem_personalizada_1 == 4)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[198])));
    printButton_verde(buffer, 200, 23, 220, 43);
  }
  else
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[198])));
    printButton(buffer, 200, 23, 220, 43);
  }
  if(sexta_dosagem_personalizada_1 == 5)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[199])));
    printButton_verde(buffer, 230, 23, 250, 43);
  }
  else
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[199])));
    printButton(buffer, 230, 23, 250, 43);
  }
  if(sabado_dosagem_personalizada_1 == 6)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[200])));
    printButton_verde(buffer, 260, 23, 280, 43);
  }
  else
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[200])));
    printButton(buffer, 260, 23, 280, 43);
  }
  if(domingo_dosagem_personalizada_1 == 7)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[73])));
    printButton_verde(buffer, 290, 23, 310, 43);
  }
  else
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[73])));
    printButton(buffer, 290, 23, 310, 43);
  }
  if (modo_personalizado_on_1 == true)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[126])));
    printButton_verde(buffer, 200, 65, 245, 85);
  }
  else
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[126])));
    printButton(buffer, 200, 65, 245, 85);
  }
  if (modo_personalizado_on_1 == false)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[127])));
    printButton_verde(buffer, 250, 65, 295, 85);
  }
  else
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[127])));
    printButton(buffer, 250, 65, 295, 85);
  }
  setFont(SMALL, 255, 255, 255, 0, 0, 0);

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[130])));
  myGLCD.print(buffer, 10, 100);

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[118])));
  myGLCD.print(buffer, 10, 120);

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[119])));
  myGLCD.print(buffer, 118, 120);

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[128])));
  myGLCD.print(buffer, 10, 140);

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[121])));
  myGLCD.print(buffer, 215, 120);

  myGLCD.print(":", 90, 120);
  myGLCD.print(":", 180, 120);

  myGLCD.printNumF(dose_dosadora_2_personalizada, 1, 275, 120);
  myGLCD.printNumI(quantidade_dose_dosadora_2_personalizada, 170, 140);

  if(hora_inicial_dosagem_personalizada_2 < 10)
  {
    myGLCD.printNumI(0, 72, 120);
    myGLCD.printNumI(hora_inicial_dosagem_personalizada_2, 80, 120);
  }
  else
  {
    myGLCD.printNumI(hora_inicial_dosagem_personalizada_2, 72, 120);
  }
  if(minuto_inicial_dosagem_personalizada_2 < 10)
  {
    myGLCD.printNumI(0, 98, 120);
    myGLCD.printNumI(minuto_inicial_dosagem_personalizada_2, 106, 120);
  }
  else
  {
    myGLCD.printNumI(minuto_inicial_dosagem_personalizada_2, 98, 120);
  }
  if(hora_final_dosagem_personalizada_2 < 10)
  {
    myGLCD.printNumI(0, 165, 120);
    myGLCD.printNumI(hora_final_dosagem_personalizada_2, 173, 120);
  }
  else
  {
    myGLCD.printNumI(hora_final_dosagem_personalizada_2, 165, 120);
  }
  if(minuto_final_dosagem_personalizada_2 < 10)
  {
    myGLCD.printNumI(0, 188, 120);
    myGLCD.printNumI(minuto_final_dosagem_personalizada_2, 196, 120);
  }
  else
  {
    myGLCD.printNumI(minuto_final_dosagem_personalizada_2, 188, 120);
  }
  if(segunda_dosagem_personalizada_2 == 1)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[70])));
    printButton_verde(buffer, 110, 93, 130, 113);
  }
  else
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[70])));
    printButton(buffer, 110, 93, 130, 113);
  }
  if(terca_dosagem_personalizada_2 == 2)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[71])));
    printButton_verde(buffer, 140, 93, 160, 113);
  }
  else
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[71])));
    printButton(buffer, 140, 93, 160, 113);
  }
  if(quarta_dosagem_personalizada_2 == 3)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[72])));
    printButton_verde(buffer, 170, 93, 190, 113);
  }
  else
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[72])));
    printButton(buffer, 170, 93, 190, 113);
  }
  if(quinta_dosagem_personalizada_2 == 4)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[198])));
    printButton_verde(buffer, 200, 93, 220, 113);
  }
  else
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[198])));
    printButton(buffer, 200, 93, 220, 113);
  }
  if(sexta_dosagem_personalizada_2 == 5)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[199])));
    printButton_verde(buffer, 230, 93, 250, 113);
  }
  else
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[199])));
    printButton(buffer, 230, 93, 250, 113);
  }
  if(sabado_dosagem_personalizada_2 == 6)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[200])));
    printButton_verde(buffer, 260, 93, 280, 113);
  }
  else
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[200])));
    printButton(buffer, 260, 93, 280, 113);
  }
  if(domingo_dosagem_personalizada_2 == 7)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[73])));
    printButton_verde(buffer, 290, 93, 310, 113);
  }
  else
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[73])));
    printButton(buffer, 290, 93, 310, 113);
  }
  if (modo_personalizado_on_2 == true)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[126])));
    printButton_verde(buffer, 200, 135, 245, 155);
  }
  else
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[126])));
    printButton(buffer, 200, 135, 245, 155);
  }
  if (modo_personalizado_on_2 == false)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[127])));
    printButton_verde(buffer, 250, 135, 295, 155);
  }
  else
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[127])));
    printButton(buffer, 250, 135, 295, 155);
  }
  setFont(SMALL, 255, 255, 255, 0, 0, 0);

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[131])));
  myGLCD.print(buffer, 10, 170);

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[118])));
  myGLCD.print(buffer, 10, 190);

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[119])));
  myGLCD.print(buffer, 118, 190);

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[128])));
  myGLCD.print(buffer, 10, 210); // tabela_textos[128] = "QUANTIDADE DE DOSES:"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[121])));
  myGLCD.print(buffer, 215, 190);

  myGLCD.print(":", 90, 190);
  myGLCD.print(":", 180, 190);

  myGLCD.printNumF(dose_dosadora_3_personalizada, 1, 275, 190);
  myGLCD.printNumI(quantidade_dose_dosadora_3_personalizada, 170, 210);

  if(hora_inicial_dosagem_personalizada_3 < 10)
  {
    myGLCD.printNumI(0, 72, 190);
    myGLCD.printNumI(hora_inicial_dosagem_personalizada_3, 80, 190);
  }
  else
  {
    myGLCD.printNumI(hora_inicial_dosagem_personalizada_3, 72, 190);
  }
  if(minuto_inicial_dosagem_personalizada_3 < 10)
  {
    myGLCD.printNumI(0, 98, 190);
    myGLCD.printNumI(minuto_inicial_dosagem_personalizada_3, 106, 190);
  }
  else
  {
    myGLCD.printNumI(minuto_inicial_dosagem_personalizada_3, 98, 190);
  }
  if(hora_final_dosagem_personalizada_3 < 10)
  {
    myGLCD.printNumI(0, 165, 190);
    myGLCD.printNumI(hora_final_dosagem_personalizada_3, 173, 190);
  }
  else
  {
    myGLCD.printNumI(hora_final_dosagem_personalizada_3, 165, 190);
  }
  if(minuto_final_dosagem_personalizada_3 < 10)
  {
    myGLCD.printNumI(0, 188, 190);
    myGLCD.printNumI(minuto_final_dosagem_personalizada_3, 196, 190);
  }
  else
  {
    myGLCD.printNumI(minuto_final_dosagem_personalizada_3, 188, 190);
  }
  if(segunda_dosagem_personalizada_3 == 1)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[70])));
    printButton_verde(buffer, 110, 163, 130, 183);
  }
  else
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[70])));
    printButton(buffer, 110, 163, 130, 183);
  }
  if(terca_dosagem_personalizada_3 == 2)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[71])));
    printButton_verde(buffer, 140, 163, 160, 183);
  }
  else
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[71])));
    printButton(buffer, 140, 163, 160, 183);
  }
  if(quarta_dosagem_personalizada_3 == 3)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[72])));
    printButton_verde(buffer, 170, 163, 190, 183);
  }
  else
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[72])));
    printButton(buffer, 170, 163, 190, 183);
  }
  if(quinta_dosagem_personalizada_3 == 4)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[198])));
    printButton_verde(buffer, 200, 163, 220, 183);
  }
  else
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[198])));
    printButton(buffer, 200, 163, 220, 183);
  }
  if(sexta_dosagem_personalizada_3 == 5)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[199])));
    printButton_verde(buffer, 230, 163, 250, 183);
  }
  else
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[199])));
    printButton(buffer, 230, 163, 250, 183);
  }
  if(sabado_dosagem_personalizada_3 == 6)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[200])));
    printButton_verde(buffer, 260, 163, 280, 183);
  }
  else
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[200])));
    printButton(buffer, 260, 163, 280, 183);
  }
  if(domingo_dosagem_personalizada_3 == 7)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[73])));
    printButton_verde(buffer, 290, 163, 310, 183);
  }
  else
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[73])));
    printButton(buffer, 290, 163, 310, 183);
  }
  if (modo_personalizado_on_3 == true)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[126])));
    printButton_verde(buffer, 200, 205, 245, 225);
  }
  else
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[126])));
    printButton(buffer, 200, 205, 245, 225);
  }
  if (modo_personalizado_on_3 == false)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[127])));
    printButton_verde(buffer, 250, 205, 295, 225);
  }
  else
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[127])));
    printButton(buffer, 250, 205, 295, 225);
  }
}

//---------------------------------------------Desativar dosadoras--------------------------------tela =35 ----------
void desativar_dosadoras(boolean refreshAll = false)
{
  if(refreshAll == true)
  {
    if (modo_personalizado_on_1 == true)
    {
      bitWrite(ativar_desativar,1,1);
    }
    else
    {
      bitWrite(ativar_desativar,1,0);
    }
    if (modo_personalizado_on_2 == true)
    {
      bitWrite(ativar_desativar,2,1);
    }
    else
    {
      bitWrite(ativar_desativar,2,0);
    }
    if (modo_personalizado_on_3 == true)
    {
      bitWrite(ativar_desativar,3,1);
    }
    else
    {
      bitWrite(ativar_desativar,3,0);
    }
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[51])));
    printHeader(buffer); // tabela_textos[51] = "DESATIVAR DOSADORAS"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[11])));
    printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3]); // "INICIO"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[1])));
    printButton(buffer, menU[0], menU[1], menU[2], menU[3]); // "MENU 1";

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[13])));
    printButton(buffer, salV[0], salV[1], salV[2], salV[3]); // "SALVAR"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[66])));
    printButton(buffer, volT[0], volT[1], volT[2], volT[3]); // VOLTAR

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[210])));
    printButton(buffer, deS[0], deS[1], deS[2], deS[3]); //"MAIS"

    setFont(SMALL, 255, 255, 255, 0, 0, 0);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[129])));
    myGLCD.print(buffer, 120, 30);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[130])));
    myGLCD.print(buffer, 120, 100);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[131])));
    myGLCD.print(buffer, 120, 170);

    setFont(SMALL, 255, 0, 0, 0, 0, 0);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[141])));
    myGLCD.print(buffer, 230, 60); //tabela_textos[141] = "USE ESTA"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[142])));
    myGLCD.print(buffer, 230, 75); //tabela_textos[141] = "FUNCAO"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[143])));
    myGLCD.print(buffer, 230, 90); // tabela_textos[143] = "APENAS PARA"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[144])));
    myGLCD.print(buffer, 230, 105); //tabela_textos[144] = "DESATIVAR"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[145])));
    myGLCD.print(buffer, 230, 120); // tabela_textos[145] = "OS MODOS"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[146])));
    myGLCD.print(buffer, 230, 135); // tabela_textos[146] = "DE DOSAGEM."
  }
  if (bitRead(ativar_desativar,1) == true)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[147])));
    printButton_verde(buffer, 100, 45, 220, 85); // tabela_textos[147]

    myGLCD.setColor(0, 0, 0);
    myGLCD.fillRect (3, 26, 117, 43);
    myGLCD.fillRect (3, 45, 95, 61);
    myGLCD.fillRect (3, 60, 95, 76);
    myGLCD.fillRect (3, 75, 95, 91);

    setFont(SMALL, 255, 255, 255, 0, 0, 0);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[149])));
    myGLCD.print(buffer, 10, 30); // tabela_textos[149] = "UM DOS MODOS"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[150])));
    myGLCD.print(buffer, 10, 45); // tabela_textos[150] = "DE DOSAGEM "

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[151])));
    myGLCD.print(buffer, 10, 60); // tabela_textos[151] = "ESTA:"
  }
  else
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[152])));
    printButton(buffer, 100, 45, 220, 85);

    setFont(SMALL, 255, 255, 0, 0, 0, 0);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[153])));
    myGLCD.print(buffer, 3, 30);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[150])));
    myGLCD.print(buffer, 3, 45);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[154])));
    myGLCD.print(buffer, 3, 60);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[155])));
    myGLCD.print(buffer, 3, 75);
  }
  if (bitRead(ativar_desativar,2) == true)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[147])));
    printButton_verde(buffer, 100, 115, 220, 155);

    myGLCD.setColor(0, 0, 0);
    myGLCD.fillRect (3, 96, 117, 113);
    myGLCD.fillRect (3, 115, 95, 131);
    myGLCD.fillRect (3, 130, 95, 146);
    myGLCD.fillRect (3, 145, 95, 161);

    setFont(SMALL, 255, 255, 255, 0, 0, 0);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[149])));
    myGLCD.print(buffer, 10, 100); // "BOTH MODES"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[150])));
    myGLCD.print(buffer, 10, 115); // "OF DOSAGE"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[151])));
    myGLCD.print(buffer, 10, 130); // "ARE OR:"
  }
  else
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[152])));
    printButton(buffer, 100, 115, 220, 155); // "DEACTIVATED"

    setFont(SMALL, 255, 255, 0, 0, 0, 0);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[153])));
    myGLCD.print(buffer, 3, 100); // "BOTH MODES"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[150])));
    myGLCD.print(buffer, 3, 115); // "OF DOSAGE"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[154])));
    myGLCD.print(buffer, 3, 130); // "ARE OR"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[155])));
    myGLCD.print(buffer, 3, 145); // "WILL BE:"
  }
  if (bitRead(ativar_desativar,3) == true)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[147])));
    printButton_verde(buffer, 100, 185, 220, 225); // "ACTIVATED"

    myGLCD.setColor(0, 0, 0);
    myGLCD.fillRect (3, 166, 117, 183);
    myGLCD.fillRect (3, 185, 95, 201);
    myGLCD.fillRect (3, 200, 95, 216);
    myGLCD.fillRect (3, 215, 95, 231);

    setFont(SMALL, 255, 255, 255, 0, 0, 0);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[149])));
    myGLCD.print(buffer, 10, 170);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[150])));
    myGLCD.print(buffer, 10, 185);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[151])));
    myGLCD.print(buffer, 10, 200);
  }
  else
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[152])));
    printButton(buffer, 100, 185, 220, 225);

    setFont(SMALL, 255, 255, 0, 0, 0, 0);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[153])));
    myGLCD.print(buffer, 3, 170);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[150])));
    myGLCD.print(buffer, 3, 185);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[154])));
    myGLCD.print(buffer, 3, 200);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[155])));
    myGLCD.print(buffer, 3, 215);
  }
}

//--------------------------------------------- PotÃƒÂªncia mÃƒÂ­nima e mÃƒÂ¡xima para a luz noturna -------------------------------- tela =36
void luz_noturna(boolean refreshAll=false)
{

  if (refreshAll)
  {
    tMaxI = MaxI;
    tMinI = MinI;

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[52])));
    printHeader(buffer); // tabela_textos[52] = "LUZ NOTURNA 255 = 100 %"

    setFont(LARGE, 255, 255, 255, 0, 0, 0);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[180])));
    myGLCD.print(buffer, 180, 140); // "ILUMINACAO MAXIMA:"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[156])));
    myGLCD.print(buffer, 180, 340); // "ILUMINACAO MINIMA:"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[157])));
    myGLCD.print(buffer, 250, 40); // "LUA CHEIA:"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[158])));
    myGLCD.print(buffer, 2600, 240); // "LUA NOVA:"

    printButton("-", temM[0], temM[1], temM[2], temM[3], true); //Lua cheia menos
    printButton("+", temP[0], temP[1], temP[2], temP[3], true); //Lua cheia mais
    printButton("-", almM[0], almM[1], almM[2], almM[3], true); //Lua nova menos
    printButton("+", almP[0], almP[1], almP[2], almP[3], true); //Lua nova mais

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[13])));
    printButton(buffer, salV[0], salV[1], salV[2], salV[3]); // "SALVAR"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[11])));
    printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3]); // "INICIO"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[1])));
    printButton(buffer, menU[0], menU[1], menU[2], menU[3]); // "MENU 1";

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[66])));
    printButton(buffer, volT[0], volT[1], volT[2], volT[3]); // tabela_textos[66] = "VOLTAR";
  }

  setFont(LARGE, 255, 255, 255, 0, 0, 0);
  myGLCD.printNumI(tMaxI, 270, 80);
  myGLCD.printNumI(tMinI, 270, 280);
}

//--------------------------------------------- Menu 2 -------------------------------- tela =37
void menuScreen_2()
{

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[2])));
  printHeader(buffer); // tabela_textos[2] = "MENU 2"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[227])));
  printButton(buffer, tanD[0], tanD[1], tanD[2], tanD[3]); // "SONDAS DE TEMP."// 1Ã‚Âº botÃƒÂ£o, 1Ã‚Âª coluna
  // printButton("", tesT[0], tesT[1], tesT[2], tesT[3]); // 2Ã‚Âº botÃƒÂ£o, 1Ã‚Âª coluna
  // printButton("", temC[0], temC[1], temC[2], temC[3]); // 3Ã‚Âº botÃƒÂ£o, 1Ã‚Âª coluna
  // printButton("", graF[0], graF[1], graF[2], graF[3]); // 4Ã‚Âº botÃƒÂ£o, 1Ã‚Âª coluna
  // printButton("", ledW[0], ledW[1], ledW[2], ledW[3]); // 1Ã‚Âº botÃƒÂ£o, 2Ã‚Âª coluna
  // printButton("", tpaA[0], tpaA[1], tpaA[2], tpaA[3]); // 2Ã‚Âº botÃƒÂ£o, 2Ã‚Âª coluna
  // printButton("", dosA[0], dosA[1], dosA[2], dosA[3]); // 3Ã‚Âº botÃƒÂ£o, 2Ã‚Âª coluna
  // printButton("", wavM[0], wavM[1], wavM[2], wavM[3]); // 4Ã‚Âº botÃƒÂ£o, 2Ã‚Âª coluna
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

  if (temporizador_1_ativado == 1)
  {
    printButton_verde("T 1",14, 44, 112, 100); // Timer 1
  }
  else
  {
    printButton("T 1",14, 44, 112, 100); // Timer 1
  }
  if (temporizador_2_ativado == 1)
  {
    printButton_verde("T 2",142, 44, 240, 100); // Timer 2
  }
  else
  {
    printButton("T 2",142, 44, 240, 100); // Timer 2
  }
  if (temporizador_3_ativado == 1)
  {
    printButton_verde("T 3",270, 44, 368, 100); // Timer 3
  }
  else
  {
    printButton("T 3",270, 44, 368, 100); // Timer 3
  }
  if (temporizador_4_ativado == 1)
  {
    printButton_verde("T 4",398, 44, 498, 100); // Timer 4
  }
  else
  {
    printButton("T 4",398, 44, 498, 100); // Timer 4
  }
  if (temporizador_5_ativado == 1)
  {
    printButton_verde("T 5",526, 44, 624, 100); // Timer 5
  }
  else
  {
    printButton("T 5",526, 44, 624, 100); // Timer 5
  }

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[126])));
  printButton_verde(buffer,14, 110, 112, 194); // BotÃƒÂ£o ON 1

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[126])));
  printButton_verde(buffer,142, 110, 240, 194); // BotÃƒÂ£o ON 2

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[126])));
  printButton_verde(buffer,270, 110, 368, 194); // BotÃƒÂ£o ON 3

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[126])));
  printButton_verde(buffer,398, 110, 496, 194); // BotÃƒÂ£o ON 4

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[126])));
  printButton_verde(buffer,526, 110, 624, 194); // BotÃƒÂ£o ON 5

  myGLCD.setColor(255, 255, 255); // RetÃƒÂ¢ngulos ao redor dos horÃƒÂ¡rios
  myGLCD.drawRoundRect(14, 204, 112, 288); // BotÃƒÂ£o ON 1
  myGLCD.drawRoundRect(142, 204, 240, 288); // BotÃƒÂ£o ON 2
  myGLCD.drawRoundRect(270, 204, 368, 288); // BotÃƒÂ£o ON 3
  myGLCD.drawRoundRect(398, 204, 496, 288); // BotÃƒÂ£o ON 4
  myGLCD.drawRoundRect(526, 204, 624, 288); // BotÃƒÂ£o ON 5

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[127])));
  printButton_vermelho(buffer, 16, 298, 110, 382); // BotÃƒÂ£o OFF 1

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[127])));
  printButton_vermelho(buffer, 144, 298, 238, 382); // BotÃƒÂ£o OFF 2

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[127])));
  printButton_vermelho(buffer, 272, 298, 366, 382); // BotÃƒÂ£o OFF 3

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[127])));
  printButton_vermelho(buffer, 400, 298, 494, 382); // BotÃƒÂ£o OFF 4

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[127])));
  printButton_vermelho(buffer, 528, 298, 622, 382); // BotÃƒÂ£o OFF 5

  myGLCD.setColor(255, 255, 255); // RetÃƒÂ¢ngulos ao redor dos horÃƒÂ¡rios
  myGLCD.drawRoundRect(14, 392, 112, 476); // BotÃƒÂ£o OFF 1
  myGLCD.drawRoundRect(142, 392, 240, 476); // BotÃƒÂ£o OFF 2
  myGLCD.drawRoundRect(270, 392, 368, 476); // BotÃƒÂ£o OFF 3
  myGLCD.drawRoundRect(398, 392, 496, 476); // BotÃƒÂ£o OFF 4
  myGLCD.drawRoundRect(526, 392, 624, 476); // BotÃƒÂ£o OFF 5

  myGLCD.setBackColor(0, 0, 0);

  if (on1_hora < 10) // Timer 1
  {
    myGLCD.print("0",24, 234);
    myGLCD.printNumI(on1_hora,41,234);
  }
  else
  {
    myGLCD.printNumI(on1_hora, 24, 234);
  }
  myGLCD.print(":", 58, 234);

  if (on1_minuto < 10)
  {
    myGLCD.print("0", 74, 234);
    myGLCD.printNumI(on1_minuto, 92, 234);
  }
  else
  {
    myGLCD.printNumI(on1_minuto, 74,234);
  }

  if (on2_hora < 10) // Timer 2
  {
    myGLCD.print("0", 152, 234);
    myGLCD.printNumI(on2_hora ,170, 234);
  }
  else
  {
    myGLCD.printNumI(on2_hora, 152, 234);
  }

  myGLCD.print(":", 186, 234);

  if (on2_minuto < 10)
  {
    myGLCD.print("0",202, 234);
    myGLCD.printNumI(on2_minuto, 220, 234);
  }
  else
  {
    myGLCD.printNumI(on2_minuto,202, 234);
  }

  if (on3_hora <10) // Timer 3
  {
    myGLCD.print("0",280, 234);
    myGLCD.printNumI(on3_hora,298, 234);
  }
  else
  {
    myGLCD.printNumI(on3_hora, 280, 234);
  }

  myGLCD.print(":",314, 234);

  if (on3_minuto < 10)
  {
    myGLCD.print("0",330, 234);
    myGLCD.printNumI(on3_minuto, 348, 234);
  }
  else {
    myGLCD.printNumI(on3_minuto ,330, 234);
  }

  if (on4_hora < 10) // Timer 4
  {
    myGLCD.print("0",408, 234);
    myGLCD.printNumI(on4_hora,426, 234);
  }
  else{
    myGLCD.printNumI(on4_hora,408, 234);
  }

  myGLCD.print(":",442, 234);

  if (on4_minuto < 10)
  {
    myGLCD.print("0",458, 234);
    myGLCD.printNumI(on4_minuto, 476, 234);
  }
  else
  {
    myGLCD.printNumI(on4_minuto, 458, 234);
  }

  if (on5_hora < 10) // Timer 5
  {
    myGLCD.print("0",535, 234);
    myGLCD.printNumI(on5_hora, 554, 234);
  }
  else
  {
    myGLCD.printNumI(on5_hora, 536, 234);
  }

  myGLCD.print(":",570, 234);

  if (on5_minuto < 10)
  {
    myGLCD.print("0", 586, 234);
    myGLCD.printNumI(on5_minuto, 604, 234);
  }
  else
  {
    myGLCD.printNumI(on5_minuto, 586, 234);
  }

  if (off1_hora < 10) // Timer 1
  {
    myGLCD.print("0",24, 422);
    myGLCD.printNumI(off1_hora, 42, 422);
  }
  else
  {
    myGLCD.printNumI(off1_hora, 24, 422);
  }

  myGLCD.print(":", 58, 420);

  if (off1_minuto < 10)
  {
    myGLCD.print("0", 74, 422);
    myGLCD.printNumI(off1_minuto, 92, 422);
  }
  else
  {
    myGLCD.printNumI(off1_minuto, 74,422);
  }

  if (off2_hora < 10) // Timer 2
  {
    myGLCD.print("0", 152, 422);
    myGLCD.printNumI(off2_hora , 170, 422);
  }
  else
  {
    myGLCD.printNumI(off2_hora, 152, 422);
  }

  myGLCD.print(":", 186, 422);

  if (off2_minuto < 10)
  {
    myGLCD.print("0",202, 422);
    myGLCD.printNumI(off2_minuto, 220, 422);
  }
  else
  {
    myGLCD.printNumI(off2_minuto,202, 422);
  }

  if (off3_hora <10) // Timer 3
  {
    myGLCD.print("0", 280, 422);
    myGLCD.printNumI(off3_hora, 298, 422);
  }
  else
  {
    myGLCD.printNumI(off3_hora, 280, 422);
  }

  myGLCD.print(":", 314, 422);

  if (off3_minuto < 10)
  {
    myGLCD.print("0", 330, 422);
    myGLCD.printNumI(off3_minuto, 348, 422);
  }
  else
  {
    myGLCD.printNumI(off3_minuto, 330, 422);
  }

  if (off4_hora < 10) // Timer 4
  {
    myGLCD.print("0", 408, 422);
    myGLCD.printNumI(off4_hora, 426, 422);
  }
  else
  {
    myGLCD.printNumI(off4_hora, 408, 422);
  }

  myGLCD.print(":", 442, 422);

  if (off4_minuto < 10)
  {
    myGLCD.print("0", 458, 422);
    myGLCD.printNumI(off4_minuto, 476, 422);
  }
  else
  {
    myGLCD.printNumI(off4_minuto, 458, 422);
  }

  if (off5_hora < 10) // Timer 5
  {
    myGLCD.print("0", 536, 422);
    myGLCD.printNumI(off5_hora, 554, 422);
  }
  else
  {
    myGLCD.printNumI(off5_hora, 536, 422);
  }

  myGLCD.print(":", 570, 422);

  if (off5_minuto < 10)
  {
    myGLCD.print("0", 586, 422);
    myGLCD.printNumI(off5_minuto, 604, 422);
  }
  else {
    myGLCD.printNumI(off5_minuto, 586, 422);
  }

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[1])));
  printButton(buffer, menU[0], menU[1], menU[2], menU[3]); // Volta ao menu 1. // "MENU 1";

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[11])));
  printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3]); // Volta ao inÃƒÂ­cio. // "INICIO"
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
      else if(temporizador == 2)
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

    printButton("+", 42, 90, 130, 176, true); // BotÃƒÂ£o para cima
    printButton("+", 178, 90, 266, 176, true); // BotÃƒÂ£o para cima
    printButton("-", 42, 270, 130, 356, true); // BotÃƒÂ£o para baixo
    printButton("-", 178, 270, 266, 356, true); // BotÃƒÂ£o para baixo

    printButton("+", 374, 90, 462, 176, true); // BotÃƒÂ£o para cima
    printButton("+", 510, 90, 598, 176, true); // BotÃƒÂ£o para cima
    printButton("-", 374, 270, 462, 356, true); // BotÃƒÂ£o para baixo
    printButton("-", 510, 270, 598, 356, true); // BotÃƒÂ£o para baixo

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[1])));
    printButton(buffer, menU[0], menU[1], menU[2], menU[3]); // Volta ao menu 1. // "MENU 1";

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[11])));
    printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3]); // Volta ao inÃƒÂ­cio. // "INICIO"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[66])));
    printButton(buffer, volT[0], volT[1], volT[2], volT[3]); // Volta ao menu selecionar timer. // "VOLTAR"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[13])));
    printButton(buffer, salV[0], salV[1], salV[2], salV[3]); // Salva as modificaÃƒÂ§ÃƒÂµes. // "SALVAR"

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

  if (off1_minuto_temp2 < 10)
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

//--------------------------------------------- Configurar leds -------------------------------- tela =40
void config_leds()
{
  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[202])));
  printHeader(buffer); // tabela_textos[2] = "CONFIGURAR LEDS"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[4])));
  printButton(buffer, tanD[0], tanD[1], tanD[2], tanD[3]); // 1Ã‚Âº botaÃƒÂ£o, 1Ã‚Âª coluna

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[7])));
  printButton(buffer, tesT[0], tesT[1], tesT[2], tesT[3]); // 2Ã‚Âº botÃƒÂ£o, 1Ã‚Âª coluna

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[159])));
  printButton(buffer, temC[0], temC[1], temC[2], temC[3]); // 3Ã‚Âº botÃƒÂ£o, 1Ã‚Âª coluna

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[228])));
  printButton(buffer, graF[0], graF[1], graF[2], graF[3]); // "COOLERS"

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[232])));
  printButton(buffer, ledW[0], ledW[1], ledW[2], ledW[3]); // "REDUZIR POT."

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[69])));
  printButton(buffer, tpaA[0],tpaA[1], tpaA[2], tpaA[3]); // "predefinido_t"

  // printButton("", dosA[0], dosA[1], dosA[2], dosA[3]); // 3Ã‚Âº botÃƒÂ£o, 2Ã‚Âª coluna
  // printButton("", wavM[0], wavM[1], wavM[2], wavM[3]); // 4Ã‚Âº botÃƒÂ£o, 2Ã‚Âª coluna
  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[1])));
  printButton(buffer, menU[0], menU[1], menU[2], menU[3]); // "MENU 1";

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[11])));
  printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3]); // "INICIO"
}

//------------------------------- Procurar sensores de temperatura -------------------------------- tela =41
void procurar_sensores(boolean refreshAll=false)
{
  int numberOfDevices; // NÃƒÂºmero de sensores encontrados
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
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[217]))); // "1"
    printButton(buffer, sonD1[0], sonD1[1], sonD1[2], sonD1[3], true);
  }
  if(sonda_associada_1_temp == 2)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[218]))); // "2"
    printButton_verde(buffer, sonD1[0], sonD1[1], sonD1[2], sonD1[3], true);
  }
  if(sonda_associada_1_temp == 3)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[219]))); // "3"
    printButton_vermelho(buffer, sonD1[0], sonD1[1], sonD1[2], sonD1[3], true);
  }

  if(sonda_associada_2_temp == 1)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[217]))); // "1"
    printButton(buffer, sonD2[0], sonD2[1], sonD2[2], sonD2[3], true);
  }
  if(sonda_associada_2_temp == 2)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[218]))); // "2"
    printButton_verde(buffer, sonD2[0], sonD2[1], sonD2[2], sonD2[3], true);
  }
  if(sonda_associada_2_temp == 3)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[219]))); // "3"
    printButton_vermelho(buffer, sonD2[0], sonD2[1], sonD2[2], sonD2[3], true);
  }

  if(sonda_associada_3_temp == 1)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[217]))); // "1"
    printButton(buffer, sonD3[0], sonD3[1], sonD3[2], sonD3[3], true);
  }
  if(sonda_associada_3_temp == 2)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[218]))); // "2"
    printButton_verde(buffer, sonD3[0], sonD3[1], sonD3[2], sonD3[3], true);
  }
  if(sonda_associada_3_temp == 3)
  {
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[219]))); // "3"
    printButton_vermelho(buffer, sonD3[0], sonD3[1], sonD3[2], sonD3[3], true);
  }

  sensors.begin();
  numberOfDevices = sensors.getDeviceCount();

  setFont(LARGE, 88, 255, 238, 0, 0, 0);
  myGLCD.printNumI(numberOfDevices, 65, 44); // NUMBER OF PROBES FOUND, IN THIS CASE,"3"


  for(byte k = 0; k < numberOfDevices; k++)
  {
    // Pesquisar endereÃƒÂ§os
    if(sensors.getAddress(tempDeviceAddress, k))
    {
      temperatura = sensors.getTempC(tempDeviceAddress);
      
      temperatura = (temperatura * 1.8) + 32.05;
     
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
    myGLCD.printNumF(temperatura, 1, 278,(k * 18) + 80); // Imprime as teperaturas.
    myGLCD.print(":", 262, (k * 20) + 80);
    myGLCD.print("F", 360, (k * 20) + 80);
    //myGLCD.print("C", 315, (k * 15) + 80);
    myGLCD.drawCircle(355, (k * 20) + 82, 1);

    setFont(LARGE, 88, 255, 238, 0, 0, 0);
    for (byte i = 0; i < 8; i++)
    {
      byte result;
      byte temp = tempDeviceAddress[i];
      result = temp/16;	//Converte primeiro caracter HEX para ASCII
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

      result = temp - (temp/16) * 16; // Converte segundo caracter HEX para ASCII
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
    myGLCD.print(buffer, 230, 40); // "INIACIAR EM:"

    //myGLCD.print("(20 ----- 35)", 220, 140); // interval /******************************************************** changed for Fahrenheit *******************************************************************/
    myGLCD.print("(68 ----- 95)", 220, 140); // interval // CHANGE VALUES FOR F SCALE TO (68 --- 84)

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[231])));
    myGLCD.print(buffer, 160, 240); // "VELOCIDADE MAXIMA EM:"

    //myGLCD.print("(36 ----- 50)", 220, 340); // interval /******************************************************** changed for Fahrenheit *******************************************************************/
    myGLCD.print("(96 ---- 122)", 220, 340); // interval // CHANGE VALUES FOR F SCALE TO (85 --- 99)

    printButton("-", temM[0], temM[1], temM[2], temM[3], true); // Temperatura para iniciar +
    printButton("+", temP[0], temP[1], temP[2], temP[3], true); // Temperatura para iniciar -
    printButton("-", almM[0], almM[1], almM[2], almM[3], true); // Temperatura para velocidade mÃƒÂ¡xima +
    printButton("+", almP[0], almP[1], almP[2], almP[3], true); // Temperatura para velocidade mÃƒÂ¡xima -
  }

  setFont(LARGE, 255, 255, 255, 0, 0, 0);
  myGLCD.printNumF(HtempMin_temp, 1, 260, 80); // the 130 is coordinate to move number left or right ***************** need to change for Fahrenheit, longer number string **********
  myGLCD.printNumF(HtempMax_temp, 1, 260, 280);
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

    myGLCD.drawCircle(590, 118, 2);
    //myGLCD.print(" C ", 299, 59); /******************************************************** changed for Fahrenheit *******************************************************************/
    myGLCD.print(" F ", 598, 118);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[234]))); // "REDUZIR POTENCIA EM"
    myGLCD.print(buffer, 130, 280);
    myGLCD.print("%.", 590, 280);
  }
  myGLCD.setColor(0, 0, 0);
  myGLCD.fillRect(450, 270, 520, 310); // Apaga valores

  setFont(LARGE, 0, 255, 0, 0, 0, 0);
  myGLCD.printNumI(tempHR_t, 450, 110);
  myGLCD.printNumI(potR_t, 450, 270);
}

//------------------------------- LED PRESET -------------------------------- tela =44
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
    myGLCD.print("PWM", 495, 376);

    setFont(LARGE, 255, 255, 255, 0, 0, 0);

    if (led_on_hora_t < 10)
    {
      myGLCD.print("0", 438, 250-10);
      myGLCD.printNumI(led_on_hora_t, 470, 250-10);
    }
    else
    {
      myGLCD.printNumI(led_on_hora_t, 438, 250-10);
    }

    myGLCD.print(":", 504, 240);

    if (led_on_minuto_t < 10)
    
    {
      myGLCD.print("0", 538, 240);
      myGLCD.printNumI(led_on_minuto_t, 570, 240);
    }
    else
    {
      myGLCD.printNumI(led_on_minuto_t, 538, 240);
    }

    if (led_off_hora_t < 10)
    {
      myGLCD.print("0", 438, 310);
      myGLCD.printNumI(led_off_hora_t, 470, 310);
    }
    else
    {
      myGLCD.printNumI(led_off_hora_t, 438, 310);
    }

    myGLCD.print(":", 504, 310);

    if (led_off_minuto_t < 10)
    {
      myGLCD.print("0", 538, 310);
      myGLCD.printNumI(led_off_minuto_t, 570, 310);
    }
    else
    {
      myGLCD.printNumI(led_off_minuto_t, 538, 310);
    }

    setFont(LARGE, 0, 255, 0, 0, 0, 0);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[250])));
    myGLCD.print(buffer, 450, 210); // "AMANHECER"

    myGLCD.setColor(255, 0, 0);
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[251])));
    myGLCD.print(buffer, 450, 280); // "ANOITECER"

    myGLCD.setColor(255, 255, 0);
    myGLCD.drawRect(410, 190, 630, 360);
    myGLCD.drawRect(412, 192, 628, 358);

  }// fim do refreshAll
  if(horario_alterado == false)
  {
    if((predefinido_t == 0) && (pre_definido_ativado_t == 1)) // Se predefinido_t igual a zero. Controlar individualmente.
    {
      strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[247])));
      printButton_verde(buffer, 20, 50, 400, 110); // "CONT. INDIVIDUALMENTE"

      myGLCD.setFont(RusFont1);

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
          myGLCD.print(buffer, 30, 144 + (i * 60) + j); // "BRANCO"
          myGLCD.print(":", 126, 144 + (i * 60) + j);
          myGLCD.print(" ", 142, 144 + (i * 60) + j);
          myGLCD.printNumI(wled_out_temp, 142, 144 + (i * 60) + j);
        }
        else if(i == 1)
        {
          myGLCD.setColor(cor_canal2[0], cor_canal2[1], cor_canal2[2]);
          myGLCD.fillRoundRect(20, 120 + (i * 60) + j, 260, 180 + (i * 60) + j);
          myGLCD.setColor(0, 0, 0);
          myGLCD.setBackColor(cor_canal2[0], cor_canal2[1], cor_canal2[2]);
          strcpy_P(buffer, (char*)pgm_read_word_near(&(nome_canal[7])));
          myGLCD.print(buffer, 30, 144 + (i * 60) + j); // "AZUL"
          myGLCD.print(":", 94, 144 + (i * 60) + j);
          myGLCD.print(" ", 110, 144 + (i * 60) + j);
          myGLCD.printNumI(bled_out_temp, 110, 144 + (i * 60) + j);
        }
        else if(i == 2)
        {
          myGLCD.setColor(cor_canal3[0], cor_canal3[1], cor_canal3[2]);
          myGLCD.fillRoundRect(20, 120 + (i * 60) + j, 260, 180 + (i * 60) + j);
          myGLCD.setColor(0, 0, 0);
          myGLCD.setBackColor(cor_canal3[0], cor_canal3[1], cor_canal3[2]);
          strcpy_P(buffer, (char*)pgm_read_word_near(&(nome_canal[8])));
          myGLCD.print(buffer, 30, 144 + (i * 60) + j); // "AZUL ROYAL"
          myGLCD.print(":", 190, 144 + (i * 60) + j);
          myGLCD.print(" ", 206, 144 + (i * 60) + j);
          myGLCD.printNumI(rbled_out_temp, 206, 144 + (i * 60) + j);
        }
        else if(i == 3)
        {
          myGLCD.setColor(cor_canal4[0], cor_canal4[1], cor_canal4[2]);
          myGLCD.fillRoundRect(20, 120 + (i * 60) + j, 260, 180 + (i * 60) + j);
          myGLCD.setColor(0, 0, 0);
          myGLCD.setBackColor(cor_canal4[0], cor_canal4[1], cor_canal4[2]);
          strcpy_P(buffer, (char*)pgm_read_word_near(&(nome_canal[9])));
          myGLCD.print(buffer, 30, 144 + (i * 60) + j); // "VERMELHO"
          myGLCD.print(":", 158, 144 + (i * 60) + j);
          myGLCD.print(" ", 174, 144 + (i * 60) + j);
          myGLCD.printNumI(rled_out_temp, 174, 144 + (i * 60) + j);
        }
        else if(i == 4)
        {
          myGLCD.setColor(cor_canal5[0], cor_canal5[1], cor_canal5[2]);
          myGLCD.fillRoundRect(20, 120 + (i * 60) + j, 260, 180 + (i * 60) + j);
          myGLCD.setColor(0, 0, 0);
          myGLCD.setBackColor(cor_canal5[0], cor_canal5[1], cor_canal5[2]);
          strcpy_P(buffer, (char*)pgm_read_word_near(&(nome_canal[10])));
          myGLCD.print(buffer, 30, 144 + (i * 60) + j); // "VIOLETA"
          myGLCD.print(":", 142 , 144 + (i * 60) + j);
          myGLCD.print(" ", 158, 144 + (i * 60) + j);
          myGLCD.printNumI(uvled_out_temp, 158, 144 + (i * 60) + j);
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
        myGLCD.setFont(RusFont1);

        if(i == 0)
        {
          strcpy_P(buffer, (char*)pgm_read_word_near(&(nome_canal[6])));
          myGLCD.print(buffer, 30, 144 + (i * 60) + j); // "BRANCO"
          myGLCD.print(":", 126, 144 + (i * 60) + j);
          myGLCD.print(" ", 142, 144 + (i * 60) + j);
          myGLCD.printNumI(wled_out_temp, 142, 144 + (i * 60) + j);

        }
        if(i == 1)
        {
          strcpy_P(buffer, (char*)pgm_read_word_near(&(nome_canal[7])));
          myGLCD.print(buffer, 30, 144 + (i * 60) + j); // "AZUL"
          myGLCD.print(":", 94, 144 + (i * 60) + j);
          myGLCD.print(" ", 110, 144 + (i * 60) + j);
          myGLCD.printNumI(bled_out_temp, 110, 144 + (i * 60) + j);
        }
        if(i == 2)
        {
          strcpy_P(buffer, (char*)pgm_read_word_near(&(nome_canal[8])));
          myGLCD.print(buffer, 30, 144 + (i * 60) + j); // "AZUL ROYAL"
          myGLCD.print(":", 190, 144 + (i * 60) + j);
          myGLCD.print(" ", 206, 144 + (i * 60) + j);
          myGLCD.printNumI(rbled_out_temp, 206, 144 + (i * 60) + j);
        }
        if(i == 3)
        {
          strcpy_P(buffer, (char*)pgm_read_word_near(&(nome_canal[9])));
          myGLCD.print(buffer, 30, 144 + (i * 60) + j); // "VERMELHO"
          myGLCD.print(":", 158, 144 + (i * 60) + j);
          myGLCD.print(" ", 174, 144 + (i * 60) + j);
          myGLCD.printNumI(rled_out_temp, 174, 144 + (i * 60) + j);
        }
        if(i == 4)
        {
          strcpy_P(buffer, (char*)pgm_read_word_near(&(nome_canal[10])));
          myGLCD.print(buffer, 30, 144 + (i * 60) + j); // "VIOLETA"
          myGLCD.print(":", 142, 144 + (i * 60) + j);
          myGLCD.print(" ", 158, 144 + (i * 60) + j);
          myGLCD.printNumI(uvled_out_temp, 158, 144 + (i * 60) + j);
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
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[254]))); // "CONFIG. FOTOPERIODO"
    printHeader(buffer);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[250])));
    printButton_verde(buffer, 16, 34, 284, 68); // "AMANHECER"

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[251])));
    printButton_vermelho(buffer, 346, 34, 624, 68); // "ANOITECER"

    setFont(LARGE, 255, 255, 255, 0, 0, 0);

    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[253])));
    myGLCD.print(buffer, 30, 310); // "DURACAO DO NASCER E POR DO SOL EM MIN."

    printButton("+", 60, 90, 110, 140, true); // BotÃƒÂ£o para cima
    printButton("+", 200, 90, 250, 140, true); // BotÃƒÂ£o para cima
    printButton("-", 60, 210, 110, 260, true); // BotÃƒÂ£o para baixo
    printButton("-", 200, 210, 250, 260, true); // BotÃƒÂ£o para baixo

    printButton("+", 390, 90, 440, 140, true); // BotÃƒÂ£o para cima
    printButton("+", 530, 90, 580, 140, true); // BotÃƒÂ£o para cima
    printButton("-", 390, 210, 440, 260, true); // BotÃƒÂ£o para baixo
    printButton("-", 530, 210, 580, 260, true); // BotÃƒÂ£o para baixo


    printButton("-", 200, 350, 250, 400, true); // BotÃƒÂ£o para cima
    printButton("+", 390, 350, 440, 400, true); // BotÃƒÂ£o para cima


    setFont(LARGE, 255, 255, 255, 0, 0, 0);
    myGLCD.print(":",140, 166);
    myGLCD.print(":",472, 166);

    setFont(LARGE, 255, 255, 255, 0, 0, 0);
    if (led_on_hora_t < 10)
    {
      myGLCD.print("0",54, 160);
      myGLCD.printNumI(led_on_hora_t, 88, 160);
    }
    else
    {
      myGLCD.printNumI(led_on_hora_t, 54, 160);
    }

    if (led_on_minuto_t < 10)
    {
      myGLCD.print("0", 196, 160);
      myGLCD.printNumI(led_on_minuto_t, 212, 160);
    }
    else
    {
      myGLCD.printNumI(led_on_minuto_t, 196, 160);
    }

    if (led_off_hora_t < 10)
    {
      myGLCD.print("0",386, 160);
      myGLCD.printNumI(led_off_hora_t, 402, 160);
    }
    else
    {
      myGLCD.printNumI(led_off_hora_t, 386, 166);
    }

    if (led_off_minuto_t < 10)
    {
      myGLCD.print("0",542, 160);
      myGLCD.printNumI(led_off_minuto_t, 558, 160);
    }
    else
    {
      myGLCD.printNumI(led_off_minuto_t, 542, 160);
    }

    if (amanhecer_anoitecer_t < 100)
    {
      myGLCD.print(" ", 272, 358);
      myGLCD.printNumI(amanhecer_anoitecer_t, 288, 358);
    }
    else
    {
      myGLCD.printNumI(amanhecer_anoitecer_t, 272, 358);
    }
    strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[252])));
    printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3]); // "PRONTO"

    myGLCD.setColor(0, 0, 0);
    myGLCD.fillRoundRect(1, 402, 798, 478);
  }
}
