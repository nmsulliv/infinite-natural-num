#include <iostream>
using namespace std;

#include "longint.h"

int main()
{
  char cmd;
  cout << "Available commands: a (add), m (multiply), f (factorial), and q (quit).\n";
  cout << "command: ";
  cin >> cmd;
  while (cmd != 'q' && cmd != 'Q')
    {
      if  (cmd == 'a' || cmd == 'A')
		{
	  		int left, right;
	  		cout << "left operand = ";
	  		cin >> left;
	  		cout << "right operand = ";
	  		cin >> right;
      
	  		NaturalNumber x(left), y(right);
	  		cout << x << " + " << y << " = " << x.add(y) << '\n';
		}
      else if  (cmd == 'm' || cmd == 'M') 
      {
	  		int left, right;
	  		cout << "left operand = ";
	  		cin >> left;
	  		cout << "right operand = ";
	  		cin >> right;
      
	  		NaturalNumber x(left), y(right);
	  		cout << x << " * " << y << " = " << x.mult(y) << '\n';
		}
      else if  (cmd == 'f' || cmd == 'F') 
      {
	 	 	int n;
	  		cout << "to compute n!, n = ";
	  		cin >> n;
	  		NaturalNumber x(1);
	  		for  (int i=1;  i<=n;  i++) {
	      		NaturalNumber y(i);
	      		x = x.mult(y);
	    	}
  
	  		cout << x << "\n";
		}
      else
			cout << "illegal command \'" << cmd << "\'\n";

      	cout << "command: ";
      	cin >> cmd;
    }
}
