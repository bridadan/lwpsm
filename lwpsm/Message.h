#include <string>

class Message {
public:
  Message();
  ~Message();

  std::string getType();
  void setType(std::string type);

  char* getData();
  size_t getDataLength();
  void setData(char *data, size_t dataLength);

  std::string type;
  char *data;
  size_t dataLength;
};