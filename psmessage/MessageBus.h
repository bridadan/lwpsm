#ifndef MESSAGE_BUS_H
#define MESSAGE_BUS_H

class MessageBus {
public:
  virtual void write(const *char data, int dataLength) = 0;
  virtual int read(*char dataBuffer, int dataBufferLength) = 0;
};

#endif