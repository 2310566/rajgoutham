#include <stdio.h>
int dayNumber(int day, int month, int year) {
    static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
    year -= month < 3;
    return (year + year / 4 - year / 100 + year / 400 + t[month - 1] + day) % 7;
}
char* getMonthName(int monthNumber) {
    char* month;
    switch (monthNumber) {
        case 0: month = "January"; break;
        case 1: month = "February"; break;
        case 2: month = "March"; break;
        case 3: month = "April"; break;
        case 4: month = "May"; break;
        case 5: month = "June"; break;
        case 6: month = "July"; break;
        case 7: month = "August"; break;
        case 8: month = "September"; break;
        case 9: month = "October"; break;
        case 10: month = "November"; break;
        case 11: month = "December"; break;
    }
    return month;
}
int numberOfDays(int monthNumber, int year) {
    if (monthNumber == 0 || monthNumber == 2 || monthNumber == 4 || monthNumber == 6 || monthNumber == 7 || monthNumber == 9 || monthNumber == 11)
        return 31;
    else if (monthNumber == 3 || monthNumber == 5 || monthNumber == 8 || monthNumber == 10)
        return 30;
    else {
        if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
            return 29;
        else
            return 28;
    }
}
void printCalendar(int year) {
    printf("Calendar - %d\n\n", year);
    int days, current;
	 for (int i = 0; i < 12; i++) {
        current = dayNumber(1, i + 1, year);
        days = numberOfDays(i, year);
		printf("\n ------------%s-------------\n", getMonthName(i));
        printf(" Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");
         int k;
        for (k = 0; k < current; k++)
            printf("     ");

        for (int j = 1; j <= days; j++) {
            printf("%5d", j);

            if (++k > 6) {
                k = 0;
                printf("\n");
            }
        }

        if (k)
            printf("\n");

        current = k;
    }
}
int main() {
    int year;

    printf("Enter the year: ");
    scanf("%d", &year);
    printCalendar(year);
}

