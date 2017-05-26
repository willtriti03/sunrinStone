#ifndef _CCLIENT_H_
#define _CCLIENT_H_

#include"CSocket.h"
#include<process.h>
#include<queue>
#include<thread>

#define CCLIENT_NO_MORE_DATA -1	//���ۿ��� �о���ϰ� ������ ��� ����

class ThreadClass{
private:
protected:
	std::thread *thread = NULL;
public:
	ThreadClass(){}
	virtual ~ThreadClass(){
		if (thread != NULL){
			if (thread->joinable()) { thread->join(); }
			delete thread;
		}
	}

	void start(){ thread = new std::thread(&ThreadClass::run, this); }
	void stop(){}

	virtual void run(){}
};

class CClient : public ThreadClass, CSocket{
private:
	boolean closed = false;

	//������ ����� ���� ����
	SOCKET sock;
	SOCKADDR_IN serverAddr;

	//������ ����(ť)
	std::queue<CSocket::DATA *> dataQueue;

	void run();

protected:
public:
	CClient(std::string serverIP, int serverPort);//���� ip,���� ��Ʈ
	virtual ~CClient();

	int write(int code, char *data);	//������ ����
	int read(int *code, char *data);		//������ �б�(���ۿ���)

	int closeSocket();
};

#endif