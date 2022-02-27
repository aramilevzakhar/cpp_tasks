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

char buffer[1024];
int *sock = new int[3];

void hear(int* v1) {
	using namespace std;
	int new_socket, valread;

	while (true) {
		memset(buffer, 0, strlen(buffer));
		valread = read(*v1, buffer, 1024);
		printf("%s\n", (buffer) );
		for (int i=0;i<3;i++) {
			//send(sock[i], mess.c_str(), mess.length(), 0);
			if (*v1 != sock[i])
				send(sock[i], buffer, strlen(buffer), 0);
			//cout << sock[i] << endl;
		}

	}
	//std::cout << "(close)v2: " << v2 << std::endl;


}

void sending(int* sock) {
	using namespace std;
	while (true) {
		// getline(std::cin, mess);
		// mess = std::to_string(i) + mess + "\n";

		for (int i=0;i<3;i++) {
			//send(sock[i], mess.c_str(), mess.length(), 0);
			send(*sock, buffer, 1024, 0);
			cout << sock[i] << endl;
		}
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

	vector<int*> th_array = {};
	thread th_arr[3];
	int i = 0;


	while (true) {
		if ((sock[i] = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {
				perror("accept");
				exit(EXIT_FAILURE);
		} else {
			cout << "A new person.." << endl;
		}
		//array.push_back(&sock);
		cout<<" socket = "<<&sock[i]<< endl;
		th_arr[i] = thread(hear, &sock[i]);
		i++;


	}

	for (int i = 0; i < 3; i++) {
		delete [] sock;
	}



	th_arr[0].join();
	return 0;
}
