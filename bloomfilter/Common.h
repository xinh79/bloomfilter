#ifndef _COMMON_H
#define _COMMON_H

#include <iostream>
#include <math.h>

#define INF 0xFFFF
#define SR_SIZE 32
#define LINE_SIZE 256
#define BROAD_ADDR  0xFFFF
#define MAX_TTL     16
#define MAX_TRACE   8

extern int gDebugLevel;
#define myCout(MyLevel) if(gDebugLevel & (1<<MyLevel)) cout

typedef int Address;
typedef int EventType;
typedef double Time;
typedef int Command;
typedef int PacketType;

using namespace std;

enum {
  DebugCritical    = 0,
  DebugImportant   = 1,
  DebugPacket      = 2,
  DebugProtocol    = 3,
  DebugNode        = 4,
  DebugNetwork     = 5,
  DebugEvent       = 6,
  DebugTraceback   = 7,
  DebugStats       = 8,
  DebugParam       = 9,
  DebugAnything
};

#endif // _COMMON_H
