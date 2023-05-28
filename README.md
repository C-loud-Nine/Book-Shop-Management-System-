# Book-Shop-Management-System-
This is a simple console-based bookshop management program written in C++. It allows you to perform various operations such as adding books, displaying books, checking specific books, updating book details, and deleting books.

## Features

- Add a Book: You can add a new book to the inventory by providing the book ID, title, author name, and quantity. The book details are stored in a file called "books.txt".

- Show Books: Displays the list of all books in the inventory. The book details are read from the "books.txt" file and displayed on the console.

- Check Book: Allows you to search for a specific book by its ID. If found, it displays the book details including the book ID, title, author name, and quantity.

- Update Book: Enables you to update the details of a specific book. You can modify the book's title, author name, and quantity. The updated information is saved in the "books.txt" file.

- Delete Book: Allows you to remove a book from the inventory by specifying its ID. The book is permanently deleted from the "books.txt" file.

## Usage

1. Compile the source code using a C++ compiler. For example:

g++ main.cpp -o bookshop

markdown


2. Run the executable file:

./bookshop

sql


3. The program will display a control panel with different options. Enter the corresponding number to select an operation.

4. Follow the prompts to add, display, check, update, or delete books as per your requirements.

5. To exit the program, select the "Exit" option from the control panel.

## File Format

The book details are stored in a text file called "books.txt". Each line in the file represents a book and follows the format:

<Book ID> <Book Title> <Author Name> <Quantity>

vbnet


Ensure that each field is separated by a space and there are no extra spaces or characters within the fields.

## Note

- Make sure to have read and write permissions for the directory where the program and "books.txt" file are located.

- The program assumes that the input data is correctly formatted and doesn't perform extensive error checking. Ensure that the input data follows the expected format to avoid any unexpected behavior.

- This program is intended for educational purposes and may not include advanced error handling or validation. Feel free to enhance it as per your requirements.
