#include<iostream>
#include<string.h>

#include "declarationsFile.h"


//#define DEBUG

using namespace std;



typedef struct word_s{

    char wordData[20];
	int  characterCountInWord = 0;	
	
}word_s_type;

typedef struct line_s{

    word_s_type WordDataInLine[10];
	int characterCountInLine = 0;
	int wordCountInLine = 0;	
	
}line_s_type;


//Global Array: create a pointer to line structure
line_s_type * line;

//Function declarations:
line_s_type * createLinePointer();
bool getLineInfo( char input_string[],int size );
int getTheCharacterCount(char input_string[],int size);
bool printData(line_s_type *line);
bool processCommands();
bool processOneWordCommands();
bool processTwoWordsCommands();

int main()
{
	char input_string[100];
	//give the string info as a string.
	//char input_string[100] = "Hello this is Harish from onePlus" ;
   // char input_string[100] = "pwd" ;

   while (1)
    {
        //Read line from user
        cout << "-->$";
	    cin.getline(input_string,100);

        #ifdef DEBUG
        //print the line to console
        cout << input_string <<endl;
        #endif

        int sizeOfArray = sizeof(input_string)/sizeof(input_string[0]);

        //cout << sizeOfArray << endl;
        
        getLineInfo(input_string,sizeOfArray);

        if( line != NULL )
        {
            processCommands();
        }
       else
        {
            cout << "failed to process the data read from console " << endl ;
            cout << "quitting" << endl;
           // break;
        }

        //Process the terminal logic:

        



        
        //clear previous data in structure.
        memset(line,0,sizeof(line_s_type));
    
    }// closing while
    



	return 0;
}

bool processCommands()
{
    #ifdef DEBUG
    cout <<"inside processCommands " << endl;
    #endif 

    switch (line->wordCountInLine)
    {
    case WORD_COUNT_ONE:
        processOneWordCommands();
        break;
    case   WORD_COUNT_TWO:
            break;
    case WORD_COUNT_THREE:
           break;
    case   WORD_COUNT_FOUR:
            break;
    
    default:
        cout << "no single command matched " << endl;
        break;
    }


    return TRUE;
}

bool processOneWordCommands()
{
    #ifdef DEBUG
    cout <<"inside processOneWordCommands " << endl;
    #endif

    if( !strncmp(line->WordDataInLine[0].wordData,"help",line->WordDataInLine[0].characterCountInWord) ){
        #ifdef DEBUG
        cout <<"Help command detected " << endl;
        #endif

            cout << "********Valid commands are*******" << endl;
     	    cout << "quit" << "\t";
     	    cout << "help" << "\t";
     	    cout << "name" << "\t";
     	    cout << "ls"  << "\t" ;
     	    cout << "pwd"  << endl;
     	    //cout << "Valid commands:" << endl;
     	    //cout << "Valid commands:" << endl;
     	    //cout << "Valid commands:" << endl;
    }
    else if( !strncmp(line->WordDataInLine[0].wordData,"name",line->WordDataInLine[0].characterCountInWord) ){

    }
    else if( !strncmp(line->WordDataInLine[0].wordData,"ls",line->WordDataInLine[0].characterCountInWord) ){
         cout << system("dir") << endl;
    }
    else if( !strncmp(line->WordDataInLine[0].wordData,"pwd",line->WordDataInLine[0].characterCountInWord) ){
	   	   cout << system("cd") << endl;
    }
    else if( !strncmp(line->WordDataInLine[0].wordData,"name",line->WordDataInLine[0].characterCountInWord) ){
	   	   cout << "Hello This is  CPP Toddlers Terminal " << endl;
    }
    else if( !strncmp(line->WordDataInLine[0].wordData,"quit",line->WordDataInLine[0].characterCountInWord) ){
	   	    cout << "exiting the shell" << endl;
               exit(0);
     	  //  break;
    }
    else
    {
        cout << "invalid command" << endl;
    }
    

    return TRUE;
}


//Return the pointer to one and only one line structure.

line_s_type * createLinePointer()
{
	static line_s_type line1;
	
	#ifdef DEBUG
	cout << "sizeof structure: " << sizeof(line1) << endl;
	#endif

	return &line1;
}


int getTheCharacterCount(char input_string[],int size)
{
	int length=0;
	while(input_string[length] != '\0')
	{
		length++;
	}

	return length;
}



bool getLineInfo( char input_string[],int size )
{
	
  //	line_s_type * line = createLinePointer();
   line = createLinePointer();
  	line->characterCountInLine = getTheCharacterCount(input_string,size);
  	//line->wordCountInLine = getTheWordCount(input_string,line->characterCountInLine);
  	//line->WordDataInLine = getWordDataInfo(input_string,line->characterCountInLine);


  	//int wordCount =0;
	int wordCount =0;

	//column count in a word.
	int columnCount=0;

	for (int i = 0; i <= line->characterCountInLine; ++i)
	{
		if( input_string[i] == '\0' )
		{
			#ifdef DEBUG
			line->WordDataInLine[wordCount].wordData[columnCount] = '\0';
			cout << endl ;
			#endif

			line->WordDataInLine[wordCount].characterCountInWord =  columnCount   ;

			#ifdef DEBUG
			cout << "line->WordDataInLine[" << wordCount << "].characterCountInWord:  " << line->WordDataInLine[wordCount].characterCountInWord <<endl;
			cout << "columnCount: " << columnCount << endl;
			#endif

			columnCount = 0;
			wordCount ++;

			//close the word with \0
			//line->WordDataInLine[wordCount].wordData[columnCount] = '\0';	


		}
		else if(input_string[i] == ' ')
		{
			line->WordDataInLine[wordCount].wordData[columnCount] = '\0';		

			//cout << "2: " << line->WordDataInLine[wordCount].wordData[columnCount] << endl ;
			//cout << "2: line->WordDataInLine[" << wordCount << "].wordData[" << columnCount << "] " << line->WordDataInLine[wordCount].wordData[columnCount] << endl;
			#ifdef DEBUG
			cout << endl ;
			#endif


			//Reset the column count to zero for starting the new word.
			//Before resetting the coulmn count, save the column count to structure.

			line->WordDataInLine[wordCount].characterCountInWord =  columnCount   ;

			#ifdef DEBUG
			cout << "line->WordDataInLine[" << wordCount << "].characterCountInWord:  " << line->WordDataInLine[wordCount].characterCountInWord <<endl;
			cout << "columnCount: " << columnCount << endl;
			#endif


			columnCount = 0;

			

			//increment the word count
			wordCount++;
		}
		else
		{
    		//else count:
    		line->WordDataInLine[wordCount].wordData[columnCount] = input_string[i]  ;

			#ifdef DEBUG
			cout << "1: line->WordDataInLine[" << wordCount << "].wordData[" << columnCount << "] " << line->WordDataInLine[wordCount].wordData[columnCount] << endl;
			#endif

			//increment the columnCount:
			columnCount++;
		}
	}

	line->wordCountInLine = wordCount;

	//cout << "characterCountInLine: " << line->characterCountInLine << endl; 
  	//cout << "wordCountInLine: " << line->wordCountInLine << endl;

    #ifdef DEBUG
	printData(line);
    #endif

  	return TRUE;
	
}

bool printData(line_s_type *line)
{
    
	cout << "characterCountInLine: " << line->characterCountInLine << endl; 
  	cout << "wordCountInLine: " << line->wordCountInLine << endl;
	//cout << "wordCountInLine: " << line->wordCountInLine << endl;
	
	cout << "=================================================================" << endl;
    
	for (int i = 0; i < line->wordCountInLine; i++)
	{
		#ifdef DEBUG
		cout << "wordCountInLine: " << line->WordDataInLine[i].characterCountInWord << endl;
		#endif

		for (int j = 0; j < line->WordDataInLine[i].characterCountInWord; j++)
		{
			cout << "line->WordDataInLine[" << i << "].wordData[" <<  j << "]" << line->WordDataInLine[i].wordData[j] << endl ;
		}
		
		cout << endl;
	}
	

	

	return TRUE;
}




