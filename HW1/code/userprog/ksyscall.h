/**************************************************************
 *
 * userprog/ksyscall.h
 *
 * Kernel interface for systemcalls 
 *
 * by Marcus Voelp  (c) Universitaet Karlsruhe
 *
 **************************************************************/

#ifndef __USERPROG_KSYSCALL_H__ 
#define __USERPROG_KSYSCALL_H__ 

#include "kernel.h"

#include "synchconsole.h"


void SysHalt()
{
  kernel->interrupt->Halt();
}

int SysAdd(int op1, int op2)
{
  return op1 + op2;
}

int SysCreate(char *filename)
{
	// return value
	// 1: success
	// 0: failed
	return kernel->interrupt->CreateFile(filename);
}

int SysPrintInt(int num)
{
	kernel->interrupt->PrintInt(num);
}

OpenFileId SysOpen(char *filename)
{
	// Return -1 if open fails
	return kernel->interrupt->OpenFile(filename);
}

int SysWrite(char *buffer, int size, OpenFileId id)
{
	// If attempt writing to an invalid id, return -1
	return kernel->interrupt->WriteFile(buffer, size, id);
}

int SysRead(char *buffer, int size, OpenFileId id)
{
	// If attempt reading from an invalid id, return -1
	return kernel->interrupt->ReadFile(buffer, size, id);
}

int SysClose(OpenFileId id)
{
	// If attempt closing an invalid id, return -1
	return kernel->interrupt->CloseFile(id);
}

#endif /* ! __USERPROG_KSYSCALL_H__ */
