#include "stdio.h"
#include <string>
#include "lwpsm/Message.h"

int main() {
  Message message;
  char myData[] = {0x01, 0x02, 0x03};
  std::string type = "event";

  message.setType(type);
  message.setData(myData, sizeof(myData));

  if (message.getType() != type) {
    printf("Bad type\r\n");
    return 1;
  }

  char* data = message.getData();
  int dataLength = message.getDataLength();


  if (dataLength != sizeof(myData)) {
    printf("Bad dataLength\r\n");
    return 1;
  }

  for (int i = 0; i < dataLength; i++) {
    if(data[i] != myData[i]) {
      printf("Bad data %d\r\n", i);
      return 1;
    }
  }

  return 0;
}