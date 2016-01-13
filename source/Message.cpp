#include "stdio.h"
#include "string.h"

#include "lwpsm/Message.h"

Message::Message() : data(NULL) {

}

Message::~Message() {
  if (data) {
    delete[] data;
  }
}

std::string Message::getType() {
  return type;
}

void Message::setType(std::string type) {
  this->type = type;
}

void Message::setData(char *data, size_t dataLength) {
  if (this->data) {
    delete[] data;
  }

  this->dataLength = dataLength;
  this->data = new char[dataLength];
  memcpy(this->data, data, dataLength);
}

char* Message::getData() {
  return data;
}

size_t Message::getDataLength() {
  return dataLength;
}
