//---------------------------------------------------------------------------------------------
void checkTempC()
{ 
  contador_temp ++;

  sensors.requestTemperatures();                                          // Chamada para todos os sensores.
  temperatura_agua_temp += (sensors.getTempC(sensor_agua));               // LÃƒÂª temperatura da ÃƒÂ¡gua
  temperatura_dissipador_temp += (sensors.getTempC(sensor_dissipador));   // LÃƒÂª temperatura do dissipador
  temperatura_ambiente_temp += (sensors.getTempC(sensor_ambiente));       // LÃƒÂª temperatura do dissipador

  if(contador_temp == 12)
  {
    tempC = temperatura_agua_temp / 12;
    tempH = temperatura_dissipador_temp / 12;
    tempA = temperatura_ambiente_temp / 12;
    
    tempC = (tempC * 1.8) + 32; /******************************************************** added for Fahrenheit *******************************************************************/
    tempH = (tempH * 1.8) + 32;
    tempA = (tempA * 1.8) + 32;
    
    contador_temp = 0;
    temperatura_agua_temp = 0;
    temperatura_dissipador_temp = 0;
    temperatura_ambiente_temp = 0;
  }

  if (tempC < (setTempC + offTempC + alarmTempC) && tempC > (setTempC - offTempC - alarmTempC)) 
  {
    bitWrite(status_parametros,2,0);
  }

  if (alarmTempC > 0)                        // Aciona alarme
  {
    if ((tempC >= (setTempC + offTempC + alarmTempC)) || (tempC <= (setTempC - offTempC - alarmTempC)))
    {
      bitWrite(status_parametros,2,1);
    }
  }

  if ((tempC < (setTempC + offTempC)) && (tempC > (setTempC - offTempC)))          // Desliga aquecedor e chieller
  {
    bitWrite(status_parametros,0,0);
    bitWrite(status_parametros,1,0);
    digitalWrite(aquecedorPin, LOW);
    digitalWrite(chillerPin, LOW);   
  }

  if (offTempC > 0)
  {
    if ((tempC > (setTempC + offTempC)))            // Liga o chiller
    {
      bitWrite(status_parametros,0,1);
      digitalWrite(chillerPin, HIGH);
    }
    if ((tempC < (setTempC - offTempC)))             // Liga o aquecedor
    {
      bitWrite(status_parametros,1,1);
      digitalWrite(aquecedorPin, HIGH);
    }
  }

  if ((tempC > 122) || (tempC <50))
     // ((tempC > 50) || (tempC <10))
  
  {
    bitWrite(status_parametros,0,0);
    bitWrite(status_parametros,1,0);
    digitalWrite(aquecedorPin, LOW);
    digitalWrite(chillerPin, LOW);
  }

  if ((bitRead(status_parametros, 0) == true) &&  (bitRead(status_parametros, 1) == true)) // Evita aquecedor e chiller ligados ao mesmo tempo.
  {
    bitWrite(status_parametros,0,0);
    bitWrite(status_parametros,1,0);
    digitalWrite(aquecedorPin, LOW);
    digitalWrite(chillerPin, LOW);
  }

  int tempval = int(tempH * 10);
  int fanSpeed = map(tempval, (HtempMin * 10), (HtempMax * 10), 0, 255);       // Controle de velocidade das ventoinhas do dissipador
  if (fanSpeed < 0)
  {  
    fanSpeed = 0;
  }    
  if (fanSpeed > 255)
  {
    fanSpeed = 255;
  }
  analogWrite(fanPin, fanSpeed);

  if(tempH < HtempMin) // Desativa os coolers se a temperatura estive abaixo da mÃƒÂ­nima definida.
  {
    digitalWrite(desativarFanPin, LOW);
  }
  else
  {
    digitalWrite(desativarFanPin, HIGH);
  }
}

void check_nivel() // Verifica o nÃƒÂ­vel do reef e fish only.
{
  if((analogRead(sensor5) > 400) ||(analogRead(sensor6) > 400) || (analogRead(sensor2) < 400) && (bitRead(tpa_status,1) == false))
  {
    nivel_status =true; // Sinaliza nivel baixo em um dos aquÃƒÂ¡rios ou sump
  }
  else 
  {
    nivel_status =false; // Sinaliza nÃƒÂ­vel normal dos aquÃƒÂ¡rios e sump
  }
}

void check_PH_reator()
{ 
  if (PHR < (setPHR + offPHR + alarmPHR) && PHR > (setPHR - offPHR - alarmPHR)) 
  {
    bitWrite(status_parametros,6,0);
  }
  if (alarmPHR > 0)           // Liga o alarme
  {
    if ((PHR > (setPHR + offPHR + alarmPHR)) || (PHR <= (setPHR - offPHR - alarmPHR)))
    {
      bitWrite(status_parametros,6,1);
    }
  }
  if (PHR < setPHR)       
  {
    bitWrite(status_parametros,5,0);
    digitalWrite(reatorPin, LOW);  // Desliga co2 do reator de cÃƒÂ¡lcio
  }
  if (offPHR > 0)
  {
    if (PHR > setPHR)    
    {
      bitWrite(status_parametros,5,1);
      digitalWrite(reatorPin, HIGH); // Liga co2 do reator de cÃƒÂ¡lcio
    }
  }
  if ((PHR < 4) || (PHR > 10))
  {
    bitWrite(status_parametros,5,0);
    digitalWrite(reatorPin, LOW);  // Desliga co2 do reator de cÃƒÂ¡lcio
  }     
}

void check_PH_aquario()
{ 
  if (PHA < (setPHA + offPHA + alarmPHA) && PHA > (setPHA - offPHA - alarmPHA)) 
  {
    bitWrite(status_parametros,3,0);
  }
  if (alarmPHA > 0)           // Liga o alarme
  {
    if ((PHA >= (setPHA + offPHA + alarmPHA)) || (PHA <= (setPHA - offPHA - alarmPHA)))
    {
      bitWrite(status_parametros,3,1);
    }
  }
  if (PHA < (setPHA - offPHA)) // Se PH do aquÃƒÂ¡rio menor que o desejado menos a variacao permitida. 
  {
    bitWrite(status_parametros,5,0);
    digitalWrite(reatorPin, LOW);  // Desliga co2 do reator de cÃƒÂ¡lcio
  }  
}

void check_densidade()
{ 
  if (DEN < (setDEN + offDEN + alarmDEN) && DEN > (setDEN - offDEN - alarmDEN)) 
  {
    bitWrite(status_parametros,4,0);
  }
  if (alarmDEN > 0)           // Liga o alarme
  {
    if ((DEN >= (setDEN + offPHR + alarmDEN)) || (DEN <= (setDEN - offDEN - alarmDEN)))
    {
      bitWrite(status_parametros,4,1);
    }
  }   
}

void check_ORP()
{ 
  if (ORP < (setORP + offORP + alarmORP) && ORP > (setORP - offORP - alarmORP)) 
  {
    bitWrite(status_parametros_1,0,0);
  }
  if (alarmORP > 0)            // Liga o alarme
  {
    if ((ORP >= (setORP + offORP + alarmORP)) || (ORP <= (setORP - offORP - alarmORP)))
    {
      bitWrite(status_parametros_1,0,1);
    }
  }
  if (ORP > setORP)    
  {
    bitWrite(status_parametros,7,0);    
    digitalWrite(ozonizadorPin, LOW);  // Desliga ozonizador
  }
  if (offORP > 0)
  {
    if (ORP < setORP)    
    {
      bitWrite(status_parametros,7,1);
      digitalWrite(ozonizadorPin, HIGH); // Liga ozonizador
    }
    if ((ORP < 100) || (ORP > 500))
    {
      bitWrite(status_parametros,7,0);
      digitalWrite(ozonizadorPin, LOW); // Desliga ozonizador
    }
  }
}
void check_alarme()
{
  if ((bitRead(status_parametros,2) == true) || (bitRead(status_parametros,3) == true) || (bitRead(status_parametros,4) == true) || 
    (bitRead(status_parametros,6) == true) || (bitRead(status_parametros_1,1)==true) || (bitRead(tpa_status,2) == true))
  {
    digitalWrite (alarmPin, HIGH);
  }
  else
  {
    digitalWrite (alarmPin, LOW);
  }
}

void reposicao_agua_doce () // abre a solenoide 1 se o nÃƒÂ­vel estiver baixo e se a tpa nÃƒÂ£o estiver em andamento
//e se o chiller estiver desligado e se o nÃƒÂ­vel do sump nÃƒÂ£o estiver anormal e se nÃƒÂ£o houve falha durante uma tpa.
{
  if((analogRead(sensor3) > 400) && (analogRead(sensor2) > 400) && (bitRead(tpa_status,1) == false) && (bitRead(status_parametros,0) == false) && (bitRead(tpa_status,2) == false))
  {
    PCF8575.digitalWrite(solenoide1Pin,HIGH);
    //digitalWrite(solenoide1Pin,HIGH);
    bitWrite(Status,1,1); //sinaliza reposiÃƒÂ§ÃƒÂ£o em andamento
  }
  else
  {
    PCF8575.digitalWrite(solenoide1Pin,LOW);
    //digitalWrite(solenoide1Pin,LOW);
    bitWrite(Status,1,0); // sinaliza reposiÃƒÂ§ÃƒÂ£o em andamento
  }
}




