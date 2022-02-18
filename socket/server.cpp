#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
//#include <string>
#include <string.h>
#include <thread>


#define PORT 8080



void hear(int* sock) {
	int new_socket, valread;
	char buffer[1024];

	while (true) {
		valread = read(*sock, buffer, 1024);
		printf("%s\n", buffer );

	}

}

void sending(int* sock) {
	std::string mess;
	while (true) {
		getline(std::cin, mess);
		//mess = std::to_string(i) + mess + "\n";
		send(*sock, mess.c_str(), mess.length(), 0);

	}


}

int main() {
	using namespace std;
	//sleep(10);


  int server_fd, sock, valread;
  struct sockaddr_in address;
  int opt = 1;
  int addrlen = sizeof(address);
  char buffer[1024] = {0};

     
  // Creating socket file descriptor
  if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
      perror("socket failed");
      exit(EXIT_FAILURE);
  }
     
  // Forcefully attaching socket to the port 8080
  if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
      perror("setsockopt");
      exit(EXIT_FAILURE);
  }
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons( PORT );
     
  // Forcefully attaching socket to the port 8080
  if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) {
      perror("bind failed");
      exit(EXIT_FAILURE);
  }
  if (listen(server_fd, 3) < 0) {
      perror("listen");
      exit(EXIT_FAILURE);
  }


	/*
	cout << "Server lissent to you.." << endl;
	thread sss1(hear, &server_fd, &address, &addrlen, buffer);
	cout << "I'm here" << endl;
	*/


	/*
	if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {
			perror("accept");
			exit(EXIT_FAILURE);
	} else {
		cout << "A new communication.." << endl;
	}
	*/

		if ((sock = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {
				perror("accept");
				exit(EXIT_FAILURE);
		} else {
			cout << "A new person.." << endl;
		}


		cout << address.sin_port << endl;
		thread sss1(hear, &sock);
		thread sss2(sending, &sock);
		



		sss1.join();
		sss2.join();











	//sss1.join();
	/*
  if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {
      perror("accept");
      exit(EXIT_FAILURE);
  }
  valread = read( new_socket , buffer, 1024);
  printf("%s\n", buffer );
  printf("Hello message sent\n");
	*/
	return 0;
}
