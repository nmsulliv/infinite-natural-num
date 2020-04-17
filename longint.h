struct ListNode {
  char digit;
  ListNode* next;
  ListNode* prev;
};


class NaturalNumber {
 	private:
  		ListNode* msd;  // first
		ListNode* lsd;  // last
		int length;


		void shift_left (int n); 

		int check_length () const;
		void delete_extra ();

 	public:
  		NaturalNumber (int n);
		~NaturalNumber ();
		
  		NaturalNumber add (const NaturalNumber x);
  		NaturalNumber mult (const NaturalNumber x);
  		
  		friend ostream& operator<< (ostream& outs, const NaturalNumber& x);
};


  
  
