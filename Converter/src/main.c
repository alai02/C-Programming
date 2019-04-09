#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "create.h"
#include "manipulate.h"
#include "fileio.h"
#include "helper.h"

int main(int argc, char* argv[]){
	parseFile(argv[1]);
	return 0;
}
