#include <iostream>
#include <string>
#include <vector>
using namespace std;

 class User{
 	private:
 		string username,password;
 	public:
 	 User(string uname,string pass){
 		username=uname;
 		password=pass;
	 }
	 string  getname(){
	 	return username;
	 }
	 string getpass(){
	 	return password;
	 }
 };
class Usermanager{
	private:
	vector<User> users;
	public:
		void RegisterUser(){
			string username,password;
			cout<<"ENTER USERNAME: ";
			cin>>username;
			cout<<"ENTER PASSWORD: ";
			cin>>password;
			User newuser(username,password);
			users.push_back(newuser);
			cout<<"\t\t   USER REGISTERED SUCCESSFULLY"<<endl;
			
		}
		bool LoginUser(string name,string pass){
			for(int i=0; i<users.size(); i++){
				if(users[i].getname()==name&&users[i].getpass()==pass){
					cout<<"LOGIN SUCCESSFULL"<<endl;
					return true;
				}
				}
			cout<<"INVALID USERNAME OR PASSWORD"<<endl;
			return false;
		}
		void showusers(){
			cout<<"\t\t --------USERS LIST------"<<endl;
			for(int i=0; i<users.size(); i++ ){
				cout<<"\t\t "<<users[i].getname()<<endl;
			}
		}
		void searchUser(string username){
		    for(int i=0; i<users.size(); i++){
		        if(users[i].getname()==username){
		            cout<<"\t\t USER FOUND"<<endl;
		        }
		        else{
		            cout<<"USER NOT FOUND SORRY"<<endl;
		        }
		    }
		    
		}
	    void deleteuser(string username){
	           for(int i=0; i<users.size(); i++){
	               if(users[i].getname()==username){
	                   users.erase(users.begin()+i);
	                   cout<<"\t\t USER REMOVED SUCCSSFULLY"<<endl;
	               }
	           }
	           
	       }

};
int main(){
	Usermanager usermanager;
	int op;
	char ch;
	do
	{
	cout<<"************************************"<<endl;
	cout<<"\t\t      1.REGISTER USER    "<<endl;
	cout<<"\t\t      2.LOGIN            "<<endl;
	cout<<"\t\t      3.SHOW USERLIST    "<<endl;
	cout<<"\t\t      4.SEARCH USER      "<<endl;
	cout<<"\t\t      5.DELETE USER      "<<endl;
	cout<<"\t\t      6.EXIT             "<<endl;
	cout<<"\t\t  ENTER YOUR CHOICE:";
	
	cin>>op;
	switch(op){
		case 1:{
			
			usermanager.RegisterUser();
			break;
		}
		case 2:{
			string username,password;
			cout<<"ENTER USERNAME AND PASSWORD";
			cin>>username;
			cin>>password;
			usermanager.LoginUser(username,password);
			break;
		}
		case 3:{
			usermanager.showusers();
			break;
		}
		case 4:{
		    string uname;
		    cout<<"ENTER USERNAME:";
		    cin>>uname;
		    usermanager.searchUser(uname);
		    break;
		    
		}
		case 5:{
		    string name;
		    cout<<"enter username to be deleted"<<endl;
		    cin>>name;
		    usermanager.deleteuser(name);
		    break;
		}
		case 6:
		        exit(1);
		
	}
	cout<<"WANT TO CONTINUE? Y/N"<<endl;
	    cin>>ch;
    }while(ch=='y'||ch=='Y');

	return 0; 
	           
}
		


