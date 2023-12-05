#include "CHandler.h"

int main(int argc, char* argv[])
{
	return CHandler::GetIntance()->Start(argc, argv);
}