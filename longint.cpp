#include <iostream>
using namespace std;

#include "longint.h"

NaturalNumber::NaturalNumber (int n)
	{
  		ListNode* p = new ListNode;
  		p->digit = n % 10;
 		p->next = NULL;
  		p->prev = NULL;
  		msd = p;
  		lsd = p;
  		length = 1;
  
  		n = n / 10;
  		while (n > 0)
    		{
      			ListNode* p = new ListNode;
      			p->digit = n % 10;
      			p->next = msd;
    		 	p->prev = NULL;
     		 	msd->prev = p;
      			msd = p;
      			length++;
      			n = n / 10;
    		}
	}

NaturalNumber::~NaturalNumber ()
	{

	}

ostream& operator << (ostream& outs, const NaturalNumber& x) 
	{
		for  (ListNode* p=x.msd;  p!=NULL;  p=p->next)
			{
      			char c = p -> digit + '0';
      			outs << c;
   			}

  		return outs;
	}



NaturalNumber NaturalNumber::add (const NaturalNumber x) 
	{
		NaturalNumber* result = new NaturalNumber (0);
		
		int len_a = this->check_length();
		int len_b = x.check_length();
		
		//variables for carry, temp_addition, and node_ptrs
		int carry = 0; 
		int temp_addition = 0;
		ListNode* other_ptr;
		ListNode* a_ptr;
  		
  		//determines which linked list is longer, adjust variables accordingly
  		if (len_a > len_b)  
  			{
  				other_ptr = x.lsd;
  				a_ptr = this->lsd;
  			}
		else 
			{
  				other_ptr = this->lsd;
  				a_ptr = x.lsd;
  			}
  			
  		//addition calculation
  		for  (ListNode* p = a_ptr;  p!=NULL;  p=p->prev)
			{
				if (other_ptr != NULL) 
					{
						temp_addition = other_ptr->digit + p->digit + carry;
						carry = temp_addition / 10;
					}
						
				else if (other_ptr == NULL)
					{
						temp_addition = p->digit + carry;
						carry = temp_addition / 10;
					}

				ListNode* pt = new ListNode;
				pt->digit = temp_addition % 10;
				pt->next = result->msd;
    			pt->prev = NULL;
     			result->msd->prev = pt;
      			result->msd = pt;
      			result->length++;
      			
      			if (other_ptr!= NULL)
					other_ptr = other_ptr->prev;						

	  		}
	  		
	  	//adds last carry bit if applicable
	  	if (carry == 1) 
	  		{
	  			ListNode* pt = new ListNode;
				pt->digit = 1;
      			pt->next = result->msd;
    			pt->prev = NULL;
     			result->msd->prev = pt;
      			result->msd = pt;
      			result->length++;
	  		}
			
		//deltes extra (original) zero and returns
	  	result->delete_extra();
		return *result;
	}



NaturalNumber NaturalNumber::mult (const NaturalNumber x) 
	{
		NaturalNumber result (0);
		int len_a = this->check_length();
		int len_b = x.check_length();
		
		//variables for carry, temp_addition, and node_ptrs
		int carry = 0; 
		int temp_mult = 0;
		int count = 0;
		int outer_count = 0;
		int length = 0;
		ListNode* other_ptr;
		ListNode* a_ptr;
  		
  		//determines which linked list is longer, adjust variables accordingly
  		if (len_a > len_b)  
  			{
  				length = len_a;
  				other_ptr = this->lsd;
  				a_ptr = x.lsd;
  			}
		else 
			{
				length = len_b;
  				other_ptr = x.lsd;
  				a_ptr = this->lsd;
  			}
  			
  		for  (ListNode* p = a_ptr;  p!=NULL;  p=p->prev)
			{
			NaturalNumber temp_result(0);
			
			//multiply
			while (other_ptr != NULL)
				{
						temp_mult = (other_ptr->digit * p->digit +carry);
						carry = (temp_mult / 10);
						ListNode* pt = new ListNode;
						pt->digit = temp_mult % 10;
						pt->next = temp_result.msd;
    					pt->prev = NULL;
     					temp_result.msd->prev = pt;
      					temp_result.msd = pt;
      					temp_result.length++;
      			
						count++;			
	  					//adds last carry bit if applicable
	  					if ((carry != 0) && (count == length)) 
	  						{
	  							ListNode* pt = new ListNode;
								pt->digit = carry;
      							pt->next = temp_result.msd;
    							pt->prev = NULL;
     							temp_result.msd->prev = pt;
      							temp_result.msd = pt;
      							temp_result.length++;	
	  						}
	  				//increment ptr		
	  				other_ptr = other_ptr->prev;	
				}
				outer_count++;
				
				//add temp to running total
				temp_result.delete_extra();
				temp_result.shift_left(outer_count - 1);
				result = result.add(temp_result);
				
				//reinitialize
				count = 0;
				carry = 0;
  				if (len_a > len_b)  
  					{
  						other_ptr = this->lsd;
  					}
				else 
					{
  						other_ptr = x.lsd;
  					}
	  		}
		return result;
	}


int NaturalNumber::check_length () const
	{
		int length = 0;
		for  (ListNode* p=this->msd;  p!=NULL;  p=p->next)
			{
				length++;
	  		}
  		return length;
	}

void NaturalNumber::delete_extra () 
	{
		ListNode* p = this->lsd->prev;
		delete p->next;
		p->next = NULL;
		lsd = p;
		this->length--;
	}


void NaturalNumber::shift_left (int n)
	{
		for (int i = 0; i < n; i++)
			{
	  			ListNode* pt = new ListNode;
				pt->digit = 0;
      			pt->next = NULL;
    			pt->prev = this->lsd;
     			this->lsd->next = pt;
      			this->lsd = pt;
      			this->length++;	
			
			}
	}

