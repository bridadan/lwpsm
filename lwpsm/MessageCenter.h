#ifndef MESSAGE_CENTER_H
#define MESSAGE_CENTER_H

#include <map>
#include <deque>
#include <string>

#include "MessageBus.h"
#include "Message.h"

class MessageCenter {
public:
  ~MessageCenter();
  void addMessageBus(MessageBus *messageBus, int bufferSize = 64);
  void removeMessageBus(MessageBus *messageBus);
  void receiveData(MessageBus *messageBus);

  void subscribe(std::string, void (*callback)(Message*));
  void publish(Message *msg);

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

  static const char messageStartByte = '%';
};

#endif