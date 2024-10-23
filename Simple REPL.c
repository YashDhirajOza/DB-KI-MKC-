
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <unistd.h>
#include<stdbool.h>
// makeing the strcture of buffer 
 typedef struct{
    char* buffer;  
    size_t buffer_length;
    ssize_t input_length;
 } InputBuffer;
 
 InputBuffer* new_input_buffer(){
    InputBuffer* input_buffer=(InputBuffer*)malloc(sizeof(InputBuffer));
    input_buffer->buffer=NULL;
    input_buffer-> buffer_length=0;
    input_buffer->input_length=0;
    return input_buffer;
 }
// fucntion to print the propmt
 void print_prompt(){printf("db > ");}
 // to read a line 
 ssize_t getline(char **lineptr, size_t *n,FILE *stream);
// size_t or ssize_t means undefined size for unsigned interger
// **ptr means it is a pointer to a pointer  */
// main fucntion to get the commad 
int main(int argc, char* argv[] ){
    InputBuffer *input_buffer = new_input_buffer();
    while(true){
        print_prompt();
        read_input(input_buffer);
        if (strcmp(input_buffer->buffer,".exit")==0){
            close_input_buffer(input_buffer);
            exit(EXIT_SUCCESS);
        }
        else{
            printf("Unrecognized command '%s'.\n", input_buffer->buffer);
        }
    }  
}
void read_input(InputBuffer* input_buffer){
    ssize_t bytes_read=getline(&(input_buffer->buffer),&(input_buffer->buffer_length),stdin);
    if (bytes_read<= 0){
        printf("ERROR IN READING INPUT \n");
        exit(EXIT_FAILURE);

    }   
  // to ingore the trailing lines 
  input_buffer->input_length=bytes_read-1;
  input_buffer->buffer[bytes_read-1]=0;
}

void close_input_buffer(InputBuffer* input_buffer){
    free(input_buffer->buffer);
    free(input_buffer);



}
