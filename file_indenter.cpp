///code to indent an unindented file
 //input file : "file.txt"
 //output file: "newfile.txt"
 
 //NAME-ATUL MISHRA
 //ROLL-17CS8017
 
#include<bits/stdc++.h>
using namespace std;

int main()
{
	FILE *f,*fn;                                                //two files:- original (f) and new file (fn) 
	int curly_braces=0,i;                                       //curly_braces counts '{' encountered so far
	char c,c_old;                                               //variables to store current and previous character
	f=fopen("file.txt","r");                                    //open original file in read only mode
	fn=fopen("newfile.txt","w");                                //create a newfile in write only mode
	while(!feof(f))
	{
		c=getc(f);                                                //reads the file ( one character at a time )
		if(c=='{')                                                
		{
			curly_braces=curly_braces+1;                                     //if a '{' is encountered ,indent using newlines and calculated no. of spaces 
			putc('\n',fn);
			for(i=1;i<curly_braces;i++) putc('\t',fn);
			putc(c,fn);
			putc('\n',fn);
			for(i=1;i<curly_braces+1;i++) putc('\t',fn);	
			
		}
		else if(c=='}')                                             //if a '}' is encountered, indent using newlines, decreasing no. of spaces
		{
			putc('\n',fn);
			for(i=1;i<curly_braces;i++) putc('\t',fn);
			putc(c,fn);
			curly_braces=curly_braces-1;
		}
		else if((c=='\n') &&(c_old=='{')) continue;
		else if(c=='\n')                                             //if '\n' is encountered, place the next line with proper no. of spaces
		{
			putc(c,fn);
			for(i=1;i<curly_braces+1;i++) putc('\t',fn);
			
		}
		else
		putc(c,fn);                                                 //print the character in the new file
		c_old=c;
	}
	fclose(f);
	fclose(fn);                                                     //close both files
	cout<<"successfull"<<endl;
}
