#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include "flags.h"

int h_tpiugs = 0;
int L_tpiugs = 0;
int t_tpiugs = 0;
int p_tpiugs = 0;
int i_tpiugs = 0;
int I_tpiugs = 0;
int u_tpiugs = 0;
int g_tpiugs = 0;
int s_tpiugs = 0;
int d_tpiugs = 0;





int main(int argc, char *argv[])
{
	int opt, n;
	char *file;

	while((opt = getopt(argc, argv, "hLdgipstuI:l")) != -1)
	{
		switch(opt)
		{
			case 'h':
				h_tpiugs = 1;				
				break;
			case 'L':
				L_tpiugs = 1;
				break;

			case 'd':
				d_tpiugs = 1;
				break;

			case 'g':
				g_tpiugs = 1;
				break;

			case 'i':
				i_tpiugs = 1;
				break;

			case 'p':
				p_tpiugs = 1;
				break;

			case 's':
				s_tpiugs = 1;
				break;

			case 't':
				t_tpiugs = 1;
				break;

			case 'u':
				u_tpiugs = 1;
				break;

			case 'I':
				I_tpiugs = 1;
				n = (int)atoi(optarg);
				break;

			case 'l':
				L_tpiugs = 1;
				d_tpiugs = 1;
				g_tpiugs = 1;
				i_tpiugs = 1;
				p_tpiugs = 1;
				s_tpiugs = 1;
				t_tpiugs = 1;
				u_tpiugs = 1;
				break;

			case '?':
				printf("unknown argument: %s\n", optarg);
				break;

			default:
				fprintf(stderr, "youve gone too far\n");
				exit(EXIT_FAILURE);
				break;
		
		}
	
	}

	if(optind < argc)
	{
		printf("non-option argument: %s \n", argv[optind]);
	}	

	
	if(h_tpiugs == 1)
	{
		printf("------HELP MESSAGE-----\n");
		printf("Below is a list of keys to display file information\n\n");
		printf("-L: follow symbolic links if any\n");
		printf("-t: print information on file type\n");
		printf("-p: print permission bits as rwx rwx rwx\n");
		printf("-i: print the number of links to file in inode table\n");
		printf("-In: indent by n number of spaces\n");
		printf("-u: print the UID associated with the file\n");
		printf("-g: print the GIC associated with the file\n");
		printf("-s: print the size of the file in bytes\n");
		printf("-d: show the time of the last modification\n");
		printf("-l: show all of the about information, minus indetions unless explicitly stated in command line\n");
		exit(1);
	}
	if(L_tpiugs == 1)
	{
		printf("following symbolic links\n");
	}
	if(t_tpiugs == 1)
	{
		printf("printing file type information\n");
	}
	if(p_tpiugs == 1)
	{
		printf("printing file permission bits\n");
	}
	if(i_tpiugs == 1)
	{
		printf("printing number of linkgs to file in inode table\n");
	}
	if(u_tpiugs == 1)
	{
		printf("printing UID associated with the file\n");
	}
	if(g_tpiugs == 1)
	{
		printf("printing GIC associated with the file\n");
	}
	if(s_tpiugs == 1)
	{
		printf("printing file size in bytes\n");	
	}
	if(d_tpiugs == 1)
	{
		printf("printing time of last modification for file\n");
	}	
	if(I_tpiugs == 1)
	{
		printf("%*s indented spaces \n", n);
	}
	

	return 0;

}	
