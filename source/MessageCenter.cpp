#include <vector>
#include "stdio.h"
#include "lwpsm/MessageCenter.h"
#include "lwpsm/MessageBus.h"


MessageCenter::~MessageCenter() {
  std::map<MessageBus*, MessageBusData*>::iterator it;

  // Delete all the Message Data pointers
  for(it = messageBuses.begin() ; it != messageBuses.end(); it++) {
    removeMessageBus(it->first);
  }
}

void MessageCenter::addMessageBus(MessageBus *messageBus, int bufferSize) {
  MessageBusData *messageBusData = new MessageBusData();
  messageBusData->messageBus = messageBus;
  messageBusData->tmpBuffer = new char[bufferSize];
  messageBusData->tmpBufferLength = bufferSize;
  messageBuses[messageBus] = messageBusData;
}

void MessageCenter::removeMessageBus(MessageBus *messageBus) {
  removeMessageBusData(messageBuses[messageBus]);
  messageBuses.erase(messageBus);
}

void MessageCenter::receiveData(MessageBus *messageBus) {
  int numBytesReceived;
  char buffer[64];

  MessageBusData *messageBusData = messageBuses[messageBus];

  do {
    numBytesReceived = messageBus->read(messageBusData->tmpBuffer,
                                        messageBusData->tmpBufferLength);

    for (int i = 0; i < numBytesReceived; i++) {
      messageBusData->dataBuffer.push_back(messageBusData->tmpBuffer[i]);
    }
  } while (numBytesReceived > 0);

  parseData(messageBusData);
}

void MessageCenter::removeMessageBusData(MessageCenter::MessageBusData *messageBusData) {
  if (messageBusData->tmpBuffer) {
    delete[] messageBusData->tmpBuffer;
  }

  if (messageBusData) {
    delete messageBusData;
  }

}

void MessageCenter::parseData(MessageBusData *messageBusData) {
}