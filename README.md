*This project has been created as part of the 42 curriculum by fdeville*

# get_next_line

## Description

This project aims to create a useful functions that reads lines consecutively from a file descriptor.
We also learn to use static variables through this project.
An example of usage of `get_next_line` would be in the case of a program that parses a file, such as a CSV, by reading the first line with the headers, then each new line containing the data.

## Instructions

To use `get_next_line`, simply compile your program with `get_next_line.c` and `get_next_line_utils.c`, such as :
```
cc -o gnl test.c get_next_line.c get_next_line_utils.c
```

## Resources

I read [geeksforgeeks](https://www.geeksforgeeks.org/c/static-variables-in-c/) website to learn more about static variables.
For the rest, the main challenge was getting the buffer properly cleared and handled when calling get_next_line, which didn't require many resources but a lot of debugging.
I used GitHub Copilot once to debug a specific case where the buffer wouldn't be cleared and such remaining data would be left and returned in the next get_next_line call.

## Explanation of selected algorithm

My implementation of `get_next_line` reads chunks from the file descriptor until a line break (`\n`) is encountered.
It then copy the buffer up to the EOL (included) in a char pointer that is returned by the function.
For the next call, it firsts check if there is a remainder in the buffer, and if so it happens it to the char pointer that will be returned and reads again up to an EOL.