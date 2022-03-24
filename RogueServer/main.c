#include <stdio.h>
#include <stdlib.h>
#include <winsock2.h>
#include <pthread.h>
#include <conio.h>
#pragma comment(lib,"Ws2_32.lib")
SOCKET active_client_socket;
pthread_t thread;
int status;
int status_addr;
void* proccessing_client() {
	SOCKET client_socket = active_client_socket;
	active_client_socket = NULL;
	char s[255] = "SASSS";
//	memset(s, 0, sizeof(s));
		while (recv(client_socket, s, sizeof(s), 0) > 0) {
			printf("\n%d:%s", client_socket, s);
		}
		printf("\n%d:close", client_socket);
}

int main() {

	WSADATA ws;
	WSAStartup(MAKEWORD(2, 2), &ws);
	SOCKET s;
	s = socket(AF_INET, SOCK_STREAM, 0);
	SOCKADDR_IN sa;
	memset(&sa, 0, sizeof(sa));
	sa.sin_family = AF_INET;
	sa.sin_port = htons(1234);
	char c;
	
	printf("Server-s\nClient-c\n");
	scanf("%c", &c);
	
	if (c == 'c') {
		sa.sin_addr.S_un.S_addr = inet_addr("88.85.171.249");
		connect(s, &sa, sizeof(sa));
		char q[255];
	
		printf("Write:");
		scanf("%s", &q);
		while (1 == 1)
		{
			send(s, q, sizeof(q), 0);
			Sleep(1000);
			printf("Send!!!");
		}
		
	}
	else {
	
		bind(s, &sa, sizeof(sa));
		listen(s, 100);
		SOCKET client_socket;
		SOCKADDR_IN client_adrr;
		int client_adr_size = sizeof(client_adrr);
		while (client_socket = accept(s, &client_adrr, &client_adr_size))
		{
			active_client_socket = client_socket;
			status_addr = pthread_create(&thread, NULL, proccessing_client, NULL);
			printf("%d\n%d\n\n", active_client_socket, status_addr);
		}
	}
	return 0;
}
