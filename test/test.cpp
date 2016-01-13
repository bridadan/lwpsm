#include "stdio"
#include "psmessage/MessageCenter.h"
#include "psmessage/MessageBus.h"

class MockMessageBus : public MessageBus {
  void write(const *char data, int dataLength) {
    fwrite(data, dataLength, 1, stdout);
  }

  int read(*char dataBuffer, int dataBufferLength) {
    for (int i = 0; i < dataBufferLength; i++) {
      dataBuffer[i] = 'a' + ((char)(i % 25));
    }
  }
};

int main() {
  MessageCenter mc;
  MockMessageBus mmb;
  mc.addMessageBus(&mmb);

  mc.receiveData(&mmb);
  return 0;
}