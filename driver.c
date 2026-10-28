# include <stdio.h>
# include <stdlib.h>
#include <string.h>

int main(int argc,char* argv[]){
	char* outputfile="a.out";
	char* inputfile;
	char buffer[256];
	int lexeronly;
	int parseronly;
	int codegenonly;
	int asmgenonly;
	if(argc<=1){
		perror("no file passed");
		return 1;
	}
	for (int i=0;i<argc;i++){
		if (strcmp(argv[i],"-o")==0){
			if (i+1>=argc){
				perror("no output file after -o");
				return 1;
			}else{
				outputfile=argv[i+1];
			}
		}
		if(argv[i][0]=='-'){
			if(strcmp(argv[i],"-lexer")==0){
				lexeronly=1;
			}else if(strcmp(argv[i],"-parser")==0){
				parseronly=1;
			}else if(strcmp(argv[i],"-codegen")==0){
				codegenonly=1;
			}else if(strcmp(argv[i],"-S")==0){
				asmgenonly=1;
			}else{
				perror("the flag doesnt exist yet");
				return 1;
			}
		}
		inputfile=argv[i];
	}
	
	snprintf(buffer,sizeof(buffer), "gcc -E -P %s -o PREPROCESSED_FILE",inputfile);
	
	int err=system(buffer);
	if (err== -1) {
        printf("Command execution failed.\n");
    }else{
        printf("Command execution successful.\n");
	}
   
	//we call the compiler module here and compile and get the .s file
	//we call the gcc myasm.s -o mybin

	printf("inputfile -> %s,flag -> %d,outputfile %s \n",inputfile,lexeronly,outputfile);
	printf("flag-> %d \n",parseronly);
	printf("flag-> %d \n",codegenonly);
	printf("flag-> %d \n",asmgenonly);
	return 0;	

}

