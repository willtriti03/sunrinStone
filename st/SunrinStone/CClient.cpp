#include"stdafx.h"
#include"CClient.h"

CClient::CClient(std::string serverIP, int serverPort){
	//���� �ʱ�ȭ
	sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock == INVALID_SOCKET){
		getErrorMessage();
		exit(0);
	}

	ZeroMemory(&serverAddr, sizeof(serverAddr));
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_addr.s_addr = inet_addr(serverIP.c_str());
	serverAddr.sin_port = htons(serverPort);

	/*
	int optval = 3000;
	if (setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (char *)optval, sizeof(optval)) == SOCKET_ERROR){
	getErrorMessage();
	exit(0);
	}
	*/

	//������ ����
	if (connect(sock, (SOCKADDR *)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR){
		getErrorMessage();
		exit(0);
	}

	//�б� ������ ����
	start();

}
CClient::~CClient(){
	//������ �Լ� �ڿ� �ݳ�
	stop();

	if (!closed){
		closeSocket();
	}

	//delete ��
	CSocket::DATA* dat;
	while (dataQueue.size() <= 0){
		dat = dataQueue.front();
		dataQueue.pop();
		delete dat;
	}
}

void CClient::run(){
	while (true){
		DATA read;

		if (readData(sock, (char *)&read, sizeof(read), 0) < 0){	//�����͸� �о� ����
			getErrorMessage();//������ �̻�
			exit(0);
		}

		//���ۿ� ������
		DATA *dat = new DATA;
		dat->code = read.code;
		strcpy(dat->data, read.data);
		//std::cout << "����" << dat->code << "/" << dat->data << std::endl;

		dataQueue.push(dat);	//���ۿ� �߰�
	}
}
int CClient::write(int code, char *data){
	CSocket::DATA dat;

	if (data[strlen(data) - 1] == '\n')
		data[strlen(data) - 1] = '\0';

	dat.code = code;
	strcpy(dat.data, data);

	if (sendData(sock, (char *)&dat, sizeof(dat), 0) < 0){//�����͸� ����
		getErrorMessage();	//�� Ŭ�� ������ �̻�
		exit(0);
	}

	//std::cout << "����" << dat.code << "/" << dat.data << std::endl;

	return strlen(data);
}
int CClient::read(int *code, char *data){
	if (dataQueue.size() <= 0){//���ۿ� ����Ÿ�� ���°�?
		*code = CCLIENT_NO_MORE_DATA;
		strcpy(data, "");
		return 0;
	}

	CSocket::DATA* dat = dataQueue.front();//������ ������

	*code = dat->code;
	strcpy(data, dat->data);

	//std::cout << "ȣ��" << dat->code << "/" << dat->data << std::endl;

	dataQueue.pop();
	delete dat;

	return strlen(dat->data);
}

int CClient::closeSocket(){
	closesocket(sock);
	closed = true;
	return 0;
}