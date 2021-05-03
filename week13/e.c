#include <string.h>
#include <unistd.h>

#define MAX_KULCS 100
#define BUFFER_MERET 256

int main(int argc, char** argv){

	char kulcs[MAX_KULCS];
	char buffer[BUFFER_MERET];

	int kulcs_index = 0;
	int olvasott_bajtok = 0;

	int kulcs_meret = strlen(argv[1]);
	strncpy(kulcs, argv[1], MAX_KULCS);

	while (( olvasott_bajtok = read ( 0, (void*) buffer, BUFFER_MERET ))){
		
		for (int i = 0; i < olvasott_bajtok; ++i){

			buffer[i] = buffer[i] ^ kulcs[kulcs_index];
			kulcs_index = (kulcs_index + 1) % kulcs_meret;
		}

		write ( 1, buffer, olvasott_bajtok );
	}

	return 0;
}