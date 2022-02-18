// Client side C/C++ program to demonstrate Socket programming
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <string>
#include <iostream>
#include <thread>

#define PORT 8080


using namespace std;



void lissen(int* sock) {
	int valread;
	char buffer[1024];
	cout << "helo:" << endl;
	while (true) {

		valread = read(*sock, buffer, 1024);
		printf("%s\n", buffer);

	}
}


void sending(int* sock) {
	std::string mess;
	while (true) {
		std::cout << "Type message please.. " << std::endl;
		getline(std::cin, mess);


		//mess = std::to_string(i) + mess + "\n";
		send(*sock, mess.c_str(), mess.length(), 0);

	}


}


int main(int argc, char const *argv[]) {
	int sock = 0, valread;
	struct sockaddr_in serv_addr;
	const char *hello = "Hello, my Name is Max ";
	char buffer[1024] = {0};
	if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		printf("\n Socket creation error \n");
		return -1;
	}

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(PORT);
	
	// Convert IPv4 and IPv6 addresses from text to binary form
	if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0) {
		printf("\nInvalid address/ Address not supported \n");
		return -1;
	}

	if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
		printf("\nConnection Failed \n");
		return -1;
	}

	//std::string mess = "fdsafwkerwerwrwasfd";


	//std::string s = "123";
	
	//char bu1[1024];
	//std::cin.getline(bu1);	

	std::thread thr1(sending, &sock);
	std::thread thr2(lissen, &sock);
	std::cout << "thread with sending is started." << std::endl;
	//while (true) {

	//valread = read(sock, buffer, 1024);
	//printf("%s\n", buffer);

	//}
	//lissen(sock);
	thr2.join();




	return 0;
}

