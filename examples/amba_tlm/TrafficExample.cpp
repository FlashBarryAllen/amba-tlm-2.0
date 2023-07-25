#include <iostream>

#include "TrafficGenerator.h"
#include "Monitor.h"
#include "Memory.h"

using namespace std;
using namespace sc_core;
using namespace ARM::AXI4;

void add_payloads_to_tg(TrafficGenerator& tg)
{
    //tg.add_payload(COMMAND_READ,  0x00001000, SIZE_16, 3);
    //tg.add_payload(COMMAND_WRITE, 0x00006000, SIZE_16, 3);
    //tg.add_payload(COMMAND_READ,  0x00002000, SIZE_16, 3);
    //tg.add_payload(COMMAND_WRITE, 0x00005000, SIZE_16, 3);
    //tg.add_payload(COMMAND_READ,  0x00003000, SIZE_16, 3);
    //tg.add_payload(COMMAND_WRITE, 0x00004000, SIZE_16, 3);
    //tg.add_payload(COMMAND_READ,  0x00004000, SIZE_16, 3);
    //tg.add_payload(COMMAND_WRITE, 0x00003000, SIZE_16, 3);
    //tg.add_payload(COMMAND_READ,  0x00005000, SIZE_16, 3);
    //tg.add_payload(COMMAND_WRITE, 0x00002000, SIZE_16, 3);
    //tg.add_payload(COMMAND_READ,  0x00006000, SIZE_16, 3);
    //tg.add_payload(COMMAND_WRITE, 0x00001000, SIZE_16, 3);
    tg.add_payload(COMMAND_WRITE, 0x00001000, SIZE_8, 4);
    tg.add_payload(COMMAND_WRITE, 0x00002000, SIZE_8, 4);
}

void add_payloads_to_tg1(TrafficGenerator& tg)
{
    //tg.add_payload(COMMAND_READ,  0x00001000, SIZE_16, 3);
    //tg.add_payload(COMMAND_WRITE, 0x00006000, SIZE_16, 3);
    //tg.add_payload(COMMAND_READ,  0x00002000, SIZE_16, 3);
    //tg.add_payload(COMMAND_WRITE, 0x00005000, SIZE_16, 3);
    //tg.add_payload(COMMAND_READ,  0x00003000, SIZE_16, 3);
    //tg.add_payload(COMMAND_WRITE, 0x00004000, SIZE_16, 3);
    //tg.add_payload(COMMAND_READ,  0x00004000, SIZE_16, 3);
    //tg.add_payload(COMMAND_WRITE, 0x00003000, SIZE_16, 3);
    //tg.add_payload(COMMAND_READ,  0x00005000, SIZE_16, 3);
    //tg.add_payload(COMMAND_WRITE, 0x00002000, SIZE_16, 3);
    //tg.add_payload(COMMAND_READ,  0x00006000, SIZE_16, 3);
    //tg.add_payload(COMMAND_WRITE, 0x00001000, SIZE_16, 3);
    tg.add_payload(COMMAND_WRITE, 0x00003000, SIZE_8, 4);
    tg.add_payload(COMMAND_WRITE, 0x00004000, SIZE_8, 4);
}

int sc_main(int argc, char* argv[])
{
    sc_clock clk("clk", 2, SC_NS, 0.5);

    TrafficGenerator tg("tg");
    TrafficGenerator tg1("tg1");

    Monitor mon("mon");
    Memory mem("mem");
    Memory mem1("mem1");

    tg.clock.bind(clk);
    tg1.clock.bind(clk);
    mem.clock.bind(clk);
    mem1.clock.bind(clk);

    tg.master.bind(*(mon.slave[0]));
    tg1.master.bind(*(mon.slave[1]));
    (*(mon.master[0])).bind(mem1.slave);
    (*(mon.master[1])).bind(mem.slave);

    add_payloads_to_tg(tg);
    add_payloads_to_tg1(tg1);

    sc_start(2000, SC_NS);

    Payload::debug_payload_pool(cout);

    return 0;
}

