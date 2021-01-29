#include "../include/cp_command.h" 

int cp_command(int argc , char **argv)
{
		if (argc < 3)
	{
		return 1;
	}

	FILE *SourceFilePtr = fopen(argv[1] ,"rb");
	if (!SourceFilePtr)
	{
		return 2;
	}

	FILE *DestinationFilePtr = fopen(argv[2] , "w+b");
	if (!DestinationFilePtr)
	{
		return 3;
	}

	char buffer[1];
	while (fread(buffer , sizeof(char) , 1 , SourceFilePtr) > 0)
	{
		fwrite(buffer , sizeof(char) , 1 , DestinationFilePtr);
	}

	fclose(DestinationFilePtr);
	fclose(SourceFilePtr);
	return 0;
}
