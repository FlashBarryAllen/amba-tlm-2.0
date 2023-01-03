# amba-tlm-1.0

cd $path/lib/

export LD_LIBRARY_PATH=$(pwd)

TLM实现不同模块之间通信的3步曲：
1. make use of TLM-2.0 core interfaces and sockets.
   So each TLM-2.0 initiator and target sockets will instantiate
   a socket and the sockets do a lot of function calls using the core
   interfaces
2. make use of the generic payload.
   the generic payload catches a set of attributes that a typiclal of memory
   and buses. So it's a generic payload transaction has passed through the
   sockets between the various TLM components.
3. use the base protocol.
   So the base protocol defines a set of phases marking
   the beginning and the end of of request and response and captures a set of
   rules that are used by the initiator and target when making function calls
   through those standard sockets and passing that standard generic payload 
   backwards and forwards.
   
non-blocking transport:
1. support calls on both the forward path and backward path.
   non-blocking transport is a multiple phases where a single transaction
   involes multiple calls nb transport. Some calling in forward direction,
   and some calling in backward direction. Allows more transaction and more
   timing resolution and sacrifice some simulation speed.
2. use AT coding style
