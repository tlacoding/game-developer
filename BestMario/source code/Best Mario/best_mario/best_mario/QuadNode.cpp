#include "QuadNode.h"
#include "trace.h"

QuadNode::QuadNode(void){
	LTNode = LBNode = RTNode = RBNode = NULL;
}

QuadNode::QuadNode(int left, int top, int right, int bottom, string iid){
	rect.left = left;
	rect.top = top;
	rect.right = right;
	rect.bottom = bottom;
	
	id = iid;
	LTNode = LBNode = RTNode = RBNode = NULL;
}

QuadNode::~QuadNode(void){}

void QuadNode::GetListObj(string ilist){
	
	if (ilist.compare("0") == 0)
	{
		//trace(L"return");
		return;
	}

	istringstream iss(ilist);
	
	while(iss.good()){
		string id;
		iss >> id;
		int id_temp = atoi(id.c_str());
		//trace(L"%d", id_temp);
		if (id_temp == 0)
		{
			//trace(L"return cause id = 0");
			return;
		}
		list<StaticObject*>::iterator ii;
		for (ii = GlobalHandler::listStaticObj.begin(); ii != GlobalHandler::listStaticObj.end(); ++ii)
		{
			if (id_temp == (*ii)->id)
			{
				listObject.push_back((*ii));				
			}
		}	
	}

	iss.str(string());
	iss.clear();
	trace(L"Clear ma khong biet duoc khong");
}

void QuadNode::Release(){
	list<StaticObject*>::iterator ii;
	StaticObject *temp;
	while(!listObject.empty()){
		list<StaticObject*>::iterator it = listObject.begin();
		temp = (*it);
		listObject.pop_front();
		delete temp;
	}

}

void QuadNode::Render(){
	
	list<StaticObject*>::iterator it;
	for(it = listObject.begin(); it != listObject.end(); ++it ){
		(*it)->Render();		
	}

}

void QuadNode::Render(int map_level){
	
	list<StaticObject*>::iterator it;
	for(it = listObject.begin(); it != listObject.end(); ++it ){
		if ((*it)->map_level == map_level)
			(*it)->Render();
	}

}

void QuadNode::Update(){

	list<StaticObject*>::iterator it;
	for(it = listObject.begin(); it != listObject.end(); ++it ){
		(*it)->Update();
	}	
}