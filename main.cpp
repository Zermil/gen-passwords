#include <cstdio>
#include <cstdlib>
#include <ctime>

int main(int argc, char* argv[])
{
    if (argc < 3) {
	fprintf(stderr, "Usage: genpass <num_of_passwords> <length_of_password>\n");
	exit(1);
    }

    srand(time(NULL));
    
    FILE* output = fopen("passwords.txt", "w");
    int num_of_passwords = atoi(argv[1]);
    int length_of_password = atoi(argv[2]);

    if (length_of_password < 12) {
	fprintf(stderr, "ERROR: Single password needs to be at least 12 characters long!\n");
	exit(1);
    }
    
    if (output == nullptr) {
	fprintf(stderr, "ERROR: Could not create \'passwords.txt\'\n");
	exit(1);
    }

    for (int i = 0; i < num_of_passwords; ++i) {
	for (int j = 0; j < length_of_password; ++j) {
	    char random_character = rand() % 93 + 33;
	    fprintf(output, "%c", random_character);
	}

	fprintf(output, "\n");
    }

    printf("Done!\n");
    return 0;
}
