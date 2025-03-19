### Objective
The goal of the **get_next_line** project is to create a function that reads a file descriptor and returns one line at a time. This function should be capable of handling large files and work efficiently, without the need to load the entire file into memory.

### Function Prototype
```c
int get_next_line(int fd, char **line);
```
## Compilation

```
make
```
Or, if there is no Makefile:
```
c++ -Wall -Wextra -Werror -std=c++98 *.cpp -o program
```
Run the program:
```
./exec_name(check Makefile)

```
If you want to check for different tyoe of inputs feel free to modify the main or the contents of 


## Topics Covered

### 1. **File Handling in C**
   - Understanding how to read from files using `open()`, `read()`, and `close()`.
   - Handling file descriptors and managing their proper closing after use.
   
### 2. **Dynamic Memory Allocation**
   - Using `malloc` and `free` to dynamically allocate and deallocate memory for reading data.
   - Efficiently managing memory in the function to avoid memory leaks.

### 3. **Buffering and Reading Lines**
   - Implementing a buffer to store data read from the file and process it line by line.
   - Reading data from a file in chunks and splitting it into lines.
   - Handling edge cases like partial lines, multiple lines, and the end of file (EOF).

### 4. **Handling File Descriptors**
   - Managing multiple file descriptors (use of static variables to store data between function calls).
   - Ensuring that each file descriptor is correctly managed and read until the EOF is reached.

### 5. **String Handling**
   - Using `strdup()`, `strchr()`, and other string manipulation functions to handle line parsing.
   - Concatenating partial buffers to form complete lines.

### 6. **Edge Case Management**
   - Handling scenarios such as no new lines in the file, empty lines, or files that end without a newline character.
   - Implementing error handling for invalid file descriptors and unexpected EOFs.

---

## Why Is This Important?

The **get_next_line** project is important because it teaches students fundamental techniques for working with file I/O in C. The ability to read from files and process the data line by line is a key skill in many systems programming tasks. This project also deepens your understanding of memory management and dynamic memory allocation, two critical aspects of C programming.

Additionally, **get_next_line** introduces the concept of buffering, which is a core mechanism used in handling large files or data streams efficiently. Understanding how to read and manage chunks of data is valuable for many real-world applications that involve processing large volumes of data.

The project reinforces the importance of edge case handling and memory management, ensuring that students understand the need for efficient code that doesn't leak memory or fail when faced with unexpected inputs.

---

## Conclusion

The **get_next_line** project is a great exercise in improving your understanding of file handling, dynamic memory management, and string manipulation in C. By building this function, you'll gain practical experience with fundamental concepts such as reading from files, allocating memory dynamically, and efficiently parsing data. You will also become more comfortable handling complex situations like multiple file descriptors and buffering.

This project is highly applicable to real-world applications where handling large files or data streams is necessary. Completing it will give you the confidence to manage file I/O and memory in your future C programs while reinforcing key programming concepts.
