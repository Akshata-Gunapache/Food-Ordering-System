#include<stdio.h>
#include <string.h>
#include<stdlib.h>
// user details
struct details {
	char username[100];
	int age;
	char password[100];
	char email[100];
	char mobile[10];
};

// course and food details
struct courses {
	char course[100];
	char first_food[20];
	char second_food[20];
	char third_food[20];
	char fourth_food[25];
	int first, second, third, fourth;
};

struct courses m[5];
struct details s[100];

// signup function
void signup();

// Function to check if account exists
void account_check();

// Function to valid
// all the input fields.
int valid();
void login();
void cart();
void bycourse();
void byfood();
void food_order(int food);


void course_initialize();
void courses(int course_option);
int v = 1, i, j = 0, count = 0, caps = 0;
int small = 0, special = 0, numbers = 0;
int success = 0, x, option;
char uname[100], upassword1[100];
char upassword2[100], umail[100];
char uphone[100];
int uage, total = 0, food_option, n;
int course_option, search_option, confirm;
int ch, food, course_id;

//home page
int main()
{
	while (1) {
		printf(""
			"\n\nWELCOME TO GOFOODS ");
		printf("\n\n1)SIGNUP\n");
		printf("2)LOGIN\n3)EXIT\n\n");
		printf("Enter your option\t");
		scanf("%d", &option);
		switch (option) {
		case 1: {
			signup();
			break;
		}
		case 2: {
			login();
			break;
		}
		case 3: {
			exit(1);
			return 0;
		}
		default: {
			printf("\nPlease Enter the ");
			printf("valid option\n");
			break;
		}
		}
	}
}

// new user
void signup()
{
	printf("Enter Your name\t");
	scanf("%s", uname);

	printf("Enter Your Age\t");
	scanf("%d", &uage);

	printf("Enter Your Email\t");
	scanf("%s", umail);

	printf("Enter Password\t");
	scanf("%s", upassword1);

	printf("Confirm Password\t");
	scanf("%s", upassword2);

	printf("Enter Your Mobile Number\t");
	scanf("%s", uphone);

//validating
	x = valid();
	if (x == 1)
		account_check();
}

// Function to validate the user info
int valid()
{
	// name
	for (i = 0; uname[i] != '\0'; i++) {
		if (!((uname[i] >= 'a' && uname[i] <= 'z')
			|| (uname[i] >= 'A'
				&& uname[i] <= 'Z'))) {
			printf("\nPlease Enter the");
			printf("valid Name\n");
			v = 0;
			break;
		}
	}
	if (v == 1) {
		count = 0;

		//mail
		for (i = 0;
			umail[i] != '\0'; i++) {
			if (umail[i] == '@'
				|| umail[i] == '.')
				count++;
		}
		if (count >= 2
			&& strlen(umail) >= 5) {
			// Validating the Password and
			// Check whether it matches
			// with Conform Password
			if (!strcmp(upassword1,
						upassword2)) {
				if (strlen(upassword1) >= 8
					&& strlen(upassword1) <= 12) {
					caps = 0;
					small = 0;
					numbers = 0;
					special = 0;
					for (i = 0; upassword1[i] != '\0';
						i++) {
						if (upassword1[i] >= 'A'
							&& upassword1[i] <= 'Z')
							caps++;
						else if (upassword1[i] >= 'a'
								&& upassword1[i]
										<= 'z')
							small++;
						else if (upassword1[i] >= '0'
								&& upassword1[i]
										<= '9')
							numbers++;
						else if (upassword1[i] == '@'
								|| upassword1[i] == '&'
								|| upassword1[i] == '#'
								|| upassword1[i]
										== '*')
							special++;
					}
					if (caps >= 1 && small >= 1
						&& numbers >= 1 && special >= 1) {
						// Validating the Input age
						if (uage != 0 && uage > 0) {
							// Validating the Input mobile
							// number
							if (strlen(uphone) == 10) {
								for (i = 0; i < 10; i++) {
									if (uphone[i]
											>= '0'
										&& uphone[i]
											<= '9') {
										success = 1;
									}
									else {
										printf("\n\nPlease");
										printf("Enter Valid ");
										printf("Mobile "
											"Number\n\n");
										return 0;
										break;
									}
								}

				
								// inputs are correct.
								if (success == 1){

									return 1;
								}
							}
							else {
								printf("\n\nPlease Enter the");
								printf("10 digit mobile");
								printf("number\n\n");
								return 0;
							}
						}
						else {
							printf("\n\nPlease Enter ");
							printf("the valid age\n\n");
							return 0;
						}
					}
					else {
						printf("\n\nPlease Enter the");
						printf("strong password, Your ");
						printf("password must contain ");
						printf("atleast one uppercase, ");
						printf("Lowercase, Number and ");
						printf("special character\n\n");
						return 0;
					}
				}
				else {
					printf("\nYour Password is very");
					printf("short\nLength must ");
					printf("between 8 to 12\n\n");
					return 0;
				}
			}
			else {
				printf("\nPassword Mismatch\n\n");
				return 0;
			}
		}
		else {
			printf("\nPlease Enter"
				" Valid E-Mail\n\n");
			return 0;
		}
	}
}

// if account exists
void account_check()
{
	for (i = 0; i < 100; i++) {
		// Check whether the email and password match
		
		if (!(strcmp(umail, s[i].email)
			&& strcmp(upassword1,
						s[i].password))) {
			printf("\n\nAccount Already Exists");
			printf("Please Login !!\n\n");
			main();
			break;
		}
	}
	// if account does not exist
	
	if (i == 100) {
		strcpy(s[j].username,uname);
		s[j].age = uage;
		strcpy(s[j].password, upassword1);
		strcpy(s[j].email, umail);
		strcpy(s[j].mobile, uphone);
		j++;
        FILE *f=fopen("users.txt","a");
        fprintf(f,"%s,%d,%s,%s,%s\n",uname,uage,umail,upassword1,uphone);
        fclose(f);
		printf("\n\n\nAccount Successfully");
		printf("Created!!\n\n");
	}
}

// Function to Login
void login()
{
	printf("\n\nLOGIN\n\n");
	printf("\nEnter Your userid(email)\t");
	scanf("%s", umail);
	printf("Enter Your Password\t");
	scanf("%s", upassword1);
	char *token,line[1000];
    FILE *fp=fopen("users.txt","r");
    
	for (i = 0; i < 100; i++) {
		// Check whether the input is valid
		fscanf(fp,"%s",line);
    	token=strtok(line,",");
		token=strtok(NULL,",");
		token=strtok(NULL,",");
		while(token!=NULL){
			
			if (!strcmp(token, umail)) {
				
				// Check whether the password is mismatched with user id
				token=strtok(NULL,",");
				if (!strcmp(token, upassword1)) {
					printf("\n\nWelcome %s, ", s[i].username);
					printf("Login successful ");
					printf("\n\n Here's what we have for you %s",uname);
					printf("\nSEARCH BY:\n ");
					printf("1)Search By courses\n2) ");
					printf("Search by Food(Most searched)\n3) ");
					printf("Exit\n\n");
					printf("Enter your option\t");
					scanf("%d", &search_option);

					// Getting the input whether
					// the user are going to search
					// /Order by courses or search/
					// order by food.
					switch (search_option) {
					case 1: {
						bycourse();
						break;
					}
					case 2: {
						byfood();
						break;
					}
					case 3: {
						exit(1);
						return;
					}
					default: {
						printf("Please Enter ");
						printf("the valid option\n\n");
						break;
					}
					}
					break;
				}
			}
			token=strtok(NULL,",");
		}
	}
	fclose(fp);
}

// Function to implement the course
// initialzer
void course_initialize()
{
	//starters and soups
	strcpy(m[1].course, "Starters ");
	strcpy(m[1].first_food, "Paneer TIkka");
	strcpy(m[1].second_food, "Gobi chilly and manchurian platter ");
	strcpy(m[1].third_food, "Hara Bhara kabab");
	m[1].first = 700;
	m[1].second = 1050;
	m[1].third = 950;

	// Initializing the structure with main course
	strcpy(m[2].course, "Main course");
	strcpy(m[2].first_food, "Dal Makhani and Roti");
	strcpy(m[2].second_food, "Trio Curry and Roti platter");
	strcpy(m[2].third_food, "Jeera rice with rabdi");
	m[2].first = 2050;
	m[2].second = 1075;
	m[2].third = 3500;

	// Initializing the structure with Desserts
	
	strcpy(m[3].course, "Desserts");
	strcpy(m[3].first_food, "Ice cream sundae");
	strcpy(m[3].second_food, "Gulab Jamun");
	strcpy(m[3].third_food, "Rasmalai");
	m[3].first = 1080;
	m[3].second = 1850;
	m[3].third = 850;
}

// after search by courses
void bycourse()
{
	course_initialize();
	printf(""
		"\n\nPlease Choose the");
	printf("courses\n\n1) %s\n2) %s\n3) %s",
		m[1].course,
		m[2].course, m[3].course);
	printf("\n4) Exit\n\nPlease ");
	printf("select the course\t");
	scanf("%d", &course_option);
	if (course_option > 4) {
		printf("Please Enter ");
		printf("valid option\n\n");
		bycourse();
	}
	else if (course_option == 4){
		exit(1);
		return;}
	else
		courses(course_option);
}

// after search by food
void courses(int course_option)
{
	total = 0;
	while (1) {
		// Displays the list of
		// foods available in
		// selected course
		printf("\n\nList of foods available");

		printf("in %s\n\n1) %s\tRs: %d\n2)",
			m[course_option].course,
			m[course_option].first_food,
			m[course_option].first);

		printf("%s\tRs: %d\n3) %s\tRs: %d\n4)",
			m[course_option].second_food,
			m[course_option].second,
			m[course_option].third_food,
			m[course_option].third);

		printf("Cart\n5) Exit\n\nPlease Enter");
		printf("Your option\t");
		scanf("%d", &food_option);
		if (food_option == 1) {
			printf("Please Enter the ");
			printf("Count of %s\t",
				m[course_option].first_food);
			scanf("%d", &n);
			total = total
					+ (n * m[course_option].first);
		}
		else if (food_option == 2) {
			printf("Please Enter the Count");
			printf("of %s\t",
				m[course_option].second_food);
			scanf("%d", &n);
			total = total
					+ (n * m[course_option].second);
		}
		else if (food_option == 3) {
			printf("Please Enter the Count");
			printf("of %s\t",
				m[course_option].third_food);
			scanf("%d", &n);
			total = total
					+ (n * m[course_option].third);
		}

		else if (food_option == 4) {
			cart();
		}
		else if (food_option == 5) {
			bycourse();
		}
		else {
			printf("Please Enter the");
			printf("valid option\n\n");
		}
	}
}

void byfood()
{
	total = 0;
	// Initialize all the
	// courses and their foods
	course_initialize();
	while (1) {
		printf("\n\nPlease choose the ");
		printf("food\n\n1) %s\t%d\n2) %s\t%d",
			m[1].first_food, m[1].first,
			m[1].second_food, m[1].second);

		printf("\n3) %s\t%d\n4) %s\t%d\n",
			m[1].third_food, m[1].third,
			m[2].first_food, m[2].first);

		printf("5) %s\t%d\n6) %s\t%d\n",
			m[2].second_food, m[2].second,
			m[2].third_food, m[2].third);

		printf("7) %s\t%d\n8) %s\t%d\n",
			m[3].first_food, m[3].first,
			m[3].second_food, m[3].second);

		printf("9) %s\t%d\n10) Cart\n",
			m[3].third_food,
			m[3].third);
		printf("11) Exit");
		printf("\nPlease Enter Your option\t");
		scanf("%d", &food);
		if (food > 10) {
			printf("Please Enter the ");
			printf("valid option\n\n");
			byfood();
		}
		// Moves to the cart
		// functionality
		else if (food == 10)
			cart();
		else if (food == 11)
			{exit(1);
			return;}
		
		else
			food_order(food);
	}
}


void food_order(int food)
{
	if (food >= 1 && food <= 3)
		course_id = 1;
	else if (food >= 4 && food <= 6)
		course_id = 2;
	else
		course_id = 3;
	if ((food % 3) == 1) {
		printf("Please Enter the");
		printf(" Count of %s\t",
			m[course_id].first_food);
		scanf("%d", &n);
		total = total + (n * m[course_id].first);
	}
	else if ((food % 3) == 2) {
		printf("Please Enter the ");
		printf("Count of %s\t",
			m[course_id].second_food);
		scanf("%d", &n);
		total = total + (n * m[course_id].second);
	}
	else if ((food % 3) == 0) {
		printf("Please Enter the ");
		printf("Count of %s\t",
			m[course_id].third_food);
		scanf("%d", &n);
		total = total + (n * m[course_id].third);
	}
}

// total order
void cart()
{
	printf("\n\n\n\n--------------Cart");
	printf("----------------");
	printf("\nYour Total Order:");
	printf("Bill amount : %d\n", total);
	printf("\n\nDo You wish to order");
	printf("(y=1/n=0):");
	scanf("%d", &ch);
	if (ch == 1) {
		printf("\n\nThank You for your ordering through GOFOODS");
		printf(" Your Food is on the way ");
		printf(" Welcome again!!\n\n");
		exit(1);
		return;
	}
	else if (ch == 0) {
		printf("Do You want to exit -1");
		printf("or Go back -0");
		scanf("%d", &confirm);
		if (confirm == 1) {
			printf("\n\nOops! Your order is cancelled.");
			printf("Exiting....");
			printf("Thank You visit again!\n");
			exit(1);
			return;
		}
		else {
			printf("\n\nThank You\n\n");
			login();
		}
	}
	else {
		printf("\n\nPlease Enter the ");
		printf("correct option\n\n");
		cart();
	}
}