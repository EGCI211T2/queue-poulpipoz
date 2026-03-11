#ifndef queue_h
#define queue_h
#include "Node.h"
class Queue {
	NodePtr headPtr,tailPtr;
	int size;
public:
    void enqueue(int);
    int dequeue();
    Queue();
    ~Queue();
};


void Queue::enqueue(int x){
  NodePtr new_node= new NODE(x);
if(new_node){ 
    if(size == 0) headPtr = new_node;
    else
    {
        tailPtr->set_next(new_node);
    }
    tailPtr = new_node;
    size++;
    //cout<<"Enqueued value "<<tailPtr->get_value()<<endl;
    }
}

int Queue::dequeue(){
  if(size>0){
    NodePtr t = headPtr;
    int value = t->get_value();
    headPtr = headPtr->get_next();
    if(size == 1) tailPtr = NULL;
    size--;
    delete t;
    cout<<"dequeing "<<value<<endl;
    return value;
  }
  cout<<"Empty Queue"<<endl;
  return -1;
}


Queue::Queue(){
    size = 0;
    headPtr = NULL;
    tailPtr = NULL;
}
Queue::~Queue(){
    cout<<"Clearing queue"<<endl;
      while(size>0){
        dequeue();
      }    
      //cout<<"Deleted queue."<<endl;
}


#endif