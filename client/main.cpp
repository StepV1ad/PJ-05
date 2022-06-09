#include "Chat.h"

extern int socket_file_descriptor, connection;
extern struct sockaddr_in serveraddress, client;

int main()
{
#if defined(__linux__)
	struct utsname utsname;
	uname(&utsname);
	std::cout << "OS name: " << utsname.sysname << std::endl;
	std::cout << "Host name: " << utsname.nodename << std::endl;
	std::cout << "OS release: " << utsname.release << std::endl;
	std::cout << "OS version: " << utsname.version << std::endl;
	std::cout << "Machine name: " << utsname.machine << std::endl;
#elif defined (_WIN32) || defined (_WIN64)
	std::cout << "OS name: Windows" << std::endl;
	std::cout << "OS version: ";
	if (IsWindows10OrGreater) std::cout << "10" << std::endl;
	else if (IsWindows8Point1OrGreater())  std::cout << "8.1" << std::endl;
	else if (IsWindows8OrGreater())  std::cout << "8" << std::endl;
	else if (IsWindows7OrGreater())  std::cout << "7" << std::endl;
	else if (IsWindowsVistaOrGreater())  std::cout << "Vista" << std::endl;
	else if (IsWindowsXPOrGreater())  std::cout << "XP" << std::endl;
#endif

	socket_file_descriptor = socket(AF_INET, SOCK_STREAM, 0);
	if (socket_file_descriptor == -1) {
		std::cout << "Creation of Socket failed!" << std::endl;
		exit(1);
	}
	serveraddress.sin_addr.s_addr = inet_addr("192.168.98.128");
	serveraddress.sin_port = htons(PORT);
	serveraddress.sin_family = AF_INET;
	connection = connect(socket_file_descriptor, (struct sockaddr*)&serveraddress, sizeof(serveraddress));
	if (connection == -1) {
		std::cout << "Connection with the server failed.!" << std::endl;
		exit(1);
	}
	
	Chat chat;
	chat.start();
	while (chat.chatWork())
	{
		chat.showLoginMenu();
		while (chat.mainMenuWork())
		{
			chat.showUserMenu();
		}
	}
	close(socket_file_descriptor);
	return 0;
}