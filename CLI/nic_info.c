#include <stdio.h>
#include <string.h>
#include <math.h>

// Decorative Menu
void getMenu(){
	printf("------------------------------------------\n");
	printf("-----------------NIC INFO-----------------\n");
	printf("------------------------------------------\n\n");
}

// Int => String
int get_int(char string[]){
	int output = 0;
	char numbers[] = {'0','1','2','3','4','5','6','7','8','9'};
	for (int i = 0; i < strlen(string); i++)
	{
		for (int j = 0; j < sizeof(numbers); j++)
		{
			if (string[i] == numbers[j])
			{
				output += j * pow(10, (strlen(string) - i - 1));
				break;
			}
		}
	}
	return output;
}

//200145938468
// Get Brithday and Month
// "Count" - total days | "month" prt to month output | "day" ptr to days output
char* get_time(int count, int* day){
	printf("%d", count);
	if (count > 365)
		return "Error";
	else if (count > 335){
		*day = count - 335;
	    return "December";
	}
	else if (count > 305){
		*day = count - 305;
		return "November";
	}
	else if (count > 274){
		*day = count - 274;
		return "Octomber";
	}
	else if (count > 244){
		*day = count - 244;
		return "September";
	}
	else if (count > 213){
		*day = count - 213;
		return "Augest";
	}
	else if (count > 182){
		*day = count - 182;
		return "Jule";
	}
	else if (count > 152){
		*day = count - 152;
		return "June";
	}
	else if (count > 121){
		*day = count - 121;
		return "May";
	}
	else if (count > 91){
		*day = count - 91;
		return "April";
	}
	else if (count > 60){
		*day = count - 60;
		return "March";
	}
	else if (count > 31){
		*day = count - 31;
		return "Febuary";
	}
	else {
		*day = count;
		return "January";
	}
	return "Error";
}

// Get information from old NICs
void get_info_old(char nic[]){
	char year[] = {'1' , '9' , nic[0] , nic[1], '\0'};
	int day = 0;
	char gender = 'M';
	// convert to days as a numerics
	char temp[] = {nic[2], nic[3], nic[4], '\0'};
	int days = get_int(temp);

	if (days > 865)
		return;
	else if (days > 500){
		days = days - 500;
		gender = 'F';
	}

	char* month = get_time(days, &day);
	getMenu();
	printf("Your Information\n");
	printf("\tGender: %c\n", gender);
	printf("\tYear: %s\n",year);
	printf("\tMonth: %s\n", month);
	printf("\tDay: %d\n", day);
}

// Get information from later NICs
void get_info_later(char nic[]){
	char year[5] = {nic[0], nic[1], nic[2], nic[3], '\0'};
	int day = 0;
	char gender = 'M';
	// convert to days as a numerics
	char temp[] = {nic[4], nic[5], nic[6], '\0'};
	int days = get_int(temp);
	
	if (days > 865){
		printf("Invalid NIC");
		return;
	}
	else if (days > 500){
		days = days - 500;
		gender = 'F';
	}
	char* month = get_time(days, &day);
	getMenu();
	printf("Your Information\n");
	printf("\tGender: %c\n", gender);
	printf("\tYear: %s\n",year);
	printf("\tMonth: %s\n", month);
	printf("\tDay: %d\n", day);
}


int main(){

	while (1 == 1)
	{
		char nicNo[12];

		getMenu();
		printf("Your NIC No (except \'V\'):\t");
		scanf("%s", &nicNo);
	
		if (strlen(nicNo) == 12)
			get_info_later(nicNo);
		else if (strlen(nicNo) == 9)
			get_info_old(nicNo);
		else {
			printf("Invalid Input\n\n");
		}
		printf("\n\n");
	}
	return 0;
}