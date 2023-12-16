#include <iostream>

using namespace std;

void welcomeScreen(char *listKey){
	std::cout <<"-----------------" <<std::endl;
	cout <<"--Welcome Directory--"<<std::endl;
	cout <<"1-Add New Person"<<std::endl;
	cout <<"2-Delete Person"<<std::endl;
	cout <<"3-List and Update" << std::endl;
	cout <<"4-Find Person" << std::endl;
	cout <<"-----------------" <<std::endl;
	cin >> *listKey; cin.ignore();
}

void addNew(string name[],string surname[],string phone[],int *counter){
	
	cout <<"-----------------" <<std::endl;
	cout << "Name: ";
	getline(cin,name[*counter]);
	cout << "Surname: ";
	getline(cin,surname[*counter]);
	cout << "Phone: ";
	getline(cin,phone[*counter]);
	(*counter)++;
}

void deleteNew(string name[],string surname[],string phone[],int *counter){
	
	int temp;
	cout << "---LIST---" << std::endl;
	for(int i = 1; i < *counter; i++){

		cout << i << "-" << name[i] << " " << surname[i] << " " << phone [i] <<std::endl;
	}
	
	cout << "Select a number to delete: ";
	cin >> temp; cin.ignore();
	if(*counter >2){
	
	for(int i = temp; i < *counter-1; i++){
		
		name[i] = name[i+1];
		surname[i] = surname[i+1];
		phone[i] = phone[i+1];} 
		(*counter)--;
		}
	else if(*counter ==1)
	
	cout << "There is no one here!" << std::endl;
	
	else if(*counter == 2){
		(*counter)--;
	}
	
	
	cout << "--Successful--" << std::endl;
}


void showList(string name[],string surname[],string phone[],int *counter){
	
	cout << "---LIST---" << std::endl;
	
	for(int i = 1; i < *counter; i++){
		
		cout << i << "-" << name[i] << " " << surname[i] << " " << phone[i] <<std::endl;
	}
	
	
}

void changeList(string name[],string surname[],string phone[],int counter){
	
	int temp;
	
	do{
		
	cout << "Select person to change: ";
	cin >> temp; cin.ignore();
	if(temp >= counter || temp < 1)
	cout << "Invalid number!" << std::endl;
	}while(temp >= counter || temp < 1);

	cout << "Name: ";
	getline(cin,name[temp]);
	cout << "Surname: ";
	getline(cin,surname[temp]);
	cout << "Phone: ";
	getline(cin,phone[temp]);
	
}

void findPerson(string name[],string surname[],string phone[],int *counter){
	
	string a; int temp=99;
	cout << "Enter Person's Surname: ";
	getline(cin,a);
	
	for(int i =1; i<*counter;i++){
		
		if(a == surname[i])
		temp = i;
	}
	
	if(temp!=99){
			cout <<"Name: " << name[temp] << endl;
			cout <<"Surname: " << surname[temp]<<endl; 
			cout <<"Phone: " << phone[temp]<<endl;
	}
	else
	cout << "Couldn't find." <<std::endl;

}


int main(){

std::string directory_name[50],directory_surname[50],directory_phone[50];

char checker,listKey,updateChecker;
int counter = 1;


do{
	
	welcomeScreen(&listKey);
	
	switch(listKey){
		
		case '1':
			addNew(directory_name,directory_surname,directory_phone,&counter);
		cout << "--Succesfull--"<<std::endl;
		break;
		
		
		case '2':
			deleteNew(directory_name,directory_surname,directory_phone,&counter);
		break;
		
		case '3':
			showList(directory_name,directory_surname,directory_phone,&counter);
			
			do{
				cout << "Do you want to update: Y-N";
					cin >> updateChecker; cin.ignore(0);
				if(updateChecker == 'Y'|| updateChecker == 'y')
			changeList(directory_name,directory_surname,directory_phone,counter);
				else if(updateChecker == 'N'|| updateChecker == 'n')
				break;
				else
				cout << "Invalid enter!" << std::endl;
	
			}while(updateChecker != 'Y' && updateChecker !='y' && updateChecker !='N' && updateChecker !='n');
		break;
		
		case '4':
				findPerson(directory_name,directory_surname,directory_phone,&counter);
		break;
		
		default:
			cout<< "Invalid Enter!(1-2-3-4)" << std::endl;
		break;
			}
			
		do{
		
		cout << "Do you want to continue(Y-N): ";
		cin >> checker; cin.ignore();
		if(checker != 'Y' && checker !='y' && checker !='N' && checker !='n')
		cout << "Invalid enter!" << std::endl;
		
		}while(checker != 'Y' && checker !='y' && checker !='N'&& checker !='n');
		
		if(checker == 'N' || checker == 'n')
		break;
		
	}while(checker == 'Y' || checker == 'y');
	
	
	cout << "See you!";
	return 0;
}



