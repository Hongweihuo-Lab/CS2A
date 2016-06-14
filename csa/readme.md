#Compressed-Suffix-Array(CSA)

##What is it?
CSA is a practical implementation of the compressed suffix arrays (CSA) theory, 
 introduced by Roberto Grossi and Jeffrey Scott Vitter. CSA retains the high-order 
 entropy-compressed theoretical performance and introduces some improvements 
 in practice.
	 
	 counting: compute the number of occurrences of a pattern P in the text T.   
	 locating: report the list of positions, where P occurs in T.    
	 extract: extraction of arbitrary portions of text T.    
## How to use it?
###just for fun
	 step 1:download or clone it
	 step 2:make
	 step 3:run my_csa
###build your own program
	 step 1:download or clone it
	 step 2:make
	 step 3:include CSA.h
	 step 4: g++ your_program.cpp -o xx -csa.a

###example
	```cpp
	#include"CSA.h"
	#include<iostream>
	using namespace std;
	int main()
	{
		CSA csa("filename");
		int num;
		csa.Counting("the",num);
		cout<<"pattern the occs "<<num<<" times"<<endl;
		int *pos;
		csa.Locating("love",num,pos);
		cout<<"pattern love occs "<<num<<" times"<<endl;
		cout<<"all the positions are:";
		for(int i=0;i<num;i++)
			cout<<pos[i]<<endl;
		delete [] pos;//it's your duty to delete pos.
		pos=NULL;

		char  sequence[len+1]={0};
		int start=0;
		int len =20;
		csa.Extracting(start,len,sequence);
		cout<<"T[start...start+len-1] is "<<sequence<<endl;

		csa.Save("index.csa");//serialize the fm object to file index.csa
		CSA csa2;
		csa2->Load("index.csa");//restore the fm object from file index.csa

		return 0;
	}
	```
##ChangeLog  
2014.6.7:We can borrow hybrid-ideas in My Czip project,mix pure-gamma and rl-gamma,It be helpful for compression-ratio.

2014.6.7:fix a memory-leak bug in CSA.Decompress function.
