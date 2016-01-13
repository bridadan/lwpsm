#include "stdio.h"
#include "lwpsm/MessageCenter.h"
#include "lwpsm/MessageBus.h"

class MockMessageBus : public MessageBus {
public:
  MockMessageBus() : didRead(false) {

  }

  void write(const char* data, int dataLength) {
    fwrite(data, dataLength, 1, stdout);
  }

  int read(char* dataBuffer, int dataBufferLength) {
    if (!didRead) {
      didRead = true;

      for (int i = 0; i < dataBufferLength; i++) {
        dataBuffer[i] = 'a' + ((char)(i % 25));
      }

      return dataBufferLength;
    } else {
      return 0;
    }
  }

private:
  bool didRead;
};

int main() {
  MessageCenter mc;
  MockMessageBus mmb;
  mc.addMessageBus(&mmb);
  mc.receiveData(&mmb);
  return 0;
}