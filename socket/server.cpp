#include <iostream>
#include <vector>
#include <stdio.h>
#include <unistd.h>
#include <list>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <thread>
#include <future>

#define PORT 8080


void hear(int* v1, int v2) {
	int new_socket, valread;

	while (true) {
		char* buffer = new char[1024];
		valread = read(*v1, buffer, 1024);
		printf("%s\n", (buffer) );
		delete [] buffer;

	}
	std::cout << "(close)v2: " << v2 << std::endl;


}

void sending(int* v1) {
	std::string mess;
	while (true) {
		// getline(std::cin, mess);
		// mess = std::to_string(i) + mess + "\n";

		send(*v1, mess.c_str(), mess.length(), 0);
	}


}

int main() {
	using namespace std;
	//sleep(10);
  int server_fd, valread;
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

	vector<int*> th_array = {};
	thread th_arr[3];
	int i = 0;

	int *sock = new int[3];

	while (true) {
		if ((sock[i] = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {
				perror("accept");
				exit(EXIT_FAILURE);
		} else {
			cout << "A new person.." << endl;
		}
		//array.push_back(&sock);
		cout << " socket = " << &sock[i] << endl;
		th_arr[i] = thread(hear, &sock[i], i);
		i++;


		//thread sss1(hear, &sock);
		//thread sss2(sending, &sock);
		
		//sss1.join();


	}

	for (int i = 0; i < 3; i++) {
		delete [] sock;
	}



	th_arr[0].join();
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
