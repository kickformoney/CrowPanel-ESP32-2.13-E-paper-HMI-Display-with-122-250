#pragma once

#if DEBUG
  #define DEBUG_PRINTLN(x) Serial.println(x)
  #define DEBUG_PRINT(x)   Serial.print(x)
#else
  #define DEBUG_PRINTLN(x) // Empty macro: ignored by compiler
  #define DEBUG_PRINT(x)   // Empty macro: ignored by compiler
#endif
