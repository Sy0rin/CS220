#include <iostream>
#include "miniDList.h"
#include "miniDListQueue.h"
#include "miniDListStack.h"
#include "miniArrayQueue.h"
#include "miniArrayStack.h"
#include "FeetInches.h"

using namespace std;

void setFeetInches(FeetInches &f, int feet, int inches)
{
    f.setFeet(feet);
    f.setInches(inches);
}

int main() {
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "Integer Doubly Linked List Tester" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << endl;

	miniDList<int> l1;

	cout << l1.size() << endl;

	l1.addFront(25);
	l1.addFront(56);
	

	l1.display();
	cout << l1.size() << endl;

	cout << endl;

	l1.addBack(55);
	l1.addBack(-47);

	l1.display();
	cout << l1.size()  << endl;
	l1.removeFront();
	l1.removeFront();
	l1.removeBack();
	l1.display();
	cout << l1.size() << endl;

	miniDList<int> l2=l1;
	l2.addBack(1000);
	l2.addFront(-1000);
	l2.display();
	bool c=l2.contains(1000);
	if(c)
	   cout << "l2 containes 1000"<<endl;


cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "integer ArrayStack Tester" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << endl;
  miniArrayStack<int> iArrS; // TODO
  iArrS.push(4);
  iArrS.push(3);
  iArrS.push(2);
  iArrS.push(1);
  cout<< iArrS.getTop()<<endl;
  iArrS.printStack();
  iArrS.pop();
  
  iArrS.printStack();

cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "double DListStack Tester" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << endl;
  miniDListStack<double> dDLStack; // TODO
  dDLStack.push(4.8);
  dDLStack.push(3.6);
  dDLStack.push(2.4);
  dDLStack.push(1.3);
  cout<< dDLStack.top() <<endl;
  dDLStack.printStack();
  dDLStack.pop();

  dDLStack.printStack();

cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "integer DListQueue Tester" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << endl;
  miniDListQueue<int> iDLQ; // TODO
iDLQ.enqueue(3);
iDLQ.enqueue(4);
iDLQ.enqueue(6);
cout<< iDLQ.front()<<endl;
miniDListQueue<int> iDLQ2=iDLQ;
iDLQ.printQueue();
iDLQ2.printQueue();
iDLQ.dequeue();
iDLQ.dequeue();

iDLQ.printQueue();

cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "DList Stack of FeetInch Tester" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << endl;
miniDListStack<FeetInches> FeetDLstack;
    FeetInches f(5, 2);

    cout << FeetDLstack.size() << endl;

    FeetDLstack.push(f);
    setFeetInches(f, 3, 3);
    FeetDLstack.push(f);
    setFeetInches(f, 7, 9);
    FeetDLstack.push(f);
    setFeetInches(f, 2, 17);
    FeetDLstack.push(f);
    setFeetInches(f, 1, 4);
    FeetDLstack.push(f);

    FeetDLstack.printStack();
    cout << FeetDLstack.size()  << endl;
    
    cout << endl;

cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "DList Queue of FeetInch Tester" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << endl;
miniDListQueue<FeetInches> FeetDLqueue;
    FeetInches q(5, 2);

    cout << FeetDLqueue.size() << endl;

    FeetDLqueue.enqueue(q);
    setFeetInches(q, 3, 3);
    FeetDLqueue.enqueue(q);
    setFeetInches(q, 7, 9);
    FeetDLqueue.enqueue(q);
    setFeetInches(q, 2, 17);
    FeetDLqueue.enqueue(q);
    setFeetInches(q, 1, 4);
    FeetDLqueue.enqueue(q);

    FeetDLqueue.printQueue();
    cout << FeetDLqueue.size()  << endl;
    
    cout << endl;

  cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "double ArrayQueue Tester" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << endl;
  miniArrayQueue<double> dArrQ;
dArrQ.enqueue(3.5);
dArrQ.enqueue(4.6);
dArrQ.enqueue(6.7);
cout<< dArrQ.getFront()<<endl;
miniArrayQueue<double> dArrQ2=dArrQ;
dArrQ.printQueue();
dArrQ2.printQueue();
dArrQ.dequeue();
dArrQ.dequeue();
dArrQ.printQueue();
dArrQ.dequeue();
dArrQ.dequeue();
	return 0;
}

