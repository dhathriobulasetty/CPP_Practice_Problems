#include <iostream>
#include <string>
#include <iomanip>

enum Genre { FICTION, NONFICTION, SCIENCE, HISTORY, TECHNOLOGY };

class Book {
private:
    int bookID;
    float rating;
    double price;
    char availabilityStatus;
    bool isReferenceOnly;
    std::string title;
    Genre genre;

public:
    // Default constructor
    Book()
        : bookID(0), rating(0.0f), price(0.0),
          availabilityStatus('A'), isReferenceOnly(false),
          title("Untitled"), genre(FICTION) {}

    // Parameterized constructor
    Book(int id, float rate, double cost, char status, bool reference, const std::string &name, Genre g)
        : bookID(id), rating(rate), price(cost),
          availabilityStatus(status), isReferenceOnly(reference),
          title(name), genre(g) {}

    // Destructor
    ~Book() {
        std::cout << "Book object with ID " << bookID << " destroyed." << std::endl;
    }

    // Getters
    int getBookID() const { return bookID; }
    float getRating() const { return rating; }
    double getPrice() const { return price; }
    char getAvailabilityStatus() const { return availabilityStatus; }
    bool getIsReferenceOnly() const { return isReferenceOnly; }
    std::string getTitle() const { return title; }
    Genre getGenre() const { return genre; }

    // Setters
    void setBookID(int id) { bookID = id; }
    void setRating(float rate) { rating = rate; }
    void setPrice(double cost) { price = cost; }
    void setAvailabilityStatus(char status) { availabilityStatus = status; }
    void setIsReferenceOnly(bool reference) { isReferenceOnly = reference; }
    void setTitle(const std::string &name) { title = name; }
    void setGenre(Genre g) { genre = g; }

    // Update availability
    void updateAvailability(bool isBorrowed) {
        availabilityStatus = isBorrowed ? 'B' : 'A';
    }

    // Display details
    void displayDetails() const {
        std::cout << "\n--- Book Details ---\n";
        std::cout << "Book ID: " << bookID << std::endl;
        std::cout << "Title: " << title << std::endl;
        std::cout << "Price: " << price << std::endl;
        std::cout << "Rating: " << rating << std::endl;
        std::cout << "Status: " << (availabilityStatus == 'A' ? "Available" : "Borrowed") << std::endl;
        std::cout << "Reference Only: " << (isReferenceOnly ? "Yes" : "No") << std::endl;

        std::cout << "Genre: ";
        switch (genre) {
            case FICTION: std::cout << "Fiction"; break;
            case NONFICTION: std::cout << "Non-Fiction"; break;
            case SCIENCE: std::cout << "Science"; break;
            case HISTORY: std::cout << "History"; break;
            case TECHNOLOGY: std::cout << "Technology"; break;
        }
        std::cout << std::endl;
    }
};

// Global functions
void markAsReference(Book &book) {
    book.setIsReferenceOnly(true);
    std::cout << "Book \"" << book.getTitle() << "\" marked as reference-only.\n";
}

bool isAffordable(const Book &book, const double budget) {
    return (book.getPrice() <= budget);
}

void printFormattedBookList(const Book books[], const int size) {
    std::cout << "\n------------------------------------------------------------\n";
    std::cout << std::left << std::setw(5) << "ID"
              << std::setw(20) << "Title"
              << std::setw(10) << "Price"
              << std::setw(8) << "Rating"
              << std::setw(10) << "Status"
              << std::setw(12) << "Reference"
              << std::setw(12) << "Genre" << std::endl;
    std::cout << "------------------------------------------------------------\n";

    for (int i = 0; i < size; i++) {
        std::cout << std::left << std::setw(5) << books[i].getBookID()
                  << std::setw(20) << books[i].getTitle()
                  << std::setw(10) << books[i].getPrice()
                  << std::setw(8) << books[i].getRating()
                  << std::setw(10) << (books[i].getAvailabilityStatus() == 'A' ? "Available" : "Borrowed")
                  << std::setw(12) << (books[i].getIsReferenceOnly() ? "Yes" : "No");

        switch (books[i].getGenre()) {
            case FICTION: std::cout << "Fiction"; break;
            case NONFICTION: std::cout << "Non-Fiction"; break;
            case SCIENCE: std::cout << "Science"; break;
            case HISTORY: std::cout << "History"; break;
            case TECHNOLOGY: std::cout << "Technology"; break;
        }
        std::cout << std::endl;
    }
    std::cout << "------------------------------------------------------------\n";
}

// Main function
int main() {
    Book books[3] = {
        Book(101, 4.5f, 299.99, 'A', false, "C++ Primer", TECHNOLOGY),
        Book(102, 3.8f, 150.00, 'B', true, "Design Patterns", SCIENCE),
        Book()
    };

    int choice;
    do {
        std::cout << "\n===== Library Book Management Menu =====\n";
        std::cout << "1. Add Book Details\n";
        std::cout << "2. Mark as Reference\n";
        std::cout << "3. Check if Affordable\n";
        std::cout << "4. Update Availability\n";
        std::cout << "5. Display Book Details\n";
        std::cout << "6. Display All Books\n";
        std::cout << "7. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (choice == 1) {
            int index, id, genreChoice;
            float rate;
            double cost;
            char status;
            bool reference;
            std::string name;

            std::cout << "Enter index (0-2): ";
            std::cin >> index;
            if (index < 0 || index > 2) {
                std::cout << "Invalid index!\n";
                continue;
            }

            std::cout << "Enter Book ID: ";
            std::cin >> id;
            std::cout << "Enter Rating (0.0 - 5.0): ";
            std::cin >> rate;
            if (rate < 0.0f || rate > 5.0f) {
                std::cout << "Invalid rating!\n";
                continue;
            }
            std::cout << "Enter Price: ";
            std::cin >> cost;
            if (cost <= 0) {
                std::cout << "Invalid price!\n";
                continue;
            }
            std::cout << "Enter Status (A/B): ";
            std::cin >> status;
            std::cout << "Is Reference Only? (1=Yes, 0=No): ";
            std::cin >> reference;
            std::cin.ignore();
            std::cout << "Enter Title: ";
            std::getline(std::cin, name);

            std::cout << "Select Genre (0=Fiction,1=Nonfiction,2=Science,3=History,4=Technology): ";
            std::cin >> genreChoice;
            if (genreChoice < 0 || genreChoice > 4) {
                std::cout << "Invalid genre!\n";
                continue;
            }

            books[index] = Book(id, rate, cost, status, reference, name, static_cast<Genre>(genreChoice));
            std::cout << "Book added successfully!\n";
        }
        else if (choice == 2) {
            int index;
            std::cout << "Enter index (0-2): ";
            std::cin >> index;
            markAsReference(books[index]);
        }
        else if (choice == 3) {
            int index;
            double budget;
            std::cout << "Enter index (0-2): ";
            std::cin >> index;
            std::cout << "Enter your budget: ";
            std::cin >> budget;
            if (isAffordable(books[index], budget)) {
                std::cout << "Yes, \"" << books[index].getTitle() << "\" is affordable.\n";
            } else {
                std::cout << "No, \"" << books[index].getTitle() << "\" exceeds your budget.\n";
            }
        }
        else if (choice == 4) {
            int index;
            bool borrow;
            std::cout << "Enter index (0-2): ";
            std::cin >> index;
            std::cout << "Is Borrowed? (1=Yes, 0=No): ";
            std::cin >> borrow;
            books[index].updateAvailability(borrow);
            std::cout << "Availability updated successfully!\n";
        }
        else if (choice == 5) {
            int index;
            std::cout << "Enter index (0-2): ";
            std::cin >> index;
            books[index].displayDetails();
        }
        else if (choice == 6) {
            printFormattedBookList(books, 3);
        }
        else if (choice == 7) {
            std::cout << "Exiting program...\n";
        }
        else {
            std::cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 7);

    return 0;
}
