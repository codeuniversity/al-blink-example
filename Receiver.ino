#define RH_MESH_MAX_MESSAGE_LEN 50

#include <RHMesh.h>
#include <RH_ASK.h>
#include <SPI.h>

#define CLIENT_ADDRESS 1
#define SERVER1_ADDRESS 2

RH_ASK driver(2000, A5, 11);

RHMesh manager(driver, SERVER1_ADDRESS);

void setup()
{
  Serial.begin(9600);
  if (!manager.init())
    Serial.println("init failed");
}

uint8_t data[] = "And hello back to you from node_b";
uint8_t buf[RH_MESH_MAX_MESSAGE_LEN];

void loop()
{
  //uint8_t arp = manager.doArp(SERVER1_ADDRESS);
  //Serial.println(arp)

  uint8_t len = sizeof(buf);
  uint8_t from;
  if (manager.recvfromAck(buf, &len, &from))
  {
    Serial.print("got request from : 0x");
    Serial.print(from, HEX);
    Serial.print(": ");
    Serial.println((char *)buf);
    // Send a reply back to the originator client
    uint8_t code = manager.sendtoWait(data, sizeof(data), from);
    Serial.println(code);
    if (code != RH_ROUTER_ERROR_NONE)
      Serial.println("sendtoWait failed");
  }
}
