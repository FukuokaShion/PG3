#include <stdio.h>
#include <list>
#include <iostream>

using namespace std;
int main(){
//-----1970------
	printf("-----1970�N-----\n");

	//���X�g�𐶐�
	list<const char*> list{
		"Tokyo",
		"Kanda",
		"Akihabara",
		"Okachimachi",
		"Ueno",
		"Uguisudani",
		"Nippori",
		"Tabata",
		"Komagome",
		"Sugamo",
		"Otsuka",
		"Ikebukuro",
		"Mejiro",
		"Takadanobaba",
		"ShinOkubo",
		"Shinjuku",
		"Yoyogi",
		"Harajuku",
		"Shibuya",
		"Ebisu",
		"Meguro",
		"Gotanda",
		"Osaki",
		"Shinagawa",
		"Tamachi",
		"Hamamatsucho",
		"Shimbashi",
		"Yurakucho"
	};
	
	//���X�g�̕\��
	for (auto itr = list.begin(); itr != list.end(); ++itr)
	{
		cout << *itr << "\n";
	}


//------2019-----
	printf("-----2019�N-----\n");
	//���X�g�ɐ����闢��ǉ�
	for (auto itr = list.begin(); itr != list.end(); ++itr)
	{
		if (*itr == "Tabata") {
			itr = list.insert(itr,"Nisinippori");
			break;
		}
	}
	//���X�g�̕\��
	for (auto itr = list.begin(); itr != list.end(); ++itr)
	{
		cout << *itr << "\n";
	}

	printf("\n");

//-----2022-----
	printf("-----2022�N-----\n");
	//���X�g�ɍ���G��ǉ�
	for (auto itr = list.begin(); itr != list.end(); ++itr)
	{
		if (*itr == "Tamachi") {
			itr = list.insert(itr, "TakanawaGateway");
			break;
		}
	}
	//���X�g�̕\��
	for (auto itr = list.begin(); itr != list.end(); ++itr)
	{
		cout << *itr << "\n";
	}

	system("pause");

	return 0;
}