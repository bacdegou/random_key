#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <Windows.h>
using namespace std;
char rand_ch() 
{
    return 'a'+rand()%26;              
}
int main(){
	string key;
	cout<<"请输入key格式，每个字段之间用“-”分开\n如:XXXXX-XXXXX-XXXXX-XXXXX-XXXXX\n";
	cin>>key;
	int n;
	cout<<"请输入生成个数\n";
	cin>>n;
	string cfg1,cfg2;
	int cfgs=1,cfgn=1;
	cout<<"请输入生成配置(默认或者不知道是什么请随便输入)\n";
	cin>>cfg1;
	bool b=1,s=0,num=0;
	if(cfg1!="default"){
		if(cfg1.find("string_config")!=string::npos){
			cfg1=cfg1.substr(cfg1.find("=")+1,cfg1.size()-cfg1.find("="));
			if(cfg1=="0"){
				cfgs=0;
			}else if(cfg1=="1"){
				cfgs=1;
			}else if(cfg1=="2"){
				cfgs=2;
			}else if(cfg1=="3"){
				cfgs=3;
			}else{
				cout<<"无效的配置，默认将string_config设置为1\n";
			}
				s=1;
		}else if(cfg1.find("numbers_config")!=string::npos){
			cfg1=cfg1.substr(cfg1.find("=")+1,cfg1.size()-cfg1.find("="));
			if(cfg1=="0"){
				cfgn=0;
			}else if(cfg1=="1"){
				cfgn=1;
			}else{
				cout<<"无效的配置，默认将numbers_config设置为1\n";
			}
			num=1;
		}else{
			cout<<"无效的配置，将使用默认值\n";
			b=0;
		}
		if(b!=0){
			cin>>cfg2;
			if(cfg2!="default"){
				if(cfg2.find("string_config")!=string::npos){
					cfg2=cfg2.substr(cfg2.find("=")+1,cfg2.size()-cfg2.find("="));
					if(cfg2=="0"){
						cfgs=0;
					}else if(cfg2=="1"){
							cfgs=1;
					}else if(cfg2=="2"){
							cfgs=2;
					}else if(cfg2=="3"){
							cfgs=3;
					}else{
							cout<<"无效的配置，默认将string_config设置为1\n";
					}
					s=1;
				}else if(cfg2.find("numbers_config")!=string::npos){
					cfg2=cfg2.substr(cfg2.find("=")+1,cfg2.size()-cfg2.find("="));
					if(cfg2=="0"){
						cfgn=0;
					}else if(cfg2=="1"){
						cfgn=1;
					}else{
						cout<<"无效的配置，默认将numbers_config设置为1\n";
					}
					num=1;
				}else{
					cout<<"无效的配置，将使用默认值\n";
				}
			}
		}
	}
	cout<<"正在准备生成(此操作约需要5秒钟)";
	DWORD t;
	while(1){
		t=rand()%5000;
		if(t<=5300&&t>=4700){
			break;
		}
	}
	Sleep(t);
	system("cls");
	for(int i=0;i<n;i++){
		for(int i=0;i<key.size();i++){
			if(key[i]=='-'){
				cout<<'-';
			}else if(rand()%2==1&&(cfgs==1||cfgs==2||cfgs==3)){
				if(cfgs==1){
					cout<<(char)(rand_ch()-32);
				}else if(cfgs==3){
					if(rand()%2==1){
						cout<<(char)(rand_ch()-32);
					}else{
						cout<<rand_ch();
					}
				}else if(cfgs==2){
					cout<<rand_ch();
				}
			}else if(cfgn==1){
				cout<<rand()%10;
			}
		}
		cout<<"\n";
	}
	system("pause");
	return 0;
} 
