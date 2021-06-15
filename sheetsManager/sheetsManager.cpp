/**
 *	Google Sheets Manager.
 *	@file		sheetsManager.h
 *	@author		dihordyross@gmail.com
 *	@version	1.0
 *	@date		30-06-2021
 *	@copyright	MTTL - Metalúrgica Laranjeiras.
 */
 
#include "Arduino.h"
#include "sheetsManager.h"
#include <HTTPClient.h>

// Construtor, chamado na inicializacao da biblioteca/classe
sheetsManager::sheetsManager(String googleScriptID){
	this->_googleScriptID = googleScriptID;
	
}


// --MÉTODOS--/**
/*  Publica dados em planilhas Google Sheets.
 *  @param  dados   Informação que se deseja publicar no formato: ("Nome1="
 *  @retval true    The entry successfully delete.
 *          false   Could not deleted.
 */
void IRAM_ATTR sheetsManager::publish(String dados){
	
	//Serial.println(dados);
	
	HTTPClient http;
    String url = "https://script.google.com/macros/s/" + _googleScriptID + "/exec?" + dados;
    http.begin(url, _root_ca); //Specify the URL and certificate
    int httpCode = http.GET();  
    http.end();
    //Serial.println(": done " + httpCode);
	
}

/*void SendAlarm(){// função para ativar alarme (examplo: portão aberto por mais de uma hora); poderá setar true no enableSendingEmails no google script
    sendData("alarm=fixme"); 
}*/