#ifndef MESSAGE_CENTER_H
#define MESSAGE_CENTER_H

#include <vector>
#include <deque>

class MessageCenter {
  ~MessageCenter();
  void addMessageBus(MessageBus *messageBus, int bufferSize = 64);
  void removeMessageBus(MessageBus *messageBus, int bufferSize = 64);
  void receiveData(MessageBus *messageBus);

private:
  struct MessageBusData {
    MessageBus *messageBus;
    char *tmpBuffer;
    int tmpBufferLength;
    std::deque<char> dataBuffer;
  };

  void removeMessageBusData(MessageBusData* messageBusData);
  void parseData(MessageBusData* messageBusData);

  std::map<MessageBus*, MessageBusData*> messageBusses;
};

#endif