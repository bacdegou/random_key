#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <Windows.h>
using namespace std;
char rand_ch() 
{
    return 'a'+rand()%26;;                
}
int main(){
	string key;
	cout<<"������key��ʽ��ÿ���ֶ�֮���á�-���ֿ�\n��:XXXXX-XXXXX-XXXXX-XXXXX-XXXXX\n";
	cin>>key;
	int n;
	cout<<"���������ɸ���\n";
	cin>>n;
	string cfg1,cfg2;
	int cfgs=1,cfgn=1;
	cout<<"��������������(Ĭ�ϻ��߲�֪����ʲô������defult)\n";
	cin>>cfg1;
	bool b=1,s=0,num=0;
	if(cfg1!="defult"){
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
				cout<<"��Ч�����ã�Ĭ�Ͻ�string_config����Ϊ1\n";
			}
				s=1;
		}else if(cfg1.find("numbers_config")!=string::npos){
			cfg1=cfg1.substr(cfg1.find("=")+1,cfg1.size()-cfg1.find("="));
			if(cfg1=="0"){
				cfgn=0;
			}else if(cfg1=="1"){
				cfgn=1;
			}else{
				cout<<"��Ч�����ã�Ĭ�Ͻ�numbers_config����Ϊ1\n";
			}
			num=1;
		}else{
			cout<<"��Ч�����ã���ʹ��Ĭ��ֵ\n";
			b=0;
		}
		if(b!=0){
			cin>>cfg2;
			if(cfg2!="defult"){
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
							cout<<"��Ч�����ã�Ĭ�Ͻ�string_config����Ϊ1\n";
					}
					s=1;
				}else if(cfg2.find("numbers_config")!=string::npos){
					cfg2=cfg2.substr(cfg2.find("=")+1,cfg2.size()-cfg2.find("="));
					if(cfg2=="0"){
						cfgn=0;
					}else if(cfg2=="1"){
						cfgn=1;
					}else{
						cout<<"��Ч�����ã�Ĭ�Ͻ�numbers_config����Ϊ1\n";
					}
					num=1;
				}else{
					cout<<"��Ч�����ã���ʹ��Ĭ��ֵ\n";
				}
			}
		}
	}
	cout<<"����׼������(�˲���Լ��Ҫ5����)";
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
