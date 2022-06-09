#pragma once
#include <vector>
#include <memory>
#include "Message.h"

class Chat
{
	std::vector<User> users_;
	std::vector<Message> commonChat_;
	std::vector<Message> messages_;
	std::shared_ptr<User> currentUser_ = nullptr;
	int idStorage_ = 0;
	bool chatWork_ = false;
	bool mainMenuWork_ = false;

	bool checkLogin(const std::string& login);
	bool checkName(const std::string& name);
	bool checkPassword(const std::string& name, const std::string& password);
	void signUp();
	void login();

	void addCommonMessage();
	void showCommonChat();
	void addUserMessage();
	void showUserChat();
	void changeUser(); // изменяет имя или пароль пользователя
	void showUsers(); // отображает список имён всех пользователей 
	void readUserFile();
	void wrightUserFile();
	void readMessageFile();
	void wrightMessageFile();
	void readCommonChatFile();
	void wrightCommonChatFile();

	void admin(); // зарегестрированный пользователь с отдельным меню // login admin, password 13579
	void printAllInf(); // отображает всю информацию пользователей
	void showPrivateChat(); // просмотр чатов пользователей

public:
	void start();
	bool chatWork() const { return chatWork_; }
	bool mainMenuWork() const { return mainMenuWork_; }
	void showLoginMenu();
	void showUserMenu();
};