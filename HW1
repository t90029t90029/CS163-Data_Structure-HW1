//Shang-Chun,Lin  CS163 program#1 assignment
#include "video.h"

using namespace std;

//the purpose of this file is to test the structs and classes that I have declared in .h file (working as client program)

int main()
{
	list cs_class;
	video_to_add to_add;
	char matching_name[21] = {'\0'};	//the name of a video which is already in the list
	char item_to_add[21] = {'\0'};		//the name of an item to add
	char item_to_remove[21] = {'\0'};	//the name of an item to remove
	int answer = 0;
	cout<<"Please type a integer number to choose what you want to do."<<endl
	<<"1 for adding a new video,                 2 for removing a specific video, "<<endl
	<<"3 for adding an item to a specific video, 4 for removing an item from a specific video,"<<endl
	<<"5 for quitting the program."<<endl;
	cin>>answer;
	cin.ignore(100,'\n');

	while(answer != 5)
	{
		matching_name[21] = {'\0'};	//reset
		item_to_add[21] = {'\0'};
		item_to_remove[21] = {'\0'};

		if(answer == 1)
		{
			cout<<"Please input the name of the new video."<<endl;
			cin.get(to_add.name,100,'\n');
			cin.ignore(100,'\n');
			cout<<"Please input the name of the teacher of the new video."<<endl;
			cin.get(to_add.teacher,100,'\n');
			cin.ignore(100,'\n');
			cout<<"Please input the topic of the new video."<<endl;
			cin.get(to_add.topic,100,'\n');
			cin.ignore(100,'\n');
			cout<<"Please input the length of the new video."<<endl;
			cin.get(to_add.length,100,'\n');
			cin.ignore(100,'\n');
	
			if(cs_class.add(to_add))
			{
				cout<<"Now we have "<<endl<<cs_class.display()<<" video in the list."<<endl;
			}
		}

		if(answer == 2)
		{
			cout<<"Now we have "<<endl<<cs_class.display()<<" video in the list."<<endl;
			cout<<"Please type in the name of a video which you want to remove in the list."<<endl;
			cin.get(matching_name,21,'\n');
			cin.ignore(100,'\n');

			cout<<"You have removed "<<cs_class.remove(matching_name)<<" video."<<endl;
			cout<<"Now we have "<<endl<<cs_class.display()<<" video in the list."<<endl;
		}

		if(answer == 3)
		{
			cout<<"Now we have "<<endl<<cs_class.display()<<" video in the list."<<endl;
			cout<<"Please type in an new item's name."<<endl;
			cin.get(item_to_add,100,'\n');
			cin.ignore(100,'\n');
			cout<<"Please type in the name of the video that you want the item to add."<<endl;
			cin.get(matching_name,100,'\n');
			cin.ignore(100,'\n');

			cout<<"You have added "<<cs_class.add_item(matching_name,item_to_add)<<" item."<<endl;
			cout<<"Now we have the information about items for this video showm below."<<endl
			<<"We have "<<endl<<cs_class.display_item(matching_name)<<" items in that video."<<endl;
		}
		
		if(answer == 4)
		{
			cout<<"Now we have "<<endl<<cs_class.display()<<" video in the list."<<endl;
			cout<<"Please type in a video's name that is in the list."<<endl;
			cin.get(matching_name,100,'\n');
			cin.ignore(100,'\n');
			cout<<"Now we have the information about items for this video showm below."<<endl
			<<"We have "<<endl<<cs_class.display_item(matching_name)<<" items in that video."<<endl;
			cout<<"Please type in the name of an item that you want to remove from this video list."<<endl;
			cin.get(item_to_remove,100,'\n');
			cin.ignore(100,'\n');

			cout<<"You have removed "<<cs_class.remove_item(matching_name,item_to_remove)<<" item."<<endl;
			cout<<"Now we have the information about items for this video showm below."<<endl
			<<"We have "<<endl<<cs_class.display_item(matching_name)<<" items in that video."<<endl;
		}

		cout<<"Please type a integer number to choose what you want to do."<<endl
		<<"1 for adding a new video,                 2 for removing a specific video, "<<endl
		<<"3 for adding an item to a specific video, 4 for removing an item from a specific video,"<<endl
		<<"5 for quitting the program."<<endl;

		cin>>answer;
		cin.ignore(100,'\n');
	}


	return 0;
}
