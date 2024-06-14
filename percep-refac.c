#include <stdio.h>
#include <string.h>

#define THRESHOLD 1.6
#define INPUT_COUNT 5

int set_input(int i, char input_buff, float *input){
	
	if(input_buff == 'Y' || input_buff == 'y'){
		*input = 1;
	}
	else if(input_buff == 'N' || input_buff == 'n'){
		*input = 0;
		if(i==3){
			printf("\n \t Well, get ready to lose your sleep!\n");
		}
	}
	else{
		return -1;
	}
	return 0;
}

void *get_questions(int i, float *weight){ //* represents string literal function
	switch(i){
		case 0:
			*weight = 0.8;
			return "Do you love to create new things?";
			break;
		case 1: 
			*weight = 0.6;
			return "Do you love to learn new things continuously?";
			break;
		case 2: 
			*weight = 0.4;
			return "Are you willing to give up your social life?";
			break;
		case 3: 
			*weight = 0.4;
			return "Do you have insomnia?";
			break;
		case 4: 
			*weight = 0.7;
			return "Are you patient enough to search for bugs for hours?";
			break;
		default:
			return "ERROR";
			break;
	}

}

int main()
{
	printf("----------Should you choose computer science as your major?---------\n");

	float x[INPUT_COUNT];
	float w[INPUT_COUNT];
	
	float p;
	float p_max;
	char input;

	for(int i = 0; i<INPUT_COUNT; i++){
		char *str = get_questions(i,&w[i]);
		
		if(!strcmp("ERROR",str)){
			fprintf(stderr, "\nERROR: No Questions Defined. Check The Questions.");
			return 1;
		}

	 	printf("\t %s (Y or N):", str);

		scanf(" %c",&input);
		while(getchar() != '\n');
	
		if( set_input(i,input,&x[i]) != 0){
			fprintf(stderr, "ERROR: INVALID OUTPUT");
			return 1;
		}
		
		p += x[i] * w[i];
		p_max += 1*w[i];
	}
	if(p<THRESHOLD){
		printf("\t\033[1;31mNO: Choose Design\033[0m");
	}
	else{
		printf("\t\033[1;32mYES: You can choose Computer Science\033[0m");
	}

	printf("\n\t%%P = %f%%", (p/p_max)*100);
	
	return 0;

}
