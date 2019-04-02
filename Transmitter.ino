#define RH_MESH_MAX_MESSAGE_LEN 50

#include <RHMesh.h>
#include <RH_ASK.h>
#include <SPI.h>

#define CLIENT_ADDRESS 1
#define SERVER1_ADDRESS 2

RH_ASK driver(2000, A5, 11);
RHMesh manager(driver, CLIENT_ADDRESS);

void setup()
{
  Serial.begin(9600);
  if (!manager.init())
    Serial.println("init failed");
}

uint8_t data[] = "Hello Mesh World!";
// Dont put this on the stack:
uint8_t buf[RH_MESH_MAX_MESSAGE_LEN];

void loop()
{
  //uint8_t arp = manager.doArp(SERVER1_ADDRESS);
  //Serial.println(arp)

  Serial.println("Sending to manager_mesh_node_b");

  // Send a message to a ask_mesh_server
  // A route to the destination will be automatically discovered.

  uint8_t code = manager.sendtoWait(data, sizeof(data), SERVER1_ADDRESS);
  Serial.println(code);
  //Serial.println(RH_ROUTER_ERROR_NONE);

  if (code == RH_ROUTER_ERROR_NONE || code == 2)
  {
    // It has been reliably delivered to the next node.
    // Now wait for a reply from the ultimate server
    Serial.println("route was found");
    uint8_t len = sizeof(buf);
    uint8_t from;
    if (manager.recvfromAckTimeout(buf, &len, 10000, &from))
    {
      Serial.print("got reply from : 0x");
      Serial.print(from, HEX);
      Serial.print(": ");
      Serial.println((char *)buf);
    }
    else
    {
      Serial.println("No reply, is ask_mesh_node_b running?");
    }
  }
  else
    Serial.println("sendtoWait failed. Are the intermediate mesh servers running?");
}
