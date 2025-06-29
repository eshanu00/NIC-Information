# NIC-Information

This program exxtract the inforamtion of a person's
1. Birth Year
2. Birth Month
3. BirthDay
4. Gender
using the NIC no.

## Machanism
*example(old nic)* : 937538421
*example(later nic)* : 20055829358

### For Older NIC Number Format
1. First two digit *(93)* is stand for the birth year.
2. Next 3 digit *(753)* is stand for the days of the year, *for females, 500 is add to the days*.

### For Later NIC Number Format
1. First four digit *(2005)* is stand for the birth year.
2. Next 3 digit *(582)* is stand for the days of the year, *for females, 500 is add to the days*.

## CLI Version

Converting char to int for calculate days and month by day count in C lang.

```
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
```

Calculate month and day by counting days from decenmber as:
1. days > 335 December
2. days > 305 November
3. days > 274 Octomber
4. days > 244 September
5. days > 213 Augest
6. days > 182 Jule
7. days > 152 June
8. days > 121 May
9. days > 91 April
10. days > 60 March
11. days > 31 Febuary
12. days > 0 January
then the day count would be substracted from the numbers mentioned above to get the exact day of the month.

```
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
```

To determind the "*gender*", if the count of the days is over 500, the gender gets as *Female* else *Male*

```
char gender = 'M'

if (days > 500){
		days = days - 500;
		gender = 'F';
	}
```

![](/assets/screenshot01.png "CLI Version")

**Not Yet Completed**
## GUI Version
![](/assets/screenshot01.png "GUL Version")
