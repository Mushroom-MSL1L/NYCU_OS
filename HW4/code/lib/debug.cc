// debug.cc 
//	Debugging routines.  Allows users to control whether to 
//	print DEBUG statements, based on a command line argument.
//
// Copyright (c) 1992-1996 The Regents of the University of California.
// All rights reserved.  See copyright.h for copyright notice and limitation 
// of liability and disclaimer of warranty provisions.

#include "copyright.h"
#include "utility.h"
#include "debug.h" 
#include "string.h"

//----------------------------------------------------------------------
// Debug::Debug
//      Initialize so that only DEBUG messages with a flag in flagList 
//	will be printed.
//
//	If the flag is "+", we enable all DEBUG messages.
//
// 	"flagList" is a string of characters for whose DEBUG messages are 
//		to be enabled.
//----------------------------------------------------------------------

Debug::Debug(char *flagList)
{
    enableFlags = flagList;
}


//----------------------------------------------------------------------
// Debug::IsEnabled
//      Return TRUE if DEBUG messages with "flag" are to be printed.
//----------------------------------------------------------------------

bool
Debug::IsEnabled(char flag)
{
    if (enableFlags != NULL) {
	return ((strchr(enableFlags, flag) != 0) 
		|| (strchr(enableFlags, '+') != 0));
    } else {
    	return FALSE;
    }
}

void
Debug::debug_z_message(char* buffer, char *zType, int current_total_tick, char *process_name){
    if (strcmp(zType, "A") == 0) { 
        sprintf(buffer, "[A] Tick [%d]: Process [%s] is inserted into queue", current_total_tick, process_name);
    } else if (strcmp(zType, "B") == 0) { 
        sprintf(buffer, "[B] Tick [%d]: Process [%s] is removed from queue", current_total_tick, process_name);
    } else {
        sprintf(buffer, "Invalid zType[ %s ], Tick [%d]: Process [%s] is inserted into queue", zType, current_total_tick, process_name);
    }
}

void
Debug::debug_z_message(char* buffer, char *zType, int current_total_tick, char *first_process_name, char *second_process_name){
    if (strcmp(zType, "C") == 0) {
        sprintf(buffer, "[C] Tick [%d]: Process [%s] is now selected for execution, Process [%s] is replaced.", current_total_tick, first_process_name, second_process_name);
    } else {
        sprintf(buffer, "Invalid zType[ %s ], Tick [%d]: Process [%s] is inserted into queue", zType, current_total_tick, second_process_name);
    }
}

