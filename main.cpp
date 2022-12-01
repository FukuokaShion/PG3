#include <stdio.h>
#include <list>
#include <iostream>

using namespace std;
int main(){
//-----1970------
	printf("-----1970年-----\n");

	//リストを生成
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
	
	//リストの表示
	for (auto itr = list.begin(); itr != list.end(); ++itr)
	{
		cout << *itr << "\n";
	}


//------2019-----
	printf("-----2019年-----\n");
	//リストに西日暮里を追加
	for (auto itr = list.begin(); itr != list.end(); ++itr)
	{
		if (*itr == "Tabata") {
			itr = list.insert(itr,"Nisinippori");
			break;
		}
	}
	//リストの表示
	for (auto itr = list.begin(); itr != list.end(); ++itr)
	{
		cout << *itr << "\n";
	}

	printf("\n");

//-----2022-----
	printf("-----2022年-----\n");
	//リストに高輪Gを追加
	for (auto itr = list.begin(); itr != list.end(); ++itr)
	{
		if (*itr == "Tamachi") {
			itr = list.insert(itr, "TakanawaGateway");
			break;
		}
	}
	//リストの表示
	for (auto itr = list.begin(); itr != list.end(); ++itr)
	{
		cout << *itr << "\n";
	}

	system("pause");

	return 0;
}