#include <RH_ASK.h>
#include <SPI.h> // Not actually used but needed to compile
#include <MD5.h> // source is https://github.com/tzikis/ArduinoMD5


RH_ASK driver(2000, A5, 11); // Setting RX pin (receiver) to A5 and TX pin (transmitter) to 11
char *messageHashs[10];  

void setup()
{
  Serial.begin(9600);
  if (!driver.init())
    Serial.println("driver init failed");
}

void loop()
{ 
  driver.setModeRx();

  uint8_t buf[12];
  uint8_t buflen = sizeof(buf);

  if (driver.recv(buf, &buflen)) // Non-blocking
  {
     Serial.print("message received: ");
     Serial.println((char *)buf);
      
     unsigned char* messageHash=MD5::make_hash((char *)buf);
     char *md5str = MD5::make_digest(messageHash, 16);
     free(messageHash);
    
     if (!hashAlreadyExists(md5str) || true){

      storeHash(md5str);

      driver.setModeTx();

      driver.send(buf, buflen);
      driver.waitPacketSent();

      Serial.println("forwarded received message");
      Serial.println("");
    } else {
        Serial.println("ignored already received message");
      }
  }
}


boolean hashAlreadyExists(unsigned char *hash){
    for (int i = 0; i < 10; i++){
      if (strcmp(*hash, *messageHashs[i]) == 0){
        return true;
      }
    }
    return false;
}

void storeHash(char *hash){
  for (int i = 0; i < 10; i++){
    if (i == 9){
      messageHashs[i] = hash;
    } else{
      messageHashs[i]= messageHashs[i+1];
    }   
  }
}


// what about reliable sending if we only send it to the mother ship? 
// we need to implement that ourselves I guess 
