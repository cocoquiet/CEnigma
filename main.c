#include <stdio.h>
#include <string.h>
#include <windows.h>

void drawEnigma() {
	printf("■■■■■　■　　　■　■■■■■　■■■■■　■　　　■　　　■　　\n");
	printf("■　　　　　■■　　■　　　■　　　■　　　　　■■　■■　　■　■　\n");
	printf("■■■■■　■　■　■　　　■　　　■　　■■　■　■　■　■■■■■\n");
	printf("■　　　　　■　　■■　　　■　　　■　　　■　■　　　■　■　　　■\n");
	printf("■■■■■　■　　　■　■■■■■　■■■■■　■　　　■　■　　　■\n");
	printf("\n");
	printf("\n");
	printf("\n");
	Sleep(500);
}

int main() {
	int i;
	char temp;
	
	char message[17576];
	int messageOrder = 0;
	char code[17576];
	int codeOrder;
	char rotorIn, rotorOut;
	
	// 로터 기본 세팅 
	int rotorCheck1, rotorCheck2, rotorCheck3; // 세팅할 로터 종류 
	char selectedRotor1[26], selectedRotor2[26], selectedRotor3[26];
	char selectedRotorReverse1[26], selectedRotorReverse2[26], selectedRotorReverse3[26];
	
	// 로터 알파벳 정보 (1 ~ 8)
	char rotor1[26] = {'E','K','M','F','L','G','D','Q','V','Z','N','T','O','W','Y','H','X','U','S','P','A','I','B','R','C','J'};
	char rotorReverse1[26] = {'U','W','Y','G','A','D','F','P','V','Z','B','E','C','K','M','T','H','X','S','L','R','I','N','Q','O','J'};
	char rotor2[26] = {'A','J','D','K','S','I','R','U','X','B','L','H','W','T','M','C','Q','G','Z','N','P','Y','F','V','O','E'};
	char rotorReverse2[26] = {'A','J','P','C','Z','W','R','L','F','B','D','K','O','T','Y','U','Q','G','E','N','H','X','M','I','V','S'};
	char rotor3[26] = {'B','D','F','H','J','L','C','P','R','T','X','V','Z','N','Y','E','I','W','G','A','K','M','U','S','Q','O'};
	char rotorReverse3[26] = {'T','A','G','B','P','C','S','D','R','E','U','F','V','N','Z','H','Y','I','X','J','W','L','R','K','O','M'};
	char rotor4[26] = {'E','S','O','V','P','Z','J','A','Y','Q','U','I','R','H','X','L','N','F','T','G','K','D','C','M','W','B'};
	char rotorReverse4[26] = {'H','Z','W','V','A','R','T','N','L','G','U','P','X','Q','C','E','J','M','B','S','K','D','Y','O','I','F'};
	char rotor5[26] = {'V','Z','B','R','G','I','T','Y','U','P','S','D','N','H','L','X','A','W','M','J','Q','O','F','E','C','K'};
	char rotorReverse5[26] = {'Q','C','Y','L','X','W','E','N','F','T','Z','O','S','M','V','J','U','D','K','G','I','A','R','P','H','B'};
	char rotor6[26] = {'J','P','G','V','O','U','M','F','Y','Q','B','E','N','H','Z','R','D','K','A','S','X','L','I','C','T','W'};
	char rotorReverse6[26] = {'S','K','X','Q','L','H','C','N','W','A','R','V','G','M','E','B','J','P','T','Y','F','D','Z','U','I','O'};
	char rotor7[26] = {'N','Z','J','H','G','R','C','X','M','Y','S','W','B','O','U','F','A','I','V','L','P','E','K','Q','D','T'};
	char rotorReverse7[26] = {'Q','M','G','Y','V','P','E','D','R','C','W','T','I','A','N','U','X','F','K','Z','O','S','L','H','J','B'};
	char rotor8[26] = {'F','K','Q','H','T','L','X','O','C','B','J','S','P','D','Z','R','A','M','E','W','N','I','U','Y','G','V'};
	char rotorReverse8[26] = {'Q','J','I','N','S','A','Y','D','V','K','B','F','R','U','H','M','C','P','L','E','W','Z','T','G','X','O'};
	
	// 플러그보드 기본 세팅 
	char plugboard[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
	char plugboardChange1, plugboardChange2;
	
	// 반사판 기본 세팅
	char reflector[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
	char reflectorChange1, reflectorChange2;
	
	

	drawEnigma();
	printf("로터 3개를 왼쪽부터 순서대로 선택하세요 (1 ~ 8) ex) 1 2 3 : ");
	scanf("%d %d %d", &rotorCheck1, &rotorCheck2, &rotorCheck3);
	switch(rotorCheck1) {
		case 1:
			strcpy(selectedRotor1, rotor1);
			strcpy(selectedRotorReverse1, rotorReverse1);
		case 2:
			strcpy(selectedRotor1, rotor2);
			strcpy(selectedRotorReverse1, rotorReverse2);
		case 3:
			strcpy(selectedRotor1, rotor3);
			strcpy(selectedRotorReverse1, rotorReverse3);
		case 4:
			strcpy(selectedRotor1, rotor4);
			strcpy(selectedRotorReverse1, rotorReverse4);
		case 5:
			strcpy(selectedRotor1, rotor5);
			strcpy(selectedRotorReverse1, rotorReverse5);
		case 6:
			strcpy(selectedRotor1, rotor6);
			strcpy(selectedRotorReverse1, rotorReverse6);
		case 7:
			strcpy(selectedRotor1, rotor7);
			strcpy(selectedRotorReverse1, rotorReverse7);
		case 8:
			strcpy(selectedRotor1, rotor8);
			strcpy(selectedRotorReverse1, rotorReverse8);
	}
	switch(rotorCheck2) {
		case 1:
			strcpy(selectedRotor2, rotor1);
			strcpy(selectedRotorReverse2, rotorReverse1);
		case 2:
			strcpy(selectedRotor2, rotor2);
			strcpy(selectedRotorReverse2, rotorReverse2);
		case 3:
			strcpy(selectedRotor2, rotor3);
			strcpy(selectedRotorReverse2, rotorReverse3);
		case 4:
			strcpy(selectedRotor2, rotor4);
			strcpy(selectedRotorReverse2, rotorReverse4);
		case 5:
			strcpy(selectedRotor2, rotor5);
			strcpy(selectedRotorReverse2, rotorReverse5);
		case 6:
			strcpy(selectedRotor2, rotor6);
			strcpy(selectedRotorReverse2, rotorReverse6);
		case 7:
			strcpy(selectedRotor2, rotor7);
			strcpy(selectedRotorReverse2, rotorReverse7);
		case 8:
			strcpy(selectedRotor2, rotor8);
			strcpy(selectedRotorReverse2, rotorReverse8);
	}
	switch(rotorCheck3) {
		case 1:
			strcpy(selectedRotor3, rotor1);
			strcpy(selectedRotorReverse3, rotorReverse1);
		case 2:
			strcpy(selectedRotor3, rotor2);
			strcpy(selectedRotorReverse3, rotorReverse2);
		case 3:
			strcpy(selectedRotor3, rotor3);
			strcpy(selectedRotorReverse3, rotorReverse3);
		case 4:
			strcpy(selectedRotor3, rotor4);
			strcpy(selectedRotorReverse3, rotorReverse4);
		case 5:
			strcpy(selectedRotor3, rotor5);
			strcpy(selectedRotorReverse3, rotorReverse5);
		case 6:
			strcpy(selectedRotor3, rotor6);
			strcpy(selectedRotorReverse3, rotorReverse6);
		case 7:
			strcpy(selectedRotor3, rotor7);
			strcpy(selectedRotorReverse3, rotorReverse7);
		case 8:
			strcpy(selectedRotor3, rotor8);
			strcpy(selectedRotorReverse3, rotorReverse8);
	}
	
	Sleep(500);
	system("cls");
	
	
	drawEnigma();
	printf("반사판을 세팅하세요 ex) A C\n");
	for(i = 0; i < 13; i++) {
		printf("%d번째 세팅 : ", i + 1);
		scanf("\n%c %c", &reflectorChange1, &reflectorChange2);
		
		temp = reflector[reflectorChange1 - 65];
		reflector[reflectorChange1 - 65] = reflector[reflectorChange2 - 65];
		reflector[reflectorChange2 - 65] = temp;
	}
	printf("\n\n");
	
	Sleep(1000);
	system("cls"); 
	
	
	drawEnigma();
	printf("모든 세팅을 끝냈습니다.\n");
	printf("--------------------------------\n");
	Sleep(1000);
	
	printf("로터 세팅 : %d번 %d번 %d번", rotorCheck1, rotorCheck2, rotorCheck3);
	printf("\n\n");
	
	printf("반사판 세팅 : ");
	for(i = 0; i < 26; i++) {
		printf("%c ", reflector[i]);
	}
	printf("\n\n");	
	Sleep(1000);
	
	printf("암호화할 문장을 적으십시오.\n");
	scanf("%s", &message);
	
	for(codeOrder = 0; codeOrder < strlen(message); codeOrder++) {
    	code[codeOrder] = selectedRotorReverse3[selectedRotorReverse2[selectedRotorReverse1[reflector[selectedRotor1[selectedRotor2[selectedRotor3[message[messageOrder]-65]-65]-65]-65]-65]-65]-65];
		messageOrder++;
   }

	
	for(i = 0; i < strlen(message); i++) {
		printf("%c", code[i]);
	}
	printf("\n\n");
	
	system("pause");
}
