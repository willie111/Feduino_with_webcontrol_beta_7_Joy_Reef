void tempgScreen()//------------------------------------------------------------ tela =11
{
  int x, y, z, grafico;
  int16_t n;
  char buf[8];
  float temperatura;
  int j = 0;
  int i = 0;
  int k = 0;
  float soma = 0.0f; // Soma dos valores de todos os elementos
  float media = 0.0f; // MÃƒÂ©dia dos valores
  float linhaR;
  float linhaG;
  float linhaB;
  int f = 60;

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[25])));
  printHeader(buffer); // tabela_textos[25] = "GRAFICO DE TEMPERATURA DA AGUA"

  setFont(LARGE, 255, 255, 255, 0, 0, 0);

  for(float i = 81; i > 75.5; i -= .5)   // Fahrenheit scale 81---75.5
   //(float i = 27.5; i > 22; i -= .5) // Celsius scale 27.5--22 
  {
    myGLCD.printNumF(i, 1, 5, 3 + f);
    f += 30; 
  }

  f = 510;
  for(int i = 22; i > 0; i -= 2)
  {
    myGLCD.printNumI(i, f, 386);
    f -= 40;
  }

  myGLCD.print("0", 550, 386); 
  myGLCD.drawCircle(30, 42, 2);
  myGLCD.print("F", 40, 36);  
  //myGLCD.print("C", 20, 18);
  myGLCD.print("HOUR", 580, 386);

  myGLCD.drawLine(80, 60, 80, 380); // Eixo y
  myGLCD.drawLine(80, 380, 580, 380);  // Eixo x

  myGLCD.setColor(64, 64, 64);  // Malha

  //EIXO X
  for(int k=80; k<360; k+=30)
  {
    myGLCD.drawLine(80, k, 580, k);
  }

  //EIXO Y
  for(int l=120; l<600; l+=40)
  {
    myGLCD.drawLine(2, 60, 2, 380);
  }
/***********************************************CELSIUS******************************/
/**************************************************************************** changed for Fahrenheit *******************************************************************/
  /*
  linhaR =setTempC;   //  Linhas de comparaÃƒÂ§ÃƒÂ£o
  linhaG =(setTempC+offTempC);
  linhaB = (setTempC-offTempC);

  if ((linhaR >= 22.5) && (linhaR <= 27.5))
  {
    x= (190 - ((linhaR - 22.5) * 30));
  }
  else if (linhaR > 27.5)
  {
    x = 30;
  }
  else if (linhaR < 22.5)
  {
    x = 190;
  }

  if ((linhaG >= 22.5) && (linhaG <= 27.5))
  {
    y = (190-((linhaG - 22.5) * 30));
  }
  else if (linhaG > 27.5)
  {
    y = 30;
  }
  else if (linhaG < 22.5)
  {
    y = 190;
  }

  if ((linhaB >= 22.5) && (linhaB <= 27.5))
  {
    z = (190 -((linhaB - 22.5) * 30));
  }
  else if (linhaB > 27.5)
  {
    z = 30;
  }
  else if (linhaB < 22.5)
  {
    z = 190;
  }
  
  */
  
  /********************************************************************** added for Fahrenheit *******************************************************************/
  /********************************************* FAHRENHEIT ****************************************/
    linhaR =setTempC;                  //  lines compared
  linhaG =(setTempC+offTempC);
  linhaB = (setTempC-offTempC);

  if ((linhaR >= 75.5) && (linhaR <= 81))
    x= (380 - ((linhaR - 75.5) * 60));

  else if (linhaR > 81)
    x = 60;

  else if (linhaR < 75.5)
    x = 380;

  if ((linhaG >= 75.5) && (linhaG <= 81))
    y = (380-((linhaG - 75.5) * 60));

  else if (linhaG > 81)
    y = 60;

  else if (linhaG < 75.5)
    y = 380;

  if ((linhaB >= 75.5) && (linhaB <= 81))
    z = (380 -((linhaB - 75.5) * 60));

  else if (linhaB > 81)
    z = 60;

  else if (linhaB < 75.5)
    z = 380;
    
//--------------------------------------------end F or C -----------------------------------------------//
  

  myGLCD.setColor(255, 0, 0);
  myGLCD.drawLine(80, x, 580, x);// Temperatura desejada
  myGLCD.setColor(10, 10, 255);        // VariaÃƒÂ§ÃƒÂ£o permitida
  myGLCD.drawLine(80, y, 580, y); // VariaÃƒÂ§ÃƒÂ£o mais
  myGLCD.drawLine(80, z, 580, z); // VariaÃƒÂ§ÃƒÂ£o menos

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[11])));
  printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3]); 

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[1])));
  printButton(buffer, menU[0], menU[1], menU[2], menU[3]);

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[66])));
  printButton(buffer, volT[0], volT[1], volT[2], volT[3]);

  setFont(SMALL, 255, 255, 0, 0, 0, 0);

  int d = 82 + (NumMins(t.hour,t.min) / 3);

  myGLCD.drawLine(d, 30, d, 380); // Linha de marcaÃƒÂ§ÃƒÂ£o do horÃƒÂ¡rio.
  myGLCD.print(rtc.getTimeStr(FORMAT_SHORT), d + 2, 75, 270);

  file.open(&root, "LOGTDIA.TXT", O_READ);
  while ((n = file.read(buf, sizeof(buf))) > 0)
  {
    temperatura = atof(buf);
    soma +=temperatura;

    if(strlen(buf) == 5)
    {
      i++;
      k++;
    }

    if (temperatura <= 2 )
    {
      k -= 1;
    }

    if (i == 6)
    {
      media = soma / k;
      i = 0;
      j++;
      soma = 0;
      k = 0;
/********************************************************************** added for Fahrenheit *******************************************************************/
      //if ((media) > 27.5)
      if ((media) > 81)
      {
        grafico = 60;
      }
      //else if ((media >= 22.5) && (media <= 27.5))
      else if ((media >= 75.5) && (media <= 81))
      {
        //grafico = (190 -((media - 22.5) * 30));
        grafico = (380 -((media - 75.5) * 30));
      }
      else
      {
        grafico = 380;
      }
      setFont(SMALL, 255, 0, 255, 0, 0, 0);

      if(j < 250)
      {
        myGLCD.drawPixel((40 + j), grafico);
      }
    }
  }
  file.close();
}

void orpScreen()//------------------------------------------------------------tela =12
{
  int x, y, z;
  int orp = setORP;
  int orpmais = offORP;
  int orpmenos = offORP;
  float linhaR;
  float linhaG;
  float linhaB;
  int j = 0;
  int i = 0;
  int k = 0;
  int soma = 0; // soma dos valores de todos os elementos
  int media = 0; // mÃƒÂ©dia dos valores.
  int grafico;
  int16_t n;
  char buf[6];
  int redox;
  int f = 60;

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[26])));
  printHeader(buffer); // tabela_textos[26] = "GRAFICO DE ORP"
  setFont(LARGE, 255, 255, 255, 0, 0, 0);

  for(int i = 480; i > 160; i -= 30)
  {
    myGLCD.printNumI(i, 10, 3 + f);
    f += 30; 
  }

  f = 510;
  for(int i = 22; i > 0; i -= 2)
  {
    myGLCD.printNumI(i, f, 396);
    f -= 40;
  }
  myGLCD.print("0", 550, 396);    
  myGLCD.print("MV", 36, 36);
  myGLCD.print("H", 580, 396);
  myGLCD.drawLine(80, 380, 580, 380);  //eixo x
  myGLCD.drawLine(80, 60, 80, 380); //eixo y

  myGLCD.setColor(64, 64, 64);                    //malha

  //EIXO X
  for(int k=80; k<360; k+=30)
  {
    myGLCD.drawLine(80, k, 580, k);
  }

  //EIXOY
  for(int l = 1200; l<600; l+=40)
  {
    myGLCD.drawLine(2, 60, 2, 380);
  } 

  linhaR = orp;       //  Linhas de comparacao
  linhaG =(orp + orpmais);
  linhaB = (orp - orpmenos);

  if ((linhaR >= 180) && (linhaR <= 480))
  {
    x = (380 - ((linhaR - 180) * 0.5));
  }
  else if (linhaR > 480)
  {
    x = 60;
  }
  else if (linhaR < 180)
  {
    x = 380;
  }

  if ((linhaG > 180) && (linhaG <= 480))
  {
    y = (380 - ((linhaG - 180) * 0.5));
  }
  else if (linhaG > 480)
  {
    y = 60;
  }
  else if (linhaG < 180)
  {
    y = 380;
  }

  if ((linhaB > 180) && (linhaB <= 480))
  {
    z = (380 - ((linhaB - 180) * 0.5));
  }
  else if (linhaB > 480)
  {
    z = 60;
  }
  else if (linhaB < 180)
  {
    z = 380;
  }

  myGLCD.setColor(255, 0, 0);
  myGLCD.drawLine(80, x, 580, x);//Temperatura desejada
  myGLCD.setColor(10, 10, 255);        //Variacao permitida
  myGLCD.drawLine(80, y, 580, y); //variacao mais
  myGLCD.drawLine(80, z, 580, z); //variacao menos

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[11])));
  printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3]); 

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[1])));
  printButton(buffer, menU[0], menU[1], menU[2], menU[3]);

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[66])));
  printButton(buffer, volT[0], volT[1], volT[2], volT[3]);

  setFont(SMALL, 255, 255, 0, 0, 0, 0);

  int d = 82 + (NumMins(t.hour,t.min) / 3);

  myGLCD.drawLine(d, 30, d, 380); // Linha de marcaÃƒÂ§ÃƒÂ£o do horÃƒÂ¡rio.
  myGLCD.print(rtc.getTimeStr(FORMAT_SHORT), d + 2, 75, 270);

  file.open(&root, "LOGODIA.TXT", O_READ);
  while ((n = file.read(buf, sizeof(buf))) > 0)
  {
    redox = atoi(buf);
    soma +=redox;


    if(strlen(buf)==3)
    {
      i++;
      k++;
    }

    if (redox <= 2 )
    {
      k -= 1;
    }

    if (i==6)
    {
      media = soma / k;
      i = 0;
      j++;
      soma = 0;
      k = 0;

      if ((media) < 180)
      {
        grafico = 380;
      }
      else if ((media) > 480)
      {
        grafico = 60;
      }
      else if ((media >= 180) && (media <= 480))
      {
        grafico = (380 - ((media - 180) * 0.5));
      }
      setFont(SMALL, 255, 0, 255, 0, 0, 0);

      if(j < 250)
      {
        myGLCD.drawPixel((40 + j), grafico);
      }
    }
  }
  file.close();
}
void PHAScreen()//-------------------------------ph do aqua-----------------------------tela =13
{
  float x, y, z;
  float ph = setPHA;
  float phmais = offPHA;
  float phmenos = offPHA;
  float linhaR;
  float linhaG;
  float linhaB;
  int j = 0;
  int i = 0;
  int k = 0;
  float soma = 0.0f; // soma dos valores de todos os elementos
  float media = 0.0f; // mÃƒÂ©dia dos valores.
  int grafico;
  int16_t n;
  char buf[7];
  float pht;
  int f = 60;

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[27])));
  printHeader(buffer); //tabela_textos[27] = "GRAFICO DE PH DO AQUARIO"
  setFont(LARGE, 255, 255, 255, 0, 0, 0);

  for(float i = 9; i > 6.9; i -= 0.2)
  {
    myGLCD.printNumF(i, 1, 10, 3 + f);
    f += 30; 
  }

  f = 510;
  for(int i = 22; i > 0; i -= 2)
  {
    myGLCD.printNumI(i, f, 386);
    f -= 40;
  }
  myGLCD.print("0", 550, 386);   
  myGLCD.print("PH", 34, 36);
  myGLCD.print("H", 580, 386);

  myGLCD.drawLine(80, 60, 80, 380); //eixo y
  myGLCD.drawLine(80, 380, 580, 380);  //eixo x

  myGLCD.setColor(64, 64, 64);            //malha
  //EIXO X
  for(int k=80; k<360; k+=30)
  {
    myGLCD.drawLine(80, k, 580, k);
  }

  //EIXOY
  for(int l= 120; l < 600; l += 40)
  {
    myGLCD.drawLine(2, 60, 2, 380);
  }

  linhaR =ph;  //  Linhas de comparacao
  linhaG =ph+phmais;
  linhaB =ph-phmenos;

  if ((linhaR >= 7) && (linhaR <= 9))
  {
    x= 380 - ((linhaR - 7) * 75);
  }
  else if (linhaR > 9)
  {
    x = 60;
  }
  else if (linhaR < 7)
  {
    x = 380;
  }

  if ((linhaG >= 7) && (linhaG <= 9))
  {
    y= 380 - ((linhaG - 7) * 75);
  }
  else if (linhaG > 9)
  {
    y = 60;
  }
  else if (linhaG < 7)
  {
    y = 380;
  }

  if ((linhaB >= 7) && (linhaB <= 9))
  {
    z= 380 - ((linhaB - 7) * 75);
  }
  else if (linhaB > 9)
  {
    z = 60;
  }
  else if (linhaB < 7)
  {
    z = 380;
  }

  myGLCD.setColor(255, 0, 0);
  myGLCD.drawLine(80, x, 580, x);//PH desejado
  myGLCD.setColor(10, 10, 255);  //Variacao permitida
  myGLCD.drawLine(80, y, 580, y); //variacao mais
  myGLCD.drawLine(80, z, 580, z); //variacao menos

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[11])));
  printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3],false); 

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[1])));
  printButton(buffer, menU[0], menU[1], menU[2], menU[3], false);

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[66])));
  printButton(buffer, volT[0], volT[1], volT[2], volT[3],false);

  setFont(SMALL, 255, 255, 0, 0, 0, 0);

  int d = 82 + (NumMins(t.hour,t.min) / 3);

  myGLCD.drawLine(d, 60, d, 380); // Linha de marcaÃƒÂ§ÃƒÂ£o do horÃƒÂ¡rio.
  myGLCD.print(rtc.getTimeStr(FORMAT_SHORT), d + 2, 75, 270);

  file.open(&root, "LOGPDIA.TXT", O_READ);
  while ((n = file.read(buf, sizeof(buf))) > 0)
  {
    pht = atof(buf);
    soma +=pht;

    if(strlen(buf)==4)
    {
      i++;
      k++;
    }

    if (pht <= 2 )
    {
      k -= 1;
    }

    if (i==6)
    {
      media = soma / k;
      i = 0;
      j++;
      soma = 0;
      k = 0;

      if ((media) > 9)
      {
        grafico = 60;
      }
      else if ((media >= 7) && (media <= 9))
      {
        grafico = (380-((media-7)* 75));
      }
      else
      {
        grafico = 380;
      }
      setFont(SMALL, 255, 0, 255, 0, 0, 0);

      if(j < 250)
      {
        myGLCD.drawPixel((40 + j), grafico);
      }
    }
  }
  file.close();
}

void PHRScreen()//----------------PH do reator --------------------------------------------tela =17
{
  float x, y, z;
  float ph = setPHR;
  float phmais = offPHR;
  float phmenos = offPHR;
  float linhaR;
  float linhaG;
  float linhaB;
  int j = 0;
  int i = 0;
  int k = 0;
  float soma = 0.0f; // soma dos valores de todos os elementos
  float media = 0.0f; // mÃƒÂ©dia dos valores.
  int grafico;
  int16_t n;
  char buf[7];
  float pht;
  int f = 60;

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[28])));
  printHeader(buffer); //tabela_textos[28] = "GRAFICO DE PH DO REATOR DE CALCIO"

  setFont(LARGE, 255, 255, 255, 0, 0, 0);

  for(float i = 7.4; i > 5.3; i -= 0.2)
  {
    myGLCD.printNumF(i, 1, 10, 3 + f);
    f += 30; 
  }

  f = 510;
  for(int i = 22; i > 0; i -= 2)
  {
    myGLCD.printNumI(i, f, 386);
    f -= 40;
  }
  myGLCD.print("0", 550, 386);   
  myGLCD.print("PH", 34, 36);
  myGLCD.print("H", 580, 386);

  myGLCD.drawLine(80, 60, 80, 380); //eixo y
  myGLCD.drawLine(80, 380, 580, 380);  //eixo x

  myGLCD.setColor(64, 64, 64);            //malha

  //EIXO X
  for(int k=80; k<380; k+=30)
  {
    myGLCD.drawLine(80, k, 580, k);
  }

  //EIXOY
  for(int l=120; l<600; l+=40)
  {
    myGLCD.drawLine(2, 60, 2, 380);
  }

  linhaR =ph;  //  Linhas de comparacao
  linhaG =ph+phmais;
  linhaB =ph-phmenos;

  if ((linhaR>=5.4) && (linhaR<=7.4))
  {
    x= 380-((linhaR-5.4)*75);
  }
  else if (linhaR >7.4)
  {
    x=60;
  }
  else if (linhaR <5.4)
  {
    x=380;
  }

  if ((linhaG >= 5.4) && (linhaG <= 7.4))
  {
    y= 380 - ((linhaG-5.4) * 75);
  }
  else if (linhaG > 7.4)
  {
    y = 60;
  }
  else if (linhaG < 5.4)
  {
    y = 380;
  }

  if ((linhaB >= 5.4) && (linhaB <= 7.4))
  {
    z = 380 -((linhaB - 5.4) * 75);
  }
  else if (linhaB > 7.4)
  {
    z = 60;
  }
  else if (linhaB < 5.4)
  {
    z = 380;
  }
  myGLCD.setColor(255, 0, 0);
  myGLCD.drawLine(80, x, 580, x);//PH desejado
  myGLCD.setColor(10, 10, 255);  //Variacao permitida
  myGLCD.drawLine(80, y, 580, y); //variacao mais
  myGLCD.drawLine(80, z, 580, z); //variacao menos

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[11])));
  printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3],false); 

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[1])));
  printButton(buffer, menU[0], menU[1], menU[2], menU[3], false);

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[66])));
  printButton(buffer, volT[0], volT[1], volT[2], volT[3],false);

  setFont(SMALL, 255, 255, 0, 0, 0, 0);

  int d = 82 + (NumMins(t.hour,t.min)/3);

  myGLCD.drawLine(d, 60, d, 380); // Linha de marcaÃƒÂ§ÃƒÂ£o do horÃƒÂ¡rio.
  myGLCD.print(rtc.getTimeStr(FORMAT_SHORT), d + 2, 75, 270);

  file.open(&root, "LOGRDIA.TXT", O_READ);
  while ((n = file.read(buf, sizeof(buf))) > 0)
  {
    pht = atof(buf);
    soma += pht;

    if(strlen(buf) == 4)
    {
      i++;
      k++;
    }
    if (pht <= 2 )
    {
      k -= 1;
    }
    if (i==6)
    {
      media = soma / k;
      i = 0;
      j++;
      soma = 0;
      k = 0;

      if ((media) > 7.4)
      {
        grafico = 60;
      }
      else if ((media >= 5.4) && (media <= 7.4))
      {
        grafico = (380 - ((media - 5.4) * 75));
      }
      else
      {
        grafico = 380;
      }
      setFont(SMALL, 255, 0, 255, 0, 0, 0);

      if(j < 250)
      {
        myGLCD.drawPixel((40 + j), grafico);
      }
    }
  }
  file.close();
}

void densidadeScreen()//----------------grafico de densidade --------------------------------------------tela =19
{
  float x, y, z;
  float dens = setDEN;
  float densmais = offDEN;
  float densmenos = offDEN;
  float linhaR;
  float linhaG;
  float linhaB;
  int j = 0;
  int i = 0;
  int k = 0;
  int soma = 0; // soma dos valores de todos os elementos
  int media = 0; // mÃƒÂ©dia dos valores.
  int grafico;
  int16_t n;
  char buf[7];
  int densidade;
  int f = 60;

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[29])));
  printHeader(buffer); //tabela_textos[29] = "GRAFICO DE DENSIDADE"

  setFont(LARGE, 255, 255, 255, 0, 0, 0);

  for(int i = 1030; i > 1008; i -= 2)
  {
    myGLCD.printNumI(i, 12, 3 + f);
    f += 30; 
  }

  f = 530;
  for(int i = 22; i > 0; i -= 2)
  {
    myGLCD.printNumI(i, f, 386);
    f -= 40;
  }

  myGLCD.print("0", 570, 386);   
  myGLCD.print("DENS.", 24, 36);
  myGLCD.print("H", 600, 386);

  myGLCD.drawLine(100, 60, 100, 380); //eixo y
  myGLCD.drawLine(100, 380, 600, 380);  //eixo x
  //EIXO X
  myGLCD.setColor(64, 64, 64);            //malha

  //EIXO X
  for(int k=80; k<380; k+=30)
  {
    myGLCD.drawLine(100, k, 600, k);
  }

  //EIXOY
  for(int l=140; l < 600; l+=40)
  {
    myGLCD.drawLine(2, 60, 2, 380);
  }


  linhaR = dens;  //  Linhas de comparacao
  linhaG = dens + densmais;
  linhaB = dens - densmenos;

  if ((linhaR >= 1010) && (linhaR <= 1030))
  {
    x= 380 - ((linhaR - 1010) * 7.5);
  }
  else if (linhaR > 1030)
  {
    x = 60;
  }
  else if (linhaR < 1010)
  {
    x = 380;
  }

  if ((linhaG >= 1010) && (linhaG <= 1030))
  {
    y= 380 - ((linhaG - 1010) * 7.5);
  }
  else if (linhaG >1030)
  {
    y = 60;
  }
  else if (linhaG < 1010)
  {
    y = 318;
  }

  if ((linhaB >= 1010) && (linhaB <= 1030))
  {
    z = 380 - ((linhaB - 1010) * 7.5);
  }
  else if (linhaB > 1030)
  {
    z = 60;
  }
  else if (linhaB < 1010)
  {
    z = 380;
  }
  myGLCD.setColor(255, 0, 0);
  myGLCD.drawLine(100, x, 600, x);//PH desejado
  myGLCD.setColor(10, 10, 255);  //Variacao permitida
  myGLCD.drawLine(100, y, 600, y); //variacao mais
  myGLCD.drawLine(100, z, 600, z); //variacao menos

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[11])));
  printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3],false); 

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[1])));
  printButton(buffer, menU[0], menU[1], menU[2], menU[3], false);

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[66])));
  printButton(buffer, volT[0], volT[1], volT[2], volT[3],false);

  setFont(SMALL, 255, 255, 0, 0, 0, 0);

  int d = 102 + (NumMins(t.hour,t.min)/3);

  myGLCD.drawLine(d, 60, d, 380); // Linha de marcaÃƒÂ§ÃƒÂ£o do horÃƒÂ¡rio.
  myGLCD.print(rtc.getTimeStr(FORMAT_SHORT), d + 2, 75, 270);

  file.open(&root, "LOGDDIA.TXT", O_READ);
  while ((n = file.read(buf, sizeof(buf))) > 0)
  {
    densidade = atof(buf);
    soma +=densidade;

    if(strlen(buf)==4)
    {
      i++;
      k++;
    }
    
    if (densidade <= 2 )
    {
      k -= 1;
    }
    
    if (i == 6)
    {
      media = soma / k;
      i = 0;
      j++;
      soma = 0;
      k = 0;

      if ((media) < 1010)
      {
        grafico = 380;
      }
      else if ((media) > 1030)
      {
        grafico = 60;
      }
      else if (1010 <= media <= 1030)
      {
        grafico = (380 - ((media - 1010) * 7.5));
      }
      setFont(SMALL, 255, 0, 255, 0, 0, 0);

      if(j < 250)
      {
        myGLCD.drawPixel((50 + j), grafico);
      }
    }
  }
  file.close();
}





