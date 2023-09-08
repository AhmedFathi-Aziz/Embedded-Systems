# string.h
# fmemchr
This function searches for the first occurrence of the character 'c' in the first 'n' bytes of the memory block pointed by 's'.

## Function Signature
`void *fmemchr(const void *s, unsigned char c, unsigned int n);`

### Parameters
- `s`(const void *):Pointer to the memory block to search
- `c`(unsigned char):The character to locate
- `n`(unsigned int):Number of bytes to search in the memory block

### Return Value
- (void *):Pointer to the first occurrence of 'c' in 's', or NULL if not found.

# fmemcpy
This function copies 'n' bytes from the memory block pointed to by 'src' to the memory block pointed to by 'dest'. The memory areas must not overlap.

## Function Signature
`void *fmemcpy(void *dest, const void *src, int n);`

### Parameters
- `dest`(void *):Pointer to the destination memory block
- `src`(const void *):Pointer to the source memory block
- `n`:Number of bytes to copy.

### Return Value
- (void *):Pointer to the destination memory block 'dest'.

# fmemmove
This function copies 'n' bytes from the memory block pointed by 'src' to the memory block pointed by 'dest'. The memory areas may overlap.

## Function Signature
`void *fmemmove(void *dest, const void *src, int n);`

### Parameters
- `dest`(void *):Pointer to the destination memory block
- `src`(const void *):Pointer to the source memory block
- `n`(int):Number of bytes to copy

### Return Value
- (void *):Pointer to the destination memory block 'dest'.

# fmemset
This function fills the first 'n' bytes of the memory block pointed by 's' with the character 'c'.

## Function Signature
`void *fmemset(void *s, unsigned char c, int n);`

### Parameters
- `s`(void *):Pointer to the memory block to fill.
- `c`(unsigned char):The character used for filling.
- `n`(int):Number of bytes to fill.

### Return Value
- (void *):Pointer to the filled memory block 's'.

# fstrcat
This function appends the string 'src' to the end of the string 'dest'

## Function Signature
`char *fstrcat(char *dest, const char *src);`

### Parameters
- `desr`(char *):Pointer to the destination string.
- `src`(const char *):Pointer to the source string to append.

### Return Value
- (char *):Pointer to the destination string 'dest'.

# fstrncat

Concatenate at most 'n' characters from 'src' to the end of 'dest'.

## Function Signature
`char *fstrncat(char *dest, const char *src, unsigned int n);`

### Parameters

- `dest` (char *): Pointer to the destination buffer.
- `src` (const char *): Pointer to the source string to append.
- `n` (unsigned int): Maximum number of characters to append.

### Return Value

- (char *): Pointer to the destination buffer 'dest'.

# fstrchr

This function searches the string 's' for the first occurrence of the character 'c'.

## Function Signature
`char *fstrchr(const char *s, unsigned char c);`

### Parmeters
- `s` (const char *): Pointer to the null-terminated string to search
- `c` (unsigned char): The character to locate

### Return Value
- (char *): Pointer to the first occurrence of 'c' in 's' or NULL if not found.

# fmemcmp
This function compares the first 'n' bytes of memory areas 's1' and 's2'

## Function Signature
`int fmemcmp(const void *s1, const void *s2, unsigned int n);`

### Parameters
- `s1` (const void *): Pointer to the first memory area
- `s2` (const void *): Pointer to the second memory area
- `n` (unsigned int): Number of bytes to compare

### Return value
- (int): 0 if 's1' and 's2' are equal, a negative value if 's1' is less than 's2', or positive value is 's1' is greater than 's2'

# fstrcmp
This function compares the strings 's1' and 's2'

## Function Signature
`int fstrcmp(const char *s1, const char *s2);`

### Parameters
- `s1`(const char *): Pointer to the first string
- `s2`(const char *): Pointer to the second string

### Return Value
- (int): 0 if 's1' and 's2' are equal, a negative value if 's1' is less than 's2', or positive value is 's1' is greater than 's2'

# fstrncmp
This function compares at most 'n' characters of the strings 's1' and 's2'

## Function Signature
`int fstrncmp(const char *s1, const char *s2, unsigned int n)`

### Parameters
- `s1`(const char *): Pointer to the first string
- `s2`(const char *): Pointer to the second string
- `n`(unsigned int): Number of characters to compare

### Return Value
- (int): 0 if 's1' and 's2' are equal, a negative value if 's1' is less than 's2', or positive value is 's1' is greater than 's2'

# fstrcoll
This function compares the strings 's1' and 's2'

## Function Signature
`int fstrcoll(const char *s1, const char *s2);`

### Parameters
- `s1`(const char *): Pointer to the first string
- `s2`(const char *): Pointer to the second string

### Return Value
- (int): 0 if 's1' and 's2' are equal, a negative value if 's1' is less than 's2', or positive value is 's1' is greater than 's2'

# fstrcpy
This function copies the null-terminated string 'src' to the null-terminated string 'dest'

## Function Signature
`char *fstrcpy(char *dest, const char *src);`

### Parameters
- `dest`(char *):Pointer to the destination buffer.
- `src`(const char *):Pointer to the source sting.

### Return Value
- (char *):Pointer to the destination buffer 'dest'.

# fstrncpy
This function copies at most 'n' characters from the null-terminated string 'src' to the null-terminated string 'dest'.
if 'src' is shorter than 'n' characters, null characters are padded to the 'dest' to reach 'n' characters.

## Function Signature
`char *fstrncpy(char *dest, const char *src, unsigned int n);`

### Parameters
- `dest`(char *):Pointer to the destination buffer
- `src`(const char *):Pointer to the source string
- `n`(unsigned int):Maximum number of characters to copy.

### Return Value
- (char *):Pointer to the destination buffer 'dest'.

# fstrcspn
This function computes the length of the initial segment of 's1' that consists of characters not in 's2'

## Function Signature
`unsigned int fstrcspn(const char *s1, const char *s2);`

### Parameters
- `s1`(const char *):Pointer to the null-terminated string to search
- 's2'(const char *):Pointer to the null-terminated string containing characters to exclude

### Return Value
- (unsigned int):The length of the initial segment of 's1'

# fstrerror
This function returns a pointer to a string describing the error code 'errnum'.

## Function Signature
`char *fstrerror(int errnum);`

### Parameters
- `errnum`(int):The error code.

### Return Value
- (char *):Pointer to the error message string.

# fstrlen
This function computes the length of the null-terminated string 's'.

## Function Signature
`unsigned int fstrlen(const char *s);`

### Parameters
- `s`(const char *):Pointer to the null-terminated string.

### Return Value
- (unsigned int):The length of the string

# fstrpbrk
This function searches the string 's1' for the first occurrence of any character from the string 's2'.

## Function Signature
`char *fstrpbrk(const char *s1, const char *s2);`

### Parameters
- `s1`(const char *):Pointer to the null-terminated string to search.
- `s2`(const char *):Pointer to the null-terminated string containing characters to search for.

### Return Value
- (char *):Pointer to the first occurrence in 's1' or NULL if not found.

# fstrrchr
This function searches the string 's' for the last occurrence of the character 'c'.

## Function Signature
`char *fstrrchr(const char *s, unsigned char c);`

### Parameters
- `s`(const char *):Pointer to the null-terminated string to search
- `c`(unsigned char):The character to locate

### Return Value
- (char *):Pointer to the last occurrence of 'c' in 's', or NULL if not found.

# fstrspn
This function computes the length of the initial segment of 's1' that consists of characters only from 's2'.

## Function Signature
`unsigned int fstrspn(const char *s1, const char *s2);`

### Parameters
- `s1`(const char *):Pointer to the null-terminated string to search
- `s2`(const char *):Pointer to the null-terminated string containing characters to include.

### Return Value
- (unsigned int):The length of the initial segment of 's1'.

# fstrstr
This function searches the string 'haystack' for the first occurrence of the substring 'needle'.

## Function Signature
`char *fstrstr(const char *haystack, const char *needle);`

### Parameters
- `haystack`(const char *):Pointer to the null-terminated string to search
- `needle`(const char *):Pointer to the null-terminated substring to locate.

### Return Value
- (char *):Pointer to the first occurrence of 'needle' in 'haystack', or NULL if not found.

# fstrtok
This function breaks the string 's' into a sequence of tokens, each delimited by characters in the string 'delim'

## Function Signature
`char *fstrtok(char *s, const char *delim);`

### Parameters
- `s`(char *):Pointer to the null-terminated string to tokenize.
- `delim`(const char *):Pointer to the null terminated string containing delimiter characters

### Return Value
- (char *):Pointer to the next token, or NULL if no more tokens are found.

# fstrxfrm
This function transfer the string 'src' to string 'dest'.
Up to 'n' characters are stored in the 'dest' (including the null terminator)

## Fucntion Signature
`unsigned int fstrxfrm(char *dest, const char *src, unsigned int n);`

### Parameters
- `dest`(char *):Pointer to the destination buffer
- `src`(const char *):Pointer to the source string
- `n`(unsigned int): Maximum number of characters to store in 'dest'

### Return Value
- (unsigned int):Length of the transfered string