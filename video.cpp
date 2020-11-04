//Shang-Chun,Lin  CS163 program#1 assignment
#include "video.h"

using namespace std;

//the purpose of this file is to implement those structs and classes that I have declared in .h file (working as ADT)

list::list()	//constructor
{
	head = NULL;
	item_head = NULL;
}
list::~list()	//destructor
{
	if(head)
	{
		delete head;
	}
	if(item_head)
	{
		delete item_head;
	}
	head = NULL;
	item_head = NULL;
}
int list::add(video_to_add & to_add)	//adding a new video into the list (this one is a wrapper function
{
	if(!to_add.name || !to_add.teacher || !to_add.topic || !to_add.length)
	{
		return 0;
	}
	return add(head,to_add);
}
int list::add(node * & head,video_to_add & to_add)	//adding a new video into the list
{
	if(!head)
	{
		head = new node;
		head->next = NULL;
		head->data.name = new char [strlen(to_add.name) + 1];
		strcpy(head->data.name,to_add.name);
		head->data.teacher = new char [strlen(to_add.teacher) + 1];
		strcpy(head->data.teacher,to_add.teacher);
		head->data.topic = new char [strlen(to_add.topic) + 1];
		strcpy(head->data.topic,to_add.topic);
		head->data.length = new char [strlen(to_add.length) + 1];
		strcpy(head->data.length,to_add.length);

		return 1;
	}
	return add(head->next,to_add);
}
int list::remove(char matching_name[])		//removing a certain video (this one is a wrapper function
{
	if(!head || !matching_name)
	{
		return 0;
	}
	return remove(head,matching_name);
}
int list::remove(node * & head,char matching_name[])	//removing a certain video
{
	if(!head)
	{
		return 0;
	}
	if(strcmp(head->data.name,matching_name) == 0)
	{
		node*temp = head->next;
		delete head;
		head=temp;	
		return 1;
	}
	return remove(head->next,matching_name);
}
int list::add_item(char matching_name[],char item_to_add[])	//adding an item into a specific video's item list (this one is a wrapper function
{
	if(!head || !matching_name || !item_to_add)		//if the video list is empty or the user didnt type in an name to search
	{
		return 0;
	}
	return add_item(head,item_head,matching_name,item_to_add);
}
int list::add_item(node * & head,item_node * & item_head,char matching_name[],char item_to_add[])	//adding an item into a specific video's item list
{
	if(!head)
	{
		return 0;
	}
	if(strcmp(head->data.name,matching_name) == 0)
	{
		if(!item_head)
		{
			item_head = new item_node;
			item_head -> next_item = NULL;
			item_head -> item_data = new char [strlen(item_to_add)+1];
			strcpy(item_head->item_data,item_to_add);
			return 1;
		}	
		item_node * temp = item_head;
		while(temp->next_item)
		{
			temp = temp -> next_item;
		}
		temp -> next_item= new item_node;
		temp = temp -> next_item;
		temp -> next_item = NULL;
		temp -> item_data = new char [strlen(item_to_add)+1];
		strcpy(temp->item_data,item_to_add);
		return 1;
	}
	return add_item(head->next,item_head,matching_name,item_to_add);
}
int list::remove_item(char matching_name[],char item_to_remove[])	//removing a certain item from a certain video's item list (this one is a wrapper function
{
	if(!head || !matching_name || !item_to_remove)
	{
		return 0;
	}
	return remove_item(head,item_head,matching_name,item_to_remove);
}
int list::remove_item(node * & head,item_node * & item_head,char matching_name[],char item_to_remove[])	//removing a certain item from a certain video's item list
{
	if(!head)
	{
		return 0;
	}
	if(strcmp(head->data.name,matching_name) == 0)		//find that video
	{
		if(!item_head)
		{
			return 0;
		}
		if(!item_head->next_item)
		{
			if(strcmp(item_head->item_data,item_to_remove) != 0)
			{
				return 0;
			}
			delete item_head;
			item_head = NULL;
			return 1;
		}
		item_node * current = item_head->next_item;
		item_node * previous = item_head;
		while(current)
		{
			if(strcmp(current->item_data,item_to_remove) == 0)	//find that item
			{
				item_node * temp = current->next_item;
				previous->next_item = temp;
				delete current;
				current = temp;
				return 1;
			}
			current = current->next_item;
			previous = previous->next_item;
		}
		return 0;
	}
	return remove_item(head->next,item_head,matching_name,item_to_remove);
}
int list::display_item(char matching_name[])		//displaying all items from a certain video's item list (this one is a wrapper function
{
	if(!head || !matching_name)
	{
		return 0;
	}
	return display_item(head,item_head,matching_name);
}
int list::display_item(node * head,item_node * item_head,char matching_name[])		//displaying all items from a certain video's item list
{
	if(!head)
	{
		return 0;
	}
	if(strcmp(head->data.name,matching_name) == 0)
	{
		item_node * temp = item_head;
		int count = 0;
		if(!temp)
		{
			return 0;
		}
		while(temp)
		{
			cout<<temp->item_data<<endl;
			temp = temp -> next_item;
			++count;
		}
		return count;
	}
	return display_item(head->next,item_head,matching_name);
}
int list::display()		//displaying all vidoes (this one is a wrapper function
{
	if(!head)
	{
		return 0;
	}
	return display(head);
}
int list::display(node * head)	//displaying all videos
{
	if(!head)
	{
		return 0;
	}
	cout<<"The name :"<<head->data.name<<endl
	<<"The teacher :"<<head->data.teacher<<endl
	<<"The topic :"<<head->data.topic<<endl
	<<"The length :"<<head->data.length<<endl;
	
	return display(head->next)+1;
}
