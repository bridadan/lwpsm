# Lightweight Publish/Subscribe Messaging

A simple C++ module that provides a transport-agnostic publish/subscribe messaging system.

## Organization

![Diagram](/docs/diagram.png)

### Classes

#### Message

This is the basic unit of communication. It has a "type" and "data".

#### MessageBus

This is an interface for reading and writing to a transport layer. This can be UART, I2C, SPI, UDP, TCP, anything that can fit this interface.

#### MessageCenter

The Message Center is what subscribes to different "types" of Messages. It also publishes Messages.

The Message Center is also responsible for managing the Message Buses. It will perform the following tasks:

1. Read and parse raw data from a Message Bus
2. Form it into a Message
3. Determine if it is subscribed to the current Message's type
4. If so, call the appropriate callback function. Otherwise, discard the message.


## Testing

Testing is currently limited as the module is incomplete. More tests will come soon.

In the root of the module, run the following command:

```
yotta test
```