# SubstitutionCipher

Written for ET0702 - Data Structures and Algorithms

Singapore Polytechnic

**Encrypyting Process**

The program will get the string message to be encrypted either from a file or manually typed in by the user. After that, the program will convert each character in the string into its ASCII code equivalent, which will then be subsequently converted to its Octal (base 8) equivalent. 

There are 3 variables to store the value of each bit:
- three
- two
- one

The variable 'three' is used to store the Most Significant Bit. Before each of these variables are pushed into a vector, the program will add the integer 1 to variable 'three', 2 to variable 'two' and 2 to variable 'one' as well. This is to further strengthen the encryption process. After adding each of the variables, they will be pushed into a vector to be displayed or written to a file.

**Decrypting Process**

Decrypting will basically be the reverse process of the encryption process.

```JavaScript
Test
```
