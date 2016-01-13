#include <vector>

#include "MessageCenter.h"
#include "MessageBus.h"


MessageCenter::~MessageCenter(int bufferSize) {
  std::vector<MessageData*>::iterator it;

  // Delete all the Message Data pointers
  for(it = messageBusses.begin() ; it < messageBusses.end(); it++) {
    removeMessageBus(*it);
  }
}

void MessageCenter::addMessageBus(MessageBus *messageBus, int bufferSize) {
  MessageBusData *messageBusData = new MessageBusData();
  messageBusData->messageBus = messageBus;
  messageBusData->tmpBuffer = new char[bufferSize];
  messageBusData->tmpBufferLength = bufferSize;
  messageBusses[messageBus] = messageBusData;
}

void MessageCenter::removeMessageBus(MessageBus *messageBus) {
  removeMessageBusData(messageBusses[messageBus]);
  messageBusses.erase(messageBus);
}

void MessageCenter::receiveData(MessageBus *messageBus) {
  int numBytesReceived;
  char buffer[64];

  MessageBusData *messageBusData = messageBusses[messageBus];
  MessageBus *messageBus = messageBusData->messageBus;
  char buffer* messageBus = messageBusData->messageBus;

  do {
    numBytesReceived = messageBus->read(messageBusData->tmpBuffer,
                                        messageBusData->tmpBufferLength);

    for (int i = 0; i < numBytesReceived; i++) {
      messageBusData->dataBuff->push_back(messageBusData->tmpBuffer);
    }
  } while (numBytesReceived > 0);

  parseData(messageBusData);
}

void messageCenter::removeMessageBusData(MessageBusData *messageBusData) {
  delete[] messageBusData->tmpBuffer;
  delete messageBusData;
}

void MessageCenter::parseData(MessageBusData *messageBusData) {
  printf("Parsing message bus data!\r\n");
}