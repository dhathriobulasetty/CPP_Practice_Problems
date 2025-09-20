#include <algorithm>
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <string>

// ServiceRecord

class ServiceRecord {
private:
    std::string date_;         // YYYY-MM-DD
    int mileage_;              // >= 0
    std::string description_;

public:
    // Default constructor - empty record
    ServiceRecord()
        : date_{}, mileage_{0}, description_{} {}

    // Full initializer - validates mileage
    ServiceRecord(const std::string& date, int mileage, const std::string& description)
        : date_{date}, mileage_{0}, description_{description} {
        if (mileage < 0) {
            throw std::invalid_argument("ServiceRecord: mileage must be >= 0");
        }
        mileage_ = mileage;
    }

    // Copy constructor
    ServiceRecord(const ServiceRecord& other)
        : date_{other.date_}, mileage_{other.mileage_}, description_{other.description_} {}

    // Copy assignment
    ServiceRecord& operator=(const ServiceRecord& other) {
        if (this != &other) {
            date_ = other.date_;
            mileage_ = other.mileage_;
            description_ = other.description_;
        }
        return *this;
    }

    // Getters
    const std::string& getDate() const { return date_; }
    int getMileage() const { return mileage_; }
    const std::string& getDescription() const { return description_; }

    // Utility: print the record in human-readable format
    void print() const {
        std::cout << "  Date: " << date_
                  << " | Mileage: " << mileage_
                  << " | Desc: " << description_ << '\n';
    }
};

// Car
class Car {
private:
    std::string vin_;
    std::string make_;
    std::string model_;
    double price_; // non-negative

    // service history dynamic array
    ServiceRecord* serviceHistory_;
    size_t serviceCount_;
    size_t serviceCap_;

    // damage codes dynamic array
    int* damageCodes_;
    size_t damageCount_;
    size_t damageCap_;

    static size_t totalCars_;

    // Private helpers to grow arrays
    void reserveService(size_t newCap) {
        if (newCap <= serviceCap_) return;
        ServiceRecord* newArr = new ServiceRecord[newCap];
        for (size_t i = 0; i < serviceCount_; ++i) {
            newArr[i] = serviceHistory_[i];
        }
        delete[] serviceHistory_;
        serviceHistory_ = newArr;
        serviceCap_ = newCap;
    }

    void reserveDamage(size_t newCap) {
        if (newCap <= damageCap_) return;
        int* newArr = new int[newCap];
        for (size_t i = 0; i < damageCount_; ++i) {
            newArr[i] = damageCodes_[i];
        }
        delete[] damageCodes_;
        damageCodes_ = newArr;
        damageCap_ = newCap;
    }

public:
    // Default constructor
    Car()
        : vin_{}, make_{}, model_{}, price_{0.0},
          serviceHistory_{nullptr}, serviceCount_{0}, serviceCap_{0},
          damageCodes_{nullptr}, damageCount_{0}, damageCap_{0} {
        ++totalCars_;
    }

    // Parameterised constructor (validates price)
    Car(const std::string& vin, const std::string& make, const std::string& model, double price)
        : vin_{vin}, make_{make}, model_{model}, price_{0.0},
          serviceHistory_{nullptr}, serviceCount_{0}, serviceCap_{0},
          damageCodes_{nullptr}, damageCount_{0}, damageCap_{0} {
        setPrice(price); // will validate
        ++totalCars_;
    }

    // Copy constructor: deep copy of dynamic arrays (service + damage)
    Car(const Car& other)
        : vin_{other.vin_}, make_{other.make_}, model_{other.model_}, price_{other.price_},
          serviceHistory_{nullptr}, serviceCount_{other.serviceCount_}, serviceCap_{other.serviceCap_},
          damageCodes_{nullptr}, damageCount_{other.damageCount_}, damageCap_{other.damageCap_} {
        // Deep copy service history
        if (serviceCap_ > 0) {
            serviceHistory_ = new ServiceRecord[serviceCap_];
            for (size_t i = 0; i < serviceCount_; ++i) {
                serviceHistory_[i] = other.serviceHistory_[i];
            }
        } else {
            serviceHistory_ = nullptr;
        }

        // Deep copy damage codes
        if (damageCap_ > 0) {
            damageCodes_ = new int[damageCap_];
            for (size_t i = 0; i < damageCount_; ++i) {
                damageCodes_[i] = other.damageCodes_[i];
            }
        } else {
            damageCodes_ = nullptr;
        }

        ++totalCars_;
    }

    // Destructor - releases both dynamic arrays
    ~Car() {
        delete[] serviceHistory_;
        delete[] damageCodes_;
        // decrement 
        if (totalCars_ > 0) {
            --totalCars_;
        }
    }

    // Swap friend - swaps all non-static members
    friend void swap(Car& lhs, Car& rhs) noexcept {
        using std::swap;
        swap(lhs.vin_, rhs.vin_);
        swap(lhs.make_, rhs.make_);
        swap(lhs.model_, rhs.model_);
        swap(lhs.price_, rhs.price_);

        swap(lhs.serviceHistory_, rhs.serviceHistory_);
        swap(lhs.serviceCount_, rhs.serviceCount_);
        swap(lhs.serviceCap_, rhs.serviceCap_);

        swap(lhs.damageCodes_, rhs.damageCodes_);
        swap(lhs.damageCount_, rhs.damageCount_);
        swap(lhs.damageCap_, rhs.damageCap_);
    }

    // Copy-and-swap assignment
    Car& operator=(Car other) {
        swap(*this, other);
        return *this;
    }

    // Static accessor
    static size_t getTotalCars() { return totalCars_; }

    // Setters 
    void setVIN(const std::string& vin) { vin_ = vin; }
    void setMake(const std::string& make) { make_ = make; }
    void setModel(const std::string& model) { model_ = model; }
    void setPrice(double price) {
        if (price < 0.0) {
            throw std::invalid_argument("Car::setPrice: price must be non-negative");
        }
        price_ = price;
    }

    // Getters 
    const std::string& getVIN() const { return vin_; }
    const std::string& getMake() const { return make_; }
    const std::string& getModel() const { return model_; }
    double getPrice() const { return price_; }
    size_t getServiceCount() const { return serviceCount_; }
    size_t getDamageCount() const { return damageCount_; }
    const ServiceRecord* getServiceHistory() const { return serviceHistory_; } // read-only pointer
    const int* getDamageCodes() const { return damageCodes_; } // read-only pointer

    // Business logic
    void addService(const ServiceRecord& rec) {
        if (serviceCap_ == 0) {
            reserveService(2);
        } else if (serviceCount_ >= serviceCap_) {
            reserveService(serviceCap_ * 2);
        }
        serviceHistory_[serviceCount_++] = rec;
    }

    void addDamageCode(int code) {
        if (damageCap_ == 0) {
            reserveDamage(2);
        } else if (damageCount_ >= damageCap_) {
            reserveDamage(damageCap_ * 2);
        }
        damageCodes_[damageCount_++] = code;
    }

    void printInfo() const {
        std::cout << "Car VIN: " << vin_ << " | Make: " << make_ << " | Model: " << model_
                  << " | Price: $" << std::fixed << std::setprecision(2) << price_
                  << " | Services: " << serviceCount_ << " | Damage Codes: " << damageCount_
                  << '\n';

        if (serviceCount_ > 0 && serviceHistory_ != nullptr) {
            std::cout << " Service History:\n";
            for (size_t i = 0; i < serviceCount_; ++i) {
                serviceHistory_[i].print();
            }
        }

        if (damageCount_ > 0 && damageCodes_ != nullptr) {
            std::cout << " Damage Codes: ";
            for (size_t i = 0; i < damageCount_; ++i) {
                std::cout << damageCodes_[i] << (i + 1 < damageCount_ ? ", " : "\n");
            }
        }
    }
};

// static member init
size_t Car::totalCars_ = 0;



// Global functions

double averagePrice(const Car* arr, size_t n) {
    if (arr == nullptr || n == 0) return 0.0;
    double sum = 0.0;
    for (size_t i = 0; i < n; ++i) {
        sum += arr[i].getPrice();
    }
    return sum / static_cast<double>(n);
}

bool compareByPriceAsc(const Car& a, const Car& b) {
    return a.getPrice() < b.getPrice();
}

bool compareByPriceDesc(const Car& a, const Car& b) {
    return a.getPrice() > b.getPrice();
}

bool areCarsEqual(const Car& a, const Car& b) {
    return a.getVIN() == b.getVIN();
}

const Car* maxPriceCar(const Car* arr, size_t n) {
    if (arr == nullptr || n == 0) return nullptr;
    const Car* maxPtr = &arr[0];
    for (size_t i = 1; i < n; ++i) {
        if (arr[i].getPrice() > maxPtr->getPrice()) {
            maxPtr = &arr[i];
        }
    }
    return maxPtr;
}

const Car* findCarByVIN(const Car* arr, size_t n, const std::string& vin) {
    if (arr == nullptr) return nullptr;
    for (size_t i = 0; i < n; ++i) {
        if (arr[i].getVIN() == vin) return &arr[i];
    }
    return nullptr;
}

size_t countCarsWithDamage(const Car* arr, size_t n, int code) {
    if (arr == nullptr) return 0;
    size_t counter = 0;
    for (size_t i = 0; i < n; ++i) {
        const int* codes = arr[i].getDamageCodes();
        size_t dcount = arr[i].getDamageCount();
        for (size_t j = 0; j < dcount; ++j) {
            if (codes != nullptr && codes[j] == code) {
                ++counter;
                break; // count each car at most once
            }
        }
    }
    return counter;
}

// Non-member helper to swap two Car objects via friend swap
void swapCars(Car& a, Car& b) {
    swap(a, b);
}


// Main 

int main() {

        // Print the initial static-counter value
        std::cout << "Initial total cars: " << Car::getTotalCars() << '\n'; // Expect 0

        // Default-construct a Car
        Car cDefault;
        std::cout << "After default construct: total cars = " << Car::getTotalCars() << '\n';
        cDefault.printInfo();

        // Parameter-construct a Car
        Car cParam("1HGCM", "Honda", "Accord", 19999.99);
        std::cout << "After parameter construct: total cars = " << Car::getTotalCars() << '\n';
        cParam.printInfo();

        // Add three damage codes to cParam
        cParam.addDamageCode(101);
        cParam.addDamageCode(205);
        cParam.addDamageCode(307);
        std::cout << "After adding damage codes:\n";
        cParam.printInfo();

        // Create two ServiceRecord and add to cParam
        ServiceRecord sr1("2022-03-15", 15000, "Oil change");
        ServiceRecord sr2("2023-01-10", 25000, "Brake pads replacement");
        cParam.addService(sr1);
        cParam.addService(sr2);
        std::cout << "After adding services:\n";
        cParam.printInfo();

        // Copy-construct a new Car from cParam
        Car cCopy(cParam);
        std::cout << "After copy-construction: total cars = " << Car::getTotalCars() << '\n';
        std::cout << "Original damage codes:\n";
        cParam.printInfo();
        std::cout << "Copy damage codes:\n";
        cCopy.printInfo();

        // Modify a damage code in the copy and show original unchanged
        if (cCopy.getDamageCount() > 0) {
            Car temp = cCopy;
            cCopy.addDamageCode(999); // original should remain unchanged
        }

        std::cout << "After modifying copy (added 999 to copy):\n";
        std::cout << "Original damage codes (should be unchanged):\n";
        cParam.printInfo();
        std::cout << "Copy damage codes (should reflect new code):\n";
        cCopy.printInfo();

        // service counts
        std::cout << "Service counts - original: " << cParam.getServiceCount()
                  << " | copy: " << cCopy.getServiceCount() << '\n';

        // Default-construct another Car and assign from cParam
        Car cAssign;
        std::cout << "Before assignment: total cars = " << Car::getTotalCars() << '\n';
        cAssign = cParam;
        std::cout << "After assignment: total cars = " << Car::getTotalCars() << '\n';
        std::cout << "cAssign info:\n";
        cAssign.printInfo();

        // Change a damage code in cAssign and verify original unchanged
        cAssign.addDamageCode(888);
        std::cout << "After modifying cAssign (added 888):\n";
        std::cout << "cAssign:\n"; cAssign.printInfo();
        std::cout << "Original (cParam) should be unchanged:\n"; cParam.printInfo();

        // Allocate dynamic array of N = 3 Car objects
        const size_t N = 3;
        Car* garage = new Car[N]; // default-constructed
        std::cout << "After new Car[" << N << "]: total cars = " << Car::getTotalCars() << '\n';

        // Initialize each element via assignment with distinct VIN/make/model/price
        garage[0] = Car("JH4KA", "Acura", "TLX", 27999.49);
        garage[1] = Car("5YJ3E", "Tesla", "Model3", 39999.00);
        garage[2] = Car("WBA4", "BMW", "3Series", 34999.99);

        // helper lambda to add damages and services for a Car&
        auto populateCar = [](Car& c, const int* damageArr, size_t dcount, const ServiceRecord* sArr, size_t scount) {
            for (size_t i = 0; i < dcount; ++i) c.addDamageCode(damageArr[i]);
            for (size_t j = 0; j < scount; ++j) c.addService(sArr[j]);
        };

        // sample damages and service records
        int damageAcura[] = {102, 208};
        int damageTesla[] = {110, 220, 330, 440};
        int damageBMW[] = {150, 250};

        ServiceRecord sr3("2023-06-20", 30000, "Tire rotation");
        ServiceRecord sr4("2024-02-05", 35000, "Annual safety inspection");

        // Populate
        populateCar(garage[0], damageAcura, 2, &sr1, 1); // Acura: one service (sr1)
        populateCar(garage[1], damageTesla, 4, &sr3, 1); // Tesla: one service (sr3)
        ServiceRecord twoServices[] = {sr2, sr4};
        populateCar(garage[2], damageBMW, 2, twoServices, 2); // BMW: two services

        // Loop over the heap array and call printInfo()
        std::cout << "Garage cars:\n";
        for (size_t i = 0; i < N; ++i) {
            std::cout << "Index " << i << ":\n";
            garage[i].printInfo();
        }

        // Call averagePrice
        double avg = averagePrice(garage, N);
        std::cout << "Average price of garage (N=" << N << "): $" << std::fixed << std::setprecision(2) << avg << '\n';

        // Call additional utilities
        const Car* maxPtr = maxPriceCar(garage, N);
        if (maxPtr) std::cout << "Max price car VIN: " << maxPtr->getVIN() << " Price: $" << maxPtr->getPrice() << '\n';

        const Car* found = findCarByVIN(garage, N, "5YJ3E");
        if (found) std::cout << "Found VIN 5YJ3E: price $" << found->getPrice() << '\n';

        size_t countDamage110 = countCarsWithDamage(garage, N, 110);
        std::cout << "Cars with damage code 110: " << countDamage110 << '\n';

        bool equalCheck = areCarsEqual(garage[0], garage[1]);
        std::cout << "Are garage[0] and garage[1] equal by VIN? " << (equalCheck ? "Yes" : "No") << '\n';

        // Delete the heap array
        delete[] garage;
        std::cout << "After delete[] garage: total cars = " << Car::getTotalCars() << '\n';

        // Attempt to modify a const Car& by calling non-const mutator (commented out to show compile-time demonstration)
        // const Car& cref = cParam;
        // cref.setPrice(1000.0); // <-- should be compile-time error (uncommenting will fail to compile) demonstrating const correctness.

        // Print final static-counter value before exiting main
        std::cout << "Final total cars before exiting main: " << Car::getTotalCars() << '\n';
        
    return 0;
}
