#include<stdio.h>
#include<conio.h>

struct data{
	int roll = 0;
	char name[20];
	double math = 0;
	double urdu = 0;
	double isl = 0;
	double physics = 0;
	double english = 0;
};

struct tempdata{
	int roll = 0;
	char name[20];
	double math = 0;
	double urdu = 0;
	double isl = 0;
	double physics = 0;
	double english = 0;
};

// These three function are of void data type because they do not return anything
void insert();
void update();
void display();

// Globaling defing the variable as they are used in different functions
FILE *fp;
FILE *temp;
struct data b[20];
struct tempdata t[20];
int roll_number;

int main(){
	
	int choice, num;
	while(1){ // 1 means true, here the condition of while loop is always true
	
		printf("================================================================\n");
		printf("\t\t\tPlease Select\n");
		printf("================================================================\n");
		printf("1: Insert Data\n");
		printf("2: Update Data\n");
		printf("3: Display Data\n");
		printf("4: Exit\n");
		printf("================================================================\n");
		printf("Select: ");
		scanf("%d",&num);
		printf("================================================================\n");
		if(num == 1)
		{
			while(1){ // do while loop atleast executes once either the condition is true or false, that's why, it is used here to atleast run once and ask if the user wants to ru  again
				insert(); //Calling insert function
				printf("================================================================\n");
				printf("Do you want to enter another info: \n1: Yes\n2: NO\nSelect: ");
				scanf("%d",&choice);
				printf("================================================================\n");
				if(choice == 1){
					break;
				}
			}
		}
		else if(num == 3)
		{
			display(); // Calling Display function
		}
		else if(num == 2) 
		{
			update(); // Calling Update function
		}
		else if(num == 4){ 
			break; // Breaking the loop
		}
		else
		{
			printf("Invalid Selection\n");
		}
	}
	return 0;
}


void insert(){ // Function to insert data

	fp=fopen("data.txt","rb"); // Opening File in read mode
	if(fp==NULL) // Checkinf if file does not exist
	{ // This Condition will only be true when the file data.txt does not exists
		int count=0;
		fp=fopen("data.txt","wb"); // Creating File write mode automatically creates file even if it doen not exists
		for(int i=0;i<20;i++){  // writting data to data structure 
			printf("\nEnter Student's Name: " );
			fflush(stdin);
			scanf("%s",&b[i].name);
			printf("Enter Studnets's Roll Number: ");
			fflush(stdin);
			scanf("%d",&b[i].roll);
			printf("Enter Maths Marks: ");
			fflush(stdin);
			scanf("%lf",&b[i].math);
			fflush(stdin);
			printf("Enter Physics Marks: ");
			fflush(stdin);
			scanf("%lf",&b[i].physics);
			printf("Enter Islamiat Marks: ");
			fflush(stdin);
			scanf("%lf",&b[i].isl);
			printf("Enter English Marks: ");
			fflush(stdin);
			scanf("%lf",&b[i].english);
			printf("Enter Urdu Marks: ");
			fflush(stdin);
			scanf("%lf",&b[i].urdu);
			count++;
		}
		fwrite(b,sizeof(struct data),20,fp); //writting the whole structure b to the file
		printf("Data stored successfully\n");
		printf("================================================================\n");
		fclose(fp); // closing file
	}
	else
	{ // If the file data.txt already exists this condition will be executed
		fread(t,sizeof(struct data),20,fp); // Reading the data from data.txt file into tempData structure
		int count=0;
		for(int i=0;i<20; i++){ // loop to copy data from tempdata stucture to data structure
			
			// it is only for the first index of the structure
			for(int str3=0;str3<20;str3++){  // loop for copying name since name is an char array it requires a loop to copy it to another char array
				b[0].name[str3]=t[0].name[str3];
			}
			b[0].roll = t[0].roll;
			b[0].math = t[0].math;
			b[0].english = t[0].english;
			b[0].isl = t[0].isl;
			b[0].physics = t[0].physics;
			b[0].urdu = t[0].urdu;
				
			if(i>0 && b[i-1].roll!=t[i].roll){ //This condition is to avoid dupication of data while copying data from tempdata structure to data structure it checks current roll number of tempdata to the previous roll number of data if both the roll numbers are true the condition becomes true and the data is copied else it does not copy anything
				for(int str3=0;str3<20;str3++){
					b[i].name[str3]=t[i].name[str3];
				}
				b[i].roll = t[i].roll;
				b[i].math = t[i].math;
				b[i].english = t[i].english;
				b[i].isl = t[i].isl;
				b[i].physics = t[i].physics;
				b[i].urdu = t[i].urdu;
				count++; // everytime the condition is true count is increased by one which is used to write the data from user input to the next index of the data sturcture
			}
		}
		
		//writting user inputted data to the next index of the data structure
		printf("\nEnter Student's Name: " );
		fflush(stdin);
		scanf("%s",&b[count].name);
		printf("Enter Studnets's Roll Number: ");
		fflush(stdin);
		scanf("%d",&b[count].roll);
		printf("Enter Maths Marks: ");
		fflush(stdin);
		scanf("%lf",&b[count].math);
		fflush(stdin);
		printf("Enter Physics Marks: ");
		fflush(stdin);
		scanf("%lf",&b[count].physics);
		printf("Enter Islamiat Marks: ");
		fflush(stdin);
		scanf("%lf",&b[count].isl);
		printf("Enter English Marks: ");
		fflush(stdin);
		scanf("%lf",&b[count].english);
		printf("Enter Urdu Marks: ");
		fflush(stdin);
		scanf("%lf",&b[count].urdu);
			
		fclose(fp); // Closing the file, as it was open in read mode.
		fp=fopen("data.txt","wb"); // Opening the file again write mode in order to write data because in read mode data cannot be written
		fwrite(b,sizeof(struct data),20,fp); // Writting the completely copied data from tempdata and user inputed data to the file through data structure
		printf("Data stored successfully\n");
		printf("================================================================\n");
		fclose(fp);
	}
}


void display(){ // function to display data
	
	fp=fopen("data.txt","rb"); // Opening file in read mode
	fread(b,sizeof(struct data),20,fp); // Reading the complete file in data sturcture
	printf("Enter Student's Roll Number: "); 
	scanf("%d",&roll_number);
	printf("================================================================\n");
	printf("\t\tStudent's Marksheet: \n");
	printf("================================================================\n");
	for(int i=0;i<20;i++) //Loop to itrate through the data structure
	{
		if(roll_number == b[i].roll) // Condition to check if the Roll number exists in the data structure
		{
			// Displaying Particular data from data structure
			printf("Students's Name: %s\n",b[i].name);
			printf("Student's Roll Number: %.d\n",b[i].roll);
			printf("================================================================\n");
			printf("Maths : %.2lf\n",b[i].math);
			printf("Islamiat : %.2lf\n",b[i].isl);
			printf("Physics : %.2lf\n",b[i].physics);
			printf("Urdu : %.2lf\n",b[i].urdu);
			printf("English : %.2lf\n",b[i].english);
			printf("================================================================\n");
			double per = (b[i].math+b[i].physics+b[i].urdu+b[i].isl+b[i].english)*100/500;
			printf("Percentage : %.2lf\n",per);
			if(per>=80 && b[i].math>=50 && b[i].physics>=50 && b[i].urdu>=50 && b[i].isl>=50 && b[i].english>=50)
			{
				printf("Grade : A+");
			}
			else if(per>=70 && b[i].math>=50 && b[i].physics>=50 && b[i].urdu>=50 && b[i].isl>=50 && b[i].english>=50)
			{
				printf("Grade: A");
			}
			else if(per>=60 && b[i].math>=50 && b[i].physics>=50 && b[i].urdu>=50 && b[i].isl>=50 && b[i].english>=50)
			{
				printf("Grade: B");
			}
			else if(per>=50 && b[i].math>=50 && b[i].physics>=50 && b[i].urdu>=50 && b[i].isl>=50 && b[i].english>=50)
			{
				printf("Grade: C");
			}
			else
			{
				printf("Grade: F");
			}
			break;
		}
	}
	printf("\n================================================================\n");
	fclose(fp); //Closing the file
}


void update(){ // function for updating data
	
	fp=fopen("data.txt","rb"); // Opening data.txt file in read mode
	fread(b,sizeof(struct data),20,fp); // Reading data from file in data structure
	temp=fopen("tempdata.txt","wb"); //Opening/creating file tempdata.txt in write mode
	if(temp==NULL) //Cheching if there is an error while opening the file
	{
		printf("Error Cannot open file");
	}
	else
	{
		//if there is no error while opening the file else statement will be executed
		printf("Enter Student's Roll Number: "); //Asking user for the roll number to be updated
		scanf("%d",&roll_number);
		for(int i=0;i<20;i++) // Loop to iterate through the data in data structure
		{
			if(roll_number == b[i].roll) // Cheching if the user inputed Roll Number exists
			{
				t[i].roll=b[i].roll; //Copying Roll number from data sturcture to temp data structure 
				for(int str2=0;str2<20;str2++){ //Copying name from dta dtructure to tempdata structure
					t[i].name[str2]=b[i].name[str2];
				}
				printf("\nEnter Student's Name: %s\n",t[i].name); 
				printf("Enter Student's Roll Number: %d\n",t[i].roll);
				printf("Enter Maths Marks: "); //Asking for subject marks To be updated
				fflush(stdin);
				scanf("%lf",&t[i].math);
				if(t[i].math == 0){ // if User enters 0, such subject marks will not be updated
					t[i].math = b[i].math;
				}
				fflush(stdin);
				printf("Enter Physics Marks: "); //Asking for subject marks To be updated
				fflush(stdin);
				scanf("%lf",&t[i].physics);
				if(t[i].physics == 0){ // if User enters 0, such subject marks will not be updated
					t[i].physics = b[i].physics;
				}
				fflush(stdin);
				printf("Enter Urdu Marks: "); //Asking for subject marks To be updated
				fflush(stdin);
				scanf("%lf",&t[i].urdu);
				if(t[i].urdu == 0){ // if User enters 0, such subject marks will not be updated
					t[i].urdu = b[i].urdu;
				}
				fflush(stdin);
				printf("Enter English Marks: "); //Asking for subject marks To be updated
				fflush(stdin);
				scanf("%lf",&t[i].english);
				if(t[i].english == 0){ // if User enters 0, such subject marks will not be updated
					t[i].english = b[i].english;
				}
				fflush(stdin);
				printf("Enter Islamiat Marks: "); //Asking for subject marks To be updated
				fflush(stdin);
				scanf("%lf",&t[i].isl);
				if(t[i].isl == 0){ // if User enters 0, such subject marks will not be updated
					t[i].isl = b[i].isl;
				}
				fflush(stdin);
			}
			else
			{
				//This else statement is to copy the reaming data other than the roll number to the data structure to later copy it to the data.txt file, as if not done so the data.txt file will only contain the updated data and all the reamining data will be lost that's why it is important to copy the reamining data 
				for(int i=0; i<20; i++)
				{
					fflush(stdin);
					for(int str=0; str<20; str++)
					{
						b[i].name[str]==t[i].name[str];
					}
					fflush(stdin);
					b[i].roll = t[i].roll;
					fflush(stdin);
					b[i].math = t[i].math;
					fflush(stdin);
					b[i].english = t[i].english;
					fflush(stdin);
					b[i].physics = t[i].physics;
					fflush(stdin);
					b[i].urdu = t[i].urdu;
					fflush(stdin);
					b[i].isl = t[i].isl;
				}
			}
		}
	}
	fwrite(t,sizeof(struct tempdata),20,temp); //writting whole tempdata dtructure to tempdata.txt file
	fclose(fp); //closing file data.txt
	fclose(temp); //closing file tempdata.txt
	temp=fopen("tempdata.txt","rb"); //Opening tempdata.txt file in read mode tp update data.txt file
	fread(t,sizeof(struct tempdata),20,temp); // Reading data from tempdata.txt file into the tempdata structure
	fp=fopen("data.txt","wb"); // Opening file data.txt in write mode
	if(fp==NULL) //cheching if there id an error while opening the file
	{
		printf("Error Cannot Open File");
	}
	else
	{
		//This else statement will be executed when there is no error while opening the file
		for(int i=0; i<20; i++) // loop to itrate through the data in tempdata structure
		{
			//Copying the data from tempdata structure to data structure, This will overwrite the data in data structure with the newly updated data from the user which was inputed above
			fflush(stdin);
			for(int str=0; str<20; str++)
			{
				b[i].name[str]==t[i].name[str];
			}
			fflush(stdin);
			b[i].roll = t[i].roll;
			fflush(stdin);
			b[i].math = t[i].math;
			fflush(stdin);
			b[i].english = t[i].english;
			fflush(stdin);
			b[i].physics = t[i].physics;
			fflush(stdin);
			b[i].urdu = t[i].urdu;
			fflush(stdin);
			b[i].isl = t[i].isl;
		}
	fwrite(b,sizeof(struct data),20,fp); //writting the data into the data.txt file
	fclose(fp); // Closing data.txt file
	fclose(temp); //Closing Tempdata file
	}
}
