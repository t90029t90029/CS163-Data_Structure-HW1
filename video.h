//Shang-Chun,Lin  CS163 program#1 assignment
#include <iostream>
#include <cctype>
#include <cstring>

//the purpose of this file is to declare the structs, the classes, and everything we need before I am working on the .cpp file

struct video
{
	char * name;
	char * teacher;
	char * topic;
	char * length;
};

struct item_node
{
	char * item_data;
	item_node * next_item;
};

struct node
{
	video data;
	node * next;
	item_node * next_item;
};

struct video_to_add	//just for the client program to test
{
	char name[21];
	char teacher[21];
	char topic[21];
	char length[16];
};

class list
{
	public:
		list();
		~list();
		int add(video_to_add & to_add);
		int remove(char matching_name[]);
		int add_item(char matching_name[],char item_to_add[]);
		int remove_item(char matching_name[],char item_to_remove[]);
		int display_item(char matching_name[]);
		int display();
	private:
		int add(node * & head,video_to_add & to_add);
		int remove(node * & head,char matching_name[]);
		int add_item(node * & head,item_node * & item_head,char matching_name[],char item_to_add[]);
		int remove_item(node * & head,item_node * & item_head,char matching_name[],char item_to_remove[]);
		int display_item(node * head,item_node * item_head,char matching_name[]);
		int display(node * head);
		node * head;
		item_node * item_head;
};

