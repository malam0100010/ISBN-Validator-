# ISBN-Validator-
This program take the input of an ISBN-10 or ISBN-13 and checks to see its validity. 


ISBNs are comerically printed idetifiers for comerically printed books. Before 2007, they only contained 10 digits, but new ISBNs contain 13 digits. 

ISBNs may have hyphens or spaces seperating various parts of the whole identifier, but this does not effect their validity. 

ISBN-10s have 9 characters and 1 character for the check digit. 
The check digit is base 11, so a check digit of 10 is represented as 'X' or 'x' 

ISBN-13s have 12 characters and 1 check digit. 
The check digit is only number 0-9, however. 

Valid ISBNs to test:
0-486-63760-3
981-02-4897-0
3-540-20105-X
0-521-33781-X
0-521-33781-x

Invalid ISBNs to test:
012345678
01234567890
012345678901
0123456789013
01234567890X5

Sample Outputs:
Please enter an ISBN:
0-486-63760-3
Valid ISBN-10
Invalid ISBN-13

Please enter an ISBN:
01234567890X5
Invalid ISBN-10
Invalid ISBN-13



