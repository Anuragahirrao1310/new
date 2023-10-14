
library = {}

def add_book():
    ISBN = input("Enter ISBN: ")
    title = input("Enter title: ")
    author = input("Enter author: ")
    copies = int(input("Enter the number of copies available: "))
    
    if ISBN in library:
        library[ISBN]['copies'] += copies
    else:
        library[ISBN] = {'title': title, 'author': author, 'copies': copies}
        print(f"Book with ISBN {ISBN} added to the library.")


def display_books():
    if not library:
        print("The library is empty.")
    else:
        print("Books in the library:")
        for ISBN, book_info in library.items():
            print(f"ISBN: {ISBN}, Title: {book_info['title']}, Author: {book_info['author']}, Copies: {book_info['copies']}")

def search_book():
    ISBN = input("Enter ISBN to search for a book: ")
    if ISBN in library:
        book_info = library[ISBN]
        print(f"ISBN: {ISBN}, Title: {book_info['title']}, Author: {book_info['author']}, Copies: {book_info['copies']}")
    else:
        print(f"Book with ISBN {ISBN} not found in the library.")

def delete_book():
    ISBN = input("Enter ISBN to delete a book: ")
    if ISBN in library:
        del library[ISBN]
        print(f"Book with ISBN {ISBN} deleted from the library.")
    else:
        print(f"Book with ISBN {ISBN} not found in the library.")

def update_book():
    ISBN = input("Enter ISBN to update book details: ")
    if ISBN in library:
        title = input("Enter new title (or press Enter to keep the existing one): ")
        author = input("Enter new author (or press Enter to keep the existing one): ")
        copies = input("Enter the new number of copies (or press Enter to keep the existing one): ")
        
        if title:
            library[ISBN]['title'] = title
        if author:
            library[ISBN]['author'] = author
        if copies:
            library[ISBN]['copies'] = int(copies)
        
        print("Book details updated successfully.")
    else:
        print(f"Book with ISBN {ISBN} not found in the library.")

while True:
    print("\nLibrary Management System Menu:")
    print("1. Add a book")
    print("2. Display all books")
    print("3. Search for a book")
    print("4. Delete a book by ISBN")
    print("5. Update book details by ISBN")
    print("6. Quit")

    choice = input("Enter your choice: ")

    if choice == '1':
        add_book()
    elif choice == '2':
        display_books()
    elif choice == '3':
        search_book()
    elif choice == '4':
        delete_book()
    elif choice == '5':
        update_book()
    elif choice == '6':
        print("Exiting the Library Management System. Goodbye!")
        break
    else:
        print("Invalid choice. Please select a valid option (1-6).")
