  
#include<conio.h>
#include<stdio.h>//fgets(),printf(0,stdin
#include<stdlib.h>
#include<string.h>//strlen()
#include<ctype.h>//isupper(),islower(),tolower(),toupper(),isaplha() //check if alphanumeric

vigenerecipher(char *msg,char *key){
	int i,j,cipherValue;
	int len = strlen(key);
	char cipher;
	for(i=0;i<strlen(msg);i++){
		if(islower(msg[i])){
//			if its lower case then the range is 97-122
			cipherValue = ((int)msg[i]-97+ (int)tolower(key[i%len])-97)%26	;
//			printf("%d\t",cipherValue);
			cipher = (char)(cipherValue+97);
//			printf("%cd\t",cipher);
		}else{
//			else it's upper case then the range is between 65-90
			cipherValue = ((int)msg[i]-65 +(int)toupper(key[i%len])-65)%26 + 65;
			cipher = (char)(cipherValue);
//			printf("%c\t",cipher);
		}
//		Checking if the sentence or plain text input is alphabet or not 
		if(isalpha(msg[i])){
			printf("%c",cipher);
		}else{
//			is the plain text char is not alphanet then print space it space and so on
			printf("%c",msg[i]);
		}
	}
}
int main(){
 
 char* key="hello"	;
 char msg[255];
 
 printf("Please enter a word or a senetence to encrypt: ");
 fgets(msg,sizeof(msg),stdin);
 
 vigenerecipher(msg,key);
 
}

