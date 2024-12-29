# 📜 Get Next Line  

`get_next_line` is a project aimed at creating a function that reads a single line from a file descriptor efficiently. It is designed to handle large files.  

## 🚀 Features  

- **Read One Line at a Time**: Reads and returns one line from a file, including the newline character.  
- **Efficient Memory Usage**: Designed to minimize memory usage while processing files of any size.  
- **Performance**: Optimized for efficiency by leveraging linked lists for dynamic buffer management.  


## 🛠 Usage  

1. **Clone the Repository**:  
   ```bash
   git clone https://github.com/yourusername/get_next_line.git
   cd get_next_line
2. **Compile the Files**:
    ```bash
    gcc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c main.c -o gnl
3. **Run the Program**:
    ```bash
    ./gnl <your_file>
